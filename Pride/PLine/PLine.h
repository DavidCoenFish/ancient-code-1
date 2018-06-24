//file: Pride/PLine/PLine.h
#ifndef _P_LINE_H_
#define _P_LINE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PUnitVector/PUnitVector.h"

#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine;
	typedef PLine< Hubris::HREAL, 2 >PLineR2; //instanciated in cpp
	typedef PLine< Hubris::HREAL, 3 >PLineR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PLine
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;
		typedef PUnitVector< IN_TYPE, IN_COUNT >TUnitVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PLine( const PLine& in_src );
		PLine(
			const TVector& in_origin,
			const TUnitVector& in_direction
			);
		PLine();
		~PLine();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PLine& operator=( const PLine& in_rhs );
		Hubris::HBOOL operator==( const PLine& in_rhs )const;
		Hubris::HBOOL operator!=( const PLine& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TVector& OriginGet()const{ return m_origin; }
		Hubris::HVOID OriginSet( const TVector& in_origin ){ m_origin = in_origin; return; }

		const TUnitVector& DirectionGet()const{ return m_direction; }
		Hubris::HVOID DirectionSet( const TUnitVector& in_direction ){ m_direction = in_direction; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TVector m_origin;
		TUnitVector m_direction;

	};

	/**/
	
};

#endif // _P_LINE_H_