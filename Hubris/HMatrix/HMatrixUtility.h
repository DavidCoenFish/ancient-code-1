//file: Hubris/HMatrix/HMatrixUtility.h
#ifndef _H_MATRIX_UTILITY_H_
#define _H_MATRIX_UTILITY_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HMatrix/HMatrix.h"

namespace Hubris
{
	//////////////////////////////////////////////////////////////
	// typedef

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >class HMatrix;

	typedef HMatrix< HU8, 1, 1 >HVectorU1;
	typedef HMatrix< HU8, 2, 1 >HVectorU2;
	typedef HMatrix< HU8, 3, 1 >HVectorU3;
	typedef HMatrix< HU8, 4, 1 >HVectorU4;
	typedef HMatrix< HU8, 2, 2 >HMatrixU2;
	typedef HMatrix< HU8, 3, 3 >HMatrixU3;
	typedef HMatrix< HU8, 4, 4 >HMatrixU4;

	typedef HMatrix< HSINT, 1, 1 >HVectorS1;
	typedef HMatrix< HSINT, 2, 1 >HVectorS2;
	typedef HMatrix< HSINT, 3, 1 >HVectorS3;
	typedef HMatrix< HSINT, 4, 1 >HVectorS4;
	typedef HMatrix< HSINT, 2, 2 >HMatrixS2;
	typedef HMatrix< HSINT, 3, 3 >HMatrixS3;
	typedef HMatrix< HSINT, 4, 4 >HMatrixS4;

	typedef HMatrix< HREAL, 1, 1 >HVectorR1;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 2, 2 >HMatrixR2;
	typedef HMatrix< HREAL, 3, 3 >HMatrixR3;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;


	/**/
	struct HMatrixUtility
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HMatrixUtility();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >static const HSINT AxisFindLargest( const IN_TYPE& in_vector );

		template< typename IN_TYPE >static const HSINT AxisFindSmallest( const IN_TYPE& in_vector );

		template< typename IN_TYPE >static const HSINT AxisFindLargestAbsoluteSigned( const IN_TYPE& in_vector, Hubris::HBOOL& out_negative );


		template< typename IN_TYPE >static const IN_TYPE Compose( 
			const IN_TYPE& in_matrixRotate,
			const IN_TYPE& in_matrixScale,
			const IN_TYPE& in_matrixTranslate
			);

		// return cross product
		template< typename IN_TYPE >static const IN_TYPE CrossProduct( const IN_TYPE& in_lhs );
		template< typename IN_TYPE >static const IN_TYPE CrossProduct( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		template< typename IN_TYPE >static const IN_TYPE CrossVector( const IN_TYPE& in_value );

		template< typename IN_TYPE >static HVOID Decompose( 
			IN_TYPE& out_matrixRotate,
			IN_TYPE& out_matrixScale,
			IN_TYPE& out_matrixTranslate,
			const IN_TYPE& in_matrix
			);

		template< typename IN_MATRIX, typename IN_QUATERNION, typename IN_VECTOR, typename IN_SCALE >static HVOID DecomposeTransform( 
			IN_QUATERNION& out_rotate,
			IN_VECTOR& out_translate,
			IN_SCALE& out_scale,
			const IN_MATRIX& in_matrix
			);

		//scale is scalar and same as base type for other types
		template< typename IN_MATRIX, typename IN_QUATERNION, typename IN_VECTOR, typename IN_SCALE >static HVOID ComposeTransform( 
			IN_MATRIX& out_matrix,
			const IN_QUATERNION& in_rotate,
			const IN_VECTOR& in_translate,
			const IN_SCALE& in_scale
			);

		template< typename IN_TYPE, HSINT IN_WIDTH >static const IN_TYPE Determinant( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_value );

		// return dot product
		template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >static const IN_TYPE DotProduct( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );

		template< typename IN_TYPE >static const IN_TYPE& IdentityGet();

		template< typename IN_TYPE >static const IN_TYPE Inverse( const IN_TYPE& in_value );

		// return true if all values in lhs are smaller than rhs
		template< typename IN_TYPE >static const HBOOL Larger( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		// return true if all values in lhs are smaller or equal than rhs
		template< typename IN_TYPE >static const HBOOL LargerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >static const IN_TYPE Length( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value );

		template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >static const IN_TYPE LengthSquared( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value );

		//return a matrix of each member multiplied [ L0 x R0, L1 x R1, ... ]
		template< typename IN_TYPE >static const IN_TYPE MemberMultiply( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		//multiplication of each member
		template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >static const IN_TYPE MemberProduct( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value );
		//sum of each product
		template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >static const IN_TYPE MemberSum( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value );

		template< typename IN_MAJOR, typename IN_MINOR >
		static const IN_MINOR MinorMatrixGet( const IN_MAJOR& in_src, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );

		template< typename IN_MAJOR, typename IN_MINOR >
		static Hubris::HVOID MinorMatrixSet( IN_MAJOR& out_major, const IN_MINOR& in_minor, const HSINT in_excludeIndexX, const HSINT in_excludeIndexY );

		template< typename IN_TYPE >static const IN_TYPE Normalise( const IN_TYPE& in_value );

		// refelect the vector as if it has hit a mirror surface (plane defined by unitMirror) //ie. bounce ray off surface
		template< typename IN_TYPE >static const IN_TYPE Reflect( const IN_TYPE& in_unitMirror, const IN_TYPE& in_vector );

		// create a mirror verion of the vector on the other side of the mirror plane
		template< typename IN_TYPE >static const IN_TYPE Mirror( const IN_TYPE& in_unitMirror, const IN_TYPE& in_vector );

		//get the 'length' of the in_width-1 sub matrix, ie, the rotation component
		template< typename IN_TYPE, HSINT IN_WIDTH >typename static const IN_TYPE RotationLengthSquaredGet( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src );
		//set the 'length' of the in_width-1 sub matrix, ie, the rotation component
		template< typename IN_TYPE, HSINT IN_WIDTH >static HVOID RotationLengthSquaredSet( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_out_src, const IN_TYPE in_lengthSquared );

		//get the 'length' of the in_width-1 sub matrix, ie, the rotation component
		template< typename IN_TYPE, HSINT IN_WIDTH >typename static const IN_TYPE RotationLengthGet( const HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_src );
		//set the 'length' of the in_width-1 sub matrix, ie, the rotation component
		template< typename IN_TYPE, HSINT IN_WIDTH >static HVOID RotationLengthSet( HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >& in_out_src, typename const IN_TYPE in_length );

		// return true if all values in lhs are smaller than rhs
		template< typename IN_TYPE >static const HBOOL Smaller( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		// return true if all values in lhs are smaller or equal than rhs
		template< typename IN_TYPE >static const HBOOL SmallerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

		template< typename IN_MATRIX, typename IN_VECTOR >static const IN_VECTOR TranslateGet( const IN_MATRIX& in_matrix );
		//template< typename IN_TYPE >static const  HMatrix< typename IN_TYPE::TType, typename IN_TYPE::TVar::TSubWidth, 1 > TranslateGet( const IN_MATRIX& in_matrix );

		template< typename IN_MATRIX, typename IN_VECTOR >static HVOID TranslateSet( IN_MATRIX& out_matrix, const IN_VECTOR& in_translate );

		template< typename IN_TYPE >static const IN_TYPE Transpose( const IN_TYPE& in_value );

		template< typename IN_MATRIX, typename IN_VECTOR >static const IN_VECTOR VectorProduct( const IN_MATRIX& in_lhs, const IN_VECTOR& in_rhs );
		template< typename IN_MATRIX, typename IN_VECTOR >static const IN_VECTOR VectorProductNoTranslate( const IN_MATRIX& in_lhs, const IN_VECTOR& in_rhs );

	};

	////template< typename IN_TYPE >const IN_TYPE HMatrixUtility::CrossProduct( const IN_TYPE& in_lhs );
	////template< typename IN_TYPE >const IN_TYPE HMatrixUtility::CrossProduct( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );

	//template<>const HVectorR2 HMatrixUtility::CrossProduct( const HVectorR2& in_lhs );
	//template<>const HVectorR3 HMatrixUtility::CrossProduct( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >typename const IN_TYPE HMatrixUtility::DotProduct( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_lhs, const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs );
	////template<>const HREAL HMatrixUtility::DotProduct( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HREAL HMatrixUtility::DotProduct( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE >const IN_TYPE HMatrixUtility::Reflect( const IN_TYPE& in_unitMirror, const IN_TYPE& in_vector );
	//template<>const HVectorR2 HMatrixUtility::Reflect( const HVectorR2& in_unitMirror, const HVectorR2& in_vector );
	//template<>const HVectorR3 HMatrixUtility::Reflect( const HVectorR3& in_unitMirror, const HVectorR3& in_vector );

	////template< typename IN_TYPE >const HBOOL HMatrixUtility::Smaller( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HBOOL HMatrixUtility::Smaller( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HBOOL HMatrixUtility::Smaller( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE >const HBOOL HMatrixUtility::SmallerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HBOOL HMatrixUtility::SmallerEqual( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HBOOL HMatrixUtility::SmallerEqual( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE >const HBOOL HMatrixUtility::Larger( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HBOOL HMatrixUtility::Larger( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HBOOL HMatrixUtility::Larger( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE >const HBOOL HMatrixUtility::LargerEqual( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HBOOL HMatrixUtility::LargerEqual( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HBOOL HMatrixUtility::LargerEqual( const HVectorR3& in_lhs, const HVectorR3& in_rhs );

	////template< typename IN_TYPE >const IN_TYPE HMatrixUtility::MemberMultiply( const IN_TYPE& in_lhs, const IN_TYPE& in_rhs );
	//template<>const HVectorU1 HMatrixUtility::MemberMultiply( const HVectorU1& in_lhs, const HVectorU1& in_rhs );
	//template<>const HVectorU2 HMatrixUtility::MemberMultiply( const HVectorU2& in_lhs, const HVectorU2& in_rhs );
	//template<>const HVectorU3 HMatrixUtility::MemberMultiply( const HVectorU3& in_lhs, const HVectorU3& in_rhs );
	//template<>const HVectorU4 HMatrixUtility::MemberMultiply( const HVectorU4& in_lhs, const HVectorU4& in_rhs );

	//template<>const HVectorR1 HMatrixUtility::MemberMultiply( const HVectorR1& in_lhs, const HVectorR1& in_rhs );
	//template<>const HVectorR2 HMatrixUtility::MemberMultiply( const HVectorR2& in_lhs, const HVectorR2& in_rhs );
	//template<>const HVectorR3 HMatrixUtility::MemberMultiply( const HVectorR3& in_lhs, const HVectorR3& in_rhs );
	//template<>const HVectorR4 HMatrixUtility::MemberMultiply( const HVectorR4& in_lhs, const HVectorR4& in_rhs );

	////template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >const IN_TYPE HMatrixUtility::MemberSum( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_value );
	////template< typename IN_TYPE >typename const IN_TYPE::TType HMatrixUtility::MemberSum( const IN_TYPE& in_value );
	//template<>const HREAL HMatrixUtility::MemberSum( const HVectorR3& in_value );
	//template<>const HREAL HMatrixUtility::MemberSum( const HMatrixR4& in_value );

	////template< typename IN_TYPE >const IN_TYPE& HMatrixUtility::Identity();
	//template<>const HMatrixR2& HMatrixUtility::Identity();
	//template<>const HMatrixR3& HMatrixUtility::Identity();
	//template<>const HMatrixR4& HMatrixUtility::Identity();
	//
	////template< typename IN_TYPE >const IN_TYPE HMatrixUtility::Normalise( const IN_TYPE& in_value );
	//template<>const HVectorR1 HMatrixUtility::Normalise( const HVectorR1& in_value );
	//template<>const HVectorR2 HMatrixUtility::Normalise( const HVectorR2& in_value );
	//template<>const HVectorR3 HMatrixUtility::Normalise( const HVectorR3& in_value );
	//template<>const HVectorR4 HMatrixUtility::Normalise( const HVectorR4& in_value );
	//template<>const HMatrixR2 HMatrixUtility::Normalise( const HMatrixR2& in_value );
	//template<>const HMatrixR3 HMatrixUtility::Normalise( const HMatrixR3& in_value );
	//template<>const HMatrixR4 HMatrixUtility::Normalise( const HMatrixR4& in_value );


	////	static const TVector TranslateGet( const TMatrix& in_matrix );
	////	static HVOID TranslateSet( TMatrix& out_matrix, const TVector& in_translate );

	////template< typename IN_MATRIX, typename IN_TYPE >const IN_TYPE HMatrixUtility::TranslateGet( const IN_MATRIX& in_matrix );
	//template<>const HVectorR3 HMatrixUtility::TranslateGet( const HMatrixR4& in_value );

	////template< typename IN_MATRIX, typename IN_TYPE >HVOID HMatrixUtility::TranslateSet( IN_MATRIX& out_matrix, const IN_TYPE& in_translate );
	//template<>HVOID HMatrixUtility::TranslateSet( HMatrixR4& out_matrix, const HVectorR3& in_translate );

//	//const HMatrixR4 HMatrixUtilityCreate( HVectorR3& in_at, HVectorR3& in_up )
//
//	//////////////////////////////////////////////////////////////
//	// struct
//	//dot, normalise, transpose, hCross, hDeterminant, hInvert
//	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >struct HMatrixUtility
//	{
//		//////////////////////////////////////////////////////////////
//		// typedef
//	private: 
//		typedef HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >TMatrix;
//
//		//////////////////////////////////////////////////////////////
//		// public static functions
//	public:
//		//return the sum of all members of the matrix
//		static const IN_TYPE MemberSum( const TMatrix& in_src );
//
//		//return the value of all members of the matrix multiplied
//		static const IN_TYPE MemberMul( const TMatrix& in_src );
//
//		//return the matrix reult of each lhs member mul each rhs member
//		static const TMatrix MemberProduct( const TMatrix& in_lhs, const TMatrix& in_rhs );
//
//		//normalise given matrix as return
//		static const TMatrix Normalise( const TMatrix& in_src );
//
//		//move to construct? easy to templated for type, but nor size...
//		static const TMatrix CrossProduct( const TMatrix& in_lhs, const TMatrix& in_rhs );
//
//		//create a cross product of a vector
//		static const TMatrix CrossVector( const TMatrix& in_src );
//
////		//given array of HMatrix::TVar::TSize - 1 input, find the cross product
////		static TMatrix Cross( const TMatrix * const in_inputArray
////#ifdef _DEBUG //confirm array size in debug
////			, const HSINT in_debugArrayLength
////#endif
////			 );
//
//		//dot product of two given matrix 
//		static const IN_TYPE DotProduct( const TMatrix& in_lhs, const TMatrix& in_rhs );
//
//		//return the length of matrix
//		static const IN_TYPE Length( const TMatrix& in_vector ); 
//
//		//return the length squared of matrix, ie, skip the square root, same as dot product with self
//		static const IN_TYPE LengthSquared( const TMatrix& in_vector ); 
//
//		static const HSINT AxisFindLargest( const TMatrix& in_vector );
//		static const HSINT AxisFindSmallest( const TMatrix& in_vector );
//
//		//out_negative = HFALSE, +x(0), +y(1), +z(2), 
//		//out_negative = HTRUE, -x(0), -y(1), -z(2), 
//		static const HSINT AxisFindLargestAbsoluteSigned( 
//			const TMatrix& in_vector,  
//			Hubris::HBOOL& out_negative
//			);
//
//		//////////////////////////////////////////////////////////////
//		// disabled
//	private:
//		~HMatrixUtility();
//	};

};

#endif // _H_MATRIX_UTILITY_H_
