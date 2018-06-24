//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilitySegment.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilitySegment.h"

#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilitySegment >TArraySegment;

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilitySegment::PConvexHullGenerateUtilitySegment( const PConvexHullGenerateUtilitySegment& in_src )
: m_indexOne( HCOMMON_INVALID_INDEX )
, m_indexTwo( HCOMMON_INVALID_INDEX )
{
	( *this ) = in_src;
	return;
}

/**/
PConvexHullGenerateUtilitySegment::PConvexHullGenerateUtilitySegment(
	const Hubris::HSINT in_indexOne,
	const Hubris::HSINT in_indexTwo
	)
: m_indexOne( in_indexOne )
, m_indexTwo( in_indexTwo )
{
	return;
}

/**/
PConvexHullGenerateUtilitySegment::PConvexHullGenerateUtilitySegment()
: m_indexOne( HCOMMON_INVALID_INDEX )
, m_indexTwo( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
PConvexHullGenerateUtilitySegment::~PConvexHullGenerateUtilitySegment()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PConvexHullGenerateUtilitySegment& PConvexHullGenerateUtilitySegment::operator=( const PConvexHullGenerateUtilitySegment& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_indexOne = in_rhs.m_indexOne;
		m_indexTwo = in_rhs.m_indexTwo;
	}
	return( *this );
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilitySegment::operator==( const PConvexHullGenerateUtilitySegment& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_indexOne == in_rhs.m_indexOne );
		match &= ( m_indexTwo == in_rhs.m_indexTwo );
	}

	return match;
}

/**/
const Hubris::HBOOL PConvexHullGenerateUtilitySegment::operator!=( const PConvexHullGenerateUtilitySegment& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const HSINT PConvexHullGenerateUtilitySegment::NextPlaneIndexGet( 
	const Hubris::HSINT in_ourIndex,
	const TArraySegment& in_arraySegments,
	const TArrayVector& in_arrayPoints
	)
{
	HSINT bestIndex = HCOMMON_INVALID_INDEX;
	HREAL smallestDistance = HVariablesMath::MaximumGet< HREAL >();

	for( HSINT index = 0; index < in_arraySegments.SizeGet(); ++index )
	{
		if( index == in_ourIndex )
		{
			continue;
		}

		const HREAL length = HMatrixUtility::LengthSquared( in_arrayPoints[ m_indexTwo ] - in_arrayPoints[ in_arraySegments[ index ].IndexOneGet() ] );
		if( length < smallestDistance )
		{
			smallestDistance = length;
			bestIndex = index;
		}
	}

	return bestIndex;
}
/**/
