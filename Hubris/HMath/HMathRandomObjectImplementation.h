//file: Hubris/HMath/HMathRandomObjectImplementation.h
#ifndef _H_MATH_RANDOM_OBJECT_IMPLEMENTATION_H_
#define _H_MATH_RANDOM_OBJECT_IMPLEMENTATION_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HContainer/HContainerStaticArray.h"

////////////////////////////////////////////////////
// forward
/**/

/**/
namespace Hubris
{
	class HMathRandomObjectImplementation
	{
		////////////////////////////////////////////////////
		// typedef
	public:
		struct TVar
		{
			enum TEnum
			{
				TNTAB = 32
			};
		};
		typedef HContainerStaticArray< HSINT, TVar::TNTAB >TStaticArraySint;

		////////////////////////////////////////////////////
		// creation
	public:
		HMathRandomObjectImplementation( const HMathRandomObjectImplementation& in_src );
		HMathRandomObjectImplementation( const HSINT in_seed );
		HMathRandomObjectImplementation();
		~HMathRandomObjectImplementation();

		////////////////////////////////////////////////////
		// operators
	public:
		const HMathRandomObjectImplementation& operator=( const HMathRandomObjectImplementation& in_rhs );
		const HBOOL operator==( const HMathRandomObjectImplementation& in_rhs )const;
		const HBOOL operator!=( const HMathRandomObjectImplementation& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID RandomSeedSet( const Hubris::HSINT in_seed );
		const Hubris::HREAL RandomRangeOneValueGet(); //return a value [0 ... 1.0 } 
		const Hubris::HREAL RandomValueGet( const Hubris::HREAL in_range );

		const Hubris::HSINT RandomValueIntGet();

		/////////////////////////////////////////////////////////////////
		// private methods
	public:
		HVOID Initialise();
		HVOID Generate();
		const HREAL GenerateReal();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		HSINT m_idum;
		HSINT m_idum2;
		HSINT m_iy;
		TStaticArraySint m_staticArrayIv;

	};

};

#endif // _H_MATH_RANDOM_OBJECT_IMPLEMENTATION_H_