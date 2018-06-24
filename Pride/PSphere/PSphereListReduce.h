//file: Pride/PSphere/PSphereListReduce.h
#ifndef _P_SPHERE_LIST_REDUCE_H_
#define _P_SPHERE_LIST_REDUCE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;
}

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2;
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2;
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PSphereListReduce
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerPair< PSphereR3, TArraySint >TPairSphereArraySint;
		typedef Hubris::HContainerArray< TPairSphereArraySint >TArrayPairSphereArraySint;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		static Hubris::HVOID Reduce(
			TArrayPairSphereArraySint& in_out_sphereList,
			const Hubris::HSINT in_targetCount
			);

		///////////////////////////////////////////////////////
		// creation
	private:
		PSphereListReduce(
			TArrayPairSphereArraySint& in_out_sphereList,
			const Hubris::HSINT in_targetCount
			);
		~PSphereListReduce();

		///////////////////////////////////////////////////////
		// disabled
	private:
		PSphereListReduce( const PSphereListReduce& in_src );
		const PSphereListReduce& operator=( const PSphereListReduce& in_rhs );

	};

	/**/	
};

#endif // _P_SPHERE_LIST_REDUCE_H_