//file: Pride/PLine/PLineUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PLine/PLineUtility.h"

#include "Pride/PLine/PLine.h"
#include "Pride/PUnitVector/PUnitVector_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// static public methods
/**/
const Hubris::HBOOL PLineUtility::LineConstruct( 
	Pride::PLineR2& out_line,
	const Hubris::HVectorR2& in_point0, 
	const Hubris::HVectorR2& in_point1,
	Hubris::HREAL* const out_pLength
	)
{
	PUnitVectorR2 unitVector;
	if( HFALSE == PUnitVectorUtility::UnitVectorConstruct(
		unitVector,
		in_point1 - in_point0,
		out_pLength
		) )
	{
		return HFALSE;
	}

	out_line = PLineR2( 
		in_point0,
		unitVector
		);

	return HTRUE;
}

/**/
const Hubris::HBOOL PLineUtility::LineConstruct( 
	Pride::PLineR3& out_line,
	const Hubris::HVectorR3& in_point0, 
	const Hubris::HVectorR3& in_point1,
	Hubris::HREAL* const out_pLength
	)
{
	PUnitVectorR3 unitVector;
	if( HFALSE == PUnitVectorUtility::UnitVectorConstruct(
		unitVector,
		in_point1 - in_point0,
		out_pLength
		) )
	{
		return HFALSE;
	}

	out_line = PLineR3( 
		in_point0,
		unitVector
		);

	return HTRUE;
}

/**/
const Hubris::HVectorR2 PLineUtility::LinePointGet( const PLineR2& in_line, const Hubris::HREAL in_ratioOnLine )
{
	const HVectorR2 point = in_line.OriginGet() + ( in_line.DirectionGet().VectorGet() * in_ratioOnLine );
	return point;
}

/**/
const Hubris::HVectorR3 PLineUtility::LinePointGet( const PLineR3& in_line, const Hubris::HREAL in_ratioOnLine )
{
	const HVectorR3 point = in_line.OriginGet() + ( in_line.DirectionGet().VectorGet() * in_ratioOnLine );
	return point;
}

/**/
const Pride::PLineR3 PLineUtility::LineTransform( const PLineR3& in_line, const Hubris::HMatrixR4& in_matrix )
{
	PLineR3 returnLine(
		HMatrixUtility::VectorProduct( in_matrix, in_line.OriginGet() ),
		PUnitVectorR3( HMatrixUtility::VectorProductNoTranslate( in_matrix, in_line.DirectionGet().VectorGet() ) )
		);

	return returnLine;
}

/**/
