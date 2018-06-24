//file: Pride/PConvexHullGenerate/PConvexHullGenerateUtilitySegment.h
#ifndef _P_CONVEX_HULL_GENERATE_UTILITY_SEGMENT_H_
#define _P_CONVEX_HULL_GENERATE_UTILITY_SEGMENT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward define

	///////////////////////////////////////////////////////
	// class
	/**/
	class PConvexHullGenerateUtilitySegment
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HVectorR2 >TArrayVector;
		typedef Hubris::HContainerArray< PConvexHullGenerateUtilitySegment >TArraySegment;

		///////////////////////////////////////////////////////
		// creation
	public:
		PConvexHullGenerateUtilitySegment( const PConvexHullGenerateUtilitySegment& in_src );
		PConvexHullGenerateUtilitySegment(
			const Hubris::HSINT in_indexOne,
			const Hubris::HSINT in_indexTwo
			);
		PConvexHullGenerateUtilitySegment();
		~PConvexHullGenerateUtilitySegment();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PConvexHullGenerateUtilitySegment& operator=( const PConvexHullGenerateUtilitySegment& in_rhs );
		const Hubris::HBOOL operator==( const PConvexHullGenerateUtilitySegment& in_rhs )const;
		const Hubris::HBOOL operator!=( const PConvexHullGenerateUtilitySegment& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//const Hubris::HBOOL

		const Hubris::HSINT NextPlaneIndexGet( 
			const Hubris::HSINT in_ourIndex,
			const TArraySegment& in_arraySegments,
			const TArrayVector& in_arrayPoints
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT IndexOneGet()const{ return m_indexOne; }
		const Hubris::HSINT IndexTwoGet()const{ return m_indexTwo; }

		///////////////////////////////////////////////////////
		// private members
	private:
		//dummy plane

		Hubris::HSINT m_indexOne;
		Hubris::HSINT m_indexTwo;

	};

	/**/	
};

#endif // _P_CONVEX_HULL_GENERATE_UTILITY_SEGMENT_H_