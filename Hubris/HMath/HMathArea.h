//file: Hubris/HMath/HMathArea.h
#ifndef _H_MATH_AREA_H_
#define _H_MATH_AREA_H_

#include "Hubris/HCommon/HCommonType.h"

/* 
	helper unit to collect area calculations
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////////////
	// predefines
	template< typename IN_TYPE > class HContainerArray;
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;

	/**/
	struct HMathArea
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HMatrix< HREAL, 2, 1 >HVectorR2;
		typedef HContainerArray< HVectorR2 >TArrayVectorR2;

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMathArea();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		//return the area of a closed loop eg. 1-2-3-4 (infered 4-1 )
		static const HREAL AreaClosedLoop( const TArrayVectorR2& in_arrayLoop );

	};

	/**/
};

#endif // _H_MATH_AREA_H_