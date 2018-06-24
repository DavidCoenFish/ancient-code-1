//file: Hubris/HType/HTypeRunTimeInfo.h
#ifndef _H_TYPE_RUN_TIME_INFO_H_
#define _H_TYPE_RUN_TIME_INFO_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HType/HTypeIndex.h"

#define HTYPE_RUN_TIME_TYPE_INFO_BASE( IN_CLASS ) \
	public: \
	virtual Hubris::HBOOL TypeRunTimeInfoTest( const Hubris::HSINT in_typeIndex )const \
	{ return( Hubris::HTypeIndex< IN_CLASS >::UniqueTypeIndexGet() == in_typeIndex ); } \
	virtual Hubris::HBOOL TypeRunTimeInfoTestRecurse( const Hubris::HSINT in_typeIndex )const \
	{ return IN_CLASS::TypeRunTimeInfoTest( in_typeIndex ); }

#define HTYPE_RUN_TIME_TYPE_INFO( IN_CLASS, IN_PARENT ) \
	public: \
	virtual Hubris::HBOOL TypeRunTimeInfoTest( const Hubris::HSINT in_typeIndex )const \
	{ return( Hubris::HTypeIndex< IN_CLASS >::UniqueTypeIndexGet() == in_typeIndex ); } \
	virtual Hubris::HBOOL TypeRunTimeInfoTestRecurse( const Hubris::HSINT in_typeIndex )const \
	{ return( IN_CLASS::TypeRunTimeInfoTest( in_typeIndex ) || ( IN_PARENT::TypeRunTimeInfoTestRecurse( in_typeIndex ) ) ); } \

namespace Hubris
{
	/**/
	template< typename IN_TYPE, typename IN_TARGET >IN_TARGET* HTypeRunTimeInfoCast( IN_TYPE* const in_pClass )
	{
		if( HNULL == in_pClass )
		{
			return HNULL;
		}

		if( HTRUE == in_pClass->TypeRunTimeInfoTestRecurse( HTypeIndex< IN_TARGET >::UniqueTypeIndexGet() ) )
		{
			return ( IN_TARGET* )( in_pClass );
		}

		return HNULL;
	}

	/**/
	template< typename IN_TYPE, typename IN_TARGET >const IN_TARGET* HTypeRunTimeInfoCast( const IN_TYPE* const in_pClass )
	{
		if( HNULL == in_pClass )
		{
			return HNULL;
		}

		if( HTRUE == in_pClass->TypeRunTimeInfoTestRecurse( HTypeIndex< IN_TARGET >::UniqueTypeIndexGet() ) )
		{
			return ( const IN_TARGET* )( in_pClass );
		}

		return HNULL;
	}

	/**/
};

#endif // _H_TYPE_RUN_TIME_INFO_H_