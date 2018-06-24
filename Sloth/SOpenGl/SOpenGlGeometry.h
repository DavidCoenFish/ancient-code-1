//file: Sloth/SOpenGl/SOpenGlGeometry.h
#ifndef _S_OPEN_GL_GEOMETRY_H_
#define _S_OPEN_GL_GEOMETRY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SOpenGl;
	class SMaterialGeometryStage;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SOpenGlGeometry
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HVOID* const TObjectHandle;

		///////////////////////////////////////////////////////
		// disabled
	public:
		~SOpenGlGeometry();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID DrawGeometry(
			const TObjectHandle in_geometryIndex,
			SOpenGl& in_openGl,
			const SMaterialGeometryStage& in_renderStage
			);
		static const TObjectHandle GeometryCreate(
			const Pride::PGeometry& in_geometry,
			const TArraySint& in_arrayDynamicIndex,
			SOpenGl& in_openGl
			);
		static Hubris::HVOID GeometryUpdateData(
			const TObjectHandle in_geometryIndex,
			const Hubris::HSINT in_geometryDataIndex,
			const Hubris::HVOID* const in_pData,
			const Hubris::HSINT in_offset,
			const Hubris::HSINT in_size,
			SOpenGl& in_openGl
			);
		static Hubris::HVOID GeometryUpdateTopology(
			const TObjectHandle in_geometryIndex,
			const Hubris::HSINT in_topologyIndex,
			const Hubris::HSINT in_start,
			const Hubris::HSINT in_count,
			SOpenGl& in_openGl
			);
		static Hubris::HVOID GeometryRelease(
			const TObjectHandle in_geometryIndex,
			SOpenGl& in_openGl
			);

	};

	/**/
	
};

#endif // _S_OPEN_GL_GEOMETRY_H_