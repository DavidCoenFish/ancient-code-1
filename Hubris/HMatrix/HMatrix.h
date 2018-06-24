//file: Hubris/HMatrix/HMatrix.h
#ifndef _H_MATRIX_H_
#define _H_MATRIX_H_

#include "Hubris/HCommon/HCommonType.h"
//#include "Hubris/HCommon/HCommonAssert.h"

namespace Hubris
{
	//see HMatrixOperator for operators other than assignment or subscript
	//see HMatrixUtility for functions on matrix, like dot, normalise, transpose

	////////////////////////////////////////////////////
	// typedef, predefines

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;

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
	typedef HMatrix< HSINT, 5, 5 >HMatrixS5;

	typedef HMatrix< HREAL, 1, 1 >HVectorR1;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 2, 2 >HMatrixR2;
	typedef HMatrix< HREAL, 3, 3 >HMatrixR3;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;
	typedef HMatrix< HREAL, 5, 5 >HMatrixR5;

	////////////////////////////////////////////////////
	// class
	/*
		general matrix class, for matrix, vector. 
		considered as a data holder, manipulation is done elsewhere
		making assumption the copy operator on IN_TYPE is not prohibitive ( or at least acceptable )
	*/
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >class HMatrix
	{
		//HCOMMON_ASSERT_STATIC( ( ( 0 < IN_WIDTH ) && ( 0 < IN_HEIGHT ) ), width_and_height_must_be_greater_than_zero )

		////////////////////////////////////////////////////
		// typedef
	private:
		typedef HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >TMatrix;
	public:
		typedef IN_TYPE TType; //so something using matrix by type can be aware of what the intype was for matrix
		struct TVar
		{
			enum TEnum
			{
				TWidth = IN_WIDTH,
				THeight = IN_HEIGHT,
				TSize = IN_WIDTH * IN_HEIGHT
			};
		};
	
		////////////////////////////////////////////////////
		// creation
	public:
		HMatrix( const TMatrix& in_src );
		HMatrix( const IN_TYPE* const in_data );
		explicit HMatrix( const IN_TYPE in_default = 0 );
		//non virtual destructor, do not inherit ( contain or typedef instead, like for colour or quaternion )
		~HMatrix();

		////////////////////////////////////////////////////
		// operators, for the rest, see HMatrixOperator
	public:
		//assignment operators
		const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator=( const TMatrix& in_src );
		const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& operator=( const IN_TYPE in_value );

		////////////////////////////////////////////////////
		// public accessors
	public:
		const IN_TYPE* const DataGet()const;
		//set the data of a matrix from an array, ASSUMES size is correct
		HVOID DataSet( const IN_TYPE* const in_data );
		//set the data of a matrix from a value
		HVOID DataSet( const IN_TYPE in_data );

		//subscript const operator, assert on out of range
		const IN_TYPE operator[]( HSINT in_index )const;
		//subscript const operator, assert on out of range
		IN_TYPE& operator[]( HSINT in_index );

		////////////////////////////////////////////////////
		// public static methods
	public:
		//get the index from a x ( width ) and y ( height )
		static HSINT IndexGet( const HSINT in_x, const HSINT in_y );

		////////////////////////////////////////////////////
		// private members
	private:
		//the matrix data
		IN_TYPE m_data[ TVar::TSize ];

	};

	/**/

};

#endif // _H_MATRIX_H_