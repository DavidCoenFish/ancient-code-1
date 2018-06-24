//file: Hubris/HQuaternion/HQuaternionOperator.h
#ifndef _H_QUATERNION_OPERATOR_H_
#define _H_QUATERNION_OPERATOR_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	/**/
	template< typename IN_TYPE >class HQuaternion;

	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator +( const IN_TYPE in_lhs, const HQuaternion< IN_TYPE >& in_rhs );

	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator +=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator +=( HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );

	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const IN_TYPE in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator -( const HQuaternion< IN_TYPE >& in_src );

	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator -=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator -=( HQuaternion< IN_TYPE >& in_lhs, const IN_TYPE in_rhs );

	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator *( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator *=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );

	template< typename IN_TYPE >const HQuaternion< IN_TYPE > operator /( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HQuaternion< IN_TYPE >& operator /=( HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );

	template< typename IN_TYPE >const HBOOL operator <( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );
	template< typename IN_TYPE >const HBOOL operator <=( const HQuaternion< IN_TYPE >& in_lhs, const HQuaternion< IN_TYPE >& in_rhs );

	/**/
};

#endif //_H_QUATERNION_OPERATOR_H_