//file: Pride/PGeometry/PGeometryStoreVertexIndex.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryStoreVertexIndex.h"

#include "Pride/PGeometry/PGeometryTrait.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//EMEMENTO_FACTORY_SOURCE( PGeometryStoreVertexIndex, PGeometryStoreInterface );

////////////////////////////////////////////////
// creation
/**/
PGeometryStoreVertexIndex::PGeometryStoreVertexIndex( const PGeometryStoreVertexIndex& in_src )
: m_stride( in_src.m_stride )
, m_arrayDataIndex()
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryStoreVertexIndex::PGeometryStoreVertexIndex( const Hubris::HSINT in_stride )
: m_stride( in_stride )
, m_arrayDataIndex()
{
	return;
}

/**/
PGeometryStoreVertexIndex::PGeometryStoreVertexIndex()
: m_stride( 0 )
, m_arrayDataIndex()
{
	return;
}

/**/
PGeometryStoreVertexIndex::~PGeometryStoreVertexIndex()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryStoreVertexIndex& PGeometryStoreVertexIndex::operator=( const PGeometryStoreVertexIndex& in_rhs )
{
	HCOMMON_ASSERT( m_stride == in_rhs.m_stride, "data missmatch" );
	if( ( *this ) != in_rhs )
	{
		m_arrayDataIndex = in_rhs.m_arrayDataIndex;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryStoreVertexIndex::operator==( const PGeometryStoreVertexIndex& in_rhs )const
{
	HCOMMON_ASSERT( m_stride == in_rhs.m_stride, "data missmatch" );
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_arrayDataIndex == in_rhs.m_arrayDataIndex );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryStoreVertexIndex::operator!=( const PGeometryStoreVertexIndex& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

////////////////////////////////////////////////
// implement PGeometryStoreInterface
/**/
HVOID PGeometryStoreVertexIndex::Clear()
{
	m_arrayDataIndex.Clear();
	return;
}

/**/
PGeometryStoreInterface* PGeometryStoreVertexIndex::Clone()
{
	PGeometryStoreVertexIndex* pStore = HNULL;
	HCOMMON_NEW_PARAM( pStore, PGeometryStoreVertexIndex, *this );
	return pStore;
}

/**/
Hubris::HBOOL PGeometryStoreVertexIndex::Cmp( const PGeometryStoreInterface* const in_pRhs )
{
	const PGeometryStoreVertexIndex* const pRhs = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreVertexIndex >( in_pRhs );
	if( HNULL == pRhs )
	{
		return HFALSE;
	}

	return( ( *this ) == ( *pRhs ) );
}

////////////////////////////////////////////////
// public methods
/**/
Hubris::HSINT PGeometryStoreVertexIndex::DataArrayIndexUniqueAdd( const Hubris::HSINT* const in_pArrayDataIndexes )
{
	HCOMMON_ASSERT( HNULL != in_pArrayDataIndexes, "invaid param" );

	for( HSINT index = 0; index < ( m_arrayDataIndex.SizeGet() / m_stride ); ++index )
	{
		HBOOL found = HTRUE;
		const HSINT baseIndex = index * m_stride;
		for( HSINT subIndex = 0; subIndex < m_stride; ++subIndex )
		{
			if( m_arrayDataIndex[ baseIndex + subIndex ]  != in_pArrayDataIndexes[ subIndex ] )
			{
				found = HFALSE;
				break;
			}
		}

		if( HTRUE == found )
		{
			return index;
		}
	}

	return DataArrayIndexAdd( in_pArrayDataIndexes );
}

/**/
Hubris::HSINT PGeometryStoreVertexIndex::DataArrayIndexAdd( const Hubris::HSINT* const in_pArrayDataIndexes )
{
	HCOMMON_ASSERT( HNULL != in_pArrayDataIndexes, "invaid param" );

	const HSINT baseIndex = m_arrayDataIndex.SizeGet();
	const HSINT returnIndex = baseIndex / m_stride;

	m_arrayDataIndex.SizeResize( baseIndex + m_stride );

	for( HSINT index = 0; index < m_stride; ++index )
	{
		m_arrayDataIndex[ baseIndex + index ] = in_pArrayDataIndexes[ index ];
	}

	return returnIndex;
}

////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT PGeometryStoreVertexIndex::DataArrayCountGet()const
{
	HCOMMON_ASSERT( 0 != m_stride, "invalid data" );
	return( ( m_arrayDataIndex.SizeGet() ) / m_stride );
}

/**/
const Hubris::HSINT* const PGeometryStoreVertexIndex::DataArrayIndexGet( const Hubris::HSINT in_index )const
{
	return( m_arrayDataIndex.RawGet() + ( in_index * m_stride ) );
}

/**/
