//file: Greed/GParticleEmittor/GParticleEmittorStateDataExchange.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorStateDataExchange.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittorStateDataExchange::GParticleEmittorStateDataExchange(
	GParticleEmittor& in_out_particleEmittor,
	const Sloth::SComponentDelta& in_delta,
	const Hubris::HMatrixR4& in_matrixEmittor
	)
: m_particleEmittor( in_out_particleEmittor )
, m_delta( in_delta )
, m_matrixEmittor( in_matrixEmittor )
{
	return;
}

/**/
GParticleEmittorStateDataExchange::~GParticleEmittorStateDataExchange()
{
	return;
}

/**/
