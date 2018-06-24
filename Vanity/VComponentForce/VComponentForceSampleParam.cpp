//file: Vanity/VComponentForce/VComponentForceSampleParam.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentForce/VComponentForceSampleParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentForceSampleParam::VComponentForceSampleParam(
	const Hubris::HSINT in_forceFlag,
	const Hubris::HVectorR3& in_location,
	const Hubris::HREAL in_massInvert
	)
: m_forceFlag( in_forceFlag )
, m_location( in_location )
, m_massInvert( in_massInvert )
{
	return;
}

/**/
VComponentForceSampleParam::~VComponentForceSampleParam()
{
	return;
}

/**/