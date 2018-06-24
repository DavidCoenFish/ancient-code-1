//file: Hubris/HMath/HMathArea.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMath/HMathArea.h"

#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerUtility.h"
#include "Hubris/HMath/HMathUtility.h"
#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HVariables/HVariablesMath.h"

///////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HMatrix< HREAL, 2, 1 > > TArrayVectorR2;

///////////////////////////////////////////////////
// public methods
/*
http://amp.ece.cmu.edu/Publication/Cha/icip01_Cha.pdf
	area of triangle, one pointy at origin, two arbitary points
	area = 1/2(-x2y1 + x1y2) 

	sum for each line segment
*/
const HREAL Hubris::HMathArea::AreaClosedLoop( const TArrayVectorR2& in_arrayLoop )
{
	HREAL area = HVariablesMath::ZeroGet< HREAL >();

	if( 0 == in_arrayLoop.SizeGet() )
	{
		return area;
	}

	HVectorR2 prevPoint = HContainerUtility::Back( in_arrayLoop );
	HCOMMON_FOR_EACH_CONST( point, in_arrayLoop, TArrayVectorR2 )
	{
		area += ( 0.5F * ( ( prevPoint[ 0 ] * point[ 1 ] ) - ( point[ 0 ] * prevPoint[ 1 ] ) ) );
		prevPoint = point;
	}

	return area;
}

/**/

