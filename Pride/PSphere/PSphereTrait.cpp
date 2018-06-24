//file: Pride/PSphere/PSphereTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PSphere/PSphereTrait.h"

#include "Pride/PSphere/PSphere.h"

#include< Envy/Envy_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PSphereR2 >( EMementoCollect& in_out_mementoCollect, const Pride::PSphereR2& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_radius", in_data.RadiusGet() );
	in_out_mementoCollect.MemberAdd( "m_center", in_data.CenterGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PSphereR2 >( const EMementoAssign& in_out_mementoAssign, Pride::PSphereR2& out_data )
{
	HREAL radius = 0.0F;
	in_out_mementoAssign.MemberGet( "m_radius", radius );
	out_data.RadiusSet( radius );

	HVectorR2 center;
	in_out_mementoAssign.MemberGet( "m_center", center );
	out_data.CenterSet( center );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PSphereR3 >( EMementoCollect& in_out_mementoCollect, const Pride::PSphereR3& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_radius", in_data.RadiusGet() );
	in_out_mementoCollect.MemberAdd( "m_center", in_data.CenterGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PSphereR3 >( const EMementoAssign& in_out_mementoAssign, Pride::PSphereR3& out_data )
{
	HREAL radius = 0.0F;
	in_out_mementoAssign.MemberGet( "m_radius", radius );
	out_data.RadiusSet( radius );

	HVectorR3 center;
	in_out_mementoAssign.MemberGet( "m_center", center );
	out_data.CenterSet( center );

	return;
}

/**/