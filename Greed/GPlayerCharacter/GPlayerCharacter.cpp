//file: Greed/GPlayerCharacter/GPlayerCharacter.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GPlayerCharacter/GPlayerCharacter.h"

#include "Greed/GComponent/GComponent_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;
using namespace Greed;

///////////////////////////////////////////////////////
// local var
/**/
static const HCHAR* const s_factoryName = "GPlayerCharacter";

///////////////////////////////////////////////////////
// typedef
/**/
///////////////////////////////////////////////////////
// local static methods
/**/
static const HVectorR3 LocalInputMovementVectorGet(
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Hubris::HBOOL in_playContolActive,
	const Hubris::HSINT in_inputIndex
	)
{
	HVectorR3 returnVector;
	if( HFALSE == in_playContolActive )
	{
		return returnVector;
	}

	const HVectorR3& cameraAt = in_scene.CameraVectorAtGet();
	const HVectorR3& cameraRight = in_scene.CameraVectorRightGet();

	const SInput& input = in_sceneApplicationInterface.InputGet( in_inputIndex );
	HVectorR3 offset;
	if( SInput::ButtonStateDownGet() == input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardRightGet() ) )
	{
		returnVector += cameraRight;
	}
	if( SInput::ButtonStateDownGet() == input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardLeftGet() ) )
	{
		returnVector -= cameraRight;
	}
	if( SInput::ButtonStateDownGet() == input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardUpGet() ) )
	{
		returnVector += cameraAt;
	}
	if( SInput::ButtonStateDownGet() == input.ButtonStateGet( SInput::DeviceIndexKeyboardGet(), SInput::InputIndexKeyboardDownGet() ) )
	{
		returnVector -= cameraAt;
	}

	returnVector[ 2 ] = 0.0F;

	HMatrixUtility::Normalise( returnVector );

	return returnVector;
}

///////////////////////////////////////////////////////
// creation
/**/
GPlayerCharacter::GPlayerCharacter()
: m_playContolActive( HTRUE )
, m_inputIndex( 0 )
, m_pComponentTilt( HNULL )
{
	HCOMMON_NEW( m_pComponentTilt, GComponentTilt );
	return;
}

/**/
GPlayerCharacter::~GPlayerCharacter()
{
	HCOMMON_DELETE( m_pComponentTilt, GComponentTilt );
	return;
}
///////////////////////////////////////////////////////
// static public method
/**/
Vanity::VComponentGameDataBase* const GPlayerCharacter::FactoryGameObjectCreate(
	const Envy::EMementoAssign& in_mementoAssign,
	Vanity::VScene& HCOMMON_UNUSED_VAR( in_out_scene ),
	const TItemId HCOMMON_UNUSED_VAR( in_itemId )
	)
{
	GPlayerCharacter* pPlayerCharacter = HNULL;
	HCOMMON_NEW( pPlayerCharacter, GPlayerCharacter );
	if( HNULL == pPlayerCharacter )
	{
		return HNULL;
	}

	in_mementoAssign.MemberGet( "PlayerCharacter", *pPlayerCharacter );

	return pPlayerCharacter;
}

/**/
Hubris::HVOID GPlayerCharacter::GameObjectCollect(
	Envy::EMementoCollect& in_out_mementoCollect,
	const GPlayerCharacter& in_gameObject
	)
{
	in_out_mementoCollect.MemberAdd( "PlayerCharacter", in_gameObject );

	return;
}

///////////////////////////////////////////////////////
// implement VComponentGameDataBase
/**/
Hubris::HVOID GPlayerCharacter::Phase(
	Vanity::VScene& in_out_scene,
	const TItemId in_itemId,
	const Hubris::HSINT in_phaseIndex,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	switch( in_phaseIndex )
	{
	default:
		{
			break;
		}
	case 0:
		{
			PhaseZero(
				in_out_scene,
				in_itemId,
				in_sceneApplicationInterface
				);
			break;
		}
	case 1:
		{
			PhaseOne(
				in_out_scene,
				in_itemId,
				in_sceneApplicationInterface
				);
			break;
		}
	}

	return;
}

///////////////////////////////////////////////////////
// public methods
/**/

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID GPlayerCharacter::PhaseZero(
	Vanity::VScene& in_out_scene,
	const TItemId in_itemId,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	//work out force on game object. 
	// by input, camera direction, 
	const HVectorR3 inputMovementVector = LocalInputMovementVectorGet(
		in_out_scene,
		in_sceneApplicationInterface,
		m_playContolActive,
		m_inputIndex
		);

	const HREAL delta = in_sceneApplicationInterface.DeltaGet().LastDeltaGet();

	//input test, just move player on input
	PSphereR3 sphere = in_out_scene.ItemSphereGet( in_itemId );

	sphere.CenterSet( sphere.CenterGet() + ( inputMovementVector * ( delta * 20.0F ) ) ); //* in_sceneApplicationInterface.DeltaGet().LastDeltaGet() ) );
	in_out_scene.ItemPositionChange( in_itemId, sphere );

	//tilt?
	ComponentTiltGet().Update(
		delta,
		sphere.CenterGet()
		);

	in_out_scene.ItemRotateChange( in_itemId, ComponentTiltGet().RotationGet() );

	return;
}

/**/
Hubris::HVOID GPlayerCharacter::PhaseOne(
	Vanity::VScene& HCOMMON_UNUSED_VAR( in_out_scene ),
	const TItemId HCOMMON_UNUSED_VAR( in_itemId ),
	VSceneApplicationInterface& HCOMMON_UNUSED_VAR( in_sceneApplicationInterface )
	)
{
	return;
}

///////////////////////////////////////////////////////
// static public acessors
const Hubris::HCHAR* GPlayerCharacter::FactoryNameGet()
{
	return s_factoryName;
}

///////////////////////////////////////////////////////
// public acessors
/**/
const GComponentTilt& GPlayerCharacter::ComponentTiltGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentTilt, "invalid member" );
	return( *m_pComponentTilt );
}

/**/
GComponentTilt& GPlayerCharacter::ComponentTiltGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentTilt, "invalid member" );
	return( *m_pComponentTilt );
}

/**/