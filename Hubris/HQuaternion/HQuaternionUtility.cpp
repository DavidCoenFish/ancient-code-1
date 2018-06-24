//file: Hubris/HQuaternion/HQuaternionUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HQuaternion/HQuaternionUtility.h"

#include "Hubris/HQuaternion/HQuaternion.h"
#include "Hubris/HQuaternion/HQuaternionOperator.h"

#include "Hubris/HMath/HMath.h"
#include "Hubris/HMath/HMathUtility.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"
#include "Hubris/HMatrix/HMatrixUtility.h"
#include "Hubris/HVariables/HVariablesMath.h"

////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////////////
// local static methods
/**/

/////////////////////////////////////////////////////////////////
// static public methods
/*
	Normalise
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternionUtility::Normalise( 
	const IN_TYPE& in_value 
	)
{
	IN_TYPE returnQuaternion;
	returnQuaternion.m_data = HMatrixUtility::Normalise( in_value.m_data );
	return returnQuaternion;
}

template const HQuaternionREAL Hubris::HQuaternionUtility::Normalise( const HQuaternionREAL& in_value );

/*
	LengthSquared

const IN_TYPE::TType Hubris::HQuaternionUtility::LengthSquared(const IN_TYPE &)
const Hubris::HQuaternion<IN_TYPE>::TType Hubris::HQuaternionUtility::LengthSquared(const Hubris::HQuaternionREAL &)
*/
template< typename IN_TYPE >
typename static const IN_TYPE Hubris::HQuaternionUtility::LengthSquared( 
	const HQuaternion< IN_TYPE >& in_src 
	)
{
	const IN_TYPE lengthSquared = ( HMatrixUtility::LengthSquared( in_src.m_data ) );
	return lengthSquared;
}

template const HREAL Hubris::HQuaternionUtility::LengthSquared( const HQuaternionREAL& in_src );

/*
	Length
*/
template< typename IN_TYPE >
typename const IN_TYPE Hubris::HQuaternionUtility::Length( 
	const HQuaternion< IN_TYPE >& in_src 
	)
{
	const IN_TYPE length = ( HMatrixUtility::Length( in_src.m_data ) );
	return length;
}

template const HREAL Hubris::HQuaternionUtility::Length( const HQuaternionREAL& in_value );

/*
	Conjugate
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternionUtility::Conjugate( 
	const IN_TYPE& in_src 
	)
{
	return IN_TYPE( in_src.WGet(), -( in_src.XGet() ), -( in_src.YGet() ), -( in_src.ZGet() ) );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::Conjugate( const HQuaternionREAL& in_src );

/*
	Inverse
*/
template< typename IN_TYPE >
const IN_TYPE Hubris::HQuaternionUtility::Inverse( 
	const IN_TYPE& in_src 
	)
{
	const IN_TYPE::TType norm = Length( in_src );
	const IN_TYPE::TType mul = HVariablesMath::UnitGet< IN_TYPE::TType >() / norm;

	return IN_TYPE( in_src.WGet() * mul, -( in_src.XGet() * mul ), -( in_src.YGet() * mul ), -( in_src.ZGet() * mul ) );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::Inverse( const HQuaternionREAL& in_src );

/*
	ConvertToMatrix4

http://www.j3d.org/matrix_faq/matrfaq_latest.html
         ·       2     2                                      ·
         ·1 - (2Y  + 2Z )   2XY + 2ZW         2XZ - 2YW       ·
         ·                                                    ·
         ·                         2     2                    ·
     M = ·2XY - 2ZW         1 - (2X  + 2Z )   2YZ + 2XW       ·
         ·                                                    ·
         ·                                           2     2  ·
         ·2XZ + 2YW         2YZ - 2XW         1 - (2X  + 2Y ) ·
         ·                                                    ·
*/
template< typename IN_TYPE >
const HMatrix< IN_TYPE, 4, 4> Hubris::HQuaternionUtility::ConvertToMatrix4( 
	const HQuaternion< IN_TYPE >& in_src 
	)
{
	typedef HMatrix< IN_TYPE, 4, 4> TMatrix;
	TMatrix matrix;

	const IN_TYPE qw = in_src.WGet();
    const IN_TYPE qx = in_src.XGet();
    const IN_TYPE qy = in_src.YGet();
    const IN_TYPE qz = in_src.ZGet();
    const IN_TYPE xx = qx * qx;
    const IN_TYPE xy = qx * qy;
    const IN_TYPE xz = qx * qz;
    const IN_TYPE xw = qx * qw;
    const IN_TYPE yy = qy * qy;
    const IN_TYPE yz = qy * qz;
    const IN_TYPE yw = qy * qw;
    const IN_TYPE zz = qz * qz;
    const IN_TYPE zw = qz * qw;
	matrix[ TMatrix::IndexGet( 0, 0 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( yy + zz ) );
	matrix[ TMatrix::IndexGet( 1, 0 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xy - zw );
    matrix[ TMatrix::IndexGet( 2, 0 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xz + yw );
    matrix[ TMatrix::IndexGet( 0, 1 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xy + zw );
    matrix[ TMatrix::IndexGet( 1, 1 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( xx + zz ) );
    matrix[ TMatrix::IndexGet( 2, 1 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( yz - xw );
    matrix[ TMatrix::IndexGet( 0, 2 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xz - yw );
    matrix[ TMatrix::IndexGet( 1, 2 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( yz + xw );
    matrix[ TMatrix::IndexGet( 2, 2 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( xx + yy ) );
    matrix[ TMatrix::IndexGet( 3, 3 ) ] = HVariablesMath::UnitGet< IN_TYPE >();

	return matrix;
}

template const HMatrixR4 Hubris::HQuaternionUtility::ConvertToMatrix4( const HQuaternionREAL& in_src );

/*
	ConvertToMatrix3
*/
template< typename IN_TYPE >
const HMatrix< typename IN_TYPE, 3, 3 > Hubris::HQuaternionUtility::ConvertToMatrix3( 
	const HQuaternion< IN_TYPE >& in_src 
	)
{
	typedef HMatrix< IN_TYPE, 3, 3 > TMatrix;
	TMatrix matrix;

	const IN_TYPE qw = in_src.WGet();
    const IN_TYPE qx = in_src.XGet();
    const IN_TYPE qy = in_src.YGet();
    const IN_TYPE qz = in_src.ZGet();
    const IN_TYPE xx = qx * qx;
    const IN_TYPE xy = qx * qy;
    const IN_TYPE xz = qx * qz;
    const IN_TYPE xw = qx * qw;
    const IN_TYPE yy = qy * qy;
    const IN_TYPE yz = qy * qz;
    const IN_TYPE yw = qy * qw;
    const IN_TYPE zz = qz * qz;
    const IN_TYPE zw = qz * qw;
	matrix[ TMatrix::IndexGet( 0, 0 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( yy + zz ) );
	matrix[ TMatrix::IndexGet( 1, 0 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xy - zw );
    matrix[ TMatrix::IndexGet( 2, 0 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xz + yw );
    matrix[ TMatrix::IndexGet( 0, 1 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xy + zw );
    matrix[ TMatrix::IndexGet( 1, 1 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( xx + zz ) );
    matrix[ TMatrix::IndexGet( 2, 1 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( yz - xw );
    matrix[ TMatrix::IndexGet( 0, 2 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( xz - yw );
    matrix[ TMatrix::IndexGet( 1, 2 ) ] = HVariablesMath::TwiceGet< IN_TYPE >() * ( yz + xw );
    matrix[ TMatrix::IndexGet( 2, 2 ) ] = HVariablesMath::UnitGet< IN_TYPE >() - ( HVariablesMath::TwiceGet< IN_TYPE >() * ( xx + yy ) );

	return matrix;
}

template const HMatrixR3 Hubris::HQuaternionUtility::ConvertToMatrix3( const HQuaternionREAL& in_src );

/*
  http://www.j3d.org/matrix_faq/matrfaq_latest.html
                2     2     2
		T = 4 - 4x  - 4y  - 4z

					2    2    2
		= 4( 1 -x  - y  - z )

		= 1 + mat[0] + mat[5] + mat[10]


	If the trace of the matrix is greater than zero, then
	perform an "instant" calculation.
	Important note wrt. rouning errors:

	Test if ( T > 0.00000001 ) to avoid large distortions!

		S = sqrt(T) * 2;
		X = ( mat[9] - mat[6] ) / S;
		Y = ( mat[2] - mat[8] ) / S;
		Z = ( mat[4] - mat[1] ) / S;
		W = 0.25 * S;

	If the trace of the matrix is equal to zero then identify
	which major diagonal element has the greatest value.
	Depending on this, calculate the following:

	if ( mat[0] > mat[5] && mat[0] > mat[10] )  {	// Column 0: 
		S  = sqrt( 1.0 + mat[0] - mat[5] - mat[10] ) * 2;
		X = 0.25 * S;
		Y = (mat[4] + mat[1] ) / S;
		Z = (mat[2] + mat[8] ) / S;
		W = (mat[9] - mat[6] ) / S;
	} else if ( mat[5] > mat[10] ) {			// Column 1: 
		S  = sqrt( 1.0 + mat[5] - mat[0] - mat[10] ) * 2;
		X = (mat[4] + mat[1] ) / S;
		Y = 0.25 * S;
		Z = (mat[9] + mat[6] ) / S;
		W = (mat[2] - mat[8] ) / S;
	} else {						// Column 2:
		S  = sqrt( 1.0 + mat[10] - mat[0] - mat[5] ) * 2;
		X = (mat[2] + mat[8] ) / S;
		Y = (mat[9] + mat[6] ) / S;
		Z = 0.25 * S;
		W = (mat[4] - mat[1] ) / S;
	}
*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::ConvertFromMatrix4( 
	const HMatrix< typename IN_TYPE, 4, 4>& in_src 
	)
{
	typedef HMatrix< typename IN_TYPE, 4, 4> TMatrix;

	IN_TYPE qw = HVariablesMath::UnitGet< IN_TYPE >();
	IN_TYPE qx = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE qy = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE qz = HVariablesMath::ZeroGet< IN_TYPE >();
	const IN_TYPE trace = HVariablesMath::UnitGet< IN_TYPE >() + in_src[0] + in_src[5] + in_src[10];

	if( 0.01F < trace ) //was 0.0F < trace but hitting head on 180deg axis rotation
	{
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( trace ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = ( in_src[9] - in_src[6] ) * mul;
		qy = ( in_src[2] - in_src[8] ) * mul;
		qz = ( in_src[4] - in_src[1] ) * mul;
		qw = 0.25F / mul;
	}
	else if ( in_src[0] > in_src[5] && in_src[0] > in_src[10] )  
	{	// Column 0: 
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[0] - in_src[5] - in_src[10] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = 0.25F / mul;
		qy = (in_src[4] + in_src[1] ) * mul;
		qz = (in_src[2] + in_src[8] ) * mul;
		qw = (in_src[9] - in_src[6] ) * mul;
	} 
	else if ( in_src[5] > in_src[10] ) 
	{	// Column 1: 
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[5] - in_src[0] - in_src[10] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = (in_src[4] + in_src[1] ) * mul;
		qy = 0.25F / mul;
		qz = (in_src[9] + in_src[6] ) * mul;
		qw = (in_src[2] - in_src[8] ) * mul;
	} else 
	{	// Column 2:
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[10] - in_src[0] - in_src[5] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = (in_src[2] + in_src[8] ) * mul;
		qy = (in_src[9] + in_src[6] ) * mul;
		qz = 0.25F / mul;
		qw = (in_src[4] - in_src[1] ) * mul;
	}

	return HQuaternion< IN_TYPE >( qw, qx, qy, qz );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::ConvertFromMatrix4( const HMatrixR4& in_src );
//template const HQuaternion< HREAL > Hubris::HQuaternionUtility::ConvertFromMatrix( const HMatrix< HREAL, 4, 4>& in_src );
/*
	ConvertFromMatrix
*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::ConvertFromMatrix( 
	const HMatrix< typename IN_TYPE, 3, 3>& in_src 
	)
{
	typedef HMatrix< typename IN_TYPE, 3, 3> TMatrix;

	IN_TYPE qw = HVariablesMath::UnitGet< IN_TYPE >();
	IN_TYPE qx = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE qy = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE qz = HVariablesMath::ZeroGet< IN_TYPE >();
	const IN_TYPE trace = HVariablesMath::UnitGet< IN_TYPE >() + in_src[0] + in_src[4] + in_src[8];

	if( 0.0F < trace )
	{
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( trace ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = ( in_src[7] - in_src[8] ) * mul;
		qy = ( in_src[2] - in_src[6] ) * mul;
		qz = ( in_src[3] - in_src[1] ) * mul;
		qw = 0.25F / mul;
	}
	else if ( in_src[0] > in_src[4] && in_src[0] > in_src[8] )  
	{	// Column 0: 
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[0] - in_src[4] - in_src[8] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = 0.25F / mul;
		qy = (in_src[3] + in_src[1] ) * mul;
		qz = (in_src[2] + in_src[6] ) * mul;
		qw = (in_src[7] - in_src[5] ) * mul;
	} 
	else if ( in_src[4] > in_src[8] ) 
	{	// Column 1: 
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[4] - in_src[0] - in_src[8] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = (in_src[3] + in_src[1] ) * mul;
		qy = 0.25F / mul;
		qz = (in_src[7] + in_src[5] ) * mul;
		qw = (in_src[2] - in_src[6] ) * mul;
	} else 
	{	// Column 2:
		const IN_TYPE mul = HVariablesMath::UnitGet< IN_TYPE >() / ( HMath::SquareRoot( HVariablesMath::UnitGet< IN_TYPE >() + in_src[8] - in_src[0] - in_src[4] ) * HVariablesMath::TwiceGet< IN_TYPE >() );
		qx = (in_src[2] + in_src[6] ) * mul;
		qy = (in_src[8] + in_src[5] ) * mul;
		qz = 0.25F / mul;
		qw = (in_src[3] - in_src[1] ) * mul;
	}

	return HQuaternion< IN_TYPE >( qw, qx, qy, qz );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::ConvertFromMatrix( const HMatrixR3& in_src );

/*
	ConvertFromAxisAngle
*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::ConvertFromAxisAngle( 
	const HMatrix< typename IN_TYPE, 3, 1 >& in_axis, 
	const HREAL in_angleRad 
	)
{
	typedef HMatrix< typename IN_TYPE, 3, 1 >TVector;
	const TVector normalAxis = HMatrixUtility::Normalise( in_axis );
	IN_TYPE angleSin;
	IN_TYPE angleCos;
	HMath::SinCos< IN_TYPE >( in_angleRad * HVariablesMath::HalfGet< IN_TYPE >(), angleSin, angleCos );

	const IN_TYPE qx = normalAxis[ 0 ] * angleSin;
	const IN_TYPE qy = normalAxis[ 1 ] * angleSin;
	const IN_TYPE qz = normalAxis[ 2 ] * angleSin;
	const IN_TYPE qw = angleCos;

	return HQuaternion< IN_TYPE >( qw, qx, qy, qz );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::ConvertFromAxisAngle( const HVectorR3& in_axis, const HREAL in_angleRad );

/*
	BetweenVectors
*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::BetweenVectors( 
	const HMatrix< typename IN_TYPE, 3, 1 >& in_src, 
	const HMatrix< typename IN_TYPE, 3, 1 >& in_dest 
	)
{
	typedef HMatrix< typename IN_TYPE, 3, 1 >TVector;
	const TVector normalSrc = HMatrixUtility::Normalise( in_src );
	const TVector normalDest = HMatrixUtility::Normalise( in_dest );
	const IN_TYPE angle = HMath::CosArc< IN_TYPE >( HMatrixUtility::DotProduct( normalSrc, normalDest ) );

	const TVector axis = HMatrixUtility::Normalise( HMatrixUtility::CrossProduct( normalSrc, normalDest ) );

	return ConvertFromAxisAngle< IN_TYPE >( axis, angle );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::BetweenVectors( const HVectorR3& in_src, const HVectorR3& in_dest );

/*
	ConvertFromEular

http://jsbsim.sourceforge.net/quaternions.html
http://forum.onlineconversion.com/showthread.php?t=5408

q0 = cos(R/2)*cos(P/2)*cos(Y/2)+sin(R/2)*sin(P/2)*sin(Y/2)
q1 = sin(R/2)*cos(P/2)*cos(Y/2)-cos(R/2)*sin(P/2)*sin(Y/2)
q2 = cos(R/2)*sin(P/2)*cos(Y/2)+sin(R/2)*cos(P/2)*sin(Y/2)
q3 = cos(R/2)*cos(P/2)*sin(Y/2)-sin(R/2)*sin(P/2)*cos(Y/2)

*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::ConvertFromEular( 
	typename const IN_TYPE& in_xRadian, 
	typename const IN_TYPE& in_yRadian,
	typename const IN_TYPE& in_zRadian
	)
{
	IN_TYPE sin1;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos1;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE sin2;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos2;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE sin3;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos3;// = HVariablesMath::ZeroGet< IN_TYPE >();


	HMath::SinCos( in_xRadian * HVariablesMath::HalfGet< IN_TYPE >(), sin1, cos1 );
	HMath::SinCos( in_yRadian * HVariablesMath::HalfGet< IN_TYPE >(), sin2, cos2 );
	HMath::SinCos( in_zRadian * HVariablesMath::HalfGet< IN_TYPE >(), sin3, cos3 );

	const IN_TYPE qw = ( cos1 * cos2 * cos3 ) - ( sin1 * sin2 * sin3 );
	const IN_TYPE qx = -( sin1 * cos2 * cos3 ) - ( cos1 * sin2 * sin3 );
	const IN_TYPE qy = -( cos1 * sin2 * cos3 ) + ( sin1 * cos2 * sin3 );
	const IN_TYPE qz = -( cos1 * cos2 * sin3 ) - ( sin1 * sin2 * cos3 );
 
	return HQuaternion< IN_TYPE >( qw, qx, qy, qz );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::ConvertFromEular( 
	const HREAL& in_xRadian, 
	const HREAL& in_yRadian,
	const HREAL& in_zRadian
	);

/*
	ConvertToEular

http://jsbsim.sourceforge.net/quaternions.html
pyr
x = sin-1[(2(q2q3 - q1q4)]
y = tan-1[ ( -2(q2q4 + q1q3) ) / ( q1^2 + q2^2 - q3^2 - q4^2 ) ]
z = tan-1[ ( -2(q1q2 + q3q4) ) / ( q1^2 - q2^2 + q3^2 - q4^2 ) ]

*/
template< typename IN_TYPE >
HVOID Hubris::HQuaternionUtility::ConvertToEular( 
	typename IN_TYPE& out_xRadian, 
	typename IN_TYPE& out_yRadian,
	typename IN_TYPE& out_zRadian,
	typename const HQuaternion< IN_TYPE >& in_quaternion
	)
{
	const IN_TYPE qw = in_quaternion.WGet();
	const IN_TYPE qx = in_quaternion.XGet();
	const IN_TYPE qy = in_quaternion.YGet();
	const IN_TYPE qz = in_quaternion.ZGet();

	out_xRadian = HMath::SinArc( HVariablesMath::TwiceGet< IN_TYPE >() * ( ( qx * qy ) - ( qw * qz ) ) );
	out_yRadian = HMath::TanArc( ( - HVariablesMath::TwiceGet< IN_TYPE >() * ( ( qx * qz ) + ( qw * qy ) ) ) / ( ( qw * qw ) + ( qx * qx ) - ( qy * qy ) - ( qz * qz ) ) );
	out_zRadian = HMath::TanArc( ( - HVariablesMath::TwiceGet< IN_TYPE >() * ( ( qw * qx ) + ( qy * qz ) ) ) / ( ( qw * qw ) - ( qx * qx ) + ( qy * qy ) - ( qz * qz ) ) );

	return;
}

template HVOID Hubris::HQuaternionUtility::ConvertToEular( 
	HREAL& out_xRadian, 
	HREAL& out_yRadian,
	HREAL& out_zRadian,
	const HQuaternionREAL& in_quaternion
	);

/*
	ConvertFromPolar
	http://www.euclideanspace.com/maths/geometry/rotations/conversions/eulerToQuaternion/index.htm
	c1 = cos(h / 2) 
	c2 = cos(a / 2) 
	s1 = sin(h / 2) 
	s2 = sin(a / 2) 

	w = c1 c2
	x = s1 s2
	y = s1 c2
	z = c1 s2

	polar to quaternion? confirm
*/
template< typename IN_TYPE >
const HQuaternion< IN_TYPE > Hubris::HQuaternionUtility::ConvertFromPolar( 
	typename const IN_TYPE& in_lattitudeRadians, 
	typename const IN_TYPE& in_longitudeRadians 
	)
{
	IN_TYPE sin1;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos1;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE sin2;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos2;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE sin3;// = HVariablesMath::ZeroGet< IN_TYPE >();
	IN_TYPE cos3;// = HVariablesMath::ZeroGet< IN_TYPE >();

	HMath::SinCos< IN_TYPE >( in_lattitudeRadians * 0.5F, sin1, cos1 );
	HMath::SinCos< IN_TYPE >( in_longitudeRadians * 0.5F, sin2, cos2 );
	HMath::SinCos< IN_TYPE >( 0.0, sin3 = 0, cos3 = 1 );

	const IN_TYPE qw = ( cos1 * cos2 );
	const IN_TYPE qx = -( sin1 * cos2 );
	const IN_TYPE qy = -( cos1 * sin2 );
	const IN_TYPE qz = -( sin1 * sin2 );
 
	return HQuaternion< IN_TYPE >( qw, qx, qy, qz );
}

template const HQuaternionREAL Hubris::HQuaternionUtility::ConvertFromPolar( 
	const HREAL& in_lattitudeRadians, 
	const HREAL& in_longitudeRadians 
	);

/*
	MultiplyVector
*/
template< typename IN_TYPE >
const HMatrix< typename IN_TYPE, 3, 1 > Hubris::HQuaternionUtility::MultiplyVector( 
	const HQuaternion< IN_TYPE >& in_src, 
	const HMatrix< typename IN_TYPE, 3, 1 >& in_vector 
	)
{
	const HQuaternion< IN_TYPE > quat( 0.0F, in_vector[ 0 ], in_vector[ 1 ], in_vector[ 2 ] );
	const HQuaternion< IN_TYPE > result = 	in_src * quat * Conjugate( in_src );

	return( HMatrixConstructor::HVectorR3Construct( result.XGet(), result.YGet(), result.ZGet() ) );
}

template const HVectorR3 Hubris::HQuaternionUtility::MultiplyVector( const HQuaternionREAL& in_src, const HVectorR3& in_vector );

/**/
