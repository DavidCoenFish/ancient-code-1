//file: Envy/EMemento/EMemento.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMemento.h"

#include "Envy/EMemento/EMementoImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

//////////////////////////////////////////////
//creation
/**/
EMemento::EMemento( const EMemento& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, EMementoImplementation, in_src.ImplementationGet() );
	in_src;
	return;
}

/**/
EMemento::EMemento()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, EMementoImplementation );

	return;
}

/**/
EMemento::~EMemento()
{
	HCOMMON_DELETE( m_pImplementation, EMementoImplementation );
	return;
}

//////////////////////////////////////////////
//operators
/**/
const EMemento& EMemento::operator=( const EMemento& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();

	return( *this );
}

/**/
Hubris::HBOOL EMemento::operator==( const EMemento& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL EMemento::operator!=( const EMemento& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

//////////////////////////////////////////////
//private accessors
/**/
const EMementoImplementation& EMemento::ImplementationGet()const
{
	return( *m_pImplementation );
}

/**/
EMementoImplementation& EMemento::ImplementationGet()
{
	return( *m_pImplementation );
}

/**/
