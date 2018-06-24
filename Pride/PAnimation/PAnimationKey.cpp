//file: Pride/PAnimation/PAnimationKey.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PAnimation/PAnimationKey.h"

#include "Pride/PInterface/PInterface_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMath/HMath_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PAnimationKey< HSINT >;
template class Pride::PAnimationKey< HREAL >;
//template class Pride::PAnimationKey< PColourRgba >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
PAnimationKey< IN_TYPE >::PAnimationKey( const PAnimationKey& in_src )
: m_data()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE >
PAnimationKey< IN_TYPE >::PAnimationKey( const IN_TYPE& in_data )
: m_data( in_data )
{
	return;
}

/**/
template< typename IN_TYPE >
PAnimationKey< IN_TYPE >::~PAnimationKey()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE >
const PAnimationKey< IN_TYPE >& PAnimationKey< IN_TYPE >::operator=( const PAnimationKey& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL PAnimationKey< IN_TYPE >::operator==( const PAnimationKey& in_rhs )const
{
	Hubris::HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL PAnimationKey< IN_TYPE >::operator!=( const PAnimationKey& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods, interface obliged by PAnimation
/**/
template< typename IN_TYPE >
HVOID PAnimationKey< IN_TYPE >::Evalue( 
	PInterfaceAnimationVisitor& out_visitor, 
	const Hubris::HString& in_targetName, 
	const PAnimationKey& in_key 
	)
{
	out_visitor.ValueSet( in_targetName, PInterfaceAnimationVariant( in_key.m_data ) );
	return;
}

/**/
template< typename IN_TYPE >
HVOID PAnimationKey< IN_TYPE >::Evalue( 
	PInterfaceAnimationVisitor& out_visitor, 
	const Hubris::HString& in_targetName, 
	const TArrayKey& in_arrayKey,
	const TArrayReal& in_arrayTime,
	const Hubris::HSINT in_arrayIndex,
	const Hubris::HREAL in_timeSample 
	)
{
	const HREAL timeLow = in_arrayTime[ in_arrayIndex ];
	const HREAL timeHigh = in_arrayTime[ in_arrayIndex + 1 ];

	HCOMMON_ASSERT( timeLow != timeHigh, "invalid param" );

	const Hubris::HREAL ratio = ( ( in_timeSample - timeLow ) / ( timeHigh - timeLow ) );

	const IN_TYPE data = Hubris::HMathUtility::Lerp( in_arrayKey[ in_arrayIndex ].m_data, in_arrayKey[ in_arrayIndex + 1 ].m_data, ratio );

	out_visitor.ValueSet( in_targetName, PInterfaceAnimationVariant( data ) );

	return;
}

/**/
template< typename IN_TYPE >
Hubris::HVOID PAnimationKey< IN_TYPE >::EvalueKey( 
	PInterfaceAnimationVisitorKeys& out_visitorKeys, 
	const Hubris::HString& in_targetName,
	const PAnimationKey& in_key,
	const Hubris::HREAL in_time
	)
{
	out_visitorKeys.KeyValueSet( 
		in_targetName, 
		in_time, 
		PInterfaceAnimationVariant( in_key.m_data ) 
		);

	return;
}

/**/
