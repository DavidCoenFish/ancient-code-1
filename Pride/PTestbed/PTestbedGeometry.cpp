//file: Pride/PTestbed/PTestbedGeometry.cpp

#include "Pride/PTestbed/PTestbedGeometry.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HSINT >TArraySint;
typedef HContainerPair< HREAL, HSINT >TPairRealSint;

//////////////////////////////////////////////////
// local free functions
static const PGeometryTypeSignature LocalTypeSignatureBigGet()
{
	PGeometryTypeSignature typeSignature;
	TArraySint arrayDataIndex;

	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataColour(), PGeometryTypeSignature::NameGetColour() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataColourReal(), PGeometryTypeSignature::NameGetColour() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataReal(), "weight" ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataRealSint(), PGeometryTypeSignature::NameGetSkinWeight() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "flag" ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), PGeometryTypeSignature::NameGetUv() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetNormal() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR4(), "rotation" ) );

	const HSINT vertexStoreIndex = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayDataIndex );
	typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle(), vertexStoreIndex );

	return typeSignature;
}

/**/
static const PGeometryTypeSignature LocalTypeSignatureSimpleGet()
{
	PGeometryTypeSignature typeSignature;
	TArraySint arrayDataIndex;

	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetNormal() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), PGeometryTypeSignature::NameGetUv() ) );
	arrayDataIndex.Insert( typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataColour(), PGeometryTypeSignature::NameGetColour() ) );

	const HSINT vertexStoreIndex = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayDataIndex );
	typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), vertexStoreIndex );

	return typeSignature;
}

/**/
static const HBOOL LocalTestbedGeometry()
{
	HBOOL success = HTRUE;

	const PGeometryTypeSignature typeSignature0 = LocalTypeSignatureBigGet();
	const PGeometryTypeSignature typeSignature1 = LocalTypeSignatureSimpleGet();

	//PGeometry( const PGeometryTypeSignature& in_typeSigniture ); 
	//PGeometry( const PGeometry& in_src ); 
	//~PGeometry(); 
	//const PGeometry& operator=( const PGeometry& in_rhs );
	//Hubris::HBOOL operator==( const PGeometry& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometry& in_rhs )const;
	{
		PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( geometry0 );
		PGeometry geometry2( typeSignature0 );
		PGeometry geometry3( typeSignature1 );
		PGeometry geometry4 = geometry0;

		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		PGeometryUtility::VertexAdd( typeSignature0, geometry2, vertex0 );

		success &= ( geometry0 == geometry1 );
		success &= ( geometry1 == geometry0 );

		success &= ( geometry0 == geometry4 );
		success &= ( geometry4 == geometry0 );
		
		success &= ( geometry0 != geometry2 );
		success &= ( geometry2 != geometry0 );

		success &= ( geometry0 != geometry3 );
		success &= ( geometry3 != geometry0 );

		success &= !( geometry0 != geometry1 );
		success &= !( geometry1 != geometry0 );
		
		success &= !( geometry0 == geometry2 );
		success &= !( geometry2 == geometry0 );

		success &= !( geometry0 == geometry3 );
		success &= !( geometry3 == geometry0 );
	}

	//HVOID Clear();
	{
		PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 );

		success &= ( geometry0 != geometry1 );

		geometry0.Clear();

		success &= ( geometry0 == geometry1 );
	}

	//const PGeometryTypeSignature PGeometry::TypeSignatureGet()const;
	{
		PGeometry geometry0( typeSignature0 );

		success &= ( typeSignature0 == geometry0.TypeSignatureGet() );
	}

	//const Hubris::HSINT StreamTopologyCountGet()const;
	//HVOID StreamTopologyInfoGet( const Hubris::HSINT in_index, Hubris::HSINT& out_type, Hubris::HString& out_name, Hubris::HSINT& out_channel, Hubris::HString& out_comment )const; 
	{
		PGeometry geometry0( typeSignature0 );

		success &= ( 2 == geometry0.TypeSignatureGet().TopologyStreamCountGet() );

		HSINT type;

		type = geometry0.TypeSignatureGet().TopologyStreamTypeGet( 0 ); 
		success &= ( type == PGeometryTypeSignature::TypeGetTopologyVertexIndex() );

		type = geometry0.TypeSignatureGet().TopologyStreamTypeGet( 1 ); 
		success &= ( type == PGeometryTypeSignature::TypeGetTopologyTriangle() );

	}

	//const PGeometryStoreVertexIndex& StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreVertexIndex& StoreTopologyVertexIndexGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreVertexIndex& store0 = geometry0.StoreTopologyVertexIndexGet( 0 );
		PGeometryStoreVertexIndex& store1 = geometry1.StoreTopologyVertexIndexGet( 0 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreTriangleStrip& StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreTriangleStrip& StoreTopologyTriangleStripGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature1 );
		PGeometry geometry1( typeSignature1 );

		const PGeometryStoreTriangleStrip& store0 = geometry0.StoreTopologyTriangleStripGet( 1 );
		PGeometryStoreTriangleStrip& store1 = geometry1.StoreTopologyTriangleStripGet( 1 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreTriangle& StoreTopologyTriangleGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreTriangle& StoreTopologyTriangleGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreTriangle& store0 = geometry0.StoreTopologyTriangleGet( 1 );
		PGeometryStoreTriangle& store1 = geometry1.StoreTopologyTriangleGet( 1 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataSint& StoreDataSintGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataSint& StoreDataSintGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataSint& store0 = geometry0.StoreDataSintGet( 4 );
		PGeometryStoreDataSint& store1 = geometry1.StoreDataSintGet( 4 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataReal& StoreDataRealGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataReal& StoreDataRealGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataReal& store0 = geometry0.StoreDataRealGet( 2 );
		PGeometryStoreDataReal& store1 = geometry1.StoreDataRealGet( 2 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataVectorR2& StoreDataVectorR2Get( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataVectorR2& StoreDataVectorR2Get( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataVectorR2& store0 = geometry0.StoreDataVectorR2Get( 5 );
		PGeometryStoreDataVectorR2& store1 = geometry1.StoreDataVectorR2Get( 5 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataVectorR3& StoreDataVectorR3Get( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataVectorR3& StoreDataVectorR3Get( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataVectorR3& store0 = geometry0.StoreDataVectorR3Get( 6 );
		PGeometryStoreDataVectorR3& store1 = geometry1.StoreDataVectorR3Get( 6 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataVectorR4& StoreDataVectorR4Get( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataVectorR4& StoreDataVectorR4Get( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataVectorR4& store0 = geometry0.StoreDataVectorR4Get( 8 );
		PGeometryStoreDataVectorR4& store1 = geometry1.StoreDataVectorR4Get( 8 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataRealSint& StoreDataRealSintGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataRealSint& StoreDataRealSintGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataRealSint& store0 = geometry0.StoreDataRealSintGet( 3 );
		PGeometryStoreDataRealSint& store1 = geometry1.StoreDataRealSintGet( 3 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataColourRgba& StoreDataColourRgbaGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataColourRgba& StoreDataColourRgbaGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataColourRgba& store0 = geometry0.StoreDataColourRgbaGet( 0 );
		PGeometryStoreDataColourRgba& store1 = geometry1.StoreDataColourRgbaGet( 0 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//const PGeometryStoreDataColourRealRgba& StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )const;
	//PGeometryStoreDataColourRealRgba& StoreDataColourRealRgbaGet( const Hubris::HSINT in_index );
	{
		const PGeometry geometry0( typeSignature0 );
		PGeometry geometry1( typeSignature0 );

		const PGeometryStoreDataColourRealRgba& store0 = geometry0.StoreDataColourRealRgbaGet( 1 );
		PGeometryStoreDataColourRealRgba& store1 = geometry1.StoreDataColourRealRgbaGet( 1 );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometry", success );

	return success;
}

/**/
static const HBOOL LocalTestbedOperator()
{
	HBOOL success = HTRUE;

	const PGeometryTypeSignature typeSignature0 = LocalTypeSignatureSimpleGet();

	{
		PGeometry geometry0( typeSignature0 );
		TArraySint arrayIndex;	

		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 2.0F, -1.5F, 0.5F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 0.5F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
		}

		{
			PGeometryStoreTriangleStrip& storeStrip = geometry0.StoreTopologyTriangleStripGet( 1 );
			storeStrip.StripAdd( arrayIndex.RawGet(), arrayIndex.SizeGet() );
			arrayIndex.Clear();
		}

		PGeometry geometry1( typeSignature0 );

		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 1.3F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.4F, 1.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.7F, 0.5F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry1, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 2.1F, -1.5F, 0.5F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.5F, 0.0F, 1.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 1.8F, 0.0F ) );
			vertex0.ColourRgbaSet( 3, PColourRgba( 112, 127, 200, 255 ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry1, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignature0, 0 );
			PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 0.9F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( -1.1F, 0.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.6F, 1.0F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry1, vertex0 ) );
		}
		{
			PGeometryStoreTriangleStrip& storeStrip = geometry1.StoreTopologyTriangleStripGet( 1 );
			storeStrip.StripAdd( arrayIndex.RawGet(), arrayIndex.SizeGet() );
			arrayIndex.Clear();
		}

		PGeometry geometry2( geometry0 );
		PGeometry geometry3 = geometry0 + geometry1;
		geometry2 += geometry1;

		success &= ( geometry3 == geometry2 );
		success &= ( geometry0 != geometry2 );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryOperator", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStoreData()
{
	HBOOL success = HTRUE;

	//PGeometryStoreData( const PGeometryStoreData& in_src );
	//PGeometryStoreData();
	//virtual ~PGeometryStoreData();
	//const PGeometryStoreData& operator=( const PGeometryStoreData& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryStoreData& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryStoreData& in_rhs )const;
	{
		PGeometryStoreDataSint storeDataSint0;
		storeDataSint0.DataAdd( 12705 );
		PGeometryStoreDataSint storeDataSint1( storeDataSint0 );
		PGeometryStoreDataSint storeDataSint2 = storeDataSint1;
		PGeometryStoreDataSint storeDataSint3;

		success &= ( storeDataSint0 == storeDataSint1 );
		success &= ( storeDataSint1 == storeDataSint0 );

		success &= ( storeDataSint0 == storeDataSint2 );
		success &= ( storeDataSint2 == storeDataSint0 );

		success &= ( storeDataSint0 != storeDataSint3 );
		success &= ( storeDataSint3 != storeDataSint0 );

		success &= !( storeDataSint0 != storeDataSint2 );
		success &= !( storeDataSint2 != storeDataSint0 );

		success &= !( storeDataSint0 == storeDataSint3 );
		success &= !( storeDataSint3 == storeDataSint0 );
	}

	//Hubris::HSINT DataUniqueAdd( const IN_TYPE& in_data );
	//Hubris::HSINT DataAdd( const IN_TYPE& in_data );
	//Hubris::HSINT SizeGet()const;
	//const IN_TYPE& DataGet( const Hubris::HSINT in_index )const;
	//IN_TYPE& DataGet( const Hubris::HSINT in_index );
	{
		PGeometryStoreDataSint storeDataSint0;
		success &= ( 0 == storeDataSint0.DataUniqueAdd( 5 ) );
		success &= ( 0 == storeDataSint0.DataUniqueAdd( 5 ) );
		success &= ( 1 == storeDataSint0.DataUniqueAdd( 6 ) );
		success &= ( 2 == storeDataSint0.DataAdd( 6 ) );

		success &= ( 3 == storeDataSint0.SizeGet() );

		success &= ( 5 == storeDataSint0.DataGet( 0 ) );
		success &= ( 6 == storeDataSint0.DataGet( 1 ) );

		const PGeometryStoreDataSint storeDataSint1( storeDataSint0 );

		success &= ( 5 == storeDataSint1.DataGet( 0 ) );
		success &= ( 6 == storeDataSint1.DataGet( 1 ) );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryStoreData", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStoreStrip()
{
	HBOOL success = HTRUE;

	//PGeometryStoreTriangleStrip( const PGeometryStoreTriangleStrip& in_src );
	//PGeometryStoreTriangleStrip();
	//virtual ~PGeometryStoreTriangleStrip();
	//const PGeometryStoreTriangleStrip& operator=( const PGeometryStoreTriangleStrip& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryStoreTriangleStrip& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryStoreTriangleStrip& in_rhs )const;
	{
		PGeometryStoreTriangleStrip store0( 0 );
		const HSINT pData[ 5 ] = { 12, 7, 0, 5, 6 };
		store0.StripAdd( pData, 5 );
		const PGeometryStoreTriangleStrip store1( store0 );
		const PGeometryStoreTriangleStrip store2 = store0;
		const PGeometryStoreTriangleStrip store3( 0 );

		success &= ( store0 == store1 );
		success &= ( store1 == store0 );

		success &= ( store0 == store2 );
		success &= ( store2 == store0 );

		success &= ( store0 != store3 );
		success &= ( store3 != store0 );

		success &= !( store0 != store2 );
		success &= !( store2 != store0 );

		success &= !( store0 == store3 );
		success &= !( store3 == store0 );
	}

	//HVOID StripAdd( const Hubris::HSINT* const in_pArrayVertexIndexes, const Hubris::HSINT in_vertexIndexCount );  
	//const Hubris::HSINT TriangleCountGet()const{ return m_triangleCount; }
	//const Hubris::HSINT StripCountGet()const;
	//const Hubris::HSINT StripLengthGet( const Hubris::HSINT in_stripIndex )const;
	//const Hubris::HSINT* StripDataGet( const Hubris::HSINT in_stripIndex )const;
	{
		PGeometryStoreTriangleStrip store0( 0 );
		const HSINT pData0[ 5 ] = { 12, 7, 0, 5, 6 };
		const HSINT pData1[ 4 ] = { 3, 6, 4, 7 };
		store0.StripAdd( pData0, 5 );
		store0.StripAdd( pData1, 4 );

		success &= ( 5 == store0.TriangleCountGet() );
		success &= ( 2 == store0.StripCountGet() );
		success &= ( 5 == store0.StripLengthGet( 0 ) );
		success &= ( 4 == store0.StripLengthGet( 1 ) );

		const HSINT* const pData2 = store0.StripDataGet( 1 );
		for( HSINT index = 0; index < 4; ++index )
		{
			success &= ( pData2[ index ] == pData1[ index ] );
		}
	}

	//const Hubris::HSINT TargetVertexIndexStoreChannelGet()const{ return m_targetVertexIndexStoreChannel; }
	//HVOID TargetVertexIndexStoreChannelSet( const Hubris::HSINT in_targetChannel ){ m_targetVertexIndexStoreChannel = in_targetChannel; return; }
	{
		PGeometryStoreTriangleStrip store0( 0 );
		success &= ( 0 == store0.TargetTopologyVertexIndexGet() );

		//store0.TargetTopologyVertexIndexSet( 5 );
		//success &= ( 5 == store0.TargetTopologyVertexIndexGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryStoreTriangleStrip", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStoreTriangle()
{
	HBOOL success = HTRUE;

	//PGeometryStoreTriangle( const PGeometryStoreTriangle& in_src );
	//PGeometryStoreTriangle();
	//virtual ~PGeometryStoreTriangle();
	//const PGeometryStoreTriangle& operator=( const PGeometryStoreTriangle& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryStoreTriangle& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryStoreTriangle& in_rhs )const;
	{
		PGeometryStoreTriangle store0( 0 );
		const HSINT pData[ 3 ] = { 12, 7, 0 };
		store0.TriangleAdd( pData[ 0 ], pData[ 1 ], pData[ 2 ] );
		const PGeometryStoreTriangle store1( store0 );
		const PGeometryStoreTriangle store2 = store0;
		const PGeometryStoreTriangle store3( 0 );

		success &= ( store0 == store1 );
		success &= ( store1 == store0 );

		success &= ( store0 == store2 );
		success &= ( store2 == store0 );

		success &= ( store0 != store3 );
		success &= ( store3 != store0 );

		success &= !( store0 != store2 );
		success &= !( store2 != store0 );

		success &= !( store0 == store3 );
		success &= !( store3 == store0 );
	}

	//HVOID TriangleAdd( const Hubris::HSINT in_vertexIndexOne, const Hubris::HSINT in_vertexIndexTwo, const Hubris::HSINT in_vertexIndexThree );  
	//const Hubris::HSINT TriangleCountGet()const;
	//HVOID TriangleGet( const Hubris::HSINT in_triangleIndex, Hubris::HSINT& out_vertexIndexOne, Hubris::HSINT& out_vertexIndexTwo, Hubris::HSINT& out_vertexIndexThree )const;
	{
		PGeometryStoreTriangle store0( 0 );
		const HSINT pData0[ 3 ] = { 12, 7, 0 };
		const HSINT pData1[ 3 ] = { 1, 2, 3 };
		const HSINT pData2[ 3 ] = { 4, 0, 6 };
		store0.TriangleAdd( pData0[ 0 ], pData0[ 1 ], pData0[ 2 ] );
		store0.TriangleAdd( pData1[ 0 ], pData1[ 1 ], pData1[ 2 ] );
		store0.TriangleAdd( pData2[ 0 ], pData2[ 1 ], pData2[ 2 ] );

		success &= ( 3 == store0.TriangleCountGet() );
		HSINT pData3[ 3 ];
		store0.TriangleGet( 2, pData3[ 0 ], pData3[ 1 ], pData3[ 2 ] );

		for( HSINT index = 0; index < 3; ++index )
		{
			success &= ( pData3[ index ] == pData2[ index ] );
		}
	}

	//const Hubris::HSINT TargetVertexIndexStoreChannelGet()const{ return m_targetVertexIndexStoreChannel; }
	//HVOID TargetVertexIndexStoreChannelSet( const Hubris::HSINT in_targetChannel ){ m_targetVertexIndexStoreChannel = in_targetChannel; return; }
	{
		PGeometryStoreTriangle store0( 0 );
		success &= ( 0 == store0.TargetTopologyVertexIndexGet() );

		//store0.TargetTopologyVertexIndexSet( 5 );
		//success &= ( 5 == store0.TargetTopologyVertexIndexGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryStoreTriangle", success );

	return success;
}

/**/
static const HBOOL LocalTestbedStoreVertexIndex()
{
	HBOOL success = HTRUE;

	//PGeometryStoreVertexIndex( const PGeometryStoreVertexIndex& in_src );
	//PGeometryStoreVertexIndex( const Hubris::HSINT in_stride );
	//~PGeometryStoreVertexIndex();
	//const PGeometryStoreVertexIndex& operator=( const PGeometryStoreVertexIndex& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryStoreVertexIndex& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryStoreVertexIndex& in_rhs )const;
	{
		PGeometryStoreVertexIndex store0( 3 );
		const HSINT pData[ 3 ] = { 12, 7, 0 };
		store0.DataArrayIndexAdd( pData );
		const PGeometryStoreVertexIndex store1( store0 );
		const PGeometryStoreVertexIndex store2 = store0;
		const PGeometryStoreVertexIndex store3( 3 );

		success &= ( store0 == store1 );
		success &= ( store1 == store0 );

		success &= ( store0 == store2 );
		success &= ( store2 == store0 );

		success &= ( store0 != store3 );
		success &= ( store3 != store0 );

		success &= !( store0 != store2 );
		success &= !( store2 != store0 );

		success &= !( store0 == store3 );
		success &= !( store3 == store0 );
	}

	//Hubris::HSINT DataArrayIndexUniqueAdd( const Hubris::HSINT* const in_pArrayDataIndexes );
	//Hubris::HSINT DataArrayIndexAdd( const Hubris::HSINT* const in_pArrayDataIndexes );
	//const Hubris::HSINT StrideGet()const{ return m_stride; }
	//const Hubris::HSINT DataArrayCountGet()const;
	//const Hubris::HSINT* const DataArrayIndexGet( const Hubris::HSINT in_index )const;
	{
		PGeometryStoreVertexIndex store0( 3 );
		const HSINT pData0[ 3 ] = { 12, 7, 0 };
		const HSINT pData1[ 3 ] = { 0, 1, 5 };
		const HSINT pData2[ 3 ] = { 0, 7, 7 };
		const HSINT pData3[ 3 ] = { 1, 1, 5 };

		success &= ( 0 == store0.DataArrayIndexAdd( pData0 ) );
		success &= ( 1 == store0.DataArrayIndexAdd( pData1 ) );
		success &= ( 2 == store0.DataArrayIndexAdd( pData2 ) );
		success &= ( 1 == store0.DataArrayIndexUniqueAdd( pData1 ) );
		success &= ( 3 == store0.DataArrayIndexAdd( pData3 ) );

		success &= ( 3 == store0.StrideGet() );
		success &= ( 4 == store0.DataArrayCountGet() );

		const HSINT* const pData4 = store0.DataArrayIndexGet( 3 );
		for( HSINT index = 0; index < 3; ++index )
		{
			success &= ( pData3[ index ] == pData4[ index ] );
		}
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryStoreStoreVertexIndex", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTrait()
{
	HBOOL success = HTRUE;

	const PGeometryTypeSignature typeSignature0 = LocalTypeSignatureSimpleGet();

	PGeometry geometry0( typeSignature0 );
	TArraySint arrayIndex;	

	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
	}
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.5F, 2.0F ) );
		vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 0.0F ) );
		vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ) );

		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
	}
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 2.0F, -1.5F, 0.5F ) );
		vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
		vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );

		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
	}
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 0.5F, 1.5F, 2.0F ) );
		vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, 0.0F ) );
		vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ) );

		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );
	}

	{
		PGeometryStoreTriangleStrip& storeStrip = geometry0.StoreTopologyTriangleStripGet( 1 );
		storeStrip.StripAdd( arrayIndex.RawGet(), arrayIndex.SizeGet() );
		arrayIndex.Clear();
	}

	HFileSystem fileSystem;
	{
		EMemento memento;
		EMementoCollect collect( memento );
		collect.MemberAdd( "geometry", geometry0 );
		EMementoUtility::SaveText( fileSystem, "data\\geometry_memento.txt", memento );
		EMementoUtility::SaveBinary( fileSystem, "data\\geometry_memento.bin", memento );
	}

	{
		PGeometry geometry1;
		EMemento memento;
		EMementoUtility::Load( fileSystem, "data\\geometry_memento.txt", memento );
		EMementoAssign assign( memento );
		assign.MemberGet( "geometry", geometry1 );

		success &= ( geometry0 == geometry1 );
	}


	return success;
}

/**/
static const HBOOL LocalTestbedTypeSignature()
{
	HBOOL success = HTRUE;

	//PGeometryTypeSignature( const PGeometryTypeSignature& in_src  );
	//PGeometryTypeSignature( const PGeometryTypeSignatureImplementation& in_src );
	//PGeometryTypeSignature();
	//~PGeometryTypeSignature();
	//const PGeometryTypeSignature& operator=( const PGeometryTypeSignature& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryTypeSignature& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryTypeSignature& in_rhs )const;
	{
		PGeometryTypeSignature typeSignature0;
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataReal(), "foo" );
		const PGeometryTypeSignature typeSignature1( typeSignature0 );
		const PGeometryTypeSignature typeSignature2 = typeSignature0;
		const PGeometryTypeSignature typeSignature3;

		success &= ( typeSignature0 == typeSignature1 );
		success &= ( typeSignature1 == typeSignature0 );

		success &= ( typeSignature0 == typeSignature2 );
		success &= ( typeSignature2 == typeSignature0 );

		success &= ( typeSignature0 != typeSignature3 );
		success &= ( typeSignature3 != typeSignature0 );

		success &= !( typeSignature0 != typeSignature2 );
		success &= !( typeSignature2 != typeSignature0 );

		success &= !( typeSignature0 == typeSignature3 );
		success &= !( typeSignature3 == typeSignature0 );
	}

	//const PGeometryTypeSignature& operator|=( const PGeometryTypeSignature& in_rhs );
	//const PGeometryTypeSignature& operator&=( const PGeometryTypeSignature& in_rhs );
	//{
	//	PGeometryTypeSignature typeSignature0;
	//	typeSignature0.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex() );
	//	typeSignature0.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle() );
	//	typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataReal(), "foo" );
	//	typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "goo" );

	//	PGeometryTypeSignature typeSignature1;
	//	typeSignature1.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "goo" );
	//	typeSignature1.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), "moo" );

	//	PGeometryTypeSignature typeSignature2( typeSignature0 );
	//	PGeometryTypeSignature typeSignature3( typeSignature0 );
	//	typeSignature2 |= typeSignature1;
	//	typeSignature3 &= typeSignature1;

	//	success &= ( 2 == typeSignature2.TopologyStreamCountGet() );
	//	success &= ( 3 == typeSignature2.DataStreamCountGet() );
	//}

	//HVOID TopologyStreamAdd( const Hubris::HSINT in_type, const Hubris::HSINT in_channel = 0, const Hubris::HString& in_comment = HNULL );
	//const Hubris::HSINT TopologyStreamCountGet()const;
	//HVOID TopologyStreamGet( const Hubris::HSINT in_index, Hubris::HSINT& out_type, Hubris::HSINT& out_channel, Hubris::HString& out_comment )const; 
	//HVOID TopologyStreamRemove( const Hubris::HSINT in_index );
	//const Hubris::HBOOL TopologyStreamTest( const Hubris::HSINT in_type, const Hubris::HSINT in_channel = 0 )const;
	//const Hubris::HSINT TopologyStreamTypeGet( const Hubris::HSINT in_index )const;
	{
		PGeometryTypeSignature typeSignature0;
		const HSINT vertexIndex = typeSignature0.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), 0 );
		typeSignature0.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle(), vertexIndex );
		typeSignature0.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), 1 );

		success &= ( 3 == typeSignature0.TopologyStreamCountGet() );

		HSINT type = typeSignature0.TopologyStreamTypeGet( 1 );
		success &= ( type == PGeometryTypeSignature::TypeGetTopologyTriangle() );

		type = typeSignature0.TopologyStreamTypeGet( 2 );
		success &= ( type == PGeometryTypeSignature::TypeGetTopologyVertexIndex() );
	}

	//HVOID DataStreamAdd( const Hubris::HSINT in_type, const Hubris::HString& in_name, const Hubris::HSINT in_channel = 0, const Hubris::HString& in_comment = HNULL );
	//const Hubris::HSINT DataStreamCountGet()const;
	//HVOID DataStreamGet( const Hubris::HSINT in_index, Hubris::HSINT& out_type, Hubris::HString& out_name, Hubris::HSINT& out_channel, Hubris::HString& out_comment )const; 
	//HVOID DataStreamRemove( const Hubris::HSINT in_index );
	//const Hubris::HBOOL DataStreamTest( const Hubris::HSINT in_type, const Hubris::HString& in_name, const Hubris::HSINT in_channel = 0 )const;
	//const Hubris::HSINT DataStreamTypeGet( const Hubris::HSINT in_index )const;
	{
		PGeometryTypeSignature typeSignature0;
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataReal(), "foo" );
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "goo" );
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "goo" );
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), "moo" );
		typeSignature0.DataStreamAdd( PGeometryTypeSignature::TypeGetDataSint(), "goo" );

		success &= ( 5 == typeSignature0.DataStreamCountGet() );

		HSINT type = typeSignature0.DataStreamTypeGet( 2 );
		HString name = typeSignature0.DataStreamNameGet( 2 );
		success &= ( type == PGeometryTypeSignature::TypeGetDataSint() );
		success &= ( "goo" == name );

		success &= ( PGeometryTypeSignature::TypeGetDataSint() == typeSignature0.DataStreamTypeGet( 4 ) );
	}

	//static const Hubris::HSINT TypeGetTopologyVertexIndex();
	//static const Hubris::HSINT TypeGetTopologyTriangle();
	//static const Hubris::HSINT TypeGetTopologyTriangleStrip();
	//static const Hubris::HSINT TypeGetDataSint(); 
	//static const Hubris::HSINT TypeGetDataReal();
	//static const Hubris::HSINT TypeGetDataRealSint(); //weight
	//static const Hubris::HSINT TypeGetDataVectorR2();
	//static const Hubris::HSINT TypeGetDataVectorR3();
	//static const Hubris::HSINT TypeGetDataVectorR4();
	//static const Hubris::HSINT TypeGetDataColour();
	//static const Hubris::HSINT TypeGetDataColourReal();
	//static const Hubris::HString NameGetTopology();
	//static const Hubris::HString NameGetPosition();
	//static const Hubris::HString NameGetNormal();
	//static const Hubris::HString NameGetColour();
	//static const Hubris::HString NameGetUv();
	//static const Hubris::HString NameGetContinuity();//smoothing~ spline
	//static const Hubris::HString NameGetSkinWeight();// 
	{
		PGeometryTypeSignature::TypeGetTopologyVertexIndex();
		PGeometryTypeSignature::TypeGetTopologyTriangle();
		PGeometryTypeSignature::TypeGetTopologyTriangleStrip();
		PGeometryTypeSignature::TypeGetDataSint(); 
		PGeometryTypeSignature::TypeGetDataReal();
		PGeometryTypeSignature::TypeGetDataRealSint();
		PGeometryTypeSignature::TypeGetDataVectorR2();
		PGeometryTypeSignature::TypeGetDataVectorR3();
		PGeometryTypeSignature::TypeGetDataVectorR4();
		PGeometryTypeSignature::TypeGetDataColour();
		PGeometryTypeSignature::TypeGetDataColourReal();
		//PGeometryTypeSignature::NameGetTopology();
		PGeometryTypeSignature::NameGetPosition();
		PGeometryTypeSignature::NameGetNormal();
		PGeometryTypeSignature::NameGetColour();
		PGeometryTypeSignature::NameGetUv();
		PGeometryTypeSignature::NameGetContinuity();
		PGeometryTypeSignature::NameGetSkinWeight();
	}


	PTESTBED_VALIDATE_STATUS( "PGeometryTypeSignature", success );

	return success;
}

/**/
static const HBOOL LocalTestbedUtility()
{
	HBOOL success = HTRUE;

	const PGeometryTypeSignature typeSignature0 = LocalTypeSignatureBigGet();
	const PGeometryTypeSignature typeSignatureSimple = LocalTypeSignatureSimpleGet();

	//struct PGeometryUtility
	//static Hubris::HSINT VertexUniqueAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex, const Hubris::HSINT in_channel = 0 );
	//static Hubris::HSINT VertexAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex, const Hubris::HSINT in_channel = 0  );
	//static HVOID VertexGet( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex, const PGeometry& in_geometry, const Hubris::HSINT in_index, const Hubris::HSINT in_channel = 0  );
	{
		PGeometry geometry0( typeSignature0 );
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );
		vertex0.RealSet( 2, 10.3F );
		PGeometryVertex vertex1( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex1 );
		vertex1.SintSet( 4, 12 );
		vertex1.ColourRgbaSet( 0, PColourRgba( 105, 127, 200, 150 ) );

		success &= ( 0 == PGeometryUtility::VertexUniqueAdd( typeSignature0, geometry0, vertex0 ) );
		success &= ( 1 == PGeometryUtility::VertexUniqueAdd( typeSignature0, geometry0, vertex1 ) );
		success &= ( 0 == PGeometryUtility::VertexUniqueAdd( typeSignature0, geometry0, vertex0 ) );
		success &= ( 2 == PGeometryUtility::VertexAdd( typeSignature0, geometry0, vertex0 ) );

		PGeometryVertex vertex2( typeSignature0, 0 );
		PGeometryUtility::VertexGet( typeSignature0, vertex2, geometry0, 1 );
		success &= ( vertex1 == vertex2 );
	}

	//static const PGeometryStoreVertexIndex& StoreVertexIndexGet( const PGeometryTypeSignature& in_typeSignature, const PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	//static PGeometryStoreVertexIndex& StoreVertexIndexGet( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	{
		PGeometryTypeSignature typeSignature2( typeSignature0 );
		const HSINT vertexStoreIndexOne = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), 1 );
		const HSINT vertexStoreIndexTwo = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), 2 );

		const PGeometry geometry0( typeSignature2 );
		PGeometry geometry1( typeSignature2 );

		const PGeometryStoreVertexIndex& vertexIndex0 = geometry0.StoreTopologyVertexIndexGet( vertexStoreIndexOne );
		PGeometryStoreVertexIndex& vertexIndex1 = geometry1.StoreTopologyVertexIndexGet( vertexStoreIndexTwo );

		success &= ( HNULL != &vertexIndex0 );
		success &= ( HNULL != &vertexIndex1 );
	}

	//static const PGeometryStoreTriangleStrip& StoreStripGet( const PGeometryTypeSignature& in_typeSignature, const PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	//static PGeometryStoreTriangleStrip& StoreStripGet( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	{
		PGeometryTypeSignature typeSignature2( typeSignature0 );
		const HSINT vertexStoreIndexOne = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), 1 );
		const HSINT vertexStoreIndexTwo = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), 2 );

		const PGeometry geometry0( typeSignature2 );
		PGeometry geometry1( typeSignature2 );

		const PGeometryStoreTriangleStrip& store0 = geometry0.StoreTopologyTriangleStripGet( vertexStoreIndexOne );
		PGeometryStoreTriangleStrip& store1 = geometry1.StoreTopologyTriangleStripGet( vertexStoreIndexTwo );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//static const PGeometryStoreTriangle& StoreTriangleGet( const PGeometryTypeSignature& in_typeSignature, const PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	//static PGeometryStoreTriangle& StoreTriangleGet( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_geometry, const Hubris::HSINT in_channel = 0 );
	{
		PGeometryTypeSignature typeSignature2( typeSignature0 );
		const HSINT vertexStoreIndexOne = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle(), 1 );
		const HSINT vertexStoreIndexTwo = typeSignature2.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangle(), 2 );

		const PGeometry geometry0( typeSignature2 );
		PGeometry geometry1( typeSignature2 );

		const PGeometryStoreTriangle& store0 = geometry0.StoreTopologyTriangleGet( vertexStoreIndexOne );
		PGeometryStoreTriangle& store1 = geometry1.StoreTopologyTriangleGet( vertexStoreIndexTwo );

		success &= ( HNULL != &store0 );
		success &= ( HNULL != &store1 );
	}

	//static HVOID PGeometryConvert( PGeometry& out_destGeometry, const PGeometry& in_srcGenericGeometry );
	{
		PGeometry geometryBig( typeSignature0 );
		PGeometry geometrySimple( typeSignatureSimple );

		TArraySint arrayIndex;	

		{
			PGeometryVertex vertex0( typeSignatureSimple, 0 );
			PGeometryUtility::DefaultVertex( typeSignatureSimple, vertex0 );
			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignatureSimple, geometrySimple, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignatureSimple, 0 );
			PGeometryUtility::DefaultVertex( typeSignatureSimple, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignatureSimple, geometrySimple, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignatureSimple, 0 );
			PGeometryUtility::DefaultVertex( typeSignatureSimple, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 2.0F, -1.5F, 0.5F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignatureSimple, geometrySimple, vertex0 ) );
		}
		{
			PGeometryVertex vertex0( typeSignatureSimple, 0 );
			PGeometryUtility::DefaultVertex( typeSignatureSimple, vertex0 );
			vertex0.VectorR3Set( 0, HMatrixConstructor::HVectorR3Construct( 0.5F, 1.5F, 2.0F ) );
			vertex0.VectorR3Set( 1, HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, 0.0F ) );
			vertex0.VectorR2Set( 2, HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ) );

			arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignatureSimple, geometrySimple, vertex0 ) );
		}

		{
			PGeometryStoreTriangleStrip& storeStrip =  geometrySimple.StoreTopologyTriangleStripGet( 1 );
			storeStrip.StripAdd( arrayIndex.RawGet(), arrayIndex.SizeGet() );
		}

		PGeometryUtility::PGeometryConvert( geometryBig, geometrySimple, typeSignature0, typeSignatureSimple );

		success &= ( 2 == geometryBig.StoreTopologyTriangleGet( 1 ).TriangleCountGet() );
	}

	//static HVOID DefaultVertex( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex );
	{
		PGeometry geometry0( typeSignature0 );
		PGeometryVertex vertex0( typeSignature0, 0 );
		PGeometryVertex vertex1( typeSignature0, 0 );
		PGeometryUtility::DefaultVertex( typeSignature0, vertex0 );

		success &= ( vertex0 != vertex1 );
		success &= ( 0.0F == vertex0.RealGet( 2 ) );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryUtility", success );

	return success;
}

/**/
static const HBOOL LocalTestbedVertex()
{
	HBOOL success = HTRUE;
	const PGeometryTypeSignature typeSignature0 = LocalTypeSignatureBigGet();

	//PGeometryVertex( const PGeometryTypeSignature& in_typeSigniture );
	//PGeometryVertex( const PGeometryVertex& in_src );
	//~PGeometryVertex();
	//const PGeometryVertex& operator=( const PGeometryVertex& in_rhs );
	//Hubris::HBOOL operator==( const PGeometryVertex& in_rhs )const;
	//Hubris::HBOOL operator!=( const PGeometryVertex& in_rhs )const;
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		vertex0.RealSet( 2, 10.3F );
		PGeometryVertex vertex1( vertex0 );
		PGeometryVertex vertex2 = vertex1;
		PGeometryVertex vertex3( typeSignature0, 0 );

		success &= ( vertex0 == vertex1 );
		success &= ( vertex1 == vertex0 );

		success &= ( vertex0 == vertex2 );
		success &= ( vertex2 == vertex0 );

		success &= ( vertex0 != vertex3 );
		success &= ( vertex3 != vertex0 );

		success &= !( vertex0 != vertex2 );
		success &= !( vertex2 != vertex0 );

		success &= !( vertex0 == vertex3 );
		success &= !( vertex3 == vertex0 );
	}

	//HVOID Clear();
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		vertex0.RealSet( 2, 10.3F );
		PGeometryVertex vertex1( typeSignature0, 0 );

		success &= ( vertex0 != vertex1 );
		vertex0.Clear();
		success &= ( vertex0 == vertex1 );
	}

	//const PGeometryTypeSignature TypeSignatureGet()const;
	{
		PGeometryVertex vertex0( typeSignature0, 0 );

		success &= ( typeSignature0 == vertex0.TypeSignatureGet() );
	}

	//Hubris::HSINT SintGet( const Hubris::HSINT in_index )const;
	//HVOID SintSet( const Hubris::HSINT in_index, const Hubris::HSINT in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		vertex0.SintSet( 4, 1004 );
		success &= ( 1004 == vertex0.SintGet( 4 ) );
	}

	//Hubris::HSINT RealGet( const Hubris::HSINT in_index )const;
	//HVOID RealSet( const Hubris::HSINT in_index, const Hubris::HREAL in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		vertex0.RealSet( 2, 10.5F );
		success &= ( 10.5F == vertex0.RealGet( 2 ) );
	}

	//TPairRealSint RealSintGet( const Hubris::HSINT in_index )const;
	//HVOID RealSintSet( const Hubris::HSINT in_index, const TPairRealSint& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		TPairRealSint pair0;
		pair0.m_first = 10.6F;
		pair0.m_second = 11;

		vertex0.RealSintSet( 3, pair0 );
		success &= ( pair0 == vertex0.RealSintGet( 3 ) );
	}

	//Hubris::HVectorR2 VectorR2Get( const Hubris::HSINT in_index )const;
	//HVOID VectorR2Set( const Hubris::HSINT in_index, const Hubris::HVectorR2& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		const HVectorR2 vector0 = HMatrixConstructor::HVectorR2Construct( 10.36F, 11.7F );
		vertex0.VectorR2Set( 5, vector0 );
		success &= ( vector0 == vertex0.VectorR2Get( 5 ) );
	}

	//Hubris::HVectorR3 VectorR3Get( const Hubris::HSINT in_index )const;
	//HVOID VectorR3Set( const Hubris::HSINT in_index, const Hubris::HVectorR3& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		const HVectorR3 vector0 = HMatrixConstructor::HVectorR3Construct( 10.36F, 11.7F, 7.4F );
		vertex0.VectorR3Set( 6, vector0 );
		success &= ( vector0 == vertex0.VectorR3Get( 6 ) );
	}

	//Hubris::HVectorR4 VectorR4Get( const Hubris::HSINT in_index )const;
	//HVOID VectorR4Set( const Hubris::HSINT in_index, const Hubris::HVectorR4& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		const HVectorR4 vector0 = HMatrixConstructor::HVectorR4Construct( 10.36F, 11.7F, 7.4F, 3.4F );
		vertex0.VectorR4Set( 8, vector0 );
		success &= ( vector0 == vertex0.VectorR4Get( 8 ) );
	}

	//Pride::PColourRgba ColourRgbaGet( const Hubris::HSINT in_index )const;
	//HVOID ColourRgbaSet( const Hubris::HSINT in_index, const Pride::PColourRgba& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		const PColourRgba colour0( 111, 7, 204, 128 );
		vertex0.ColourRgbaSet( 0, colour0 );
		success &= ( colour0 == vertex0.ColourRgbaGet( 0 ) );
	}

	//Pride::PColourRealRgba ColourRgbaRealGet( const Hubris::HSINT in_index )const;
	//HVOID ColourRgbaRealSet( const Hubris::HSINT in_index, const Pride::PColourRealRgba& in_value );
	{
		PGeometryVertex vertex0( typeSignature0, 0 );
		const PColourRealRgba colour0( 0.3F, 1.2F, 0.5F, 0.75F );
		vertex0.ColourRgbaRealSet( 1, colour0 );
		success &= ( colour0 == vertex0.ColourRgbaRealGet( 1 ) );
	}

	PTESTBED_VALIDATE_STATUS( "PGeometryVertex", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedGeometry()
{
	PTESTBED_VALIDATE_START( "TestbedGeometry" );
	HBOOL success = HTRUE;

	success &= LocalTestbedGeometry();
	success &= LocalTestbedOperator();
	success &= LocalTestbedStoreData();
	success &= LocalTestbedStoreStrip();
	success &= LocalTestbedStoreTriangle();
	success &= LocalTestbedStoreVertexIndex();
	success &= LocalTestbedTrait();
	success &= LocalTestbedTypeSignature();
	success &= LocalTestbedUtility();
	success &= LocalTestbedVertex();

	return success;
}

/**/