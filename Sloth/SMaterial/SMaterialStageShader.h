//file: Sloth/SMaterial/SMaterialStageShader.h
#ifndef _S_MATERIAL_STAGE_SHADER_H_
#define _S_MATERIAL_STAGE_SHADER_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class SMaterialStageShader
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SMaterialStageShader( const SMaterialStageShader& in_src );
		SMaterialStageShader();
		~SMaterialStageShader();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SMaterialStageShader& operator=( const SMaterialStageShader& in_rhs );
		const Hubris::HBOOL operator==( const SMaterialStageShader& in_rhs )const;
		const Hubris::HBOOL operator!=( const SMaterialStageShader& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& ShaderGLSLVertexGet()const{ return m_shaderGLSLVertex; }
		Hubris::HString& ShaderGLSLVertexGet(){ return m_shaderGLSLVertex; }

		const Hubris::HString& ShaderGLSLFragmentGet()const{ return m_shaderGLSLFragment; }
		Hubris::HString& ShaderGLSLFragmentGet(){ return m_shaderGLSLFragment; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_shaderGLSLVertex;
		Hubris::HString m_shaderGLSLFragment;

	};

	/**/
	
};

#endif // _S_MATERIAL_STAGE_SHADER_H_