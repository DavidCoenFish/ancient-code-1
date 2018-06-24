//file: Lust/LSpring/LSpringTrait.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LSpring/LSpringTrait.h"

#include "Lust/LSpring/LSpringParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Lust;

/*
	LSpringParam
*/
Hubris::HVOID Envy::EMementoTraitCollect< LSpringParam >( EMementoCollect& in_out_mementoCollect, const LSpringParam& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_springConstant", in_data.SpringConstantGet() );
	in_out_mementoCollect.MemberAdd( "m_springDamppenConstant", in_data.SpringDamppenConstantGet() );
	in_out_mementoCollect.MemberAdd( "m_springMaximumDistance", in_data.SpringMaximumDistanceGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< LSpringParam >( const EMementoAssign& in_out_mementoAssign, LSpringParam& out_data )
{
	HREAL value = 0.0F;
	in_out_mementoAssign.MemberGet( "m_springConstant", value );
	out_data.SpringConstantSet( value );

	value = 0.0F;
	in_out_mementoAssign.MemberGet( "m_springDamppenConstant", value );
	out_data.SpringDamppenConstantSet( value );

	value = 0.0F;
	in_out_mementoAssign.MemberGet( "m_springMaximumDistance", value );
	out_data.SpringMaximumDistanceSet( value );

	return;
}

/**/