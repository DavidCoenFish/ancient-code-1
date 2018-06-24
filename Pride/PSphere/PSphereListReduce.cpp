//file: Pride/PSphere/PSphereListReduce.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PSphere/PSphereListReduce.h"

#include "Pride/PSphere/PSphere.h"
#include "Pride/PSphere/PSphereUtility.h"

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
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerPair< PSphereR3, TArraySint >TPairSphereArraySint;
typedef Hubris::HContainerArray< TPairSphereArraySint >TArrayPairSphereArraySint;

///////////////////////////////////////////////////////
// local static methods
/**
static const HREAL LocalMaxRadiusCalculate( 
	const TArrayPairSphereArraySint& in_sphereList 
	)
{
	HREAL maxRadius = HVariablesMath::ZeroGet< HREAL >();
	HCOMMON_FOR_EACH_CONST( pair, in_sphereList, TArrayPairSphereArraySint )
	{
		maxRadius = HMathUtility::Maximum( maxRadius, pair.m_first.RadiusGet() );
	}

	return maxRadius;
}

/*
want largest value for most desriable to merge
*
static const HREAL LocalCalculateValue(
	const PSphereR3& in_lhs,
	const PSphereR3& in_rhs,
	const HREAL in_largestRadius
	)
{
	HREAL value = HVariablesMath::ZeroGet< HREAL >();

	const HREAL distance = HMatrixUtility::Length( in_lhs.CenterGet() - in_rhs.CenterGet() );

	const HREAL volumeOne = HMathVolume::VolumeSphere( in_lhs.RadiusGet() );
	const HREAL volumeTwo = HMathVolume::VolumeSphere( in_rhs.RadiusGet() );
	const HREAL volumeIntersect = HMathVolume::VolumeSphereIntersection( in_lhs.RadiusGet(), in_rhs.RadiusGet(), distance );

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

	//the largest percentage of overlap
	value = HMathUtility::Maximum( percentageOne, percentageTwo );

	//increase influence of smaller spheres
	const HREAL radiusSum = ( in_lhs.RadiusGet() + in_rhs.RadiusGet() );
	if( HTRUE == HMathUtility::EpsilonZeroNot( radiusSum ) )
	{
		value *= ( ( in_largestRadius ) / ( radiusSum ) );
	}

	//if we are still zero (no intersection) get the smaller, closer spheres first
	if( HTRUE == HMathUtility::EpsilonZero( value ) )
	{
		value = -( distance + radiusSum ); 
	}

	return value;
}

/**/
static const HBOOL LocalReduceCount(
	TArrayPairSphereArraySint& in_out_sphereList
	)
{
	HSINT bestIndexOne = HCOMMON_INVALID_INDEX;
	HSINT bestIndexTwo = HCOMMON_INVALID_INDEX;
	PSphereR3 smallestMergeSphere;
	smallestMergeSphere.RadiusSet( HVariablesMath::MaximumGet< HREAL >() );

	//const HREAL maxRadius = LocalMaxRadiusCalculate( in_out_sphereList );

	const HSINT count = in_out_sphereList.SizeGet();
	for( HSINT indexOne = 0; indexOne < count; ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 1; indexTwo < count; ++indexTwo )
		{
			const PSphereR3& sphereIndexOne = in_out_sphereList[ indexOne ].m_first;
			const PSphereR3& sphereIndexTwo = in_out_sphereList[ indexTwo ].m_first;
			if( smallestMergeSphere.RadiusGet() < HMathUtility::Maximum( sphereIndexOne.RadiusGet(), sphereIndexTwo.RadiusGet() ) )
			{
				continue;
			}

			if( ( smallestMergeSphere.RadiusGet() * smallestMergeSphere.RadiusGet() ) < HMatrixUtility::LengthSquared( sphereIndexOne.CenterGet() - sphereIndexTwo.CenterGet() ) )
			{
				continue;
			}

			const PSphereR3 testSphere = PSphereUtility::SphereMerge( sphereIndexOne, sphereIndexTwo );
			if( testSphere.RadiusGet() < smallestMergeSphere.RadiusGet() )
			{
				smallestMergeSphere = testSphere;
				bestIndexOne = indexOne;
				bestIndexTwo = indexTwo;
			}
		}
	}

	if( ( HCOMMON_INVALID_INDEX == bestIndexOne ) ||
		( HCOMMON_INVALID_INDEX == bestIndexTwo ) )
	{
		return HFALSE;
	}

	in_out_sphereList[ bestIndexOne ].m_first = smallestMergeSphere;

	in_out_sphereList[ bestIndexOne ].m_second.Insert(
		in_out_sphereList[ bestIndexTwo ].m_second.Begin(),
		in_out_sphereList[ bestIndexTwo ].m_second.End()
		);

	in_out_sphereList.Remove( in_out_sphereList.Begin() + bestIndexTwo );

	return HTRUE;
}

///////////////////////////////////////////////////////
// public static methods
/**/
HVOID PSphereListReduce::Reduce(
	TArrayPairSphereArraySint& in_out_sphereList,
	const Hubris::HSINT in_targetCount
	)
{
	PSphereListReduce reduceObject(
		in_out_sphereList,
		in_targetCount
		);

	return;
}


///////////////////////////////////////////////////////
// creation
/**/
PSphereListReduce::PSphereListReduce(
	TArrayPairSphereArraySint& in_out_sphereList,
	const Hubris::HSINT in_targetCount
	)
{
	if( in_out_sphereList.SizeGet() <= in_targetCount )
	{
		return;
	}

	if( HFALSE == LocalReduceCount(
		in_out_sphereList
		) )
	{
		return;
	}

	Reduce( 
		in_out_sphereList,
		in_targetCount
		);

	return;
}

/**/
PSphereListReduce::~PSphereListReduce()
{
	return;
}

/**/