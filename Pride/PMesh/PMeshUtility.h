//file: Pride/PMesh/PMeshUtility.h
#ifndef _P_MESH_UTILITY_H_
#define _P_MESH_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PMesh;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1;
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2;
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PMeshUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

		///////////////////////////////////////////////////////
		// public static methods
	public:
		static Hubris::HVOID TiangleVertexIndexArrayGet( 
			TArraySint& out_arrayTriangleVertexIndex,
			const PMesh& in_mesh
			);

		static Hubris::HVOID MeshTransform( 
			PMesh& in_out_mesh,
			const Hubris::HMatrixR4& in_transform
			);

		static Hubris::HVOID TrianglePointCloudGet( 
			TArrayVector& out_pointCloud,
			const TArraySint& in_arrayTriangleVertexIndex,
			const PMesh& in_mesh
			);

		static const PBoundsR3 BoundsGet(
			const PMesh& in_mesh
			);

		static Hubris::HVOID MeshMerge( 
			PMesh& in_out_mesh,
			const Hubris::HREAL in_threashold //multiply with bounds to get the threashold vector for each axis
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PMeshUtility();

	};

	/**/
};

/**/
#endif // _P_MESH_MATH_UTILITY_H_