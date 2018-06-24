//file: Vanity/VComponentDynamic/VComponentDynamicDataSimple.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataSimple.h"

#include "Vanity/VComponentDynamic/VComponentDynamicTrait.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;


EMEMENTO_FACTORY_SOURCE( VComponentDynamicDataSimple, VComponentDynamicDataBase );

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamicDataSimple::VComponentDynamicDataSimple(
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL m_invertMass
	)
: m_param( in_param )
, m_invertMass( m_invertMass )
, m_arrayContactData()
, m_translationForceSum()
, m_translationVelocity()
, m_translation()
, m_resolvedMovement( HFALSE )
{
	return;
}

/**/
VComponentDynamicDataSimple::VComponentDynamicDataSimple()
: m_param()
, m_invertMass( 0.0F )
, m_arrayContactData()
, m_translationForceSum()
, m_translationVelocity()
, m_translation()
, m_resolvedMovement( HFALSE )
{
	return;
}

/**/
VComponentDynamicDataSimple::~VComponentDynamicDataSimple()
{
	return;
}

///////////////////////////////////////////////////////
// implememnt VComponentDynamicDataBase
/**/
Hubris::HVOID VComponentDynamicDataSimple::OnStartNewFrame()
{
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataSimple::ItemParamGet(
	VComponentDynamicComponentParam& out_param,
	Hubris::HREAL& out_invertMass 
	)const
{
	out_param = m_param;
	out_invertMass = m_invertMass;
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataSimple::ItemParamSet(
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL in_invertMass
	)
{
	m_param = in_param;
	m_invertMass = in_invertMass;
	return;
}

/**/
Hubris::HVOID VComponentDynamicDataSimple::ItemDataGet(
	TArrayContactData* const out_pArrayContactData,
	Hubris::HVectorR3* const out_pVelocity,
	Pride::PUnitVectorR3* const out_pRotationAxis,
	Hubris::HREAL* const out_pRotationMagnitude
	)const
{
	if( HNULL != out_pArrayContactData )
	{
		( *out_pArrayContactData ) = m_arrayContactData;
	}

	out_pVelocity;
	out_pRotationAxis;
	out_pRotationMagnitude;

	return;
}

/**/