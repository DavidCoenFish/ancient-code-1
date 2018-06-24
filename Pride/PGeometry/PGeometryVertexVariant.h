//file: Pride/PGeometry/PGeometryVertexVariant.h
#ifndef _P_GEOMETRY_VERTEX_VARIANT_H_
#define _P_GEOMETRY_VERTEX_VARIANT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

namespace Hubris
{
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};

namespace Pride
{
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	/**/
	typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TGeometryVertexDataPairRealSint;
	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 >TGeometryVertexDataStaticArray4PairRealSint;
	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 >TGeometryVertexDataStaticArray16PairRealSint;
	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 >TGeometryVertexDataStaticArray64PairRealSint;

	typedef HTYPE_LIST_11( 
		Hubris::HSINT,
		Hubris::HREAL, 
		Hubris::HVectorR2, 
		Hubris::HVectorR3,
		Hubris::HVectorR4,
		PColourRgba,
		PColourRealRgba,
		TGeometryVertexDataPairRealSint,

		TGeometryVertexDataStaticArray4PairRealSint,
		TGeometryVertexDataStaticArray16PairRealSint,
		TGeometryVertexDataStaticArray64PairRealSint

		) PGeometryVertexDataTypeList;
	
	/**/
	HVARIANT_DEFINITION( PGeometryVertexVariant, PGeometryVertexDataTypeList );

	/**/

};

#endif // _P_GEOMETRY_VERTEX_VARIANT_H_