//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitter.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitter.h"

#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitterItemData.h"

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
VComponentSoundEmitter::VComponentSoundEmitter()
: m_arrayItemData()
{
	return;
}

/**/
VComponentSoundEmitter::~VComponentSoundEmitter()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentSoundEmitter::OnAddItem(
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
HVOID VComponentSoundEmitter::OnRemoveItem(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_itemIndex )
	)
{
	return;
}

/**/