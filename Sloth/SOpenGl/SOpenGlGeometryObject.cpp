//file: Sloth/SOpenGl/SOpenGlGeometryObject.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlGeometryObject.h"

#include "Sloth/SOpenGl/SOpenGl.h"

#include "Sloth/SMaterial/SMaterial_Export.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< SOpenGlGeometryObjectTopology >TArrayTopology;
typedef Hubris::HContainerArray< SOpenGlGeometryObjectData >TArrayData;
typedef Hubris::HContainerArray< HBuffer >TArrayBuffer;
typedef Hubris::HContainerPair< HBuffer, SOpenGlGeometryObjectData >TPairBufferData;
typedef Hubris::HContainerArray< TPairBufferData >TArrayPairBufferData;

///////////////////////////////////////////////////////
// local
/**/
static HVOID LocalBufferValueAppend(
	HBuffer& out_topologyData,
	const HSINT in_vertexIndex,
	const HSINT in_topologyType
	)
{
	if( GL_UNSIGNED_BYTE == in_topologyType )
	{
		HTraitBufferInAppend< HU8 >( out_topologyData, ( HU8 )( in_vertexIndex & 0xFF ) );
	}
	else if( GL_UNSIGNED_SHORT == in_topologyType )
	{
		HTraitBufferInAppend< HU16 >( out_topologyData, ( HU16 )( in_vertexIndex & 0xFFFF ) );
	}
	else
	{
		HTraitBufferInAppend< HU32 >( out_topologyData, ( HU32 )( in_vertexIndex & 0xFFFFFFFF ) );
	}

	return;
}

/**/
static HVOID LocalGatherTopologyTriangle(
	HBuffer& out_topologyData,
	SOpenGlGeometryObjectTopology& out_topology,
	const PGeometryStoreTriangle& in_storeTriangle,
	const HSINT in_maxVertexCount
	)
{
	HSINT topologyType = GL_UNSIGNED_INT;
	HSINT topologyCount = 0;

	if( in_maxVertexCount < 255 )
	{
		topologyType = GL_UNSIGNED_BYTE;
	}
	else if( in_maxVertexCount < 65535 )
	{
		topologyType = GL_UNSIGNED_SHORT;
	}

	for( HSINT index = 0; index < in_storeTriangle.TriangleCountGet(); ++index )
	{
		HSINT vertexIndexOne = 0;
		HSINT vertexIndexTwo = 0;
		HSINT vertexIndexThree = 0;

		in_storeTriangle.TriangleGet(
			index,
			vertexIndexOne,
			vertexIndexTwo,
			vertexIndexThree
			);

		LocalBufferValueAppend(
			out_topologyData,
			vertexIndexOne,
			topologyType
			);
		LocalBufferValueAppend(
			out_topologyData,
			vertexIndexTwo,
			topologyType
			);
		LocalBufferValueAppend(
			out_topologyData,
			vertexIndexThree,
			topologyType
			);

		topologyCount += 3;
	}

	out_topology = SOpenGlGeometryObjectTopology(
		GL_TRIANGLES,
		topologyType,
		topologyCount,
		0,
		HCOMMON_INVALID_INDEX
		);

	return;
}

/**/
static HVOID LocalGatherTopologyStrip(
	HBuffer& out_topologyData,
	SOpenGlGeometryObjectTopology& out_topology,
	const PGeometryStoreTriangleStrip& in_storeStrip,
	const HSINT in_maxVertexCount
	)
{
	HSINT topologyType = GL_UNSIGNED_INT;
	HSINT topologyCount = 0;
	HSINT topologyPrimitiveIndexReset = -1;

	if( in_maxVertexCount < 255 )
	{
		topologyType = GL_UNSIGNED_BYTE;
		topologyPrimitiveIndexReset = 255;
	}
	else if( in_maxVertexCount < 65535 )
	{
		topologyType = GL_UNSIGNED_SHORT;
		topologyPrimitiveIndexReset = 65535;
	}

	const HSINT stripCount = in_storeStrip.StripCountGet();
	for( HSINT stripIndex = 0; stripIndex < stripCount; ++stripIndex )
	{
		const HSINT stripLength = in_storeStrip.StripLengthGet( stripIndex );
		const HSINT* pArrayStripVertexIndex = in_storeStrip.StripDataGet( stripIndex );

		//if we are not the first strip, put a degenerate tri at the start
		if( 0 != stripIndex )
		{
			LocalBufferValueAppend(
				out_topologyData,
				pArrayStripVertexIndex[ 0 ],
				topologyType
				);
			topologyCount += 1;

			//get onto an exen start
			if( 1 == ( topologyCount & 1 ) )
			{
				LocalBufferValueAppend(
					out_topologyData,
					pArrayStripVertexIndex[ 0 ],
					topologyType
					);
				topologyCount += 1;
			}
		}

		for( HSINT index = 0; index < stripLength; ++index )
		{
			LocalBufferValueAppend(
				out_topologyData,
				pArrayStripVertexIndex[ index ],
				topologyType
				);
		}
		topologyCount += stripLength;

		//end strip, repeat last vertex
		if( stripIndex != ( stripCount - 1 ) )
		{
			LocalBufferValueAppend(
				out_topologyData,
				pArrayStripVertexIndex[ stripLength - 1 ],
				topologyType
				);
			topologyCount += 1;
		}
	}

	out_topology = SOpenGlGeometryObjectTopology(
		GL_TRIANGLE_STRIP,
		topologyType,
		topologyCount,
		0,
		HCOMMON_INVALID_INDEX
		);

	return;
}

/**/
static HVOID LocalGatherTopologyData(
	SOpenGlGeometryObjectTopology& out_topologyData,
	const Hubris::HSINT in_index,
	const PGeometry& in_geometry,
	const PGeometryTypeSignature& in_typeSignature,
	SOpenGl& in_openGl
	)
{
	const HSINT streamType = in_typeSignature.TopologyStreamTypeGet( in_index );

	if( ( streamType != PGeometryTypeSignature::TypeGetTopologyTriangle() ) &&
		( streamType != PGeometryTypeSignature::TypeGetTopologyTriangleStrip() ) )
	{
		return;
	}

	HBuffer buffer;
	if( PGeometryTypeSignature::TypeGetTopologyTriangle() == streamType )
	{
		const HSINT vertexStoreIndex = in_geometry.StoreTopologyTriangleGet( in_index ).TargetTopologyVertexIndexGet();
		const HSINT vertexCount = in_geometry.StoreTopologyVertexIndexGet( vertexStoreIndex ).DataArrayCountGet();

		LocalGatherTopologyTriangle(
			buffer,
			out_topologyData,
			in_geometry.StoreTopologyTriangleGet( in_index ),
			vertexCount
			);
	}
	else if( PGeometryTypeSignature::TypeGetTopologyTriangleStrip() == streamType )
	{
		const HSINT vertexStoreIndex = in_geometry.StoreTopologyTriangleStripGet( in_index ).TargetTopologyVertexIndexGet();
		const HSINT vertexCount = in_geometry.StoreTopologyVertexIndexGet( vertexStoreIndex ).DataArrayCountGet();

		LocalGatherTopologyStrip(
			buffer,
			out_topologyData,
			in_geometry.StoreTopologyTriangleStripGet( in_index ),
			vertexCount
			);
	}

	HSINT bufferElementId = 0;
	in_openGl.GlGenBuffersARB( 1, &bufferElementId );
	out_topologyData.VertexBufferObjectIndexSet( bufferElementId );

	//bind the topology index data
	in_openGl.GlBindBufferARB( 
		GL_ELEMENT_ARRAY_BUFFER_ARB, 
		bufferElementId
		);

	in_openGl.GlBufferDataARB( 
		GL_ELEMENT_ARRAY_BUFFER_ARB, 
		buffer.SizeGet(),
		buffer.RawGet(),
		GL_STATIC_DRAW_ARB
		);

	in_openGl.GlBindBufferARB( 
		GL_ELEMENT_ARRAY_BUFFER_ARB, 
		HNULL
		);

	return;
}

/**/
static const HSINT LocalUsageGet( 
	const TArraySint& in_dynamicIndex,
	const HSINT in_geometryIndex
	)
{
	if( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( in_dynamicIndex, in_geometryIndex ) )
	{
		//GL_DYNAMIC_DRAW_ARB;
		return GL_STREAM_DRAW_ARB;
	}
	return GL_STATIC_DRAW_ARB;
}

/**/
static HVOID LocalGatherData(
	SOpenGlGeometryObjectData& out_data,
	const Hubris::HSINT in_geometryIndex,
	const PGeometry& in_geometry,
	const PGeometryTypeSignature& in_typeSignature,
	SOpenGl& in_openGl,
	const TArraySint& in_dynamicIndex
	)
{
	HBuffer buffer;
	const HSINT type = in_typeSignature.DataStreamTypeGet( in_geometryIndex );
	if( type == PGeometryTypeSignature::TypeGetDataColour() )
	{
		out_data.DrawSizeSet( 4 );
		out_data.DrawTypeSet( GL_UNSIGNED_BYTE );

		const HContainerArray< PColourRgba >& arrayData = in_geometry.StoreDataColourRgbaGet( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( PColourRgba ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
	{
		out_data.DrawSizeSet( 4 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< PColourRealRgba >& arrayData = in_geometry.StoreDataColourRealRgbaGet( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( PColourRealRgba ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
	{
		out_data.DrawSizeSet( 4 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< PColourRealRgba >& arrayData = in_geometry.StoreDataColourRealRgbaGet( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( PColourRealRgba ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataReal() )
	{
		out_data.DrawSizeSet( 1 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< HREAL >& arrayData = in_geometry.StoreDataRealGet( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( HREAL ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataSint() )
	{
		out_data.DrawSizeSet( 1 );
		out_data.DrawTypeSet( GL_INT );

		const HContainerArray< HSINT >& arrayData = in_geometry.StoreDataSintGet( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( HSINT ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
	{
		out_data.DrawSizeSet( 2 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< HVectorR2 >& arrayData = in_geometry.StoreDataVectorR2Get( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( HVectorR2 ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
	{
		out_data.DrawSizeSet( 3 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< HVectorR3 >& arrayData = in_geometry.StoreDataVectorR3Get( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( HVectorR3 ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}
	else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
	{
		out_data.DrawSizeSet( 4 );
		out_data.DrawTypeSet( GL_FLOAT );

		const HContainerArray< HVectorR4 >& arrayData = in_geometry.StoreDataVectorR4Get( in_geometryIndex ).ArrayDataGet();
		const HSINT size = arrayData.SizeGet() * sizeof( HVectorR4 ); 
		buffer.SizeSet( size );
		buffer.DataSet( arrayData.RawGet(), size, 0 ); 
	}

	if( buffer.SizeGet() <= 0 )
	{
		return;
	}

	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );

	const HSINT usage = LocalUsageGet( in_dynamicIndex, in_geometryIndex );
	HSINT vertexBufferObjectIndex = HCOMMON_INVALID_INDEX;
	in_openGl.GlGenBuffersARB( 1, &vertexBufferObjectIndex );
	out_data.VertexBufferObjectIndexSet( vertexBufferObjectIndex );

	//glEnableClientState( GL_VERTEX_ARRAY );
	in_openGl.GlBindBufferARB( GL_ARRAY_BUFFER_ARB, vertexBufferObjectIndex );
	in_openGl.GlBufferDataARB( GL_ARRAY_BUFFER_ARB, buffer.SizeGet(), buffer.RawGet(), usage );

	in_openGl.GlBindBufferARB( 
		GL_ARRAY_BUFFER_ARB,
		HNULL
		);

	glPopClientAttrib();

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SOpenGlGeometryObject::SOpenGlGeometryObject(
	SOpenGl& in_openGl,
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_dynamicIndex
	)
: m_arrayTopology()
, m_arrayData()
{
	GeometrySet(
		in_openGl,
		in_geometry,
		in_dynamicIndex
		);
	return;
}

/**/
SOpenGlGeometryObject::~SOpenGlGeometryObject()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SOpenGlGeometryObject::GeometryUpdateData(
	const Hubris::HSINT in_geometryDataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size,
	SOpenGl& in_openGl
	)
{
SOpenGl::ErrorCheck();

	if( ( in_geometryDataIndex < 0 ) ||
		( m_arrayData.SizeGet() <= in_geometryDataIndex ) ||
		( HNULL == in_pData ) )
	{
		return;
	}

	const SOpenGlGeometryObjectData& data = m_arrayData[ in_geometryDataIndex ];

    in_openGl.GlBindBufferARB( 
		GL_ARRAY_BUFFER_ARB, 
		data.VertexBufferObjectIndexGet() 
		);

	in_openGl.GlBufferSubDataARB(
		GL_ARRAY_BUFFER_ARB,
		in_offset,
		in_size,
		in_pData
		);

	in_openGl.GlBindBufferARB( 
		GL_ARRAY_BUFFER_ARB, 
		HNULL
		);

SOpenGl::ErrorCheck();

	return;
}

/**/
Hubris::HVOID SOpenGlGeometryObject::GeometryUpdateTopology(
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_startIndex,
	const Hubris::HSINT in_count,
	SOpenGl& HCOMMON_UNUSED_VAR( in_openGl )
	)
{
	if( ( in_topologyIndex < 0 ) ||
		( m_arrayTopology.SizeGet() <= in_topologyIndex ) )
	{
		return;
	}

	SOpenGlGeometryObjectTopology& topology = m_arrayTopology[ in_topologyIndex ];
	topology.DrawCountSet( in_count );
	topology.DrawStartIndexSet( in_startIndex );

	return;
}

/**/
const Hubris::HVOID SOpenGlGeometryObject::Draw(
	SOpenGl& in_openGl,
	const SMaterialGeometryStage& in_renderStage
	)const
{
SOpenGl::ErrorCheck();

	glPushClientAttrib( GL_CLIENT_VERTEX_ARRAY_BIT );

	const HSINT dataVertexIndex = in_renderStage.PositionIndexGet();
	if( HCOMMON_INVALID_INDEX != dataVertexIndex )
	{
		const SOpenGlGeometryObjectData& dataVertex = m_arrayData[ dataVertexIndex ];
		glEnableClientState( GL_VERTEX_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			dataVertex.VertexBufferObjectIndexGet() 
			);
		glVertexPointer( 
			dataVertex.DrawSizeGet(),
			dataVertex.DrawTypeGet(),
			0,
			0
			);
	}

	const HSINT dataNormalIndex = in_renderStage.NormalIndexGet();
	if( HCOMMON_INVALID_INDEX != dataNormalIndex )
	{
		const SOpenGlGeometryObjectData& dataNormal = m_arrayData[ dataNormalIndex ];
		glEnableClientState( GL_NORMAL_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			dataNormal.VertexBufferObjectIndexGet() 
			);
		glNormalPointer( 
			dataNormal.DrawTypeGet(),
			0,
			0
			);
	}

	const HSINT dataColourIndex = in_renderStage.ColourIndexGet();
	if( HCOMMON_INVALID_INDEX != dataColourIndex )
	{
		const SOpenGlGeometryObjectData& dataColour = m_arrayData[ dataColourIndex ];
		glEnableClientState( GL_COLOR_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			dataColour.VertexBufferObjectIndexGet() 
			);
		glColorPointer( 
			dataColour.DrawSizeGet(),
			dataColour.DrawTypeGet(),
			0,
			0
			);
	}

	const HSINT dataUvIndex = in_renderStage.TextureCoordIndexGet();
	if( HCOMMON_INVALID_INDEX != dataUvIndex )
	{
		const SOpenGlGeometryObjectData& dataUv = m_arrayData[ dataUvIndex ];
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			dataUv.VertexBufferObjectIndexGet() 
			);
		glTexCoordPointer( 
			dataUv.DrawSizeGet(),
			dataUv.DrawTypeGet(),
			0,
			0
			);
	}

	const SOpenGlGeometryObjectTopology& topology = m_arrayTopology[ in_renderStage.TopologyIndexGet() ];

	in_openGl.GlBindBufferARB( 
		GL_ELEMENT_ARRAY_BUFFER_ARB, 
		topology.VertexBufferObjectIndexGet()
		);

	glDrawElements(
		topology.DrawModeGet(),
		topology.DrawCountGet(),
		topology.DrawElementTypeGet(),
		( void* )( topology.DrawStartIndexGet() )
		);

	//unbind element buffers
	in_openGl.GlBindBufferARB( 
		GL_ELEMENT_ARRAY_BUFFER_ARB, 
		HNULL
		);

	//unsure if i need to unmap each stream or just on call...
	//in_openGl.GlBindBufferARB( 
	//	GL_ARRAY_BUFFER_ARB, 
	//	HNULL
	//	);

	if( HCOMMON_INVALID_INDEX != dataVertexIndex )
	{
		glEnableClientState( GL_VERTEX_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			HNULL 
			);
	}

	if( HCOMMON_INVALID_INDEX != dataNormalIndex )
	{
		glEnableClientState( GL_NORMAL_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			HNULL 
			);
	}

	if( HCOMMON_INVALID_INDEX != dataColourIndex )
	{
		glEnableClientState( GL_COLOR_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			HNULL 
			);
	}

	if( HCOMMON_INVALID_INDEX != dataUvIndex )
	{
		glEnableClientState( GL_TEXTURE_COORD_ARRAY );
		in_openGl.GlBindBufferARB( 
			GL_ARRAY_BUFFER_ARB, 
			HNULL 
			);
	}

	glPopClientAttrib();

SOpenGl::ErrorCheck();

	return;
}

/**/
Hubris::HVOID SOpenGlGeometryObject::GeometryRelease(
	SOpenGl& in_openGl
	)
{
	HCOMMON_FOR_EACH( topology, m_arrayTopology, TArrayTopology )
	{
		HSINT bufferId = topology.VertexBufferObjectIndexGet();
		if( HCOMMON_INVALID_INDEX == bufferId )
		{
			continue;
		}

		in_openGl.GlDeleteBuffersARB( 1, &bufferId );
	}

	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayData )
	{
		HSINT dataVertexBufferObjectIndex = data.VertexBufferObjectIndexGet();
		in_openGl.GlDeleteBuffersARB( 1, &dataVertexBufferObjectIndex );
	}

	m_arrayTopology.Clear();
	m_arrayData.Clear();

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID SOpenGlGeometryObject::GeometrySet(
	SOpenGl& in_openGl,
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_dynamicIndex
	)
{
SOpenGl::ErrorCheck();

	GeometryRelease( in_openGl );

	const PGeometryTypeSignature typeSignature = in_geometry.TypeSignatureGet();

	//topology
	const HSINT topologyCount = typeSignature.TopologyStreamCountGet();
	m_arrayTopology.SizeSet( topologyCount );
	for( HSINT index = 0; index < topologyCount; ++index )
	{
		LocalGatherTopologyData(
			m_arrayTopology[ index ],
			index,
			in_geometry,
			typeSignature,
			in_openGl
			);
	}

	//vertex data
	const HSINT dataCount = typeSignature.DataStreamCountGet();
	m_arrayData.SizeSet( dataCount );
	for( HSINT index = 0; index < dataCount; ++index )
	{
		LocalGatherData(
			m_arrayData[ index ],
			index,
			in_geometry,
			typeSignature,
			in_openGl,
			in_dynamicIndex
			);
	}

SOpenGl::ErrorCheck();

	return;
}

/**/
