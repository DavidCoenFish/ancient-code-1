//file: Sloth/SOpenGl/SOpenGlShaderManager.h
#ifndef _S_OPEN_GL_SHADER_MANAGER_H_
#define _S_OPEN_GL_SHADER_MANAGER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SOpenGl/SOpenGlShaderManagerData.h"
#include "Sloth/SMaterial/SMaterialStageShaderData.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGl;
	class SMaterialStageShader;
	//class SMaterialStageShaderData;
	class SMaterialStageShaderDataVariant;

	///////////////////////////////////////////////////////
	// struct
	/**/
	class SOpenGlShaderManager
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< SOpenGlShaderManagerData >TDataPointer;
		typedef Hubris::HContainerTree< Hubris::HString, TDataPointer >TTreeStringData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlShaderManager();
		~SOpenGlShaderManager();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SOpenGlShaderManager( const SOpenGlShaderManager& in_src );
		const SOpenGlShaderManager& operator=( const SOpenGlShaderManager& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL ShaderCreate(
			SOpenGl& in_out_openGl,
			const Hubris::HString& in_shaderName,
			const SMaterialStageShader& in_shader
			);
		Hubris::HVOID ShaderRelease(
			SOpenGl& in_out_openGl,
			const Hubris::HString& in_shaderName
			);
		Hubris::HVOID ShaderReleaseAll(
			SOpenGl& in_out_openGl			
			);

		Hubris::HVOID ShaderSet(
			SOpenGl& in_out_openGl,
			const Hubris::HString& in_shaderName,
			const SMaterialStageShaderData& in_shaderData
			//const SMaterialStageShaderData& in_shaderDataVertex,
			//const SMaterialStageShaderData& in_shaderDataFragment
			);

		//allow render to update the 
		Hubris::HVOID ShaderVariableSet(
			SOpenGl& in_out_openGl,
			const Hubris::HString& in_variableName,
			SMaterialStageShaderDataVariant& in_variant
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		TTreeStringData m_treeShaders;

		//data for the shader updated from the opengl state, like fog param or number of lights
		SMaterialStageShaderData m_shaderVariable;
		Hubris::HBOOL m_shaderVariableDirty;

		Hubris::HString m_currentShader;
		SMaterialStageShaderData m_currentShaderData;
		//SMaterialStageShaderData m_currentShaderDataVertex;
		//SMaterialStageShaderData m_currentShaderDataFragment;

	};

	/**/
	
};

#endif // _S_OPEN_GL_SHADER_MANAGER_H_