//file: Pride/PMesh/PMeshTriangle.h
#ifndef _P_MESH_TRIANGLE_H_
#define _P_MESH_TRIANGLE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;

};

namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class PMeshTriangle
	{
		///////////////////////////////////////////////////////
		// typedefs
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PMeshTriangle >TArrayTriangle;

		///////////////////////////////////////////////////////
		// creation
	public:
		PMeshTriangle( const PMeshTriangle& in_src );
		PMeshTriangle(
			const Hubris::HSINT in_vertexIndexOne,
			const Hubris::HSINT in_vertexIndexTwo,
			const Hubris::HSINT in_vertexIndexThree
			);
		PMeshTriangle();
		~PMeshTriangle();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PMeshTriangle& operator=( const PMeshTriangle& in_rhs );
		Hubris::HBOOL operator==( const PMeshTriangle& in_rhs )const;
		Hubris::HBOOL operator!=( const PMeshTriangle& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID VertexIndexSet(
			const Hubris::HSINT in_vertexIndexOne,
			const Hubris::HSINT in_vertexIndexTwo,
			const Hubris::HSINT in_vertexIndexThree
			);
		Hubris::HVOID VertexIndexGet(
			Hubris::HSINT& out_vertexIndexOne,
			Hubris::HSINT& out_vertexIndexTwo,
			Hubris::HSINT& out_vertexIndexThree
			)const;

		Hubris::HVOID TriangleEdgeFlagGet(
			Hubris::HBOOL& out_edgeVertexOneTwo,
			Hubris::HBOOL& out_edgeVertexTwoThree,
			Hubris::HBOOL& out_edgeVertexThreeOne
			)const;
		Hubris::HVOID TriangleEdgeFlagSet(
			const Hubris::HBOOL& in_edgeVertexOneTwo,
			const Hubris::HBOOL& in_edgeVertexTwoThree,
			const Hubris::HBOOL& in_edgeVertexThreeOne
			);

		//access to normal may cause calculation of the normal
		const Hubris::HSINT NormalIndexGet( 
			const TArrayVector& in_arrayVertex,
			TArrayVector& in_out_arrayNormal
			);
		const Hubris::HBOOL NormalValidGet(
			const TArrayVector& in_arrayVertex,
			TArrayVector& in_out_arrayNormal
			);

		//access to edge touching triangle may cause calculation, HCOMMON_INVALID_INDEX on no touching triangle on edge
		static const Hubris::HSINT EdgeTouchesTriangleIndexGet( 
			const Hubris::HSINT in_triangleIndex,
			const Hubris::HSINT in_edgeIndex,
			TArrayTriangle& in_out_arrayTriangle
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_vertexIndex[ 3 ];
		Hubris::HSINT m_flag; //has normal, edge toughing data been generated
		Hubris::HSINT m_touchingTriangleIndex[ 3 ];
		Hubris::HSINT m_normalIndex;

	};

	/**/
};

/**/
#endif // _P_MESH_TRIANGLE_H_