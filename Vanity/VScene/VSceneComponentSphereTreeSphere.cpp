//file: Vanity/VScene/VSceneComponentSphereTreeSphere.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"

#include "Vanity/VScene/VSceneNode.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VSceneComponentSphereTreeSphere::VSceneComponentSphereTreeSphere( const VSceneComponentSphereTreeSphere& in_src )
: m_sphere()
, m_parentSphereIndex( HCOMMON_INVALID_INDEX )
, m_nodeCollection()
, m_sphereCollection()
{
	( *this ) = in_src;
	return;
}

/**/
VSceneComponentSphereTreeSphere::VSceneComponentSphereTreeSphere(
	const Pride::PSphereR3& in_sphere,
	const Hubris::HSINT in_parentSphereIndex
	)
: m_sphere( in_sphere )
, m_parentSphereIndex( in_parentSphereIndex )
, m_nodeCollection()
, m_sphereCollection()
{
	return;
}

/**/
VSceneComponentSphereTreeSphere::VSceneComponentSphereTreeSphere()
: m_sphere()
, m_parentSphereIndex( HCOMMON_INVALID_INDEX )
, m_nodeCollection()
, m_sphereCollection()
{
	return;
}

/**/
VSceneComponentSphereTreeSphere::~VSceneComponentSphereTreeSphere()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VSceneComponentSphereTreeSphere& VSceneComponentSphereTreeSphere::operator=( const VSceneComponentSphereTreeSphere& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_sphere = in_rhs.m_sphere;
		m_parentSphereIndex = in_rhs.m_parentSphereIndex; 
		m_nodeCollection = in_rhs.m_nodeCollection; 
		m_sphereCollection = in_rhs.m_sphereCollection;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VSceneComponentSphereTreeSphere::operator==( const VSceneComponentSphereTreeSphere& in_rhs )
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_sphere == in_rhs.m_sphere );
		match &= ( m_parentSphereIndex == in_rhs.m_parentSphereIndex ); 
		match &= ( m_nodeCollection == in_rhs.m_nodeCollection ); 
		match &= ( m_sphereCollection == in_rhs.m_sphereCollection );
	}

	return match;
}
/**/
const Hubris::HBOOL VSceneComponentSphereTreeSphere::operator!=( const VSceneComponentSphereTreeSphere& in_rhs )
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VSceneComponentSphereTreeSphere::SphereAdd( 
	const Hubris::HSINT in_sphereIndex
	)
{
	m_sphereCollection.SphereAdd( in_sphereIndex );
	return;
}

/**/
const Hubris::HBOOL VSceneComponentSphereTreeSphere::NodeAdd( 
	const TArrayNode& in_arrayNodes,
	const Hubris::HSINT in_nodeIndex 
	)
{
	const HBOOL change = m_nodeCollection.NodeAdd( in_arrayNodes, in_nodeIndex );
	return change;
}

/**/
const Hubris::HBOOL VSceneComponentSphereTreeSphere::NodeRemove( 
	const TArrayNode& in_arrayNodes,
	const Hubris::HSINT in_nodeIndex 
	)
{
	const HBOOL change = m_nodeCollection.NodeRemove( in_arrayNodes, in_nodeIndex );
	return change;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT VSceneComponentSphereTreeSphere::CombinedComponentFlagGet()const
{
	const HSINT flag = m_nodeCollection.CombinedComponentFlagGet() | m_sphereCollection.CombinedComponentFlagGet();

	return flag;
}

/**/
