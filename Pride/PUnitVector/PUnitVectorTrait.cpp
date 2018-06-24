//file: Pride/PUnitVector/PUnitVectorTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PUnitVector/PUnitVectorTrait.h"

#include "Pride/PUnitVector/PUnitVector.h"

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
	PUnitVectorR2
*/
Hubris::HVOID Envy::EMementoTraitCollect< PUnitVectorR2 >( EMementoCollect& in_out_mementoCollect, const Pride::PUnitVectorR2& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_unitVector", in_data.VectorGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PUnitVectorR2 >( const EMementoAssign& in_out_mementoAssign, Pride::PUnitVectorR2& out_data )
{
	HVectorR2 unitVector;
	in_out_mementoAssign.MemberGet( "m_unitVector", unitVector );
	out_data.VectorSet( unitVector );

	return;
}

/*
	PUnitVectorR3
*/
Hubris::HVOID Envy::EMementoTraitCollect< PUnitVectorR3 >( EMementoCollect& in_out_mementoCollect, const Pride::PUnitVectorR3& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_unitVector", in_data.VectorGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PUnitVectorR3 >( const EMementoAssign& in_out_mementoAssign, Pride::PUnitVectorR3& out_data )
{
	HVectorR3 unitVector;
	in_out_mementoAssign.MemberGet( "m_unitVector", unitVector );
	out_data.VectorSet( unitVector );

	return;
}

/**/