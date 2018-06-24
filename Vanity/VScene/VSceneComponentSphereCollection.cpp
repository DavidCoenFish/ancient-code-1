//file: Vanity/VScene/VSceneComponentSphereCollection.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneComponentSphereCollection.h"

#include "Vanity/VScene/VSceneNode.h"
#include "Vanity/VScene/VSceneComponentSphereTreeSphere.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< VSceneComponentSphereTreeSphere >TArraySphere;
typedef Hubris::HContainerArray< VSceneNode >TArrayNode;

///////////////////////////////////////////////////////
// creation
/**/
VSceneComponentSphereCollection::VSceneComponentSphereCollection( const VSceneComponentSphereCollection& in_src )
: m_arrayChildrenSphereIndex()
, m_combinedComponentFlag( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
VSceneComponentSphereCollection::VSceneComponentSphereCollection()
: m_arrayChildrenSphereIndex()
, m_combinedComponentFlag( 0 )
{
	return;
}

/**/
VSceneComponentSphereCollection::~VSceneComponentSphereCollection()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VSceneComponentSphereCollection& VSceneComponentSphereCollection::operator=( const VSceneComponentSphereCollection& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayChildrenSphereIndex = in_rhs.m_arrayChildrenSphereIndex;
		m_combinedComponentFlag = in_rhs.m_combinedComponentFlag;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VSceneComponentSphereCollection::operator==( const VSceneComponentSphereCollection& in_rhs )
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayChildrenSphereIndex == in_rhs.m_arrayChildrenSphereIndex );
		match &= ( m_combinedComponentFlag == in_rhs.m_combinedComponentFlag );
	}


	return match;
}

/**/
const Hubris::HBOOL VSceneComponentSphereCollection::operator!=( const VSceneComponentSphereCollection& in_rhs )
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
HVOID VSceneComponentSphereCollection::Clear()
{
	m_arrayChildrenSphereIndex.Clear();
	m_combinedComponentFlag = 0;
	return;
}

/**/
HVOID VSceneComponentSphereCollection::SphereAdd( const Hubris::HSINT in_sphereIndex )
{
	m_arrayChildrenSphereIndex.Insert( in_sphereIndex );
	return;
}

/**/
HVOID VSceneComponentSphereCollection::SphereRemove( const Hubris::HSINT in_sphereIndex )
{
	for( HSINT index = m_arrayChildrenSphereIndex.SizeGet() - 1; 0 <= index; --index )
	{
		if( in_sphereIndex == m_arrayChildrenSphereIndex[ index ] )
		{
			m_arrayChildrenSphereIndex.Remove( m_arrayChildrenSphereIndex.Begin() + index );
			return;
		}
	}

	return;
}

/**/
const Hubris::HSINT VSceneComponentSphereCollection::ParentSphereFind(
	const TArraySphere& in_arraySphere,
	const Pride::PSphereR3& in_sphereTest,
	Hubris::HREAL& in_out_bestRadius
	)const
{
	HSINT parentIndex = HCOMMON_INVALID_INDEX;
	//is sphere inside any out the child spheres
	HCOMMON_FOR_EACH_CONST( sphereIndex, m_arrayChildrenSphereIndex, TArraySint )
	{
		const PSphereR3& sphere = in_arraySphere[ sphereIndex ].SphereGet();
		if( HFALSE == PSphereUtility::SphereEqualOrInside( 
			sphere,
			in_sphereTest
			) )
		{
			continue;
		}

		const HREAL targetRadius = sphere.RadiusGet();
		if( in_out_bestRadius < targetRadius )
		{
			continue;
		}

		in_out_bestRadius = targetRadius;
		parentIndex = sphereIndex;

		const HSINT childParentIndex = in_arraySphere[ sphereIndex ].SphereCollectionGet().ParentSphereFind(
			in_arraySphere, 
			in_sphereTest,
			in_out_bestRadius
			);

		if( HCOMMON_INVALID_INDEX != childParentIndex )
		{
			parentIndex = childParentIndex;
		}
	}

	return parentIndex;
}

/**/
const Hubris::HBOOL VSceneComponentSphereCollection::ComponentFlagUpdate( 
	const TArraySphere& in_arraySphere
	)
{
	HSINT newFlag = 0;
	HCOMMON_FOR_EACH_CONST( index, m_arrayChildrenSphereIndex, TArraySint )
	{
		newFlag |= in_arraySphere[ index ].CombinedComponentFlagGet();
	}

	if( m_combinedComponentFlag == newFlag )
	{
		return HFALSE;
	}

	m_combinedComponentFlag = newFlag;

	return HTRUE;
}

/**/
