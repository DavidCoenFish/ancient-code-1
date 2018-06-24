//file: Hubris/HMatrix/HMatrixTrait.h
#ifndef _H_MATRIX_TRAIT_H_
#define _H_MATRIX_TRAIT_H_

//#include "Hubris/HTrait/HTraitStringOut.h"
#include "Hubris/HTrait/HTraitEmpty.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HCommon/HCommonType.h"

namespace Hubris
{
	/////////////////////////////////////////////////////////////////
	// forward definitions
	/**/
	class HBuffer;

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

	typedef HMatrix< HREAL, 1, 1 >HVectorR1;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 2, 2 >HMatrixR2;
	typedef HMatrix< HREAL, 3, 3 >HMatrixR3;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;
	typedef HMatrix< HREAL, 5, 5 >HMatrixR5;
	class HString;

	/////////////////////////////////////////////////////////////////
	// global HTraitStringIn
	/**/
	template< typename IN_TYPE >HString HTraitStringIn( const IN_TYPE& in_data );

	template HString HTraitStringIn( const HVectorS2& in_data );
	template HString HTraitStringIn( const HVectorS3& in_data );
	template HString HTraitStringIn( const HVectorS4& in_data );
	template HString HTraitStringIn( const HMatrixS2& in_data );
	template HString HTraitStringIn( const HMatrixS3& in_data );
	template HString HTraitStringIn( const HMatrixS4& in_data );

	template HString HTraitStringIn( const HVectorR2& in_data );
	template HString HTraitStringIn( const HVectorR3& in_data );
	template HString HTraitStringIn( const HVectorR4& in_data );
	template HString HTraitStringIn( const HMatrixR2& in_data );
	template HString HTraitStringIn( const HMatrixR3& in_data );
	template HString HTraitStringIn( const HMatrixR4& in_data );

	/////////////////////////////////////////////////////////////////
	// global HTraitStringOut
	/**/
	template< typename IN_TYPE >HVOID HTraitStringOut( IN_TYPE& out_value, const HString& in_string );

	template HVOID HTraitStringOut( HVectorS2& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HVectorS3& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HVectorS4& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixS2& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixS3& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixS4& out_value, const HString& in_data );
											  
	template HVOID HTraitStringOut( HVectorR2& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HVectorR3& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HVectorR4& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixR2& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixR3& out_value, const HString& in_data );
	template HVOID HTraitStringOut( HMatrixR4& out_value, const HString& in_data );

	/////////////////////////////////////////////////////////////////
	// global HTraitBufferInAppend
	/**/
	template< typename IN_TYPE >void HTraitBufferInAppend( HBuffer& in_out_buffer, const IN_TYPE& in_value );

	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorU2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorU3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorU4& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixU2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixU3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixU4& in_value );

	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorS2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorS3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorS4& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixS2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixS3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixS4& in_value );

	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorR2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorR3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HVectorR4& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixR2& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixR3& in_value );
	template HVOID HTraitBufferInAppend( HBuffer& in_out_buffer, const HMatrixR4& in_value );

	/////////////////////////////////////////////////////////////////
	// global HTraitBufferInReplace
	/**/
	template< typename IN_TYPE >HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const IN_TYPE& in_value, const HSINT in_offset );

	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorU2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorU3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorU4& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixU2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixU3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixU4& in_value, const HSINT in_offset );

	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorS2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorS3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorS4& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixS2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixS3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixS4& in_value, const HSINT in_offset );

	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorR2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorR3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HVectorR4& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixR2& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixR3& in_value, const HSINT in_offset );
	template HSINT HTraitBufferInReplace( HBuffer& in_out_buffer, const HMatrixR4& in_value, const HSINT in_offset );

	/////////////////////////////////////////////////////////////////
	// global HTraitBufferOutGet
	/**/
	template< typename IN_TYPE >HVOID HTraitBufferOutGet( IN_TYPE& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

	template HVOID HTraitBufferOutGet( HVectorU2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorU3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorU4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixU2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixU3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixU4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

	template HVOID HTraitBufferOutGet( HVectorS2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorS3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorS4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixS2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixS3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixS4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
															
	template HVOID HTraitBufferOutGet( HVectorR2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorR3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HVectorR4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixR2& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixR3& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );
	template HVOID HTraitBufferOutGet( HMatrixR4& out_value, HSINT& in_out_offset, const HBuffer& in_buffer );

	/**/
	/////////////////////////////////////////////////////////
	// type name variant
	/*
		while tempting to have templated functions for the following in header, try to move code into cpp,
		ie. 
	*/
	template< typename IN_TYPE >struct HTraitName;										 

#define HMATRIX_TRAIT_NAME( IN_TYPE )			\
	template<>									\
	struct HTraitName< IN_TYPE >				\
	{											\
		static const HCHAR* const NameGet();	\
	};	

	/**/
	HMATRIX_TRAIT_NAME( HVectorS2 );
	HMATRIX_TRAIT_NAME( HVectorS3 );
	HMATRIX_TRAIT_NAME( HVectorS4 );
	HMATRIX_TRAIT_NAME( HMatrixS2 );
	HMATRIX_TRAIT_NAME( HMatrixS3 );
	HMATRIX_TRAIT_NAME( HMatrixS4 );

	/**/
	HMATRIX_TRAIT_NAME( HVectorR2 );
	HMATRIX_TRAIT_NAME( HVectorR3 );
	HMATRIX_TRAIT_NAME( HVectorR4 );
	HMATRIX_TRAIT_NAME( HMatrixR2 );
	HMATRIX_TRAIT_NAME( HMatrixR3 );
	HMATRIX_TRAIT_NAME( HMatrixR4 );

#undef HMATRIX_TRAIT_NAME

	//template< typename IN_TYPE >struct HTraitName;										 

	///**/
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >							
	//struct HTraitName< HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > >					
	//{
	//	static const HString NameGet();
	//private:			
	//	~HTraitName();								
	//};	

	///**/
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >										
	//const HString HTraitName< HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > >::NameGet(){ return( HString( "HMatrix_" ) + HTraitStringOut< HSINT >( IN_WIDTH ) + "_" + HTraitStringOut< HSINT >( IN_HEIGHT ) ); }

	/////////////////////////////////////////////////////////
	// empty 
	HTRAIT_EMPTY_HEADER( HVectorS2 );
	HTRAIT_EMPTY_HEADER( HVectorS3 );
	HTRAIT_EMPTY_HEADER( HVectorS4 );
	HTRAIT_EMPTY_HEADER( HMatrixS2 );
	HTRAIT_EMPTY_HEADER( HMatrixS3 );
	HTRAIT_EMPTY_HEADER( HMatrixS4 );

	/**/
	HTRAIT_EMPTY_HEADER( HVectorR2 );
	HTRAIT_EMPTY_HEADER( HVectorR3 );
	HTRAIT_EMPTY_HEADER( HVectorR4 );
	HTRAIT_EMPTY_HEADER( HMatrixR2 );
	HTRAIT_EMPTY_HEADER( HMatrixR3 );
	HTRAIT_EMPTY_HEADER( HMatrixR4 );

	//template< typename IN_TYPE >struct HTraitEmpty;										 

	///**/
	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >										
	//struct HTraitEmpty< HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > >					
	//{
	//	static const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& EmptyGet();
	//private:			
	//	~HTraitEmpty();								
	//};	

	//template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT >
	//const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& HTraitEmpty< HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT > >::EmptyGet(){ static const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >s_data; return s_data; }

};

#endif // _H_MATRIX_TRAIT_H_