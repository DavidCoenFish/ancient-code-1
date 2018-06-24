//file: Vanity/VComponentCollision/VComponentCollisionHull.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionHull.h"

#include "Vanity/VComponentCollision/VComponentCollisionResultBase.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;
using namespace Vanity;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentCollisionHullData >TArrayData;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////
// local static methods
/**/
static const Hubris::HBOOL LocalTestPlane(
	HREAL& out_distance,
	const VComponentCollisionHullData& in_data,
	const PLineR3& in_line,
	const HREAL in_maximumDistance,
	const TArrayData& in_arrayData
	)
{
	if( HFALSE == PIntersectionUtility::PlaneLineIntersect( 
		out_distance,
		in_data.PlaneGet(),
		in_line
		) )
	{
		return HFALSE;
	}

	if( ( in_maximumDistance < out_distance ) &&
		( HMathUtility::EpsilonEqualNot( in_maximumDistance, out_distance ) ) )
	{
		return HFALSE;
	}

	//now test intersection point is inside every plane touching this one
	const HVectorR3 intersectionPoint = PLineUtility::LinePointGet( in_line, out_distance );
	const TArraySint& arrayPlaneIndexTouching = in_data.ArrayIndexTouchingPlaneGet();

	HCOMMON_FOR_EACH_CONST( indexTouching, arrayPlaneIndexTouching, TArraySint )
	{
		if( HFALSE == PPlaneUtility::PointInsidePlane(
			in_arrayData[ indexTouching ].PlaneGet(),
			intersectionPoint
			) )
		{
			return HFALSE;
		}
	}

	return HTRUE;
}

///////////////////////////////////////////////////////
// creation
/**/
VComponentCollisionHull::VComponentCollisionHull( const VComponentCollisionHull& in_src )
: m_arrayData()
{
	( *this ) = in_src;
	return;
}

/**/
VComponentCollisionHull::VComponentCollisionHull( Pride::PConvexHull& in_hull )
: m_arrayData()
{
	const HSINT count = in_hull.PlaneCountGet();
	m_arrayData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		m_arrayData[ index ].PlaneGet() = in_hull.PlaneGet( index );
		in_hull.PlaneArrayIndexTouchingGet( 
			m_arrayData[ index ].ArrayIndexTouchingPlaneGet(),
			index
			);
	}

	return;
}

/**/
VComponentCollisionHull::VComponentCollisionHull()
: m_arrayData()
{
	return;
}

/**/
VComponentCollisionHull::~VComponentCollisionHull()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const VComponentCollisionHull& VComponentCollisionHull::operator=( const VComponentCollisionHull& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayData = in_rhs.m_arrayData;
	}

	return( *this );
}

/**/
const Hubris::HBOOL VComponentCollisionHull::operator==( const VComponentCollisionHull& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayData == in_rhs.m_arrayData );
	}

	return match;
}

/**/
const Hubris::HBOOL VComponentCollisionHull::operator!=( const VComponentCollisionHull& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID VComponentCollisionHull::CollideRay(
	VComponentCollisionResultBase& out_collisionData,
	const Pride::PLineR3& in_line,
	const Hubris::HREAL in_maximumLineLength,
	const Hubris::HMatrixR4& in_itemMatrix,
	const Hubris::HMatrixR4& in_itemMatrixInvert
	)const
{
	const PLineR3 localLine = PLineUtility::LineTransform( in_line, in_itemMatrixInvert );
	//go through the planes that point towards line, check intersect point inside touching planes
	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayData )
	{
		HREAL distance = 0.0F;
		if( HFALSE == LocalTestPlane(
			distance,
			data,
			localLine,
			in_maximumLineLength,
			m_arrayData
			) )
		{
			continue;
		}

		VComponentCollisionResultHull* pResult = HNULL;
		HCOMMON_NEW_PARAM_3(
			pResult,
			VComponentCollisionResultHull,
			in_line,
			distance,
			HMatrixUtility::VectorProductNoTranslate( in_itemMatrix, data.PlaneGet().DirectionGet().VectorGet() )
			);

		out_collisionData.PointerSetHull( pResult );	
	}

	return;
}

/**/