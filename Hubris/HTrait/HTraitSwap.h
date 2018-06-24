//file: Hubris/HTrait/HTraitSwap.h
#ifndef _H_TRAIT_SWAP_H_
#define _H_TRAIT_SWAP_H_

#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/*
		overload for quicker value swaps
	*/
	template< typename IN_TYPE >
	HVOID HTraitSwap( IN_TYPE& in_out_lhs, IN_TYPE& in_out_rhs )
	{
		const IN_TYPE temp( in_out_rhs );
		in_out_rhs = in_out_lhs;
		in_out_lhs = temp;
		return;
	}

	/**/
};

#endif // _H_TRAIT_SWAP_H_

