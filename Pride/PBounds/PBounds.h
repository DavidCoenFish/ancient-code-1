//file: Pride/PBounds/PBounds.h
#ifndef _P_BOUNDS_H_
#define _P_BOUNDS_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;
	typedef PBounds< Hubris::HREAL, 1 >PBoundsR1; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 2 >PBoundsR2; //instanciated in cpp
	typedef PBounds< Hubris::HREAL, 3 >PBoundsR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/*
		track bounds in [n] space
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PBounds( const PBounds& in_src );
		PBounds(
			const TVector& in_minimum,
			const TVector& in_maximum
			);
		PBounds();
		~PBounds();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PBounds& operator=( const PBounds& in_rhs );
		const Hubris::HBOOL operator==( const PBounds& in_rhs )const;
		const Hubris::HBOOL operator!=( const PBounds& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID InsertPoint( 
			const TVector& in_point, 
			const Hubris::HREAL in_radius = 0.0F// = HVariablesMath::ZeroGet< IN_TYPE >() 
			);

		const TVector CenterGet()const;
		//minimum radius that would form a shpere at cenert to inscribe the rectangular box described by bounds
		// ie half the length from bottom left to top right of bound box
		const Hubris::HREAL RadiusGet()const;
		const Hubris::HREAL MaxDimGet()const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//return true if valid
		const Hubris::HBOOL ValidGet()const{ return m_valid; }

		const TVector& VectorMinimumGet()const{ return m_min; }
		//Hubris::HVOID VectorMinimumSet( const TVector& in_min ){ m_min = in_min; return; }

		const TVector& VectorMaximumGet()const{ return m_max; }
		//Hubris::HVOID VectorMaximumSet( const TVector& in_max ){ m_max = in_max; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		//valid mean it container data
		Hubris::HBOOL m_valid;
		TVector m_min;
		TVector m_max;

	};

	/**/
	
};

#endif // _P_BOUNDS_H_