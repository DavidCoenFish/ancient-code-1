//file: Pride/PLine/PLineUtility.h
#ifndef _P_LINE_UTILITY_H_
#define _P_LINE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PLine/PLine.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine;
	typedef PLine< Hubris::HREAL, 2 >PLineR2;
	typedef PLine< Hubris::HREAL, 3 >PLineR3;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct PLineUtility
	{
		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return true is a valid line is made
		static const Hubris::HBOOL LineConstruct( 
			Pride::PLineR2& out_line,
			const Hubris::HVectorR2& in_point0, 
			const Hubris::HVectorR2& in_point1,
			Hubris::HREAL* const out_pLength = HNULL
			);
		static const Hubris::HBOOL LineConstruct( 
			Pride::PLineR3& out_line,
			const Hubris::HVectorR3& in_point0, 
			const Hubris::HVectorR3& in_point1,
			Hubris::HREAL* const out_pLength = HNULL
			);

		static const Hubris::HVectorR2 LinePointGet( const PLineR2& in_line, const Hubris::HREAL in_ratioOnLine );
		static const Hubris::HVectorR3 LinePointGet( const PLineR3& in_line, const Hubris::HREAL in_ratioOnLine );

		static const Pride::PLineR3 LineTransform( const PLineR3& in_line, const Hubris::HMatrixR4& in_matrix );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PLineUtility();

	};

	/**/
	
};

#endif // _P_LINE_UTILITY_H_