//file: Greed/GPlayerCharacter/GPlayerCharacterTrait.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GPlayerCharacter/GPlayerCharacterTrait.h"

#include "Greed/GPlayerCharacter/GPlayerCharacter.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;
using namespace Vanity;

///////////////////////////////////////////////////////
// global template overrides
/*
	GPlayerCharacter
*/
Hubris::HVOID Envy::EMementoTraitCollect< GPlayerCharacter >( EMementoCollect& in_out_mementoCollect, const Greed::GPlayerCharacter& in_data )
{
	in_out_mementoCollect;
	in_data;
	//in_out_mementoCollect.MemberAdd( "m_stateMachine", in_data.StateMachineGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< GPlayerCharacter >( const EMementoAssign& in_out_mementoAssign, Greed::GPlayerCharacter& out_data )
{
	in_out_mementoAssign;
	out_data;
	//in_out_mementoAssign.MemberGet( "m_stateMachine", out_data.StateMachineGet() );

	return;
}

/**/