//file: Pride/PGeometry/PGeometry.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometry.h"

#include "Pride/PGeometry/PGeometryImplementation.h"
#include "Pride/PGeometry/PGeometryTypeSignature.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PGeometry::PGeometry( const PGeometryTypeSignature& in_typeSigniture ) 
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PGeometryImplementation, in_typeSigniture.ImplementationGet() );
	return;
}

/**/
PGeometry::PGeometry( const PGeometry& in_src ) 
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PGeometryImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PGeometry::PGeometry() 
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PGeometryImplementation );
	return;
}

/**/
PGeometry::~PGeometry() 
{
	HCOMMON_DELETE( m_pImplementation, PGeometryImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PGeometry& PGeometry::operator=( const PGeometry& in_rhs )
{	
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL PGeometry::operator==( const PGeometry& in_rhs )const
{	
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PGeometry::operator!=( const PGeometry& in_rhs )const
{	
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

///////////////////////////////////////////////////////
// public methods
HVOID PGeometry::Clear()
{
	ImplementationGet().Clear();
	return;
}

///////////////////////////////////////////////////////
// public accessors
/**/
const PGeometryTypeSignature PGeometry::TypeSignatureGet()const
{
	return PGeometryTypeSignature( ImplementationGet().TypeSignatureGet() );
}

/**/
Hubris::HVOID PGeometry::TypeSignatureSet( const PGeometryTypeSignature& in_typeSignature )
{
	ImplementationGet().TypeSignatureSet( in_typeSignature.ImplementationGet() );
	return;
}

/**/
const PGeometryStoreVertexIndex& PGeometry::StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreTopologyVertexIndexGet( in_index );
}

/**/
PGeometryStoreVertexIndex& PGeometry::StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreTopologyVertexIndexGet( in_index );
}

/**/
const PGeometryStoreTriangleStrip& PGeometry::StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreTopologyTriangleStripGet( in_index );
}

/**/
PGeometryStoreTriangleStrip& PGeometry::StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreTopologyTriangleStripGet( in_index );
}

/**/
const PGeometryStoreTriangle& PGeometry::StoreTopologyTriangleGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreTopologyTriangleGet( in_index );
}

/**/
PGeometryStoreTriangle& PGeometry::StoreTopologyTriangleGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreTopologyTriangleGet( in_index );
}

/**/
const PGeometryStoreDataSint& PGeometry::StoreDataSintGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataSintGet( in_index );
}

/**/
PGeometryStoreDataSint& PGeometry::StoreDataSintGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataSintGet( in_index );
}

/**/
const PGeometryStoreDataReal& PGeometry::StoreDataRealGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataRealGet( in_index );
}

/**/
PGeometryStoreDataReal& PGeometry::StoreDataRealGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataRealGet( in_index );
}

/**/
const PGeometryStoreDataVectorR2& PGeometry::StoreDataVectorR2Get( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataVectorR2Get( in_index );
}

/**/
PGeometryStoreDataVectorR2& PGeometry::StoreDataVectorR2Get( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataVectorR2Get( in_index );
}

/**/
const PGeometryStoreDataVectorR3& PGeometry::StoreDataVectorR3Get( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataVectorR3Get( in_index );
}

/**/
PGeometryStoreDataVectorR3& PGeometry::StoreDataVectorR3Get( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataVectorR3Get( in_index );
}

/**/
const PGeometryStoreDataVectorR4& PGeometry::StoreDataVectorR4Get( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataVectorR4Get( in_index );
}

/**/
PGeometryStoreDataVectorR4& PGeometry::StoreDataVectorR4Get( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataVectorR4Get( in_index );
}

/**/
const PGeometryStoreDataRealSint& PGeometry::StoreDataRealSintGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataRealSintGet( in_index );
}

/**/
PGeometryStoreDataRealSint& PGeometry::StoreDataRealSintGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataRealSintGet( in_index );
}

/**/
const PGeometryStoreDataColourRgba& PGeometry::StoreDataColourRgbaGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataColourRgbaGet( in_index );
}

/**/
PGeometryStoreDataColourRgba& PGeometry::StoreDataColourRgbaGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataColourRgbaGet( in_index );
}

/**/
const PGeometryStoreDataColourRealRgba& PGeometry::StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataColourRealRgbaGet( in_index );
}

/**/
PGeometryStoreDataColourRealRgba& PGeometry::StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataColourRealRgbaGet( in_index );
}

/**/
const PGeometryStoreDataStaticArray4PairRealSint& PGeometry::StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataStaticArray4PairRealSintGet( in_index );
}

/**/
PGeometryStoreDataStaticArray4PairRealSint& PGeometry::StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataStaticArray4PairRealSintGet( in_index );
}

/**/
const PGeometryStoreDataStaticArray16PairRealSint& PGeometry::StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataStaticArray16PairRealSintGet( in_index );
}

/**/
PGeometryStoreDataStaticArray16PairRealSint& PGeometry::StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataStaticArray16PairRealSintGet( in_index );
}

/**/
const PGeometryStoreDataStaticArray64PairRealSint& PGeometry::StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().StoreDataStaticArray64PairRealSintGet( in_index );
}

/**/
PGeometryStoreDataStaticArray64PairRealSint& PGeometry::StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index )
{
	return ImplementationGet().StoreDataStaticArray64PairRealSintGet( in_index );
}

///////////////////////////////////////////////////////
// private accessors
/**/
const PGeometryImplementation& PGeometry::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PGeometryImplementation& PGeometry::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
