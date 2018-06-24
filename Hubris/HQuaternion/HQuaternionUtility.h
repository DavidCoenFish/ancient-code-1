//file: Hubris/HQuaternion/HQuaternionUtility.h
#ifndef _H_QUATERNION_UTILITY_H_
#define _H_QUATERNION_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE >class HQuaternion;
	typedef HQuaternion< HREAL >HQuaternionREAL;
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >class HMatrix;

	/**/
	struct HQuaternionUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HQuaternionUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >
		static const IN_TYPE Normalise( 
			const IN_TYPE& in_value 
			);

		//length squared
		template< typename IN_TYPE >
		typename static const IN_TYPE LengthSquared( 
			const HQuaternion< IN_TYPE >& in_src 
			);

		//length, modulus
		template< typename IN_TYPE >
		typename static const IN_TYPE Length( 
			const HQuaternion< IN_TYPE >& in_src 
			);

		//neg imaginary
		template< typename IN_TYPE >
		static const IN_TYPE Conjugate( 
			const IN_TYPE& in_src 
			);

		//Conjugate of src / norm
		template< typename IN_TYPE >
		static const IN_TYPE Inverse( 
			const IN_TYPE& in_src 
			);

		//assumes unit quaternion
		template< typename IN_TYPE >
		static const HMatrix< typename IN_TYPE, 4, 4> ConvertToMatrix4( 
			const HQuaternion< IN_TYPE >& in_src 
			);

		template< typename IN_TYPE >
		static const HMatrix< typename IN_TYPE, 3, 3> ConvertToMatrix3( 
			const HQuaternion< IN_TYPE >& in_src 
			);

		//assumes orthoginal unit scale matrix
		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > ConvertFromMatrix4( 
			const HMatrix< IN_TYPE, 4, 4>& in_src 
			);

		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > ConvertFromMatrix( 
			const HMatrix< IN_TYPE, 3, 3>& in_src 
			);

		//create a quaternion from unit axis and rad angle
		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > ConvertFromAxisAngle( 
			const HMatrix< IN_TYPE, 3, 1 >& in_axis, 
			const HREAL in_angleRad 
			);

		//create a quaternion to get from vect src to dest
		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > BetweenVectors( 
			const HMatrix< IN_TYPE, 3, 1 >& in_src, 
			const HMatrix< IN_TYPE, 3, 1 >& in_dest 
			);

		//rotation around x, y, then z axis
		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > ConvertFromEular( 
			typename const IN_TYPE& in_xRadian, 
			typename const IN_TYPE& in_yRadian,
			typename const IN_TYPE& in_zRadian
			);

		template< typename IN_TYPE >
		static HVOID ConvertToEular( 
			typename IN_TYPE& out_xRadian, 
			typename IN_TYPE& out_yRadian,
			typename IN_TYPE& out_zRadian,
			const HQuaternion< IN_TYPE >& in_quaternion
			);

		template< typename IN_TYPE >
		static const HQuaternion< IN_TYPE > ConvertFromPolar( 
			typename const IN_TYPE& in_lattitudeRadians, 
			typename const IN_TYPE& in_longitudeRadians 
			);


		template< typename IN_TYPE >
		static const HMatrix< typename IN_TYPE, 3, 1 > MultiplyVector( 
			const HQuaternion< IN_TYPE >& in_src, 
			const HMatrix< IN_TYPE, 3, 1 >& in_vector 
			);

	};

	//////////////////////////////////////////////////////////////
	// global free methods
	/**/

	//template const HQuaternionREAL HQuaternionUtility::Normalise( const HQuaternionREAL& in_value );


	//HQuaternionUtility

	//////////////////////////////////////////////////////////////
	// struct
	//template< typename IN_TYPE >struct HQuaternionUtility
	//{
	//	//////////////////////////////////////////////////////////////
	//	// typedef
	//private: 
	//	typedef HQuaternion< IN_TYPE >IN_TYPE;
	//	typedef HMatrix< IN_TYPE, 3, 1>TVector;

	//	//////////////////////////////////////////////////////////////
	//	// public static functions
	//public:
	//	//convert to unit quaternion
	//	static const IN_TYPE Normalise( const IN_TYPE& in_src );

	//	//length squared, norm
	//	static const IN_TYPE LengthSquared( const IN_TYPE& in_src );
	//	//length, modulus
	//	static const IN_TYPE Length( const IN_TYPE& in_src );
	//	//neg imaginary
	//	static const IN_TYPE Conjugate( const IN_TYPE& in_src );
	//	//Conjugate of src / norm
	//	static const IN_TYPE Inverse( const IN_TYPE& in_src );

	//	//assumes unit quaternion
	//	static const HMatrix< IN_TYPE, 4, 4> ConvertToMatrix( const IN_TYPE& in_src );
	//	static const HMatrix< IN_TYPE, 3, 3> ConvertToMatrix3( const IN_TYPE& in_src );
	//	//assumes orthoginal unit scale matrix
	//	static const IN_TYPE ConvertFromMatrix( const HMatrix< IN_TYPE, 4, 4>& in_src );

	//	//create a quaternion from unit axis and rad angle
	//	static const IN_TYPE ConvertFromAxisAngle( const TVector& in_axis, const HREAL in_angleRad );

	//	//create a quaternion to get from vect src to dest
	//	static const IN_TYPE BetweenVectors( const TVector& in_src, const TVector& in_dest );

	//	//rotation around x, y, then z axis
	//	static const IN_TYPE ConvertFromEular( 
	//		const IN_TYPE& in_xRadian, 
	//		const IN_TYPE& in_yRadian,
	//		const IN_TYPE& in_zRadian
	//		);

	//	static HVOID ConvertToEular( 
	//		IN_TYPE& out_xRadian, 
	//		IN_TYPE& out_yRadian,
	//		IN_TYPE& out_zRadian,
	//		const IN_TYPE& in_quaternion
	//		);

	//	static const IN_TYPE ConvertFromPolar( 
	//		const IN_TYPE& in_lattitudeRadians, 
	//		const IN_TYPE& in_longitudeRadians 
	//		);


	//	static const TVector MultiplyVector( const IN_TYPE& in_src, const TVector& in_vector );

	//	//////////////////////////////////////////////////////////////
	//	// disabled
	//private:
	//	~HQuaternionUtility();

	//};

	/**/
};

#endif //_H_QUATERNION_UTILITY_H_
