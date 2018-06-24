//file: Vanity/VScene/VSceneComponentNodeCollection.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VScene/VSceneComponentNodeCollection.h"

#include "Vanity/VScene/VSceneNode.h"

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
VSceneComponentNodeCollection::VSceneComponentNodeCollection( const VSceneComponentNodeCollection& in_src )
: m_arrayChildrenNodeIndex()
, m_combinedComponentFlag( 0 )
{
	( *this ) = in_src;
	return;
}

/**/
VSceneComponentNodeCollection::VSceneComponentNodeCollection()
: m_arrayChildrenNodeIndex()
, m_combinedComponentFlag( 0 )
{
	return;
}

/**/
VSceneComponentNodeCollection::~VSceneComponentNodeCollection()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VSceneComponentNodeCollection& VSceneComponentNodeCollection::operator=( const VSceneComponentNodeCollection& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayChildrenNodeIndex = in_rhs.m_arrayChildrenNodeIndex;
		m_combinedComponentFlag = in_rhs.m_combinedComponentFlag;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VSceneComponentNodeCollection::operator==( const VSceneComponentNodeCollection& in_rhs )
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayChildrenNodeIndex == in_rhs.m_arrayChildrenNodeIndex );
		match &= ( m_combinedComponentFlag == in_rhs.m_combinedComponentFlag );
	}


	return match;
}

/**/
const Hubris::HBOOL VSceneComponentNodeCollection::operator!=( const VSceneComponentNodeCollection& in_rhs )
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VSceneComponentNodeCollection::Clear()
{
	m_arrayChildrenNodeIndex.Clear();
	m_combinedComponentFlag = 0;
	return;
}

/**/
const Hubris::HBOOL VSceneComponentNodeCollection::NodeAdd( 
	const TArrayNode& in_arrayNodes,
	const Hubris::HSINT in_nodeIndex 
	)
{
	m_arrayChildrenNodeIndex.Insert( in_nodeIndex );

	const HSINT componentFlag = in_arrayNodes[ in_nodeIndex ].ComponentFlagGet();
	if( componentFlag == ( m_combinedComponentFlag & componentFlag ) )
	{
		return HFALSE;
	}

	const HBOOL change = ComponentFlagUpdate( in_arrayNodes );
	return change;
}

/**/
const Hubris::HBOOL VSceneComponentNodeCollection::NodeRemove( 
	const TArrayNode& in_arrayNodes,
	const Hubris::HSINT in_nodeIndex 
	)
{
	for( HSINT index = m_arrayChildrenNodeIndex.SizeGet() - 1; 0 <= index; --index )
	{
		if( in_nodeIndex == m_arrayChildrenNodeIndex[ index ] )
		{
			m_arrayChildrenNodeIndex.Remove( m_arrayChildrenNodeIndex.Begin() + index );
			break;
		}
	}

	const HBOOL change = ComponentFlagUpdate( in_arrayNodes );
	return change;
}

/**/
const Hubris::HBOOL VSceneComponentNodeCollection::ComponentFlagUpdate(
	const TArrayNode& in_arrayNodes
	)
{
	//m_combinedComponentFlag = 0;
	HSINT newFlag = 0;
	HCOMMON_FOR_EACH_CONST( index, m_arrayChildrenNodeIndex, TArraySint )
	{
		newFlag |= in_arrayNodes[ index ].ComponentFlagGet();
	}

	if( m_combinedComponentFlag == newFlag )
	{
		return HFALSE;
	}

	m_combinedComponentFlag = newFlag;

	return HTRUE;
}

/**/
