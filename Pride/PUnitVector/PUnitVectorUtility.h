//file: Pride/PUnitVector/PUnitVectorUtility.h
#ifndef _P_UNIT_VECTOR_UTILITY_H_
#define _P_UNIT_VECTOR_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2;
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PUnitVectorUtility
	{
		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return true if a valid unit vector, can return length. return false if vector within epsilon of zero
		static const Hubris::HBOOL UnitVectorConstruct(
			PUnitVectorR2& out_unitVector,
			const Hubris::HVectorR2& in_vector, 
			Hubris::HREAL* const out_pLength = HNULL
			);
		static const Hubris::HBOOL UnitVectorConstruct(
			PUnitVectorR3& out_unitVector,
			const Hubris::HVectorR3& in_vector, 
			Hubris::HREAL* const out_pLength = HNULL
			);

		static Hubris::HVOID UnitVectorFromPolar( 
			PUnitVectorR3& out_unitVector,
			const Hubris::HREAL in_latitude, //-180 ... 180 deg
			const Hubris::HREAL in_longitude //-90 ... 90 deg
			);

		static Hubris::HVOID PolarFromUnitVector(
			Hubris::HREAL& out_latitude, //-180 ... 180 deg
			Hubris::HREAL& out_longitude, //-90 ... 90 deg
			const PUnitVectorR3& in_unitVector
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PUnitVectorUtility();

	};

	/**/
};

/**/
#endif // _P_UNIT_VECTOR_UTILITY_H_