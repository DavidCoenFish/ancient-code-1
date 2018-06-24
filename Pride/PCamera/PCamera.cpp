//file: Pride/PCamera/PCamera.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PCamera/PCamera.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/*
	optimisation dependance. raw layout to match win32 bitmap colour specification.
	incase of change, need to modify PImage/PImageBitmap.h
*/
struct TType
{
	enum TEnum
	{
		TPerspective = 0,
		TOrthogonal,
		TCount
	};
};

///////////////////////////////////////////////////////
// creation
/**/
PCamera::PCamera( const PCamera& in_src )
: m_transform()
, m_type( HCOMMON_INVALID_INDEX )
, m_left( HVariablesMath::ZeroGet< HREAL >() )
, m_right( HVariablesMath::ZeroGet< HREAL >() )
, m_top( HVariablesMath::ZeroGet< HREAL >() )
, m_bottom( HVariablesMath::ZeroGet< HREAL >() )
, m_near( HVariablesMath::ZeroGet< HREAL >() )
, m_far( HVariablesMath::ZeroGet< HREAL >() )
{
	( *this ) = in_src;
	return;
}

/**/
PCamera::PCamera( 
	const Hubris::HMatrixR4& in_transform,
	const Hubris::HSINT in_type,
	const Hubris::HREAL in_left,
	const Hubris::HREAL in_right,
	const Hubris::HREAL in_top,
	const Hubris::HREAL in_bottom,
	const Hubris::HREAL in_near,
	const Hubris::HREAL in_far
	)
: m_transform( in_transform )
, m_type( in_type )
, m_left( in_left )
, m_right( in_right )
, m_top( in_top )
, m_bottom( in_bottom )
, m_near( in_near )
, m_far( in_far )
{
	return;
}

/**/
PCamera::PCamera()
: m_transform()
, m_type( HCOMMON_INVALID_INDEX )
, m_left( HVariablesMath::ZeroGet< HREAL >() )
, m_right( HVariablesMath::ZeroGet< HREAL >() )
, m_top( HVariablesMath::ZeroGet< HREAL >() )
, m_bottom( HVariablesMath::ZeroGet< HREAL >() )
, m_near( HVariablesMath::ZeroGet< HREAL >() )
, m_far( HVariablesMath::ZeroGet< HREAL >() )
{
	return;
}

/**/
PCamera::~PCamera()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PCamera& PCamera::operator=( const PCamera& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_transform = in_rhs.m_transform;
		m_type = in_rhs.m_type;
		m_left = in_rhs.m_left;
		m_right = in_rhs.m_right;
		m_top = in_rhs.m_top;
		m_bottom = in_rhs.m_bottom;
		m_near = in_rhs.m_near;
		m_far = in_rhs.m_far;
	}

	return( *this );
}

/**/
const Hubris::HBOOL PCamera::operator==( const PCamera& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_transform == in_rhs.m_transform );
		match &= ( m_type == in_rhs.m_type );
		match &= ( m_left == in_rhs.m_left );
		match &= ( m_right == in_rhs.m_right );
		match &= ( m_top == in_rhs.m_top );
		match &= ( m_bottom == in_rhs.m_bottom );
		match &= ( m_near == in_rhs.m_near );
		match &= ( m_far == in_rhs.m_far );
	}

	return match;
}

/**/
const Hubris::HBOOL PCamera::operator!=( const PCamera& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT PCamera::TypePerspectiveGet()
{
	return( TType::TPerspective );
}

/**/
const Hubris::HSINT PCamera::TypeOrthogonalGet()
{
	return( TType::TOrthogonal );
}

/**/