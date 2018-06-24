//file: Pride/PColour/PColourOperator.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColourOperator.h"

#include "Pride/PColour/PColour.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////
// golbal methods
/**/
const Hubris::HBOOL Pride::operator==( const PColourMono& in_lhs, const PColourMono& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator==( const PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator==( const PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator==( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator==( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator==( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	return( in_lhs.DataGet() == in_rhs.DataGet() );
}

/**/
const Hubris::HBOOL Pride::operator!=( const PColourMono& in_lhs, const PColourMono& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator!=( const PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator!=( const PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator!=( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator!=( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator!=( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	return( in_lhs.DataGet() != in_rhs.DataGet() );
}

/**/
const PColourMono Pride::operator+( const PColourMono& in_lhs, const PColourMono& in_rhs )
{
	PColourMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}
const PColourRgb Pride::operator+( const PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	PColourRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}
const PColourRgba Pride::operator+( const PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	PColourRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}
const PColourRealMono Pride::operator+( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	PColourRealMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}
const PColourRealRgb Pride::operator+( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	PColourRealRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}
const PColourRealRgba Pride::operator+( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return value;
}

/**/
const PColourMono Pride::operator+( const PColourMono& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRgb Pride::operator+( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRgba Pride::operator+( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealMono Pride::operator+( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealRgb Pride::operator+( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealRgba Pride::operator+( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}

/**/
const PColourMono& Pride::operator+=( PColourMono& in_lhs, const PColourMono& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}
const PColourRgb& Pride::operator+=( PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}
const PColourRgba& Pride::operator+=( PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealMono& Pride::operator+=( PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealRgb& Pride::operator+=( PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealRgba& Pride::operator+=( PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() + in_rhs.DataGet() );
	return in_lhs;
}

const PColourMono Pride::operator+=( const PColourMono& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRgb Pride::operator+=( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRgba Pride::operator+=( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealMono Pride::operator+=( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealMono value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealRgb Pride::operator+=( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgb value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}
const PColourRealRgba Pride::operator+=( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( in_lhs.DataGet() + in_rhs );
	return value;
}

const PColourMono Pride::operator*( const PColourMono& in_lhs, const PColourMono& in_rhs )
{
	PColourMono value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
const PColourRgb Pride::operator*( const PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	PColourRgb value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
const PColourRgba Pride::operator*( const PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	PColourRgba value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
const PColourRealMono Pride::operator*( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	PColourRealMono value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
const PColourRealRgb Pride::operator*( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	PColourRealRgb value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}
const PColourRealRgba Pride::operator*( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() ) );
	return value;
}

const PColourMono& Pride::operator*=( PColourMono& in_lhs, const PColourMono& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}
const PColourRgb& Pride::operator*=( PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}
const PColourRgba& Pride::operator*=( PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealMono& Pride::operator*=( PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealRgb& Pride::operator*=( PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}
const PColourRealRgba& Pride::operator*=( PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	in_lhs = HMatrixUtility::MemberMultiply( in_lhs.DataGet(), in_rhs.DataGet() );
	return in_lhs;
}

const PColourMono Pride::operator*( const PColourMono& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourMono value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRgb Pride::operator*( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgb value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRgba Pride::operator*( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs )
{
	PColourRgba value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealMono Pride::operator*( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealMono value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealRgb Pride::operator*( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgb value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealRgba Pride::operator*( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs )
{
	PColourRealRgba value;
	value.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}

const PColourMono& Pride::operator*=( PColourMono& in_lhs, const Hubris::HU8& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRgb& Pride::operator*=( PColourRgb& in_lhs, const Hubris::HU8& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRgba& Pride::operator*=( PColourRgba& in_lhs, const Hubris::HU8& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealMono& Pride::operator*=( PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealRgb& Pride::operator*=( PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}
const PColourRealRgba& Pride::operator*=( PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs )
{
	in_lhs.DataSet( in_lhs.DataGet() * in_rhs );
	return in_lhs;
}

/**/
const Hubris::HBOOL Pride::operator<( const PColourMono& in_lhs, const PColourMono& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator<( const PColourRgb& in_lhs, const PColourRgb& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator<( const PColourRgba& in_lhs, const PColourRgba& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator<( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator<( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}
const Hubris::HBOOL Pride::operator<( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs )
{
	return( in_lhs.DataGet() < in_rhs.DataGet() );
}

/**/