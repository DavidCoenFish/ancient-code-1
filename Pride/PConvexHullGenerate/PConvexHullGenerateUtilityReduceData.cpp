//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduceData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduceData.h"

#include "Pride/PBounds/PBounds_Export.h"
#include "Pride/PConvexHull/PConvexHull_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMath/HMath_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
typedef Hubris::HSmartPointer< PConvexHullGenerateUtilityReduceData >TDataPointer;
typedef Hubris::HContainerArray< TDataPointer >TArrayData;

///////////////////////////////////////////////////////
// static local variables
/**/
static const HREAL s_percentageWeight = 1000.0F;

///////////////////////////////////////////////////////
// static local methods
/**/
static const HREAL LocalCalculateValue(
	const HVectorR3& in_locationOne,
	const HREAL in_radiusOne,
	const HVectorR3& in_locationTwo,
	const HREAL in_radiusTwo
	)
{
	HREAL value = HVariablesMath::ZeroGet< HREAL >();

	const HREAL distance = HMatrixUtility::Length( in_locationOne - in_locationTwo );

	const HREAL volumeOne = HMathVolume::VolumeSphere( in_radiusOne );
	const HREAL volumeTwo = HMathVolume::VolumeSphere( in_radiusTwo );
	const HREAL volumeIntersect = HMathVolume::VolumeSphereIntersection( in_radiusOne, in_radiusTwo, distance );

	HREAL percentageOne = HVariablesMath::ZeroGet< HREAL >();
	HREAL percentageTwo = HVariablesMath::ZeroGet< HREAL >();
	if( HTRUE == HMathUtility::EpsilonZeroNot( volumeOne ) )
	{
		percentageOne = volumeIntersect / volumeOne;
	}
	if( HTRUE == HMathUtility::EpsilonZeroNot( volumeTwo ) )
	{
		percentageTwo = volumeIntersect / volumeTwo;
	}

	//we take max percentage of intersection to sphere volume as value
	value = HMathUtility::Maximum( percentageOne, percentageTwo ) + percentageOne + percentageTwo;

	//want to merge smaller, closer together sphere first, ie, better value fo small sphere
	if( value == 0.0F )
	{
		value -= ( in_radiusOne + in_radiusTwo + distance );
	}

	return value;
}

/**/
static const HSINT LocalGetBestValueIndex( const TArrayReal& in_arrayValue )
{
	HSINT bestIndex = HCOMMON_INVALID_INDEX;
	HREAL bestValue = HVariablesMath::MinimumGet< HREAL >();

	for( HSINT index = 0; index < in_arrayValue.SizeGet(); ++index )
	{
		const HREAL testValue = in_arrayValue[ index ];
		if( bestValue < testValue )
		{
			bestIndex = index;
			bestValue = testValue;
		}
	}

	return bestIndex;
}

/**/
static const HSINT LocalLocalIndexFromExternal( const HSINT in_externalIndex, const HSINT in_ourIndex )
{
	return( in_externalIndex - in_ourIndex - 1 );
}

/**/
static const HSINT LocalExternalIndexFromLocalIndex( const HSINT in_localIndex, const HSINT in_ourIndex )
{
	return( in_ourIndex + in_localIndex + 1 );
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityReduceData::PConvexHullGenerateUtilityReduceData( const PConvexHullGenerateUtilityReduceData& in_src )
: m_convexHull()
, m_location()
, m_radius( HVariablesMath::ZeroGet< HREAL >() )
, m_arrayValue()
, m_externalDataArrayIndexBest( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilityReduceData::PConvexHullGenerateUtilityReduceData(
	const PConvexHull in_convexHull
	)
: m_convexHull()
, m_location()
, m_radius( HVariablesMath::ZeroGet< HREAL >() )
, m_arrayValue()
, m_externalDataArrayIndexBest( HCOMMON_INVALID_INDEX )
{
	HullSet( in_convexHull );
	return;
}

/**/
PConvexHullGenerateUtilityReduceData::PConvexHullGenerateUtilityReduceData()
: m_convexHull()
, m_location()
, m_radius( HVariablesMath::ZeroGet< HREAL >() )
, m_arrayValue()
, m_externalDataArrayIndexBest( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PConvexHullGenerateUtilityReduceData::~PConvexHullGenerateUtilityReduceData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilityReduceData& PConvexHullGenerateUtilityReduceData::operator=( const PConvexHullGenerateUtilityReduceData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_convexHull = in_rhs.m_convexHull;
		m_location = in_rhs.m_location;
		m_radius = in_rhs.m_radius;
		m_arrayValue = in_rhs.m_arrayValue;
		m_externalDataArrayIndexBest = in_rhs.m_externalDataArrayIndexBest;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityReduceData::operator==( const PConvexHullGenerateUtilityReduceData& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_convexHull == in_rhs.m_convexHull );
		match &= ( m_location == in_rhs.m_location );
		match &= ( m_radius == in_rhs.m_radius );
		match &= ( m_arrayValue == in_rhs.m_arrayValue );
		match &= ( m_externalDataArrayIndexBest == in_rhs.m_externalDataArrayIndexBest );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilityReduceData::operator!=( const PConvexHullGenerateUtilityReduceData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHullGenerateUtilityReduceData::HullSet( 
	const PConvexHull& in_convexHull
	)
{
	( *this ) = PConvexHullGenerateUtilityReduceData();

	m_convexHull = in_convexHull;

	HCOMMON_ASSERT( HTRUE == PConvexHullUtility::EnclosedTest( m_convexHull ), "invalid data" );
	const PBoundsR3 bounds = PConvexHullUtility::BoundsGet( m_convexHull );

	m_location = bounds.CenterGet();
	m_radius = bounds.RadiusGet();

	return;
}

/**/
HVOID PConvexHullGenerateUtilityReduceData::RemoveDataIndex( const Hubris::HSINT in_removedIndex, const Hubris::HSINT in_ourIndex )
{
	if( in_ourIndex == in_removedIndex )
	{
		return;
	}

	if( in_ourIndex < in_removedIndex )
	{
		const HSINT removeIndex = LocalLocalIndexFromExternal( in_removedIndex, in_ourIndex );

		m_arrayValue.Remove( m_arrayValue.Begin() + removeIndex );
		if( in_removedIndex == m_externalDataArrayIndexBest )
		{
			m_externalDataArrayIndexBest = LocalExternalIndexFromLocalIndex( LocalGetBestValueIndex( m_arrayValue ), in_ourIndex );
		}
		else if( in_removedIndex < m_externalDataArrayIndexBest )
		{
			m_externalDataArrayIndexBest -= 1;
		}
	}

	return;
}

/**/
HVOID PConvexHullGenerateUtilityReduceData::BestValueGet( 
	Hubris::HSINT& in_out_bestDataIndexOne, 
	Hubris::HSINT& in_out_bestDataIndexTwo, 
	Hubris::HREAL& in_out_bestValue, 
	const Hubris::HSINT in_ourIndex 
	)const
{
	if( 0 == m_arrayValue.SizeGet() )
	{
		return;
	}

	const HREAL value = m_arrayValue[ LocalLocalIndexFromExternal( m_externalDataArrayIndexBest, in_ourIndex ) ];
	if( in_out_bestValue < value )
	{
		in_out_bestValue = value;
		in_out_bestDataIndexOne = in_ourIndex;
		in_out_bestDataIndexTwo = m_externalDataArrayIndexBest;
	}

	return;
}

/**/
HVOID PConvexHullGenerateUtilityReduceData::CalculateValues(
	const Hubris::HSINT in_ourIndex,
	const TArrayData& in_arrayData
	)
{
	const HSINT count = in_arrayData.SizeGet() - in_ourIndex - 1;
	m_arrayValue.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT externalIndex = LocalExternalIndexFromLocalIndex( index, in_ourIndex );
		const PConvexHullGenerateUtilityReduceData& data = *( in_arrayData[ externalIndex ] );
		m_arrayValue[ index ] = LocalCalculateValue(
			m_location,
			m_radius,
			data.m_location,
			data.m_radius
			);
	}

	m_externalDataArrayIndexBest =  LocalExternalIndexFromLocalIndex( LocalGetBestValueIndex( m_arrayValue ), in_ourIndex );

	return;
}

/**/
HVOID PConvexHullGenerateUtilityReduceData::DataAppend(
	const Hubris::HSINT in_ourIndex,
	const PConvexHullGenerateUtilityReduceData& in_data
	)
{
	const HREAL value = LocalCalculateValue(
			m_location,
			m_radius,
			in_data.m_location,
			in_data.m_radius
			);

	//const HSINT index = HContainerUtility::PushBack( m_arrayValue, value );
	HContainerUtility::PushBack( m_arrayValue, value );

	m_externalDataArrayIndexBest = LocalExternalIndexFromLocalIndex( LocalGetBestValueIndex( m_arrayValue ), in_ourIndex );

	return;
}

/**/