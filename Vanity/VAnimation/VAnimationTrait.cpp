//file: Vanity/VAnimation/VAnimationTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationTrait.h"

#include "Vanity/VAnimation/VAnimation.h"
#include "Vanity/VAnimation/VAnimationStream.h"
#include "Vanity/VAnimation/VAnimationData.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// local
/**/
template< typename IN_TYPE >
static HVOID LocalMementoCollectData(
	EMementoCollect& in_out_mementoCollect,
	const VAnimationData< IN_TYPE >& in_data
	)
{
	in_out_mementoCollect.MemberAdd( "m_flag", in_data.TypeInterpolatorGet() );
	in_out_mementoCollect.MemberAdd( "m_time", in_data.ArrayTimeGet() );
	in_out_mementoCollect.MemberAdd( "m_data", in_data.ArrayValueGet() );

	return;
}

/**/
template< typename IN_TYPE >
static HVOID LocalMementoAssignData(
	const EMementoAssign& in_out_mementoAssign,
	VAnimationData< IN_TYPE >& out_data
	)
{
	HSINT type = HCOMMON_INVALID_INDEX;
	in_out_mementoAssign.MemberGet( "m_flag", type );
	out_data.TypeInterpolatorSet( type );

	in_out_mementoAssign.MemberGet( "m_time", out_data.ArrayTimeGet() );
	in_out_mementoAssign.MemberGet( "m_data", out_data.ArrayValueGet() );

	return;
}

/*
	VAnimation
*/
HVOID Envy::EMementoTraitCollect< VAnimation >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimation& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_name", in_data.NameGet() );
	in_out_mementoCollect.MemberAdd( "m_duration", in_data.DurationGet() );
	in_out_mementoCollect.MemberAdd( "m_flag", in_data.FlagGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayStream", in_data.ArrayStreamGet() );
	in_out_mementoCollect.MemberAdd( "m_targetNameStringTable", in_data.TargetNameStringTableGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimation >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimation& out_data )
{
	in_out_mementoAssign.MemberGet( "m_name", out_data.NameGet() );
	in_out_mementoAssign.MemberGet( "m_duration", out_data.DurationGet() );
	HSINT flag = 0;
	in_out_mementoAssign.MemberGet( "m_flag", flag );
	out_data.FlagSet( flag );
	in_out_mementoAssign.MemberGet( "m_arrayStream", out_data.ArrayStreamGet() );
	in_out_mementoAssign.MemberGet( "m_targetNameStringTable", out_data.TargetNameStringTableGet() );

	return;
}

/*
	VAnimationStream
*/
HVOID Envy::EMementoTraitCollect< VAnimationStream >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationStream& in_data )
{
	const HSINT type = in_data.TypeDataGet();
	in_out_mementoCollect.MemberAdd( "m_type", type );

	if( type == VAnimationStream::TypeDataGetReal() )
	{
		in_out_mementoCollect.MemberAdd( "m_data", in_data.AnimationDataRealGet() );
	}
	else if( type == VAnimationStream::TypeDataGetSint() )
	{
		in_out_mementoCollect.MemberAdd( "m_data", in_data.AnimationDataSintGet() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR2() )
	{
		in_out_mementoCollect.MemberAdd( "m_data", in_data.AnimationDataVectorR2Get() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR3() )
	{
		in_out_mementoCollect.MemberAdd( "m_data", in_data.AnimationDataVectorR3Get() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR4() )
	{
		in_out_mementoCollect.MemberAdd( "m_data", in_data.AnimationDataVectorR4Get() );
	}

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationStream >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationStream& out_data )
{
	HSINT type = 0;
	in_out_mementoAssign.MemberGet( "m_type", type );
	out_data.TypeDataSet( type ); 

	if( type == VAnimationStream::TypeDataGetReal() )
	{
		in_out_mementoAssign.MemberGet( "m_data", out_data.AnimationDataRealGet() );
	}
	else if( type == VAnimationStream::TypeDataGetSint() )
	{
		in_out_mementoAssign.MemberGet( "m_data", out_data.AnimationDataSintGet() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR2() )
	{
		in_out_mementoAssign.MemberGet( "m_data", out_data.AnimationDataVectorR2Get() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR3() )
	{
		in_out_mementoAssign.MemberGet( "m_data", out_data.AnimationDataVectorR3Get() );
	}
	else if( type == VAnimationStream::TypeDataGetVectorR4() )
	{
		in_out_mementoAssign.MemberGet( "m_data", out_data.AnimationDataVectorR4Get() );
	}

	return;
}

/*
	VAnimationDataSint
*/
HVOID Envy::EMementoTraitCollect< VAnimationDataSint >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataSint& in_data )
{
	LocalMementoCollectData(
		in_out_mementoCollect,
		in_data
		);
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationDataSint >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataSint& out_data )
{
	LocalMementoAssignData(
		in_out_mementoAssign,
		out_data
		);
	return;
}

/*
	VAnimationDataReal
*/
HVOID Envy::EMementoTraitCollect< VAnimationDataReal >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataReal& in_data )
{
	LocalMementoCollectData(
		in_out_mementoCollect,
		in_data
		);
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationDataReal >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataReal& out_data )
{
	LocalMementoAssignData(
		in_out_mementoAssign,
		out_data
		);
	return;
}

/*
	VAnimationDataVectorR2
*/
HVOID Envy::EMementoTraitCollect< VAnimationDataVectorR2 >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR2& in_data )
{
	LocalMementoCollectData(
		in_out_mementoCollect,
		in_data
		);
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationDataVectorR2 >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR2& out_data )
{
	LocalMementoAssignData(
		in_out_mementoAssign,
		out_data
		);
	return;
}

/*
	VAnimationDataVectorR3
*/
HVOID Envy::EMementoTraitCollect< VAnimationDataVectorR3 >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR3& in_data )
{
	LocalMementoCollectData(
		in_out_mementoCollect,
		in_data
		);
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationDataVectorR3 >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR3& out_data )
{
	LocalMementoAssignData(
		in_out_mementoAssign,
		out_data
		);
	return;
}

/*
	VAnimationDataVectorR4
*/
HVOID Envy::EMementoTraitCollect< VAnimationDataVectorR4 >( EMementoCollect& in_out_mementoCollect, const Vanity::VAnimationDataVectorR4& in_data )
{
	LocalMementoCollectData(
		in_out_mementoCollect,
		in_data
		);
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VAnimationDataVectorR4 >( const EMementoAssign& in_out_mementoAssign, Vanity::VAnimationDataVectorR4& out_data )
{
	LocalMementoAssignData(
		in_out_mementoAssign,
		out_data
		);
	return;
}

/**/