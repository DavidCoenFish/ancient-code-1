//file: Vanity/VComponentForce/VComponentForceTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForceTrait.h"

#include "Vanity/VComponentForce/VComponentForce.h"
#include "Vanity/VComponentForce/VComponentForceDataBound.h"
#include "Vanity/VComponentForce/VComponentForceDataSphere.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

/**/
HTYPE_NAME_IMPLEMENTATION( VComponentForceDataBound );
HTYPE_NAME_IMPLEMENTATION( VComponentForceDataSphere );

///////////////////////////////////////////////////////////
// VComponentForce
/**/
HVOID Envy::EMementoTraitCollect< VComponentForce >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForce& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_gravitationalAccelleration", in_data.m_gravitationalAccelleration );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentForce >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForce& out_data )
{
	in_out_mementoAssign.MemberGet( "m_gravitationalAccelleration", out_data.m_gravitationalAccelleration );

	return;
}

//VComponentForceDataBound
/**/
HVOID Envy::EMementoTraitCollect< VComponentForceDataBound >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForceDataBound& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_forceFlag", in_data.ForceFlagGet() );
	in_out_mementoCollect.MemberAdd( "m_flag", in_data.FlagGet() );
	in_out_mementoCollect.MemberAdd( "m_bounds", in_data.BoundsGet() );
	in_out_mementoCollect.MemberAdd( "m_vector", in_data.VectorGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentForceDataBound >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForceDataBound& out_data )
{
	HSINT forceFlag = 0;
	in_out_mementoAssign.MemberGet( "m_forceFlag", forceFlag );
	out_data.ForceFlagSet( forceFlag );

	HSINT flag = 0;
	in_out_mementoAssign.MemberGet( "m_flag", flag );
	out_data.FlagSet( flag );

	in_out_mementoAssign.MemberGet( "m_bounds", out_data.BoundsGet() );
	in_out_mementoAssign.MemberGet( "m_vector", out_data.VectorGet() );

	return;
}

//VComponentForceDataSphere
/**/
HVOID Envy::EMementoTraitCollect< VComponentForceDataSphere >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForceDataSphere& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_forceFlag", in_data.ForceFlagGet() );
	in_out_mementoCollect.MemberAdd( "m_flag", in_data.FlagGet() );
	in_out_mementoCollect.MemberAdd( "m_vector", in_data.VectorGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentForceDataSphere >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForceDataSphere& out_data )
{
	HSINT forceFlag = 0;
	in_out_mementoAssign.MemberGet( "m_forceFlag", forceFlag );
	out_data.ForceFlagSet( forceFlag );

	HSINT flag = 0;
	in_out_mementoAssign.MemberGet( "m_flag", flag );
	out_data.FlagSet( flag );

	in_out_mementoAssign.MemberGet( "m_vector", out_data.VectorGet() );

	return;
}

/**/