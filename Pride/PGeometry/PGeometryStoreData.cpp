//file: Pride/PGeometry/PGeometryStoreData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryStoreData.h"

#include "Pride/PGeometry/PGeometryTrait.h"
#include "Pride/PColour/PColour_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PGeometryStoreData< HSINT >;
template class Pride::PGeometryStoreData< HREAL >;
template class Pride::PGeometryStoreData< TPairRealSint >;
template class Pride::PGeometryStoreData< HVectorR2 >;
template class Pride::PGeometryStoreData< HVectorR3 >;
template class Pride::PGeometryStoreData< HVectorR4 >;
template class Pride::PGeometryStoreData< Pride::PColourRgba >;
template class Pride::PGeometryStoreData< Pride::PColourRealRgba >;
template class Pride::PGeometryStoreData< HContainerStaticArray< TPairRealSint, 4 > >;
template class Pride::PGeometryStoreData< HContainerStaticArray< TPairRealSint, 16 > >;
template class Pride::PGeometryStoreData< HContainerStaticArray< TPairRealSint, 64 > >;

////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
Pride::PGeometryStoreData< IN_TYPE >::PGeometryStoreData( const PGeometryStoreData& in_src )
: m_arrayData()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE >
Pride::PGeometryStoreData< IN_TYPE >::PGeometryStoreData()
: m_arrayData()
{
	return;
}

/**/
template< typename IN_TYPE >
Pride::PGeometryStoreData< IN_TYPE >::~PGeometryStoreData()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE >
const PGeometryStoreData< IN_TYPE >& Pride::PGeometryStoreData< IN_TYPE >::operator=( const PGeometryStoreData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayData = in_rhs.m_arrayData;
	}

	return( *this );
}

/**/
template< typename IN_TYPE >
Hubris::HBOOL Pride::PGeometryStoreData< IN_TYPE >::operator==( const PGeometryStoreData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_arrayData == in_rhs.m_arrayData );
	}

	return match;
}
/**/
template< typename IN_TYPE >
Hubris::HBOOL Pride::PGeometryStoreData< IN_TYPE >::operator!=( const PGeometryStoreData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

////////////////////////////////////////////////
// implement PGeometryStoreInterface
/**/
template< typename IN_TYPE >
HVOID Pride::PGeometryStoreData< IN_TYPE >::Clear()
{
	m_arrayData.Clear();
}

/**/
template< typename IN_TYPE >
PGeometryStoreInterface* Pride::PGeometryStoreData< IN_TYPE >::Clone()
{
	PGeometryStoreData* pStore;
	HCOMMON_NEW_PARAM( pStore, PGeometryStoreData, *this );
	return pStore;
}

/**/
template< typename IN_TYPE >
Hubris::HBOOL Pride::PGeometryStoreData< IN_TYPE >::Cmp( const PGeometryStoreInterface* const in_pRhs )
{
	const PGeometryStoreData< IN_TYPE >* const pRhs = HTypeRunTimeInfoCast< PGeometryStoreInterface, PGeometryStoreData< IN_TYPE > >( in_pRhs );
	if( HNULL == pRhs )
	{
		return HFALSE;
	}

	return( ( *this ) == ( *pRhs ) );
}

////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE >
Hubris::HSINT Pride::PGeometryStoreData< IN_TYPE >::DataUniqueAdd( const IN_TYPE& in_data )
{
	return HContainerUtility::UniqueAdd( m_arrayData, in_data );
}

/**/
template< typename IN_TYPE >
Hubris::HSINT Pride::PGeometryStoreData< IN_TYPE >::DataAdd( const IN_TYPE& in_data )
{
	return HContainerUtility::PushBack( m_arrayData, in_data );
}

////////////////////////////////////////////////
// public accessor
/**/
template< typename IN_TYPE >
Hubris::HSINT Pride::PGeometryStoreData< IN_TYPE >::SizeGet()const
{
	return m_arrayData.SizeGet();
}

/**/
template< typename IN_TYPE >
const IN_TYPE& Pride::PGeometryStoreData< IN_TYPE >::DataGet( const Hubris::HSINT in_index )const
{
	return m_arrayData[ in_index ];
}

/**/
template< typename IN_TYPE >
IN_TYPE& Pride::PGeometryStoreData< IN_TYPE >::DataGet( const Hubris::HSINT in_index )
{
	return m_arrayData[ in_index ];
}


////////////////////////////////////////////////
// EMEMENTO_FACTORY_SOURCE( IN_CLASS, IN_BASE_CLASS )
/**
template< typename IN_TYPE >
const Hubris::HString Pride::PGeometryStoreData< IN_TYPE >::MementoFactoryNameGet()const		
{																	
	return Hubris::HTraitName< PGeometryStoreData< IN_TYPE > >::NameGet();				
}																	
/**
template< typename IN_TYPE >
Hubris::HVOID Pride::PGeometryStoreData< IN_TYPE >::MementoCollect( Envy::EMementoCollect& in_out_collect )const
{																	
	in_out_collect.MemberAdd( "_DATA", *this );						
	return;															
}																	
/**
template< typename IN_TYPE >
Hubris::HVOID Pride::PGeometryStoreData< IN_TYPE >::MementoAssign( const Envy::EMementoAssign& in_assign )
{																	
	in_assign.MemberGet( "_DATA", *this );							
	return;															
}																	
/**
template< typename IN_TYPE >
PGeometryStoreInterface* const Pride::PGeometryStoreData< IN_TYPE >::MementoFactoryCreate()				
{																	
	PGeometryStoreData< IN_TYPE >* pClass = HNULL;										
	HCOMMON_NEW(													
		pClass,														
		PGeometryStoreData< IN_TYPE >													
		);															
	return pClass;													
}
/**/