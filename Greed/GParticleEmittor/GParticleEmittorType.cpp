//file: Greed/GParticleEmittor/GParticleEmittorType.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorType.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;

///////////////////////////////////////////////////////
// typedef
/**/
struct TParticleFlag
{
	enum TEnum
	{
		TNone				= 0x00,
		TCollisionBounce	= 0x01,
		TCollisionSplat		= 0x02,
		TBillboard			= 0x04, //use camera up and left
		TBillboardTree		= 0x08, //use unitZ axis for up, camera relative for left

		TMaskCollision		= TCollisionBounce | TCollisionSplat,
		TMaskBillboard		= TBillboard | TBillboardTree
	};
};

///////////////////////////////////////////////////////
// static local methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittorType::GParticleEmittorType( const GParticleEmittorType& in_src )
: m_uvType( HCOMMON_INVALID_INDEX )
, m_flowRate( 0.0F )
, m_flowRateRand( 0.0F )
, m_velocity()
, m_velocityRand()
, m_lifeSpan( 0.0F )
, m_lifeSpanRand( 0.0F )
, m_invertMass( 0.0F )
, m_invertMassRand( 0.0F )
, m_size( 0.0F )
, m_sizeRand( 0.0F )
, m_forceFlag( 0 )
, m_particleFlag( 0 )
, m_colour()
, m_colourRand()
, m_pAnimation( HNULL )
, m_colourStreamIndex( HCOMMON_INVALID_INDEX )
, m_sizeStreamIndex( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
GParticleEmittorType::GParticleEmittorType()
: m_uvType( HCOMMON_INVALID_INDEX )
, m_flowRate( 0.0F )
, m_flowRateRand( 0.0F )
, m_velocity()
, m_velocityRand()
, m_lifeSpan( 0.0F )
, m_lifeSpanRand( 0.0F )
, m_invertMass( 0.0F )
, m_invertMassRand( 0.0F )
, m_size( 0.0F )
, m_sizeRand( 0.0F )
, m_forceFlag( 0 )
, m_particleFlag( 0 )
, m_colour()
, m_colourRand()
, m_pAnimation( HNULL )
, m_colourStreamIndex( HCOMMON_INVALID_INDEX )
, m_sizeStreamIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
GParticleEmittorType::~GParticleEmittorType()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const GParticleEmittorType& GParticleEmittorType::operator=( const GParticleEmittorType& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_uvType = in_rhs.m_uvType;
		m_flowRate = in_rhs.m_flowRate;
		m_flowRateRand = in_rhs.m_flowRateRand;
		m_velocity = in_rhs.m_velocity;
		m_velocityRand = in_rhs.m_velocityRand;
		m_lifeSpan = in_rhs.m_lifeSpan;
		m_lifeSpanRand = in_rhs.m_lifeSpanRand;
		m_invertMass = in_rhs.m_invertMass;
		m_invertMassRand = in_rhs.m_invertMassRand;
		m_size = in_rhs.m_size;
		m_sizeRand = in_rhs.m_sizeRand;
		m_forceFlag = in_rhs.m_forceFlag;
		m_particleFlag = in_rhs.m_particleFlag;
		m_colour = in_rhs.m_colour;
		m_colourRand = in_rhs.m_colourRand;
		m_pAnimation = HSmartPointerUtility::Copy( in_rhs.m_pAnimation );
		//m_pAnimation = in_rhs.m_pAnimation;
		m_colourStreamIndex = in_rhs.m_colourStreamIndex;
		m_sizeStreamIndex = in_rhs.m_sizeStreamIndex;
	}
	return( *this );
}

/**/
const Hubris::HBOOL GParticleEmittorType::operator==( const GParticleEmittorType& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_uvType == in_rhs.m_uvType );
		match &= ( m_flowRate == in_rhs.m_flowRate );
		match &= ( m_flowRateRand == in_rhs.m_flowRateRand );
		match &= ( m_velocity == in_rhs.m_velocity );
		match &= ( m_velocityRand == in_rhs.m_velocityRand );
		match &= ( m_lifeSpan == in_rhs.m_lifeSpan );
		match &= ( m_lifeSpanRand == in_rhs.m_lifeSpanRand );
		match &= ( m_invertMass == in_rhs.m_invertMass );
		match &= ( m_invertMassRand == in_rhs.m_invertMassRand );
		match &= ( m_size == in_rhs.m_size );
		match &= ( m_sizeRand == in_rhs.m_sizeRand );
		match &= ( m_forceFlag == in_rhs.m_forceFlag );
		match &= ( m_particleFlag == in_rhs.m_particleFlag );
		match &= ( m_colour == in_rhs.m_colour );
		match &= ( m_colourRand == in_rhs.m_colourRand );
		match &= ( HTRUE == HSmartPointerUtility::Cmp( m_pAnimation, in_rhs.m_pAnimation ) );
		//match &= ( m_pAnimation == in_rhs.m_pAnimation );
		match &= ( m_colourStreamIndex == in_rhs.m_colourStreamIndex );
		match &= ( m_sizeStreamIndex == in_rhs.m_sizeStreamIndex );
	}
	return match;
}

/**/
const Hubris::HBOOL GParticleEmittorType::operator!=( const GParticleEmittorType& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID GParticleEmittorType::UpdateStreamIndex()
{
	m_colourStreamIndex = HCOMMON_INVALID_INDEX;
	m_sizeStreamIndex = HCOMMON_INVALID_INDEX;

	if( HNULL == m_pAnimation )
	{
		return;
	}

	m_colourStreamIndex = m_pAnimation->AnimationGet().StreamIndexGet( "m_colour" );
	m_sizeStreamIndex = m_pAnimation->AnimationGet().StreamIndexGet( "m_size" );

	return;
}

///////////////////////////////////////////////////////
// public acessors
/**/
const Hubris::HBOOL GParticleEmittorType::AnimationTest()const
{
	return( HNULL != m_pAnimation );
}

/**/
Hubris::HVOID GParticleEmittorType::AnimationSet( const Hubris::HBOOL in_hasAnimation )
{
	if( HTRUE == in_hasAnimation )
	{
		if( HNULL == m_pAnimation )
		{
			m_pAnimation.Create();
		}
	}
	else
	{
		if( HNULL != m_pAnimation )
		{
			m_pAnimation = HNULL;
		}
	}

	return;
}

/**/
const Vanity::VAnimation& GParticleEmittorType::AnimationGet()const
{
	return( m_pAnimation->AnimationGet() );
}

/**/
Vanity::VAnimation& GParticleEmittorType::AnimationGet()
{
	return( m_pAnimation->AnimationGet() );
}

///////////////////////////////////////////////////////
// static public acessors
/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagCollisionBounceGet()
{
	return TParticleFlag::TCollisionBounce;
}

/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagCollisionSplatGet()
{
	return TParticleFlag::TCollisionSplat;
}

/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagBillboardGet()
{
	return TParticleFlag::TBillboard;
}

/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagBillboardTreeGet()
{
	return TParticleFlag::TBillboardTree;
}

/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagMaskCollisionGet()
{
	return TParticleFlag::TMaskCollision;
}

/**/
const Hubris::HSINT GParticleEmittorType::ParticleFlagMaskBillboardGet()
{
	return TParticleFlag::TMaskBillboard;
}

/**/
