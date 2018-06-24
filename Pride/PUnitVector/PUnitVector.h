//file: Pride/PUnitVector/PUnitVector.h
#ifndef _P_UNIT_VECTOR_H_
#define _P_UNIT_VECTOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector;
	typedef PUnitVector< Hubris::HREAL, 2 >PUnitVectorR2; //instanciated in cpp
	typedef PUnitVector< Hubris::HREAL, 3 >PUnitVectorR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/*
		simple 3 space plane
		policy:
			assert on zero length unit normal. oblige protection on input
		todo: 
			planeUtility (construct from 3 points)
			planeMathUtility (epsolone equal)
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PUnitVector
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PUnitVector( const PUnitVector& in_src );
		//assert on zero length vector
		explicit PUnitVector(
			const TVector& in_vector
			);
		PUnitVector();
		~PUnitVector();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PUnitVector& operator=( const PUnitVector& in_rhs );
		Hubris::HBOOL operator==( const PUnitVector& in_rhs )const;
		Hubris::HBOOL operator!=( const PUnitVector& in_rhs )const;

		//subscript const operator, assert on out of range
		const Hubris::HREAL operator[]( Hubris::HSINT in_index )const;

		//AVOID cast operators, easliy lead to misleading code
		//operator const Hubris::HVectorR3&()const{ return m_unitVector; }

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TVector& VectorGet()const{ return m_unitVector; }
		//assert on zero length vector
		Hubris::HVOID VectorSet( const TVector& in_unitVector );

		///////////////////////////////////////////////////////
		// private members
	private:
		TVector m_unitVector;

	};

	/**/
	
};

#endif // _P_UNIT_VECTOR_H_