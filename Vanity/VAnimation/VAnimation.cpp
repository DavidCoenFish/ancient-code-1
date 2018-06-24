//file: Vanity/VAnimation/VAnimation.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimation.h"

#include "Vanity/VAnimation/VAnimation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
struct TFlag
{
	enum TEnum
	{
		TNone = 0x00,
		TLoop = 0x01,
	};
};

struct TDataTypeInterpolator
{
	enum TEnum
	{
		TStep = 0, //is default
		TLerp,
		TSplineCatmultRom,

		TCount
	};
};

///////////////////////////////////////////////////////
// creation
/**/
VAnimation::VAnimation( const VAnimation& in_src )
: m_name()
, m_duration( 0.0F )
, m_flag( 0 )
, m_arrayStream()
, m_targetNameStringTable()
{
	( *this ) = in_src;
	return;
}

/**/
VAnimation::VAnimation()
: m_name()
, m_duration( 0.0F )
, m_flag( 0 )
, m_arrayStream()
, m_targetNameStringTable()
{
	return;
}

/**/
VAnimation::~VAnimation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VAnimation& VAnimation::operator=( const VAnimation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_name = in_rhs.m_name;
		m_duration = in_rhs.m_duration;
		m_flag = in_rhs.m_flag;
		m_arrayStream = in_rhs.m_arrayStream;
		m_targetNameStringTable = in_rhs.m_targetNameStringTable;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VAnimation::operator==( const VAnimation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_name == in_rhs.m_name );
		match &= ( m_duration == in_rhs.m_duration );
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_arrayStream == in_rhs.m_arrayStream );
		match &= ( m_targetNameStringTable == in_rhs.m_targetNameStringTable );
	}

	return match;
}

/**/
const Hubris::HBOOL VAnimation::operator!=( const VAnimation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VAnimation::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HREAL in_animationWeight,
	const Hubris::HSINT in_streamIndex,
	Hubris::HSINT& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].AnimationDataSintGet().SampleValue(
		in_currentTime,
		LoopGet(),
		in_animationWeight,
		in_out_value,
		in_out_indexHint
		);
	return;
}

/**/
Hubris::HVOID VAnimation::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HREAL in_animationWeight,
	const Hubris::HSINT in_streamIndex,
	Hubris::HREAL& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].AnimationDataRealGet().SampleValue(
		in_currentTime,
		LoopGet(),
		in_animationWeight,
		in_out_value,
		in_out_indexHint
		);
	return;
}

/**/
Hubris::HVOID VAnimation::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HREAL in_animationWeight,
	const Hubris::HSINT in_streamIndex,
	Hubris::HVectorR2& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].AnimationDataVectorR2Get().SampleValue(
		in_currentTime,
		LoopGet(),
		in_animationWeight,
		in_out_value,
		in_out_indexHint
		);
	return;
}

/**/
Hubris::HVOID VAnimation::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HREAL in_animationWeight,
	const Hubris::HSINT in_streamIndex,
	Hubris::HVectorR3& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].AnimationDataVectorR3Get().SampleValue(
		in_currentTime,
		LoopGet(),
		in_animationWeight,
		in_out_value,
		in_out_indexHint
		);
	return;
}

/**/
Hubris::HVOID VAnimation::SampleValue(
	const Hubris::HREAL in_currentTime,
	const Hubris::HREAL in_animationWeight,
	const Hubris::HSINT in_streamIndex,
	Hubris::HVectorR4& in_out_value,
	Hubris::HSINT& in_out_indexHint
	)const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].AnimationDataVectorR4Get().SampleValue(
		in_currentTime,
		LoopGet(),
		in_animationWeight,
		in_out_value,
		in_out_indexHint
		);
	return;
}

/**/
Hubris::HVOID VAnimation::DataSet(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_dataFlag, //VAnimationData flag, interploator type
	const TArrayPairTimeSint& in_arrayData
	)
{
	VAnimationStream& stream = StreamCreateGet( in_targetName );
	stream.TypeDataSet( VAnimationStream::TypeDataGetSint() );
	stream.AnimationDataSintGet().StreamDataSet( 
		in_dataFlag,
		in_arrayData
		);
	if( 0 < in_arrayData.SizeGet() )
	{
		DurationUpdate( HContainerUtility::Back( in_arrayData ).m_first );
	}

	return;
}

/**/
Hubris::HVOID VAnimation::DataSet(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_dataFlag,
	const TArrayPairTimeReal& in_arrayData
	)
{
	VAnimationStream& stream = StreamCreateGet( in_targetName );
	stream.TypeDataSet( VAnimationStream::TypeDataGetReal() );
	stream.AnimationDataRealGet().StreamDataSet( 
		in_dataFlag,
		in_arrayData
		);
	if( 0 < in_arrayData.SizeGet() )
	{
		DurationUpdate( HContainerUtility::Back( in_arrayData ).m_first );
	}

	return;
}

/**/
Hubris::HVOID VAnimation::DataSet(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_dataFlag,
	const TArrayPairTimeVectorR2& in_arrayData
	)
{
	VAnimationStream& stream = StreamCreateGet( in_targetName );
	stream.TypeDataSet( VAnimationStream::TypeDataGetVectorR2() );
	stream.AnimationDataVectorR2Get().StreamDataSet( 
		in_dataFlag,
		in_arrayData
		);
	if( 0 < in_arrayData.SizeGet() )
	{
		DurationUpdate( HContainerUtility::Back( in_arrayData ).m_first );
	}

	return;
}

/**/
Hubris::HVOID VAnimation::DataSet(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_dataFlag,
	const TArrayPairTimeVectorR3& in_arrayData
	)
{
	VAnimationStream& stream = StreamCreateGet( in_targetName );
	stream.TypeDataSet( VAnimationStream::TypeDataGetVectorR3() );
	stream.AnimationDataVectorR3Get().StreamDataSet( 
		in_dataFlag,
		in_arrayData
		);
	if( 0 < in_arrayData.SizeGet() )
	{
		DurationUpdate( HContainerUtility::Back( in_arrayData ).m_first );
	}

	return;
}

/**/
Hubris::HVOID VAnimation::DataSet(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_dataFlag,
	const TArrayPairTimeVectorR4& in_arrayData
	)
{
	VAnimationStream& stream = StreamCreateGet( in_targetName );
	stream.TypeDataSet( VAnimationStream::TypeDataGetVectorR4() );
	stream.AnimationDataVectorR4Get().StreamDataSet( 
		in_dataFlag,
		in_arrayData
		);
	if( 0 < in_arrayData.SizeGet() )
	{
		DurationUpdate( HContainerUtility::Back( in_arrayData ).m_first );
	}

	return;
}

/**/
const Hubris::HSINT VAnimation::StreamIndexGet(
	const Hubris::HString& in_targetName
	)const
{
	const HSINT streamIndex = m_targetNameStringTable.StringFind( in_targetName );
	return streamIndex;
}

///////////////////////////////////////////////////////
// private methods
/**/
VAnimationStream& VAnimation::StreamCreateGet(
	const Hubris::HString& in_targetName
	)
{
	const HSINT streamIndex = m_targetNameStringTable.StringAdd( in_targetName );
	if( m_arrayStream.SizeGet() <= streamIndex )
	{
		m_arrayStream.SizeResize( streamIndex + 1 );
	}

	return m_arrayStream[ streamIndex ];
}

/**/
Hubris::HVOID VAnimation::DurationUpdate(
	const TTime in_time
	)
{
	if( m_duration < in_time )
	{
		m_duration = in_time;
	}
	return;
}

///////////////////////////////////////////////////////
// static public accessors
const Hubris::HSINT VAnimation::FlagDataInterpolatorStepGet()
{
	return TDataTypeInterpolator::TStep;
}

const Hubris::HSINT VAnimation::FlagDataInterpolatorLerpGet()
{
	return TDataTypeInterpolator::TLerp;
}

const Hubris::HSINT VAnimation::FlagDataInterpolatorSpineCamultRomGet()
{
	return TDataTypeInterpolator::TSplineCatmultRom;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HBOOL VAnimation::LoopGet()const
{
	return( 0 != ( m_flag & TFlag::TLoop ) );
}
/**/
Hubris::HVOID VAnimation::LoopSet( const Hubris::HBOOL in_loop )
{
	if( HTRUE == in_loop )
	{
		m_flag |= TFlag::TLoop;
	}
	else
	{
		m_flag &= ~TFlag::TLoop;
	}
	return;
}

/**/
const Hubris::HSINT VAnimation::TypeDataGet( const Hubris::HSINT in_streamIndex )const
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	const HSINT type = m_arrayStream[ in_streamIndex ].TypeDataGet();
	return type;
}

/**/
Hubris::HVOID VAnimation::TypeDataSet( const Hubris::HSINT in_streamIndex, const Hubris::HSINT in_typeData )
{
	HCOMMON_ASSERT( ( 0 <= in_streamIndex ) && ( in_streamIndex < m_arrayStream.SizeGet() ), "invalid param" );
	m_arrayStream[ in_streamIndex ].TypeDataSet( in_typeData );
	return;

}

/**/
