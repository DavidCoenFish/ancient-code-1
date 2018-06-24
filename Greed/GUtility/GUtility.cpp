//file: Greed/GUtility/GUtility.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GUtility/GUtility.h"

#include "Greed/GParticleEmittor/GParticleEmittor_Export.h"
#include "Greed/GPlayerCharacter/GPlayerCharacter_Export.h"

#include< Vanity/VScene/VScene_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID Greed::GUtility::RegisterGameObjectFactory(
	Vanity::VScene& in_out_scene
	)
{
	if( 0 == ( VScene::FlagComponentGameGet() & in_out_scene.ComponentFlagGet() ) )
	{
		return;
	}

	in_out_scene.InterfaceObjectGameGet().FactoryGameObjectCreateRegister( 
		GParticleEmittor::FactoryNameGet(),
		&GParticleEmittor::FactoryGameObjectCreate
		);
	in_out_scene.InterfaceObjectGameGet().FactoryGameObjectCreateRegister( 
		GPlayerCharacter::FactoryNameGet(),
		&GPlayerCharacter::FactoryGameObjectCreate
		);

	return;
}

/**/
