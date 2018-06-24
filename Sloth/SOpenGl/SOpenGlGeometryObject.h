//file: Sloth/SOpenGl/SOpenGlGeometryObject.h
#ifndef _S_OPEN_GL_GEOMETRY_OBJECT_H_
#define _S_OPEN_GL_GEOMETRY_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SOpenGl/SOpenGlGeometryObjectData.h"
#include "Sloth/SOpenGl/SOpenGlGeometryObjectTopology.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGl;
	class SMaterialGeometryStage;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SOpenGlGeometryObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< SOpenGlGeometryObjectTopology >TArrayTopology;
		typedef Hubris::HContainerArray< SOpenGlGeometryObjectData >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SOpenGlGeometryObject(
			SOpenGl& in_openGl,
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_dynamicIndex
			);
		~SOpenGlGeometryObject();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SOpenGlGeometryObject( const SOpenGlGeometryObject& in_src );
		const SOpenGlGeometryObject& operator=( const SOpenGlGeometryObject& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID GeometryUpdateData(
			const Hubris::HSINT in_geometryDataIndex,
			const Hubris::HVOID* const in_pData,
			const Hubris::HSINT in_offset,
			const Hubris::HSINT in_size,
			SOpenGl& in_openGl
			);
		Hubris::HVOID GeometryUpdateTopology(
			const Hubris::HSINT in_index,
			const Hubris::HSINT in_startIndex,
			const Hubris::HSINT in_count,
			SOpenGl& in_openGl
			);

		const Hubris::HVOID Draw(
			SOpenGl& in_openGl,
			const SMaterialGeometryStage& in_renderStage
			)const;

		Hubris::HVOID GeometryRelease(
			SOpenGl& in_openGl
			);

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID GeometrySet(
			SOpenGl& in_openGl,
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_dynamicIndex
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayTopology m_arrayTopology;
		TArrayData m_arrayData;

	};

	/**/
	
};

#endif // _S_OPEN_GL_GEOMETRY_OBJECT_H_