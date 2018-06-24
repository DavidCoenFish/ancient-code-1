//file: Sloth/SComponent/SComponentDeltaImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentDeltaImplementation.h"

#include< Windows.h >
/*

GetSystemTime

milliseconds that have elapsed since the system was started
DWORD dwStart = GetTickCount();
//wiki A millisecond (from milli- and second; abbreviation: ms) is one thousandth of a second.

BOOL QueryPerformanceFrequency(
  LARGE_INTEGER* lpFrequency
);

BOOL QueryPerformanceCounter(
  LARGE_INTEGER* lpPerformanceCount
);

*/

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentDeltaImplementation::SComponentDeltaImplementation()
: m_lastTick( 0 )
, m_lastDelta( HVariablesMath::ZeroGet< HREAL >() )
{
	Reset();
	return;
}

/**/
SComponentDeltaImplementation::~SComponentDeltaImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentDeltaImplementation::Reset()
{
	m_lastTick = GetTickCount();
	m_lastDelta = HVariablesMath::ZeroGet< HREAL >();
	return;
}

/**/
Hubris::HVOID SComponentDeltaImplementation::StartNewFrame()
{
	const HSINT lastTick = m_lastTick;
	m_lastTick = GetTickCount();

	const HSINT deltaTick = m_lastTick - lastTick;

	if( deltaTick < 1000000 )
	{
		m_lastDelta = ( HREAL )( deltaTick ) * 0.001F;
	}
	else
	{
		m_lastDelta = HVariablesMath::ZeroGet< HREAL >();
	}

	return;
}

/**/
const Hubris::HREAL SComponentDeltaImplementation::LastDeltaGet()const
{
	return m_lastDelta;
}

/**/
