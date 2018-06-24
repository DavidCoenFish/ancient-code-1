//file: Vanity/VAnimation/VAnimationData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationData.h"

#include "Vanity/VAnimation/VAnimation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

////////////////////////////////////////////////////
// template definitions
/**/
typedef Hubris::HREAL TTime;
typedef Hubris::HContainerArray< TTime >TArrayTime;
//typedef Hubris::HContainerArray< IN_TYPE >TArrayValue;

template class Vanity::VAnimationData< Hubris::HSINT >;
template class Vanity::VAnimationData< Hubris::HREAL >;
template class Vanity::VAnimationData< Hubris::HVectorR2 >;
template class Vanity::VAnimationData< Hubris::HVectorR3 >;
template class Vanity::VAnimationData< Hubris::HVectorR4 >;

///////////////////////////////////////////////////////
// static local methods
/**/
static HVOID LocalSegmentUpdate(
	HSINT& in_out_indexHint,
	const HREAL in_currentTime,
	const TArrayTime& in_arrayTime
	)
{
	if( in_out_indexHint < 0 )
	{
		in_out_indexHint = 0;
	}
	const HSINT count = in_arrayTime.SizeGet();
	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT sampleIndex = ( in_out_indexHint + index ) % count;
		const HSINT sampleIndexNext = ( in_out_indexHint + index + 1 ) % count;
		if( sampleIndex == ( count - 1 ) )
		{
			continue;
		}

		const TTime sampleTime = in_arrayTime[ sampleIndex ];
		const TTime sampleTimeNext = in_arrayTime[ sampleIndexNext ];

		if( ( sampleTime <= in_currentTime ) &&
			( in_currentTime < sampleTimeNext ) )
		{
			in_out_indexHint = sampleIndex;
			return;
		}
	}

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalStepSample(
	IN_TYPE& in_out_value,
	const HSINT in_index,
	const Hubris::HContainerArray< IN_TYPE >& in_arrayValue,
	const HREAL in_animationWeight
	)
{
	in_out_value += static_cast< IN_TYPE >( in_arrayValue[ in_index ] * in_animationWeight );
	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalLerpSample(
	IN_TYPE& in_out_value,
	const HSINT in_index,
	const TArrayTime& in_arrayTime,
	const Hubris::HContainerArray< IN_TYPE >& in_arrayValue,
	const HREAL in_currentTime,
	const HREAL in_animationWeight
	)
{
	const HREAL low = in_arrayTime[ in_index ];
	const HREAL high = in_arrayTime[ in_index + 1 ];
	const HREAL ratio = in_currentTime - low / ( high - low );

	const IN_TYPE value = HMathUtility::Lerp( in_arrayValue[ in_index ], in_arrayValue[ in_index + 1 ], ratio );
	in_out_value += static_cast< IN_TYPE >( value * in_animationWeight );

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalSplineCatmultRomSample(
	IN_TYPE& in_out_value,
	const HSINT in_index,
	const TArrayTime& in_arrayTime,
	const Hubris::HContainerArray< IN_TYPE >& in_arrayValue,
	const HREAL in_currentTime,
	const HREAL in_animationWeight,
	const HBOOL in_loopAnimation
	)
{
	const HREAL low = in_arrayTime[ in_index ];
	const HREAL high = in_arrayTime[ in_index + 1 ];
	const HREAL ratio = in_currentTime - low / ( high - low );

	HSINT indexSpline0 = in_index - 1;
	HSINT indexSpline1 = in_index + 2;
	const HSINT count = in_arrayTime.SizeGet();

	//wrap the pline endpoints
	if( in_loopAnimation )
	{
		indexSpline0 %= count;
		indexSpline1 %= count;
	}
	else
	{
		indexSpline0 = HMathUtility::Maximum( 0, indexSpline0 );
		indexSpline1 = HMathUtility::Minimum( count - 1, indexSpline1 );
	}

	const IN_TYPE value = HMathUtility::SplineCatmullRom(
		ratio,
		in_arrayValue[ indexSpline0 ],
		in_arrayValue[ in_index ],
		in_arrayValue[ in_index + 1 ],
		in_arrayValue[ indexSpline1 ]
		);
	in_out_value += static_cast< IN_TYPE >( value * in_animationWeight );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
VAnimationData< IN_TYPE >::VAnimationData( const VAnimationData& in_src )
: m_flag( 0 )
, m_arrayTime()
, m_arrayValue()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE >
VAnimationData< IN_TYPE >::VAnimationData()
: m_flag( 0 )
, m_arrayTime()
, m_arrayValue()
{
	return;
}

/**/
template< typename IN_TYPE >
VAnimationData< IN_TYPE >::~VAnimationData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE >
const VAnimationData< IN_TYPE >& VAnimationData< IN_TYPE >::operator=( const VAnimationData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_flag = in_rhs.m_flag;
		m_arrayTime = in_rhs.m_arrayTime;
		m_arrayValue = in_rhs.m_arrayValue;
	}
	return( *this );
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL VAnimationData< IN_TYPE >::operator==( const VAnimationData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) ) 
	{
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_arrayTime == in_rhs.m_arrayTime );
		match &= ( m_arrayValue == in_rhs.m_arrayValue );
	}
	return match;
}

/**/
template< typename IN_TYPE >
const Hubris::HBOOL VAnimationData< IN_TYPE >::operator!=( const VAnimationData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods

///////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE >
Hubris::HVOID VAnimationData< IN_TYPE >::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HBOOL in_loopAnimation,
	const Hubris::HREAL in_animationWeight,
	IN_TYPE& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	if( m_arrayTime.SizeGet() <= 0 )
	{
		return;
	}
	//clamp past end of animation
	if( in_currentTime < 0.0F )
	{
		in_out_value += static_cast< IN_TYPE >( m_arrayValue[ 0 ] * in_animationWeight );
		return;
	}
	else if( HContainerUtility::Back( m_arrayTime ) <= in_currentTime )
	{
		in_out_value += static_cast< IN_TYPE >( HContainerUtility::Back( m_arrayValue ) * in_animationWeight );
		return;
	}

	LocalSegmentUpdate(
		in_out_indexHint,
		in_currentTime,
		m_arrayTime
		);

	const typeInterpolator = TypeInterpolatorGet();
	if( VAnimation::FlagDataInterpolatorStepGet() == typeInterpolator )
	{
		LocalStepSample(
			in_out_value,
			in_out_indexHint,
			m_arrayValue,
			in_animationWeight
			);
	}
	else if( VAnimation::FlagDataInterpolatorLerpGet() == typeInterpolator )
	{
		LocalLerpSample(
			in_out_value,
			in_out_indexHint,
			m_arrayTime,
			m_arrayValue,
			in_currentTime,
			in_animationWeight
			);
	}
	else if( VAnimation::FlagDataInterpolatorSpineCamultRomGet() == typeInterpolator )
	{
		LocalSplineCatmultRomSample(
			in_out_value,
			in_out_indexHint,
			m_arrayTime,
			m_arrayValue,
			in_currentTime,
			in_animationWeight,
			in_loopAnimation
			);
	}

	return;
}

/**/
template< typename IN_TYPE >
Hubris::HVOID VAnimationData< IN_TYPE >::StreamDataSet(
	const Hubris::HSINT in_flag,
	const TArrayPairTimeValue& in_arrayData
	)
{
	m_flag = in_flag;
	const HSINT count = in_arrayData.SizeGet();
	m_arrayTime.SizeSet( count );
	m_arrayValue.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		m_arrayTime[ index ] = in_arrayData[ index ].m_first;
		m_arrayValue[ index ] = in_arrayData[ index ].m_second;
	}

	return;
}

/**/

