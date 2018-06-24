//file: Hubris/HContainer/HContainerLess.h
#ifndef _H_CONTAINER_LESS_H_
#define _H_CONTAINER_LESS_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"

/**/
namespace Hubris
{
	template< typename IN_TYPE >struct HContainerLess
	{
		HBOOL operator()(const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )const
		{
			return( in_lhs < in_rhs );
		}

		static const HString NameGet()
		{
			return( HString( "HLess" ) + "_" + HTraitName< IN_TYPE >::NameGet() );
		}
	};
};

#endif// _H_CONTAINER_LESS_H_
