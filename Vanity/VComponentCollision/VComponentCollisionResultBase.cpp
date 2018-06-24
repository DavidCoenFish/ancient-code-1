//file: Vanity/VComponentCollision/VComponentCollisionResultBase.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionResultBase::VComponentCollisionResultBase( const VComponentCollisionResultBase& in_src )
: m_pBound( HNULL )
, m_pHull( HNULL )
, m_pSphere( HNULL )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentCollisionResultBase::VComponentCollisionResultBase()
: m_pBound( HNULL )
, m_pHull( HNULL )
, m_pSphere( HNULL )
{
	return;
}

/**/
VComponentCollisionResultBase::~VComponentCollisionResultBase()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentCollisionResultBase& VComponentCollisionResultBase::operator=( const VComponentCollisionResultBase& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_pBound = in_rhs.m_pBound;
		m_pHull = in_rhs.m_pHull;
		m_pSphere = in_rhs.m_pSphere;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentCollisionResultBase::operator==( const VComponentCollisionResultBase& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_pBound == in_rhs.m_pBound );
		match &= ( m_pHull == in_rhs.m_pHull );
		match &= ( m_pSphere == in_rhs.m_pSphere );
	}
	return match;
}

/**/
const Hubris::HBOOL VComponentCollisionResultBase::operator!=( const VComponentCollisionResultBase& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL VComponentCollisionResultBase::ValidGet()
{
	if( HNULL != m_pBound )
	{
		return HTRUE;
	}
	if( HNULL != m_pHull )
	{
		return HTRUE;
	}
	if( HNULL != m_pSphere )
	{
		return HTRUE;
	}
	return HFALSE;
}

/**/
const Hubris::HREAL VComponentCollisionResultBase::DistanceSquaredGet()
{
	if( HNULL != m_pBound )
	{
		return m_pBound->DistanceSquaredGet();
	}
	if( HNULL != m_pHull )
	{
		return m_pHull->DistanceSquaredGet();
	}
	if( HNULL != m_pSphere )
	{
		return m_pSphere->DistanceSquaredGet();
	}	

	return 0.0F;
}

/**/
const Hubris::HREAL VComponentCollisionResultBase::DistanceGet()
{
	if( HNULL != m_pBound )
	{
		return m_pBound->DistanceGet();
	}
	if( HNULL != m_pHull )
	{
		return m_pHull->DistanceGet();
	}
	if( HNULL != m_pSphere )
	{
		return m_pSphere->DistanceGet();
	}	

	return 0.0F;
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultBase::ContactPositionGet()
{
	if( HNULL != m_pBound )
	{
		return m_pBound->ContactPositionGet();
	}
	if( HNULL != m_pHull )
	{
		return m_pHull->ContactPositionGet();
	}
	if( HNULL != m_pSphere )
	{
		return m_pSphere->ContactPositionGet();
	}	

	return HTraitEmpty<HVectorR3>::EmptyGet();
}

/**/
const Hubris::HVectorR3& VComponentCollisionResultBase::ContactNormalGet()
{
	if( HNULL != m_pBound )
	{
		return m_pBound->ContactNormalGet();
	}
	if( HNULL != m_pHull )
	{
		return m_pHull->ContactNormalGet();
	}
	if( HNULL != m_pSphere )
	{
		return m_pSphere->ContactNormalGet();
	}	

	return HTraitEmpty<HVectorR3>::EmptyGet();
}

///////////////////////////////////////////////////////
// public accessors
/**/
Hubris::HVOID VComponentCollisionResultBase::PointerSetBound( VComponentCollisionResultBound* const in_pBound )
{
	m_pBound = in_pBound;
	m_pHull = HNULL;
	m_pSphere = HNULL;
	return;
}

/**/
Hubris::HVOID VComponentCollisionResultBase::PointerSetHull( VComponentCollisionResultHull* const in_pHull )
{
	m_pBound = HNULL;
	m_pHull = in_pHull;
	m_pSphere = HNULL;
	return;
}

/**/
Hubris::HVOID VComponentCollisionResultBase::PointerSetSphere( VComponentCollisionResultSphere* const in_pSphere )
{
	m_pBound = HNULL;
	m_pHull = HNULL;
	m_pSphere = in_pSphere;
	return;
}

/**/
