//file: Pride/PGeometry/PGeometryUtility.h
#ifndef _P_GEOMETRY_UTILITY_H_
#define _P_GEOMETRY_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >


namespace Hubris
{
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PGeometryStoreTriangleStrip;
	class PGeometryStoreVertexIndex;
	class PGeometryStoreTriangle;
	class PGeometryTypeSignature;
	class PGeometryVertex;
	class PGeometry;

	///////////////////////////////////////////////////////
	// class
	/*
		utitility and vertex currently deal with 'simplified' pgeometry objects
		expect certain patterns of data (like "position" vectorR3
	*/
	struct PGeometryUtility
	{
		////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;

		////////////////////////////////////////////////
		// static public methods
	public:
		/*
			policy, passing an extra param for channel rather than to just use index? a bit of a mess
		*/

		//give the index of the topology vertex store you want to add to
		static Hubris::HSINT VertexUniqueAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex );
		//add data, return index 
		static Hubris::HSINT VertexAdd( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const PGeometryVertex& in_vertex );
		static Hubris::HVOID VertexGet( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex, const PGeometry& in_geometry, const Hubris::HSINT in_vertexIndex );
		
		static const Hubris::HSINT DataStoreIndexGet( 
			const PGeometryTypeSignature& in_typeSignature, 
			const Hubris::HString& in_name,
			const Hubris::HSINT in_type
			);

		static const Hubris::HSINT VertexDataStoreIndexGet( 
			const PGeometryTypeSignature& in_typeSignature, 
			const Hubris::HSINT in_vertexTopologyIndex,
			const Hubris::HString& in_name,
			const Hubris::HSINT in_type
			);

		//convert the input src geometry into dest geometry
		/*
			attempt to make this a safe function, may need to provide default values for missing data

			simple function, will not correctly handdle complicated topology, takes firswt strip then trinagle stream
			of src and dest and convert between them
		*/
		static Hubris::HVOID PGeometryConvert( 
			PGeometry& out_destGeometry, 
			const PGeometry& in_srcGenericGeometry,
			const PGeometryTypeSignature& in_destSignature, 
			const PGeometryTypeSignature& in_srcSignature
			);

		//set the values in a vertex to the defaults for each type
		static Hubris::HVOID DefaultVertex( const PGeometryTypeSignature& in_typeSignature, PGeometryVertex& out_vertex );

		static Hubris::HVOID TranslateGeometry( const PGeometryTypeSignature& in_typeSignature, PGeometry& in_out_geometry, const Hubris::HMatrixR4& in_matrix );

		static const Hubris::HSINT DataStoreTypeSkinDataGet( const Hubris::HSINT in_maxWeightsPerVertex );

		//return true if the give topology vertex has skinning, and return the position and normal data stream index
		static const Hubris::HBOOL SkinningDataStreamIndexGet(
			Hubris::HSINT& out_positionDataStreamIndex,
			Hubris::HSINT& out_normalDataStreamIndex,
			const PGeometryTypeSignature& in_typeSignature,
			const Hubris::HSINT in_topologyVertexIndex
			);

		static Hubris::HVOID PerformSkinning( 
			TArrayReal& out_vertexPosition,
			TArrayReal& out_vertexNormal,
			const PGeometryTypeSignature& in_typeSignature, 
			const PGeometry& in_geometry,
			const Hubris::HSINT in_topologyVertexIndex,
			const TArrayMatrix& in_arrayMatrix
			);

		//return true if the give topology vertex has spring, and return the position data stream index
		static const Hubris::HBOOL SpringDataStreamIndexGet(
			Hubris::HSINT& out_positionDataStreamIndex,
			const PGeometryTypeSignature& in_typeSignature,
			const Hubris::HSINT in_topologyVertexIndex
			);

		static Hubris::HVOID PerformSpring( 
			TArrayReal& in_out_vertexPosition,
			TArrayVector& in_out_vertexVelocity,
			const TArrayReal& in_targetVertexPosition,//could be out of PGeometry, but want to allow sking output as input
			const PGeometryTypeSignature& in_typeSignature, 
			const PGeometry& in_geometry,
			const Hubris::HSINT in_topologyVertexIndex,
			const Hubris::HREAL in_timeDelta
			);

		////////////////////////////////////////////////
		// disabled
	private:
		~PGeometryUtility();

	};
	/**/
	
};

#endif // _P_GEOMETRY_UTILITY_H_