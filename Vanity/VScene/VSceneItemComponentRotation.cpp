//file: Vanity/VScene/VSceneItemComponentRotation.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneItemComponentRotation.h"

#include "Vanity/VScene/VSceneTrait.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

/**/
EMEMENTO_FACTORY_SOURCE( VSceneItemComponentRotation, VSceneItemComponentRotation );

///////////////////////////////////////////////////////
// creation
/**/
VSceneItemComponentRotation::VSceneItemComponentRotation(
	const VSceneItemComponentRotation& in_src
	)
: m_rotation()
, m_rotationMatrix()
, m_rotationMatrixInverted()
, m_dirtyMatrix( HTRUE )
, m_dirtyMatrixInverted( HTRUE )
{
	( *this ) = in_src;
	return;
}

/**/
VSceneItemComponentRotation::VSceneItemComponentRotation( 
	const Hubris::HQuaternionREAL& in_rotation
	)
: m_rotation( in_rotation )
, m_rotationMatrix()
, m_rotationMatrixInverted()
, m_dirtyMatrix( HTRUE )
, m_dirtyMatrixInverted( HTRUE )
{
	return;
}

/**/
VSceneItemComponentRotation::~VSceneItemComponentRotation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VSceneItemComponentRotation& VSceneItemComponentRotation::operator=( const VSceneItemComponentRotation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_rotation = in_rhs.m_rotation;
		m_rotationMatrix = in_rhs.m_rotationMatrix;
		m_rotationMatrixInverted = in_rhs.m_rotationMatrixInverted;
		m_dirtyMatrix = in_rhs.m_dirtyMatrix;
		m_dirtyMatrixInverted = in_rhs.m_dirtyMatrixInverted;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VSceneItemComponentRotation::operator==( const VSceneItemComponentRotation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_rotation == in_rhs.m_rotation );
		match &= ( m_rotationMatrix == in_rhs.m_rotationMatrix );
		match &= ( m_rotationMatrixInverted == in_rhs.m_rotationMatrixInverted );
		match &= ( m_dirtyMatrix == in_rhs.m_dirtyMatrix );
		match &= ( m_dirtyMatrixInverted == in_rhs.m_dirtyMatrixInverted );
	}

	return match;
}
/**/
const Hubris::HBOOL VSceneItemComponentRotation::operator!=( const VSceneItemComponentRotation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HVectorR3 VSceneItemComponentRotation::RotateVector( 
	const Hubris::HVectorR3& in_vector 
	)const
{
	return( in_vector * RotationMatrixGet() );
}

/**/
const Hubris::HVectorR3 VSceneItemComponentRotation::RotateVectorInverse( 
	const Hubris::HVectorR3& in_vector 
	)const
{
	return( in_vector * RotationMatrixInvertedGet() );
}

///////////////////////////////////////////////////////
// public accessors
/**/
HVOID VSceneItemComponentRotation::RotationSet( const Hubris::HQuaternionREAL& in_rotation )
{
	m_rotation = in_rotation;
	m_dirtyMatrix = HTRUE;
	m_dirtyMatrixInverted = HTRUE;

}

///////////////////////////////////////////////////////
// private accessors
/**/
const Hubris::HMatrixR3& VSceneItemComponentRotation::RotationMatrixGet()const
{
	if( HTRUE == m_dirtyMatrix )
	{
		m_dirtyMatrix = HFALSE;
		m_rotationMatrix = HQuaternionUtility::ConvertToMatrix3( m_rotation );
	}

	return m_rotationMatrix;
}

/**/
const Hubris::HMatrixR3& VSceneItemComponentRotation::RotationMatrixInvertedGet()const
{
	if( HTRUE == m_dirtyMatrixInverted )
	{
		m_dirtyMatrixInverted = HFALSE;
		m_rotationMatrixInverted = HMatrixUtility::Inverse( RotationMatrixGet() );
	}

	return m_rotationMatrixInverted;
}

/**/
