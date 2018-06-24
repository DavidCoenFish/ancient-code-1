//file: Hubris/HQuaternion/HQuaternion.h
#ifndef _H_QUATERNION_H_
#define _H_QUATERNION_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HVariables/HVariablesMath.h"

/**/
namespace Hubris
{
	//////////////////////////////////////////
	// typedefs
	/**/
	template< typename IN_TYPE >class HQuaternion;
	typedef HQuaternion< HREAL >HQuaternionREAL;
	struct HMathUtility;
	struct HQuaternionUtility;

	//////////////////////////////////////////
	// class
	//see HQuaternionOperators for operators
	//see HQuaternionUtility for general operations
	/*
		http://easyweb.easynet.co.uk/~mrmeanie/quatern/quatern.htm

		w is real scalar component
		i,j,k are imaginary

		rules
		i^2 = -1
		j^2 = -1
		k^2 = -1

		ij = k
		jk = i
		ki = j
		ji = -k
		kj = -i
		ik = -j

		addition:
		q = w + xi + yj + zk
		r = a + bi + cj + dk
		q + r = a + w + i(x + b) + j(y + c) + k(z + d)

		subtraction:
		q = w + xi + yj + zk
		r = a + bi + cj + dk
		q - r = a - w + i(x - b) + j(y - c) + k(z - d)

		multiplication:
		q = w + xi + yj + zk
		r = a + bi + cj + dk
		qr = wa - xb - yc - zd + i(wb + xa + yd - zc) + j(wc - xd + ya - zb) + k(wd + xc - yb + za)

		norm:
		q = w + xi + yj + zk
		norm(q) = w^2 + x^2 + y^2 + z^2

		modulus:
		q = w + xi + yj + zk
		|q| = ( w^2 + x^2 + y^2 + z^2 ) ^ (1/2)

		conjugate:
		q = w + xi + yj + zk
		q* = w - xi - yj - zk

		inverse:
		q = w + xi + yj + zk
		q^(-1) = ( w - xi - yj - zk ) / ( w^2 + x^2 + y^2 + z^2 )

		division:
		q = w + xi + yj + zk
		r = a + bi + cj + dk
		q/r = ( aw + bx + cy + dz + i(ax - bw - cz + dy) + j(ay + bz - cw - dx) + k(az - by + cx - dw) ) / (a^2 + b^2 + c^2 + d^2)

		rotation:
		R radians around axis [s t u]
		q = cos( R / 2 ) + is( sin( R / 2 ) ) + jt( sin( R / 2 ) ) + kt( sint( R / 2 ) )

		matrix:
			1 - 2y^2 - 2z^2		2xy + 2wz			2xz - 2wy			0
		[	2xy - 2wz			1 - 2x^2 - 2z^2		2yz + 2wx			0	]
			2xz + 2wy			2yz - 2wx			1 - 2x^2 - 2y^2		0
				0					0					0				1

	*/
	template< typename IN_TYPE >class HQuaternion
	{
		friend HMathUtility;
		friend HQuaternionUtility;

		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HMatrix< IN_TYPE, 4, 1 >TVector;
	public:
		typedef IN_TYPE TType;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HQuaternion( const HQuaternion& in_src );
		HQuaternion( 
			const IN_TYPE in_w = 1.0F, //HVariablesMath::UnitGet< IN_TYPE >(),
			const IN_TYPE in_x = 0.0F, //HVariablesMath::ZeroGet< IN_TYPE >(),
			const IN_TYPE in_y = 0.0F, //HVariablesMath::ZeroGet< IN_TYPE >(), 
			const IN_TYPE in_z = 0.0F //HVariablesMath::ZeroGet< IN_TYPE >()
			);
		~HQuaternion();

		//////////////////////////////////////////
		// operators, for other operators, see HQuaternionOperators
	public:
		const HQuaternion& operator=( const HQuaternion& in_rhs );
		HBOOL operator==( const HQuaternion& in_rhs )const;
		HBOOL operator!=( const HQuaternion& in_rhs )const;

		//////////////////////////////////////////
		// public accessors
	public:
		HVOID WSet( const IN_TYPE in_w );
		const IN_TYPE WGet()const;

		HVOID XSet( const IN_TYPE in_x );
		const IN_TYPE XGet()const;

		HVOID YSet( const IN_TYPE in_y );
		const IN_TYPE YGet()const;

		HVOID ZSet( const IN_TYPE in_z );
		const IN_TYPE ZGet()const;

		//////////////////////////////////////////
		// private members
	private:
		TVector m_data;

	};

	/**/
};

#endif // _H_QUATERNION_H_