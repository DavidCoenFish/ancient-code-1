//file: Pride/PGeometry/PGeometryTypeSignature.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryTypeSignature.h"

#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// creation
/**/
PGeometryTypeSignature::PGeometryTypeSignature( const PGeometryTypeSignature& in_src  )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PGeometryTypeSignatureImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PGeometryTypeSignature::PGeometryTypeSignature( const PGeometryTypeSignatureImplementation& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PGeometryTypeSignatureImplementation, in_src );
	return;
}

/**/
PGeometryTypeSignature::PGeometryTypeSignature()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PGeometryTypeSignatureImplementation );
	return;
}

/**/
PGeometryTypeSignature::~PGeometryTypeSignature()
{
	HCOMMON_DELETE( m_pImplementation, PGeometryTypeSignatureImplementation );
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryTypeSignature& PGeometryTypeSignature::operator=( const PGeometryTypeSignature& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL PGeometryTypeSignature::operator==( const PGeometryTypeSignature& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PGeometryTypeSignature::operator!=( const PGeometryTypeSignature& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT PGeometryTypeSignature::TopologyStreamAdd( const Hubris::HSINT in_type, const Hubris::HSINT& in_arrayIndex )
{
	TArraySint arrayIndex;
	arrayIndex.Insert( in_arrayIndex );
	return TopologyStreamAdd( in_type, arrayIndex );
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TopologyStreamAdd( const Hubris::HSINT in_type, const TArraySint& in_arrayIndex )
{
	return ImplementationGet().TopologyStreamAdd( in_type, in_arrayIndex );
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TopologyStreamCountGet()const
{
	return ImplementationGet().TopologyStreamCountGet();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TopologyStreamTypeGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().TopologyStreamTypeGet( in_index );
}

const PGeometryTypeSignature::TArraySint& PGeometryTypeSignature::TopologyStreamArrayIndexGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().TopologyStreamArrayIndexGet( in_index );
}


/**/
const Hubris::HSINT PGeometryTypeSignature::DataStreamAdd( const Hubris::HSINT in_type, const Hubris::HString& in_name )
{
	return ImplementationGet().DataStreamAdd( in_type, in_name );
}

/**/
const Hubris::HSINT PGeometryTypeSignature::DataStreamCountGet()const
{
	return ImplementationGet().DataStreamCountGet();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::DataStreamTypeGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().DataStreamTypeGet( in_index );
}

/**/
const Hubris::HString& PGeometryTypeSignature::DataStreamNameGet( const Hubris::HSINT in_index )const
{
	return ImplementationGet().DataStreamNameGet( in_index );
}

////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetTopologyVertexIndex()
{
	return PGeometryTypeSignatureImplementation::TypeGetTopologyVertexIndex();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetTopologyTriangle()
{
	return PGeometryTypeSignatureImplementation::TypeGetTopologyTriangle();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetTopologyTriangleStrip()
{
	return PGeometryTypeSignatureImplementation::TypeGetTopologyTriangleStrip();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataSint() 
{
	return PGeometryTypeSignatureImplementation::TypeGetDataSint();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataReal()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataReal();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataRealSint()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataRealSint();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataVectorR2()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataVectorR2();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataVectorR3()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataVectorR3();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataVectorR4()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataVectorR4();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataColour()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataColour();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataColourReal()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataColourReal();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataStaticArray4PairRealSint();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataStaticArray16PairRealSint()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataStaticArray16PairRealSint();
}

/**/
const Hubris::HSINT PGeometryTypeSignature::TypeGetDataStaticArray64PairRealSint()
{
	return PGeometryTypeSignatureImplementation::TypeGetDataStaticArray64PairRealSint();
}

/**
const Hubris::HString PGeometryTypeSignature::NameGetTopology()
{
	return PGeometryTypeSignatureImplementation::NameGetTopology();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetPosition()
{
	return PGeometryTypeSignatureImplementation::NameGetPosition();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetNormal()
{
	return PGeometryTypeSignatureImplementation::NameGetNormal();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetTangent()
{
	return PGeometryTypeSignatureImplementation::NameGetTangent();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetBinormal()
{
	return PGeometryTypeSignatureImplementation::NameGetBinormal();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetColour()
{
	return PGeometryTypeSignatureImplementation::NameGetColour();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetUv()
{
	return PGeometryTypeSignatureImplementation::NameGetUv();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetContinuity()
{
	return PGeometryTypeSignatureImplementation::NameGetContinuity();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetSkinWeight()
{
	return PGeometryTypeSignatureImplementation::NameGetSkinWeight();
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignature::NameGetSpring()
{
	return PGeometryTypeSignatureImplementation::NameGetSpring();
}

////////////////////////////////////////////////
// private accessors
/**/
const PGeometryTypeSignatureImplementation& PGeometryTypeSignature::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PGeometryTypeSignatureImplementation& PGeometryTypeSignature::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/