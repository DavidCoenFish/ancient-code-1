//file: Sloth/SOpenGl/SOpenGlGeometry.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlGeometry.h"

#include "Sloth/SOpenGl/SOpenGl.h"
#include "Sloth/SOpenGl/SOpenGlGeometryObject.h"

#include "Sloth/SMaterial/SMaterial_Export.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID SOpenGlGeometry::DrawGeometry(
	const TObjectHandle in_geometryIndex,
	SOpenGl& in_openGl,
	const SMaterialGeometryStage& in_renderStage
	)
{
	SOpenGlGeometryObject* pGeometry = ( SOpenGlGeometryObject* )( in_geometryIndex );
	if( HNULL != pGeometry )
	{
		pGeometry->Draw(
			in_openGl,
			in_renderStage
			);
	}

	return;
}

/**/
const SOpenGlGeometry::TObjectHandle SOpenGlGeometry::GeometryCreate(
	const Pride::PGeometry& in_geometry,
	const TArraySint& in_arrayDynamicIndex,
	SOpenGl& in_openGl
	)
{
	SOpenGlGeometryObject *pObject = HNULL;
	HCOMMON_NEW_PARAM_3(
		pObject,
		SOpenGlGeometryObject,
		in_openGl,
		in_geometry,
		in_arrayDynamicIndex
		);

	return( ( TObjectHandle ) pObject );
}

/**/
Hubris::HVOID SOpenGlGeometry::GeometryUpdateData(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_geometryDataIndex,
	const Hubris::HVOID* const in_pData,
	const Hubris::HSINT in_offset,
	const Hubris::HSINT in_size,
	SOpenGl& in_openGl
	)
{
	SOpenGlGeometryObject* pGeometry = ( SOpenGlGeometryObject* )( in_geometryIndex );
	if( HNULL != pGeometry )
	{
		pGeometry->GeometryUpdateData(
			in_geometryDataIndex,
			in_pData,
			in_offset,
			in_size,
			in_openGl
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGlGeometry::GeometryUpdateTopology(
	const TObjectHandle in_geometryIndex,
	const Hubris::HSINT in_topologyIndex,
	const Hubris::HSINT in_start,
	const Hubris::HSINT in_count,
	SOpenGl& in_openGl
	)
{
	SOpenGlGeometryObject* pGeometry = ( SOpenGlGeometryObject* )( in_geometryIndex );
	if( HNULL != pGeometry )
	{
		pGeometry->GeometryUpdateTopology(
			in_topologyIndex,
			in_start,
			in_count,
			in_openGl
			);
	}
	return;
}

/**/
Hubris::HVOID SOpenGlGeometry::GeometryRelease(
	const TObjectHandle in_geometryIndex,
	SOpenGl& in_openGl
	)
{
	SOpenGlGeometryObject* pGeometry = ( SOpenGlGeometryObject* )( in_geometryIndex );
	if( HNULL != pGeometry )
	{
		pGeometry->GeometryRelease(
			in_openGl
			);

		HCOMMON_DELETE(
			pGeometry,
			SOpenGlGeometryObject
			);
	}

	return;
}

/**/
