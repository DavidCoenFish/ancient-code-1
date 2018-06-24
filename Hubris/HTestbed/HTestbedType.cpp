//file: Hubris/HTestbed/HTestbedType.cpp

#include "Hubris/HTestbed/HTestbedType.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HType/HTypeHandle.h"
#include "Hubris/HType/HTypeIndex.h"
#include "Hubris/HType/HTypeList.h"
#include "Hubris/HType/HTypeListTrait.h"
#include "Hubris/HType/HTypeListUtility.h"
#include "Hubris/HType/HTypeNone.h"
#include "Hubris/HType/HTypeNoneTrait.h"
#include "Hubris/HType/HTypeRunTimeInfo.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;


class ClassTestbedTypeRunTimeInfo0
{
	HTYPE_RUN_TIME_TYPE_INFO_BASE( ClassTestbedTypeRunTimeInfo0 )
};

class ClassTestbedTypeRunTimeInfo1 : public ClassTestbedTypeRunTimeInfo0
{
	HTYPE_RUN_TIME_TYPE_INFO( ClassTestbedTypeRunTimeInfo1, ClassTestbedTypeRunTimeInfo0 )
};

class ClassTestbedTypeRunTimeInfo2 : public ClassTestbedTypeRunTimeInfo1
{
	HTYPE_RUN_TIME_TYPE_INFO( ClassTestbedTypeRunTimeInfo2, ClassTestbedTypeRunTimeInfo1 )
};


//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedTypeHandle()
{
	HBOOL success = HTRUE;

	HTYPE_HANDLE( ClassTestbedHandle );

	{
		ClassTestbedHandle handle0;
		success &= ( HCOMMON_INVALID_INDEX == handle0 );

		ClassTestbedHandle handle1( 145 );
		ClassTestbedHandle handle2( handle1 );

		success &= ( handle0 != handle2 );
		success &= ( handle2 != handle0 );

		success &= ( handle1 == handle2 );
		success &= ( handle2 == handle1 );

		success &= ( handle0 < handle1 );
		success &= !( handle1 < handle0 );
	}

	HTESTBED_VALIDATE_STATUS( "HTypeHandle", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeIndex()
{
	HBOOL success = HTRUE;

	{
		success &= ( HTypeIndex< HU8 >::UniqueTypeIndexGet() != HTypeIndex< HS8 >::UniqueTypeIndexGet() );
		success &= ( HTypeIndex< HU8 >::UniqueTypeIndexGet() != HTypeIndex< HU32 >::UniqueTypeIndexGet() );
		success &= ( HTypeIndex< HU8 >::UniqueTypeIndexGet() != HTypeIndex< HSINT >::UniqueTypeIndexGet() );
		success &= ( HTypeIndex< HU8 >::UniqueTypeIndexGet() != HTypeIndex< HBOOL >::UniqueTypeIndexGet() );

		success &= ( HTypeIndex< HSINT >::UniqueTypeIndexGet() == HTypeIndex< HSINT >::UniqueTypeIndexGet() );
		success &= ( HTypeIndex< HREAL >::UniqueTypeIndexGet() == HTypeIndex< HREAL >::UniqueTypeIndexGet() );
	}

	HTESTBED_VALIDATE_STATUS( "HTypeIndex", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeList()
{
	HBOOL success = HTRUE;

	typedef HTYPE_LIST_0() TTypeList0;
	typedef HTYPE_LIST_1( HU8 ) TTypeList1;
	typedef HTYPE_LIST_2( HBOOL, HCHAR ) TTypeList2;
	typedef HTYPE_LIST_APPEND( HREAL, TTypeList2 ) TTypeList3;

	HTESTBED_VALIDATE_STATUS( "HTypeList", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeListTrait()
{
	HBOOL success = HTRUE;

	typedef HTYPE_LIST_0() TTypeList0;
	typedef HTYPE_LIST_1( HU8 ) TTypeList1;
	typedef HTYPE_LIST_2( HBOOL, HCHAR ) TTypeList2;
	typedef HTYPE_LIST_APPEND( HREAL, TTypeList2 ) TTypeList3;

	typedef HTYPE_LIST_3( HREAL, HBOOL, HCHAR ) TTypeList4;

	//template<class IN_CLASS_A, class IN_CLASS_B> struct HTypeListUtilMatch::result
	{
		success &= ( HTRUE == HTypeListUtilMatch< HU8, HU8 >::result );
		success &= ( HFALSE == HTypeListUtilMatch< HU8, HS8 >::result );
	}

	//template<class IN_TYPE_LIST, class IN_CLASS> struct HTypeListUtilContains::result
	{
		success &= ( HTRUE == HTypeListUtilContains< TTypeList3, HBOOL >::result );
		success &= ( HFALSE == HTypeListUtilContains< TTypeList3, HString >::result );
	}

	//template<class IN_TYPE_LIST, class IN_CLASS> struct HTypeListUtilIndexOf::index
	{
		success &= ( 2 == HTypeListUtilIndexOf< TTypeList3, HBOOL >::index );
		success &= ( 1 == HTypeListUtilIndexOf< TTypeList3, HCHAR >::index );
		success &= ( 0 == HTypeListUtilIndexOf< TTypeList3, HREAL >::index );
	}
	//template<class IN_TYPE_LIST, const HS32 IN_INDEX> struct HTypeListUtilIndexType::Type
	{
		success &= ( HTRUE == HTypeListUtilMatch< HTypeListUtilIndexType< TTypeList3, 2 >::Type, HBOOL >::result );
		success &= ( HTRUE == HTypeListUtilMatch< HTypeListUtilIndexType< TTypeList3, 1 >::Type, HCHAR >::result );
		success &= ( HTRUE == HTypeListUtilMatch< HTypeListUtilIndexType< TTypeList3, 0 >::Type, HREAL >::result );
	}
	//template<class IN_TYPE_LIST> struct HTypeListUtilCount::count
	{
		success &= ( 0 == HTypeListUtilCount< TTypeList0 >::count );
		success &= ( 1 == HTypeListUtilCount< TTypeList1 >::count );
		success &= ( 2 == HTypeListUtilCount< TTypeList2 >::count );
		success &= ( 3 == HTypeListUtilCount< TTypeList3 >::count );
	}

	HTESTBED_VALIDATE_STATUS( "HTypeListTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeListUtility()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HTypeListUtility", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeNone()
{
	HBOOL success = HTRUE;

	{
		//conside disabling creation of NONE class?
		HTypeNone none;
	}

	HTESTBED_VALIDATE_STATUS( "HTypeNone", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeNoneTrait()
{
	HBOOL success = HTRUE;

	HTESTBED_VALIDATE_STATUS( "HTypeNoneTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedTypeRunTimeInfo()
{
	HBOOL success = HTRUE;

	{
		ClassTestbedTypeRunTimeInfo1 object0;
		ClassTestbedTypeRunTimeInfo2 object1;

		ClassTestbedTypeRunTimeInfo0* pObject0 = &object0;
		ClassTestbedTypeRunTimeInfo0* pObject1 = &object1;
		const ClassTestbedTypeRunTimeInfo0* const pObject2 = &object0;
		const ClassTestbedTypeRunTimeInfo0* const pObject3 = &object1;

		success &= ( HTRUE == pObject0->TypeRunTimeInfoTest( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject1->TypeRunTimeInfoTest( HTypeIndex< ClassTestbedTypeRunTimeInfo2 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject2->TypeRunTimeInfoTest( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject3->TypeRunTimeInfoTest( HTypeIndex< ClassTestbedTypeRunTimeInfo2 >::UniqueTypeIndexGet() ) );

		success &= ( HTRUE == pObject0->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject1->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject1->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo2 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject2->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject3->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == pObject3->TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo2 >::UniqueTypeIndexGet() ) );

		success &= ( HTRUE == object0.TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == object1.TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo1 >::UniqueTypeIndexGet() ) );
		success &= ( HTRUE == object1.TypeRunTimeInfoTestRecurse( HTypeIndex< ClassTestbedTypeRunTimeInfo2 >::UniqueTypeIndexGet() ) );

		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo1 >( pObject0 ) );
		success &= ( HNULL == HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo2 >( pObject0 ) );
		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo1 >( pObject1 ) );
		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo2 >( pObject1 ) );

		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo1 >( pObject2 ) );
		success &= ( HNULL == HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo2 >( pObject2 ) );
		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo1 >( pObject3 ) );
		success &= ( HNULL != HTypeRunTimeInfoCast< ClassTestbedTypeRunTimeInfo0, ClassTestbedTypeRunTimeInfo2 >( pObject3 ) );

	}

	HTESTBED_VALIDATE_STATUS( "HTypeRunTimeInfo", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedType()
{
	HTESTBED_VALIDATE_START( "TestbedType" );
	HBOOL success = HTRUE;

	success &= LocalTestbedTypeHandle();
	success &= LocalTestbedTypeIndex();
	success &= LocalTestbedTypeList();
	success &= LocalTestbedTypeListTrait();
	success &= LocalTestbedTypeListUtility();
	success &= LocalTestbedTypeNone();
	success &= LocalTestbedTypeNoneTrait();
	success &= LocalTestbedTypeRunTimeInfo();

	return success;
}

/**/