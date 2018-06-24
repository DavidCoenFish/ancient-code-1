//file: Hubris/HTestbed/HTestbedVariant.cpp

#include "Hubris/HTestbed/HTestbedVariant.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringOperators.h"
#include "Hubris/HString/HStringTrait.h"
#include "Hubris/HTrait/HTraitName.h"
#include "Hubris/HType/HTypeNone.h"
#include "Hubris/HType/HTypeNoneTrait.h"
#include "Hubris/HType/HTypeList.h"
#include "Hubris/HType/HTypeListTrait.h"
#include "Hubris/HVariant/HVariant.h"
#include "Hubris/HVariant/HVariantTrait.h"
#include "Hubris/HVariant/HVariantUtility.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// typedef
/**/
HVARIANT_DEFINITION( TVariant0, HTYPE_LIST_3( HU8, HU16, HU32 ) );
HVARIANT_DEFINITION( TVariant1, HTYPE_LIST_5( HU16, HS16, HU32, HS32, HBOOL ) );

//////////////////////////////////////////////////////
// local methods

/**/
static HBOOL LocalTestbedVariant()
{
	HBOOL success = HTRUE;

	//template< typename IN_TYPE >HVariantImplementation( const IN_TYPE& in_src )
	//HVariantImplementation( const HVariantImplementation& in_src );
	//HVariantImplementation();
	//~HVariantImplementation();

	{
		TVariant0 variant0( HU8( 150 ) );
		const TVariant0 variant1( variant0 );
		TVariant0 variant2;

		success &= ( variant0 == variant0 );

		success &= ( variant0 == variant1 );
		success &= ( variant1 == variant0 );

		success &= ( variant0 != variant2 );
		success &= ( variant2 != variant0 );
	}

	//template< typename IN_TYPE >void ValueSet( const IN_TYPE& in_src )
	//template< typename IN_TYPE >const IN_TYPE& ValueGet()const
	//template< typename IN_TYPE >IN_TYPE& ValueGet()
	//template< typename IN_TYPE > HBOOL TypeTest()const
	{
		TVariant0 variant0;
		variant0.ValueSet< HU8 >( 150 );

		TVariant0 variant1;
		variant1.ValueSet< HU16 >( 578 );

		TVariant0 variant2;
		variant2.ValueSet< HU32 >( 65599 );

		const TVariant0 variant3( variant2 );

		success &= ( HTRUE == variant0.TypeTest< HU8 >() );
		success &= ( HFALSE == variant0.TypeTest< HS8 >() );
		success &= ( 150 == variant0.ValueGet< HU8 >() );

		success &= ( HTRUE == variant1.TypeTest< HU16 >() );
		success &= ( HFALSE == variant1.TypeTest< HU8 >() );
		success &= ( 578 == variant1.ValueGet< HU16 >() );

		success &= ( HTRUE == variant2.TypeTest< HU32 >() );
		success &= ( HFALSE == variant2.TypeTest< HU16 >() );
		success &= ( 65599 == variant2.ValueGet< HU32 >() );

		variant2.ValueSet< HU16 >( 579 );
		success &= ( HTRUE == variant2.TypeTest< HU16 >() );
		success &= ( HFALSE == variant2.TypeTest< HS16 >() );
		success &= ( 579 == variant2.ValueGet< HU16 >() );

		success &= ( HTRUE == variant3.TypeTest< HU32 >() );
		success &= ( HFALSE == variant3.TypeTest< HU16 >() );
		success &= ( 65599 == variant3.ValueGet< HU32 >() );
	}


	//HSINT TypeIndexGet()const;
	//const HVariantImplementation& operator=( const HVariantImplementation & in_rhs );
	//HBOOL operator==( const HVariantImplementation& in_rhs )const;
	//HBOOL operator!=( const HVariantImplementation& in_rhs )const;
	//HBOOL TypesMatch( const HVariantImplementation& in_rhs )const;
	//template< typename IN_TYPE >operator IN_TYPE()const
	{
		TVariant0 variant0;
		variant0.ValueSet< HU16 >( 553 );

		TVariant0 variant1;
		variant1.ValueSet< HU16 >( 578 );

		TVariant0 variant2;
		variant2.ValueSet< HU32 >( 99999 );

		success &= ( variant0.TypeIndexGet() == variant1.TypeIndexGet() );
		success &= ( variant0.TypeIndexGet() != variant2.TypeIndexGet() );

		success &= ( HTRUE == variant0.TypesMatch( variant1 ) );
		success &= ( HTRUE == variant1.TypesMatch( variant0 ) );
		success &= ( HFALSE == variant0.TypesMatch( variant2 ) );

		success &= ( variant0 != variant1 );
		success &= ( variant1 != variant0 );

		variant1 = variant2;
		success &= ( variant1 == variant2 );
		success &= ( variant2 == variant1 );

		//success &= ( 99999 == ( HU32 ) variant1 );
	}

	HTESTBED_VALIDATE_STATUS( "HVariant", success );

	return success;
}

/**/
static HBOOL LocalTestbedVariantTrait()
{
	HBOOL success = HTRUE;

	{
		success &= ( "HVariant_HTypeList_HU8_HU16_HU32" == HTraitName< TVariant0::TVariantImplementation >::NameGet() );
		success &= ( "HVariant_HTypeList_HU16_HS16_HU32_HS32_HBOOL" == HTraitName< TVariant1::TVariantImplementation >::NameGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HVariantTrait", success );

	return success;
}

/**/
static HBOOL LocalTestbedVariantUtility()
{
	HBOOL success = HTRUE;

	//struct HVariantUtility
	//static void Convertor( IN_VARIANT_LHS& out_lhs, const IN_VARIANT_RHS& in_rhs );
	{
		TVariant0 variant0;
		TVariant1 variant1( ( HU16 )577 ); 

		HVariantUtility::Convertor( variant0, variant1 );
		success &= ( variant0.ValueGet< HU16 >() == variant1.ValueGet< HU16 >() );

		variant1.ValueSet< HU32 >( 99999 );
		HVariantUtility::Convertor( variant0, variant1 );
		success &= ( variant0.ValueGet< HU32 >() == variant1.ValueGet< HU32 >() );

		variant1.ValueSet< HBOOL >( HTRUE );
		HVariantUtility::Convertor( variant0, variant1 );
		success &= ( variant0 == TVariant0() );

		variant0.ValueSet< HU8 >( 129 );
		HVariantUtility::Convertor( variant1, variant0 );
		success &= ( variant1 == TVariant1() );
	}

	//static HSINT TypeIndexFromName( const HString& in_name );
	{
		success &= ( 4 == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HU16 >::NameGet() ) );
		success &= ( 3 == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HS16 >::NameGet() ) );
		success &= ( 2 == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HU32 >::NameGet() ) );
		success &= ( 1 == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HS32 >::NameGet() ) );
		success &= ( 0 == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HBOOL >::NameGet() ) );
		success &= ( HCOMMON_INVALID_INDEX == HVariantUtility::TypeIndexFromName< TVariant1 >( HTraitName< HString >::NameGet() ) );
	}

	HTESTBED_VALIDATE_STATUS( "HVariantUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedVariant()
{
	HTESTBED_VALIDATE_START( "TestbedVariant" );
	HBOOL success = HTRUE;

	success &= LocalTestbedVariant();
	success &= LocalTestbedVariantTrait();
	success &= LocalTestbedVariantUtility();

	return success;
}

/**/
