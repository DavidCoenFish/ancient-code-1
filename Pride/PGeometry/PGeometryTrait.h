//file: Pride/PGeometry/PGeometryTrait.h
#ifndef _P_GEOMETRY_TRAIT_H_
#define _P_GEOMETRY_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HTrait/HTrait_Export.h >

/*
	could protect type, and memento via accessors. but would need to compose the names from index?
	otherwise have factories and owned pointers
*/

/**/
namespace Pride
{
	class PGeometry;
	class PGeometryStoreInterface;
	class PGeometryStoreTriangle;
	class PGeometryStoreTriangleStrip;
	class PGeometryStoreVertexIndex;
	class PGeometryTypeSignature;
	class PGeometryTypeSignatureData;
	class PGeometryTypeSignatureTopologyData;

	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	template< typename IN_TYPE >class PGeometryStoreData;

	typedef PGeometryStoreData< Hubris::HSINT >PGeometryStoreDataSint;
	typedef PGeometryStoreData< Hubris::HREAL >PGeometryStoreDataReal;
	typedef PGeometryStoreData< Hubris::HVectorR2 >PGeometryStoreDataVectorR2;
	typedef PGeometryStoreData< Hubris::HVectorR3 >PGeometryStoreDataVectorR3;
	typedef PGeometryStoreData< Hubris::HVectorR4 >PGeometryStoreDataVectorR4;
	typedef PGeometryStoreData< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT > >PGeometryStoreDataRealSint; //ie, weight and matrix id
	typedef PGeometryStoreData< Pride::PColourRgba >PGeometryStoreDataColourRgba;
	typedef PGeometryStoreData< Pride::PColourRealRgba >PGeometryStoreDataColourRealRgba;

};

/**/
namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	///////////////////////////////////////////////////////////
	// memento
	/**/
	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	//PGeometry
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometry& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometry& out_data );

	//PGeometryTypeSignature
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignature& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignature& out_data );

	//PGeometryTypeSignatureData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignatureData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignatureData& out_data );

	//PGeometryTypeSignatureTopologyData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignatureTopologyData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignatureTopologyData& out_data );

	//PGeometryStoreVertexIndex
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreVertexIndex& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreVertexIndex& out_data );
	//PGeometryStoreTriangleStrip
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreTriangleStrip& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreTriangleStrip& out_data );
	//PGeometryStoreTriangle
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreTriangle& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreTriangle& out_data );

	//PGeometryStoreDataSint
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataSint& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataSint& out_data );
	//PGeometryStoreDataReal
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataReal& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataReal& out_data );
	//PGeometryStoreDataVectorR2
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR2& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR2& out_data );
	//PGeometryStoreDataVectorR3
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR3& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR3& out_data );
	//PGeometryStoreDataVectorR4
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataVectorR4& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataVectorR4& out_data );
	//PGeometryStoreDataRealSint
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataRealSint& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataRealSint& out_data );
	//PGeometryStoreDataColourRgba
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataColourRgba& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataColourRgba& out_data );
	//PGeometryStoreDataColourRealRgba
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryStoreDataColourRealRgba& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryStoreDataColourRealRgba& out_data );

};


#endif // _P_GEOMETRY_TRAIT_H_