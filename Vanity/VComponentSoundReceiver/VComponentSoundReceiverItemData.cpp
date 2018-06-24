//file: Vanity/VComponentSoundReceiver/VComponentSoundReceiverItemData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundReceiver/VComponentSoundReceiverItemData.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentSoundReceiverItemData::VComponentSoundReceiverItemData( const VComponentSoundReceiverItemData& in_src )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentSoundReceiverItemData::VComponentSoundReceiverItemData()
{
	return;
}

/**/
VComponentSoundReceiverItemData::~VComponentSoundReceiverItemData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentSoundReceiverItemData& VComponentSoundReceiverItemData::operator=( const VComponentSoundReceiverItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentSoundReceiverItemData::operator==( const VComponentSoundReceiverItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentSoundReceiverItemData::operator!=( const VComponentSoundReceiverItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
