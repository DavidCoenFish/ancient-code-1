//file: Hubris/HSmartPointer/HSmartPointerOperators.h
#ifndef _H_SMART_POINTER_OPERATORS_H_
#define _H_SMART_POINTER_OPERATORS_H_


#include "Hubris/HSmartPointer/HSmartPointer.h"

namespace Hubris
{
	/**/
	template< typename IN_TYPE >HBOOL operator==( const HSmartPointer< IN_TYPE >& in_lhs, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		HBOOL match = true;

		if( &in_lhs != &in_rhs )
		{
			match = match && ( in_lhs.RawGet() == in_rhs.RawGet() );
		}

		return match;
	}

	/**/
	template< typename IN_TYPE >HBOOL operator==( const IN_TYPE * const in_lhs, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		HBOOL match = true;

		match = match && ( in_lhs == in_rhs.RawGet() );

		return match;
	}

	/**/
	template< typename IN_TYPE >HBOOL operator==(  const HSmartPointer< IN_TYPE >& in_lhs, const IN_TYPE * const in_rhs )
	{
		
		HBOOL match = true;

		match = match && ( in_lhs.RawGet() == in_rhs );

		return match;
	}

	/**/
	template< typename IN_TYPE >HBOOL operator==( const HS32 in_null, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		HCOMMON_ASSERT( HNULL == in_null, "non null in null comparison" );
		HBOOL match = true;

		match = match && ( HNULL == in_rhs.RawGet() );

		return match;
	}

	/**/
	template< typename IN_TYPE >HBOOL operator==( const HSmartPointer< IN_TYPE >& in_lhs, const HS32 in_null )
	{
		
		HCOMMON_ASSERT( HNULL == in_null, "non null in null comparison" );
		HBOOL match = true;

		match = match && ( in_lhs.RawGet() == HNULL );

		return match;
	}

	/**/
	template< typename IN_TYPE >HBOOL operator!=( const HSmartPointer< IN_TYPE >& in_lhs, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		return!( operator==( in_lhs, in_rhs ) );
	}

	/**/
	template< typename IN_TYPE >HBOOL operator!=( const IN_TYPE* const in_lhs, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		return!( operator==( in_lhs, in_rhs ) );
	}

	/**/
	template< typename IN_TYPE >HBOOL operator!=( const HSmartPointer< IN_TYPE >& in_lhs, const IN_TYPE* const in_rhs )
	{
		
		return!( operator==( in_lhs, in_rhs ) );
	}

	/**/
	template< typename IN_TYPE >HBOOL operator!=( const HSINT in_null, const HSmartPointer< IN_TYPE >& in_rhs )
	{
		
		return!( operator==( in_null, in_rhs ) );
	}

	/**/
	template< typename IN_TYPE >HBOOL operator!=( const HSmartPointer< IN_TYPE >& in_lhs, const HSINT in_null )
	{
		
		return!( operator==( in_lhs, in_null ) );
	}
	/**/

};

#endif // _H_SMART_POINTER_OPERATORS_H_