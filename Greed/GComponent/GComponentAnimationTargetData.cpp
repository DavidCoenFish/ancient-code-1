//file: Greed/GComponent/GComponentAnimationTargetData.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GComponent/GComponentAnimationTargetData.h"

#include "Greed/GComponent/GComponentAnimationTargetDataValue.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TType
{
	enum TEnum
	{
		TSint = 0,
		TReal,
		TVectorR2,
		TVectorR3,
		TVectorR4,
		TCount
	};
};

typedef GComponentAnimationTargetDataValue< Hubris::HSINT >TDataValueSint;
typedef GComponentAnimationTargetDataValue< Hubris::HREAL >TDataValueReal;
typedef GComponentAnimationTargetDataValue< Hubris::HVectorR2 >TDataValueVectorR2;
typedef GComponentAnimationTargetDataValue< Hubris::HVectorR3 >TDataValueVectorR3;
typedef GComponentAnimationTargetDataValue< Hubris::HVectorR4 >TDataValueVectorR4;

///////////////////////////////////////////////////////
// creation
/**/
GComponentAnimationTargetData::GComponentAnimationTargetData(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HSINT in_defaultValue
	)
: m_gameObjectVarId( in_gameObjectVarId )
, m_blenderTargetIndex( in_blenderTargetIndex )
, m_typeIndex( TType::TSint )
, m_pData( HNULL )
{
	HCOMMON_NEW_PARAM( m_pData, TDataValueSint, in_defaultValue );
	return;
}

/**/
GComponentAnimationTargetData::GComponentAnimationTargetData(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HREAL in_defaultValue
	)
: m_gameObjectVarId( in_gameObjectVarId )
, m_blenderTargetIndex( in_blenderTargetIndex )
, m_typeIndex( TType::TReal )
, m_pData( HNULL )
{
	HCOMMON_NEW_PARAM( m_pData, TDataValueReal, in_defaultValue );
	return;
}

/**/
GComponentAnimationTargetData::GComponentAnimationTargetData(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HVectorR2& in_defaultValue
	)
: m_gameObjectVarId( in_gameObjectVarId )
, m_blenderTargetIndex( in_blenderTargetIndex )
, m_typeIndex( TType::TVectorR2 )
, m_pData( HNULL )
{
	HCOMMON_NEW_PARAM( m_pData, TDataValueVectorR2, in_defaultValue );
	return;
}

/**/
GComponentAnimationTargetData::GComponentAnimationTargetData(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HVectorR3& in_defaultValue
	)
: m_gameObjectVarId( in_gameObjectVarId )
, m_blenderTargetIndex( in_blenderTargetIndex )
, m_typeIndex( TType::TVectorR3 )
, m_pData( HNULL )
{
	HCOMMON_NEW_PARAM( m_pData, TDataValueVectorR3, in_defaultValue );
	return;
}

/**/
GComponentAnimationTargetData::GComponentAnimationTargetData(
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HVectorR4& in_defaultValue
	)
: m_gameObjectVarId( in_gameObjectVarId )
, m_blenderTargetIndex( in_blenderTargetIndex )
, m_typeIndex( TType::TVectorR4 )
, m_pData( HNULL )
{
	HCOMMON_NEW_PARAM( m_pData, TDataValueVectorR4, in_defaultValue );
	return;
}

/**/
GComponentAnimationTargetData::~GComponentAnimationTargetData()
{
	if( HNULL != m_pData )
	{
		switch( m_typeIndex )
		{
		default:
			{
				break;
			}
		case TType::TSint:
			{
				HCOMMON_DELETE( m_pData, TDataValueSint );
				break;
			}
		case TType::TReal:
			{
				HCOMMON_DELETE( m_pData, TDataValueReal );
				break;
			}
		case TType::TVectorR2:
			{
				HCOMMON_DELETE( m_pData, TDataValueVectorR2 );
				break;
			}
		case TType::TVectorR3:
			{
				HCOMMON_DELETE( m_pData, TDataValueVectorR3 );
				break;
			}
		case TType::TVectorR4:
			{
				HCOMMON_DELETE( m_pData, TDataValueVectorR4 );
				break;
			}
		}
	}
	return;
}

///////////////////////////////////////////////////////
// static public accessor
/**/
const Hubris::HSINT GComponentAnimationTargetData::TypeGetSint()
{
	return TType::TSint;
}

/**/
const Hubris::HSINT GComponentAnimationTargetData::TypeGetReal()
{
	return TType::TReal;
}

/**/
const Hubris::HSINT GComponentAnimationTargetData::TypeGetVectorR2()
{
	return TType::TVectorR2;
}

/**/
const Hubris::HSINT GComponentAnimationTargetData::TypeGetVectorR3()
{
	return TType::TVectorR3;
}

/**/
const Hubris::HSINT GComponentAnimationTargetData::TypeGetVectorR4()
{
	return TType::TVectorR4;
}

///////////////////////////////////////////////////////
// public accessor
/**/
const Hubris::HSINT GComponentAnimationTargetData::DefaultValueSintGet()const
{
	HCOMMON_ASSERT( ( HNULL != m_pData ) && ( TType::TSint == m_typeIndex ), "invalid state" );
	const HSINT returnValue = ( *( TDataValueSint* )m_pData ).ValueGet();
	return returnValue;
}

/**/
const Hubris::HREAL GComponentAnimationTargetData::DefaultValueRealGet()const
{
	HCOMMON_ASSERT( ( HNULL != m_pData ) && ( TType::TReal == m_typeIndex ), "invalid state" );
	const HREAL returnValue = ( *( TDataValueReal* )m_pData ).ValueGet();
	return returnValue;
}

/**/
const Hubris::HVectorR2& GComponentAnimationTargetData::DefaultValueVectorR2Get()const
{
	HCOMMON_ASSERT( ( HNULL != m_pData ) && ( TType::TVectorR2 == m_typeIndex ), "invalid state" );
	const HVectorR2& returnValue = ( *( TDataValueVectorR2* )m_pData ).ValueGet();
	return returnValue;
}

/**/
const Hubris::HVectorR3& GComponentAnimationTargetData::DefaultValueVectorR3Get()const
{
	HCOMMON_ASSERT( ( HNULL != m_pData ) && ( TType::TVectorR3 == m_typeIndex ), "invalid state" );
	const HVectorR3& returnValue = ( *( TDataValueVectorR3* )m_pData ).ValueGet();
	return returnValue;
}

/**/
const Hubris::HVectorR4& GComponentAnimationTargetData::DefaultValueVectorR4Get()const
{
	HCOMMON_ASSERT( ( HNULL != m_pData ) && ( TType::TVectorR4 == m_typeIndex ), "invalid state" );
	const HVectorR4& returnValue = ( *( TDataValueVectorR4* )m_pData ).ValueGet();
	return returnValue;
}

/**/
