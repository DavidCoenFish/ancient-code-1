//file: Vanity/VComponentLightReceiver/VComponentLightReceiver.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentLightReceiver/VComponentLightReceiver.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentLightReceiver::VComponentLightReceiver()
: m_arrayItemData()
{
	return;
}

/**/
VComponentLightReceiver::~VComponentLightReceiver()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentLightReceiver::OnAddItem(
	const TItemId in_itemId
	)
{
	if( m_arrayItemData.SizeGet() <= in_itemId )
	{
		m_arrayItemData.SizeSet( in_itemId + 1 );
	}

	return;
}
/**/
HVOID VComponentLightReceiver::OnRemoveItem(
	const TItemId HCOMMON_UNUSED_VAR( in_itemId )
	)
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentLightReceiver::DynamicLightAdd(
	const TItemId in_itemId,
	const TItemId in_lightItemId,
	const Hubris::HSINT in_frameId
	)
{
	m_arrayItemData[ in_itemId ].DynamicLightAdd(
		in_lightItemId,
		in_frameId
		);

	return;
}

/**/
Hubris::HVOID VComponentLightReceiver::ArrayLightIdGather(
	const TItemId in_itemId,
	TArrayItemId& out_arrayLightsId
	)const
{
	m_arrayItemData[ in_itemId ].ArrayLightIdGather(
		out_arrayLightsId
		);

	return;
}

/**/
Hubris::HVOID VComponentLightReceiver::ArrayLightIdStaticSet(
	const TItemId in_itemId,
	const TArrayItemId& in_arrayLightIdStatic
	)
{
	m_arrayItemData[ in_itemId ].ArrayLightIdStaticSet(
		in_arrayLightIdStatic
		);

	return;
}

/**/