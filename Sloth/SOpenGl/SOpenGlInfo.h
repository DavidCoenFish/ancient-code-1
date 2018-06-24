//file: Sloth/SOpenGl/SOpenGlInfo.h
#ifndef _S_OPEN_GL_INFO_H_
#define _S_OPEN_GL_INFO_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SOpenGlInfo
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerTree< Hubris::HString, Hubris::HSINT >TTreeStringInt;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlInfo();
		~SOpenGlInfo();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SOpenGlInfo( const SOpenGlInfo& in_src );
		const SOpenGlInfo& operator=( const SOpenGlInfo& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL ExtentionTest( const Hubris::HString& in_extention );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT MaxTextureSizeGet()const{ return m_maxTextureSize; }
		const Hubris::HSINT MaxLightsGet()const{ return m_maxLights; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_vendor;
		Hubris::HString m_renderer;
		Hubris::HString m_version;
		TTreeStringInt m_treeExtensions;
		TArrayString m_arrayExtentions; //easier to look at in debug than tree
		Hubris::HSINT m_redBits;
		Hubris::HSINT m_greenBits;
		Hubris::HSINT m_blueBits;
		Hubris::HSINT m_alphaBits;
		Hubris::HSINT m_depthBits;
		Hubris::HSINT m_stencilBits;
		Hubris::HSINT m_maxTextureSize;
		Hubris::HSINT m_maxLights;
		Hubris::HSINT m_maxAttribStacks;
		Hubris::HSINT m_maxModelViewStacks;
		Hubris::HSINT m_maxProjectionStacks;
		Hubris::HSINT m_maxClipPlanes;
		Hubris::HSINT m_maxTextureStacks;
		Hubris::HSINT m_maxMultipassTexureUnit;

	};

	/**/
	
};

#endif // _S_OPEN_GL_INFO_H_