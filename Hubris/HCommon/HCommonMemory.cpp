//file: Hubris/HCommon/HCommonMemory.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HCommon/HCommonMemory.h"

#include "Hubris/HCommon/HCommonAssert.h"

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
HVOID* Hubris::HCommonMemory::Malloc( HSINT in_size )
{
	return malloc( in_size );
}

/**/
HVOID* Hubris::HCommonMemory::Realloc( HVOID* in_memory, HSINT in_size )
{
	return realloc( in_memory, in_size );
}

/**/
HVOID Hubris::HCommonMemory::Free( HVOID* in_memory )
{
	if( HNULL != in_memory )
	{
		free( in_memory );
	}

	return;
}

/**/
HVOID Hubris::HCommonMemory::MemoryCopy( HVOID* const in_dest, const HVOID* const in_src, const HSINT in_size )
{
	HCOMMON_ASSERT( HNULL != in_src, "invalid param" );
	HCOMMON_ASSERT( HNULL != in_dest, "invalid param" );
	HCOMMON_ASSERT( 0 < in_size, "invalid param" );

	memcpy( in_dest, in_src, static_cast< size_t >( in_size ) );

	return;
}

/**/
HSINT Hubris::HCommonMemory::MemoryCompair( const HVOID* const in_lhs, const HVOID* const in_rhs, const HSINT in_size )
{
	if( 0 == in_size )
	{
		return 0;
	}

	HCOMMON_ASSERT( HNULL != in_lhs, "invalid param" );
	HCOMMON_ASSERT( HNULL != in_rhs, "invalid param" );

	return memcmp( in_lhs, in_rhs, in_size );
}

/**/