//file: Hubris/HMatrix/HMatrixUtility4.h
#ifndef _H_MATRIX_UTILITY4_H_
#define _H_MATRIX_UTILITY4_H_


#include "Hubris/HMatrix/HMatrix.h"

namespace Hubris
{
	////////////////////////////////////////////////////////////////
	//// typedef
	//template< typename IN_TYPE, HSINT IN_SIZE >struct HMatrixUtility4;
	//typedef HMatrixUtility4< HREAL, 4 >HMatrixUtilityR4;

	////////////////////////////////////////////////////////////////
	//// struct
	///*
	//	todo: reconsider class name, started out as utility for 4x4 matrix, but could be 1<N
	//*/
	//template< typename IN_TYPE, HSINT IN_SIZE >struct HMatrixUtility4
	//{
	//	//////////////////////////////////////////////////////////////
	//	// typedef
	//private: 
	//	typedef HMatrix< IN_TYPE, IN_SIZE, IN_SIZE >TMatrix;
	//	typedef HMatrix< IN_TYPE, IN_SIZE - 1, 1 >TVector;
	//	typedef HMatrix< IN_TYPE, IN_SIZE, 1 >TUpcastVector;

	//	//////////////////////////////////////////////////////////////
	//	// public static functions
	//public:
	//	static const TVector TranslateGet( const TMatrix& in_matrix );
	//	static HVOID TranslateSet( TMatrix& out_matrix, const TVector& in_translate );

	//	static const TVector VectorProduct( const TMatrix& in_lhs, const TVector& in_rhs );
	//	static const TVector VectorProductNoTranslate( const TMatrix& in_lhs, const TVector& in_rhs );

	//	static HVOID Decompose( 
	//		TMatrix& out_matrixRotate,
	//		TMatrix& out_matrixScale,
	//		TMatrix& out_matrixTranslate,
	//		const TMatrix& in_matrix
	//		);

	//	static const TMatrix Compose( 
	//		const TMatrix& in_matrixRotate,
	//		const TMatrix& in_matrixScale,
	//		const TMatrix& in_matrixTranslate
	//		);

	//	//////////////////////////////////////////////////////////////
	//	// disabled
	//private:
	//	~HMatrixUtility4();

	//};

};

#endif // _H_MATRIX_UTILITY4_H_