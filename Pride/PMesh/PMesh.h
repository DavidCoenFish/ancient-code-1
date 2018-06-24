//file: Pride/PMesh/PMesh.h
#ifndef _P_MESH_H_
#define _P_MESH_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PMeshImplementation;

	///////////////////////////////////////////////////////
	// class
	/*
		simple specific geometric representation.
		vertex is position [R3], triangle indexes 3 vertex.
		generated on demand is triangle normal or triangle edge association
		cache triangle edge association, and traingle normals
	*/
	class PMesh
	{
		///////////////////////////////////////////////////////
		// typedefs
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< Hubris::HBOOL >TArrayBool;

		///////////////////////////////////////////////////////
		// creation
	public:
		PMesh( const PMesh& in_src );
		PMesh( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex	//assert SizeGet() %3 == 0
			);
		PMesh( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
			const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
			);
		PMesh();
		~PMesh();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PMesh& operator=( const PMesh& in_rhs );
		const PMesh& operator+=( const PMesh& in_rhs );
		const Hubris::HBOOL operator==( const PMesh& in_rhs )const;
		const Hubris::HBOOL operator!=( const PMesh& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DataSet( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
			);

		Hubris::HVOID DataSet( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
			const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
			);

		//add a triangle, can add invalid triangle, but normal will be invalid
		const Hubris::HSINT TriangleAdd(
			const Hubris::HVectorR3& in_vertexOne,
			const Hubris::HVectorR3& in_vertexTwo,
			const Hubris::HVectorR3& in_vertexThree,
			const Hubris::HVectorR3& in_threashold = Hubris::HVectorR3()
			);

		const TArrayVector& ArrayVertexGet()const;
		const Hubris::HSINT TriangleCountGet()const;
		Hubris::HVOID TriangleIndexGet(
			const Hubris::HSINT in_triangleIndex,
			Hubris::HSINT& out_vertexIndexOne,
			Hubris::HSINT& out_vertexIndexTwo,
			Hubris::HSINT& out_vertexIndexThree
			)const;
		//convienence, or remove
		Hubris::HVOID TriangleVertexGet(
			const Hubris::HSINT in_triangleIndex,
			Hubris::HVectorR3& out_vertexOne,
			Hubris::HVectorR3& out_vertexTwo,
			Hubris::HVectorR3& out_vertexThree
			)const;

		Hubris::HVOID TriangleEdgeFlagGet(
			const Hubris::HSINT in_triangleIndex,
			Hubris::HBOOL& out_edgeVertexOneTwo,
			Hubris::HBOOL& out_edgeVertexTwoThree,
			Hubris::HBOOL& out_edgeVertexThreeOne
			)const;
		Hubris::HVOID TriangleEdgeFlagSet(
			const Hubris::HSINT in_triangleIndex,
			const Hubris::HBOOL& in_edgeVertexOneTwo,
			const Hubris::HBOOL& in_edgeVertexTwoThree,
			const Hubris::HBOOL& in_edgeVertexThreeOne
			);

		//non const, mesh data my change as data is gathered
		const Hubris::HSINT TriangleEdgeTouchesGet(
			const Hubris::HSINT in_triangleIndex,
			const Hubris::HSINT in_edgeIndex
			);
		//non const, mesh data my change as data is gathered
		//todo, add normal valid concept
		const Hubris::HBOOL TriangleNormalValidGet(
			const Hubris::HSINT in_triangleIndex
			);
		const Hubris::HVectorR3& TriangleNormalGet(
			const Hubris::HSINT in_triangleIndex
			);

		//pull out the mesh data at certain triangels, no, better just to keep array of traingles index external
		// aim to not recalculate edge or normal generated data, and not need to re add extracted mesh
		//HVOID MeshExtract( 
		//	PMesh& out_mesh,
		//	const TArraySint& in_arrayTriangleIndex
		//	);

		///////////////////////////////////////////////////////
		// private methods
	private:
		const PMeshImplementation& ImplementationGet()const;
		PMeshImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		PMeshImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _P_MESH_H_