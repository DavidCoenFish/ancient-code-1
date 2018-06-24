//file: Vanity/VAnimation/VAnimationBlendData.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationBlendData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VAnimationBlendData::VAnimationBlendData()
: m_pAnimation()
, m_arrayMapBlenderTargetArrayToAnimationTargetArray()
{
	return;
}

/**/
VAnimationBlendData::~VAnimationBlendData()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT VAnimationBlendData::StreamIndexGet( const Hubris::HSINT in_blenderTargetIndex )const
{
	if( ( 0 <= in_blenderTargetIndex ) &&
		( in_blenderTargetIndex < m_arrayMapBlenderTargetArrayToAnimationTargetArray.SizeGet() ) )
	{
		return m_arrayMapBlenderTargetArrayToAnimationTargetArray[ in_blenderTargetIndex ];
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
Hubris::HVOID VAnimationBlendData::StreamIndexSet( 
	const Hubris::HSINT in_blenderTargetIndex,
	const Hubris::HSINT in_streamIndex
	)
{
	for( HSINT index = m_arrayMapBlenderTargetArrayToAnimationTargetArray.SizeGet(); index <= in_blenderTargetIndex; ++index )
	{
		HContainerUtility::PushBack( m_arrayMapBlenderTargetArrayToAnimationTargetArray, HCOMMON_INVALID_INDEX );
	}

	m_arrayMapBlenderTargetArrayToAnimationTargetArray[ in_blenderTargetIndex ] = in_streamIndex;

	return;
}

/**/
