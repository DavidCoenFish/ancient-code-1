//file: Pride/PGeometry/PGeometryTypeSignatureData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryTypeSignatureData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// creation
/**/
PGeometryTypeSignatureData::PGeometryTypeSignatureData( const PGeometryTypeSignatureData& in_src  )
: m_type( HCOMMON_INVALID_INDEX )
, m_name()
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryTypeSignatureData::PGeometryTypeSignatureData( 
	const Hubris::HSINT in_type,
	const Hubris::HString& in_name
	)
: m_type( in_type )
, m_name( in_name )
{
	return;
}

/**/
PGeometryTypeSignatureData::PGeometryTypeSignatureData()
: m_type( HCOMMON_INVALID_INDEX )
, m_name()
{
	return;
}

/**/
PGeometryTypeSignatureData::~PGeometryTypeSignatureData()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryTypeSignatureData& PGeometryTypeSignatureData::operator=( const PGeometryTypeSignatureData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_type = in_rhs.m_type;
		m_name = in_rhs.m_name;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryTypeSignatureData::operator==( const PGeometryTypeSignatureData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_type == in_rhs.m_type );
		match &= ( m_name == in_rhs.m_name );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryTypeSignatureData::operator!=( const PGeometryTypeSignatureData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
