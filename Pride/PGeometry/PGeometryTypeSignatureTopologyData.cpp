//file: Pride/PGeometry/PGeometryTypeSignatureTopologyData.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryTypeSignatureTopologyData.h"
#include "Pride/PGeometry/PGeometryTypeSignatureData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// creation
/**/
PGeometryTypeSignatureTopologyData::PGeometryTypeSignatureTopologyData( const PGeometryTypeSignatureTopologyData& in_src  )
: m_type( HCOMMON_INVALID_INDEX )
, m_arrayIndex()
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryTypeSignatureTopologyData::PGeometryTypeSignatureTopologyData( 
	const Hubris::HSINT in_type,
	const TArraySint& in_arrayIndex
	)
: m_type( in_type )
, m_arrayIndex( in_arrayIndex )
{
	return;
}

/**/
PGeometryTypeSignatureTopologyData::PGeometryTypeSignatureTopologyData()
: m_type( HCOMMON_INVALID_INDEX )
, m_arrayIndex()
{
	return;
}

/**/
PGeometryTypeSignatureTopologyData::~PGeometryTypeSignatureTopologyData()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryTypeSignatureTopologyData& PGeometryTypeSignatureTopologyData::operator=( const PGeometryTypeSignatureTopologyData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_type = in_rhs.m_type;
		m_arrayIndex = in_rhs.m_arrayIndex;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryTypeSignatureTopologyData::operator==( const PGeometryTypeSignatureTopologyData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != &in_rhs )
	{
		match &= ( m_type == in_rhs.m_type );
		match &= ( m_arrayIndex == in_rhs.m_arrayIndex );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryTypeSignatureTopologyData::operator!=( const PGeometryTypeSignatureTopologyData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
