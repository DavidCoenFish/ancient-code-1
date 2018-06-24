//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiver.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiver.h"

#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiverItemData.h"

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
VComponentSoundReceiver::VComponentSoundReceiver()
: m_arrayItemData()
{
	return;
}

/**/
VComponentSoundReceiver::~VComponentSoundReceiver()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentSoundReceiver::OnAddItem(
	const Hubris::HSINT in_itemIndex 
	)
{
	if( m_arrayItemData.SizeGet() <= in_itemIndex )
	{
		m_arrayItemData.SizeSet( in_itemIndex + 1 );
	}

	return;
}
/**/
HVOID VComponentSoundReceiver::OnRemoveItem(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_itemIndex )
	)
{
	return;
}

/**/