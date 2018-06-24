//file: Pride/PGeometry/PGeometryOperator.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryOperator.h"

#include "Pride/PGeometry/PGeometry.h"
#include "Pride/PGeometry/PGeometryStoreTriangleStrip.h"
#include "Pride/PGeometry/PGeometryStoreTriangle.h"
#include "Pride/PGeometry/PGeometryTypeSignature.h"
#include "Pride/PGeometry/PGeometryUtility.h"
#include "Pride/PGeometry/PGeometryVertex.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HSINT >TArraySint;

/////////////////////////////////////////////////////////////////
// local static method
/**/
static Hubris::HVOID LocalAppendTriangle( PGeometry& in_out_lhs, const PGeometry& in_rhs, const HSINT in_topographyIndex, const PGeometryTypeSignature& in_typeSignature )
{
	PGeometryStoreTriangle& lhsStore = in_out_lhs.StoreTopologyTriangleGet( in_topographyIndex );
	const PGeometryStoreTriangle& rhsStore = in_rhs.StoreTopologyTriangleGet( in_topographyIndex );
	PGeometryVertex vertex( in_typeSignature, lhsStore.TargetTopologyVertexIndexGet() );

	HSINT rhsVertexIndex[ 3 ];
	HSINT lhsVertexIndex[ 3 ];
	const HSINT count = rhsStore.TriangleCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		rhsStore.TriangleGet( index, rhsVertexIndex[ 0 ], rhsVertexIndex[ 1 ], rhsVertexIndex[ 2 ] ); 

		for( HSINT subIndex = 0; subIndex < 3; ++subIndex )
		{
			PGeometryUtility::VertexGet( in_typeSignature, vertex, in_rhs, rhsVertexIndex[ subIndex ] );

			lhsVertexIndex[ subIndex ] = PGeometryUtility::VertexAdd( in_typeSignature, in_out_lhs, vertex );
		}

		lhsStore.TriangleAdd( lhsVertexIndex[ 0 ], lhsVertexIndex[ 1 ], lhsVertexIndex[ 2 ] );
	}

	return;
}

/**/
static Hubris::HVOID LocalAppendStrip( PGeometry& in_out_lhs, const PGeometry& in_rhs, const HSINT in_topographyIndex, const PGeometryTypeSignature& in_typeSignature )
{
	PGeometryStoreTriangleStrip& lhsStore = in_out_lhs.StoreTopologyTriangleStripGet( in_topographyIndex );
	const PGeometryStoreTriangleStrip& rhsStore = in_rhs.StoreTopologyTriangleStripGet( in_topographyIndex );
	PGeometryVertex vertex( in_typeSignature, lhsStore.TargetTopologyVertexIndexGet() );

	TArraySint lhsArrayVertexIndex;

	const HSINT count = rhsStore.StripCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT subCount = rhsStore.StripLengthGet( index );
		const HSINT* const pRhsVertexIndex = rhsStore.StripDataGet( index ); 
		lhsArrayVertexIndex.SizeSet( subCount );

		for( HSINT subIndex = 0; subIndex < subCount; ++subIndex )
		{
			PGeometryUtility::VertexGet( in_typeSignature, vertex, in_rhs, pRhsVertexIndex[ subIndex ] );

			lhsArrayVertexIndex[ subIndex ] = PGeometryUtility::VertexAdd( in_typeSignature, in_out_lhs, vertex );
		}

		lhsStore.StripAdd( lhsArrayVertexIndex.RawGet(), subCount );
	}

	return;
}

/////////////////////////////////////////////////////////////////
// free operators
/**/
const PGeometry Pride::operator+( const PGeometry& in_lhs, const PGeometry& in_rhs )
{
	PGeometry returnValue( in_lhs );
	returnValue += in_rhs;

	return returnValue;
}

/**/
const PGeometry& Pride::operator+=( PGeometry& in_out_lhs, const PGeometry& in_rhs )
{
	const PGeometryTypeSignature lhsTypeSignature = in_out_lhs.TypeSignatureGet();
	HCOMMON_ASSERT( lhsTypeSignature == in_rhs.TypeSignatureGet(), "require matching type for operation" );

	const HSINT count = lhsTypeSignature.TopologyStreamCountGet();
	for( HSINT index = 0; index < count; ++index )
	{
		const HSINT type = lhsTypeSignature.TopologyStreamTypeGet( index );

		if( type == PGeometryTypeSignature::TypeGetTopologyVertexIndex() )
		{
			//NOP
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyTriangle() )
		{
			LocalAppendTriangle( in_out_lhs, in_rhs, index, lhsTypeSignature );
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyTriangleStrip() )
		{
			LocalAppendStrip( in_out_lhs, in_rhs, index, lhsTypeSignature );
		}
		else
		{
			HCOMMON_ASSERT_ALWAYS( "unknow type" );
		}
	}

	return( in_out_lhs );
}

/**/
