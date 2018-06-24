//file: Pride/PGeometry/PGeometryOperator.h
#ifndef _P_GEOMETRY_OPERATOR_H_
#define _P_GEOMETRY_OPERATOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PGeometry;

	/////////////////////////////////////////////////////////////////
	// free operators
	/*
		lhs and rhs type signatures must match
		policy, for speed, using vertexAdd not vertexUniqueAdd, data is not checked for reuse on operations
	*/
	const PGeometry operator+( const PGeometry& in_lhs, const PGeometry& in_rhs );
	const PGeometry& operator+=( PGeometry& in_out_lhs, const PGeometry& in_rhs );

};

#endif // _P_GEOMETRY_OPERATOR_H_