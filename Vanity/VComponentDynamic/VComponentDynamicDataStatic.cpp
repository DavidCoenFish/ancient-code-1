//file: Vanity/VComponentDynamic/VComponentDynamicDataStatic.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataStatic.h"

#include "Vanity/VComponentDynamic/VComponentDynamicTrait.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

EMEMENTO_FACTORY_SOURCE( VComponentDynamicDataStatic, VComponentDynamicDataBase );

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamicDataStatic::VComponentDynamicDataStatic(
	const VComponentDynamicComponentParam& in_param
	)
: m_param( in_param )
{
	return;
}

/**/
VComponentDynamicDataStatic::VComponentDynamicDataStatic()
: m_param()
{
	return;
}

/**/
VComponentDynamicDataStatic::~VComponentDynamicDataStatic()
{
	return;
}

///////////////////////////////////////////////////////
// implememnt VComponentDynamicDataBase
/**/
Hubris::HVOID VComponentDynamicDataStatic::OnStartNewFrame()
{
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataStatic::ItemParamGet(
	VComponentDynamicComponentParam& HCOMMON_UNUSED_VAR( out_param ),
	Hubris::HREAL& HCOMMON_UNUSED_VAR( out_invertMass ) 
	)const
{
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataStatic::ItemParamSet(
	const VComponentDynamicComponentParam& HCOMMON_UNUSED_VAR( in_param ),
	const Hubris::HREAL HCOMMON_UNUSED_VAR( in_invertMass )
	)
{
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataStatic::ItemDataGet(
	TArrayContactData* const HCOMMON_UNUSED_VAR( out_pArrayContactData ),
	Hubris::HVectorR3* const HCOMMON_UNUSED_VAR( out_pVelocity ),
	Pride::PUnitVectorR3* const HCOMMON_UNUSED_VAR( out_pRotationAxis ),
	Hubris::HREAL* const HCOMMON_UNUSED_VAR( out_pRotationMagnitude )
	)const
{
	return;
}

/**/
