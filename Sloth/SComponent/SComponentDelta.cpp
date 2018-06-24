//file: Sloth/SComponent/SComponentDelta.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentDelta.h"

#include "Sloth/SComponent/SComponentDeltaImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentDelta::SComponentDelta()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW(
		m_pImplementation,
		SComponentDeltaImplementation
		);
	return;
}

/**/
SComponentDelta::~SComponentDelta()
{
	HCOMMON_DELETE(
		m_pImplementation,
		SComponentDeltaImplementation
		);
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentDelta::Reset()
{
	ImplementationGet().Reset();
	return;
}

/**/
Hubris::HVOID SComponentDelta::StartNewFrame()
{
	ImplementationGet().StartNewFrame();
	return;
}

/**/
const Hubris::HREAL SComponentDelta::LastDeltaGet()const
{
	const HREAL lastDelta = ImplementationGet().LastDeltaGet();
	return lastDelta;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentDeltaImplementation& SComponentDelta::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentDeltaImplementation& SComponentDelta::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
