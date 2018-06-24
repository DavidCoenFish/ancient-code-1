//file: Pride/PMesh/PMeshImplementation.h
#ifndef _P_MESH_IMPLEMENTATION_H_
#define _P_MESH_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PMesh/PMeshTriangle.h"
#include "Pride/PPointCloud/PPointCloud_Export.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PMeshImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PMeshImplementation
	{
		///////////////////////////////////////////////////////
		// typedefs
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< PMeshTriangle >TArrayTriangle;
		typedef Hubris::HContainerArray< Hubris::HBOOL >TArrayBool;

		///////////////////////////////////////////////////////
		// creation
	public:
		PMeshImplementation( const PMeshImplementation& in_src );
		PMeshImplementation( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex	//assert SizeGet() %3 == 0
			);
		PMeshImplementation( 
			const TArrayVector& in_arrayVertex,  
			const TArraySint& in_arrayTriangleVertexIndex,	//assert SizeGet() %3 == 0
			const TArrayBool& in_arrayTriangleEdgeFlags		//assert SizeGet() == in_arrayTriangleVertexIndex.SizeGet()
			);
		PMeshImplementation();
		~PMeshImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PMeshImplementation& operator=( const PMeshImplementation& in_rhs );
		const PMeshImplementation& operator+=( const PMeshImplementation& in_rhs );
		const Hubris::HBOOL operator==( const PMeshImplementation& in_rhs )const;
		const Hubris::HBOOL operator!=( const PMeshImplementation& in_rhs )const;

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

		const Hubris::HSINT TriangleAdd(
			const Hubris::HVectorR3& in_vertexOne,
			const Hubris::HVectorR3& in_vertexTwo,
			const Hubris::HVectorR3& in_vertexThree,
			const Hubris::HVectorR3& in_threashold
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
		const Hubris::HBOOL TriangleNormalValidGet(
			const Hubris::HSINT in_triangleIndex
			);
		const Hubris::HVectorR3& TriangleNormalGet(
			const Hubris::HSINT in_triangleIndex
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		PPointCloudR3 m_arrayVertex;
		TArrayVector m_arrayNormal;
		TArrayTriangle m_arrayTriangle;

	};

	/**/
};

/**/
#endif // _P_MESH_IMPLEMENTATION_H_