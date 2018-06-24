//file: Pride/PPointCloud/PPointCloud.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PPointCloud/PPointCloud.h"

#include "Pride/PBounds/PBounds_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template class Pride::PPointCloud< HREAL, 2 >;
template class Pride::PPointCloud< HREAL, 3 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPointCloud< IN_TYPE, IN_COUNT >::PPointCloud( const PPointCloud& in_src )
: m_arrayPoints()
, m_arrayMergeCount()
{
	( *this ) = in_src;
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPointCloud< IN_TYPE, IN_COUNT >::PPointCloud()
: m_arrayPoints()
, m_arrayMergeCount()
{
	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
PPointCloud< IN_TYPE, IN_COUNT >::~PPointCloud()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const PPointCloud< IN_TYPE, IN_COUNT >& PPointCloud< IN_TYPE, IN_COUNT >::operator=( const PPointCloud& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayPoints = in_rhs.m_arrayPoints;
		m_arrayMergeCount = in_rhs.m_arrayMergeCount;
	}

	return( *this );
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HBOOL PPointCloud< IN_TYPE, IN_COUNT >::operator==( const PPointCloud& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayPoints == in_rhs.m_arrayPoints );
		match &= ( m_arrayMergeCount == in_rhs.m_arrayMergeCount );
	}

	return match;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HBOOL PPointCloud< IN_TYPE, IN_COUNT >::operator!=( const PPointCloud& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// static public methods
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
typename const PPointCloud< IN_TYPE, IN_COUNT >::TVector PPointCloud< IN_TYPE, IN_COUNT >::ThreasholdCreate(
	const TBounds& in_bounds,
	const Hubris::HREAL in_pointMergeThreasholdPercentage
	)
{
	if( HFALSE == in_bounds.ValidGet() )
	{
		return TVector();
	}

	return ( ( in_bounds.VectorMaximumGet() - in_bounds.VectorMinimumGet() ) * in_pointMergeThreasholdPercentage );
}

template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
typename const PPointCloud< IN_TYPE, IN_COUNT >::TVector PPointCloud< IN_TYPE, IN_COUNT >::ThreasholdCreate(
	const TArrayVector& in_arrayPoint,
	const Hubris::HREAL in_pointMergeThreasholdPercentage
	)
{
	PBounds< IN_TYPE, IN_COUNT > bounds;
	HCOMMON_FOR_EACH_CONST( point, in_arrayPoint, TArrayVector )
	{
		bounds.InsertPoint( point );
	}

	return ThreasholdCreate( bounds, in_pointMergeThreasholdPercentage );
}

///////////////////////////////////////////////////////
// public methods
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
const Hubris::HSINT PPointCloud< IN_TYPE, IN_COUNT >::PointMerge( 
	const TVector& in_point,
	const TVector& in_threashold
	)
{
	for( HSINT index = 0; index < m_arrayPoints.SizeGet(); ++index )
	{
		TVector& cleanPoint = m_arrayPoints[ index ];

		const TVector offset = HMathUtility::Absolute( in_point - cleanPoint );
		//if( offset <= in_threashold )
		if( HTRUE == HMatrixUtility::SmallerEqual( offset, in_threashold ) )
		{
			//merge point
			HSINT& size = m_arrayMergeCount[ index ]; 
			size += 1;
			cleanPoint = ( ( cleanPoint * ( HREAL )( size ) ) + in_point ) * ( 1.0F / ( HREAL )( size + 1 ) );

			return index;
		}
	}

	const HSINT returnIndex = HContainerUtility::PushBack( m_arrayPoints, in_point );
	HContainerUtility::PushBack( m_arrayMergeCount, 0 );

	return returnIndex;
}
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
HVOID PPointCloud< IN_TYPE, IN_COUNT >::ArrayPointMerge( 
	const TArrayVector& in_arrayPoint,
	const TVector& in_threashold
	)
{
	PBounds< IN_TYPE, IN_COUNT > bounds;
	HCOMMON_FOR_EACH_CONST( point, in_arrayPoint, TArrayVector )
	{
		PointMerge( point, in_threashold );
	}

	return;
}

/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
HVOID PPointCloud< IN_TYPE, IN_COUNT >::ArrayPointAdd( 
	const TArrayVector& in_arrayPoint
	)
{
	m_arrayPoints.Insert( in_arrayPoint.Begin(), in_arrayPoint.End() );
	m_arrayMergeCount.SizeResize( m_arrayPoints.SizeGet() );

	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
template< typename IN_TYPE, Hubris::HSINT IN_COUNT >
HVOID PPointCloud< IN_TYPE, IN_COUNT >::ArrayPointsSet( const TArrayVector& in_arrayVertex )
{
	m_arrayPoints = in_arrayVertex;
	m_arrayMergeCount.SizeSet( m_arrayPoints.SizeGet() );

	return;
}

/**/
