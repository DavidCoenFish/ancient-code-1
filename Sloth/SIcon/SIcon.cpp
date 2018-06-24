//file: Sloth/SIcon/SIcon.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SIcon/SIcon.h"

#include "Sloth/SIcon/SIconImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SIcon::SIcon( 
	const SIconParam& in_param
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation, 
		SIconImplementation,
		in_param	
		);
	return;
}

/**/
SIcon::~SIcon()
{
	HCOMMON_DELETE( m_pImplementation, SIconImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
SIcon::HICON SIcon::IconLargeGet()
{
	return ImplementationGet().IconLargeGet();
}

/**/
SIcon::HICON SIcon::IconSmallGet()
{
	return ImplementationGet().IconSmallGet();
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SIconImplementation& SIcon::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
SIconImplementation& SIcon::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}
/**/
