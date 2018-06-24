//file: Sloth/SComponent/SComponentFPS.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentFPS.h"

#include "Sloth/SComponent/SComponentFPSImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentFPS::SComponentFPS( 
	const Hubris::HSINT in_sampleLoopLength
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM(
		m_pImplementation,
		SComponentFPSImplementation,
		in_sampleLoopLength
		);
	return;
}

/**/
SComponentFPS::~SComponentFPS()
{
	HCOMMON_DELETE(
		m_pImplementation,
		SComponentFPSImplementation
		);
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentFPS::Reset()
{
	ImplementationGet().Reset();
	return;
}

/**/
Hubris::HVOID SComponentFPS::NotifyNewFrame( const Hubris::HREAL in_delta )
{
	ImplementationGet().NotifyNewFrame( in_delta );
	return;
}

/**/
const Hubris::HREAL SComponentFPS::FPSGet()const
{
	const HREAL fps = ImplementationGet().FPSGet();
	return fps;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SComponentFPSImplementation& SComponentFPS::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
SComponentFPSImplementation& SComponentFPS::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid memeber" );
	return( *m_pImplementation );
}

/**/
