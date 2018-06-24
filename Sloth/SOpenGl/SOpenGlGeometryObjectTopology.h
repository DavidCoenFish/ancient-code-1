//file: Sloth/SOpenGl/SOpenGlGeometryObjectTopology.h
#ifndef _S_OPEN_GL_GEOMETRY_OBJECT_TOPOLOGY_H_
#define _S_OPEN_GL_GEOMETRY_OBJECT_TOPOLOGY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGl;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SOpenGlGeometryObjectTopology
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlGeometryObjectTopology( const SOpenGlGeometryObjectTopology& in_src );
		SOpenGlGeometryObjectTopology(
			const Hubris::HSINT in_drawMode,
			const Hubris::HSINT in_drawElementType,
			const Hubris::HSINT in_drawCount,
			const Hubris::HSINT in_drawStartIndex,
			const Hubris::HSINT in_vertexBufferObjectIndex
			);
		SOpenGlGeometryObjectTopology();
		~SOpenGlGeometryObjectTopology();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SOpenGlGeometryObjectTopology& operator=( const SOpenGlGeometryObjectTopology& in_rhs );
		const Hubris::HBOOL operator==( const SOpenGlGeometryObjectTopology& in_rhs )const;
		const Hubris::HBOOL operator!=( const SOpenGlGeometryObjectTopology& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT DrawModeGet()const{ return m_drawMode; }
		Hubris::HVOID DrawModeSet( const Hubris::HSINT in_drawMode ){ m_drawMode = in_drawMode; return; }

		const Hubris::HSINT DrawElementTypeGet()const{ return m_drawElementType; }
		Hubris::HVOID DrawElementTypeSet( const Hubris::HSINT in_drawElementType ){ m_drawElementType = in_drawElementType; return; }

		const Hubris::HSINT DrawStartIndexGet()const{ return m_drawStartIndex; }
		Hubris::HVOID DrawStartIndexSet( const Hubris::HSINT in_drawStartIndex ){ m_drawStartIndex = in_drawStartIndex; return; }

		const Hubris::HSINT DrawCountGet()const{ return m_drawCount; }
		Hubris::HVOID DrawCountSet( const Hubris::HSINT in_drawCount ){ m_drawCount = in_drawCount; return; }

		const Hubris::HSINT VertexBufferObjectIndexGet()const{ return m_vertexBufferObjectIndex; }
		Hubris::HVOID VertexBufferObjectIndexSet( const Hubris::HSINT in_vertexBufferObjectIndex ){ m_vertexBufferObjectIndex = in_vertexBufferObjectIndex; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_drawMode;
		Hubris::HSINT m_drawElementType;
		Hubris::HSINT m_drawCount;
		Hubris::HSINT m_drawStartIndex;
		Hubris::HSINT m_vertexBufferObjectIndex;

	};

	/**/
	
};

#endif // _S_OPEN_GL_GEOMETRY_OBJECT_TOPOLOGY_H_