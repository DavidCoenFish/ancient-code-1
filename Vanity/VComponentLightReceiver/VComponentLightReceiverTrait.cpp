//file: Vanity/VComponentLightReceiver/VComponentLightReceiverTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiverTrait.h"

#include "Vanity/VComponentLightReceiver/VComponentLightReceiver.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/**/

///////////////////////////////////////////////////////////
// VComponentLightReceiver
/**/
HVOID Envy::EMementoTraitCollect< VComponentLightReceiver >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiver& in_data )
{
	in_out_mementoCollect.MemberAdd( "itemData", in_data.m_arrayItemData );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentLightReceiver >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiver& out_data )
{
	in_out_mementoAssign.MemberGet( "itemData", out_data.m_arrayItemData );

	return;
}

///////////////////////////////////////////////////////////
// VComponentLightReceiverItemData
/**/
HVOID Envy::EMementoTraitCollect< VComponentLightReceiverItemData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentLightReceiverItemData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayLightIdStatic", in_data.m_arrayLightIdStatic );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentLightReceiverItemData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentLightReceiverItemData& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayLightIdStatic", out_data.m_arrayLightIdStatic );

	return;
}
/**/