//file: Pride/PLine/PLineSegment.h
#ifndef _P_LINE_SEGMENT_H_
#define _P_LINE_SEGMENT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PLine/PLine.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment;
	typedef PLineSegment< Hubris::HREAL, 2 >PLineSegmentR2; //instanciated in cpp
	typedef PLineSegment< Hubris::HREAL, 3 >PLineSegmentR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLineSegment
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;
		typedef PUnitVector< IN_TYPE, IN_COUNT >TUnitVector;
		typedef PLine< IN_TYPE, IN_COUNT >TLine;

		///////////////////////////////////////////////////////
		// creation
	public:
		PLineSegment( const PLineSegment& in_src );
		explicit PLineSegment(
			const TLine& in_line
			);
		PLineSegment();
		~PLineSegment();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PLineSegment& operator=( const PLineSegment& in_rhs );
		Hubris::HBOOL operator==( const PLineSegment& in_rhs )const;
		Hubris::HBOOL operator!=( const PLineSegment& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		// return true if line segment has upper and lower bounds
		//move to utility
		//const Hubris::HBOOL SegmentValidTest()const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HBOOL BoundsUpperValidGet()const{ return m_boundsUpperValid; }
		Hubris::HVOID BoundsUpperValidClear(){ m_boundsUpperValid = HFALSE; }
		const IN_TYPE BoundsUpperGet()const{ return m_boundsUpper; }
		Hubris::HVOID BoundsUpperSet( const IN_TYPE in_boundsUpper ){ m_boundsUpper = in_boundsUpper; m_boundsUpperValid = HTRUE; return; }

		const Hubris::HBOOL BoundsLowerValidGet()const{ return m_boundsLowerValid; }
		Hubris::HVOID BoundsLowerValidClear(){ m_boundsLowerValid = HFALSE; }
		const IN_TYPE BoundsLowerGet()const{ return m_boundsLower; }
		Hubris::HVOID BoundsLowerSet( const IN_TYPE in_boundsLower ){ m_boundsLower = in_boundsLower; m_boundsLowerValid = HTRUE; return; }

		const TLine& LineGet()const{ return m_line; }
		Hubris::HVOID LineSet( const TLine& in_line ){ m_line = in_line; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TLine m_line;
		IN_TYPE m_boundsUpper;
		IN_TYPE m_boundsLower;
		Hubris::HBOOL m_boundsUpperValid;
		Hubris::HBOOL m_boundsLowerValid;

	};

	/**/
	
};

#endif // _P_LINE_SEGMENT_H_