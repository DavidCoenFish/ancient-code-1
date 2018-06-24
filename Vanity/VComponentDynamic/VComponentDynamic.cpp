//file: Vanity/VComponentDynamic/VComponentDynamic.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamic.h"

#include "Vanity/VComponentDynamic/VComponentDynamicDataSimple.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataStatic.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Sloth/Sloth_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamic::VComponentDynamic()
: m_arrayData()
, m_componentParam()
{
	return;
}

/**/
VComponentDynamic::~VComponentDynamic()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentDynamic::OnAddItem(
	const Hubris::HSINT in_itemIndex 
	)
{
	if( m_arrayData.SizeGet() <= in_itemIndex )
	{
		m_arrayData.SizeResize( in_itemIndex + 1 );
	}

	return;
}
/**/
HVOID VComponentDynamic::OnRemoveItem(
	const Hubris::HSINT in_itemIndex
	)
{
	m_arrayData[ in_itemIndex ] = HNULL;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::StartNewFrame()
{
	//TODO: clear force on each dynamic item
	return;
}

/**/
Hubris::HVOID VComponentDynamic::DefaultParamSet(
	const VComponentDynamicComponentParam& in_param
	)
{
	m_componentParam = in_param;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemParamGet(
	const TItemId in_itemId,
	VComponentDynamicComponentParam& out_param,
	Hubris::HREAL& out_invertMass //zero if item doesn't move
	)
{
	const VComponentDynamicDataBase* const pDataBase = DataBaseGet( in_itemId );

	if( HNULL != pDataBase )
	{
		pDataBase->ItemParamGet(
			out_param,
			out_invertMass
			);
	}
	else
	{
		out_param = m_componentParam;
		out_invertMass = 0.0F;
	}

	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemParamSet(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL in_invertMass //zero if item doesn't move
	)
{
	VComponentDynamicDataBase* const pDataBase = DataBaseGet( in_itemId );

	if( HNULL != pDataBase )
	{
		pDataBase->ItemParamSet(
			in_param,
			in_invertMass
			);
	}

	return;
}
	
/**/
Hubris::HVOID VComponentDynamic::CreateDynamicStatic(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param
	)
{
	VComponentDynamicDataStatic* m_pDataStatic = HNULL;

	HCOMMON_NEW_PARAM(
		m_pDataStatic,
		VComponentDynamicDataStatic,
		in_param
		);

	m_arrayData[ in_itemId ] = m_pDataStatic;

	return;
}

/**/
Hubris::HVOID VComponentDynamic::CreateDynamicSimple(
	const TItemId in_itemId,
	const VComponentDynamicComponentParam& in_param,
	const Hubris::HREAL in_massInvert
	)
{
	VComponentDynamicDataSimple* m_pDataSimple = HNULL;

	HCOMMON_NEW_PARAM_2(
		m_pDataSimple,
		VComponentDynamicDataSimple,
		in_param,
		in_massInvert
		);

	m_arrayData[ in_itemId ] = m_pDataSimple;

	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemApplyTranslateForce(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_force
	)
{
	in_itemId;
	in_force;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemApplyTranslateForce(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_force,
	const Hubris::HVectorR3& in_position
	)
{
	in_itemId;
	in_force;
	in_position;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemApplyRotateForce(
	const TItemId in_itemId,
	const Pride::PUnitVectorR3& in_axis,
	const Hubris::HREAL in_magnitude
	)
{
	in_itemId;
	in_axis;
	in_magnitude;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemTranslateTeleport(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_newPosition
	)
{
	in_itemId;
	in_newPosition;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemTranslateSweep(
	const TItemId in_itemId,
	const Hubris::HVectorR3& in_newPosition
	)
{
	in_itemId;
	in_newPosition;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ResolveMovement(
	const Sloth::SComponentDelta& in_delta,
	VScene& in_scene
	)
{
	in_delta;
	in_scene;
	return;
}

/**/
Hubris::HVOID VComponentDynamic::ItemDataGet(
	const TItemId in_itemId,
	TArrayContactData* const out_pArrayContactData,
	Hubris::HVectorR3* const out_pVelocity,
	Pride::PUnitVectorR3* const out_pRotationAxis,
	Hubris::HREAL* const out_pRotationMagnitude
	)const
{
	const VComponentDynamicDataBase* const pDataBase = DataBaseGet( in_itemId );
	if( HNULL != pDataBase )
	{
		pDataBase->ItemDataGet(
			out_pArrayContactData,
			out_pVelocity,
			out_pRotationAxis,
			out_pRotationMagnitude
			);
	}

	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const VComponentDynamicDataBase* const VComponentDynamic::DataBaseGet(
	const TItemId in_itemId
	)const
{
	if( ( 0 <= in_itemId ) &&
		( in_itemId < m_arrayData.SizeGet() ) )
	{
		return m_arrayData[ in_itemId ].RawGet();
	}

	return HNULL;
}

/**/
VComponentDynamicDataBase* const VComponentDynamic::DataBaseGet(
	const TItemId in_itemId
	)
{
	if( ( 0 <= in_itemId ) &&
		( in_itemId < m_arrayData.SizeGet() ) )
	{
		return m_arrayData[ in_itemId ].RawGet();
	}

	return HNULL;
}

/**/