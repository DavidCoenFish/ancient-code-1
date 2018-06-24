//file: Hubris/HContainer/HContainerAlgorithmSort.h
#ifndef _H_CONTAINER_ALGORITHM_SORT_H_
#define _H_CONTAINER_ALGORITHM_SORT_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	template< typename IN_CLASS >class HContainerAlgorithmSort
	{
		///////////////////////////////////////////////////////////
		// public static functions
	public:
		static HBOOL Compair( const IN_CLASS & in_lhs, const IN_CLASS & in_rhs ){ return in_lhs < in_rhs; }

		///////////////////////////////////////////////////////////
		// disabled
	private:
		~HContainerAlgorithmSort();
	};

	/**/
};

#endif // _H_CONTAINER_ALGORITHM_SORT_H_