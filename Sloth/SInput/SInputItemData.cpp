//file: Sloth/SInput/SInputItemData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SInput/SInputItemData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
struct TButtonStateFlag
{
	enum TEnum
	{
		TNone				= 0x00,
		TButtonUp			= 0x01,
		TButtonDown			= 0x02,
		TButtonChangeUp		= 0x04,
		TButtonChangeDown	= 0x08,
		TButtonModifier		= 0x10,
	};
};


///////////////////////////////////////////////////////
// creation
/**/
SInputItemData::SInputItemData( const SInputItemData& in_src )
: m_flag( TButtonStateFlag::TButtonUp )
, m_value( HVariablesMath::ZeroGet< HREAL >() )
, m_previousValue( HVariablesMath::ZeroGet< HREAL >() )
{
	( *this ) = in_src;
	return;
}

/**/
SInputItemData::SInputItemData()
: m_flag( TButtonStateFlag::TButtonUp )
, m_value( HVariablesMath::ZeroGet< HREAL >() )
, m_previousValue( HVariablesMath::ZeroGet< HREAL >() )
{
	return;
}

/**/
SInputItemData::~SInputItemData()
{
	return;
}


///////////////////////////////////////////////////////
// disabled
/**/
const SInputItemData& SInputItemData::operator=( const SInputItemData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_flag = in_rhs.m_flag;
		m_value = in_rhs.m_value;
		m_previousValue = in_rhs.m_previousValue;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SInputItemData::operator==( const SInputItemData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_value == in_rhs.m_value );
		match &= ( m_previousValue == in_rhs.m_previousValue );
	}

	return( match );
}

/**/
const Hubris::HBOOL SInputItemData::operator!=( const SInputItemData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SInputItemData::Update()
{
	m_previousValue = m_value;
	if( m_flag & ( TButtonStateFlag::TButtonChangeDown | TButtonStateFlag::TButtonChangeUp ) )
	{
		m_flag &= ~( TButtonStateFlag::TButtonChangeDown | TButtonStateFlag::TButtonChangeUp );
	}
	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT SInputItemData::ButtonStateNoneGet()
{
	return( TButtonStateFlag::TNone );
}

/**/
const Hubris::HSINT SInputItemData::ButtonStateUpGet()
{
	return( TButtonStateFlag::TButtonUp );
}

/**/
const Hubris::HSINT SInputItemData::ButtonStateDownGet()
{
	return( TButtonStateFlag::TButtonDown );
}

/**/
const Hubris::HSINT SInputItemData::ButtonStateChangedToUpGet()
{
	return( TButtonStateFlag::TButtonChangeUp );
}

/**/
const Hubris::HSINT SInputItemData::ButtonStateChangedToDownGet()
{
	return( TButtonStateFlag::TButtonChangeDown );
}

/**/
const Hubris::HSINT SInputItemData::ButtonStateModifierGet()
{
	return( TButtonStateFlag::TButtonModifier );
}

/**/
