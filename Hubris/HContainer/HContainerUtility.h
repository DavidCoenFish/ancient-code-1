//file: Hubris/HContainer/HContainerUtility.h
#ifndef _H_CONTAINER_UTILITY_H_
#define _H_CONTAINER_UTILITY_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerArray.h"

/**/
namespace Hubris
{
	struct HContainerUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HContainerUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		/**/
		template< typename IN_CONTAINER >static const typename IN_CONTAINER::TType& Back( const IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 != count, "invalid param" );
			return in_array[ count - 1];
		};

		/**/
		template< typename IN_CONTAINER >static typename IN_CONTAINER::TType& Back( IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 != count, "invalid param" );
			return in_array[ count - 1];
		};

		/**/
		template< typename IN_CONTAINER >static HVOID PopBack( IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 != count, "invalid param" );
			in_array.SizeResize( count - 1 );
			return;
		}

		/**/
		template< typename IN_CONTAINER >static HVOID PopFront( IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 != count, "invalid param" );
			in_array.Remove( in_array.Begin() );
			return;
		}

		/**/
		template< typename IN_CONTAINER >static const HSINT PushBack( IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_data )
		{
			const HSINT index = in_array.SizeGet();
			in_array.Insert( in_data, in_array.End() );
			return index;
		}

		/**/
		template< typename IN_CONTAINER >static const HSINT PushFront( IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_data )
		{
			in_array.Insert( in_data, in_array.Begin() );
			return 0;
		}

		/**/
		template< typename IN_CONTAINER >static const typename IN_CONTAINER::TType& Front( const IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 < count, "invalid param" );

			return in_array[ 0 ];
		}

		template< typename IN_CONTAINER >static typename IN_CONTAINER::TType& Front( IN_CONTAINER& in_array )
		{
			const HSINT count = in_array.SizeGet();
			HCOMMON_ASSERT( 0 < count, "invalid param" );

			return in_array[ 0 ];
		}

		//return index of first item in array that matches data. WARNING slow function
		template< typename IN_CONTAINER >static const HSINT IndexOf( const IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_data )
		{
			for( HSINT index = 0; index < in_array.SizeGet(); ++index )
			{
				if( in_data == in_array[ index ] )
				{
					return index;
				}
			}

			return HCOMMON_INVALID_INDEX;
		}

		//return index of first item in array that matches data. WARNING slow function
		template< typename IN_CONTAINER >static const HSINT UniqueAdd( IN_CONTAINER& in_out_array, typename const IN_CONTAINER::TType& in_data )
		{
			HSINT index = HContainerUtility::IndexOf( in_out_array, in_data );

			if( HCOMMON_INVALID_INDEX == index )
			{
				index = in_out_array.SizeGet();
				HContainerUtility::PushBack( in_out_array, in_data ); 
			}

			return index;
		}

		//return index of highest item with value smaller or == to key
		template< typename IN_CONTAINER >static const HSINT Search( const IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_key, HBOOL& out_beforeStart, HBOOL& out_afterEnd )
		{
			HCOMMON_ASSERT( 0 < in_array.SizeGet(), "invalid param" );
			out_beforeStart = HFALSE;
			out_afterEnd = HFALSE;
			if( in_key <= in_array[ 0 ] )
			{
				out_beforeStart = HTRUE;
				return 0;
			}
			else if( HContainerUtility::Back( in_array ) <= in_key )
			{
				out_afterEnd = HTRUE;
				return in_array.SizeGet() - 1;
			}

			if( in_array.SizeGet() < 8 )
			{
				for( HSINT index = 1; index < in_array.SizeGet(); ++index )
				{
					if( in_key < in_array[ index ] )
					{
						return( index - 1 );
					}

				}

				return in_array.SizeGet() - 1;
			}

			//binary search
			HSINT lowIndex = 0;
			HSINT highIndex = in_array.SizeGet() - 1;

			do
			{
				const HSINT midpoint = ( highIndex + lowIndex ) >> 1;

				if( in_key < in_array[ midpoint ] )
				{
					highIndex = midpoint;
				}
				else
				{
					lowIndex = midpoint;
				}
			}
			while( lowIndex + 1 < highIndex );
			
			return lowIndex;
		}

	};

	/**/
};

#endif// _H_CONTAINER_UTILITY_H_
