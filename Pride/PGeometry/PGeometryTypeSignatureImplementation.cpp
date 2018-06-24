//file: Pride/PGeometry/PGeometryTypeSignatureImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< PGeometryTypeSignatureData >TArrayData;

////////////////////////////////////////////////
// local definitions
/**/
struct TType
{
	enum TEnum
	{
		TTopologyVertexIndex = 0,
		TTopologyTriangle,
		TTopologyStrip,
		TDataSint,
		TDataReal,
		TDataRealSint,
		TDataVector2,
		TDataVector3,
		TDataVector4,
		TDataColour,
		TDataColourReal,

		TDataStaticArray4PairRealSint,
		TDataStaticArray16PairRealSint,
		TDataStaticArray64PairRealSint,

	};
};

static const HCHAR* const s_nameTopology = "Topology";
static const HCHAR* const s_namePosition = "Position";
static const HCHAR* const s_nameNormal = "Normal";
static const HCHAR* const s_nameTangent = "Tangent";
static const HCHAR* const s_nameBinormal = "Binormal";
static const HCHAR* const s_nameColour = "Colour";
static const HCHAR* const s_nameUv = "Uv";
static const HCHAR* const s_nameContinuity = "Continuity";
static const HCHAR* const s_nameSkinWeight = "SkinWeight";
static const HCHAR* const s_nameSpring = "Spring";

////////////////////////////////////////////////
// local functions
/**
HVOID LocalOrStreamArray( TArrayData& in_out_destArrayData, const TArrayData& in_srcArrayData )
{
	HCOMMON_FOR_EACH_CONST( data, in_srcArrayData, TArrayData )
	{
		if( HFALSE == LocalStreamTest( in_out_destArrayData, data.TypeGet(), data.NameGet(), data.ChannelGet() ) )
		{
			in_out_destArrayData.Insert( data );
		}
	}

	return;
}

/**
HVOID LocalAndStreamArray( TArrayData& in_out_destArrayData, const TArrayData& in_srcArrayData )
{
	TArrayData result;

	HCOMMON_FOR_EACH_CONST( data, in_srcArrayData, TArrayData )
	{
		if( HTRUE == LocalStreamTest( in_out_destArrayData, data.TypeGet(), data.NameGet(), data.ChannelGet() ) )
		{
			result.Insert( data );
		}
	}

	in_out_destArrayData = result;

	return;
}

////////////////////////////////////////////////
// creation
/**/
PGeometryTypeSignatureImplementation::PGeometryTypeSignatureImplementation( const PGeometryTypeSignatureImplementation& in_src  )
: m_arrayTopology()
, m_arrayData()
{
	( *this ) = in_src;
	return;
}

/**/
PGeometryTypeSignatureImplementation::PGeometryTypeSignatureImplementation()
: m_arrayTopology()
, m_arrayData()
{
	return;
}

/**/
PGeometryTypeSignatureImplementation::~PGeometryTypeSignatureImplementation()
{
	return;
}

////////////////////////////////////////////////
// operators
/**/
const PGeometryTypeSignatureImplementation& PGeometryTypeSignatureImplementation::operator=( const PGeometryTypeSignatureImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayTopology = in_rhs.m_arrayTopology;
		m_arrayData = in_rhs.m_arrayData;
	}

	return( *this );
}

/**/
Hubris::HBOOL PGeometryTypeSignatureImplementation::operator==( const PGeometryTypeSignatureImplementation& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != &in_rhs )
	{
		match &= ( m_arrayTopology == in_rhs.m_arrayTopology );
		match &= ( m_arrayData == in_rhs.m_arrayData );
	}

	return match;
}

/**/
Hubris::HBOOL PGeometryTypeSignatureImplementation::operator!=( const PGeometryTypeSignatureImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**
const PGeometryTypeSignatureImplementation& PGeometryTypeSignatureImplementation::operator|=( const PGeometryTypeSignatureImplementation& in_rhs )
{
	LocalOrStreamArray( m_arrayTopology, in_rhs.m_arrayTopology );
	LocalOrStreamArray( m_arrayData, in_rhs.m_arrayData );

	return( *this );
}

/**
const PGeometryTypeSignatureImplementation& PGeometryTypeSignatureImplementation::operator&=( const PGeometryTypeSignatureImplementation& in_rhs )
{
	LocalAndStreamArray( m_arrayTopology, in_rhs.m_arrayTopology );
	LocalAndStreamArray( m_arrayData, in_rhs.m_arrayData );

	return( *this );
}

////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TopologyStreamAdd( const Hubris::HSINT in_type, const TArraySint& in_target )
{
	//add the stream
	const PGeometryTypeSignatureTopologyData data(
		in_type,
		in_target
		);

	const HSINT index = HContainerUtility::PushBack( m_arrayTopology, data );

	return index;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TopologyStreamCountGet()const
{
	return m_arrayTopology.SizeGet();
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TopologyStreamTypeGet( const Hubris::HSINT in_index )const
{
	return m_arrayTopology[ in_index ].TypeGet();
}

/**/
const PGeometryTypeSignatureImplementation::TArraySint& PGeometryTypeSignatureImplementation::TopologyStreamArrayIndexGet( const Hubris::HSINT in_index )const
{
	return m_arrayTopology[ in_index ].ArrayIndexGet();
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::DataStreamAdd( const Hubris::HSINT in_type, const Hubris::HString& in_name )
{
	//add the stream
	const PGeometryTypeSignatureData data(
		in_type,
		in_name
		);

	const HSINT index = HContainerUtility::PushBack( m_arrayData, data );

	return index;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::DataStreamCountGet()const
{
	return m_arrayData.SizeGet();
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::DataStreamTypeGet( const Hubris::HSINT in_index )const
{
	return m_arrayData[ in_index ].TypeGet();
}

/**/
const Hubris::HString& PGeometryTypeSignatureImplementation::DataStreamNameGet( const Hubris::HSINT in_index )const
{
	return m_arrayData[ in_index ].NameGet();
}

////////////////////////////////////////////////
// public static accessors
/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetTopologyVertexIndex()
{
	return TType::TTopologyVertexIndex;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetTopologyTriangle()
{
	return TType::TTopologyTriangle;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetTopologyTriangleStrip()
{
	return TType::TTopologyStrip;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataSint()
{
	return TType::TDataSint;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataReal()
{
	return TType::TDataReal;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataRealSint()
{
	return TType::TDataRealSint;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataVectorR2()
{
	return TType::TDataVector2;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataVectorR3()
{
	return TType::TDataVector3;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataVectorR4()
{
	return TType::TDataVector4;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataColour()
{
	return TType::TDataColour;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataColourReal()
{
	return TType::TDataColourReal;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataStaticArray4PairRealSint()
{
	return TType::TDataStaticArray4PairRealSint;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataStaticArray16PairRealSint()
{
	return TType::TDataStaticArray16PairRealSint;
}

/**/
const Hubris::HSINT PGeometryTypeSignatureImplementation::TypeGetDataStaticArray64PairRealSint()
{
	return TType::TDataStaticArray64PairRealSint;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetTopology()
{
	return s_nameTopology;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetPosition()
{
	return s_namePosition;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetNormal()
{
	return s_nameNormal;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetTangent()
{
	return s_nameTangent;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetBinormal()
{
	return s_nameBinormal;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetColour()
{
	return s_nameColour;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetUv()
{
	return s_nameUv;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetContinuity()
{
	return s_nameContinuity;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetSkinWeight()
{
	return s_nameSkinWeight;
}

/**/
const Hubris::HCHAR* const PGeometryTypeSignatureImplementation::NameGetSpring()
{
	return s_nameSpring;
}

/**/