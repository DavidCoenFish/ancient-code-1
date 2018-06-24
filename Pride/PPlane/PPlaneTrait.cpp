//file: Pride/PPlane/PPlaneTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PPlane/PPlaneTrait.h"

#include "Pride/PPlane/PPlane.h"

#include< Envy/Envy_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// typedef
/**/

/////////////////////////////////////////////////////////////////
// memento
/*
	PPlaneR2
*/
Hubris::HVOID Envy::EMementoTraitCollect< PPlaneR2 >( EMementoCollect& in_out_mementoCollect, const Pride::PPlaneR2& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_distance", in_data.DistanceGet() );
	in_out_mementoCollect.MemberAdd( "m_direction", in_data.DirectionGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PPlaneR2 >( const EMementoAssign& in_out_mementoAssign, Pride::PPlaneR2& out_data )
{
	HREAL distance = 0.0F;
	in_out_mementoAssign.MemberGet( "m_distance", distance );
	out_data.DistanceSet( distance );

	PUnitVectorR2 direction;
	in_out_mementoAssign.MemberGet( "m_direction", direction );
	out_data.DirectionSet( direction );

	return;
}

/*
	PPlaneR3
*/
Hubris::HVOID Envy::EMementoTraitCollect< PPlaneR3 >( EMementoCollect& in_out_mementoCollect, const Pride::PPlaneR3& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_distance", in_data.DistanceGet() );
	in_out_mementoCollect.MemberAdd( "m_direction", in_data.DirectionGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PPlaneR3 >( const EMementoAssign& in_out_mementoAssign, Pride::PPlaneR3& out_data )
{
	HREAL distance = 0.0F;
	in_out_mementoAssign.MemberGet( "m_distance", distance );
	out_data.DistanceSet( distance );

	PUnitVectorR3 direction;
	in_out_mementoAssign.MemberGet( "m_direction", direction );
	out_data.DirectionSet( direction );

	return;
}

/**/