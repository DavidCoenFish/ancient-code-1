//file: Vanity/VComponentVisual/VComponentVisualDataBase.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisualDataBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisualDataBase::VComponentVisualDataBase()
: m_alphaOverrideFrameId( HCOMMON_INVALID_INDEX )
, m_alphaOverride( 0.0F )
{
	return;
}

/**/
VComponentVisualDataBase::~VComponentVisualDataBase()
{
	return;
}

///////////////////////////////////////////////////////
// public members
/**/
Hubris::HVOID VComponentVisualDataBase::AlphaOverrideSet(
	const Hubris::HSINT in_alphaOverrideFrameId,
	Hubris::HREAL in_alphaOverride
	)
{
	m_alphaOverrideFrameId = in_alphaOverrideFrameId;
	m_alphaOverride = in_alphaOverride;

	return;
}
/**/