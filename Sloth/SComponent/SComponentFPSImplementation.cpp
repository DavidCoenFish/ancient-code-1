//file: Sloth/SComponent/SComponentFPSImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentFPSImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentFPSImplementation::SComponentFPSImplementation( 
	const Hubris::HSINT in_sampleLoopLength
	)
: m_arrayDelta()
, m_averageDelta( HVariablesMath::ZeroGet< HREAL >() )
, m_arrayLoopLength( in_sampleLoopLength )
, m_loopInsertTrace( 0 )
{
	return;
}

/**/
SComponentFPSImplementation::~SComponentFPSImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SComponentFPSImplementation::Reset()
{
	m_arrayDelta.Clear();
	m_averageDelta = HVariablesMath::ZeroGet< HREAL >();
	m_loopInsertTrace = 0;

	return;
}

/**/
Hubris::HVOID SComponentFPSImplementation::NotifyNewFrame( const Hubris::HREAL in_delta )
{
	if( m_arrayDelta.SizeGet() < m_arrayLoopLength )
	{
		HContainerUtility::PushBack( m_arrayDelta, in_delta );
	}
	else
	{
		m_arrayDelta[ m_loopInsertTrace ] = in_delta;
		m_loopInsertTrace = ( ( m_loopInsertTrace + 1 ) % m_arrayLoopLength );
	}

	//update average delta
	const HREAL mul = 1.0F / ( HREAL )m_arrayDelta.SizeGet();
	m_averageDelta = HVariablesMath::ZeroGet< HREAL >();
	HCOMMON_FOR_EACH( delta, m_arrayDelta, TArrayReal )
	{
		m_averageDelta += ( mul * delta );
	}

	return;
}

/**/
const Hubris::HREAL SComponentFPSImplementation::FPSGet()const
{
	if( 0.0F != m_averageDelta )
	{
		return( 1.0F / m_averageDelta );
	}

	return 0.0F;
}

/**/
