//file: Vanity/VScene/VSceneNode.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneNode.h"

#include "Vanity/VScene/VSceneItemComponentRotation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// creation
/**/
VSceneNode::VSceneNode( const VSceneNode& in_src )
: m_sphere()
, m_pRotation( HNULL )
, m_parentSphereIndex( HCOMMON_INVALID_INDEX )
, m_componentFlag( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
VSceneNode::VSceneNode(
	const Pride::PSphereR3 in_sphere,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HSINT in_parentSphereIndex,
	const Hubris::HQuaternionREAL* const in_pRotation
	)
: m_sphere()
, m_pRotation( HNULL )
, m_parentSphereIndex( HCOMMON_INVALID_INDEX )
, m_componentFlag( 0 )
{
	DataSet(
		in_sphere,
		in_componentFlag,
		in_parentSphereIndex,
		in_pRotation
		);
	return;
}

/**/
VSceneNode::VSceneNode()
: m_sphere()
, m_pRotation( HNULL )
, m_parentSphereIndex( HCOMMON_INVALID_INDEX )
, m_componentFlag( 0 )
{
	return;
}

/**/
VSceneNode::~VSceneNode()
{
	if( HNULL != m_pRotation )
	{
		HCOMMON_DELETE( 
			m_pRotation,
			VSceneItemComponentRotation
			);
	}
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VSceneNode& VSceneNode::operator=( const VSceneNode& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		const HQuaternionREAL* pRotation = HNULL;
		if( HTRUE == in_rhs.ComponentRotationTest() )
		{
			pRotation = &( in_rhs.ComponentRotationGet().RotationGet() );
		}

		DataSet(
			in_rhs.m_sphere,
			in_rhs.m_componentFlag,
			in_rhs.m_parentSphereIndex,
			pRotation
			);
	}

	return( *this );
}

/**/
const Hubris::HBOOL VSceneNode::operator==( const VSceneNode& in_rhs )
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_sphere == in_rhs.m_sphere );
		match &= ( m_componentFlag == in_rhs.m_componentFlag );
		match &= ( m_parentSphereIndex == in_rhs.m_parentSphereIndex );

		if( HTRUE == match )
		{
			if( ( HNULL != m_pRotation ) && 
				( HNULL != in_rhs.m_pRotation ) )
			{
				match &= ( ( *m_pRotation ) == ( *in_rhs.m_pRotation ) );
			}
			else
			{
				match &= ( m_pRotation == in_rhs.m_pRotation );
			}

		}
	}

	return match;
}

/**/
const Hubris::HBOOL VSceneNode::operator!=( const VSceneNode& in_rhs )
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VSceneNode::DataSet(
	const Pride::PSphereR3 in_sphere,
	const Hubris::HSINT in_componentFlag,
	const Hubris::HSINT in_parentSphereIndex,
	const Hubris::HQuaternionREAL* const in_pRotation
	)
{
	HCOMMON_ASSERT( 0 != in_componentFlag, "invalid param" );

	m_sphere = in_sphere;
	m_parentSphereIndex = in_parentSphereIndex;
	m_componentFlag = in_componentFlag;

	if( HNULL != in_pRotation )
	{
		if( HNULL == m_pRotation )
		{
			HCOMMON_NEW_PARAM( 
				m_pRotation,
				VSceneItemComponentRotation,
				( *in_pRotation )
				);
		}
		else
		{
			m_pRotation->RotationSet( *in_pRotation );
		}
	}
	else if( HNULL != m_pRotation )
	{
		HCOMMON_DELETE(
			m_pRotation,
			VSceneItemComponentRotation
			);
	}

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
HVOID VSceneNode::RotationSet( const Hubris::HQuaternionREAL& in_rotation )
{
	if( HNULL != m_pRotation )
	{
		m_pRotation->RotationSet( in_rotation );
	}

	return;
}

/**/
const Hubris::HBOOL VSceneNode::ComponentRotationTest()const
{
	return( HNULL != m_pRotation );
}

/**/
const VSceneItemComponentRotation& VSceneNode::ComponentRotationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pRotation, "invalid member" );
	return( *m_pRotation );
}

/**/
const Hubris::HBOOL VSceneNode::NodeInUseTest()const
{
	return( 0 != m_componentFlag );
}

/**/
HVOID VSceneNode::NodeNotInUseSet()
{
	m_componentFlag = 0;
	return;
}

/**/