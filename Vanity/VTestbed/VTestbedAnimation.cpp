//file: Vanity/VTestbed/VTestbedAnimation.cpp

#include "Vanity/VTestbed/VTestbedAnimation.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;
using namespace Sloth;

//////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HREAL TTime;
typedef Hubris::HContainerPair< TTime, Hubris::HSINT >TPairTimeSint;
typedef Hubris::HContainerArray< TPairTimeSint >TArrayPairTimeSint;
typedef Hubris::HContainerPair< TTime, Hubris::HREAL >TPairTimeReal;
typedef Hubris::HContainerArray< TPairTimeReal >TArrayPairTimeReal;

//////////////////////////////////////////////////////
// local static functions
/**/
static const VAnimation LocalSampleAnimationMake()
{
	VAnimation animation;
	animation.LoopSet( HFALSE );
	animation.NameGet() = "foo";
	animation.DurationGet() = 2.0F;
	TArrayPairTimeReal arrayTimeReal; 
	arrayTimeReal.Insert( TPairTimeReal( 0.0F, 1.0F ) );
	arrayTimeReal.Insert( TPairTimeReal( 1.0F, 5.0F ) );
	arrayTimeReal.Insert( TPairTimeReal( 2.0F, 3.0F ) );
	animation.DataSet(
		"one", 
		VAnimation::FlagDataInterpolatorStepGet(),
		arrayTimeReal
		);
	animation.DataSet(
		"two", 
		VAnimation::FlagDataInterpolatorLerpGet(),
		arrayTimeReal
		);
	animation.DataSet(
		"three", 
		VAnimation::FlagDataInterpolatorSpineCamultRomGet(),
		arrayTimeReal
		);

	return animation;
}

/**/
static const Hubris::HBOOL LocalAnimation()
{
	HBOOL success = HTRUE;

	{
		const VAnimation animation0 = LocalSampleAnimationMake();
		const VAnimation animation1( animation0 );
		const VAnimation animation2 = animation0;
		const VAnimation animation3;

		success &= ( animation0 == animation0 );

		success &= ( animation0 == animation1 );
		success &= ( animation1 == animation0 );

		success &= ( animation0 == animation2 );
		success &= ( animation2 == animation0 );

		success &= ( animation0 != animation3 );
		success &= ( animation3 != animation0 );

		success &= !( animation0 != animation2 );
		success &= !( animation2 != animation0 );

		success &= !( animation0 == animation3 );
		success &= !( animation3 == animation0 );
	}

	//test step
	{
		const VAnimation animation0 = LocalSampleAnimationMake();
		HREAL value = 0.0F;
		const HSINT streamIndex0 = animation0.StreamIndexGet( "one" );
		HSINT indexHint = HCOMMON_INVALID_INDEX;

		value = 0.0F;
		animation0.SampleValue( -0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.0F, 0.75F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 0.75F ) );

		value = 0.0F;
		animation0.SampleValue( 0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 1.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 5.0F ) );

		value = 0.0F;
		animation0.SampleValue( 1.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 5.0F ) );

		value = 0.0F;
		animation0.SampleValue( 2.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );

		value = 0.0F;
		animation0.SampleValue( 2.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );
	}

	//test lerp
	{
		const VAnimation animation0 = LocalSampleAnimationMake();
		HREAL value = 0.0F;
		const HSINT streamIndex0 = animation0.StreamIndexGet( "two" );
		HSINT indexHint = HCOMMON_INVALID_INDEX;

		value = 0.0F;
		animation0.SampleValue( -0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.25F, 0.75F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.5F ) );

		value = 0.0F;
		animation0.SampleValue( 0.25F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 2.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );

		value = 0.0F;
		animation0.SampleValue( 1.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 5.0F ) );

		value = 0.0F;
		animation0.SampleValue( 1.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 4.0F ) );

		value = 0.0F;
		animation0.SampleValue( 2.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );

		value = 0.0F;
		animation0.SampleValue( 2.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );
	}


	//spline catmul rom
	{
		const VAnimation animation0 = LocalSampleAnimationMake();
		HREAL value = 0.0F;
		const HSINT streamIndex0 = animation0.StreamIndexGet( "three" );
		HSINT indexHint = HCOMMON_INVALID_INDEX;

		value = 0.0F;
		animation0.SampleValue( -0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		animation0.SampleValue( 0.25F, 0.75F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.3945313F ) );

		value = 0.0F;
		animation0.SampleValue( 0.25F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 1.8593750F ) );

		value = 0.0F;
		animation0.SampleValue( 0.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.1250000F ) );

		value = 0.0F;
		animation0.SampleValue( 1.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 5.0F ) );

		value = 0.0F;
		animation0.SampleValue( 1.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 4.25F ) );

		value = 0.0F;
		animation0.SampleValue( 2.0F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );

		value = 0.0F;
		animation0.SampleValue( 2.5F, 1.0F, streamIndex0, value, indexHint );
		success &= ( HMathUtility::EpsilonEqual( value, 3.0F ) );
	}

	VTESTBED_VALIDATE_STATUS( "VAnimation", success );

	return success;
}

/**/
static const Hubris::HBOOL LocalAnimationBlender()
{
	HBOOL success = HTRUE;

	{
		VAnimationBlender blender;
		const VAnimation animation0 = LocalSampleAnimationMake();
		blender.AnimationAdd( animation0 );
		const HSINT animationIndex = blender.AnimationIndexGet( "foo" );
		success &= ( HCOMMON_INVALID_INDEX != animationIndex ); 
		success &= ( HCOMMON_INVALID_INDEX == blender.AnimationIndexGet( "bar" ) ); 

		VAnimationPlayParam playParam;
		blender.PlayAnimation(
			animationIndex,
			playParam
			);

		const HSINT targetIndex = blender.TargetNameIndexGet( "three" );
		success &= ( HCOMMON_INVALID_INDEX != targetIndex ); 

		HREAL value = 0.0F;

		value = 0.0F;
		blender.SampleValueGet( value, targetIndex );
		success &= ( HMathUtility::EpsilonEqual( value, 1.0F ) );

		value = 0.0F;
		blender.TimeDeltaApply( 1.5F );
		blender.SampleValueGet( value, targetIndex );
		success &= ( HMathUtility::EpsilonEqual( value, 4.25F ) );

		value = 0.0F;
		blender.TimeDeltaApply( 0.5F );
		blender.SampleValueGet( value, targetIndex );
		success &= ( HMathUtility::EpsilonEqual( value, 0.0F ) );

		blender.AnimationRemove( animation0 );

		success &= ( HCOMMON_INVALID_INDEX == blender.AnimationIndexGet( "foo" ) ); 
	}


	VTESTBED_VALIDATE_STATUS( "VAnimationBlender", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions

/**/
const Hubris::HBOOL TestbedAnimation()
{
	VTESTBED_VALIDATE_START( "TestbedAnimation" );

	HBOOL success = HTRUE;

	success &= LocalAnimation();
	success &= LocalAnimationBlender();

	return success;
}

/**/
