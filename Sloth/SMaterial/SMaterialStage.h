//file: Sloth/SMaterial/SMaterialStage.h
#ifndef _S_MATERIAL_STAGE_H_
#define _S_MATERIAL_STAGE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Sloth/SMaterial/SMaterialStageShaderData.h"

#include< Pride/PColour/PColour_Export.h >

namespace Sloth
{
	class SMaterialStage;
};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	//PGeometryTypeSignature
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialStage& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialStage& out_data );
};

namespace Sloth
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class SMaterialStage
	{
		friend Hubris::HVOID Envy::EMementoTraitCollect< SMaterialStage >( Envy::EMementoCollect& in_out_mementoCollect, const SMaterialStage& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< SMaterialStage >( const Envy::EMementoAssign& in_out_mementoAssign, SMaterialStage& out_data );

		///////////////////////////////////////////////////////
		// creation
	public:
		SMaterialStage( const SMaterialStage& in_src );
		SMaterialStage();
		~SMaterialStage();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SMaterialStage& operator=( const SMaterialStage& in_rhs );
		Hubris::HBOOL operator==( const SMaterialStage& in_rhs )const;
		Hubris::HBOOL operator!=( const SMaterialStage& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PColourRealRgb& ColourAmbientGet()const{ return m_colourAmbient; }
		Hubris::HVOID ColourAmbientSet( const Pride::PColourRealRgb& in_colourAmbient ){ m_colourAmbient = in_colourAmbient; return; }

		const Pride::PColourRealRgb& ColourDiffuseGet()const{ return m_colourDiffuse; }
		Hubris::HVOID ColourDiffuseSet( const Pride::PColourRealRgb& in_colourDiffuse ){ m_colourDiffuse = in_colourDiffuse; return; }

		//const Pride::PColourRealRgb& ColourSpecularGet()const{ return m_colourSpecular; }
		//Hubris::HVOID ColourSpecularSet( const Pride::PColourRealRgb& in_colourSpecular ){ m_colourSpecular = in_colourSpecular; return; }

		const Pride::PColourRealRgb& ColourEmissionGet()const{ return m_colourEmission; }
		Hubris::HVOID ColourEmissionSet( const Pride::PColourRealRgb& in_colourEmission ){ m_colourEmission = in_colourEmission; return; }

		const Hubris::HREAL AlphaGet()const{ return m_alpha; }
		Hubris::HVOID AlphaSet( const Hubris::HREAL in_alpha ){ m_alpha = in_alpha; return; }

		const Hubris::HREAL ShininessGet()const{ return m_shininess; }
		Hubris::HVOID ShininessGet( const Hubris::HREAL in_shininess ){ m_shininess = in_shininess; return; }

		const Hubris::HREAL AlphaTestReferenceGet()const;
		Hubris::HVOID AlphaTestReferenceSet( const Hubris::HREAL in_alphaTestReference );

		const Hubris::HSINT TextureIdGet()const;
		Hubris::HVOID TextureIdSet( const Hubris::HSINT in_textureId );

		const Hubris::HBOOL FlagTwoSidedGet()const;
		Hubris::HVOID FlagTwoSidedSet( const Hubris::HBOOL in_twoSided );

		const Hubris::HBOOL FlagSmoothGet()const;
		Hubris::HVOID FlagSmoothSet( const Hubris::HBOOL in_smooth );

		const Hubris::HBOOL FlagUseLightGet()const;
		Hubris::HVOID FlagUseLightSet( const Hubris::HBOOL in_useLight );

		const Hubris::HBOOL FlagUseTextureGet()const;
		Hubris::HVOID FlagUseTextureSet( const Hubris::HBOOL in_useTexture );

		//const Hubris::HBOOL FlagUseVertexColourGet()const;
		//Hubris::HVOID FlagUseVertexColourSet( const Hubris::HBOOL in_useVertexColour );

		const Hubris::HBOOL FlagZReadGet()const;
		Hubris::HVOID FlagZReadSet( const Hubris::HBOOL in_zRead );

		const Hubris::HBOOL FlagZWriteGet()const;
		Hubris::HVOID FlagZWriteSet( const Hubris::HBOOL in_zWrite );

		//const Hubris::HBOOL FlagSpecularApproximationGet()const;
		//Hubris::HVOID FlagSpecularApproximationSet( const Hubris::HBOOL in_specularApproximation );

		const Hubris::HBOOL FlagGenerateSphereUVGet()const;
		Hubris::HVOID FlagGenerateSphereUVSet( const Hubris::HBOOL in_generateSphereUV );

		const Hubris::HBOOL FlagAlphaTestGet()const;
		Hubris::HVOID FlagAlphaTestSet( const Hubris::HBOOL in_alphaTest );

		const Hubris::HBOOL FlagAlphaBlendGet()const;
		Hubris::HVOID FlagAlphaBlendSet( const Hubris::HBOOL in_alphaBlend );

		//const Hubris::HBOOL FlagUseBarrelDistortionGet()const;
		//Hubris::HVOID FlagUseBarrelDistortionSet( const Hubris::HBOOL in_useBarrelDistortion );

		const Hubris::HSINT BlendModeSourceGet()const;
		Hubris::HVOID BlendModeSourceSet( const Hubris::HSINT in_blendModeSource );

		const Hubris::HSINT BlendModeDestinationGet()const;
		Hubris::HVOID BlendModeDestinationSet( const Hubris::HSINT in_blendModeDestination );

		const Hubris::HSINT AlphaTestModeGet()const;
		Hubris::HVOID AlphaTestModeSet( const Hubris::HSINT in_alphaTestMode );

		const Hubris::HFileSystemPath& TexturePathGet()const{ return m_texturePath; }
		Hubris::HVOID TexturePathSet( const Hubris::HFileSystemPath& in_texturePath ){ m_texturePath = in_texturePath; return; }

		const Hubris::HString& ShaderNameGet()const{ return m_shaderName; }
		Hubris::HString& ShaderNameGet(){ return m_shaderName; }

		const SMaterialStageShaderData& ShaderDataGet()const{ return m_shaderData; }
		SMaterialStageShaderData& ShaderDataGet(){ return m_shaderData; }

		//const SMaterialStageShaderData& ShaderDataVertexGet()const{ return m_shaderDataVertex; }
		//SMaterialStageShaderData& ShaderDataVertexGet(){ return m_shaderDataVertex; }

		//const SMaterialStageShaderData& ShaderDataFragmentGet()const{ return m_shaderDataFragment; }
		//SMaterialStageShaderData& ShaderDataFragmentGet(){ return m_shaderDataFragment; }

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT BlendModeZeroGet();
		static const Hubris::HSINT BlendModeOneGet();
		static const Hubris::HSINT BlendModeDestinationColourGet();
		static const Hubris::HSINT BlendModeSourceColourGet();
		static const Hubris::HSINT BlendModeOneMinusDestinationColourGet();
		static const Hubris::HSINT BlendModeOneMinusSourceColourGet();
		static const Hubris::HSINT BlendModeSourceAlphaGet();
		static const Hubris::HSINT BlendModeOneMinusSourceAlphaGet();
		static const Hubris::HSINT BlendModeDestinationAlphaGet();
		static const Hubris::HSINT BlendModeOneMinusDestinationAlphaGet();
		static const Hubris::HSINT BlendModeSourceAlphaSaturateGet(); 

		static const Hubris::HSINT AlphaTestModeNeverGet();
		static const Hubris::HSINT AlphaTestModeAlwaysGet();
		static const Hubris::HSINT AlphaTestModeLessGet();
		static const Hubris::HSINT AlphaTestModeLessEqualGet();
		static const Hubris::HSINT AlphaTestModeEqualGet();
		static const Hubris::HSINT AlphaTestModeGreaterEqualGet();
		static const Hubris::HSINT AlphaTestModeGreaterGet();
		static const Hubris::HSINT AlphaTestModeNotEqualGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PColourRealRgb m_colourAmbient;
		Pride::PColourRealRgb m_colourDiffuse;
		//Pride::PColourRealRgb m_colourSpecular;
		Pride::PColourRealRgb m_colourEmission;
		Hubris::HREAL m_alpha; // 0 .. 1.0F
		Hubris::HREAL m_shininess; // specular exponent, 0 ... 128.0F
		Hubris::HREAL m_alphaTestReference; //map to 0 .. 1.0F
		//Hubris::HSINT m_textureId;
		Hubris::HSINT m_flag;

		Hubris::HFileSystemPath m_texturePath;
		//do not scribe the arraytextureId, that is run time resource
		Hubris::HSINT m_textureId;

		Hubris::HString m_shaderName;
		SMaterialStageShaderData m_shaderData;
		//SMaterialStageShaderData m_shaderDataVertex;
		//SMaterialStageShaderData m_shaderDataFragment;

	};

	/**/
	
};

#endif // _S_MATERIAL_STAGE_H_