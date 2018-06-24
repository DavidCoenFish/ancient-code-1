//file: Pride/PGeometry/PGeometryTrait.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryTrait.h"

#include "Pride/PGeometry/PGeometry.h"
#include "Pride/PGeometry/PGeometryImplementation.h"
#include "Pride/PGeometry/PGeometryStoreData.h"
#include "Pride/PGeometry/PGeometryStoreInterface.h"
#include "Pride/PGeometry/PGeometryStoreTriangle.h"
#include "Pride/PGeometry/PGeometryStoreTriangleStrip.h"
#include "Pride/PGeometry/PGeometryStoreVertexIndex.h"
#include "Pride/PGeometry/PGeometryTypeSignature.h"
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"
#include "Pride/PGeometry/PGeometryTypeSignatureTopologyData.h"

#include "Pride/PColour/PColour_Export.h"

#include< Envy/Envy_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

///////////////////////////////////////////////////////////
// static local variables
/**/
static const HCHAR* const s_typeSignature = "m_typeSignature";
static const HCHAR* const s_arrayTopology = "m_arrayTopology";
static const HCHAR* const s_arrayData = "m_arrayData";

///////////////////////////////////////////////////////////
// global functions
/**
Hubris::HVOID Envy::PGeometryTraitRegister()
{
	//EMEMENTO_FACTORY_REGISTER( PGeometryStoreInterface, PGeometryStoreInterface );
}


///////////////////////////////////////////////////////////
// static local methods
/**/
static const HString LocalNameGetTopology( const Hubris::HSINT in_index )
{
	return( HString( "m_topology" ) + HTraitStringIn( in_index ) );
}

/**/
static const HString LocalNameGetData( const Hubris::HSINT in_index )
{
	return( HString( "m_data" ) + HTraitStringIn( in_index ) );
}

///////////////////////////////////////////////////////////
// specialise memento
/**/
HVOID Envy::EMementoTraitCollect< PGeometry >( EMementoCollect& in_out_mementoCollect, const PGeometry& in_data )
{
	//in_out_mementoCollect.MemberAdd( s_typeSignature, in_data.ImplementationGet().m_typeSignature );
	//in_out_mementoCollect.OwnedPointerAdd( s_arrayTopology, in_data.ImplementationGet().m_arrayTopology );
	//in_out_mementoCollect.OwnedPointerAdd( s_arrayData, in_data.ImplementationGet().m_arrayData );

	const PGeometryTypeSignature typeSignature = in_data.TypeSignatureGet();
	in_out_mementoCollect.MemberAdd( s_typeSignature, typeSignature );

	const HSINT topologyCount = typeSignature.TopologyStreamCountGet();
	for( HSINT index = 0; index < topologyCount; ++index )
	{
		const HSINT type = typeSignature.TopologyStreamTypeGet( index );
		const HString mementoName = LocalNameGetTopology( index );

		if( type == PGeometryTypeSignature::TypeGetTopologyTriangle() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreTopologyTriangleGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyTriangleStrip() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreTopologyTriangleStripGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyVertexIndex() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreTopologyVertexIndexGet( index ) );
		}
	}

	const HSINT dataCount = typeSignature.DataStreamCountGet();
	for( HSINT index = 0; index < dataCount; ++index )
	{
		const HSINT type = typeSignature.DataStreamTypeGet( index );
		const HString mementoName = LocalNameGetData( index );

		if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataColourRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataColourRealRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataRealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataVectorR2Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataVectorR3Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			in_out_mementoCollect.MemberAdd( mementoName, in_data.StoreDataVectorR4Get( index ) );
		}
	}

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< PGeometry >( const EMementoAssign& in_out_mementoAssign, PGeometry& out_data )
{
	//in_out_mementoAssign.MemberGet( s_typeSignature, out_data.ImplementationGet().m_typeSignature );
	//in_out_mementoAssign.OwnedPointerGet( s_arrayTopology, out_data.ImplementationGet().m_arrayTopology );
	//in_out_mementoAssign.OwnedPointerGet( s_arrayData, out_data.ImplementationGet().m_arrayData );

	PGeometryTypeSignature typeSignature;
	in_out_mementoAssign.MemberGet( s_typeSignature, typeSignature );
	out_data.TypeSignatureSet( typeSignature );

	const HSINT topologyCount = typeSignature.TopologyStreamCountGet();
	for( HSINT index = 0; index < topologyCount; ++index )
	{
		const HSINT type = typeSignature.TopologyStreamTypeGet( index );
		const HString mementoName = LocalNameGetTopology( index );

		if( type == PGeometryTypeSignature::TypeGetTopologyTriangle() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreTopologyTriangleGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyTriangleStrip() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreTopologyTriangleStripGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetTopologyVertexIndex() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreTopologyVertexIndexGet( index ) );
		}
	}

	const HSINT dataCount = typeSignature.DataStreamCountGet();
	for( HSINT index = 0; index < dataCount; ++index )
	{
		const HSINT type = typeSignature.DataStreamTypeGet( index );
		const HString mementoName = LocalNameGetData( index );

		if( type == PGeometryTypeSignature::TypeGetDataColour() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataColourRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataColourReal() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataColourRealRgbaGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataReal() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataRealGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataRealSint() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataRealSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataSint() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataSintGet( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR2() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataVectorR2Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR3() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataVectorR3Get( index ) );
		}
		else if( type == PGeometryTypeSignature::TypeGetDataVectorR4() )
		{
			in_out_mementoAssign.MemberGet( mementoName, out_data.StoreDataVectorR4Get( index ) );
		}
	}

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryTypeSignature >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignature& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayTopology", in_data.ImplementationGet().m_arrayTopology );
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ImplementationGet().m_arrayData );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryTypeSignature >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignature& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayTopology", out_data.ImplementationGet().m_arrayTopology );
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ImplementationGet().m_arrayData );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryTypeSignatureData >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignatureData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_type", in_data.TypeGet() );
	in_out_mementoCollect.MemberAdd( "m_name", in_data.NameGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryTypeSignatureData >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignatureData& out_data )
{
	HSINT type = 0;
	in_out_mementoAssign.MemberGet( "m_type", type );
	out_data.TypeSet( type );

	HString name;
	in_out_mementoAssign.MemberGet( "m_name", name );
	out_data.NameSet( name );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryTypeSignatureTopologyData >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignatureTopologyData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_type", in_data.TypeGet() );
	const TArraySint& arrayIndex = in_data.ArrayIndexGet();
	in_out_mementoCollect.MemberAdd( "m_arrayIndex", arrayIndex );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryTypeSignatureTopologyData >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignatureTopologyData& out_data )
{
	HSINT type = 0;
	in_out_mementoAssign.MemberGet( "m_type", type );
	out_data.TypeSet( type );

	TArraySint arrayIndex;
	in_out_mementoAssign.MemberGet( "m_arrayIndex", arrayIndex );
	out_data.ArrayIndexSet( arrayIndex );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreVertexIndex >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreVertexIndex& in_data )
{
	const HSINT stride = in_data.StrideGet();
	in_out_mementoCollect.MemberAdd( "m_stride", stride );
	in_out_mementoCollect.MemberAdd( "m_arrayDataIndex", in_data.ArrayDataIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreVertexIndex >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreVertexIndex& out_data )
{
	HSINT stride = 0;
	in_out_mementoAssign.MemberGet( "m_stride", stride );
	out_data.StrideSet( stride );
	in_out_mementoAssign.MemberGet( "m_arrayDataIndex", out_data.ArrayDataIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreTriangleStrip >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreTriangleStrip& in_data )
{
	const HSINT triangleCount = in_data.TriangleCountGet();
	in_out_mementoCollect.MemberAdd( "m_triangleCount", triangleCount );

	const HSINT targetTopologyVertexIndex = in_data.TargetTopologyVertexIndexGet();
	in_out_mementoCollect.MemberAdd( "m_targetTopologyVertexIndex", targetTopologyVertexIndex );

	in_out_mementoCollect.MemberAdd( "m_arrayStripLengthsBase", in_data.ArrayStripLengthsBaseGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayVertexIndex", in_data.ArrayVertexIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreTriangleStrip >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreTriangleStrip& out_data )
{
	HSINT triangleCount = 0; //in_data.TriangleCountGet();
	in_out_mementoAssign.MemberGet( "m_triangleCount", triangleCount );
	out_data.TriangleCountSet( triangleCount );

	HSINT targetTopologyVertexIndex = HCOMMON_INVALID_INDEX; //in_data.TargetTopologyVertexIndexGet();
	in_out_mementoAssign.MemberGet( "m_targetTopologyVertexIndex", targetTopologyVertexIndex );
	out_data.TargetTopologyVertexIndexSet( targetTopologyVertexIndex );

	in_out_mementoAssign.MemberGet( "m_arrayStripLengthsBase", out_data.ArrayStripLengthsBaseGet() );
	in_out_mementoAssign.MemberGet( "m_arrayVertexIndex", out_data.ArrayVertexIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreTriangle >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreTriangle& in_data )
{
	const HSINT targetTopologyVertexIndex = in_data.TargetTopologyVertexIndexGet();
	in_out_mementoCollect.MemberAdd( "m_targetTopologyVertexIndex", targetTopologyVertexIndex );

	in_out_mementoCollect.MemberAdd( "m_arrayVertexIndex", in_data.ArrayVertexIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreTriangle >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreTriangle& out_data )
{
	HSINT targetTopologyVertexIndex = HCOMMON_INVALID_INDEX; //in_data.TargetTopologyVertexIndexGet();
	in_out_mementoAssign.MemberGet( "m_targetTopologyVertexIndex", targetTopologyVertexIndex );
	out_data.TargetTopologyVertexIndexSet( targetTopologyVertexIndex );

	in_out_mementoAssign.MemberGet( "m_arrayVertexIndex", out_data.ArrayVertexIndexGet() );

	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataSint >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataSint& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataSint >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataSint& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataReal >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataReal& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataReal >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataReal& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataVectorR2 >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR2& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataVectorR2 >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR2& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataVectorR3 >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR3& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataVectorR3 >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR3& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataVectorR4 >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR4& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataVectorR4 >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR4& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataRealSint >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataRealSint& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataRealSint >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataRealSint& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataColourRgba >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataColourRgba& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataColourRgba >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataColourRgba& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< PGeometryStoreDataColourRealRgba >( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataColourRealRgba& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< PGeometryStoreDataColourRealRgba >( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataColourRealRgba& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/**/
