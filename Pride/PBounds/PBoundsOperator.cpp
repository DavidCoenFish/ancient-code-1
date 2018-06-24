//file: Pride/PBounds/PBoundsOperator.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PBounds/PBoundsOperator.h"

#include "Pride/PBounds/PBounds.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/////////////////////////////////////////////////////////////////
// global operators
/**/
const PBoundsR1 Pride::operator+( const PBoundsR1& in_lhs, const PBoundsR1& in_rhs )
{
	PBoundsR1 value( in_lhs );
	value += in_rhs;
	return value;
}

/**/
const PBoundsR2 Pride::operator+( const PBoundsR2& in_lhs, const PBoundsR2& in_rhs )
{
	PBoundsR2 value( in_lhs );
	value += in_rhs;
	return value;
}

/**/
const PBoundsR3 Pride::operator+( const PBoundsR3& in_lhs, const PBoundsR3& in_rhs )
{
	PBoundsR3 value( in_lhs );
	value += in_rhs;
	return value;
}

/**/
const PBoundsR1& Pride::operator+=( PBoundsR1& in_lhs, const PBoundsR1& in_rhs )
{
	in_lhs.InsertPoint( in_rhs.VectorMinimumGet() );
	in_lhs.InsertPoint( in_rhs.VectorMaximumGet() );
	return in_lhs;
}

/**/
const PBoundsR2& Pride::operator+=( PBoundsR2& in_lhs, const PBoundsR2& in_rhs )
{
	in_lhs.InsertPoint( in_rhs.VectorMinimumGet() );
	in_lhs.InsertPoint( in_rhs.VectorMaximumGet() );
	return in_lhs;
}

/**/
const PBoundsR3& Pride::operator+=( PBoundsR3& in_lhs, const PBoundsR3& in_rhs )
{
	in_lhs.InsertPoint( in_rhs.VectorMinimumGet() );
	in_lhs.InsertPoint( in_rhs.VectorMaximumGet() );
	return in_lhs;
}

/**/