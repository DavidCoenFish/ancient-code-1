//file: Pride/PPlane/PPlane.h
#ifndef _P_PLANE_H_
#define _P_PLANE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PUnitVector/PUnitVector.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane;
	typedef PPlane< Hubris::HREAL, 2 >PPlaneR2; //instanciated in cpp
	typedef PPlane< Hubris::HREAL, 3 >PPlaneR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/*
		simple 3 space plane
		todo: 
			planeUtility (construct from 3 points)
			planeMathUtility (epsolone equal)
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPlane
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef PUnitVector< IN_TYPE, IN_COUNT >TUnitVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PPlane( const PPlane& in_src );
		PPlane(
			const IN_TYPE in_distance,
			const TUnitVector& in_direction
			);
		PPlane();
		~PPlane();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PPlane& operator=( const PPlane& in_rhs );
		Hubris::HBOOL operator==( const PPlane& in_rhs )const;
		Hubris::HBOOL operator!=( const PPlane& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const IN_TYPE DistanceGet()const{ return m_distance; }
		Hubris::HVOID DistanceSet( const IN_TYPE in_distance ){ m_distance = in_distance; return; }

		const TUnitVector& DirectionGet()const{ return m_direction; }
		Hubris::HVOID DirectionSet( const TUnitVector& in_direction ){ m_direction = in_direction; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		IN_TYPE m_distance;
		TUnitVector m_direction;

	};

	/**/
	
};

#endif // _P_PLANE_H_