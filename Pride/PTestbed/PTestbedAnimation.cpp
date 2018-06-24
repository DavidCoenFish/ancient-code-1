//file: Pride/PTestbed/PTestbedAnimation.cpp

#include "Pride/PTestbed/PTestbedAnimation.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HREAL >TArrayReal;
typedef HContainerArray< HString >TArrayString;

typedef PAnimationKey< HREAL >TAnimationKeyReal;
typedef PAnimationKey< HSINT >TAnimationKeySint;

typedef HContainerPair< Hubris::HREAL, TAnimationKeyReal >TPairTimeKeyReal;
typedef HContainerArray< TPairTimeKeyReal >TArrayPairTimeKeyReal;

typedef HContainerPair< Hubris::HREAL, TAnimationKeySint >TPairTimeKeySint;
typedef HContainerArray< TPairTimeKeySint >TArrayPairTimeKeySint;

class TTestbedAnimationVisitor : public PInterfaceAnimationVisitor
{
public:
	TTestbedAnimationVisitor( HBOOL& in_success, const HSINT in_caseCount )
	: m_success( in_success )
	, m_caseCount( in_caseCount )
	{
		return;
	}

	~TTestbedAnimationVisitor(){ return; }

	/////////////////////////////////////////////////////////
	// implement PInterfaceAnimationVisitor
private:
	virtual HVOID ValueGet( const Hubris::HString&, PInterfaceAnimationVariant& )
	{
		return;
	}
	virtual HVOID ValueSet( const Hubris::HString& in_targetName, const PInterfaceAnimationVariant& in_value )
	{
		switch( m_caseCount )
		{
		case 0:
			{
				m_success &= ( "data0" == in_targetName );
				m_success &= ( 2.0F == in_value.ValueGet< HREAL >() );
				break;
			}
		case 1:
			{
				m_success &= ( "data1" == in_targetName );
				m_success &= ( 6 == in_value.ValueGet< HSINT >() );
				break;
			}
		case 2:
			{
				m_success &= ( "data2" == in_targetName );
				m_success &= ( 0.0F == in_value.ValueGet< HREAL >() );
				break;
			}

		case 3:
			{
				m_success &= ( "data0" == in_targetName );
				m_success &= ( 7.5F == in_value.ValueGet< HREAL >() );
				break;
			}
		case 4:
			{
				m_success &= ( "data1" == in_targetName );
				m_success &= ( 6 == in_value.ValueGet< HSINT >() );
				break;
			}
		case 5:
			{
				m_success &= ( "data2" == in_targetName );
				m_success &= ( 5.0F == in_value.ValueGet< HREAL >() );
				break;
			}
		}

		m_caseCount += 1;

		return;
	}
	virtual HVOID ValueAbsoluteGet( const Hubris::HString&, PInterfaceAnimationVariant& )
	{
		return;
	}
	virtual HVOID ValueAbsoluteSet( const Hubris::HString&, const PInterfaceAnimationVariant& )
	{
		return;
	}

	/////////////////////////////////////////////////////////
	// disabled
private:
	TTestbedAnimationVisitor( const TTestbedAnimationVisitor& in_src );
	const TTestbedAnimationVisitor& operator=( const TTestbedAnimationVisitor& in_rhs );

	/////////////////////////////////////////////////////////
	// private members
private:
	HBOOL& m_success;
	HSINT m_caseCount;

};

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedAnimation()
{
	HBOOL success = HTRUE;

	TArrayPairTimeKeyReal animationKeyData0;
	animationKeyData0.Insert( TPairTimeKeyReal( 0.0F, TAnimationKeyReal( 2.0F ) ) );
	animationKeyData0.Insert( TPairTimeKeyReal( 1.0F, TAnimationKeyReal( 10.0F ) ) );
	animationKeyData0.Insert( TPairTimeKeyReal( 3.0F, TAnimationKeyReal( 5.0F ) ) );
	TArrayReal animationKeyDataTime0;
	animationKeyDataTime0.Insert( 0.0F );
	animationKeyDataTime0.Insert( 1.0F );
	animationKeyDataTime0.Insert( 3.0F );

	TArrayPairTimeKeySint animationKeyData1;
	animationKeyData1.Insert( TPairTimeKeySint( -1.0F, TAnimationKeySint( 8 ) ) );
	animationKeyData1.Insert( TPairTimeKeySint( 1.0F, TAnimationKeySint( 4 ) ) );
	animationKeyData1.Insert( TPairTimeKeySint( 5.0F, TAnimationKeySint( 12 ) ) );
	TArrayReal animationKeyDataTime1;
	animationKeyDataTime1.Insert( -1.0F );
	animationKeyDataTime1.Insert( 1.0F );
	animationKeyDataTime1.Insert( 5.0F );

	TArrayPairTimeKeyReal animationKeyData2;
	animationKeyData2.Insert( TPairTimeKeyReal( 1.0F, TAnimationKeyReal( 0.0F ) ) );
	animationKeyData2.Insert( TPairTimeKeyReal( 2.0F, TAnimationKeyReal( 5.0F ) ) );
	animationKeyData2.Insert( TPairTimeKeyReal( 3.0F, TAnimationKeyReal( 10.0F ) ) );
	TArrayReal animationKeyDataTime2;
	animationKeyDataTime2.Insert( 1.0F );
	animationKeyDataTime2.Insert( 2.0F );
	animationKeyDataTime2.Insert( 3.0F );

	//TArrayReal animationKeyDataTime3;
	//animationKeyDataTime3.Insert( -1.0F );
	//animationKeyDataTime3.Insert( 0.0F );
	//animationKeyDataTime3.Insert( 1.0F );
	//animationKeyDataTime3.Insert( 2.0F );
	//animationKeyDataTime3.Insert( 3.0F );
	//animationKeyDataTime3.Insert( 5.0F );

	//PAnimation( const PAnimation& in_src );
	//PAnimation();
	//~PAnimation();
	//const PAnimation& operator=( const PAnimation& in_rhs );
	//Hubris::HBOOL operator==( const PAnimation& in_rhs )const;
	//Hubris::HBOOL operator!=( const PAnimation& in_rhs )const;
	{
		PAnimation animation0;
		animation0.DataAdd( "data0", animationKeyData0 );
		const PAnimation animation1( animation0 );
		const PAnimation animation2 = animation0;
		const PAnimation animation3;

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

	//HVOID DataAdd( 
	//	const Hubris::HString& in_name, 
	//	const Hubris::HContainerArray< Hubris::HContainerPair< Hubris::HREAL, IN_KEY > >& in_arrayKeys
	//	)
	//HVOID NameArrayGet( TArrayString& out_arrayName )const;
	//HVOID TimeKeyGet( const Hubris::HString& in_name, TArrayReal& out_arrayTime )const;
	{
		PAnimation animation0;
		animation0.DataAdd( "data0", animationKeyData0 );
		animation0.DataAdd( "data1", animationKeyData1 );
		animation0.DataAdd( "data2", animationKeyData2 );

		TArrayString arrayString;
		animation0.NameArrayGet( arrayString );

		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayString, "data0" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayString, "data1" ) );
		success &= ( HCOMMON_INVALID_INDEX != HContainerUtility::IndexOf( arrayString, "data2" ) );
		success &= ( HCOMMON_INVALID_INDEX == HContainerUtility::IndexOf( arrayString, "data3" ) );

		TArrayReal arrayTime0;
		animation0.TimeKeyGet( "data0", arrayTime0 );
		success &= ( arrayTime0 == animationKeyDataTime0 );

		TArrayReal arrayTime1;
		animation0.TimeKeyGet( "data1", arrayTime1 );
		success &= ( arrayTime1 == animationKeyDataTime1 );
	}

	//virtual const Hubris::HBOOL TimeAbsoluteTest()const{ return HTRUE; }
	//virtual HVOID TimeAbsoluteRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const;
	{
		PAnimation animation0;
		animation0.DataAdd( "data0", animationKeyData0 );
		animation0.DataAdd( "data1", animationKeyData1 );
		animation0.DataAdd( "data2", animationKeyData2 );
		success &= ( HTRUE == animation0.TimeAbsoluteTest() );

		HREAL timeLow;
		HREAL timeHigh;
		animation0.TimeAbsoluteRangeGet( timeLow, timeHigh );

		success &= ( -1.0F == timeLow );
		success &= ( 5.0F == timeHigh );
	}

	//virtual HVOID SubmitVisitorAbsolute( const Hubris::HREAL in_timeAbsolute, PInterfaceAnimationVisitor& out_visitor )const;
	//virtual HVOID SubmitVisitorDelta( const Hubris::HREAL HCOMMON_UNUSED_VAR( in_timeDelta ), PInterfaceAnimationVisitor& HCOMMON_UNUSED_VAR( out_visitor ) )const{ HCOMMON_ASSERT_ALWAYS( "invalid code path" ); }
	{
		PAnimation animation0;
		animation0.DataAdd( "data0", animationKeyData0 );
		animation0.DataAdd( "data1", animationKeyData1 );
		animation0.DataAdd( "data2", animationKeyData2 );

		TTestbedAnimationVisitor visitor0( success, 0 );
		animation0.SubmitVisitorAbsolute( 0.0F, visitor0 );

		animation0.SubmitVisitorAbsolute( 2.0F, visitor0 );
	}

	PTESTBED_VALIDATE_STATUS( "PAnimation", success );

	return success;
}

/**/
static const HBOOL LocalTestbedAnimationUtility()
{
	HBOOL success = HTRUE;

	TArrayPairTimeKeyReal animationKeyData0;
	animationKeyData0.Insert( TPairTimeKeyReal( 0.0F, TAnimationKeyReal( 2.0F ) ) );
	animationKeyData0.Insert( TPairTimeKeyReal( 1.0F, TAnimationKeyReal( 10.0F ) ) );
	animationKeyData0.Insert( TPairTimeKeyReal( 3.0F, TAnimationKeyReal( 5.0F ) ) );
	TArrayReal animationKeyDataTime0;
	animationKeyDataTime0.Insert( 0.0F );
	animationKeyDataTime0.Insert( 1.0F );
	animationKeyDataTime0.Insert( 3.0F );

	TArrayPairTimeKeySint animationKeyData1;
	animationKeyData1.Insert( TPairTimeKeySint( -1.0F, TAnimationKeySint( 8 ) ) );
	animationKeyData1.Insert( TPairTimeKeySint( 1.0F, TAnimationKeySint( 4 ) ) );
	animationKeyData1.Insert( TPairTimeKeySint( 5.0F, TAnimationKeySint( 12 ) ) );
	TArrayReal animationKeyDataTime1;
	animationKeyDataTime1.Insert( -1.0F );
	animationKeyDataTime1.Insert( 1.0F );
	animationKeyDataTime1.Insert( 5.0F );

	TArrayPairTimeKeyReal animationKeyData2;
	animationKeyData2.Insert( TPairTimeKeyReal( 1.0F, TAnimationKeyReal( 0.0F ) ) );
	animationKeyData2.Insert( TPairTimeKeyReal( 2.0F, TAnimationKeyReal( 5.0F ) ) );
	animationKeyData2.Insert( TPairTimeKeyReal( 3.0F, TAnimationKeyReal( 10.0F ) ) );
	TArrayReal animationKeyDataTime2;
	animationKeyDataTime2.Insert( 1.0F );
	animationKeyDataTime2.Insert( 2.0F );
	animationKeyDataTime2.Insert( 3.0F );

	TArrayReal animationKeyDataTime3;
	animationKeyDataTime3.Insert( -1.0F );
	animationKeyDataTime3.Insert( 0.0F );
	animationKeyDataTime3.Insert( 1.0F );
	animationKeyDataTime3.Insert( 2.0F );
	animationKeyDataTime3.Insert( 3.0F );
	animationKeyDataTime3.Insert( 5.0F );

	//static HVOID CollectKeyframe( const PAnimation& in_animation, TArrayReal& out_timeArray );
	{
		PAnimation animation0;
		animation0.DataAdd( "data0", animationKeyData0 );
		animation0.DataAdd( "data1", animationKeyData1 );
		animation0.DataAdd( "data2", animationKeyData2 );

		TArrayReal arrayKey0;
		PAnimationUtility::CollectKeyframe( arrayKey0, animation0 );

		success &= ( arrayKey0 == animationKeyDataTime3 );
	}

	PTESTBED_VALIDATE_STATUS( "PAnimationUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedAnimation()
{
	PTESTBED_VALIDATE_START( "TestbedAnimation" );

	HBOOL success = HTRUE;

	success &= LocalTestbedAnimation();
	success &= LocalTestbedAnimationUtility();

	return success;
}

/**/