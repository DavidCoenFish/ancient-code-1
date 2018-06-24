//file: Pride/PBounds/PBounds.h
#ifndef _P_BOUNDS_OPERATOR_H_
#define _P_BOUNDS_OPERATOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3; //instanciated in cpp

	/////////////////////////////////////////////////////////////////
	// global operators
	/**/
	const PBoundsR1 operator+( const PBoundsR1& in_lhs, const PBoundsR1& in_rhs );
	const PBoundsR2 operator+( const PBoundsR2& in_lhs, const PBoundsR2& in_rhs );
	const PBoundsR3 operator+( const PBoundsR3& in_lhs, const PBoundsR3& in_rhs );

	const PBoundsR1& operator+=( PBoundsR1& in_lhs, const PBoundsR1& in_rhs );
	const PBoundsR2& operator+=( PBoundsR2& in_lhs, const PBoundsR2& in_rhs );
	const PBoundsR3& operator+=( PBoundsR3& in_lhs, const PBoundsR3& in_rhs );

};

/**/
#endif // _P_BOUNDS_OPERATOR_H_