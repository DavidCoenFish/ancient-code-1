//file: Pride/PBounds/PBoundsUtility.h
#ifndef _P_BOUNDS_UTILITY_H_
#define _P_BOUNDS_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1;
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2;
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3;

	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine;
	typedef PLine< Hubris::HREAL, 2 >PLineR2;
	typedef PLine< Hubris::HREAL, 3 >PLineR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PBoundsUtility
	{
		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const Hubris::HBOOL IntersectLine( 
			const PBoundsR3& in_bounds,
			const PLineR3& in_line,
			Hubris::HREAL* const out_pRatioOnLineNear = HNULL, 
			Hubris::HVectorR3* const our_pSurfaceNormalNear = HNULL
			);

		//inclusive
		static const Hubris::HBOOL PointInsideTest(
			const PBoundsR3& in_bounds,
			const Hubris::HVectorR3& in_point
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PBoundsUtility();

	};

};

#endif // _P_BOUNDS_UTILITY_H_