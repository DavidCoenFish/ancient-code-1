//file: Pride/PTriangle/PTriangle.h
#ifndef _P_TRIANGLE_H_
#define _P_TRIANGLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// class
	/*
		simple 3 point triangle
	*/
	class PTriangle
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		PTriangle( const PTriangle& in_src );
		PTriangle(
			const Hubris::HVectorR3& in_pointOne,
			const Hubris::HVectorR3& in_pointTwo,
			const Hubris::HVectorR3& in_pointThree
			);
		PTriangle();
		~PTriangle();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PTriangle& operator=( const PTriangle& in_rhs );
		Hubris::HBOOL operator==( const PTriangle& in_rhs )const;
		Hubris::HBOOL operator!=( const PTriangle& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& PointOneGet()const{ return m_pointOne; }
		Hubris::HVOID PointOneSet( const Hubris::HVectorR3& in_pointOne ){ m_pointOne = in_pointOne; return; }

		const Hubris::HVectorR3& PointTwoGet()const{ return m_pointTwo; }
		Hubris::HVOID PointTwoSet( const Hubris::HVectorR3& in_pointTwo ){ m_pointTwo = in_pointTwo; return; }

		const Hubris::HVectorR3& PointThreeGet()const{ return m_pointThree; }
		Hubris::HVOID PointThreeSet( const Hubris::HVectorR3& in_pointThree ){ m_pointThree = in_pointThree; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR3 m_pointOne;
		Hubris::HVectorR3 m_pointTwo;
		Hubris::HVectorR3 m_pointThree;

	};

	/**/
	
};

#endif // _P_TRIANGLE_H_