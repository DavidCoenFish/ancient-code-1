//file: Sloth/SComponent/SComponentCameraTargetDistanceKeyData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SComponent/SComponentCameraTargetDistanceKeyData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SComponentCameraTargetDistanceKeyData::SComponentCameraTargetDistanceKeyData( const SComponentCameraTargetDistanceKeyData& in_src )
: m_distance( 0.0F )
, m_targetElevation( 0.0F )
, m_cameraElevation( 0.0F )
, m_projectionTime( 0.0F )
{
	( *this ) = in_src;
	return;
}

/**/
SComponentCameraTargetDistanceKeyData::SComponentCameraTargetDistanceKeyData(
	const Hubris::HREAL in_distance,
	const Hubris::HREAL in_targetElevation,
	const Hubris::HREAL in_cameraElevation,
	const Hubris::HREAL in_projectionTime
	)
: m_distance( in_distance )
, m_targetElevation( in_targetElevation )
, m_cameraElevation( in_cameraElevation )
, m_projectionTime( in_projectionTime )
{
	return;
}

/**/
SComponentCameraTargetDistanceKeyData::SComponentCameraTargetDistanceKeyData()
: m_distance( 0.0F )
, m_targetElevation( 0.0F )
, m_cameraElevation( 0.0F )
, m_projectionTime( 0.0F )
{
	return;
}

/**/
SComponentCameraTargetDistanceKeyData::~SComponentCameraTargetDistanceKeyData()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SComponentCameraTargetDistanceKeyData& SComponentCameraTargetDistanceKeyData::operator=( const SComponentCameraTargetDistanceKeyData& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_distance = in_rhs.m_distance;
		m_targetElevation = in_rhs.m_targetElevation;
		m_cameraElevation = in_rhs.m_cameraElevation;
		m_projectionTime = in_rhs.m_projectionTime;
	}

	return( *this );
}

/**/
const Hubris::HBOOL SComponentCameraTargetDistanceKeyData::operator==( const SComponentCameraTargetDistanceKeyData& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_distance == in_rhs.m_distance );
		match &= ( m_targetElevation == in_rhs.m_targetElevation );
		match &= ( m_cameraElevation == in_rhs.m_cameraElevation );
		match &= ( m_projectionTime == in_rhs.m_projectionTime );
	}

	return match;
}

/**/
const Hubris::HBOOL SComponentCameraTargetDistanceKeyData::operator!=( const SComponentCameraTargetDistanceKeyData& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
