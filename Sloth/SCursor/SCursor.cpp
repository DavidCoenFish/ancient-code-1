//file: Sloth/SCursor/SCursor.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SCursor/SCursor.h"

#include "Sloth/SCursor/SCursorImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SCursor::SCursor( 
	const SCursorParam& in_param
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation, 
		SCursorImplementation,
		in_param	
		);
	return;
}

/**/
SCursor::~SCursor()
{
	HCOMMON_DELETE( m_pImplementation, SCursorImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
SCursor::HCURSOR SCursor::CursorGet()
{
	return ImplementationGet().CursorGet();
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SCursorImplementation& SCursor::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
SCursorImplementation& SCursor::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}
/**/
