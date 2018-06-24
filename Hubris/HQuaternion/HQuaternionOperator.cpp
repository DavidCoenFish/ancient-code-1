//file: Hubris/HQuaternion/HQuaternionOperator.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HQuaternion/HQuaternionOperator.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HQuaternion/HQuaternion.h"

////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

////////////////////////////////////////////////////
// forward declair templates
/*
	attempt to avoid specilisation instansiating function signitures by forward delaricing them all
*/
template<>const HQuaternion< HREAL > Hubris::operator +( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL > Hubris::operator +( const HQuaternion< HREAL >& in_lhs, const HREAL in_rhs );
template<>const HQuaternion< HREAL > Hubris::operator +( const HREAL in_lhs, const HQuaternion< HREAL >& in_rhs );

template<>const HQuaternion< HREAL >& Hubris::operator +=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL >& Hubris::operator +=( HQuaternion< HREAL >& in_lhs, const HREAL in_rhs );

template<>const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_lhs, const HREAL in_rhs );
template<>const HQuaternion< HREAL > Hubris::operator -( const HREAL in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_src );

template<>const HQuaternion< HREAL >& Hubris::operator -=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL >& Hubris::operator -=( HQuaternion< HREAL >& in_lhs, const HREAL in_rhs );

template<>const HQuaternion< HREAL > Hubris::operator *( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL >& Hubris::operator *=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );

template<>const HQuaternion< HREAL > Hubris::operator /( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HQuaternion< HREAL >& Hubris::operator /=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );

template<>const HBOOL Hubris::operator <( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );
template<>const HBOOL Hubris::operator <=( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs );

/**/

/**/
template<>
const HQuaternion< HREAL > Hubris::operator +( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{	
	HQuaternion< HREAL > returnValue( in_lhs );

	returnValue += in_rhs;

	return returnValue;
}

/**/
template< >
const HQuaternion< HREAL > Hubris::operator +( const HQuaternion< HREAL >& in_lhs, const HREAL in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );

	returnValue += in_rhs;

	return returnValue;
}

template<>
const HQuaternion< HREAL > Hubris::operator +( const HREAL in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );

	returnValue += in_rhs;

	return returnValue;
}

/*
	q = w + xi + yj + zk
	r = a + bi + cj + dk
	q + r = a + w + i(x + b) + j(y + c) + k(z + d)
*/
template<>
const HQuaternion< HREAL >& Hubris::operator +=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	in_lhs.WSet( in_lhs.WGet() + in_rhs.WGet() );
	in_lhs.XSet( in_lhs.XGet() + in_rhs.XGet() );
	in_lhs.YSet( in_lhs.YGet() + in_rhs.YGet() );
	in_lhs.ZSet( in_lhs.ZGet() + in_rhs.ZGet() );

	return in_lhs;
}
/**/
template<>
const HQuaternion< HREAL >& Hubris::operator +=( HQuaternion< HREAL >& in_lhs, const HREAL in_rhs )
{
	HQuaternion< HREAL > localRhs( in_rhs );
	in_lhs += localRhs;

	return in_lhs;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );
	returnValue -= in_rhs;
	return returnValue;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_lhs, const HREAL in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );
	returnValue -= in_rhs;
	return returnValue;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator -( const HREAL in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );
	returnValue -= in_rhs;
	return returnValue;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator -( const HQuaternion< HREAL >& in_src )
{
	HQuaternion< HREAL > returnValue( 
		-in_src.WGet(),
		-in_src.XGet(),
		-in_src.YGet(),
		-in_src.ZGet()
		);

	return returnValue;
}

/**/
template<>
const HQuaternion< HREAL >& Hubris::operator -=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	in_lhs += ( -in_rhs );
	return in_lhs;
}

/**/
template<>
const HQuaternion< HREAL >& Hubris::operator -=( HQuaternion< HREAL >& in_lhs, const HREAL in_rhs )
{
	HQuaternion< HREAL > localRhs( -in_rhs );
	in_lhs += localRhs;

	return in_lhs;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator *( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );

	returnValue *= in_rhs;

	return returnValue;
}

/*
	q = w + xi + yj + zk
	r = a + bi + cj + dk
	qr = wa - xb - yc - zd + i(wb + xa + yd - zc) + j(wc - xd + ya + zb) + k(wd + xc - yb + za)
*/
template<>
const HQuaternion< HREAL >& Hubris::operator *=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	const HREAL w1 = in_lhs.WGet();
	const HREAL x1 = in_lhs.XGet();
	const HREAL y1 = in_lhs.YGet();
	const HREAL z1 = in_lhs.ZGet();

	const HREAL w2 = in_rhs.WGet();
	const HREAL x2 = in_rhs.XGet();
	const HREAL y2 = in_rhs.YGet();
	const HREAL z2 = in_rhs.ZGet();

	in_lhs.WSet( ( w1 * w2 ) - ( x1 * x2 ) - ( y1 * y2 ) - ( z1 * z2 ) );
	in_lhs.XSet( ( w1 * x2 ) + ( x1 * w2 ) + ( y1 * z2 ) - ( z1 * y2 ) );
	in_lhs.YSet( ( w1 * y2 ) - ( x1 * z2 ) + ( y1 * w2 ) + ( z1 * x2 ) );
	in_lhs.ZSet( ( w1 * z2 ) + ( x1 * y2 ) - ( y1 * x2 ) + ( z1 * w2 ) );

	return in_lhs;
}

/**/
template<>
const HQuaternion< HREAL > Hubris::operator /( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HQuaternion< HREAL > returnValue( in_lhs );

	returnValue /= in_rhs;

	return returnValue;
}

/*
	q = w + xi + yj + zk
	r = a + bi + cj + dk
	q/r = ( aw + bx + cy + dz + i(ax - bw - cz + dy) + j(ay + bz - cw - dx) + k(az - by + cx - dw) ) / (a^2 + b^2 + c^2 + d^2)
*/
template<>
const HQuaternion< HREAL >& Hubris::operator /=( HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	const HREAL w = in_lhs.WGet();
	const HREAL x = in_lhs.XGet();
	const HREAL y = in_lhs.YGet();
	const HREAL z = in_lhs.ZGet();
	const HREAL a = in_rhs.WGet();
	const HREAL b = in_rhs.XGet();
	const HREAL c = in_rhs.YGet();
	const HREAL d = in_rhs.ZGet();
	const HREAL mul = HVariablesMath::UnitGet< HREAL >() / ( ( a * a ) + ( b * b ) + ( c * c ) + ( d * d ) );

	in_lhs.WSet( ( ( a * w ) + ( b * x ) + ( c * y ) + ( d * z ) ) * mul );
	in_lhs.XSet( ( ( a * x ) - ( b * w ) - ( c * z ) + ( d * y ) ) * mul );
	in_lhs.YSet( ( ( a * y ) + ( b * z ) - ( c * w ) - ( d * x ) ) * mul );
	in_lhs.ZSet( ( ( a * z ) - ( b * y ) + ( c * x ) - ( d * w ) ) * mul );

	return in_lhs;
}

/**/
template<>
const HBOOL Hubris::operator <( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HBOOL less = HFALSE;
	if( & in_lhs != &in_rhs )
	{
		less = HTRUE;
		less &= ( in_lhs.WGet() < in_rhs.WGet() );
		less &= ( in_lhs.XGet() < in_rhs.XGet() );
		less &= ( in_lhs.YGet() < in_rhs.YGet() );
		less &= ( in_lhs.ZGet() < in_rhs.ZGet() );
	}

	return less;
}

/**/
template<>
const HBOOL Hubris::operator <=( const HQuaternion< HREAL >& in_lhs, const HQuaternion< HREAL >& in_rhs )
{
	HBOOL less = HTRUE;
	if( & in_lhs != &in_rhs )
	{
		less = HTRUE;
		less &= ( in_lhs.WGet() <= in_rhs.WGet() );
		less &= ( in_lhs.XGet() <= in_rhs.XGet() );
		less &= ( in_lhs.YGet() <= in_rhs.YGet() );
		less &= ( in_lhs.ZGet() <= in_rhs.ZGet() );
	}

	return less;
}

/**/
