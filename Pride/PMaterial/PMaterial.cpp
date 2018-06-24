//file: Pride/PMaterial/PMaterial.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMaterial/PMaterial.h"

#include "Pride/PMaterial/PMaterialImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PMaterial::PMaterial( const PMaterial& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PMaterialImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PMaterial::PMaterial()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PMaterialImplementation );
	return;
}

/**/
PMaterial::~PMaterial()
{
	HCOMMON_DELETE( m_pImplementation, PMaterialImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PMaterial& PMaterial::operator=( const PMaterial& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL PMaterial::operator==( const PMaterial& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PMaterial::operator!=( const PMaterial& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const PMaterialImplementation& PMaterial::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PMaterialImplementation& PMaterial::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/