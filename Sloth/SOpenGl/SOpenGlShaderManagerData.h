//file: Sloth/SOpenGl/SOpenGlShaderManagerData.h
#ifndef _S_OPEN_GL_SHADER_MANAGER_DATA_H_
#define _S_OPEN_GL_SHADER_MANAGER_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGl;
	class SMaterialStageShader;

	///////////////////////////////////////////////////////
	// class
	/*
		trying to move towards RAII, 
			requires keeping reference to openGl object to release resources on destruction though
	*/
	class SOpenGlShaderManagerData : public Hubris::HSmartPointerObjectBase< SOpenGlShaderManagerData >
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlShaderManagerData(
			SOpenGl& in_out_openGl,
			const SMaterialStageShader& in_shader
			);
		~SOpenGlShaderManagerData();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SOpenGlShaderManagerData( const SOpenGlShaderManagerData& in_src );
		const SOpenGlShaderManagerData& operator=( const SOpenGlShaderManagerData& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL ValidGet()const{ return m_valid; }

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HU32 ShaderIdVertexGet()const{ return m_shaderIdVertex; }
		const Hubris::HU32 ShaderIdFragmentGet()const{ return m_shaderIdFragment; }
		const Hubris::HU32 ProgramIdGet()const{ return m_programId; }

		///////////////////////////////////////////////////////
		// private members
	private:
		SOpenGl& m_openGl;
		Hubris::HU32 m_shaderIdVertex;
		Hubris::HU32 m_shaderIdFragment;
		Hubris::HU32 m_programId;
		Hubris::HBOOL m_valid;

	};

	/**/
	
};

#endif // _S_OPEN_GL_SHADER_MANAGER_DATA_H_