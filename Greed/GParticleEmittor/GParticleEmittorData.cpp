//file: Greed/GParticleEmittor/GParticleEmittorData.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GParticleEmittor/GParticleEmittorData.h"

#include "Greed/GParticleEmittor/GParticleEmittorType.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Greed;
using namespace Lust;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Hubris::HVectorR3, Hubris::HVectorR3 >TPairVectorVector;

///////////////////////////////////////////////////////
// local static variables
/**/
static const HCHAR* const s_animationStreamNameColour = "m_colour";
static const HCHAR* const s_animationStreamNameSize = "m_size";

struct TFlag
{
	enum TEnum
	{
		TNone				= 0x00,
		TStationaryPosition	= 0x01, // if the particle is stationary, the default is moving
		TStationaryRotation	= 0x02 // if the particle is stationary, disable billboard
		//TUseLocalDirection	= 0x02 //use the data member at and right for particle orientation
	};
};

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalColourRandGet( 
	PColourRgba& in_out_colour,							  
	const PColourRgba& in_range 
	)
{
	if( in_range == PColourRgba() )
	{
		return;
	}

	const PColourRealRgba rangeReal = PColourConvertor::RgbaToRgba( in_range );
	PColourRealRgba colourReal = PColourConvertor::RgbaToRgba( in_out_colour );

	colourReal.RedSet( colourReal.RedGet() + HMathRandom::RandomValuePlusMinusGet( rangeReal.RedGet() ) );
	colourReal.GreenSet( colourReal.GreenGet() + HMathRandom::RandomValuePlusMinusGet( rangeReal.GreenGet() ) );
	colourReal.BlueSet( colourReal.BlueGet() + HMathRandom::RandomValuePlusMinusGet( rangeReal.BlueGet() ) );
	colourReal.OpacitySet( colourReal.OpacityGet() + HMathRandom::RandomValuePlusMinusGet( rangeReal.OpacityGet() ) );

	in_out_colour = PColourConvertor::RgbaToRgba( colourReal );

	return;
}

/**/
static Hubris::HVOID LocalCollisionTestParticle(
	Hubris::HSINT& in_out_flag,
	Hubris::HVectorR3& out_up,
	Hubris::HVectorR3& out_right,
	Lust::LTranslationComponent& in_out_translationComponent,
	const Hubris::HVectorR3& in_oldPosition,
	Lust::LTranslationComponentVelocity& in_out_translationComponentVelocity,
	const Hubris::HSINT in_particleFlag,
	Vanity::VScene& in_out_scene,
	const Hubris::HREAL in_delta,
	const Hubris::HREAL in_size,
	const HSINT in_depthProtect = 0
	)
{
	//can not assuem stationary if velocity is zero, reached top point of arch
	//if( HTRUE == HMathUtility::EpsilonZero( in_out_translationComponentVelocity.VelocityGet()

	PLineR3 ray;
	HREAL rayLength;
	if( HFALSE == PLineUtility::LineConstruct( 
		ray,
		in_oldPosition,
		in_out_translationComponent.TranslationGet(),
		&rayLength
		) )
	{
		//could not make a valid line, ie, no movement
		return;
	}

	VComponentCollisionResultBase collisionResult;
	if( HFALSE == VSceneUtility::CollideRay(
		collisionResult,
		in_out_scene,
		ray,
		rayLength
		) )
	{
		return;
	}

	if( ( GParticleEmittorType::ParticleFlagCollisionSplatGet() & in_particleFlag ) ||
		( 4 < in_depthProtect ) ) //inf loop protect on bounce recusion
	{
		in_out_flag |= ( TFlag::TStationaryPosition | TFlag::TStationaryRotation );
		in_out_translationComponent.TranslationGet() = collisionResult.ContactPositionGet() + ( collisionResult.ContactNormalGet() * ( 0.5F * in_size ) );
		out_right = HMatrixUtility::CrossVector( collisionResult.ContactNormalGet() );
		out_up = HMatrixUtility::CrossProduct( collisionResult.ContactNormalGet(), out_right );
	}
	else if( GParticleEmittorType::ParticleFlagCollisionBounceGet() & in_particleFlag )
	{
		const HVectorR3 localOldPosition = collisionResult.ContactPositionGet();
		in_out_translationComponentVelocity.VelocityGet() = ( HMatrixUtility::Reflect( collisionResult.ContactNormalGet(), in_out_translationComponentVelocity.VelocityGet() ) ) * ( -0.75F );

		const HREAL ratio = collisionResult.DistanceGet() / rayLength;
		const HREAL localDelta = ratio * in_delta;
		in_out_translationComponent.TranslationGet() = localOldPosition + ( in_out_translationComponentVelocity.VelocityGet() * localDelta );
		//in_out_translationComponent.ApplyVelocity( in_out_translationComponentVelocity, in_delta );

		LocalCollisionTestParticle(
			in_out_flag,
			out_up,
			out_right,
			in_out_translationComponent,
			localOldPosition,
			in_out_translationComponentVelocity,
			in_particleFlag,
			in_out_scene,
			localDelta,
			in_size,
			in_depthProtect + 1
			);
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
GParticleEmittorData::GParticleEmittorData( const GParticleEmittorData& in_src )
: m_translationComponentVelocity()
, m_translationComponent()
, m_massInvert( 0.0F )
, m_size( 0.0F )
, m_colour()
, m_particleLifespan( 0.0F )
, m_particleAge( 0.0F )
, m_particleType( HCOMMON_INVALID_INDEX )
, m_colourIndexHint( HCOMMON_INVALID_INDEX )
, m_sizeIndexHint( HCOMMON_INVALID_INDEX )
, m_flag( 0 )
, m_up()
, m_right()
{
	( *this ) = in_src;
	return;
}

/**/
GParticleEmittorData::GParticleEmittorData()
: m_translationComponentVelocity()
, m_translationComponent()
, m_massInvert( 0.0F )
, m_size( 0.0F )
, m_colour()
, m_particleLifespan( 0.0F )
, m_particleAge( 0.0F )
, m_particleType( HCOMMON_INVALID_INDEX )
, m_colourIndexHint( HCOMMON_INVALID_INDEX )
, m_sizeIndexHint( HCOMMON_INVALID_INDEX )
, m_flag( 0 )
, m_up()
, m_right()
{
	return;
}

/**/
GParticleEmittorData::~GParticleEmittorData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const GParticleEmittorData& GParticleEmittorData::operator=( const GParticleEmittorData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_translationComponentVelocity = in_rhs.m_translationComponentVelocity;
		m_translationComponent = in_rhs.m_translationComponent;
		m_massInvert = in_rhs.m_massInvert;
		m_size = in_rhs.m_size;
		m_colour = in_rhs.m_colour;
		m_particleLifespan = in_rhs.m_particleLifespan;
		m_particleAge = in_rhs.m_particleAge;
		m_particleType = in_rhs.m_particleType;
		m_colourIndexHint = in_rhs.m_colourIndexHint;
		m_sizeIndexHint = in_rhs.m_sizeIndexHint;
		m_flag = in_rhs.m_flag;
		m_up = in_rhs.m_up;
		m_right = in_rhs.m_right;
	}

	return( *this );
}

/**/
const Hubris::HBOOL GParticleEmittorData::operator==( const GParticleEmittorData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_translationComponentVelocity == in_rhs.m_translationComponentVelocity );
		match &= ( m_translationComponent == in_rhs.m_translationComponent );
		match &= ( m_massInvert == in_rhs.m_massInvert );
		match &= ( m_size == in_rhs.m_size );
		match &= ( m_colour == in_rhs.m_colour );
		match &= ( m_particleLifespan == in_rhs.m_particleLifespan );
		match &= ( m_particleAge == in_rhs.m_particleAge );
		match &= ( m_particleType == in_rhs.m_particleType );
		match &= ( m_colourIndexHint == in_rhs.m_colourIndexHint );
		match &= ( m_sizeIndexHint == in_rhs.m_sizeIndexHint );
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_up == in_rhs.m_up );
		match &= ( m_right == in_rhs.m_right );
	}

	return match;
}

/**/
const Hubris::HBOOL GParticleEmittorData::operator!=( const GParticleEmittorData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public acessors
/**/
Hubris::HVOID GParticleEmittorData::InitialiseParticle(
	const Hubris::HVectorR3& in_velocity,
	const Hubris::HVectorR3& in_position,
	const Hubris::HSINT in_particleType,
	const Hubris::HREAL in_particleAge,
	const GParticleEmittorType& in_typeData
	)
{
	m_translationComponentVelocity.VelocityGet() = in_velocity;
	m_translationComponent.TranslationGet() = in_position;
	m_particleType = in_particleType;
	m_flag = 0;
	//some default values, incase no billboard or direction set
	m_up = HMatrixConstructor::HVectorR3AxisZ();
	m_right = HMatrixConstructor::HVectorR3AxisX();

	m_particleAge = in_particleAge;
	if( 0.0F < m_particleAge )
	{
		//you know, this means that collision will not be tested for the start of movement
		// but collision is not tested for emition point
		m_translationComponent.TranslationGet() += ( in_velocity * m_particleAge );
	}

	m_massInvert = in_typeData.InvertMassGet() + HMathRandom::RandomValuePlusMinusGet( in_typeData.InvertMassRandGet() );
	m_size = in_typeData.SizeGet() + HMathRandom::RandomValuePlusMinusGet( in_typeData.SizeRandGet() );
	m_particleLifespan = in_typeData.LifeSpanGet() + HMathRandom::RandomValuePlusMinusGet( in_typeData.LifeSpanRandGet() );
	m_colour = in_typeData.ColourGet();
	LocalColourRandGet( m_colour, in_typeData.ColourRandGet() );

	m_colourIndexHint = HCOMMON_INVALID_INDEX;
	m_sizeIndexHint = HCOMMON_INVALID_INDEX;

	return;
}

/**/
const Hubris::HBOOL GParticleEmittorData::Tick(
	const Sloth::SComponentDelta& in_delta
	)
{
	m_particleAge += in_delta.LastDeltaGet();
	//check particle active
	if( m_particleLifespan <= m_particleAge )
	{
		return HFALSE;
	}

	return HTRUE;
}

/**
const Hubris::HBOOL GParticleEmittorData::ActiveGet()const
{
	return( m_particleAge < m_particleLifespan );
}

/**/
Hubris::HVOID GParticleEmittorData::DeactiveSet()
{
	m_particleLifespan = 0.0F;
	m_particleAge = 0.0F;
	return;
}

/**/
Hubris::HVOID GParticleEmittorData::UpdatePosition(
	Vanity::VScene& in_out_scene,
	const Sloth::SComponentDelta& in_delta,
	const GParticleEmittorType& in_particleType,
	const Hubris::HVectorR3& in_cameraVectorUp,
	const Hubris::HVectorR3& in_cameraVectorRight
	)
{
	const HSINT particleFlag = in_particleType.ParticleFlagGet();

	if( 0 == ( m_flag & TFlag::TStationaryPosition ) )
	{
		//collect force sum
		LTranslationComponentForceSum forceSum;
		VSceneUtility::SampleForce(
			forceSum.ForceSumGet(),
			in_out_scene,
			in_particleType.ForceFlagGet(),
			m_translationComponent.TranslationGet(),
			m_massInvert
			);

		//apply force sum to particle
		m_translationComponentVelocity.ApplyForceSum(
			forceSum,
			in_delta,
			m_massInvert
			);

		HVectorR3 oldPosition = m_translationComponent.TranslationGet();

		m_translationComponent.ApplyVelocity(
			m_translationComponentVelocity,
			in_delta
			);

		//collision test
		if( in_particleType.ParticleFlagGet() & ( GParticleEmittorType::ParticleFlagCollisionBounceGet() | GParticleEmittorType::ParticleFlagCollisionSplatGet() ) )
		{
			LocalCollisionTestParticle(
				m_flag,
				m_up,
				m_right,
				m_translationComponent,
				oldPosition,
				m_translationComponentVelocity,
				in_particleType.ParticleFlagGet(),
				in_out_scene,
				in_delta.LastDeltaGet(),
				m_size
				);
		}
	}

	// colision could result in stationary particle, so bail before updating direction
	if( 0 == ( m_flag & TFlag::TStationaryRotation ) )
	{
		//direction
		if( particleFlag & GParticleEmittorType::ParticleFlagBillboardGet() )
		{
			m_up = in_cameraVectorUp;
			m_right = in_cameraVectorRight;
		}
	}

	return;
}

/**/
Hubris::HVOID GParticleEmittorData::WriteOutValues(
	Vanity::VComponentVisualAssetParticleData& out_data,
	const GParticleEmittorType& in_typeData,
	const Hubris::HMatrixR4& in_modelMatrixInvert
	)
{
	//values from data
	out_data.PositionSet( HMatrixUtility::VectorProduct( in_modelMatrixInvert, m_translationComponent.TranslationGet() ) );
	out_data.TypeIndexSet( in_typeData.UvTypeGet() );
	out_data.VectorRightSet( m_right );
	out_data.VectorUpSet( m_up );

	//values that can be animated
	HREAL size = m_size;
	PColourRgba colour = m_colour;

	if( HTRUE == in_typeData.AnimationTest() )
	{
		const VAnimation& animation = in_typeData.AnimationGet();
		const HSINT colourStreamIndex = in_typeData.ColourStreamIndexGet();
		const HSINT sizeStreamIndex = in_typeData.SizeStreamIndexGet();

		if( HCOMMON_INVALID_INDEX != colourStreamIndex )
		{
			HVectorR4 vectorValue;
			animation.SampleValue(
				m_particleAge / m_particleLifespan,
				1.0F,
				colourStreamIndex,
				vectorValue,
				m_colourIndexHint
				);
			PColourRealRgba colourReal;
			colourReal.DataSet( vectorValue );
			colour = PColourConvertor::RgbaToRgba( colourReal );
		}

		if( HCOMMON_INVALID_INDEX != sizeStreamIndex )
		{
			animation.SampleValue(
				m_particleAge / m_particleLifespan,
				1.0F,
				sizeStreamIndex,
				size,
				m_sizeIndexHint
				);
		}
	}

	out_data.ColourSet( colour );
	out_data.SizeSet( size );

	return;
}

/**/
