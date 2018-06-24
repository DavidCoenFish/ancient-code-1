//file: Pride/PConvexHull/PConvexHullTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHull/PConvexHullTrait.h"

#include "Pride/PConvexHull/PConvexHull.h"
#include "Pride/PPlane/PPlane_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Envy/Envy_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PPlaneR3 >TArrayPlane;

/////////////////////////////////////////////////////////////////
// memento
/*
	PConvexHull
*/
Hubris::HVOID Envy::EMementoTraitCollect< PConvexHull >( EMementoCollect& in_out_mementoCollect, const Pride::PConvexHull& in_data )
{
	TArrayPlane arrayPlane;
	const HSINT count = in_data.PlaneCountGet();
	arrayPlane.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		arrayPlane[ index ] = in_data.PlaneGet( index );
	}

	in_out_mementoCollect.MemberAdd( "m_arrayPlane", arrayPlane );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PConvexHull >( const EMementoAssign& in_out_mementoAssign, Pride::PConvexHull& out_data )
{
	TArrayPlane arrayPlane;
	in_out_mementoAssign.MemberGet( "m_arrayPlane", arrayPlane );

	HCOMMON_FOR_EACH_CONST( plane, arrayPlane, TArrayPlane )
	{
		out_data.PlaneAdd( plane );
	}

	return;
}

/**/