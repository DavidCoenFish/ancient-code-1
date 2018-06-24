//file: Pride/PGeometry/PGeometryVertex.cpp
#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryVertex.h"

#include "Pride/PGeometry/PGeometryTypeSignature.h"
#include "Pride/PGeometry/PGeometryVertexImplementation.h"

#include "Pride/PColour/PColour_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// local static functions
/**/
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;

////////////////////////////////////////////////
// creation
/**/
PGeometryVertex::PGeometryVertex( const PGeometryVertex& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PGeometryVertexImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PGeometryVertex::PGeometryVertex( const PGeometryTypeSignature& in_typeSigniture, const Hubris::HSINT in_topologyVertexIndex )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM_2( 
		m_pImplementation, 
		PGeometryVertexImplementation, 
		in_typeSigniture.ImplementationGet(), 
		in_topologyVertexIndex 
		);
	return;
}

/**/
PGeometryVertex::~PGeometryVertex()
{
	return;
}

////////////////////////////////////////////////
// operator
/**/
const PGeometryVertex& PGeometryVertex::operator=( const PGeometryVertex& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();

	return( *this );
}

/**/
Hubris::HBOOL PGeometryVertex::operator==( const PGeometryVertex& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PGeometryVertex::operator!=( const PGeometryVertex& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

////////////////////////////////////////////////
// public methods
/**/
HVOID PGeometryVertex::Clear()
{
	ImplementationGet().Clear();
	return;
}

////////////////////////////////////////////////
// public accessors
/**/
const PGeometryTypeSignature PGeometryVertex::TypeSignatureGet()const
{
	return PGeometryTypeSignature( ImplementationGet().TypeSignatureGet() );
}

/**/
const Hubris::HSINT PGeometryVertex::TopologyVertexIndexGet()const
{
	return ImplementationGet().TopologyVertexIndexGet();
}

/**/
Hubris::HSINT PGeometryVertex::SintGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< HSINT >();
}

/**/
HVOID PGeometryVertex::SintSet( const Hubris::HSINT in_index, const Hubris::HSINT in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Hubris::HREAL PGeometryVertex::RealGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< HREAL >();
}

/**/
HVOID PGeometryVertex::RealSet( const Hubris::HSINT in_index, const Hubris::HREAL in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
PGeometryVertex::TPairRealSint PGeometryVertex::RealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< TPairRealSint >();
}

/**/
HVOID PGeometryVertex::RealSintSet( const Hubris::HSINT in_index, const TPairRealSint& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Hubris::HVectorR2 PGeometryVertex::VectorR2Get( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< HVectorR2 >();
}

/**/
HVOID PGeometryVertex::VectorR2Set( const Hubris::HSINT in_index, const Hubris::HVectorR2& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Hubris::HVectorR3 PGeometryVertex::VectorR3Get( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< HVectorR3 >();
}

/**/
HVOID PGeometryVertex::VectorR3Set( const Hubris::HSINT in_index, const Hubris::HVectorR3& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Hubris::HVectorR4 PGeometryVertex::VectorR4Get( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< HVectorR4 >();
}

/**/
HVOID PGeometryVertex::VectorR4Set( const Hubris::HSINT in_index, const Hubris::HVectorR4& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Pride::PColourRgba PGeometryVertex::ColourRgbaGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< Pride::PColourRgba >();
}

/**/
HVOID PGeometryVertex::ColourRgbaSet( const Hubris::HSINT in_index, const Pride::PColourRgba& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/**/
Pride::PColourRealRgba PGeometryVertex::ColourRgbaRealGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< Pride::PColourRealRgba >();
}

/**/
HVOID PGeometryVertex::ColourRgbaRealSet( const Hubris::HSINT in_index, const Pride::PColourRealRgba& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/*  4  */
PGeometryVertex::TStaticArray4PairRealSint PGeometryVertex::StaticArray4PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< TStaticArray4PairRealSint >();
}

/**/
Hubris::HVOID PGeometryVertex::StaticArray4PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray4PairRealSint& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/*  16  */
PGeometryVertex::TStaticArray16PairRealSint PGeometryVertex::StaticArray16PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< TStaticArray16PairRealSint >();
}

/**/
Hubris::HVOID PGeometryVertex::StaticArray16PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray16PairRealSint& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

/*  64  */
PGeometryVertex::TStaticArray64PairRealSint PGeometryVertex::StaticArray64PairRealSintGet( const Hubris::HSINT in_index )const
{
	const PGeometryVertexVariant& value = ImplementationGet().VariantGet( in_index );
	return value.ValueGet< TStaticArray64PairRealSint >();
}

/**/
Hubris::HVOID PGeometryVertex::StaticArray64PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray64PairRealSint& in_value )
{
	ImplementationGet().VariantSet( in_index, in_value );
	return;
}

////////////////////////////////////////////////
// private accessors
/**/
const PGeometryVertexImplementation& PGeometryVertex::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PGeometryVertexImplementation& PGeometryVertex::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
