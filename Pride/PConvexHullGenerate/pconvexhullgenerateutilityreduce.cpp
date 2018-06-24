//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduce.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduce.h"

#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtility.h"
#include "Pride/PConvexHullGenerate/PConvexHullGenerateUtilityReduceData.h"

#include "Pride/PInterface/PInterface_Export.h"
#include "Pride/PConvexHull/PConvexHull_Export.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< PConvexHull >TArrayConvexHull;
typedef Hubris::HSmartPointer< PConvexHullGenerateUtilityReduceData >TDataPointer;
typedef Hubris::HContainerArray< TDataPointer >TArrayData;

///////////////////////////////////////////////////////
// local static functions
/**/
static Hubris::HVOID LocalGetBestRemove( 
	HSINT& out_bestOne,
	HSINT& out_bestTwo,
	const TArrayData& in_arrayData
	)
{
	HREAL bestValue = HVariablesMath::MinimumGet< HREAL >();

	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		in_arrayData[ index ]->BestValueGet( out_bestOne, out_bestTwo, bestValue, index );
	}

	return;
}

/**/
static HBOOL LocalCreateMerge( 
	TDataPointer& in_out_data, 
	TArrayData& in_arrayData,
	const HSINT in_indexOne, 
	const HSINT in_indexTwo 
	)
{
	PConvexHull mergeHull;

	TArrayVector pointCloud = in_arrayData[ in_indexOne ]->HullGet().PointCloudGet();
	const TArrayVector& tempPointCloud = in_arrayData[ in_indexTwo ]->HullGet().PointCloudGet();
	pointCloud.Insert( tempPointCloud.Begin(), tempPointCloud.End(), pointCloud.End() );

	PConvexHullGenerateUtility::CreateHullFromPointCloud(
		mergeHull, 
		pointCloud
		);

	if( HFALSE == PConvexHullUtility::EnclosedTest( mergeHull ) )
	{
		return HFALSE;
	}

	in_out_data->HullSet( mergeHull );

	return HTRUE;
}

/**/
static Hubris::HVOID LocalRemove( 
	TArrayData& in_arrayData,
	const HSINT in_indexOne, 
	const HSINT in_indexTwo 
	)
{
	const HSINT removeFirst = HMathUtility::Maximum( in_indexOne, in_indexTwo );
	const HSINT removeSecond = HMathUtility::Minimum( in_indexOne, in_indexTwo );

	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		in_arrayData[ index ]->RemoveDataIndex( removeFirst, index );
	}
	in_arrayData.Remove( in_arrayData.Begin() + removeFirst );

	for( HSINT index = 0; index < in_arrayData.SizeGet(); ++index )
	{
		in_arrayData[ index ]->RemoveDataIndex( removeSecond, index );
	}
	in_arrayData.Remove( in_arrayData.Begin() + removeSecond );

	return;
}

/**/
static Hubris::HVOID LocalAppend(
	TArrayData& in_out_arrayData,
	TDataPointer& in_out_data
	)
{
	for( HSINT index = 0; index < in_out_arrayData.SizeGet(); ++index )
	{
		in_out_arrayData[ index ]->DataAppend( 
			index,
			( *in_out_data )
			);
	}

	HContainerUtility::PushBack( in_out_arrayData, in_out_data );

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
PConvexHullGenerateUtilityReduce::PConvexHullGenerateUtilityReduce(
	TArrayConvexHull& in_arrayConvexHull,
	const Hubris::HSINT in_maxCount,
	PInterfaceProgress* const in_pProgress
	)
: m_arrayData()
{
	HCOMMON_FOR_EACH( hull, in_arrayConvexHull, TArrayConvexHull )
	{
		if( HFALSE == PConvexHullUtility::EnclosedTest( hull ) )
		{
			continue;
		}

		TDataPointer data;
		data.Create();

		data->HullSet( hull );

		m_arrayData.Insert( data );
	}

	for( HSINT index = 0; index < m_arrayData.SizeGet(); ++index )
	{
		m_arrayData[ index ]->CalculateValues( index, m_arrayData );
	}

	const HSINT originalSize = m_arrayData.SizeGet();
	while( in_maxCount < m_arrayData.SizeGet() )
	{
		HSINT removeOne = HCOMMON_INVALID_INDEX;
		HSINT removeTwo = HCOMMON_INVALID_INDEX;

		LocalGetBestRemove( 
			removeOne,
			removeTwo,
			m_arrayData
			);

		if( ( HCOMMON_INVALID_INDEX == removeOne ) || 
			( HCOMMON_INVALID_INDEX == removeTwo ) )
		{
			break;
		}

		TDataPointer data;
		data.Create();
		const HBOOL newData = LocalCreateMerge( data, m_arrayData, removeOne, removeTwo );

		LocalRemove( m_arrayData, removeOne, removeTwo );

		if( HTRUE == newData )
		{
			LocalAppend( m_arrayData, data );
		}

		if( HNULL != in_pProgress )
		{
			HString message = "reduced hull count to " + HTraitStringIn( m_arrayData.SizeGet() );
			const HREAL progress = 1.0F - ( HREAL( m_arrayData.SizeGet() - in_maxCount ) / HREAL( originalSize - in_maxCount ) );
			in_pProgress->ProgressSet( message, progress );
		}
	}

	return;
}

/**/
PConvexHullGenerateUtilityReduce::~PConvexHullGenerateUtilityReduce()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID PConvexHullGenerateUtilityReduce::GatherHulls(
	TArrayConvexHull& out_arrayConvexHull
	)
{
	const HSINT count = m_arrayData.SizeGet();
	out_arrayConvexHull.SizeSet( count );

	for( HSINT index = 0; index < count; ++index )
	{
		out_arrayConvexHull[ index ] = m_arrayData[ index ]->HullGet();
	}

	return;
}

/**/
