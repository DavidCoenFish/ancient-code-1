//file: Hubris/HSmartPointer/HSmartPointerUtility.h
#ifndef _H_SMART_POINTER_UTILITY_H_
#define _H_SMART_POINTER_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HSmartPointer/HSmartPointer.h"

namespace Hubris
{
	////////////////////////////////////////
	// struct
	/*
		collect some smart pointer operators that act on smart pointers/ arrays as if they are object 
		 (ie, dereference them )
	*/
	struct HSmartPointerUtility
	{
		////////////////////////////////////////
		// public static functions
		/**/
	public:
		template< typename IN_SMART_POINTER > 
		static IN_SMART_POINTER Copy( const IN_SMART_POINTER& in_src )
		{
			IN_SMART_POINTER newPointer;
			if( HNULL != in_src )
			{
				newPointer.Create();
				( *newPointer ) = ( *in_src );
			}
			return newPointer;
		};

		template< typename IN_SMART_POINTER > 
		static HContainerArray< IN_SMART_POINTER > Copy( const HContainerArray< IN_SMART_POINTER >& in_src )
		{
			HContainerArray< IN_SMART_POINTER > returnArray;

			HCOMMON_FOR_EACH( pointer, in_src, HContainerArray< IN_SMART_POINTER > )
			{
				returnArray.Insert( Copy( pointer ) );
			}

			return returnArray;
		};

		/**/
		template< typename IN_SMART_POINTER > 
		static const HBOOL Cmp( const IN_SMART_POINTER& in_lhs, const IN_SMART_POINTER& in_rhs )
		{
			if( ( HNULL == in_lhs ) || 
				( HNULL == in_rhs ) )
			{
				//either side is null, match if both are null
				const HBOOL result = ( in_lhs == in_rhs );
				return result;
			}
			const HBOOL result = ( ( *in_lhs ) == ( *in_rhs ) );
			return result;
		};

		template< typename IN_SMART_POINTER > 
		static const HBOOL Cmp( const HContainerArray< IN_SMART_POINTER >& in_lhs, const HContainerArray< IN_SMART_POINTER >& in_rhs )
		{
			typedef HContainerArray< IN_SMART_POINTER >TArray;
			if( in_lhs.SizeGet() != in_rhs.SizeGet() )
			{
				return HFALSE;
			}

			const TArray::TIterator rhsIter = in_rhs.Begin();
			for( const TArray::TIterator lhsIter = in_lhs.Begin(); lhsIter != in_lhs.End(); ++lhsIter )
			{
				if( HFALSE == Cmp( ( *lhsIter ), ( *rhsIter ) ) )
				{
					return HFALSE;
				}

				++rhsIter;
			}

			return HTRUE;
		};

	};
	/**/


};

/**/
#endif // _H_SMART_POINTER_UTILITY_H_
