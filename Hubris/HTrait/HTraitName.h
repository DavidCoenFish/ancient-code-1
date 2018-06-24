//file: Hubris/HTrait/HTraitName.h
#ifndef _H_TRAIT_NAME_H_
#define _H_TRAIT_NAME_H_

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonType.h"

//#include "Hubris/HString/HString.h"
//#include "Hubris/HString/HStringOperators.h"
//#include "Hubris/HContainer/HContainerArray.h"

#define HTYPE_NAME_HEADER( IN_TYPE )		\
	template<>									\
	struct Hubris::HTraitName< IN_TYPE >			\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< IN_TYPE* >			\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< IN_TYPE& >			\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< const IN_TYPE >		\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< const IN_TYPE* >		\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< const IN_TYPE& >		\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< const IN_TYPE* const>\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\
	template<>									\
	struct Hubris::HTraitName< IN_TYPE* const>		\
	{											\
		static const Hubris::HCHAR* const NameGet();	\
	};											\

#define HTYPE_NAME_IMPLEMENTATION( IN_TYPE )																							\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE >::NameGet(){ return HCOMMON_TOKEN( IN_TYPE ); }								\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE* >::NameGet(){ return HCOMMON_TOKEN_TOKEN( P, IN_TYPE ); }					\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE& >::NameGet(){ return HCOMMON_TOKEN_TOKEN( R, IN_TYPE ); }					\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE >::NameGet(){ return HCOMMON_TOKEN_TOKEN( C, IN_TYPE ); }				\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE* >::NameGet(){ return HCOMMON_TOKEN_TOKEN( CP, IN_TYPE ); }			\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE& >::NameGet(){ return HCOMMON_TOKEN_TOKEN( CR, IN_TYPE ); }			\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE* const >::NameGet(){ return HCOMMON_TOKEN_TOKEN( CPC, IN_TYPE ); }		\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE* const >::NameGet(){ return HCOMMON_TOKEN_TOKEN( PC, IN_TYPE ); }			

#define HTYPE_NAME_NAME_IMPLEMENTATION( IN_PREPEND, IN_TYPE )																							\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE >::NameGet(){ return HCOMMON_TOKEN_TOKEN( IN_PREPEND, IN_TYPE ); }							\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE* >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, P, IN_TYPE ); }					\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE& >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, R, IN_TYPE );	}				\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, C, IN_TYPE ); }			\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE* >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, CP, IN_TYPE ); }	 		\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE& >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, CR, IN_TYPE ); }			\
	const Hubris::HCHAR* const Hubris::HTraitName< const IN_TYPE* const >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, CPC, IN_TYPE ); }	\
	const Hubris::HCHAR* const Hubris::HTraitName< IN_TYPE* const >::NameGet(){ return HCOMMON_TOKEN_TOKEN_TOKEN( IN_PREPEND, PC, IN_TYPE ); }			


/**/
namespace Hubris
{
	///////////////////////////////////////////////
	// forward declarations
	/**/
	class HString;
	class HTypeNone;

	/**/
	template< typename IN_TYPE >struct HTraitName;										 

	/////////////////////////////////////////////////////////
	// type name base
	/**/

	HTYPE_NAME_HEADER( HU8 );
	HTYPE_NAME_HEADER( HS8 );
	HTYPE_NAME_HEADER( HU16 );
	HTYPE_NAME_HEADER( HS16 );
	HTYPE_NAME_HEADER( HU32 );
	HTYPE_NAME_HEADER( HS32 );
	HTYPE_NAME_HEADER( HR32 );
	HTYPE_NAME_HEADER( HR64 );
	HTYPE_NAME_HEADER( HCHAR );
	HTYPE_NAME_HEADER( HBOOL );
	HTYPE_NAME_HEADER( HVOID* );

	/////////////////////////////////////////////////////////
	// type name none
	/**/
	//HTYPE_NAME_HEADER( HTypeNone );

	/////////////////////////////////////////////////////////
	// type name HContainer Array
	/**/
//	template< typename IN_TYPE >										
//	struct HTraitName< HContainerArray< IN_TYPE > >					
//	{
//		static HString NameGet();
//	private:			
//		~HTraitName();								
//	};	
//
//	template< typename IN_TYPE >										
//	HString HTraitName< HContainerArray< IN_TYPE > >::NameGet(){ return HString( HTraitName< IN_TYPE >::NameGet() ) + "_ARRAY"; }
//
//	/////////////////////////////////////////////////////////
//	// type name HContainer Pair
//	/**/
//	template< typename IN_FIRST, typename IN_SECOND >										
//	struct HTraitName< HContainerPair< IN_FIRST, IN_SECOND > >					
//	{
//		static HString NameGet();
//	private:			
//		~HTraitName();								
//	};	
//
//	template< typename IN_FIRST, typename IN_SECOND >										
//	HString HTraitName< HContainerPair< IN_FIRST, IN_SECOND > >::NameGet(){ return HString( HTraitName< IN_FIRST >::NameGet() ) + HString( HTraitName< IN_SECOND >::NameGet() ) + "_PAIR"; }
//
//	/////////////////////////////////////////////////////////
//	// type name HMatrix
//	/**/
//#define HMATRIX_TRAIT_NAME( IN_TYPE )			\
//	template<>									\
//	struct HTraitName< IN_TYPE >			\
//	{											\
//		static const HCHAR* const NameGet();	\
//	};	
//
//	/**/
//	HMATRIX_TRAIT_NAME( HVectorS2 );
//	HMATRIX_TRAIT_NAME( HVectorS3 );
//	HMATRIX_TRAIT_NAME( HVectorS4 );
//	HMATRIX_TRAIT_NAME( HMatrixS2 );
//	HMATRIX_TRAIT_NAME( HMatrixS3 );
//	HMATRIX_TRAIT_NAME( HMatrixS4 );
//
//	/**/
//	HMATRIX_TRAIT_NAME( HVectorR2 );
//	HMATRIX_TRAIT_NAME( HVectorR3 );
//	HMATRIX_TRAIT_NAME( HVectorR4 );
//	HMATRIX_TRAIT_NAME( HMatrixR2 );
//	HMATRIX_TRAIT_NAME( HMatrixR3 );
//	HMATRIX_TRAIT_NAME( HMatrixR4 );
//
//#undef HMATRIX_TRAIT_NAME
//
//	/////////////////////////////////////////////////////////
//	// type name typelist
//
//	/**/
//	template< class IN_CLASS_A, class IN_CLASS_B >										
//	struct HTraitName< HTypeList< IN_CLASS_A, IN_CLASS_B > >					
//	{
//		static HString NameGet();
//	private:			
//		~HTraitName();								
//	};	
//
//	template< class IN_CLASS_A, class IN_CLASS_B >										
//	HString HTraitName< HTypeList< IN_CLASS_A, IN_CLASS_B > >::NameGet(){ return HTraitName< IN_CLASS_B >::NameGet() + HString( "_" ) + HTraitName< IN_CLASS_A >::NameGet(); }
//
//	/**/
//	template< class IN_CLASS_A >										
//	struct HTraitName< HTypeList< IN_CLASS_A, HTypeNone > >					
//	{
//		static HString NameGet();
//	private:			
//		~HTraitName();								
//	};	
//
//	template< class IN_CLASS_A >										
//	HString HTraitName< HTypeList< IN_CLASS_A, HTypeNone > >::NameGet(){ return HString( "TYPELIST_" ) + HTraitName< IN_CLASS_A >::NameGet(); }
//
//	/////////////////////////////////////////////////////////
//	// type name variant
//
//	/**/
//	template< typename IN_TYPE_LIST >										
//	struct HTraitName< HVariantImplementation< IN_TYPE_LIST > >					
//	{
//		static HString NameGet();
//	private:			
//		~HTraitName();								
//	};	
//
//	//template< typename IN_TYPE >										
//	//struct HTraitName< IN_TYPE >					
//	//{
//	//	static HString NameGet();
//	//private:			
//	//	~HTraitName();								
//	//};	
//
//	/**/
//	//template< typename IN_TYPE >										
//	//HString HTraitName< typename IN_TYPE::TVariantImplementation >::NameGet(){ return HTraitName< IN_TYPE::TVariantImplementation >::NameGet(); }
//
//	template< typename IN_TYPE_LIST >										
//	HString HTraitName< HVariantImplementation< IN_TYPE_LIST > >::NameGet(){ return HString( HTraitName< IN_TYPE_LIST >::NameGet() ) + "_VARIANT"; }
//
//	/**/

};

/**/
#endif // _H_TRAIT_NAME_H_

