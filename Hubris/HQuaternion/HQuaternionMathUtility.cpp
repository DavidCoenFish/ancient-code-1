//file: Hubris/HQuaternion/HQuaternionMathUtility.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HQuaternion/HQuaternionMathUtility.h"

#include "Hubris/HQuaternion/HQuaternion.h"
#include "Hubris/HQuaternion/HQuaternionOperator.h"
//#include "Hubris/HQuaternion/HQuaternionUtility.h" //mark3 lerp

#include "Hubris/HCommon/HCommonDefine.h"
//#include "Hubris/HMath/HMath.h" //mark2 lerp

/*
wierd, i can not compile out calls to HMathUtility< some other type >
while inside my own HMathUtility< quaternion > functions? limits of specialisation?

therefor not using HMathUtility< IN_TYPE::TType >::Functions to help, doh
*/

////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Maximum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HQuaternionREAL Hubris::HMathUtility::Maximum< HQuaternionREAL >( const HQuaternionREAL& in_lhs, const HQuaternionREAL& in_rhs )
{
	HQuaternionREAL value;

	value.WSet( HMathUtility::Maximum( in_lhs.WGet(), in_rhs.WGet() ) );
	value.XSet( HMathUtility::Maximum( in_lhs.XGet(), in_rhs.XGet() ) );
	value.YSet( HMathUtility::Maximum( in_lhs.YGet(), in_rhs.YGet() ) );
	value.ZSet( HMathUtility::Maximum( in_lhs.ZGet(), in_rhs.ZGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Minimum( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HQuaternionREAL Hubris::HMathUtility::Minimum< HQuaternionREAL >( const HQuaternionREAL& in_lhs, const HQuaternionREAL& in_rhs )
{
	HQuaternionREAL value;

	value.WSet( HMathUtility::Minimum( in_lhs.WGet(), in_rhs.WGet() ) );
	value.XSet( HMathUtility::Minimum( in_lhs.XGet(), in_rhs.XGet() ) );
	value.YSet( HMathUtility::Minimum( in_lhs.YGet(), in_rhs.YGet() ) );
	value.ZSet( HMathUtility::Minimum( in_lhs.ZGet(), in_rhs.ZGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Absolute( const IN_TYPE& in_src );
*/
template<>
const HQuaternionREAL Hubris::HMathUtility::Absolute< HQuaternionREAL >( const HQuaternionREAL& in_src )
{
	HQuaternionREAL value;

	value.WSet( HMathUtility::Absolute( in_src.WGet() ) );
	value.XSet( HMathUtility::Absolute( in_src.XGet() ) );
	value.YSet( HMathUtility::Absolute( in_src.YGet() ) );
	value.ZSet( HMathUtility::Absolute( in_src.ZGet() ) );

	return value;
}

/*
	template< typename IN_TYPE >const IN_TYPE HMathUtility::Lerp( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs, const HREAL in_ratio );
*/
template<>
const HQuaternionREAL Hubris::HMathUtility::Lerp< HQuaternionREAL >( const HQuaternionREAL& in_lhs, const HQuaternionREAL& in_rhs, const HREAL in_ratio )
{
	HQuaternionREAL value;

	//mark1
	value.WSet( HMathUtility::Lerp( in_lhs.WGet(), in_rhs.WGet(), in_ratio ) );
	value.XSet( HMathUtility::Lerp( in_lhs.XGet(), in_rhs.XGet(), in_ratio ) );
	value.YSet( HMathUtility::Lerp( in_lhs.YGet(), in_rhs.YGet(), in_ratio ) );
	value.ZSet( HMathUtility::Lerp( in_lhs.ZGet(), in_rhs.ZGet(), in_ratio ) );

	//mark2
	////http://www.3dkingdoms.com/weekly/quat.h
	// // float w1, w2;

	// // float cosTheta = a.Dot(b);
	// // float theta    = (float)acos(cosTheta);
	// // float sinTheta = (float)sin(theta);

	// // if( sinTheta > 0.001f )
	// // {
	//	//w1 = float( sin( (1.0f-t)*theta ) / sinTheta);
	//	//w2 = float( sin( t*theta) / sinTheta);
	// // } else {
	//	//// CQuat a ~= CQuat b
	//	//w1 = 1.0f - t;
	//	//w2 = t;
	// // }

	//const HREAL cosTheta = ( in_lhs.WGet() * in_rhs.WGet() ) + ( in_lhs.XGet() * in_rhs.XGet() ) + ( in_lhs.YGet() * in_rhs.YGet() ) + ( in_lhs.ZGet() * in_rhs.ZGet() );
	//const HREAL theta = HMath::CosArc( cosTheta );
	//const HREAL sinTheta = HMath::CosArc( cosTheta );
	//HREAL localRatio( in_ratio );
	//if( 0.001F < sinTheta )
	//{
	//	localRatio = ( HMath::Sin( in_ratio * theta ) / sinTheta );
	//}

	//value.WSet( HMathUtility::Lerp( in_lhs.WGet(), in_rhs.WGet(), localRatio ) );
	//value.XSet( HMathUtility::Lerp( in_lhs.XGet(), in_rhs.XGet(), localRatio ) );
	//value.YSet( HMathUtility::Lerp( in_lhs.YGet(), in_rhs.YGet(), localRatio ) );
	//value.ZSet( HMathUtility::Lerp( in_lhs.ZGet(), in_rhs.ZGet(), localRatio ) );

	////Mark3
	//HQuaternionREAL localLhs( in_lhs );
	//if( localLhs.WGet() < 0.0F )
	//{
	//	localLhs = HQuaternionUtility::Conjugate( localLhs );
	//}

	//HQuaternionREAL localRhs( in_rhs );
	//if( localRhs.WGet() < 0.0F )
	//{
	//	localRhs = HQuaternionUtility::Conjugate( localRhs );
	//}

	//value.WSet( HMathUtility::Lerp( localLhs.WGet(), localRhs.WGet(), in_ratio ) );
	//value.XSet( HMathUtility::Lerp( localLhs.XGet(), localRhs.XGet(), in_ratio ) );
	//value.YSet( HMathUtility::Lerp( localLhs.YGet(), localRhs.YGet(), in_ratio ) );
	//value.ZSet( HMathUtility::Lerp( localLhs.ZGet(), localRhs.ZGet(), in_ratio ) );

	return value;
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::Valid( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::Valid< HQuaternionREAL >( const HQuaternionREAL& in_src )
{
	return( ( HTRUE == HMathUtility::Valid( in_src.WGet() ) ) &&
		( HTRUE == HMathUtility::Valid( in_src.XGet() ) ) &&
		( HTRUE == HMathUtility::Valid( in_src.YGet() ) ) &&
		( HTRUE == HMathUtility::Valid( in_src.ZGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::ValidNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::ValidNot< HQuaternionREAL >( const HQuaternionREAL& in_src )
{
	return( !HMathUtility::Valid( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZero( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZero< HQuaternionREAL >( const HQuaternionREAL& in_src )
{
	return( HTRUE == HMathUtility::EpsilonZero( in_src.m_data ) );

	//return( ( HTRUE == HMathUtility::EpsilonZero( in_src.WGet() ) ) &&
	//	( HTRUE == HMathUtility::EpsilonZero( in_src.XGet() ) ) &&
	//	( HTRUE == HMathUtility::EpsilonZero( in_src.YGet() ) ) &&
	//	( HTRUE == HMathUtility::EpsilonZero( in_src.ZGet() ) ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonZeroNot( const IN_TYPE& in_src );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonZeroNot< HQuaternionREAL >( const HQuaternionREAL& in_src )
{
	return( !HMathUtility::EpsilonZero( in_src ) );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqual< HQuaternionREAL >( const HQuaternionREAL& in_lhs, const HQuaternionREAL& in_rhs )
{
	return HMathUtility::EpsilonZero( in_lhs - in_rhs );
}

/*
	template< typename IN_TYPE >const HBOOL HMathUtility::EpsilonEqualNot( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
*/
template<>
const HBOOL Hubris::HMathUtility::EpsilonEqualNot< HQuaternionREAL >( const HQuaternionREAL& in_lhs, const HQuaternionREAL& in_rhs )
{
	return( !HMathUtility::EpsilonZero( in_lhs - in_rhs ) );
}

/**/
