//file: Vanity/VComponentDynamic/VComponentDynamicComponentParam.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicComponentParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

///////////////////////////////////////////////////////
// creation
/**/
VComponentDynamicComponentParam::VComponentDynamicComponentParam( const VComponentDynamicComponentParam& in_src )
: m_staticFriction( 0.0F )
, m_movingFriction( 0.0F )
, m_elasticCollisionDampen( 0.0F )
{
	( *this ) = in_src;
	return;
}

/**/
VComponentDynamicComponentParam::VComponentDynamicComponentParam(
	const Hubris::HREAL in_staticFriction,
	const Hubris::HREAL in_movingFriction,
	const Hubris::HREAL in_elasticCollisionDampen
	)
: m_staticFriction( in_staticFriction )
, m_movingFriction( in_movingFriction )
, m_elasticCollisionDampen( in_elasticCollisionDampen )
{
	return;
}

/**/
VComponentDynamicComponentParam::VComponentDynamicComponentParam()
: m_staticFriction( 0.0F )
, m_movingFriction( 0.0F )
, m_elasticCollisionDampen( 0.0F )
{
	return;
}

/**/
VComponentDynamicComponentParam::~VComponentDynamicComponentParam()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VComponentDynamicComponentParam& VComponentDynamicComponentParam::operator=( const VComponentDynamicComponentParam& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_staticFriction = in_rhs.m_staticFriction;
		m_movingFriction = in_rhs.m_movingFriction;
		m_elasticCollisionDampen = in_rhs.m_elasticCollisionDampen;
	}
	return( *this );
}

/**/
const Hubris::HBOOL VComponentDynamicComponentParam::operator==( const VComponentDynamicComponentParam& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_staticFriction == in_rhs.m_staticFriction );
		match &= ( m_movingFriction == in_rhs.m_movingFriction );
		match &= ( m_elasticCollisionDampen == in_rhs.m_elasticCollisionDampen );
	}
	return match;
}

/**/
const Hubris::HBOOL VComponentDynamicComponentParam::operator!=( const VComponentDynamicComponentParam& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
