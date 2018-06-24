//file: Pride/PBounds/PBoundsTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PBounds/PBoundsTrait.h"

#include "Pride/PBounds/PBounds.h"

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
	PBoundsR1
*/
Hubris::HVOID Envy::EMementoTraitCollect< PBoundsR1 >( EMementoCollect& in_out_mementoCollect, const Pride::PBoundsR1& in_data )
{
	const HBOOL valid = in_data.ValidGet();
	in_out_mementoCollect.MemberAdd( "m_valid", valid );

	if( HTRUE == valid )
	{
		in_out_mementoCollect.MemberAdd( "m_min", in_data.VectorMinimumGet() );
		in_out_mementoCollect.MemberAdd( "m_max", in_data.VectorMaximumGet() );
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PBoundsR1 >( const EMementoAssign& in_out_mementoAssign, Pride::PBoundsR1& out_data )
{
	HBOOL valid = HFALSE;
	in_out_mementoAssign.MemberGet( "m_valid", valid );

	if( HTRUE == valid )
	{
		HVectorR1 minVector;
		HVectorR1 maxVector;
		in_out_mementoAssign.MemberGet( "m_min", minVector );
		in_out_mementoAssign.MemberGet( "m_max", maxVector );
		out_data = PBoundsR1( minVector, maxVector );
	}
	else
	{
		out_data = PBoundsR1();
	}

	return;
}

/*
	PBoundsR2
*/
Hubris::HVOID Envy::EMementoTraitCollect< PBoundsR2 >( EMementoCollect& in_out_mementoCollect, const Pride::PBoundsR2& in_data )
{
	const HBOOL valid = in_data.ValidGet();
	in_out_mementoCollect.MemberAdd( "m_valid", valid );

	if( HTRUE == valid )
	{
		in_out_mementoCollect.MemberAdd( "m_min", in_data.VectorMinimumGet() );
		in_out_mementoCollect.MemberAdd( "m_max", in_data.VectorMaximumGet() );
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PBoundsR2 >( const EMementoAssign& in_out_mementoAssign, Pride::PBoundsR2& out_data )
{
	HBOOL valid = HFALSE;
	in_out_mementoAssign.MemberGet( "m_valid", valid );

	if( HTRUE == valid )
	{
		HVectorR2 minVector;
		HVectorR2 maxVector;
		in_out_mementoAssign.MemberGet( "m_min", minVector );
		in_out_mementoAssign.MemberGet( "m_max", maxVector );
		out_data = PBoundsR2( minVector, maxVector );
	}
	else
	{
		out_data = PBoundsR2();
	}

	return;
}

/*
	PBoundsR3
*/
Hubris::HVOID Envy::EMementoTraitCollect< PBoundsR3 >( EMementoCollect& in_out_mementoCollect, const Pride::PBoundsR3& in_data )
{
	const HBOOL valid = in_data.ValidGet();
	in_out_mementoCollect.MemberAdd( "m_valid", valid );

	if( HTRUE == valid )
	{
		in_out_mementoCollect.MemberAdd( "m_min", in_data.VectorMinimumGet() );
		in_out_mementoCollect.MemberAdd( "m_max", in_data.VectorMaximumGet() );
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PBoundsR3 >( const EMementoAssign& in_out_mementoAssign, Pride::PBoundsR3& out_data )
{
	HBOOL valid = HFALSE;
	in_out_mementoAssign.MemberGet( "m_valid", valid );

	if( HTRUE == valid )
	{
		HVectorR3 minVector;
		HVectorR3 maxVector;
		in_out_mementoAssign.MemberGet( "m_min", minVector );
		in_out_mementoAssign.MemberGet( "m_max", maxVector );
		out_data = PBoundsR3( minVector, maxVector );
	}
	else
	{
		out_data = PBoundsR3();
	}

	return;
}


/**/