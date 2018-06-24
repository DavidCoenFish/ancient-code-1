//file: Hubris/HTrait/HTraitEmpty.h
#ifndef _H_TRAIT_EMPTY_H_
#define _H_TRAIT_EMPTY_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	/**/
	//template< typename IN_TYPE >const IN_TYPE& HTraitEmpty();

	//template const HU8& HTraitEmpty();
	//template const HS8& HTraitEmpty();
	//template const HU16& HTraitEmpty();
	//template const HS16& HTraitEmpty();
	//template const HU32& HTraitEmpty();
	//template const HS32& HTraitEmpty();
	//template const HR32& HTraitEmpty();
	//template const HR64& HTraitEmpty();
	//template const HCHAR& HTraitEmpty();
	//template const HBOOL& HTraitEmpty();
	//template const HVOID*& HTraitEmpty();

	/**/
};

#define HTRAIT_EMPTY_HEADER_POINTER( IN_CLASS )		\
	template<>										\
	struct Hubris::HTraitEmpty< IN_CLASS* >			\
	{												\
		static IN_CLASS* EmptyGet();				\
	private:										\
		~HTraitEmpty();								\
	};										

#define HTRAIT_EMPTY_HEADER( IN_CLASS )		\
	template<>								\
	struct Hubris::HTraitEmpty< IN_CLASS >			\
	{										\
		static const IN_CLASS& EmptyGet();	\
	private:								\
		~HTraitEmpty();						\
	};										\
	template<>								\
	struct Hubris::HTraitEmpty< IN_CLASS* >			\
	{										\
		static IN_CLASS* EmptyGet();		\
	private:								\
		~HTraitEmpty();						\
	};										

#define HTRAIT_EMPTY_IMPLEMENTATION_POINTER( IN_CLASS )							\
	IN_CLASS* Hubris::HTraitEmpty< IN_CLASS* >::EmptyGet() { return HNULL; }		

#define HTRAIT_EMPTY_IMPLEMENTATION_ZERO( IN_CLASS )								\
	const IN_CLASS& Hubris::HTraitEmpty< IN_CLASS >::EmptyGet() { static const IN_CLASS s_default = 0; return s_default; }				\
	IN_CLASS* Hubris::HTraitEmpty< IN_CLASS* >::EmptyGet() { return HNULL; }		

#define HTRAIT_EMPTY_IMPLEMENTATION_CONSTRUCTOR( IN_CLASS )						\
	const IN_CLASS& Hubris::HTraitEmpty< IN_CLASS >::EmptyGet() { static const IN_CLASS s_default; return s_default; } 	\
	IN_CLASS* Hubris::HTraitEmpty< IN_CLASS* >::EmptyGet() { return HNULL; } 


/**/
namespace Hubris
{
	///////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE >struct HTraitEmpty;

	//template< typename IN_TYPE > class HContainerArray;
	//template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;
	//template< typename IN_TYPE >struct HContainerLess;
	//template< typename IN_KEY, typename IN_DATA, typename IN_SORT = HContainerLess< IN_KEY > >class HContainerTree;

	//class HTypeNone;
	//template< class IN_CLASS_A, class IN_CLASS_B >class HTypeList;

	//template< class IN_TYPE_LIST >class HVariantImplementation;

	/**/

	/////////////////////////////////////////////////////////
	// type name base
	/**/
	HTRAIT_EMPTY_HEADER( HU8 );
	HTRAIT_EMPTY_HEADER( HS8 );
	HTRAIT_EMPTY_HEADER( HU16 );
	HTRAIT_EMPTY_HEADER( HS16 );
	HTRAIT_EMPTY_HEADER( HU32 );
	HTRAIT_EMPTY_HEADER( HS32 );
	HTRAIT_EMPTY_HEADER( HR32 );
	HTRAIT_EMPTY_HEADER( HR64 );
	HTRAIT_EMPTY_HEADER( HCHAR );
	HTRAIT_EMPTY_HEADER( HBOOL );
	HTRAIT_EMPTY_HEADER( HVOID* );

	/////////////////////////////////////////////////////////
	// HBuffer
	/**/
	//HTRAIT_EMPTY_HEADER( HBuffer );

	/////////////////////////////////////////////////////////
	// type name none
	/**/
	//HTRAIT_EMPTY_HEADER( HTypeNone );

	/////////////////////////////////////////////////////////
	// type name HString
	/**/
	//HTRAIT_EMPTY_HEADER( HString );

	///////////////////////////////////////////////////////////
	//// empty HContainer Array
	///**/
	//template< typename IN_TYPE >										
	//struct HTraitEmpty< HContainerArray< IN_TYPE > >					
	//{
	//	static const HContainerArray< IN_TYPE >& EmptyGet();
	//private:			
	//	~HTraitEmpty();								
	//};	

	//template< typename IN_TYPE >
	//const HContainerArray< IN_TYPE >& HTraitEmpty< HContainerArray< IN_TYPE > >::EmptyGet(){ static const HContainerArray< IN_TYPE > s_data; return s_data; }

	///////////////////////////////////////////////////////////
	//// empty HContainer Pair
	///**/
	//template< typename IN_FIRST, typename IN_SECOND >										
	//struct HTraitEmpty< HContainerPair< IN_FIRST, IN_SECOND > >					
	//{
	//	static const HContainerPair< IN_FIRST, IN_SECOND >& EmptyGet();
	//private:			
	//	~HTraitEmpty();								
	//};	

	//template< typename IN_FIRST, typename IN_SECOND >
	//const HContainerPair< IN_FIRST, IN_SECOND >& HTraitEmpty< HContainerPair< IN_FIRST, IN_SECOND > >::EmptyGet(){ static const HContainerPair< IN_FIRST, IN_SECOND > s_data; return s_data; }

	///////////////////////////////////////////////////////////
	//// empty matrix
	///**/
	//HTRAIT_EMPTY_HEADER( HVectorS2 );
	//HTRAIT_EMPTY_HEADER( HVectorS3 );
	//HTRAIT_EMPTY_HEADER( HVectorS4 );
	//HTRAIT_EMPTY_HEADER( HMatrixS2 );
	//HTRAIT_EMPTY_HEADER( HMatrixS3 );
	//HTRAIT_EMPTY_HEADER( HMatrixS4 );

	///**/
	//HTRAIT_EMPTY_HEADER( HVectorR2 );
	//HTRAIT_EMPTY_HEADER( HVectorR3 );
	//HTRAIT_EMPTY_HEADER( HVectorR4 );
	//HTRAIT_EMPTY_HEADER( HMatrixR2 );
	//HTRAIT_EMPTY_HEADER( HMatrixR3 );
	//HTRAIT_EMPTY_HEADER( HMatrixR4 );

	///////////////////////////////////////////////////////////
	//// empty filesystem
	///**/
	//HTRAIT_EMPTY_HEADER( HFileSystemPath );

	/**/
};

/**/
#endif // _H_TRAIT_EMPTY_H_

