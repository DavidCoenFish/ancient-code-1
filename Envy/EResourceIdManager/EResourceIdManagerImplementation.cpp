//file: Envy/EResourceIdManager/EResourceIdManagerImplementation.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EResourceIdManager/EResourceIdManagerImplementation.h"

#include< Hubris/HVariables/HVariables_Export.h >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

/*
	bit is 'on' when resourceID not in use
*/

static const HU32 s_flagDefault = 0xFFFFFFFF;
static const HS32 s_bitCount = 32; 

///////////////////////////////////////////////////////
// creation
/**/
EResourceIdManagerImplementation::EResourceIdManagerImplementation( const EResourceIdManagerImplementation& in_src )
: m_minimumResourceValue( 0 )
, m_maximumResourceValue( HVariablesMath::MaximumGet< HSINT >() )
, m_minimumFreeArrayIndex( 0 )
, m_arrayResourceUseFlag()
, m_count( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
EResourceIdManagerImplementation::EResourceIdManagerImplementation( const Hubris::HSINT in_minimumResourceValue )
: m_minimumResourceValue( in_minimumResourceValue )
, m_maximumResourceValue( HVariablesMath::MaximumGet< HSINT >() )
, m_minimumFreeArrayIndex( 0 )
, m_arrayResourceUseFlag()
, m_count( 0 )
{
	return;
}

/**/
EResourceIdManagerImplementation::~EResourceIdManagerImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const EResourceIdManagerImplementation& EResourceIdManagerImplementation::operator=( const EResourceIdManagerImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_minimumResourceValue = in_rhs.m_minimumResourceValue;
		m_maximumResourceValue = in_rhs.m_maximumResourceValue;
		m_minimumFreeArrayIndex = in_rhs.m_minimumFreeArrayIndex;
		m_arrayResourceUseFlag = in_rhs.m_arrayResourceUseFlag;
		m_count = in_rhs.m_count;
	}

	return( *this );
}

/**/
const Hubris::HBOOL EResourceIdManagerImplementation::operator==( const EResourceIdManagerImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_minimumResourceValue == in_rhs.m_minimumResourceValue );
		match &= ( m_maximumResourceValue == in_rhs.m_maximumResourceValue );
		match &= ( m_minimumFreeArrayIndex == in_rhs.m_minimumFreeArrayIndex );
		match &= ( m_arrayResourceUseFlag == in_rhs.m_arrayResourceUseFlag );
		match &= ( m_count == in_rhs.m_count );
	}

	return match;
}

/**/
const Hubris::HBOOL EResourceIdManagerImplementation::operator!=( const EResourceIdManagerImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
Hubris::HVOID EResourceIdManagerImplementation::Clear()
{
	m_arrayResourceUseFlag.Clear();
	m_minimumFreeArrayIndex = 0;
	m_count = 0;
	return;
}

/**/
const Hubris::HSINT EResourceIdManagerImplementation::ResourceIdAcquire()
{
	HSINT returnIndex = HCOMMON_INVALID_INDEX;

	if( ( m_maximumResourceValue - m_minimumResourceValue ) <= m_count )
	{
		return HCOMMON_INVALID_INDEX;
	}

	for( HSINT arrayIndex = m_minimumFreeArrayIndex;; arrayIndex += 1, m_minimumFreeArrayIndex += 1 )
	{
		if( m_arrayResourceUseFlag.SizeGet() <= arrayIndex )
		{
			HContainerUtility::PushBack( m_arrayResourceUseFlag, s_flagDefault );
		}

		HU32& flag = m_arrayResourceUseFlag[ arrayIndex ];

		if( 0 == flag )
		{
			continue;
		}

		const HSINT index = HCOMMON_LOWEST_BIT32( flag );
		if( index == HCOMMON_INVALID_INDEX )
		{
			continue;
		}

		flag &= ( ~( HCOMMON_INDEX_TO_FLAG( index ) ) );
		returnIndex = m_minimumResourceValue + ( ( s_bitCount * arrayIndex ) + index );

		break;
	}

	m_count += 1;

	return returnIndex;
}

/**/
const Hubris::HBOOL EResourceIdManagerImplementation::ResourceIdValid( const Hubris::HSINT in_resourceId )const
{
	HSINT index = in_resourceId - m_minimumResourceValue;
	const HSINT arrayIndex = index / s_bitCount;

	if( ( 0 <= arrayIndex ) && ( arrayIndex < m_arrayResourceUseFlag.SizeGet() ) )
	{
		const HU32 itemFlag = HCOMMON_INDEX_TO_FLAG( index - ( arrayIndex * s_bitCount ) );
		const HU32 flag = m_arrayResourceUseFlag[ arrayIndex ];
		if( 0 == ( flag & itemFlag ) )
		{
			return HTRUE;
		}
	}

	return HFALSE;
}

/**/
Hubris::HVOID EResourceIdManagerImplementation::ResourceIdRelease( const Hubris::HSINT in_resourceId )
{
	HSINT index = in_resourceId - m_minimumResourceValue;
	const HSINT arrayIndex = index / s_bitCount;

	if( ( 0 <= arrayIndex ) && ( arrayIndex < m_arrayResourceUseFlag.SizeGet() ) )
	{
		const HU32 itemFlag = HCOMMON_INDEX_TO_FLAG( index - ( arrayIndex * s_bitCount ) );
		HU32& flag = m_arrayResourceUseFlag[ arrayIndex ];
		if( 0 == ( flag & itemFlag ) )
		{
			//only decrement count if this id was active
			m_count -= 1;
		}

		flag |= itemFlag;

		if( arrayIndex < m_minimumFreeArrayIndex )
		{
			m_minimumFreeArrayIndex = arrayIndex;
		}
	}

	return;
}
/**/

