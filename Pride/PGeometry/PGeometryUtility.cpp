//file: Pride/PGeometry/PGeometryUtility.cpp
#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryUtility.h"

#include "Pride/PGeometry/PGeometry.h"
#include "Pride/PGeometry/PGeometryStoreData.h"
#include "Pride/PGeometry/PGeometryStoreTriangleStrip.h"
#include "Pride/PGeometry/PGeometryStoreTriangle.h"
#include "Pride/PGeometry/PGeometryStoreVertexIndex.h"
#include "Pride/PGeometry/PGeometryTypeSignature.h"
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"
#include "Pride/PGeometry/PGeometryVertex.h"
#include "Pride/PGeometry/PGeometryVertexImplementation.h"

#include "Pride/PColour/PColour_Export.h"

#include< Hubris/HVariables/HVariables_Export.h >
#include< Lust/LSpring/LSpring_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Lust;

////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HSINT >TArraySint;
typedef HContainerPair< HREAL, HSINT >TPairRealSint;
typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;

typedef Hubris::HContainerStaticArray< TPairRealSint, 4 >TStaticArray4PairRealSint;
typedef Hubris::HContainerStaticArray< TPairRealSint, 16 >TStaticArray16PairRealSint;
typedef Hubris::HContainerStaticArray< TPairRealSint, 64 >TStaticArray64PairRealSint;


////////////////////////////////////////////////
// static local methods
/**/
static const PGeometryStoreTriangle* const LocalGetFirstTriangleStore( const PGeometryTypeSignature& in_typeSignature, const PGeometry& in_geometry )
{
	for( HSINT index = 0; index < in_typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = in_typeSignature.TopologyStreamTypeGet( index );
		if( type == PGeometryTypeSignature::TypeGetTopologyTriangle() )
		{
			return &in_geometry.StoreTopologyTriangleGet( index );
		}
	}

	return HNULL;
}

/**/
static PGeometryStoreTriangle* const LocalGetFirstTriangleStore( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_geometry )
{
	for( HSINT index = 0; index < in_typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = in_typeSignature.TopologyStreamTypeGet( index );
		if( type == PGeometryTypeSignature::TypeGetTopologyTriangle() )
		{
			return &in_geometry.StoreTopologyTriangleGet( index );
		}
	}

	return HNULL;
}
/**/
static const PGeometryStoreTriangleStrip* const LocalGetFirstStripStore( const PGeometryTypeSignature& in_typeSignature, const PGeometry& in_geometry )
{
	for( HSINT index = 0; index < in_typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = in_typeSignature.TopologyStreamTypeGet( index );
		if( type == PGeometryTypeSignature::TypeGetTopologyTriangleStrip() )
		{
			return &in_geometry.StoreTopologyTriangleStripGet( index );
		}
	}

	return HNULL;
}

/**/
static PGeometryStoreTriangleStrip* const LocalGetFirstStripStore( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_geometry )
{
	for( HSINT index = 0; index < in_typeSignature.TopologyStreamCountGet(); ++index )
	{
		const HSINT type = in_typeSignature.TopologyStreamTypeGet( index );
		if( type == PGeometryTypeSignature::TypeGetTopologyTriangleStrip() )
		{
			return &in_geometry.StoreTopologyTriangleStripGet( index );
		}
	}

	return HNULL;
}

/**/
const PGeometryVertexImplementation& Pride::GeometryUtilityVertexImplementationGet( const PGeometryVertex& in_src )
{
	return in_src.ImplementationGet();
}

/**/
template< typename IN_TYPE > 
static IN_TYPE LocalExtractVertexValue( const PGeometryVertex& in_srcVertex, const PGeometryTypeSignature& in_srcTypeSignature, const HSINT in_type, const HString& in_name )
{
	IN_TYPE returnValue = IN_TYPE();

	const HSINT topologyVertexIndex = in_srcVertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_srcTypeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );

	for( HSINT index = 0; index < arrayDataStoreIndex.SizeGet(); ++index )
	{
		const HSINT dataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_srcTypeSignature.DataStreamTypeGet( dataStoreIndex );
		const HString name = in_srcTypeSignature.DataStreamNameGet( dataStoreIndex );

		if( ( in_type == type ) &&
			( in_name == name ) )
		{
			returnValue = GeometryUtilityVertexImplementationGet( in_srcVertex ).VariantGet( index ).ValueGet< IN_TYPE >();
			break;
		}
	}

	return returnValue;
}

/**/
static Hubris::HVOID LocalConvertVertex( 
	PGeometryVertex& out_destVertex, 
	const PGeometryVertex& in_srcVertex, 
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature 
	)
{
	const HSINT topologyVertexIndex = out_destVertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_destTypeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );

	for( HSINT index = 0; index < arrayDataStoreIndex.SizeGet(); ++index )
	{
		const HSINT destDataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_destTypeSignature.DataStreamTypeGet( destDataStoreIndex );
		const HString name = in_destTypeSignature.DataStreamNameGet( destDataStoreIndex );

		if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			out_destVertex.RealSet( index, LocalExtractVertexValue< HREAL >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			out_destVertex.SintSet( index, LocalExtractVertexValue< HSINT >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			out_destVertex.RealSintSet( index, LocalExtractVertexValue< TPairRealSint >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			out_destVertex.VectorR2Set( index, LocalExtractVertexValue< HVectorR2 >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			out_destVertex.VectorR3Set( index, LocalExtractVertexValue< HVectorR3 >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			out_destVertex.VectorR4Set( index, LocalExtractVertexValue< HVectorR4 >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			out_destVertex.ColourRgbaSet( index, LocalExtractVertexValue< PColourRgba >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			out_destVertex.ColourRgbaRealSet( index, LocalExtractVertexValue< PColourRealRgba >( in_srcVertex, in_srcTypeSignature, type, name ) );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "missing case" );
		}
	}

	return;
}

/**/
static Hubris::HVOID LocalConvert( 
	PGeometryStoreTriangleStrip& out_destStrip, 
	const PGeometryStoreTriangleStrip& in_srcStrip, 
	PGeometry& out_destGeometry, 
	const PGeometry& in_srcGenericGeometry, 
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature 
	)
{
	PGeometryVertex srcVertex( in_srcTypeSignature, in_srcStrip.TargetTopologyVertexIndexGet() );
	PGeometryVertex destVertex( in_destTypeSignature, out_destStrip.TargetTopologyVertexIndexGet() );

	const HSINT stripCount = in_srcStrip.StripCountGet();

	for( HSINT stripIndex = 0; stripIndex < stripCount; ++stripIndex )
	{
		const HSINT stripLength = in_srcStrip.StripLengthGet( stripIndex );
		const HSINT* const pStripIndexData = in_srcStrip.StripDataGet( stripIndex );
		TArraySint destVertexIndex;
		destVertexIndex.SizeSet( stripLength );

		for( HSINT subIndex = 0; subIndex < stripLength; ++subIndex )
		{
			srcVertex.Clear();
			destVertex.Clear();

			PGeometryUtility::VertexGet( in_srcTypeSignature, srcVertex, in_srcGenericGeometry, pStripIndexData[ subIndex ] );

			LocalConvertVertex( destVertex, srcVertex, in_destTypeSignature, in_srcTypeSignature );

			destVertexIndex[ subIndex ] = PGeometryUtility::VertexUniqueAdd( in_destTypeSignature, out_destGeometry, destVertex );
		}

		out_destStrip.StripAdd( destVertexIndex.RawGet(), stripLength );
	}

	return;
}

/**/
static Hubris::HVOID LocalConvert( 
	PGeometryStoreTriangle& out_destTriangle, 
	const PGeometryStoreTriangleStrip& in_srcStrip, 
	PGeometry& out_destGeometry, 
	const PGeometry& in_srcGenericGeometry, 
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature 
	)
{
	PGeometryVertex srcVertex( in_srcTypeSignature, in_srcStrip.TargetTopologyVertexIndexGet() );
	PGeometryVertex destVertex( in_destTypeSignature, out_destTriangle.TargetTopologyVertexIndexGet() );

	const HSINT stripCount = in_srcStrip.StripCountGet();

	for( HSINT stripIndex = 0; stripIndex < stripCount; ++stripIndex )
	{
		const HSINT stripLength = in_srcStrip.StripLengthGet( stripIndex );
		const HSINT* const pStripIndexData = in_srcStrip.StripDataGet( stripIndex );
		TArraySint destVertexIndex;
		destVertexIndex.SizeSet( stripLength );

		for( HSINT subIndex = 0; subIndex < stripLength; ++subIndex )
		{
			srcVertex.Clear();
			destVertex.Clear();

			PGeometryUtility::VertexGet( in_srcTypeSignature, srcVertex, in_srcGenericGeometry, pStripIndexData[ subIndex ] );

			LocalConvertVertex( destVertex, srcVertex, in_destTypeSignature, in_srcTypeSignature );

			destVertexIndex[ subIndex ] = PGeometryUtility::VertexUniqueAdd( in_destTypeSignature, out_destGeometry, destVertex );

			if( 2 <= subIndex )
			{
				if( 0 == ( subIndex & 1 ) )
				{
					out_destTriangle.TriangleAdd( destVertexIndex[ subIndex - 2 ], destVertexIndex[ subIndex - 1 ], destVertexIndex[ subIndex ] ); 
				}
				else
				{
					out_destTriangle.TriangleAdd( destVertexIndex[ subIndex - 1 ], destVertexIndex[ subIndex - 2 ], destVertexIndex[ subIndex ] ); 
				}
			}
		}
	}
	return;
}

/**/
static Hubris::HVOID LocalConvert( 
	PGeometryStoreTriangle& out_destTriangle, 
	const PGeometryStoreTriangle& in_srcTriangle, 
	PGeometry& out_destGeometry, 
	const PGeometry& in_srcGenericGeometry, 
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature 
	)
{
	PGeometryVertex srcVertex( in_srcTypeSignature, in_srcTriangle.TargetTopologyVertexIndexGet() );
	PGeometryVertex destVertex( in_destTypeSignature, out_destTriangle.TargetTopologyVertexIndexGet() );

	const HSINT triangleCount = in_srcTriangle.TriangleCountGet();

	for( HSINT triangleIndex = 0; triangleIndex < triangleCount; ++triangleIndex )
	{
		HSINT triangleIndexData[ 3 ]; 
		in_srcTriangle.TriangleGet( triangleIndex, triangleIndexData[ 0 ], triangleIndexData[ 1 ], triangleIndexData[ 2 ] );
		HSINT destVertexIndex[ 3 ];

		for( HSINT subIndex = 0; subIndex < 3; ++subIndex )
		{
			srcVertex.Clear();
			destVertex.Clear();

			PGeometryUtility::VertexGet( in_srcTypeSignature, srcVertex, in_srcGenericGeometry, triangleIndexData[ subIndex ] );

			LocalConvertVertex( destVertex, srcVertex, in_destTypeSignature, in_srcTypeSignature );

			destVertexIndex[ subIndex ] = PGeometryUtility::VertexUniqueAdd( in_destTypeSignature, out_destGeometry, destVertex );
		}

		out_destTriangle.TriangleAdd( destVertexIndex[ 0 ], destVertexIndex[ 1 ], destVertexIndex[ 2 ] );
	}

	return;
}

/**/
static Hubris::HVOID LocalConvert( 
	PGeometryStoreTriangleStrip& out_destStrip, 
	const PGeometryStoreTriangle& in_srcTriangle, 
	PGeometry& out_destGeometry, 
	const PGeometry& in_srcGenericGeometry, 
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature 
	)
{
	PGeometryVertex srcVertex( in_srcTypeSignature, in_srcTriangle.TargetTopologyVertexIndexGet() );
	PGeometryVertex destVertex( in_destTypeSignature, out_destStrip.TargetTopologyVertexIndexGet() );

	const HSINT triangleCount = in_srcTriangle.TriangleCountGet();

	for( HSINT triangleIndex = 0; triangleIndex < triangleCount; ++triangleIndex )
	{
		HSINT triangleIndexData[ 3 ];
		in_srcTriangle.TriangleGet( triangleIndex, triangleIndexData[ 0 ], triangleIndexData[ 1 ], triangleIndexData[ 2 ] );
		HSINT destVertexIndex[ 3 ];

		for( HSINT subIndex = 0; subIndex < 3; ++subIndex )
		{
			srcVertex.Clear();
			destVertex.Clear();

			PGeometryUtility::VertexGet( in_srcTypeSignature, srcVertex, in_srcGenericGeometry, triangleIndexData[ subIndex ] );

			LocalConvertVertex( destVertex, srcVertex, in_destTypeSignature, in_srcTypeSignature );

			destVertexIndex[ subIndex ] = PGeometryUtility::VertexUniqueAdd( in_destTypeSignature, out_destGeometry, destVertex );
		}

		out_destStrip.StripAdd( destVertexIndex, 3 );
	}

	return;
}

/**/
static Hubris::HBOOL LocalTranslateStream( const HSINT in_index, const HSINT in_type, const HString& in_name, PGeometry& in_out_geometry, const Hubris::HMatrixR4& in_matrix )
{
	if( ( in_type == PGeometryTypeSignature::TypeGetDataVectorR3() ) && ( in_name == PGeometryTypeSignature::NameGetPosition() ) )
	{
		PGeometryStoreDataVectorR3& dataStore = in_out_geometry.StoreDataVectorR3Get( in_index );
		const HSINT count = dataStore.SizeGet();
		for( HSINT index = 0; index < count; ++index )
		{
			HVectorR3& value = dataStore.DataGet( index );
			value = HMatrixUtility::VectorProduct( in_matrix, value );
		}

		return HTRUE;
	}

	return HFALSE;
}

/**/
static Hubris::HBOOL LocalRotateStream( const HSINT in_index, const HSINT in_type, const HString& in_name, PGeometry& in_out_geometry, const Hubris::HMatrixR4& in_matrix )
{
	if( ( in_type == PGeometryTypeSignature::TypeGetDataVectorR3() ) && ( in_name == PGeometryTypeSignature::NameGetNormal() ) )
	{
		PGeometryStoreDataVectorR3& dataStore = in_out_geometry.StoreDataVectorR3Get( in_index );
		const HSINT count = dataStore.SizeGet();
		for( HSINT index = 0; index < count; ++index )
		{
			HVectorR3& value = dataStore.DataGet( index );
			value = HMatrixUtility::VectorProductNoTranslate( in_matrix, value );
		}

		return HTRUE;
	}

	return HFALSE;
}

/**/
template< HSINT IN_COUNT > 
static Hubris::HVOID LocalSkinDataProcess(
	const HSINT in_index,
	TArrayReal& out_vertexPosition,
	TArrayReal& out_vertexNormal,
	const Hubris::HContainerStaticArray< TPairRealSint, IN_COUNT >& in_arraySkinningData,
	const PGeometryStoreDataVectorR3* const in_pStoreDataPosition,
	const HSINT in_positionDataIndex,
	const PGeometryStoreDataVectorR3* const in_pStoreDataNormal,
	const HSINT in_normalDataIndex,
	const TArrayMatrix& in_arrayMatrix
	)
{
	HVectorR3 resultPosition;
	HVectorR3 sourcePosition;
	HVectorR3 resultNormal;
	HVectorR3 sourceNormal;
	HREAL remaningWeight = 1.0F;
	if( HNULL != in_pStoreDataPosition )
	{
		sourcePosition = in_pStoreDataPosition->DataGet( in_positionDataIndex );
	}
	if( HNULL != in_pStoreDataNormal )
	{
		sourceNormal = in_pStoreDataNormal->DataGet( in_normalDataIndex );
	}

	//adjust the data for each skinning data
	for( HSINT index = 0; index < in_arraySkinningData.SizeGet(); ++index )
	{
		const TPairRealSint& pairData = in_arraySkinningData[ index ];
		remaningWeight -= pairData.m_first;
		const HMatrixR4& matrix = in_arrayMatrix[ pairData.m_second ];

		if( HNULL != in_pStoreDataPosition )
		{
			resultPosition += ( ( HMatrixUtility::VectorProduct( matrix, sourcePosition ) ) * pairData.m_first );
		}
		if( HNULL != in_pStoreDataNormal )
		{
			resultNormal += ( ( HMatrixUtility::VectorProductNoTranslate( matrix, sourceNormal ) ) * pairData.m_first );
		}
	}

	//finish with remaining 'normalised' weight from the default position
	if( HVariablesMath::EpsilonGet< HREAL >() < remaningWeight )
	{
		if( HNULL != in_pStoreDataPosition )
		{
			resultPosition += ( remaningWeight * sourcePosition ); 
		}
		if( HNULL != in_pStoreDataNormal )
		{
			resultNormal += ( remaningWeight * sourceNormal ); 
		}
	}

	//write out result to the output arrays
	if( HNULL != in_pStoreDataPosition )
	{
		HSINT baseIndex = in_index * 3;
		out_vertexPosition[ baseIndex ] = resultPosition[ 0 ];
		out_vertexPosition[ baseIndex + 1] = resultPosition[ 1 ];
		out_vertexPosition[ baseIndex + 2] = resultPosition[ 2 ];
	}
	if( HNULL != in_pStoreDataNormal )
	{
		HSINT baseIndex = in_index * 3;
		out_vertexNormal[ baseIndex ] = resultNormal[ 0 ];
		out_vertexNormal[ baseIndex + 1] = resultNormal[ 1 ];
		out_vertexNormal[ baseIndex + 2] = resultNormal[ 2 ];
	}

	return;
}

////////////////////////////////////////////////
// static public methods
/**/
Hubris::HSINT PGeometryUtility::VertexUniqueAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex )
{
	HCOMMON_ASSERT( in_typeSignature == in_out_geometry.TypeSignatureGet(), "types must match" );
	HCOMMON_ASSERT( in_typeSignature == in_vertex.TypeSignatureGet(), "types must match" );

	const HSINT topologyVertexIndex = in_vertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );
	const HSINT count = arrayDataStoreIndex.SizeGet();
	TArraySint arraySint;
	arraySint.SizeSet( count );

	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT dataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_typeSignature.DataStreamTypeGet( dataStoreIndex );

		if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataRealGet( dataStoreIndex ).DataUniqueAdd( in_vertex.RealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataSintGet( dataStoreIndex ).DataUniqueAdd( in_vertex.SintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataRealSintGet( dataStoreIndex ).DataUniqueAdd( in_vertex.RealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR2Get( dataStoreIndex ).DataUniqueAdd( in_vertex.VectorR2Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR3Get( dataStoreIndex ).DataUniqueAdd( in_vertex.VectorR3Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR4Get( dataStoreIndex ).DataUniqueAdd( in_vertex.VectorR4Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataColourRgbaGet( dataStoreIndex ).DataUniqueAdd( in_vertex.ColourRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataColourRealRgbaGet( dataStoreIndex ).DataUniqueAdd( in_vertex.ColourRgbaRealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray4PairRealSintGet( dataStoreIndex ).DataUniqueAdd( in_vertex.StaticArray4PairRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray16PairRealSintGet( dataStoreIndex ).DataUniqueAdd( in_vertex.StaticArray16PairRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray64PairRealSintGet( dataStoreIndex ).DataUniqueAdd( in_vertex.StaticArray64PairRealSintGet( index ) );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "missing case" );
		}
	}

	PGeometryStoreVertexIndex& storeVertexIndex = in_out_geometry.StoreTopologyVertexIndexGet( topologyVertexIndex );
	const HSINT vertexIndex = storeVertexIndex.DataArrayIndexUniqueAdd( arraySint.RawGet() );

	return vertexIndex;
}

/**/
Hubris::HSINT PGeometryUtility::VertexAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex )
{
	HCOMMON_ASSERT( in_typeSignature == in_out_geometry.TypeSignatureGet(), "types must match" );
	HCOMMON_ASSERT( in_typeSignature == in_vertex.TypeSignatureGet(), "types must match" );

	const HSINT topologyVertexIndex = in_vertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );
	const HSINT count = arrayDataStoreIndex.SizeGet();
	TArraySint arraySint;
	arraySint.SizeSet( count );

	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT dataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_typeSignature.DataStreamTypeGet( dataStoreIndex );
		if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataRealGet( dataStoreIndex ).DataAdd( in_vertex.RealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataSintGet( dataStoreIndex ).DataAdd( in_vertex.SintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataRealSintGet( dataStoreIndex ).DataAdd( in_vertex.RealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR2Get( dataStoreIndex ).DataAdd( in_vertex.VectorR2Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR3Get( dataStoreIndex ).DataAdd( in_vertex.VectorR3Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataVectorR4Get( dataStoreIndex ).DataAdd( in_vertex.VectorR4Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataColourRgbaGet( dataStoreIndex ).DataAdd( in_vertex.ColourRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataColourRealRgbaGet( dataStoreIndex ).DataAdd( in_vertex.ColourRgbaRealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray4PairRealSintGet( dataStoreIndex ).DataAdd( in_vertex.StaticArray4PairRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray16PairRealSintGet( dataStoreIndex ).DataAdd( in_vertex.StaticArray16PairRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() )
		{
			arraySint[ index ] = in_out_geometry.StoreDataStaticArray64PairRealSintGet( dataStoreIndex ).DataAdd( in_vertex.StaticArray64PairRealSintGet( index ) );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "missing case" );
		}
	}

	PGeometryStoreVertexIndex& storeVertexIndex = in_out_geometry.StoreTopologyVertexIndexGet( topologyVertexIndex );
	const HSINT vertexIndex = storeVertexIndex.DataArrayIndexAdd( arraySint.RawGet() );

	return vertexIndex;
}

/**/
Hubris::HVOID PGeometryUtility::VertexGet( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex, const PGeometry& in_geometry, const Hubris::HSINT in_vertexIndex )
{
	HCOMMON_ASSERT( in_typeSignature == out_vertex.TypeSignatureGet(), "types must match" );
	HCOMMON_ASSERT( in_typeSignature == in_geometry.TypeSignatureGet(), "types must match" );

	//the data store indexs for each item in the vertex
	const HSINT topologyVertexIndex = out_vertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );
	const PGeometryStoreVertexIndex& storeVertexIndex = in_geometry.StoreTopologyVertexIndexGet( topologyVertexIndex );
	const HSINT* const pArrayDataStoreItemIndex = storeVertexIndex.DataArrayIndexGet( in_vertexIndex );

	for( HSINT index = 0; index < arrayDataStoreIndex.SizeGet(); ++index )
	{
		const HSINT dataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_typeSignature.DataStreamTypeGet( dataStoreIndex );
		if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			out_vertex.RealSet( index, in_geometry.StoreDataRealGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			out_vertex.SintSet( index, in_geometry.StoreDataSintGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			out_vertex.RealSintSet( index, in_geometry.StoreDataRealSintGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			out_vertex.VectorR2Set( index, in_geometry.StoreDataVectorR2Get( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			out_vertex.VectorR3Set( index, in_geometry.StoreDataVectorR3Get( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			out_vertex.VectorR4Set( index, in_geometry.StoreDataVectorR4Get( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			out_vertex.ColourRgbaSet( index, in_geometry.StoreDataColourRgbaGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			out_vertex.ColourRgbaRealSet( index, in_geometry.StoreDataColourRealRgbaGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() )
		{
			out_vertex.StaticArray4PairRealSintSet( index, in_geometry.StoreDataStaticArray4PairRealSintGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() )
		{
			out_vertex.StaticArray16PairRealSintSet( index, in_geometry.StoreDataStaticArray16PairRealSintGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() )
		{
			out_vertex.StaticArray64PairRealSintSet( index, in_geometry.StoreDataStaticArray64PairRealSintGet( dataStoreIndex ).DataGet( pArrayDataStoreItemIndex[ index ] ) );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "missing case" );
		}
	}
	
	return;
}

/**/
const Hubris::HSINT PGeometryUtility::DataStoreIndexGet( 
	const PGeometryTypeSignature& in_typeSignature, 
	const Hubris::HString& in_name,
	const Hubris::HSINT in_type
	)
{
	for( HSINT dataIndex = 0; dataIndex < in_typeSignature.DataStreamCountGet(); ++dataIndex )
	{
		if( in_name != in_typeSignature.DataStreamNameGet( dataIndex ) )
		{
			continue;
		}
		if( in_type != in_typeSignature.DataStreamTypeGet( dataIndex ) )
		{
			continue;
		}

		return dataIndex;
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const Hubris::HSINT PGeometryUtility::VertexDataStoreIndexGet( 
	const PGeometryTypeSignature& in_typeSignature, 
	const Hubris::HSINT in_vertexTopologyIndex,
	const Hubris::HString& in_name,
	const Hubris::HSINT in_type
	)
{
	const TArraySint& arrayDataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_vertexTopologyIndex );
	HCOMMON_FOR_EACH_CONST( dataIndex, arrayDataStoreIndex, TArraySint )
	{
		if( in_name != in_typeSignature.DataStreamNameGet( dataIndex ) )
		{
			continue;
		}
		if( in_type != in_typeSignature.DataStreamTypeGet( dataIndex ) )
		{
			continue;
		}

		return dataIndex;
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
HVOID PGeometryUtility::PGeometryConvert(
	PGeometry& out_destGeometry, 
	const PGeometry& in_srcGenericGeometry,
	const PGeometryTypeSignature& in_destTypeSignature, 
	const PGeometryTypeSignature& in_srcTypeSignature
	)	
{
	HCOMMON_ASSERT( in_destTypeSignature == out_destGeometry.TypeSignatureGet(), "types must match" );
	HCOMMON_ASSERT( in_srcTypeSignature == in_srcGenericGeometry.TypeSignatureGet(), "types must match" );

	out_destGeometry.Clear();

	//shortcut if no changes needed
	if( in_srcTypeSignature == in_destTypeSignature )
	{
		out_destGeometry = in_srcGenericGeometry;
		return;
	}

	const PGeometryStoreTriangle* const pSrcTriangles = LocalGetFirstTriangleStore( in_srcTypeSignature, in_srcGenericGeometry );
	const PGeometryStoreTriangleStrip* const pSrcStrip = LocalGetFirstStripStore( in_srcTypeSignature, in_srcGenericGeometry );
	PGeometryStoreTriangle* const pDestTriangles = LocalGetFirstTriangleStore( in_destTypeSignature, out_destGeometry );
	PGeometryStoreTriangleStrip* const pDestStrip = LocalGetFirstStripStore( in_destTypeSignature, out_destGeometry );

	if( ( HNULL != pSrcStrip ) && ( HNULL != pDestStrip ) )
	{
		LocalConvert( *pDestStrip, *pSrcStrip, out_destGeometry, in_srcGenericGeometry, in_destTypeSignature, in_srcTypeSignature );
	}
	else if( ( HNULL != pSrcTriangles ) && ( HNULL != pDestTriangles ) )
	{
		LocalConvert( *pDestTriangles, *pSrcTriangles, out_destGeometry, in_srcGenericGeometry, in_destTypeSignature, in_srcTypeSignature );
	}
	else if( ( HNULL != pSrcStrip ) && ( HNULL != pDestTriangles ) )
	{
		LocalConvert( *pDestTriangles, *pSrcStrip, out_destGeometry, in_srcGenericGeometry, in_destTypeSignature, in_srcTypeSignature );
	}
	else if( ( HNULL != pSrcTriangles ) && ( HNULL != pDestStrip ) )
	{
		LocalConvert( *pDestStrip, *pSrcTriangles, out_destGeometry, in_srcGenericGeometry, in_destTypeSignature, in_srcTypeSignature );
	}

	return;
}

/**/
HVOID PGeometryUtility::DefaultVertex( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex )
{
	HCOMMON_ASSERT( in_typeSignature == out_vertex.TypeSignatureGet(), "types must match" );

	const HSINT topologyVertexIndex = out_vertex.TopologyVertexIndexGet();
	const TArraySint& arrayDataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( topologyVertexIndex );

	for( HSINT index = 0; index < arrayDataStoreIndex.SizeGet(); ++index )
	{
		const HSINT dataStoreIndex = arrayDataStoreIndex[ index ];
		const HSINT type = in_typeSignature.DataStreamTypeGet( dataStoreIndex );

		if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			out_vertex.RealSet( index, HVariablesMath::ZeroGet< HREAL >() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			out_vertex.SintSet( index, 0 );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			out_vertex.RealSintSet( index, TPairRealSint( HVariablesMath::ZeroGet< HREAL >(), 0 ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			out_vertex.VectorR2Set( index, HVectorR2() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			out_vertex.VectorR3Set( index, HVectorR3() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			out_vertex.VectorR4Set( index, HVectorR4() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			out_vertex.ColourRgbaSet( index, PColourRgba() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			out_vertex.ColourRgbaRealSet( index, PColourRealRgba() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() )
		{
			out_vertex.StaticArray4PairRealSintSet( index, TStaticArray4PairRealSint() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() )
		{
			out_vertex.StaticArray16PairRealSintSet( index, TStaticArray16PairRealSint() );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() )
		{
			out_vertex.StaticArray64PairRealSintSet( index, TStaticArray64PairRealSint() );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "missing case" );
		}
	}

	return;
}

/**/
HVOID PGeometryUtility::TranslateGeometry( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const Hubris::HMatrixR4& in_matrix )
{
	if( in_matrix == HMatrixUtility::IdentityGet< HMatrixR4 >() )
	{
		return;
	}

	const HSINT count = in_typeSignature.DataStreamCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT type = in_typeSignature.DataStreamTypeGet( index );
		const HString name = in_typeSignature.DataStreamNameGet( index );
		//do we need to rotate and move this stream
		if( HTRUE == LocalTranslateStream( index, type, name, in_out_geometry, in_matrix ) )
		{
			continue;
		}
		//do we need to rotate this stream
		if( HTRUE == LocalRotateStream( index, type, name, in_out_geometry, in_matrix ) )
		{
			continue;
		}
	}

	return;
}

/**/
const Hubris::HSINT PGeometryUtility::DataStoreTypeSkinDataGet( const Hubris::HSINT in_maxWeightsPerVertex )
{
	if( in_maxWeightsPerVertex <= 0 )
	{
		return HCOMMON_INVALID_INDEX;
	}
	if( in_maxWeightsPerVertex < 4 )
	{
		return PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint();
	}
	else if( in_maxWeightsPerVertex < 16 )
	{
		return PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint();
	}
	else if( in_maxWeightsPerVertex < 64 )
	{
		return PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint();
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
const Hubris::HBOOL PGeometryUtility::SkinningDataStreamIndexGet(
	Hubris::HSINT& out_positionDataStreamIndex,
	Hubris::HSINT& out_normalDataStreamIndex,
	const PGeometryTypeSignature& in_typeSignature,
	const Hubris::HSINT in_topologyVertexIndex
	)
{
	const TArraySint& arrayDataStreamIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_topologyVertexIndex ); 
	HBOOL found = HFALSE;

	for( HSINT index = 0; index < arrayDataStreamIndex.SizeGet(); ++index )
	{
		const HSINT dataStreamIndex = arrayDataStreamIndex[ index ];
		const HSINT dataStreamType = in_typeSignature.DataStreamTypeGet( dataStreamIndex );
		const HString& dataStreamName = in_typeSignature.DataStreamNameGet( dataStreamIndex );
		if( ( PGeometryTypeSignature::NameGetPosition() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			out_positionDataStreamIndex = dataStreamIndex;
		}
		else if( ( PGeometryTypeSignature::NameGetNormal() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			out_normalDataStreamIndex = dataStreamIndex;
		}
		else if( PGeometryTypeSignature::NameGetSkinWeight() == dataStreamName )
		{
			if( PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() == dataStreamType )
			{
				found = HTRUE;
			}
			else if( PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() == dataStreamType )
			{
				found = HTRUE;
			}
			else if( PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() == dataStreamType )
			{
				found = HTRUE;
			}
		}
	}
	return found;
}

/**/
HVOID PGeometryUtility::PerformSkinning( 
	TArrayReal& out_vertexPosition,
	TArrayReal& out_vertexNormal,
	const PGeometryTypeSignature& in_typeSignature, 
	const PGeometry& in_geometry,
	const Hubris::HSINT in_topologyVertexIndex,
	const TArrayMatrix& in_arrayMatrix
	)
{
	const TArraySint& arrayDataStreamIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_topologyVertexIndex ); 

	//find the skin weight stream index, and position, normal
	const PGeometryStoreDataStaticArray4PairRealSint* pStoreDataSkin4 = HNULL;
	const PGeometryStoreDataStaticArray16PairRealSint* pStoreDataSkin16 = HNULL;
	const PGeometryStoreDataStaticArray64PairRealSint* pStoreDataSkin64 = HNULL;
	const PGeometryStoreDataVectorR3* pStoreDataPosition = HNULL;
	const PGeometryStoreDataVectorR3* pStoreDataNormal = HNULL;

	HSINT typeMatrixWeights = HCOMMON_INVALID_INDEX;
	HSINT vertexIndexMatrixWeights = HCOMMON_INVALID_INDEX;
	HSINT vertexIndexPosition = HCOMMON_INVALID_INDEX;
	HSINT vertexIndexNormal = HCOMMON_INVALID_INDEX;
	//HCOMMON_FOR_EACH_CONST( index, arrayDataStreamIndex, TArraySint )
	for( HSINT index = 0; index < arrayDataStreamIndex.SizeGet(); ++index )
	{
		const HSINT dataStreamIndex = arrayDataStreamIndex[ index ];
		const HSINT dataStreamType = in_typeSignature.DataStreamTypeGet( dataStreamIndex );
		const HString& dataStreamName = in_typeSignature.DataStreamNameGet( dataStreamIndex );
		if( ( PGeometryTypeSignature::NameGetPosition() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			pStoreDataPosition = &( in_geometry.StoreDataVectorR3Get( dataStreamIndex ) );
			vertexIndexPosition = index;
			out_vertexPosition.SizeSet( pStoreDataPosition->ArrayDataGet().SizeGet() * 3 );
		}
		else if( ( PGeometryTypeSignature::NameGetNormal() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			pStoreDataNormal = &( in_geometry.StoreDataVectorR3Get( dataStreamIndex ) );
			vertexIndexNormal = index;
			out_vertexNormal.SizeSet( pStoreDataNormal->ArrayDataGet().SizeGet() * 3 );
		}
		else if( PGeometryTypeSignature::NameGetSkinWeight() == dataStreamName )
		{
			if( PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint() == dataStreamType )
			{
				pStoreDataSkin4 = &( in_geometry.StoreDataStaticArray4PairRealSintGet( dataStreamIndex ) );
				typeMatrixWeights = dataStreamType;
				vertexIndexMatrixWeights = index;
			}
			else if( PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint() == dataStreamType )
			{
				pStoreDataSkin16 = &( in_geometry.StoreDataStaticArray16PairRealSintGet( dataStreamIndex ) );
				typeMatrixWeights = dataStreamType;
				vertexIndexMatrixWeights = index;
			}
			else if( PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint() == dataStreamType )
			{
				pStoreDataSkin64 = &( in_geometry.StoreDataStaticArray64PairRealSintGet( dataStreamIndex ) );
				typeMatrixWeights = dataStreamType;
				vertexIndexMatrixWeights = index;
			}
		}
	}

	if( ( HCOMMON_INVALID_INDEX == vertexIndexMatrixWeights ) ||
		( ( HNULL == pStoreDataPosition ) && ( HNULL == pStoreDataNormal ) ) )
	{
		//bail, no skinning info found
		return;
	}

	const PGeometryStoreVertexIndex& storeVertexIndex = in_geometry.StoreTopologyVertexIndexGet( in_topologyVertexIndex );
	for( HSINT index = 0; index < storeVertexIndex.DataArrayCountGet(); ++index )
	{
		const HSINT* const pArrayVertexDataIndex = storeVertexIndex.DataArrayIndexGet( index );
		HSINT positionDataIndex = HCOMMON_INVALID_INDEX;
		HSINT normalDataIndex = HCOMMON_INVALID_INDEX;
		if( HCOMMON_INVALID_INDEX != vertexIndexPosition )
		{
			positionDataIndex = pArrayVertexDataIndex[ vertexIndexPosition ];
		}
		if( HCOMMON_INVALID_INDEX != vertexIndexNormal )
		{
			normalDataIndex = pArrayVertexDataIndex[ vertexIndexNormal ];
		}

		if( HNULL != pStoreDataSkin4 )
		{
			LocalSkinDataProcess(
				index,
				out_vertexPosition,
				out_vertexNormal,
				pStoreDataSkin4->DataGet( pArrayVertexDataIndex[ vertexIndexMatrixWeights ] ),
				pStoreDataPosition,
				positionDataIndex,
				pStoreDataNormal,
				normalDataIndex,
				in_arrayMatrix
				);
		}
		else if( HNULL != pStoreDataSkin16 )
		{
			LocalSkinDataProcess(
				index,
				out_vertexPosition,
				out_vertexNormal,
				pStoreDataSkin16->DataGet( pArrayVertexDataIndex[ vertexIndexMatrixWeights ] ),
				pStoreDataPosition,
				positionDataIndex,
				pStoreDataNormal,
				normalDataIndex,
				in_arrayMatrix
				);
		}
		else if( HNULL != pStoreDataSkin64 )
		{
			LocalSkinDataProcess(
				index,
				out_vertexPosition,
				out_vertexNormal,
				pStoreDataSkin64->DataGet( pArrayVertexDataIndex[ vertexIndexMatrixWeights ] ),
				pStoreDataPosition,
				positionDataIndex,
				pStoreDataNormal,
				normalDataIndex,
				in_arrayMatrix
				);
		}
	}

	return;
}

/**/
const Hubris::HBOOL PGeometryUtility::SpringDataStreamIndexGet(
	Hubris::HSINT& out_positionDataStreamIndex,
	const PGeometryTypeSignature& in_typeSignature,
	const Hubris::HSINT in_topologyVertexIndex
	)
{
	const TArraySint& arrayDataStreamIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_topologyVertexIndex ); 
	HBOOL found = HFALSE;

	for( HSINT index = 0; index < arrayDataStreamIndex.SizeGet(); ++index )
	{
		const HSINT dataStreamIndex = arrayDataStreamIndex[ index ];
		const HSINT dataStreamType = in_typeSignature.DataStreamTypeGet( dataStreamIndex );
		const HString& dataStreamName = in_typeSignature.DataStreamNameGet( dataStreamIndex );
		if( ( PGeometryTypeSignature::NameGetPosition() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			out_positionDataStreamIndex = dataStreamIndex;
		}
		else if( ( PGeometryTypeSignature::NameGetSpring() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			found = HTRUE;
		}
	}

	return found;
}

/**/
HVOID PGeometryUtility::PerformSpring( 
	TArrayReal& in_out_vertexPosition,
	TArrayVector& in_out_vertexVelocity,
	const TArrayReal& in_targetVertexPosition,
	const PGeometryTypeSignature& in_typeSignature, 
	const PGeometry& in_geometry,
	const Hubris::HSINT in_topologyVertexIndex,
	const Hubris::HREAL in_timeDelta
	)
{
	//find the spring data index
	const TArraySint& arrayDataStreamIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_topologyVertexIndex ); 
	const PGeometryStoreDataVectorR3* pStoreDataSpring = HNULL;
	HSINT vertexDataIndexSpring = HCOMMON_INVALID_INDEX;
	HSINT vertexDataIndexPosition = HCOMMON_INVALID_INDEX;
	for( HSINT index = 0; index < arrayDataStreamIndex.SizeGet(); ++index )
	{
		const HSINT dataStreamIndex = arrayDataStreamIndex[ index ];
		const HSINT dataStreamType = in_typeSignature.DataStreamTypeGet( dataStreamIndex );
		const HString& dataStreamName = in_typeSignature.DataStreamNameGet( dataStreamIndex );
		if( ( PGeometryTypeSignature::NameGetSpring() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			pStoreDataSpring = &( in_geometry.StoreDataVectorR3Get( dataStreamIndex ) );
			vertexDataIndexSpring = index;
		}
		else if( ( PGeometryTypeSignature::NameGetPosition() == dataStreamName ) &&
			( PGeometryTypeSignature::TypeGetDataVectorR3() == dataStreamType ) )
		{
			vertexDataIndexPosition = index;
		}
	}

	if( ( HCOMMON_INVALID_INDEX == vertexDataIndexSpring ) ||
		( HCOMMON_INVALID_INDEX == vertexDataIndexPosition ) )
	{
		return;
	}

	//for each vertex, update the spring data
	const PGeometryStoreVertexIndex& storeVertexIndex = in_geometry.StoreTopologyVertexIndexGet( in_topologyVertexIndex );

	const HSINT vertexCount = storeVertexIndex.DataArrayCountGet();
	HCOMMON_ASSERT( in_targetVertexPosition.SizeGet() == vertexCount * 3, "invalid state" );
	if( in_out_vertexPosition.SizeGet() != in_targetVertexPosition.SizeGet() )
	{
		in_out_vertexPosition = in_targetVertexPosition;
	}
	in_out_vertexVelocity.SizeResize( vertexCount );

	HVectorR3 newDisplacement;
	HVectorR3 oldDisplacement;
	for( HSINT index = 0; index < storeVertexIndex.DataArrayCountGet(); ++index )
	{
		const HSINT* const pArrayVertexDataIndex = storeVertexIndex.DataArrayIndexGet( index );

		const HVectorR3& springData = pStoreDataSpring->DataGet( pArrayVertexDataIndex[ vertexDataIndexSpring ] );
		const HSINT positionIndex = pArrayVertexDataIndex[ vertexDataIndexPosition ];

		const HSINT baseIndex = ( positionIndex * 3 );

		oldDisplacement = HMatrixConstructor::HVectorR3Construct( 
			in_out_vertexPosition[ baseIndex ] - in_targetVertexPosition[ baseIndex ],
			in_out_vertexPosition[ baseIndex + 1 ] - in_targetVertexPosition[ baseIndex + 1 ],
			in_out_vertexPosition[ baseIndex + 2 ] - in_targetVertexPosition[ baseIndex + 2 ]
			);

		LSpringUtility::SpringVariablesTick(
			newDisplacement,
			in_out_vertexVelocity[ positionIndex ],
			oldDisplacement,
			in_out_vertexVelocity[ positionIndex ],
			in_timeDelta,
			LSpringParam(
				springData[ 0 ], //in_springConstant,
				springData[ 1 ], //in_springDamppenConstant,
				springData[ 2 ] //in_maximumDisplacement
				)
			);

		in_out_vertexPosition[ baseIndex ] = newDisplacement[ 0 ] + in_targetVertexPosition[ baseIndex ];
		in_out_vertexPosition[ baseIndex + 1 ] = newDisplacement[ 1 ] + in_targetVertexPosition[ baseIndex + 1 ];
		in_out_vertexPosition[ baseIndex + 2 ] = newDisplacement[ 2 ] + in_targetVertexPosition[ baseIndex + 2 ];
	}

	return;
}

/**/