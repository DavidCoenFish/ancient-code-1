//file: Hubris/HCommon/HCommonMemory.h
#ifndef _H_COMMON_MEMORY_H_
#define _H_COMMON_MEMORY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

/**/
namespace Hubris
{
	/**/
	struct HCommonMemory
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HCommonMemory();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		static HVOID* Malloc( const HSINT in_size );
		static HVOID* Realloc( HVOID* const in_memory, const HSINT in_size );
		static HVOID Free( HVOID* const in_memory );

		static HVOID MemoryCopy( HVOID* const in_dest, const HVOID* const in_src, const HSINT in_size );
		//returns zero on lhs matching rhs, else returns first difference
		static HSINT MemoryCompair( const HVOID* const in_lhs, const HVOID* const in_rhs, const HSINT in_size );

	};

	/**/
};

/**/
#define HCOMMON_MALLOC( TYPE, COUNT )			( static_cast<TYPE*> ( Hubris::HCommonMemory::Malloc( sizeof( TYPE ) * ( COUNT ) ) ) )
#define HCOMMON_REALLOC( INTPUT, TYPE, COUNT )	( static_cast<TYPE*> ( Hubris::HCommonMemory::Realloc( static_cast<HVOID*>( INTPUT ), sizeof( TYPE ) * ( COUNT ) ) ) )
#define HCOMMON_FREE( INPUT )					{ Hubris::HCommonMemory::Free( static_cast<HVOID*>( INPUT ) ); INPUT = HNULL; }

/**/

#endif// _H_COMMON_MEMORY_H_
