//file: Pride/PSphere/PSphere.h
#ifndef _P_SPHERE_H_
#define _P_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere;
	typedef PSphere< Hubris::HREAL, 2 >PSphereR2; //instanciated in cpp
	typedef PSphere< Hubris::HREAL, 3 >PSphereR3; //instanciated in cpp

	///////////////////////////////////////////////////////
	// class
	/*
		simple 3 space plane
		todo: 
			planeUtility (construct from 3 points)
			planeMathUtility (epsolone equal)
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PSphere
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PSphere( const PSphere& in_src );
		PSphere(
			const IN_TYPE in_radius,
			const TVector& in_center
			);
		PSphere();
		~PSphere();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PSphere& operator=( const PSphere& in_rhs );
		Hubris::HBOOL operator==( const PSphere& in_rhs )const;
		Hubris::HBOOL operator!=( const PSphere& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const IN_TYPE RadiusGet()const{ return m_radius; }
		Hubris::HVOID RadiusSet( const IN_TYPE in_radius ){ m_radius = in_radius; return; }

		const TVector& CenterGet()const{ return m_center; }
		Hubris::HVOID CenterSet( const TVector& in_center ){ m_center = in_center; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		IN_TYPE m_radius;
		TVector m_center;

	};

	/**/
	
};

#endif // _P_SPHERE_H_