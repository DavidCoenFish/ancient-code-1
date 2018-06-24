//file: Hubris/HMatrix/HMatrixConstructor.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixConstructor.h"

#include "Hubris/HMatrix/HMatrixUtility.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

#include "Hubris/HMath/HMath.h"
#include "Hubris/HVariables/HVariablesMath.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
const HVectorS2 Hubris::HMatrixConstructor::HVectorS2Construct( const HSINT in_x, const HSINT in_y )
{
	HSINT data[ 2 ];
	data[ 0 ] = in_x;
	data[ 1 ] = in_y;
	return HVectorS2( data );
}

/**/
const HVectorS3 Hubris::HMatrixConstructor::HVectorS3Construct( const HSINT in_x, const HSINT in_y, const HSINT in_z )
{
	HSINT data[ 3 ];
	data[ 0 ] = in_x;
	data[ 1 ] = in_y;
	data[ 2 ] = in_z;
	return HVectorS3( data );
}

/**/
const HVectorR2 Hubris::HMatrixConstructor::HVectorR2Construct( const HREAL in_x, const HREAL in_y )
{
	HREAL data[ 2 ];
	data[ 0 ] = in_x;
	data[ 1 ] = in_y;
	return HVectorR2( data );
}

/**/
const HVectorR3 Hubris::HMatrixConstructor::HVectorR3Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z )
{
	HREAL data[ 3 ];
	data[ 0 ] = in_x;
	data[ 1 ] = in_y;
	data[ 2 ] = in_z;
	return HVectorR3( data );
}

/**/
const HVectorR4 Hubris::HMatrixConstructor::HVectorR4Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z, const HREAL in_w )
{
	HREAL data[ 4 ];
	data[ 0 ] = in_x;
	data[ 1 ] = in_y;
	data[ 2 ] = in_z;
	data[ 3 ] = in_w;
	return HVectorR4( data );
}

/*
  http://www.euclideanspace.com/maths/geometry/rotations/conversions/angleToMatrix/index.htm
*/
const HMatrixR4 HMatrixConstructor::HMatrixR4ConstructAxisAngle( const HVectorR3& in_axis, const HREAL in_angleRad )
{
	const HVectorR3 localAxis = HMatrixUtility::Normalise( in_axis );
	const HREAL axis_x = localAxis[ 0 ];
	const HREAL axis_y = localAxis[ 1 ];
	const HREAL axis_z = localAxis[ 2 ];

	HMatrixR4 matrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	HREAL c = HMath::Cos( in_angleRad );
	HREAL s = HMath::Sin( in_angleRad );
	HREAL t = 1.0F - c;

	matrix[ HMatrixR4::IndexGet( 0, 0 ) ] = c + axis_x * axis_x * t;
	matrix[ HMatrixR4::IndexGet( 1, 1 ) ] = c + axis_y * axis_y * t;
	matrix[ HMatrixR4::IndexGet( 2, 2 ) ] = c + axis_z * axis_z * t;

	HREAL tmp1 = axis_x * axis_y * t;
	HREAL tmp2 = axis_z * s;
	matrix[ HMatrixR4::IndexGet( 1, 0 ) ] = tmp1 + tmp2;
	matrix[ HMatrixR4::IndexGet( 0, 1 ) ] = tmp1 - tmp2;
	tmp1 = axis_x * axis_z * t;
	tmp2 = axis_y * s;
	matrix[ HMatrixR4::IndexGet( 2, 0 ) ] = tmp1 - tmp2;
	matrix[ HMatrixR4::IndexGet( 0, 2 ) ] = tmp1 + tmp2;    
	tmp1 = axis_y * axis_z * t;
	tmp2 = axis_x * s;
	matrix[ HMatrixR4::IndexGet( 2, 1 ) ] = tmp1 + tmp2;
	matrix[ HMatrixR4::IndexGet( 1, 2 ) ] = tmp1 - tmp2;

	return matrix;
}

/*
  from _Mathematics for computer graphics p.171
 mapping a pair of vectors onto another pair, u,x being one pair, a,y being another of unit vectors at same angle
 u.x = a.y = cos(\), with sin(\) != 0
 a roation matrix sending u,x to a,y given by
               a 
 M = [u v w ][ b ]
               c
 d = | x * u | = | y * a | = | sin(\) |
 if 90deg = u to x, cos(\) = 0, sin(\) = 1
 v = ( x * u ) / d
 b = ( y * a ) / d
 w = ( x - u( cos(\) ) ) / d
 c = ( y - a( cos(\) ) ) / d
*/
const HMatrixR4 HMatrixConstructor::HMatrixR4ConstructAtUp( 
	const HVectorR3& in_targetAt, 
	const HVectorR3& in_targetUp, 
	const HVectorR3& in_baseAt, 
	const HVectorR3& in_baseUp
	)
{
	HMatrixR4 returnMatrix( HMatrixUtility::IdentityGet< HMatrixR4 >() );

	const HVectorR3 crossBaseUpAt = HMatrixUtility::CrossProduct( in_baseUp, in_baseAt );
	const HVectorR3 crossTargetUpAt = HMatrixUtility::CrossProduct( in_targetUp, in_targetAt );

	for( HSINT index = 0; index < 3; ++index )
	{ 
		returnMatrix[ HMatrixR4::IndexGet( 0, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 0 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 0 ] ) + ( in_baseUp[ index ] * in_targetUp[ 0 ] );
		returnMatrix[ HMatrixR4::IndexGet( 1, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 1 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 1 ] ) + ( in_baseUp[ index ] * in_targetUp[ 1 ] );
		returnMatrix[ HMatrixR4::IndexGet( 2, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 2 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 2 ] ) + ( in_baseUp[ index ] * in_targetUp[ 2 ] );
	} 

	return returnMatrix;
}
const HMatrixR3 HMatrixConstructor::HMatrixR4ConstructAtUp3( 
	const HVectorR3& in_targetAt, 
	const HVectorR3& in_targetUp,
	const HVectorR3& in_baseAt, 
	const HVectorR3& in_baseUp
	)
{
	const HVectorR3 crossBaseUpAt = HMatrixUtility::CrossProduct( in_baseUp, in_baseAt );
	const HVectorR3 crossTargetUpAt = HMatrixUtility::CrossProduct( in_targetUp, in_targetAt );

	HREAL data[ 9 ];
	for( HSINT index = 0; index < 3; ++index )
	{ 
		data[ HMatrixR3::IndexGet( 0, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 0 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 0 ] ) + ( in_baseUp[ index ] * in_targetUp[ 0 ] );
		data[ HMatrixR3::IndexGet( 1, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 1 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 1 ] ) + ( in_baseUp[ index ] * in_targetUp[ 1 ] );
		data[ HMatrixR3::IndexGet( 2, index ) ] = ( in_baseAt[ index ] * in_targetAt[ 2 ] ) + ( crossBaseUpAt[ index ] * crossTargetUpAt[ 2 ] ) + ( in_baseUp[ index ] * in_targetUp[ 2 ] );
	} 

	return HMatrixR3( data );
}

/**/
const HMatrixR4 HMatrixConstructor::HMatrixR4ConstructLookAt( const HVectorR3& in_pos, const HVectorR3& in_target, const HVectorR3& in_up )
{
	const HVectorR3 at = HMatrixUtility::Normalise( in_target - in_pos );

	HMatrixR4 returnMatrix = HMatrixR4ConstructAtUp( at, in_up );

	HMatrixUtility::TranslateSet( returnMatrix, in_pos );

	return returnMatrix;
}

/**/
const HMatrixR3 HMatrixConstructor::HMatrixR3ConstructColoumn(
	const HVectorR3& in_coloumn0,
	const HVectorR3& in_coloumn1,
	const HVectorR3& in_coloumn2
	)
{
	HMatrixR3 returnMatrix;
	returnMatrix[ 0 ] = in_coloumn0[ 0 ];
	returnMatrix[ 3 ] = in_coloumn0[ 1 ];
	returnMatrix[ 6 ] = in_coloumn0[ 2 ];
	returnMatrix[ 1 ] = in_coloumn1[ 0 ];
	returnMatrix[ 4 ] = in_coloumn1[ 1 ];
	returnMatrix[ 7 ] = in_coloumn1[ 2 ];
	returnMatrix[ 2 ] = in_coloumn2[ 0 ];
	returnMatrix[ 5 ] = in_coloumn2[ 1 ];
	returnMatrix[ 8 ] = in_coloumn2[ 2 ];

	return returnMatrix;
}

/**/
const HVectorR3& HMatrixConstructor::HVectorR3AxisX()
{
	static HVectorR3 s_vector = HVectorR3Construct( 
		HVariablesMath::UnitGet< HREAL >(),
		HVariablesMath::ZeroGet< HREAL >(), 
		HVariablesMath::ZeroGet< HREAL >() 
		);
	return s_vector;
}

/**/
const HVectorR3& HMatrixConstructor::HVectorR3AxisY()
{
	static HVectorR3 s_vector = HVectorR3Construct( 
		HVariablesMath::ZeroGet< HREAL >(), 
		HVariablesMath::UnitGet< HREAL >(),
		HVariablesMath::ZeroGet< HREAL >() 
		);
	return s_vector;
}

/**/
const HVectorR3& HMatrixConstructor::HVectorR3AxisZ()
{
	static HVectorR3 s_vector = HVectorR3Construct( 
		HVariablesMath::ZeroGet< HREAL >(), 
		HVariablesMath::ZeroGet< HREAL >(), 
		HVariablesMath::UnitGet< HREAL >()
		);
	return s_vector;
}

/*
-2/width  0  0  0
0  -2/height 0  0
0  0  2/far-near 0
tx ty tz 1

tx = right + left / right - left
ty = top + bottom / top - bottom
tz = far + near / far - near

*
const HMatrixR4 HMatrixConstructor::HMatrixR4ConstructOrtho( 
	const Hubris::HREAL in_width,
	const Hubris::HREAL in_height,
	const Hubris::HREAL in_near,
	const Hubris::HREAL in_far
	)
{
	HREAL data[ 16 ];

	data[  0 ] = -2.0F / in_width;

	return HMatrixR4( data );
}

/*
2near/width  0  0  0
0  2near/height 0  0
A  B  C -1
0 0 D 0

A = right + left / right - left 
A = top + bottom / top - bottom
*
const HMatrixR4 HMatrixConstructor::HMatrixR4ConstructPerspective( 
	const Hubris::HREAL in_width,
	const Hubris::HREAL in_height,
	const Hubris::HREAL in_near,
	const Hubris::HREAL in_far
	)
{
}

/**/