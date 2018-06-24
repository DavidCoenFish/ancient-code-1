//file: Vanity/VComponentSoundEmitter/VComponentSoundEmitterItemData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentSoundEmitter/VComponentSoundEmitterItemData.h"

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
VComponentSoundEmitterItemData::VComponentSoundEmitterItemData( const VComponentSoundEmitterItemData& in_src )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentSoundEmitterItemData::VComponentSoundEmitterItemData()
{
	return;
}

/**/
VComponentSoundEmitterItemData::~VComponentSoundEmitterItemData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentSoundEmitterItemData& VComponentSoundEmitterItemData::operator=( const VComponentSoundEmitterItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentSoundEmitterItemData::operator==( const VComponentSoundEmitterItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentSoundEmitterItemData::operator!=( const VComponentSoundEmitterItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
