//file: Sloth/SMaterial/SMaterialStage.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterialStage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TFlag
{
	enum TEnum
	{
		TNone				= 0x00000000,
		TTwoSide			= 0x00000001,
		TSmooth				= 0x00000002,
		TUseLight			= 0x00000004,
		TUseTexture			= 0x00000008,
		TUseVertexColour	= 0x00000010,
		TZRead				= 0x00000020,
		TZWrite				= 0x00000040,
		TSpeculareApproximation	= 0x00000080,
		TGenerateSphereUV	= 0x00000100,
		TAlphaTest			= 0x00000200,
		TAlphaBlend			= 0x00000400,
		//TUseBarrelDistortion = 0x00000800,

		TAlphaTestModeMask = 0x00F00000,
		TAlphaTestModeShift = 20,

		TBlendModeDestinationMask = 0x0F000000,
		TBlendModeDestinationShift = 24,

		TBlendModeSourceMask = 0xF0000000,
		TBlendModeSourceShift = 28,
	};
};

struct TBlendMode
{
	enum TEnum
	{
		TZero = 0,
		TOne,
		TDestinationColour,
		TSourceColour,
		TOneMinusDestinationColour,
		TOneMinusSourceColour,
		TSourceAlpha,
		TOneMinusSourceAlpha,
		TDestinationAlpha,
		TOneMinusDestinationAlpha,
		TSourceAlphaSaturate,

		TCount
	};
};

struct TAlphaTestMode
{
	enum TEnum
	{
		TNever = 0,
		TAlways,
		TLess,
		TLessEqual,
		TEqual,
		TGreaterEqual,
		TGreater,
		TNotEqual,

		TCount
	};
};

///////////////////////////////////////////////////////
// static local variables
/**/
static const HSINT s_defaultFlag = \
	TFlag::TSmooth | TFlag::TSpeculareApproximation | TFlag::TZRead | TFlag::TZWrite | \
	( TBlendMode::TSourceAlpha << TFlag::TBlendModeSourceShift ) | \
	( TBlendMode::TOneMinusSourceAlpha << TFlag::TBlendModeDestinationShift );
	// TFlag::TUseBarrelDistortion | \ 


///////////////////////////////////////////////////////
// static local methods
/* assumes only setting one bit at a time */
static HVOID LocalFlagSet( 
	Hubris::HSINT& in_out_flag,
	const HSINT in_value,
	const HBOOL in_active 
	)
{
	if( ( 0 != ( in_out_flag & in_value ) ) != in_active )
	{
		in_out_flag ^= in_value;
	}

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
SMaterialStage::SMaterialStage( const SMaterialStage& in_src )
: m_colourAmbient( 1.0F, 1.0F, 1.0F )
, m_colourDiffuse( 1.0F, 1.0F, 1.0F )
//, m_colourSpecular( 1.0F, 1.0F, 1.0F )
, m_colourEmission( 0.0F, 0.0F, 0.0F )
, m_alpha( 1.0F )
, m_shininess( 2.0F )
, m_alphaTestReference( 0 )
, m_flag( s_defaultFlag )
, m_texturePath()
, m_textureId( HCOMMON_INVALID_INDEX )
, m_shaderName()
, m_shaderData()
//, m_shaderDataVertex()
//, m_shaderDataFragment()
{
	( *this ) = in_src;
	return;
}

/**/
SMaterialStage::SMaterialStage()
: m_colourAmbient( 1.0F, 1.0F, 1.0F )
, m_colourDiffuse( 1.0F, 1.0F, 1.0F )
//, m_colourSpecular( 1.0F, 1.0F, 1.0F )
, m_colourEmission( 0.0F, 0.0F, 0.0F )
, m_alpha( 1.0F )
, m_shininess( 2.0F )
, m_alphaTestReference( 0 )
, m_flag( s_defaultFlag )
, m_texturePath()
, m_textureId( HCOMMON_INVALID_INDEX )
, m_shaderName()
, m_shaderData()
//, m_shaderDataVertex()
//, m_shaderDataFragment()
{
	return;
}

/**/
SMaterialStage::~SMaterialStage()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const SMaterialStage& SMaterialStage::operator=( const SMaterialStage& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_colourAmbient = in_rhs.m_colourAmbient;
		m_colourDiffuse = in_rhs.m_colourDiffuse;
		//m_colourSpecular = in_rhs.m_colourSpecular;
		m_colourEmission = in_rhs.m_colourEmission;
		m_alpha = in_rhs.m_alpha;
		m_shininess = in_rhs.m_shininess;
		m_alphaTestReference = in_rhs.m_alphaTestReference;
		//m_textureId = in_rhs.m_textureId;
		m_flag = in_rhs.m_flag;
		m_texturePath = in_rhs.m_texturePath;
		m_textureId = in_rhs.m_textureId;
		m_shaderName = in_rhs.m_shaderName;
		m_shaderData = in_rhs.m_shaderData;
	}

	return( *this );
}

/**/
Hubris::HBOOL SMaterialStage::operator==( const SMaterialStage& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_colourAmbient == in_rhs.m_colourAmbient );
		match &= ( m_colourDiffuse == in_rhs.m_colourDiffuse );
		//match &= ( m_colourSpecular == in_rhs.m_colourSpecular );
		match &= ( m_colourEmission == in_rhs.m_colourEmission );
		match &= ( m_alpha == in_rhs.m_alpha );
		match &= ( m_shininess == in_rhs.m_shininess );
		match &= ( m_alphaTestReference == in_rhs.m_alphaTestReference );
		//match &= ( m_textureId == in_rhs.m_textureId );
		match &= ( m_flag == in_rhs.m_flag );
		match &= ( m_texturePath == in_rhs.m_texturePath );
		match &= ( m_textureId == in_rhs.m_textureId );
		match &= ( m_shaderName == in_rhs.m_shaderName );
		match &= ( m_shaderData == in_rhs.m_shaderData );
	}

	return match;
}

/**/
Hubris::HBOOL SMaterialStage::operator!=( const SMaterialStage& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HREAL SMaterialStage::AlphaTestReferenceGet()const
{
	//const HREAL returnValue = ( ( HREAL )( m_alphaTestReference ) * 1.5259021896696421759365224689097e-5F );
	return m_alphaTestReference;
}

/**/
Hubris::HVOID SMaterialStage::AlphaTestReferenceSet( const Hubris::HREAL in_alphaTestReference )
{
	//m_alphaTestReference = ( HU16 )( ( HMathUtility::Clamp( in_alphaTestReference, 0.0F, 1.0F ) * 65535.0F ) + 0.5F );
	m_alphaTestReference = in_alphaTestReference;
	return;
}

/**/
const Hubris::HSINT SMaterialStage::TextureIdGet()const
{
	return m_textureId;
}

/**/
Hubris::HVOID SMaterialStage::TextureIdSet( const Hubris::HSINT in_textureId )
{
	m_textureId = in_textureId;

	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagTwoSidedGet()const
{
	return( 0 != ( m_flag & TFlag::TTwoSide ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagTwoSidedSet( const Hubris::HBOOL in_twoSided )
{
	LocalFlagSet( m_flag, TFlag::TTwoSide, in_twoSided );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagSmoothGet()const
{
	return( 0 != ( m_flag & TFlag::TSmooth ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagSmoothSet( const Hubris::HBOOL in_smooth )
{
	LocalFlagSet( m_flag, TFlag::TSmooth, in_smooth );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagUseLightGet()const
{
	return( 0 != ( m_flag & TFlag::TUseLight ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagUseLightSet( const Hubris::HBOOL in_useLight )
{
	LocalFlagSet( m_flag, TFlag::TUseLight, in_useLight );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagUseTextureGet()const
{
	return( 0 != ( m_flag & TFlag::TUseTexture ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagUseTextureSet( const Hubris::HBOOL in_useTexture )
{
	LocalFlagSet( m_flag, TFlag::TUseTexture, in_useTexture );
	return;
}

/**
const Hubris::HBOOL SMaterialStage::FlagUseVertexColourGet()const
{
	return( 0 != ( m_flag & TFlag::TUseVertexColour ) );
}

/**
Hubris::HVOID SMaterialStage::FlagUseVertexColourSet( const Hubris::HBOOL in_useVertexColour )
{
	LocalFlagSet( m_flag, TFlag::TUseVertexColour, in_useVertexColour );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagZReadGet()const
{
	return( 0 != ( m_flag & TFlag::TZRead ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagZReadSet( const Hubris::HBOOL in_zRead )
{
	LocalFlagSet( m_flag, TFlag::TZRead, in_zRead );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagZWriteGet()const
{
	return( 0 != ( m_flag & TFlag::TZWrite ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagZWriteSet( const Hubris::HBOOL in_zWrite )
{
	LocalFlagSet( m_flag, TFlag::TZWrite, in_zWrite );
	return;
}

/**
const Hubris::HBOOL SMaterialStage::FlagSpecularApproximationGet()const
{
	return( 0 != ( m_flag & TFlag::TSpeculareApproximation ) );
}

/**
Hubris::HVOID SMaterialStage::FlagSpecularApproximationSet( const Hubris::HBOOL in_specularApproximation )
{
	LocalFlagSet( m_flag, TFlag::TSpeculareApproximation, in_specularApproximation );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagGenerateSphereUVGet()const
{
	return( 0 != ( m_flag & TFlag::TGenerateSphereUV ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagGenerateSphereUVSet( const Hubris::HBOOL in_generateSphereUV )
{
	LocalFlagSet( m_flag, TFlag::TGenerateSphereUV, in_generateSphereUV );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagAlphaTestGet()const
{
	return( 0 != ( m_flag & TFlag::TAlphaTest ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagAlphaTestSet( const Hubris::HBOOL in_alphaTest )
{
	LocalFlagSet( m_flag, TFlag::TAlphaTest, in_alphaTest );
	return;
}

/**/
const Hubris::HBOOL SMaterialStage::FlagAlphaBlendGet()const
{
	return( 0 != ( m_flag & TFlag::TAlphaBlend ) );
}

/**/
Hubris::HVOID SMaterialStage::FlagAlphaBlendSet( const Hubris::HBOOL in_alphaBlend )
{
	LocalFlagSet( m_flag, TFlag::TAlphaBlend, in_alphaBlend );
	return;
}

/**
const Hubris::HBOOL SMaterialStage::FlagUseBarrelDistortionGet()const
{
	return( 0 != ( m_flag & TFlag::TUseBarrelDistortion ) );
}

/**
Hubris::HVOID SMaterialStage::FlagUseBarrelDistortionSet( const Hubris::HBOOL in_useBarrelDistortion )
{
	LocalFlagSet( m_flag, TFlag::TUseBarrelDistortion, in_useBarrelDistortion );
	return;
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeSourceGet()const
{
	const HSINT returnMode = ( ( m_flag & TFlag::TBlendModeSourceMask ) >> TFlag::TBlendModeSourceShift );
	return returnMode;
}

/**/
Hubris::HVOID SMaterialStage::BlendModeSourceSet( const Hubris::HSINT in_blendModeSource )
{
	m_flag &= ~TFlag::TBlendModeSourceMask;
	m_flag |= ( in_blendModeSource << TFlag::TBlendModeSourceShift );
	return;
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeDestinationGet()const
{
	const HSINT returnMode = ( ( m_flag & TFlag::TBlendModeDestinationMask ) >> TFlag::TBlendModeDestinationShift );
	return returnMode;
}

/**/
Hubris::HVOID SMaterialStage::BlendModeDestinationSet( const Hubris::HSINT in_blendModeDestination )
{
	m_flag &= ~TFlag::TBlendModeDestinationMask;
	m_flag |= ( in_blendModeDestination << TFlag::TBlendModeDestinationShift );
	return;
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeGet()const
{
	const HSINT returnMode = ( ( m_flag & TFlag::TAlphaTestModeMask ) >> TFlag::TAlphaTestModeShift );
	return returnMode;
}

/**/
Hubris::HVOID SMaterialStage::AlphaTestModeSet( const Hubris::HSINT in_alphaTestMode )
{
	m_flag &= ~TFlag::TAlphaTestModeMask;
	m_flag |= ( in_alphaTestMode << TFlag::TAlphaTestModeShift );
	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT SMaterialStage::BlendModeZeroGet()
{
	return( TBlendMode::TZero );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeOneGet()
{
	return( TBlendMode::TOne );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeDestinationColourGet()
{
	return( TBlendMode::TDestinationColour );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeSourceColourGet()
{
	return( TBlendMode::TSourceColour );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeOneMinusDestinationColourGet()
{
	return( TBlendMode::TOneMinusDestinationColour );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeOneMinusSourceColourGet()
{
	return( TBlendMode::TOneMinusSourceColour );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeSourceAlphaGet()
{
	return( TBlendMode::TSourceAlpha );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeOneMinusSourceAlphaGet()
{
	return( TBlendMode::TOneMinusSourceAlpha );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeDestinationAlphaGet()
{
	return( TBlendMode::TDestinationAlpha );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeOneMinusDestinationAlphaGet()
{
	return( TBlendMode::TOneMinusDestinationAlpha );
}

/**/
const Hubris::HSINT SMaterialStage::BlendModeSourceAlphaSaturateGet() 
{
	return( TBlendMode::TSourceAlphaSaturate );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeNeverGet()
{
	return( TAlphaTestMode::TNever );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeAlwaysGet()
{
	return( TAlphaTestMode::TAlways );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeLessGet()
{
	return( TAlphaTestMode::TLess );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeLessEqualGet()
{
	return( TAlphaTestMode::TLessEqual );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeEqualGet()
{
	return( TAlphaTestMode::TEqual );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeGreaterEqualGet()
{
	return( TAlphaTestMode::TGreaterEqual );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeGreaterGet()
{
	return( TAlphaTestMode::TGreater );
}

/**/
const Hubris::HSINT SMaterialStage::AlphaTestModeNotEqualGet()
{
	return( TAlphaTestMode::TNotEqual );
}

/**/
