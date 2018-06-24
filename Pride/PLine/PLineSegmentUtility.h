//file: Pride/PLine/PLineSegmentUtility.h
#ifndef _P_LINE_SEGMENT_UTILITY_H_
#define _P_LINE_SEGMENT_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
};

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2;
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment;
	typedef PLineSegment< Hubris::HREAL, 2 >PLineSegmentR2;
	typedef PLineSegment< Hubris::HREAL, 3 >PLineSegmentR3;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PLineSegmentUtility
	{
		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return false if line is on plane
		static const Hubris::HBOOL TrimLineSegment( PLineSegmentR2& in_out_lineSegment, const PPlaneR2& in_plane );
		static const Hubris::HBOOL TrimLineSegment( PLineSegmentR3& in_out_lineSegment, const PPlaneR3& in_plane );

		static Hubris::HVOID LineSegmentToPoints(
			Hubris::HVectorR2& out_lowPoint,
			Hubris::HBOOL& out_lowPointValid,
			Hubris::HVectorR2& out_highPoint,
			Hubris::HBOOL& out_highPointValid,
			const PLineSegmentR2& in_lineSegment
			);
		static Hubris::HVOID LineSegmentToPoints(
			Hubris::HVectorR3& out_lowPoint,
			Hubris::HBOOL& out_lowPointValid,
			Hubris::HVectorR3& out_highPoint,
			Hubris::HBOOL& out_highPointValid,
			const PLineSegmentR3& in_lineSegment
			);

		static const Hubris::HBOOL LineSegmentFromPoints(
			PLineSegmentR3& out_lineSegment,
			const Hubris::HVectorR3& in_lowPoint,
			const Hubris::HVectorR3& in_highPoint
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PLineSegmentUtility();

	};

	/**/
	
};

#endif // _P_LINE_SEGMENT_UTILITY_H_