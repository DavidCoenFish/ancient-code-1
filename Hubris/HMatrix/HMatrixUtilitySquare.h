//file: Hubris/HMatrix/HMatrixUtilitySquare.h
#ifndef _H_MATRIX_UTILITY_SQUARE_H_
#define _H_MATRIX_UTILITY_SQUARE_H_



namespace Hubris
{
	////////////////////////////////////////////////////////////////
	//// typedef

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >class HMatrix;
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >struct HMatrixUtility;
	//typedef HMatrixUtility< HREAL, 2, 1 > HMatrixUtilityR2;
	//typedef HMatrixUtility< HREAL, 3, 1 > HMatrixUtilityR3;

	//template< typename IN_TYPE, HSINT IN_WIDTH >struct HMatrixUtilitySquare;
	//typedef HMatrixUtilitySquare< HREAL, 3 >HMatrixUtilitySquareR3;
	//typedef HMatrixUtilitySquare< HREAL, 4 >HMatrixUtilitySquareR4;
	//typedef HMatrixUtilitySquare< HREAL, 5 >HMatrixUtilitySquareR5;

	////////////////////////////////////////////////////////////////
	//// struct

	////dot, normalise, transpose, hCross, hDeterminant, hInvert
	//template< typename IN_TYPE, HSINT IN_WIDTH >struct HMatrixUtilitySquare
	//{
	//	//////////////////////////////////////////////////////////////
	//	// typedef
	//private: 
	//	typedef HMatrix< IN_TYPE, IN_WIDTH, IN_WIDTH >TMatrix;
	//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, IN_WIDTH - 1 >TMatrixMinor;
	//	typedef HMatrix< IN_TYPE, IN_WIDTH - 1, 1 >TVector;

	//	//////////////////////////////////////////////////////////////
	//	// public static functions
	//public:
	//	static IN_TYPE Determinant( const TMatrix& in_src ); 

	//	static TMatrix Transpose( const TMatrix& in_src );

	//	static TMatrix Inverse( const TMatrix& in_src );

	//	static const TMatrix& Identity();

	//	//get the 'length' of the in_width-1 sub matrix, ie, the rotation component
	//	static const IN_TYPE RotationLengthSquaredGet( const TMatrix& in_src );
	//	//set the 'length' of the in_width-1 sub matrix, ie, the rotation component
	//	static HVOID RotationLengthSquaredSet( TMatrix& in_out_src, const IN_TYPE in_lengthSquared );

	//	//get the 'length' of the in_width-1 sub matrix, ie, the rotation component
	//	static const IN_TYPE RotationLengthGet( const TMatrix& in_src );
	//	//set the 'length' of the in_width-1 sub matrix, ie, the rotation component
	//	static HVOID RotationLengthSet( TMatrix& in_out_src, const IN_TYPE in_length );

	//	static const TMatrixMinor MinorMatrixGet( 
	//		const TMatrix& in_src,
	//		const HSINT in_ignoreRow,
	//		const HSINT in_ignoreColumn
	//		);

	//	//////////////////////////////////////////////////////////////
	//	// disabled
	//private:
	//	~HMatrixUtilitySquare();
	//};

};

#endif // _H_MATRIX_UTILITY_SQUARE_H_