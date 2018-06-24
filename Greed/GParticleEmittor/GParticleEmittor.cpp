//file: Greed/GParticleEmittor/GParticleEmittor.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittor.h"

#include "Greed/GParticleEmittor/GParticleEmittorAnimationVisitor.h"
#include "Greed/GParticleEmittor/GParticleEmittorStateDataExchange.h"

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
static const HCHAR* const s_factoryName = "GParticleEmittor";
static const HCHAR* const s_eventTick = "tick";
static const HCHAR* const s_eventEmit = "emit";

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentVisualAssetParticleData >TArrayParticleData;
typedef Hubris::HContainerPair< Hubris::HVectorR3, Hubris::HVectorR3 >TPairVectorVector;

struct TAnimationValueEnum
{
	enum TEnum
	{
		TCurrentState = 0,

		TCount
	};
};

struct TAnimationValueEnumEmittorShape
{
	enum TEnum
	{
		TUnitVector = 0,
		TScale
	};
};

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittor::GParticleEmittor()
: m_stateMachine()
, m_arrayPendingStateName()
, m_emittorShape()
, m_arrayType()
, m_arrayData()
, m_activeData()
, m_pComponentAnimation( HNULL )
{
	return;
}

/**/
GParticleEmittor::~GParticleEmittor()
{
	return;
}
///////////////////////////////////////////////////////
// static public method
/**/
Vanity::VComponentGameDataBase* const GParticleEmittor::FactoryGameObjectCreate(
	const Envy::EMementoAssign& in_mementoAssign,
	Vanity::VScene& HCOMMON_UNUSED_VAR( in_out_scene ),
	const TItemId HCOMMON_UNUSED_VAR( in_itemId )
	)
{
	GParticleEmittor* pEmittor = HNULL;
	HCOMMON_NEW( pEmittor, GParticleEmittor );
	if( HNULL == pEmittor )
	{
		return HNULL;
	}

	in_mementoAssign.MemberGet( "ParticleEmittor", *pEmittor );

	return pEmittor;
}

/**/
Hubris::HVOID GParticleEmittor::GameObjectCollect(
	Envy::EMementoCollect& in_out_mementoCollect,
	const GParticleEmittor& in_gameObject
	)
{
	in_out_mementoCollect.MemberAdd( "ParticleEmittor", in_gameObject );

	return;
}

///////////////////////////////////////////////////////
// implement VComponentGameDataBase
/**/
Hubris::HVOID GParticleEmittor::Phase(
	Vanity::VScene& in_out_scene,
	const TItemId in_itemId,
	const Hubris::HSINT in_phaseIndex,
	Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
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
Hubris::HVOID GParticleEmittor::AnimationValueSet(
	Vanity::VScene& in_out_scene,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_animatedValue
	)
{
	//TODO
	in_out_scene;
	in_gameObjectVarId;
	in_animatedValue;
	return;
}

/**/
Hubris::HVOID GParticleEmittor::AnimationValueSet(
	Vanity::VScene& in_out_scene,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HREAL in_animatedValue
	)
{
	//TODO
	in_out_scene;
	in_gameObjectVarId;
	in_animatedValue;
	return;
}

/**/
Hubris::HVOID GParticleEmittor::AnimationValueSet(
	Vanity::VScene& in_out_scene,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR2& in_animatedValue
	)
{
	//TODO
	in_out_scene;
	in_gameObjectVarId;
	in_animatedValue;
	return;
}

/**/
Hubris::HVOID GParticleEmittor::AnimationValueSet(
	Vanity::VScene& in_out_scene,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR3& in_animatedValue
	)
{
	//TODO
	in_out_scene;
	in_gameObjectVarId;
	in_animatedValue;
	return;
}

/**/
Hubris::HVOID GParticleEmittor::AnimationValueSet(
	Vanity::VScene& in_out_scene,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR4& in_animatedValue
	)
{
	//TODO
	in_out_scene;
	in_gameObjectVarId;
	in_animatedValue;
	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID GParticleEmittor::PhaseZero(
	Vanity::VScene& in_out_scene,
	const TItemId HCOMMON_UNUSED_VAR( in_itemId ),
	Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	const Sloth::SComponentDelta& delta = in_sceneApplicationInterface.DeltaGet();
	GParticleEmittorStateDataExchange dataExchange( *this, delta, HMatrixUtility::IdentityGet< HMatrixR4 >() );

	m_stateMachine.SubmitEvent( 
		StateSubmitEventNameGetTick(),
		dataExchange
		);

	if( 0 < m_arrayPendingStateName.SizeGet() )
	{
		const TArrayString activationState( m_arrayPendingStateName );
		m_arrayPendingStateName.Clear();
		HCOMMON_FOR_EACH_CONST( name, activationState, TArrayString )
		{
			m_stateMachine.StateActiveSet( name, HTRUE, dataExchange );
		}
	}

	if( HNULL == m_pComponentAnimation )
	{
		return;
	}

	m_pComponentAnimation->Tick( delta );

	GParticleEmittorAnimationVisitor animationVisitor(
		*this,
		in_out_scene
		);

	m_pComponentAnimation->Update(
		animationVisitor
		);

	return;
}
/**/
Hubris::HVOID GParticleEmittor::PhaseOne(
	Vanity::VScene& in_out_scene,
	const TItemId in_itemId,
	Vanity::VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	//get location of item
	Hubris::HMatrixR4 modelMatrix; //for putting particles into world space
	Hubris::HMatrixR4 modelMatrixInvert; //for getting particles from worldspace into visual item space
	VSceneUtility::ItemMatrixGet(
		modelMatrix,
		modelMatrixInvert,
		in_out_scene,
		in_itemId
		);

	//emit new partices
	const Sloth::SComponentDelta& delta = in_sceneApplicationInterface.DeltaGet();
	GParticleEmittorStateDataExchange dataExchange( *this, delta, modelMatrix );
	m_stateMachine.SubmitEvent( 
		s_eventEmit,
		dataExchange
		);

	//update visuals
	TArrayParticleData* pArrayParticleData = HNULL;
	HSINT maxParticleVisual = 0;
	VComponentVisualInterfaceObject interfaceVisual = in_out_scene.InterfaceObjectVisualGet();
	interfaceVisual.ParticleDataLock(
		in_itemId,
		maxParticleVisual,
		pArrayParticleData
		);
	if( HNULL == pArrayParticleData )
	{
		return;
	}
	//think i need to do this....
	pArrayParticleData->SizeResize( 0 );

	const Hubris::HVectorR3& cameraVectorUp = in_out_scene.CameraVectorUpGet();
	const Hubris::HVectorR3& cameraVectorRight = in_out_scene.CameraVectorRightGet(); 

	//apply delta to partices~ collision forces, mark as dead
	HSINT activeCount = 0;
	for( HSINT index = 0; index < m_arrayData.SizeGet(); ++index )
	{
		if( HFALSE == m_activeData.ResourceIdValid( index ) )
		{
			continue;
		}

		GParticleEmittorData& data = m_arrayData[ index ];
		if( HFALSE == data.Tick( delta ) )
		{
			m_activeData.ResourceIdRelease( index );
			continue;
		}

		const HSINT typeIndex = data.ParticleTypeGet();
		const GParticleEmittorType& particleType = m_arrayType[ typeIndex ];
		data.UpdatePosition(
			in_out_scene,
			delta,
			particleType,
			cameraVectorUp,
			cameraVectorRight
			);

		//only display if allowed...
		if( maxParticleVisual <= activeCount )
		{
			continue;
		}

		if( pArrayParticleData->SizeGet() <= activeCount )
		{
			pArrayParticleData->SizeResize( activeCount + 1 );
		}

		data.WriteOutValues(
			( *pArrayParticleData )[ activeCount ],
			particleType,
			modelMatrixInvert
			);

		activeCount += 1;
	}

	interfaceVisual.ParticleDataUnlock(
		in_itemId
		);

	return;
}

///////////////////////////////////////////////////////
// static public acessors
const Hubris::HCHAR* GParticleEmittor::FactoryNameGet()
{
	return s_factoryName;
}

/**/
const Hubris::HCHAR* GParticleEmittor::StateSubmitEventNameGetTick()
{
	return s_eventTick;
}

/**/
const Hubris::HCHAR* GParticleEmittor::StateSubmitEventNameGetEmit()
{
	return s_eventEmit;
}

///////////////////////////////////////////////////////
// public acessors
/**/
const Hubris::HSINT GParticleEmittor::MaximumParticleCountGet()const
{
	return m_arrayData.SizeGet();
}

/**/
Hubris::HVOID GParticleEmittor::MaximumParticleCountSet( const Hubris::HSINT in_maximumParticleCount )
{
	m_arrayData.SizeResize( in_maximumParticleCount );
	m_activeData.MaximumResourceValueSet( in_maximumParticleCount );
	return;
}

/**/