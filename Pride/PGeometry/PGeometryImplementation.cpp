//file: Pride/PGeometry/PGeometryImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryImplementation.h"

#include "Pride/PGeometry/PGeometryStoreData.h"
#include "Pride/PGeometry/PGeometryStoreInterface.h"
#include "Pride/PGeometry/PGeometryStoreTriangleStrip.h"
#include "Pride/PGeometry/PGeometryStoreTriangle.h"
#include "Pride/PGeometry/PGeometryStoreVertexIndex.h"
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >


/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PGeometryStoreInterface* >TArrayStore;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalRelease( TArrayStore& in_out_arrayStore )
{
	HCOMMON_FOR_EACH( pStore, in_out_arrayStore, TArrayStore )
	{
		HCOMMON_ASSERT( HNULL != pStore, "invalid member" );
		delete pStore;
	}

	in_out_arrayStore.Clear();

	return;
}

/**/
static Hubris::HVOID LocalCreate( TArrayStore& out_arrayTopology, TArrayStore& out_arrayData, const PGeometryTypeSignatureImplementation& in_typeSignature )
{
	HCOMMON_ASSERT( 0 == out_arrayTopology.SizeGet(), "invalid state" );
	HCOMMON_ASSERT( 0 == out_arrayData.SizeGet(), "invalid state" );

	const HSINT topologyCount = in_typeSignature.TopologyStreamCountGet(); 
	out_arrayTopology.SizeSet( topologyCount );
	const HSINT dataCount = in_typeSignature.DataStreamCountGet(); 
	out_arrayData.SizeSet( dataCount );

	for( HSINT index = 0; index < topologyCount; ++index )
	{
		const HSINT type = in_typeSignature.TopologyStreamTypeGet( index );

		if( type == PGeometryTypeSignatureImplementation::TypeGetTopologyVertexIndex() )
		{
			PGeometryStoreVertexIndex* pStore = HNULL;
			HCOMMON_NEW_PARAM( pStore, PGeometryStoreVertexIndex, dataCount );
			out_arrayTopology[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetTopologyTriangleStrip() )
		{
			PGeometryStoreTriangleStrip* pStore = HNULL;
			const TArraySint& arraySint = in_typeSignature.TopologyStreamArrayIndexGet( index );
			HCOMMON_ASSERT( 1 == arraySint.SizeGet(), "invalid data for topography store, expect one index" );
			HCOMMON_NEW_PARAM( 
				pStore, 
				PGeometryStoreTriangleStrip,
				arraySint[ 0 ]
				);
			out_arrayTopology[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetTopologyTriangle() )
		{
			PGeometryStoreTriangle* pStore = HNULL;
			const TArraySint& arraySint = in_typeSignature.TopologyStreamArrayIndexGet( index );
			HCOMMON_ASSERT( 1 == arraySint.SizeGet(), "invalid data for topography store, expect one index" );
			HCOMMON_NEW_PARAM( 
				pStore, 
				PGeometryStoreTriangle,
				arraySint[ 0 ]
				);
			out_arrayTopology[ index ] = pStore;
			continue;
		}

		HCOMMON_ASSERT_ALWAYS( HString( "unknown type:" + HTraitStringIn( type ) ).RawGet() );
	}

	for( HSINT index = 0; index < dataCount; ++index )
	{
		const HSINT type = in_typeSignature.DataStreamTypeGet( index );

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataReal() )
		{
			PGeometryStoreDataReal* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataReal );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataRealSint() )
		{
			PGeometryStoreDataRealSint* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataRealSint );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataSint() )
		{
			PGeometryStoreDataSint* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataSint );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR2() )
		{
			PGeometryStoreDataVectorR2* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataVectorR2 );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR3() )
		{
			PGeometryStoreDataVectorR3* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataVectorR3 );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR4() )
		{
			PGeometryStoreDataVectorR4* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataVectorR4 );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataColour() )
		{
			PGeometryStoreDataColourRgba* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataColourRgba );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataColourReal() )
		{
			PGeometryStoreDataColourRealRgba* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataColourRealRgba );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray4PairRealSint() )
		{
			PGeometryStoreDataStaticArray4PairRealSint* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataStaticArray4PairRealSint );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray16PairRealSint() )
		{
			PGeometryStoreDataStaticArray16PairRealSint* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataStaticArray16PairRealSint );
			out_arrayData[ index ] = pStore;
			continue;
		}

		if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray64PairRealSint() )
		{
			PGeometryStoreDataStaticArray64PairRealSint* pStore = HNULL;
			HCOMMON_NEW( pStore, PGeometryStoreDataStaticArray64PairRealSint );
			out_arrayData[ index ] = pStore;
			continue;
		}

		HCOMMON_ASSERT_ALWAYS( HString( "unknown type:" + HTraitStringIn( type ) ).RawGet() );
	}

	return;
}

///////////////////////////////////////////////////////
// creation
PGeometryImplementation::PGeometryImplementation( const PGeometryTypeSignatureImplementation& in_typeSigniture ) 
: m_typeSignature()
, m_arrayTopology()
, m_arrayData()
{
	TypeSignatureSet( in_typeSigniture );
	return;
}

/**/
PGeometryImplementation::PGeometryImplementation( const PGeometryImplementation& in_src )
: m_typeSignature()
, m_arrayTopology()
, m_arrayData()
{
	TypeSignatureSet( in_src.TypeSignatureGet() );
	( *this ) = in_src;
	return;
}

/**/
PGeometryImplementation::PGeometryImplementation()
: m_typeSignature()
, m_arrayTopology()
, m_arrayData()
{
	return;
}

/**/
PGeometryImplementation::~PGeometryImplementation()
{
	LocalRelease( m_arrayTopology );
	LocalRelease( m_arrayData );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PGeometryImplementation& PGeometryImplementation::operator=( const PGeometryImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_typeSignature = in_rhs.m_typeSignature;

		LocalRelease( m_arrayTopology );
		LocalRelease( m_arrayData );

		HCOMMON_FOR_EACH( pStore, in_rhs.m_arrayData, TArrayStore )
		{
			HContainerUtility::PushBack( m_arrayData, pStore->Clone() );
		}

		HCOMMON_FOR_EACH( pStore, in_rhs.m_arrayTopology, TArrayStore )
		{
			HContainerUtility::PushBack( m_arrayTopology, pStore->Clone() );
		}
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryImplementation::operator==( const PGeometryImplementation& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_typeSignature == in_rhs.m_typeSignature );

		if( HTRUE == match )
		{
			HCOMMON_ASSERT( m_arrayData.SizeGet() == in_rhs.m_arrayData.SizeGet(), "invalid data state" );
			for( HSINT index = 0; index < m_arrayData.SizeGet(); ++index )
			{
				match &= ( HTRUE == m_arrayData[ index ]->Cmp( in_rhs.m_arrayData[ index ] ) );
			}

			HCOMMON_ASSERT( m_arrayTopology.SizeGet() == in_rhs.m_arrayTopology.SizeGet(), "invalid data state" );
			for( HSINT index = 0; index < m_arrayTopology.SizeGet(); ++index )
			{
				match &= ( HTRUE == m_arrayTopology[ index ]->Cmp( in_rhs.m_arrayTopology[ index ] ) );
			}
		}
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryImplementation::operator!=( const PGeometryImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PGeometryImplementation::Clear()
{
	HCOMMON_FOR_EACH( pStore, m_arrayTopology, TArrayStore )
	{
		HCOMMON_ASSERT( HNULL != pStore, "invalid member" );
		pStore->Clear();
	}

	HCOMMON_FOR_EACH( pStore, m_arrayData, TArrayStore )
	{
		HCOMMON_ASSERT( HNULL != pStore, "invalid member" );
		pStore->Clear();
	}

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
Hubris::HVOID PGeometryImplementation::TypeSignatureSet( const PGeometryTypeSignatureImplementation& in_typeSignature )
{
	m_typeSignature = in_typeSignature;
	LocalRelease( m_arrayTopology );
	LocalRelease( m_arrayData );
	LocalCreate( m_arrayTopology, m_arrayData, m_typeSignature );

	return;
}

/**/
const PGeometryStoreVertexIndex& PGeometryImplementation::StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreVertexIndex* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreVertexIndex >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreVertexIndex& PGeometryImplementation::StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )
{
	PGeometryStoreVertexIndex* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreVertexIndex >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreTriangleStrip& PGeometryImplementation::StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreTriangleStrip* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangleStrip >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreTriangleStrip& PGeometryImplementation::StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )
{
	PGeometryStoreTriangleStrip* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangleStrip >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreTriangle& PGeometryImplementation::StoreTopologyTriangleGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreTriangle* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangle >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreTriangle& PGeometryImplementation::StoreTopologyTriangleGet( const Hubris::HSINT in_index )
{
	PGeometryStoreTriangle* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreTriangle >( m_arrayTopology[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataSint& PGeometryImplementation::StoreDataSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataSint& PGeometryImplementation::StoreDataSintGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataSint* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataReal& PGeometryImplementation::StoreDataRealGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataReal* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataReal >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataReal& PGeometryImplementation::StoreDataRealGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataReal* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataReal >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataVectorR2& PGeometryImplementation::StoreDataVectorR2Get( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataVectorR2* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR2 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataVectorR2& PGeometryImplementation::StoreDataVectorR2Get( const Hubris::HSINT in_index )
{
	PGeometryStoreDataVectorR2* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR2 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataVectorR3& PGeometryImplementation::StoreDataVectorR3Get( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataVectorR3* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR3 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataVectorR3& PGeometryImplementation::StoreDataVectorR3Get( const Hubris::HSINT in_index )
{
	PGeometryStoreDataVectorR3* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR3 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataVectorR4& PGeometryImplementation::StoreDataVectorR4Get( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataVectorR4* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR4 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataVectorR4& PGeometryImplementation::StoreDataVectorR4Get( const Hubris::HSINT in_index )
{
	PGeometryStoreDataVectorR4* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataVectorR4 >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataRealSint& PGeometryImplementation::StoreDataRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataRealSint& PGeometryImplementation::StoreDataRealSintGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataRealSint* pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataColourRgba& PGeometryImplementation::StoreDataColourRgbaGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataColourRgba* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataColourRgba >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataColourRgba& PGeometryImplementation::StoreDataColourRgbaGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataColourRgba* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataColourRgba >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataColourRealRgba& PGeometryImplementation::StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataColourRealRgba* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataColourRealRgba >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataColourRealRgba& PGeometryImplementation::StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataColourRealRgba* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataColourRealRgba >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

const PGeometryStoreDataStaticArray4PairRealSint& PGeometryImplementation::StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataStaticArray4PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray4PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataStaticArray4PairRealSint& PGeometryImplementation::StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataStaticArray4PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray4PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataStaticArray16PairRealSint& PGeometryImplementation::StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataStaticArray16PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray16PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataStaticArray16PairRealSint& PGeometryImplementation::StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataStaticArray16PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray16PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
const PGeometryStoreDataStaticArray64PairRealSint& PGeometryImplementation::StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryStoreDataStaticArray64PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray64PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
PGeometryStoreDataStaticArray64PairRealSint& PGeometryImplementation::StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index )
{
	PGeometryStoreDataStaticArray64PairRealSint* const pStore = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreDataStaticArray64PairRealSint >( m_arrayData[ in_index ] );
	HCOMMON_ASSERT( HNULL != pStore, "invalid data" );
	return( *pStore );
}

/**/
