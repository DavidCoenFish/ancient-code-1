//file: Pride/PTriangle/PTriangleUtility.h
#ifndef _P_TRIANGLE_UTILITY_H_
#define _P_TRIANGLE_UTILITY_H_

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

/**/
namespace Pride
{
	//////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PTriangle;
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment;
	typedef PLineSegment< Hubris::HREAL, 2 >PLineSegmentR2;
	typedef PLineSegment< Hubris::HREAL, 3 >PLineSegmentR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2;
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PTriangleUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
		typedef Hubris::HContainerArray< PTriangle >TArrayTriangle;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		
		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const Hubris::HBOOL TrianglePointValidTest( 
			const Hubris::HVectorR3& in_pointOne,
			const Hubris::HVectorR3& in_pointTwo,
			const Hubris::HVectorR3& in_pointThree
			);

		//gather normal to triangle, return HFALSE is any points are co-incident or co-linear
		//TODO: will this deal correctly with colinear vectors, points all on one line
		//  it does, cross product of parallel lines of any length is zero
		static const Hubris::HBOOL TriangleNormalGet( PUnitVectorR3& out_normal, const PTriangle& in_triangle );

		static Hubris::HVOID CapEdgeLoop( 
			TArrayTriangle& out_triangleArray, 
			const TArrayVector& in_arrayVector 
			);

		static Hubris::HVOID CapEdgeLoop( 
			TArraySint& out_arrayTriangleVertexIndexTriplets, //size%3
			const TArrayVector& in_arrayVector 
			);

		static const Hubris::HBOOL TriangleEdgeLineSegmentsGet(
			PLineSegmentR3& out_LineOne, 
			PLineSegmentR3& out_LineTwo, 
			PLineSegmentR3& out_LineThree, 
			const PTriangle& in_triangle 
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PTriangleUtility();

	};

	/**/	

};

/**/
#endif // _P_TRIANGLE_UTILITY_H_