//file: Hubris/HVariant/HVariantUtility.h
#ifndef _H_VARIANT_UTILITY_H_
#define _H_VARIANT_UTILITY_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HTrait/HTraitName.h"
#include "Hubris/HContainer/HContainerTree.h"
#include "Hubris/HContainer/HContainerLess.h"

/**/
namespace Hubris
{
	/**/
	class HString;

	/*
		attempt to get from on variant type1 to another variant type2
		lhs is assigned value from rhs
	*/
	struct HVariantUtility
	{
		/////////////////////////////////////////////////////////
		// disabled
	private:
		~HVariantUtility();

		/////////////////////////////////////////////////////////
		// public static methods
	public:
		template< typename IN_VARIANT_LHS, typename IN_VARIANT_RHS > 
		static HVOID Convertor( IN_VARIANT_LHS& out_lhs, const IN_VARIANT_RHS& in_rhs );

		template< typename IN_VARIANT_LHS > 
		static const HSINT TypeIndexFromName( const HString& in_name );

		template< typename IN_VARIANT > 
		static const HString TypeNameFromVariant( const IN_VARIANT& in_variant );

		/////////////////////////////////////////////////////////
		// private static methods
	private:
		template< typename IN_VARIANT_LHS, typename IN_VARIANT_RHS, HSINT IN_RHS_TYPE_INDEX > 
		static HVOID ConvertorIndex( IN_VARIANT_LHS& out_lhs, const IN_VARIANT_RHS& in_rhs );

		//template< HSINT IN_INDEX, typename IN_VARIANT > 
		//static HBOOL TypeIndexFromNameIndex( HSINT& in_out_index, const HString& in_name );

	};

	/**/
	template< typename IN_VARIANT_LHS, typename IN_TYPE, HBOOL IN_RESULT >
	struct HVariantUtilityConvertorHelper
	{
		static HVOID Invoke( IN_VARIANT_LHS& out_lhs, const IN_TYPE& in_rhs );
	};

	template< typename IN_VARIANT_LHS, typename IN_TYPE >
	struct HVariantUtilityConvertorHelper< IN_VARIANT_LHS, IN_TYPE, HTRUE >
	{
		static HVOID Invoke( IN_VARIANT_LHS& out_lhs, const IN_TYPE& in_rhs );
	};
	//
	template< typename IN_VARIANT_LHS, typename IN_TYPE >
	HVOID HVariantUtilityConvertorHelper< IN_VARIANT_LHS, IN_TYPE, HTRUE >::Invoke( IN_VARIANT_LHS& out_lhs, const IN_TYPE& in_rhs )
	{
		out_lhs.ValueSet< IN_TYPE >( in_rhs );
		return;
	}
	//
	template< typename IN_VARIANT_LHS, typename IN_TYPE >
	struct HVariantUtilityConvertorHelper< IN_VARIANT_LHS, IN_TYPE, HFALSE >
	{
		static HVOID Invoke( IN_VARIANT_LHS& out_lhs, const IN_TYPE& in_rhs );
	};
	//
	template< typename IN_VARIANT_LHS, typename IN_TYPE >
	HVOID HVariantUtilityConvertorHelper< IN_VARIANT_LHS, IN_TYPE, HFALSE >::Invoke( IN_VARIANT_LHS&, const IN_TYPE& )
	{
		return;
	}


	/////////////////////////////////////////////////////////
	// public methods
	/**/
	template< typename IN_VARIANT_LHS, typename IN_VARIANT_RHS > 
	HVOID HVariantUtility::Convertor( IN_VARIANT_LHS& out_lhs, const IN_VARIANT_RHS& in_rhs )
	{
		out_lhs = IN_VARIANT_LHS();

		const HSINT index = in_rhs.TypeIndexGet();

		switch( index )
		{
		default:
			{
				break;
			}
		case  0: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  0 >( out_lhs, in_rhs ); break; }
		case  1: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  1 >( out_lhs, in_rhs ); break; }
		case  2: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  2 >( out_lhs, in_rhs ); break; }
		case  3: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  3 >( out_lhs, in_rhs ); break; }
		case  4: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  4 >( out_lhs, in_rhs ); break; }
		case  5: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  5 >( out_lhs, in_rhs ); break; }
		case  6: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  6 >( out_lhs, in_rhs ); break; }
		case  7: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  7 >( out_lhs, in_rhs ); break; }
		case  8: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  8 >( out_lhs, in_rhs ); break; }
		case  9: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS,  9 >( out_lhs, in_rhs ); break; }
		case 10: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 10 >( out_lhs, in_rhs ); break; }
		case 11: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 11 >( out_lhs, in_rhs ); break; }
		case 12: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 12 >( out_lhs, in_rhs ); break; }
		case 13: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 13 >( out_lhs, in_rhs ); break; }
		case 14: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 14 >( out_lhs, in_rhs ); break; }
		case 15: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 15 >( out_lhs, in_rhs ); break; }
		case 16: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 16 >( out_lhs, in_rhs ); break; }
		case 17: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 17 >( out_lhs, in_rhs ); break; }
		case 18: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 18 >( out_lhs, in_rhs ); break; }
		case 19: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 19 >( out_lhs, in_rhs ); break; }
		case 20: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 20 >( out_lhs, in_rhs ); break; }
		case 21: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 21 >( out_lhs, in_rhs ); break; }
		case 22: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 22 >( out_lhs, in_rhs ); break; }
		case 23: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 23 >( out_lhs, in_rhs ); break; }
		case 24: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 24 >( out_lhs, in_rhs ); break; }
		case 25: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 25 >( out_lhs, in_rhs ); break; }
		case 26: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 26 >( out_lhs, in_rhs ); break; }
		case 27: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 27 >( out_lhs, in_rhs ); break; }
		case 28: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 28 >( out_lhs, in_rhs ); break; }
		case 29: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 29 >( out_lhs, in_rhs ); break; }
		case 30: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 30 >( out_lhs, in_rhs ); break; }
		case 31: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 31 >( out_lhs, in_rhs ); break; }
		case 32: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 32 >( out_lhs, in_rhs ); break; }
		case 33: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 33 >( out_lhs, in_rhs ); break; }
		case 34: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 34 >( out_lhs, in_rhs ); break; }
		case 35: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 35 >( out_lhs, in_rhs ); break; }
		case 36: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 36 >( out_lhs, in_rhs ); break; }
		case 37: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 37 >( out_lhs, in_rhs ); break; }
		case 38: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 38 >( out_lhs, in_rhs ); break; }
		case 39: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 39 >( out_lhs, in_rhs ); break; }
		case 40: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 40 >( out_lhs, in_rhs ); break; }
		case 41: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 41 >( out_lhs, in_rhs ); break; }
		case 42: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 42 >( out_lhs, in_rhs ); break; }
		case 43: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 43 >( out_lhs, in_rhs ); break; }
		case 44: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 44 >( out_lhs, in_rhs ); break; }
		case 45: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 45 >( out_lhs, in_rhs ); break; }
		case 46: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 46 >( out_lhs, in_rhs ); break; }
		case 47: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 47 >( out_lhs, in_rhs ); break; }
		case 48: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 48 >( out_lhs, in_rhs ); break; }
		case 49: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 49 >( out_lhs, in_rhs ); break; }
		case 50: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 50 >( out_lhs, in_rhs ); break; }
		case 51: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 51 >( out_lhs, in_rhs ); break; }
		case 52: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 52 >( out_lhs, in_rhs ); break; }
		case 53: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 53 >( out_lhs, in_rhs ); break; }
		case 54: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 54 >( out_lhs, in_rhs ); break; }
		case 55: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 55 >( out_lhs, in_rhs ); break; }
		case 56: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 56 >( out_lhs, in_rhs ); break; }
		case 57: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 57 >( out_lhs, in_rhs ); break; }
		case 58: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 58 >( out_lhs, in_rhs ); break; }
		case 59: { ConvertorIndex< IN_VARIANT_LHS, IN_VARIANT_RHS, 59 >( out_lhs, in_rhs ); break; }
		}
	};

	/**/
	template< typename IN_VARIANT > 
	const HSINT HVariantUtility::TypeIndexFromName( const HString& in_name )
	{	
		//TODO: convert to tree
		typedef HContainerTree< HString, HSINT >TTreeStringSint;
		static TTreeStringSint s_data;
		if( 0 == s_data.SizeGet() )
		{
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  0 >::Type >::NameGet(),  0 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  1 >::Type >::NameGet(),  1 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  2 >::Type >::NameGet(),  2 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  3 >::Type >::NameGet(),  3 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  4 >::Type >::NameGet(),  4 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  5 >::Type >::NameGet(),  5 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  6 >::Type >::NameGet(),  6 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  7 >::Type >::NameGet(),  7 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  8 >::Type >::NameGet(),  8 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  9 >::Type >::NameGet(),  9 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 10 >::Type >::NameGet(), 10 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 11 >::Type >::NameGet(), 11 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 12 >::Type >::NameGet(), 12 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 13 >::Type >::NameGet(), 13 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 14 >::Type >::NameGet(), 14 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 15 >::Type >::NameGet(), 15 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 16 >::Type >::NameGet(), 16 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 17 >::Type >::NameGet(), 17 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 18 >::Type >::NameGet(), 18 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 19 >::Type >::NameGet(), 19 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 20 >::Type >::NameGet(), 20 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 21 >::Type >::NameGet(), 21 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 22 >::Type >::NameGet(), 22 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 23 >::Type >::NameGet(), 23 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 24 >::Type >::NameGet(), 24 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 25 >::Type >::NameGet(), 25 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 26 >::Type >::NameGet(), 26 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 27 >::Type >::NameGet(), 27 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 28 >::Type >::NameGet(), 28 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 29 >::Type >::NameGet(), 29 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 30 >::Type >::NameGet(), 30 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 31 >::Type >::NameGet(), 31 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 32 >::Type >::NameGet(), 32 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 33 >::Type >::NameGet(), 33 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 34 >::Type >::NameGet(), 34 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 35 >::Type >::NameGet(), 35 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 36 >::Type >::NameGet(), 36 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 37 >::Type >::NameGet(), 37 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 38 >::Type >::NameGet(), 38 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 39 >::Type >::NameGet(), 39 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 40 >::Type >::NameGet(), 40 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 41 >::Type >::NameGet(), 41 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 42 >::Type >::NameGet(), 42 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 43 >::Type >::NameGet(), 43 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 44 >::Type >::NameGet(), 44 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 45 >::Type >::NameGet(), 45 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 46 >::Type >::NameGet(), 46 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 47 >::Type >::NameGet(), 47 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 48 >::Type >::NameGet(), 48 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 49 >::Type >::NameGet(), 49 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 50 >::Type >::NameGet(), 50 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 51 >::Type >::NameGet(), 51 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 52 >::Type >::NameGet(), 52 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 53 >::Type >::NameGet(), 53 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 54 >::Type >::NameGet(), 54 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 55 >::Type >::NameGet(), 55 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 56 >::Type >::NameGet(), 56 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 57 >::Type >::NameGet(), 57 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 58 >::Type >::NameGet(), 58 );
			s_data.Insert( HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 59 >::Type >::NameGet(), 59 );
		}

		const TTreeStringSint::TIterator iterator = s_data.Find( in_name );
		if( iterator != s_data.End() )
		{
			return( *iterator );
		}

		return HCOMMON_INVALID_INDEX;
	}

	/**/
	template< typename IN_VARIANT > 
	const HString HVariantUtility::TypeNameFromVariant( const IN_VARIANT& in_variant )
	{
		const HSINT index = in_variant.TypeIndexGet();

		switch( index )
		{
		default:
			{
				break;
			}
		case  0: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  0 >::Type >::NameGet(); }
		case  1: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  1 >::Type >::NameGet(); }
		case  2: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  2 >::Type >::NameGet(); }
		case  3: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  3 >::Type >::NameGet(); }
		case  4: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  4 >::Type >::NameGet(); }
		case  5: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  5 >::Type >::NameGet(); }
		case  6: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  6 >::Type >::NameGet(); }
		case  7: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  7 >::Type >::NameGet(); }
		case  8: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  8 >::Type >::NameGet(); }
		case  9: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList,  9 >::Type >::NameGet(); }
		case 10: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 10 >::Type >::NameGet(); }
		case 11: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 11 >::Type >::NameGet(); }
		case 12: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 12 >::Type >::NameGet(); }
		case 13: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 13 >::Type >::NameGet(); }
		case 14: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 14 >::Type >::NameGet(); }
		case 15: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 15 >::Type >::NameGet(); }
		case 16: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 16 >::Type >::NameGet(); }
		case 17: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 17 >::Type >::NameGet(); }
		case 18: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 18 >::Type >::NameGet(); }
		case 19: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 19 >::Type >::NameGet(); }
		case 20: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 20 >::Type >::NameGet(); }
		case 21: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 21 >::Type >::NameGet(); }
		case 22: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 22 >::Type >::NameGet(); }
		case 23: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 23 >::Type >::NameGet(); }
		case 24: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 24 >::Type >::NameGet(); }
		case 25: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 25 >::Type >::NameGet(); }
		case 26: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 26 >::Type >::NameGet(); }
		case 27: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 27 >::Type >::NameGet(); }
		case 28: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 28 >::Type >::NameGet(); }
		case 29: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 29 >::Type >::NameGet(); }
		case 30: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 30 >::Type >::NameGet(); }
		case 31: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 31 >::Type >::NameGet(); }
		case 32: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 32 >::Type >::NameGet(); }
		case 33: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 33 >::Type >::NameGet(); }
		case 34: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 34 >::Type >::NameGet(); }
		case 35: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 35 >::Type >::NameGet(); }
		case 36: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 36 >::Type >::NameGet(); }
		case 37: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 37 >::Type >::NameGet(); }
		case 38: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 38 >::Type >::NameGet(); }
		case 39: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 39 >::Type >::NameGet(); }
		case 40: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 40 >::Type >::NameGet(); }
		case 41: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 41 >::Type >::NameGet(); }
		case 42: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 42 >::Type >::NameGet(); }
		case 43: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 43 >::Type >::NameGet(); }
		case 44: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 44 >::Type >::NameGet(); }
		case 45: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 45 >::Type >::NameGet(); }
		case 46: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 46 >::Type >::NameGet(); }
		case 47: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 47 >::Type >::NameGet(); }
		case 48: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 48 >::Type >::NameGet(); }
		case 49: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 49 >::Type >::NameGet(); }
		case 50: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 50 >::Type >::NameGet(); }
		case 51: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 51 >::Type >::NameGet(); }
		case 52: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 52 >::Type >::NameGet(); }
		case 53: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 53 >::Type >::NameGet(); }
		case 54: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 54 >::Type >::NameGet(); }
		case 55: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 55 >::Type >::NameGet(); }
		case 56: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 56 >::Type >::NameGet(); }
		case 57: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 57 >::Type >::NameGet(); }
		case 58: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 58 >::Type >::NameGet(); }
		case 59: { return HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, 59 >::Type >::NameGet(); }
		}

		return HTraitName< HTypeNone >::NameGet();
	}

	/////////////////////////////////////////////////////////
	// private methods
	/**/
	template< typename IN_VARIANT_LHS, typename IN_VARIANT_RHS, HSINT IN_RHS_TYPE_INDEX > 
	HVOID HVariantUtility::ConvertorIndex( IN_VARIANT_LHS& out_lhs, const IN_VARIANT_RHS& in_rhs )
	{
		typedef HTypeListUtilIndexType< IN_VARIANT_RHS::TTypeList, IN_RHS_TYPE_INDEX >::Type TRhsType;
		const HBOOL result = HTypeListUtilContains< IN_VARIANT_LHS::TTypeList, TRhsType >::result;

		HVariantUtilityConvertorHelper< IN_VARIANT_LHS, TRhsType, result >::Invoke( out_lhs, in_rhs.ValueGet< TRhsType >() );

		return;
	}

	/**/
	//HTraitName< HTypeListUtilIndexType< IN_VARIANT::TTypeList, IN_INDEX >::Type >::NameGet
	//template< HSINT IN_INDEX, typename IN_VARIANT > 
	//HBOOL HVariantUtility::TypeIndexFromNameIndex( HSINT& in_out_index, const HString& in_name )
	//{
	//	typedef HTypeListUtilIndexType< IN_VARIANT::TTypeList, IN_INDEX >::Type TType;
	//	if( in_name == HTraitName< TType >::NameGet() )
	//	{
	//		in_out_index = IN_INDEX;
	//		return HTRUE;
	//	}

	//	return HFALSE;
	//}

	/**/

};

#endif // _H_VARIANT_UTILITY_H_