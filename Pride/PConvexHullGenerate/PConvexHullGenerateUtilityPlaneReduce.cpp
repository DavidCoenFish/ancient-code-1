//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduce.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduce.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceData.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityPlaneReduceLine.h"

#include "Pride/PIntersection/PIntersection_Export.h"
#include "Pride/PConvexHull/PConvexHull_Export.h"
#include "Pride/PPlane/PPlane_Export.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceData >TArrayData;
typedef Hubris::HContainerArray< HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< HVectorR2 >TArrayVectorR2;
typedef Hubris::HContainerArray< PConvexHullGenerateUtilityPlaneReduceLine >TArrayLine;

///////////////////////////////////////////////////////
// local static methods
/**/
static Hubris::HVOID LocalGenerateLines(
	TArrayLine& in_arrayLines,
	const TArrayData& in_arrayData
	)
{
	const HSINT count = in_arrayData.SizeGet();
	for( HSINT indexOne = 0; indexOne < count; ++indexOne )
	{
		for( HSINT indexTwo = indexOne + 1; indexTwo < count; ++indexTwo )
		{
			PLineR3 line;
			if( HFALSE == PIntersectionUtility::PlanePlaneIntersect(
				line, 
				in_arrayData[ indexOne ].PlaneGet(),
				in_arrayData[ indexTwo ].PlaneGet()
				) )
			{
				continue;
			}

			in_arrayLines.Insert( 
				PConvexHullGenerateUtilityPlaneReduceLine(
					line,
					indexOne,
					indexTwo
					) );
		}
	}

	return;
}

/**/
static const HSINT LocalPlaneCountInUseGet(
	const TArrayData& in_arrayData
	)
{
	HSINT count = 0;
	HCOMMON_FOR_EACH_CONST( data, in_arrayData, TArrayData )
	{
		if( HTRUE == data.PlaneInUseGet() )
		{
			count += 1;
		}
	}

	return count;
}

/**/
static Hubris::HVOID LocalPrepLines(
	TArrayLine& in_out_arrayLines,
	TArrayData& in_out_arrayData
	)
{
	HCOMMON_FOR_EACH( data, in_out_arrayData, TArrayData )
	{
		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		data.ArrayLineIndexClear();
	}

	for( HSINT index = 0; index < in_out_arrayLines.SizeGet(); ++index )
	{
		PConvexHullGenerateUtilityPlaneReduceLine& line = in_out_arrayLines[ index ];

		if( ( HFALSE == in_out_arrayData[ line.PlaneIndexOneGet() ].PlaneInUseGet() ) ||
			( HFALSE == in_out_arrayData[ line.PlaneIndexTwoGet() ].PlaneInUseGet() ) )
		{
			continue;
		}

		if( HFALSE == line.TrimSegmentAgainstPlanes( in_out_arrayData ) )
		{
			continue;
		}

		in_out_arrayData[ line.PlaneIndexOneGet() ].ArrayLineIndexAdd( index );
		in_out_arrayData[ line.PlaneIndexTwoGet() ].ArrayLineIndexAdd( index );
	}

	return;
}

/**/
static const HSINT LocalRemoveCandidateEquivalentFind(
	const TArrayData& in_arrayData
	)
{
	//look for any planes that are equivalent
	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		const PConvexHullGenerateUtilityPlaneReduceData& data = in_arrayData[ index ];

		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		for( HSINT indexTwo = index + 1; indexTwo < in_arrayData.SizeGet(); ++indexTwo )
		{
			const PConvexHullGenerateUtilityPlaneReduceData& dataTwo = in_arrayData[ indexTwo ];

			if( HFALSE == dataTwo.PlaneInUseGet() )
			{
				continue;
			}


			if( PPlaneUtility::EqualDelta( data.PlaneGet(), dataTwo.PlaneGet(), 0.01F, 0.1F ) )
			{
				return index;
			}
		}
	}

	return HCOMMON_INVALID_INDEX;
}

/**
static const HSINT LocalRemoveCandidateFind(
	const TArrayData& in_arrayData
	)
{
	//construct a hull
	PConvexHull hull;
	HCOMMON_FOR_EACH_CONST( data, in_arrayData, TArrayData )
	{
		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		hull.PlaneAdd( data.PlaneGet() );
	}

	HSINT localIndex = HCOMMON_INVALID_INDEX;
	HREAL smallestArea = HVariablesMath::MaximumGet< HREAL >();

	for( HSINT index = 0; index < hull.PlaneCountGet(); ++index )
	{
		TArrayVector arrayEdgeLoop;
		HBOOL loopClosed = HFALSE;
		PConvexHullUtility::PlaneEdgeLoopGet( 
			index,
			arrayEdgeLoop,
			loopClosed,
			hull,
			0.0001F
			);

		if( HFALSE == loopClosed )
		{
			continue;
		}

		TArrayVectorR2 arrayPlanePoint;
		PPlaneUtility::ProjectOntoPlane(
			arrayPlanePoint,
			arrayEdgeLoop,
			hull.PlaneGet( index )
			);

		const HREAL area = HMathArea::AreaClosedLoop( arrayPlanePoint );
		if( area < smallestArea )
		{
			smallestArea = area;
			localIndex = index;

			if( HTRUE == HMathUtility::EpsilonZero( area ) )
			{
				break;
			}
		}
	}

	HSINT trace = 0;
	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		const PConvexHullGenerateUtilityPlaneReduceData& data  = in_arrayData[ index ];
		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		if( trace == localIndex )
		{
			return index;
		}

		++trace;
	}

	return HCOMMON_INVALID_INDEX;
}

/**/
static const HSINT LocalRemoveCandidateFind(
	const TArrayLine& in_arrayLines,
	const TArrayData& in_arrayData
	)
{
	//look for smallest volume to remove
	HSINT removeIndex = HCOMMON_INVALID_INDEX;

	HREAL smallestVolume = HVariablesMath::MaximumGet< HREAL >();

	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		const PConvexHullGenerateUtilityPlaneReduceData& data = in_arrayData[ index ];

		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		const HREAL testRemoveVolume = in_arrayData[ index ].CalculateRemovedVolume( 
			in_arrayLines,
			in_arrayData,
			index
			);

		if( testRemoveVolume <= 0.0F )
		{
			removeIndex = index;
			break;
		}

		if( testRemoveVolume < smallestVolume )
		{
			removeIndex = index;
			smallestVolume = testRemoveVolume;
		}
	}

	return removeIndex;
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityPlaneReduce::PConvexHullGenerateUtilityPlaneReduce(
	const PConvexHull& in_hull,
	const Hubris::HSINT in_maxPlaneCount
	)
: m_arrayData()
, m_arrayLines()
{
	const HSINT count = in_hull.PlaneCountGet();
	m_arrayData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		m_arrayData[ index ].PlaneSet( in_hull.PlaneGet( index ) );
	}

	if( count < in_maxPlaneCount )
	{
		return;
	}

	while( in_maxPlaneCount < LocalPlaneCountInUseGet( m_arrayData ) )
	{
		const HSINT removeIndex = LocalRemoveCandidateEquivalentFind(
			m_arrayData
			);

		if( HCOMMON_INVALID_INDEX == removeIndex )
		{
			break;
		}

		m_arrayData[ removeIndex ].PlaneInUseSet( HFALSE );
	} 

	if( count < in_maxPlaneCount )
	{
		return;
	}

	LocalGenerateLines(
		m_arrayLines,
		m_arrayData
		);

	while( in_maxPlaneCount < LocalPlaneCountInUseGet( m_arrayData ) )
	{
		LocalPrepLines(
			m_arrayLines,
			m_arrayData
			);

		const HSINT removeIndex = LocalRemoveCandidateFind(
			m_arrayLines,
			m_arrayData
			);

		if( HCOMMON_INVALID_INDEX == removeIndex )
		{
			break;
		}

		m_arrayData[ removeIndex ].PlaneInUseSet( HFALSE );
	} 

	return;
}

/**/
PConvexHullGenerateUtilityPlaneReduce::~PConvexHullGenerateUtilityPlaneReduce()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHullGenerateUtilityPlaneReduce::GatherHull(
	PConvexHull& out_hull
	)
{
	out_hull.Clear();

	HCOMMON_FOR_EACH_CONST( data, m_arrayData, TArrayData )
	{
		if( HFALSE == data.PlaneInUseGet() )
		{
			continue;
		}

		out_hull.PlaneAdd( data.PlaneGet() );
	}

	return;
}

/**/