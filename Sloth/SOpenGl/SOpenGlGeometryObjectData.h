//file: Sloth/SOpenGl/SOpenGlGeometryObjectData.h
#ifndef _S_OPEN_GL_GEOMETRY_OBJECT_DATA_H_
#define _S_OPEN_GL_GEOMETRY_OBJECT_DATA_H_

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
	class SOpenGlGeometryObjectData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlGeometryObjectData( const SOpenGlGeometryObjectData& in_src );
		SOpenGlGeometryObjectData(
			const Hubris::HSINT in_drawSize,
			const Hubris::HSINT in_drawType,
			const Hubris::HSINT in_vertexBufferObjectIndex
			);
		SOpenGlGeometryObjectData();
		~SOpenGlGeometryObjectData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SOpenGlGeometryObjectData& operator=( const SOpenGlGeometryObjectData& in_rhs );
		const Hubris::HBOOL operator==( const SOpenGlGeometryObjectData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SOpenGlGeometryObjectData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT DrawSizeGet()const{ return m_drawSize; }
		Hubris::HVOID DrawSizeSet( const Hubris::HSINT in_drawSize ){ m_drawSize = in_drawSize; return; }

		const Hubris::HSINT DrawTypeGet()const{ return m_drawType; }
		Hubris::HVOID DrawTypeSet( const Hubris::HSINT in_drawType ){ m_drawType = in_drawType; return; }

		const Hubris::HSINT VertexBufferObjectIndexGet()const{ return m_vertexBufferObjectIndex; }
		Hubris::HVOID VertexBufferObjectIndexSet( const Hubris::HSINT in_vertexBufferObjectIndex ){ m_vertexBufferObjectIndex = in_vertexBufferObjectIndex; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_drawSize;
		Hubris::HSINT m_drawType;
		Hubris::HSINT m_vertexBufferObjectIndex;

	};

	/**/
	
};

#endif // _S_OPEN_GL_GEOMETRY_OBJECT_DATA_H_