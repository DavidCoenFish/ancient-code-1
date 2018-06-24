//file: Pride/PGeometry/PGeometryVertexImplementation.cpp
#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryVertexImplementation.h"

#include "Pride/PGeometry/PGeometryVertexVariant.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 >TStaticArray4PairRealSint;
typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 >TStaticArray16PairRealSint;
typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 >TStaticArray64PairRealSint;

////////////////////////////////////////////////
// local static functions
/**/
static HBOOL LocalTypeTest( const PGeometryTypeSignatureImplementation& in_typeSignature, const HSINT in_topologyVertexIndex, const HSINT in_index, const PGeometryVertexVariant& in_variant )
{
	HBOOL match = HTRUE;
	const HSINT dataStoreIndex = in_typeSignature.TopologyStreamArrayIndexGet( in_topologyVertexIndex ).operator []( in_index );
	const HSINT type = in_typeSignature.DataStreamTypeGet( dataStoreIndex ); 

	if( type == PGeometryTypeSignatureImplementation::TypeGetDataSint() )
	{
		match &= ( HTRUE == in_variant.TypeTest< HSINT >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataReal() )
	{
		match &= ( HTRUE == in_variant.TypeTest< HREAL >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataRealSint() )
	{
		match &= ( HTRUE == in_variant.TypeTest< TPairRealSint >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR2() )
	{
		match &= ( HTRUE == in_variant.TypeTest< HVectorR2 >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR3() )
	{
		match &= ( HTRUE == in_variant.TypeTest< HVectorR3 >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataVectorR4() )
	{
		match &= ( HTRUE == in_variant.TypeTest< HVectorR4 >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataColour() )
	{
		match &= ( HTRUE == in_variant.TypeTest< PColourRgba >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataColourReal() )
	{
		match &= ( HTRUE == in_variant.TypeTest< PColourRealRgba >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray4PairRealSint() )
	{
		match &= ( HTRUE == in_variant.TypeTest< TStaticArray4PairRealSint >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray16PairRealSint() )
	{
		match &= ( HTRUE == in_variant.TypeTest< TStaticArray16PairRealSint >() );
	}
	else if( type == PGeometryTypeSignatureImplementation::TypeGetDataStaticArray64PairRealSint() )
	{
		match &= ( HTRUE == in_variant.TypeTest< TStaticArray64PairRealSint >() );
	}
	else
	{
		HCOMMON_ASSERT_ALWAYS( "missing case" );
		match = HFALSE;
	}

	return match;
}

////////////////////////////////////////////////
// creation
/**/
PGeometryVertexImplementation::PGeometryVertexImplementation( const PGeometryVertexImplementation& in_src )
: m_typeSignature( in_src.TypeSignatureGet() )
, m_data()
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryVertexImplementation::PGeometryVertexImplementation( 
	const PGeometryTypeSignatureImplementation& in_typeSignature, 
	const Hubris::HSINT in_topologyVertexIndex
	)
: m_typeSignature( in_typeSignature )
, m_topologyVertexIndex( in_topologyVertexIndex )
, m_data()
{
	const HSINT size = m_typeSignature.TopologyStreamArrayIndexGet( m_topologyVertexIndex ).SizeGet();
	m_data.SizeSet( size );
	return;
}

/**/
PGeometryVertexImplementation::~PGeometryVertexImplementation()
{
	return;
}

////////////////////////////////////////////////
// operator
/**/
const PGeometryVertexImplementation& PGeometryVertexImplementation::operator=( const PGeometryVertexImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_typeSignature = in_rhs.m_typeSignature;
		m_topologyVertexIndex = in_rhs.m_topologyVertexIndex;
		m_data = in_rhs.m_data;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryVertexImplementation::operator==( const PGeometryVertexImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_typeSignature == in_rhs.m_typeSignature );
		match &= ( m_topologyVertexIndex == in_rhs.m_topologyVertexIndex );
		match &= ( m_data == in_rhs.m_data );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryVertexImplementation::operator!=( const PGeometryVertexImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

////////////////////////////////////////////////
// public methods
/**/
HVOID PGeometryVertexImplementation::Clear()
{
	HCOMMON_FOR_EACH( data, m_data, TArrayData )
	{
		data = PGeometryVertexVariant();
	}

	return;
}

////////////////////////////////////////////////
// public accessors
/**/
HVOID PGeometryVertexImplementation::VariantSet( const Hubris::HSINT in_index, const PGeometryVertexVariant& in_variant )
{
	HCOMMON_ASSERT( HTRUE == LocalTypeTest( m_typeSignature, m_topologyVertexIndex, in_index, in_variant ), "incorrect data" );

	m_data[ in_index ] = in_variant;

	return;
}

/**/
const PGeometryVertexVariant& PGeometryVertexImplementation::VariantGet( const Hubris::HSINT in_index )const
{
	return m_data[ in_index ];
}

/**/
