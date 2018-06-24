//file: Pride/PTestbed/PTestbedSphere.cpp

#include "Pride/PTestbed/PTestbedSphere.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PSphereR3 >TArraySphere;
typedef Hubris::HContainerArray< PSphereR2 >TArraySphere2D;

typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector2D;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;


//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedSphere()
{
	HBOOL success = HTRUE;

	{
		const PSphereR3 sphere0( 3.5F, HMatrixConstructor::HVectorR3Construct( 2.6F, 1.3F, 1.2F ) );
		const PSphereR3 sphere1( sphere0 );
		PSphereR3 sphere2;
		sphere2.RadiusSet( sphere0.RadiusGet() );
		sphere2.CenterSet( sphere0.CenterGet() );
		const PSphereR3 sphere3;

		success &= ( sphere0 == sphere1 );
		success &= ( sphere1 == sphere0 );

		success &= ( sphere0 == sphere2 );
		success &= ( sphere2 == sphere0 );

		success &= ( sphere0 != sphere3 );
		success &= ( sphere3 != sphere0 );

		success &= !( sphere0 != sphere2 );
		success &= !( sphere2 != sphere0 );

		success &= !( sphere0 == sphere3 );
		success &= !( sphere3 == sphere0 );

	}

	PTESTBED_VALIDATE_STATUS( "PSphere", success );

	return success;
}

/**/
static const HBOOL LocalTestbedSphereUtility()
{
	HBOOL success = HTRUE;

	//PSphereUtility
	//static const PSphereR3 SphereMerge(
	//	const PSphereR3& in_lhs,
	//	const PSphereR3& in_rhs
	//	);
	{
		const PSphereR3 sphere0( 1.0F, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.0F, 1.0F ) );
		const PSphereR3 sphere1( 2.0F, HMatrixConstructor::HVectorR3Construct( 1.0F, -1.0F, 1.0F ) );
		const PSphereR3 sphere2( 0.1F, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.0F, 1.0F ) );
		const PSphereR3 sphere3( 0.1F, HMatrixConstructor::HVectorR3Construct( 1.0F, 1.1F, 1.0F ) );

		const PSphereR3 sphere4( 2.5F, HMatrixConstructor::HVectorR3Construct( 1.0F, -0.5F, 1.0F ) );

		success &= ( sphere4 == PSphereUtility::SphereMerge( sphere0, sphere1 ) );
		success &= ( sphere0 == PSphereUtility::SphereMerge( sphere0, sphere0 ) );
		success &= ( sphere0 == PSphereUtility::SphereMerge( sphere0, sphere2 ) );
		success &= ( sphere0 == PSphereUtility::SphereMerge( sphere0, sphere3 ) );
	}

	//// given a list of sphere, and target number, return the merge list
	//static HVOID SphereListReduce(
	//	TArrayArraySint& out_mergeList,
	//	const TArraySphere& in_arraySphere,
	//	const Hubris::HSINT in_maxCount
	//	);	
	{
		TArrayArraySint mergeList;
		TArraySphere arraySphere;

		arraySphere.Insert( PSphereR3( 1.0F, HMatrixConstructor::HVectorR3Construct(  1.0F, 0.0F, 0.0F ) ) );
		arraySphere.Insert( PSphereR3( 1.0F, HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, 0.0F ) ) );
		arraySphere.Insert( PSphereR3( 1.0F, HMatrixConstructor::HVectorR3Construct( 10.0F, 0.0F, 1.0F ) ) );
		arraySphere.Insert( PSphereR3( 1.0F, HMatrixConstructor::HVectorR3Construct( 12.0F, 0.0F, 1.0F ) ) );

		PSphereR3 mergedOne( 2.0F, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ) );
		PSphereR3 mergedTwo( 2.0F, HMatrixConstructor::HVectorR3Construct( 11.0F, 0.0F, 1.0F ) );


		PSphereUtility::SphereListReduce(
			mergeList,
			arraySphere,
			2
			);

		success &= ( 2 == mergeList.SizeGet() );
		if( HTRUE == success )
		{
			success &= ( 2 == mergeList[ 0 ].SizeGet() );
			success &= ( 2 == mergeList[ 1 ].SizeGet() );
			success &= ( mergeList[ 0 ] != mergeList[ 1 ] );
		}

		HCOMMON_FOR_EACH_CONST( mergeArray, mergeList, TArrayArraySint )
		{
			TArraySphere arrayMergeSphere;
			for( HSINT index = 0; index < mergeArray.SizeGet(); ++index )
			{
				arrayMergeSphere.Insert( arraySphere[ mergeArray[ index ] ] );
			}

			const PSphereR3 sphere = PSphereUtility::SphereMerge( arrayMergeSphere );

			success &= ( ( sphere == mergedOne ) ||
				( sphere == mergedTwo ) );
		}
	}
		
	PTESTBED_VALIDATE_STATUS( "PSphereUtility", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedSphere()
{
	PTESTBED_VALIDATE_START( "TestbedSphere" );
	HBOOL success = HTRUE;

	success &= LocalTestbedSphere();
	success &= LocalTestbedSphereUtility();

	return success;
}

/**/