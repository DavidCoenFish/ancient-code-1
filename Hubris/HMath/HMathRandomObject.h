//file: Hubris/HMath/HMathRandomObject.h
#ifndef _H_MATH_RANDOM_OBJECT_H_
#define _H_MATH_RANDOM_OBJECT_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	////////////////////////////////////////////////////
	// forward
	/**/
	class HMathRandomObjectImplementation;

	class HMathRandomObject
	{
		////////////////////////////////////////////////////
		// creation
	public:
		HMathRandomObject( const HMathRandomObject& in_src );
		HMathRandomObject( const HSINT in_seed );
		HMathRandomObject();
		~HMathRandomObject();

		////////////////////////////////////////////////////
		// operators, for the rest, see HMatrixOperator
	public:
		const HMathRandomObject& operator=( const HMathRandomObject& in_rhs );
		const HBOOL operator==( const HMathRandomObject& in_rhs )const;
		const HBOOL operator!=( const HMathRandomObject& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID RandomSeedSet( const Hubris::HSINT in_seed );
		const Hubris::HREAL RandomRangeOneValueGet(); //return a value [0 ... 1.0 } 
		const Hubris::HREAL RandomValueGet( const Hubris::HREAL in_range );

		const Hubris::HSINT RandomValueIntGet();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const HMathRandomObjectImplementation& ImplementationGet()const;
		HMathRandomObjectImplementation& ImplementationGet();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		HMathRandomObjectImplementation* m_pImplementaion;

	};

};

#endif // _H_MATH_RANDOM_OBJECT_H_