//file: Vanity/VComponentCollision/VComponentCollisionResultBound.h
#ifndef _V_COMPONENT_COLLISION_RESULT_BOUND_H_
#define _V_COMPONENT_COLLISION_RESULT_BOUND_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionResultBound : public Hubris::HSmartPointerObjectBase< VComponentCollisionResultBound >
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionResultBound(
			const Hubris::HREAL in_distance,
			const Pride::PLineR3& in_line,
			const Hubris::HVectorR3& in_normal
			);
		~VComponentCollisionResultBound();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionResultBound( const VComponentCollisionResultBound& in_src );
		const VComponentCollisionResultBound& operator=( const VComponentCollisionResultBound& in_rhs );

		///////////////////////////////////////////////////////
		// public methods, contract with VComponentCollisionResultBase
	public:
		const Hubris::HREAL DistanceSquaredGet();
		const Hubris::HREAL DistanceGet();
		const Hubris::HVectorR3& ContactPositionGet();
		const Hubris::HVectorR3& ContactNormalGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HREAL m_distance;
		Pride::PLineR3 m_line;
		Hubris::HVectorR3 m_normal;
		Hubris::HVectorR3 m_position;
		Hubris::HBOOL m_positionValid;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_RESULT_BOUND_H_