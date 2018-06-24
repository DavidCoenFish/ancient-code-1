//file: Envy/EMemento/EMementoTrait.h
#ifndef _E_MEMENTO_TRAIT_H_
#define _E_MEMENTO_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

#define EMEMENTO_TRAIT_HEADER( IN_CLASS )					\
namespace Envy												\
{															\
	class EMementoCollect;									\
	class EMementoAssign;									\
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );\
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );\
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_CLASS& in_data );\
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_CLASS& out_data );\
};

#define EMEMENTO_TRAIT_FRIEND( IN_CLASS )					\
friend Hubris::HVOID Envy::EMementoTraitCollect< IN_CLASS >( Envy::EMementoCollect& in_out_mementoCollect, const IN_CLASS& in_data );\
friend Hubris::HVOID Envy::EMementoTraitAssign< IN_CLASS >( const Envy::EMementoAssign& in_out_mementoAssign, IN_CLASS& out_data );\


namespace Hubris
{
	class HFileSystemPath;
	class HTypeNone;

	template< typename IN_TYPE >class HQuaternion;
	typedef HQuaternion< HREAL >HQuaternionREAL;
}

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//HFileSystemPath
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Hubris::HFileSystemPath& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Hubris::HFileSystemPath& out_data );

	//HTypeNone
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Hubris::HTypeNone& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Hubris::HTypeNone& out_data );

	//HQuaternionREAL
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Hubris::HQuaternionREAL& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Hubris::HQuaternionREAL& out_data );

	//HMatrix
	template< typename IN_TYPE, Hubris::HSINT IN_WIDTH, Hubris::HSINT IN_HEIGHT >
	Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_data )
	{
		typedef Hubris::HContainerArray< IN_TYPE >TArray;
		TArray arrayData;
		arrayData.SizeSet( IN_WIDTH * IN_HEIGHT );
		for( Hubris::HSINT index = 0; index < IN_WIDTH * IN_HEIGHT; ++index )
		{
			arrayData[ index ] = in_data[ index ];
		}
		in_out_mementoCollect.MemberAdd( "data", arrayData );

		return;
	}
	template< typename IN_TYPE, Hubris::HSINT IN_WIDTH, Hubris::HSINT IN_HEIGHT >
	Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& out_data )
	{
		typedef Hubris::HContainerArray< IN_TYPE >TArray;
		TArray arrayData;
		in_out_mementoAssign.MemberGet( "data", arrayData );
		for( Hubris::HSINT index = 0; index < IN_WIDTH * IN_HEIGHT; ++index )
		{
			out_data[ index ] = arrayData[ index ];
		}

		return;
	}

	//variant
	template< typename IN_TYPELIST >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Hubris::HVariantImplementation< IN_TYPELIST >& in_data )
	{
		const Hubris::HSINT type = in_data.TypeIndexGet();
		in_out_mementoCollect.MemberAdd( "typeName", Hubris::HVariantUtility::TypeNameFromVariant( in_data ) );

		switch( type )
		{
		default: break;
		case  0: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  0 >::Type >() ); break;
		case  1: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  1 >::Type >() ); break;
		case  2: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  2 >::Type >() ); break;
		case  3: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  3 >::Type >() ); break;
		case  4: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  4 >::Type >() ); break;
		case  5: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  5 >::Type >() ); break;
		case  6: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  6 >::Type >() ); break;
		case  7: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  7 >::Type >() ); break;
		case  8: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  8 >::Type >() ); break;
		case  9: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST,  9 >::Type >() ); break;
		case 10: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 10 >::Type >() ); break;
		case 11: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 11 >::Type >() ); break;
		case 12: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 12 >::Type >() ); break;
		case 13: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 13 >::Type >() ); break;
		case 14: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 14 >::Type >() ); break;
		case 15: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 15 >::Type >() ); break;
		case 16: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 16 >::Type >() ); break;
		case 17: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 17 >::Type >() ); break;
		case 18: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 18 >::Type >() ); break;
		case 19: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 19 >::Type >() ); break;
		case 20: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 20 >::Type >() ); break;
		case 21: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 21 >::Type >() ); break;
		case 22: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 22 >::Type >() ); break;
		case 23: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 23 >::Type >() ); break;
		case 24: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 24 >::Type >() ); break;
		case 25: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 25 >::Type >() ); break;
		case 26: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 26 >::Type >() ); break;
		case 27: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 27 >::Type >() ); break;
		case 28: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 28 >::Type >() ); break;
		case 29: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 29 >::Type >() ); break;
		case 30: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 30 >::Type >() ); break;
		case 31: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 31 >::Type >() ); break;
		case 32: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 32 >::Type >() ); break;
		case 33: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 33 >::Type >() ); break;
		case 34: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 34 >::Type >() ); break;
		case 35: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 35 >::Type >() ); break;
		case 36: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 36 >::Type >() ); break;
		case 37: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 37 >::Type >() ); break;
		case 38: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 38 >::Type >() ); break;
		case 39: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 39 >::Type >() ); break;
		case 40: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 40 >::Type >() ); break;
		case 41: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 41 >::Type >() ); break;
		case 42: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 42 >::Type >() ); break;
		case 43: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 43 >::Type >() ); break;
		case 44: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 44 >::Type >() ); break;
		case 45: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 45 >::Type >() ); break;
		case 46: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 46 >::Type >() ); break;
		case 47: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 47 >::Type >() ); break;
		case 48: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 48 >::Type >() ); break;
		case 49: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 49 >::Type >() ); break;
		case 50: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 50 >::Type >() ); break;
		case 51: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 51 >::Type >() ); break;
		case 52: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 52 >::Type >() ); break;
		case 53: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 53 >::Type >() ); break;
		case 54: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 54 >::Type >() ); break;
		case 55: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 55 >::Type >() ); break;
		case 56: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 56 >::Type >() ); break;
		case 57: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 57 >::Type >() ); break;
		case 58: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 58 >::Type >() ); break;
		case 59: in_out_mementoCollect.MemberAdd( "data", in_data.ValueGet< Hubris::HTypeListUtilIndexType< IN_TYPELIST, 59 >::Type >() ); break;
		}
		return;
	}

	template< typename IN_TYPELIST, Hubris::HSINT IN_TYPE_INDEX >Hubris::HVOID EMementoTraitAssignVariantType( const EMementoAssign& in_out_mementoAssign, Hubris::HVariantImplementation< IN_TYPELIST >& out_data )
	{
		typedef Hubris::HTypeListUtilIndexType< IN_TYPELIST, IN_TYPE_INDEX >::Type TType;
		TType value;
		in_out_mementoAssign.MemberGet( "data", value );
		out_data.ValueSet< TType >( value );
		return;
	}

	template< typename IN_TYPELIST >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Hubris::HVariantImplementation< IN_TYPELIST >& out_data )
	{
		Hubris::HString typeName;
		in_out_mementoAssign.MemberGet( "typeName", typeName );
		const Hubris::HSINT type = Hubris::HVariantUtility::TypeIndexFromName< Hubris::HVariantImplementation< IN_TYPELIST > >( typeName );

		switch( type )
		{
		default: break;
		case  0: EMementoTraitAssignVariantType< IN_TYPELIST,  0 >( in_out_mementoAssign, out_data ); break;
		case  1: EMementoTraitAssignVariantType< IN_TYPELIST,  1 >( in_out_mementoAssign, out_data ); break;
		case  2: EMementoTraitAssignVariantType< IN_TYPELIST,  2 >( in_out_mementoAssign, out_data ); break;
		case  3: EMementoTraitAssignVariantType< IN_TYPELIST,  3 >( in_out_mementoAssign, out_data ); break;
		case  4: EMementoTraitAssignVariantType< IN_TYPELIST,  4 >( in_out_mementoAssign, out_data ); break;
		case  5: EMementoTraitAssignVariantType< IN_TYPELIST,  5 >( in_out_mementoAssign, out_data ); break;
		case  6: EMementoTraitAssignVariantType< IN_TYPELIST,  6 >( in_out_mementoAssign, out_data ); break;
		case  7: EMementoTraitAssignVariantType< IN_TYPELIST,  7 >( in_out_mementoAssign, out_data ); break;
		case  8: EMementoTraitAssignVariantType< IN_TYPELIST,  8 >( in_out_mementoAssign, out_data ); break;
		case  9: EMementoTraitAssignVariantType< IN_TYPELIST,  9 >( in_out_mementoAssign, out_data ); break;
		case 10: EMementoTraitAssignVariantType< IN_TYPELIST, 10 >( in_out_mementoAssign, out_data ); break;
		case 11: EMementoTraitAssignVariantType< IN_TYPELIST, 11 >( in_out_mementoAssign, out_data ); break;
		case 12: EMementoTraitAssignVariantType< IN_TYPELIST, 12 >( in_out_mementoAssign, out_data ); break;
		case 13: EMementoTraitAssignVariantType< IN_TYPELIST, 13 >( in_out_mementoAssign, out_data ); break;
		case 14: EMementoTraitAssignVariantType< IN_TYPELIST, 14 >( in_out_mementoAssign, out_data ); break;
		case 15: EMementoTraitAssignVariantType< IN_TYPELIST, 15 >( in_out_mementoAssign, out_data ); break;
		case 16: EMementoTraitAssignVariantType< IN_TYPELIST, 16 >( in_out_mementoAssign, out_data ); break;
		case 17: EMementoTraitAssignVariantType< IN_TYPELIST, 17 >( in_out_mementoAssign, out_data ); break;
		case 18: EMementoTraitAssignVariantType< IN_TYPELIST, 18 >( in_out_mementoAssign, out_data ); break;
		case 19: EMementoTraitAssignVariantType< IN_TYPELIST, 19 >( in_out_mementoAssign, out_data ); break;
		case 20: EMementoTraitAssignVariantType< IN_TYPELIST, 20 >( in_out_mementoAssign, out_data ); break;
		case 21: EMementoTraitAssignVariantType< IN_TYPELIST, 21 >( in_out_mementoAssign, out_data ); break;
		case 22: EMementoTraitAssignVariantType< IN_TYPELIST, 22 >( in_out_mementoAssign, out_data ); break;
		case 23: EMementoTraitAssignVariantType< IN_TYPELIST, 23 >( in_out_mementoAssign, out_data ); break;
		case 24: EMementoTraitAssignVariantType< IN_TYPELIST, 24 >( in_out_mementoAssign, out_data ); break;
		case 25: EMementoTraitAssignVariantType< IN_TYPELIST, 25 >( in_out_mementoAssign, out_data ); break;
		case 26: EMementoTraitAssignVariantType< IN_TYPELIST, 26 >( in_out_mementoAssign, out_data ); break;
		case 27: EMementoTraitAssignVariantType< IN_TYPELIST, 27 >( in_out_mementoAssign, out_data ); break;
		case 28: EMementoTraitAssignVariantType< IN_TYPELIST, 28 >( in_out_mementoAssign, out_data ); break;
		case 29: EMementoTraitAssignVariantType< IN_TYPELIST, 29 >( in_out_mementoAssign, out_data ); break;
		case 30: EMementoTraitAssignVariantType< IN_TYPELIST, 30 >( in_out_mementoAssign, out_data ); break;
		case 31: EMementoTraitAssignVariantType< IN_TYPELIST, 31 >( in_out_mementoAssign, out_data ); break;
		case 32: EMementoTraitAssignVariantType< IN_TYPELIST, 32 >( in_out_mementoAssign, out_data ); break;
		case 33: EMementoTraitAssignVariantType< IN_TYPELIST, 33 >( in_out_mementoAssign, out_data ); break;
		case 34: EMementoTraitAssignVariantType< IN_TYPELIST, 34 >( in_out_mementoAssign, out_data ); break;
		case 35: EMementoTraitAssignVariantType< IN_TYPELIST, 35 >( in_out_mementoAssign, out_data ); break;
		case 36: EMementoTraitAssignVariantType< IN_TYPELIST, 36 >( in_out_mementoAssign, out_data ); break;
		case 37: EMementoTraitAssignVariantType< IN_TYPELIST, 37 >( in_out_mementoAssign, out_data ); break;
		case 38: EMementoTraitAssignVariantType< IN_TYPELIST, 38 >( in_out_mementoAssign, out_data ); break;
		case 39: EMementoTraitAssignVariantType< IN_TYPELIST, 39 >( in_out_mementoAssign, out_data ); break;
		case 40: EMementoTraitAssignVariantType< IN_TYPELIST, 40 >( in_out_mementoAssign, out_data ); break;
		case 41: EMementoTraitAssignVariantType< IN_TYPELIST, 41 >( in_out_mementoAssign, out_data ); break;
		case 42: EMementoTraitAssignVariantType< IN_TYPELIST, 42 >( in_out_mementoAssign, out_data ); break;
		case 43: EMementoTraitAssignVariantType< IN_TYPELIST, 43 >( in_out_mementoAssign, out_data ); break;
		case 44: EMementoTraitAssignVariantType< IN_TYPELIST, 44 >( in_out_mementoAssign, out_data ); break;
		case 45: EMementoTraitAssignVariantType< IN_TYPELIST, 45 >( in_out_mementoAssign, out_data ); break;
		case 46: EMementoTraitAssignVariantType< IN_TYPELIST, 46 >( in_out_mementoAssign, out_data ); break;
		case 47: EMementoTraitAssignVariantType< IN_TYPELIST, 47 >( in_out_mementoAssign, out_data ); break;
		case 48: EMementoTraitAssignVariantType< IN_TYPELIST, 48 >( in_out_mementoAssign, out_data ); break;
		case 49: EMementoTraitAssignVariantType< IN_TYPELIST, 49 >( in_out_mementoAssign, out_data ); break;
		case 50: EMementoTraitAssignVariantType< IN_TYPELIST, 50 >( in_out_mementoAssign, out_data ); break;
		case 51: EMementoTraitAssignVariantType< IN_TYPELIST, 51 >( in_out_mementoAssign, out_data ); break;
		case 52: EMementoTraitAssignVariantType< IN_TYPELIST, 52 >( in_out_mementoAssign, out_data ); break;
		case 53: EMementoTraitAssignVariantType< IN_TYPELIST, 53 >( in_out_mementoAssign, out_data ); break;
		case 54: EMementoTraitAssignVariantType< IN_TYPELIST, 54 >( in_out_mementoAssign, out_data ); break;
		case 55: EMementoTraitAssignVariantType< IN_TYPELIST, 55 >( in_out_mementoAssign, out_data ); break;
		case 56: EMementoTraitAssignVariantType< IN_TYPELIST, 56 >( in_out_mementoAssign, out_data ); break;
		case 57: EMementoTraitAssignVariantType< IN_TYPELIST, 57 >( in_out_mementoAssign, out_data ); break;
		case 58: EMementoTraitAssignVariantType< IN_TYPELIST, 58 >( in_out_mementoAssign, out_data ); break;
		case 59: EMementoTraitAssignVariantType< IN_TYPELIST, 59 >( in_out_mementoAssign, out_data ); break;
		}
		return;
	}


	/**/
};

#endif // _E_MEMENTO_TRAIT_H_