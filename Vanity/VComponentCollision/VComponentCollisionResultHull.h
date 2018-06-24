//file: Vanity/VComponentCollision/VComponentCollisionResultHull.h
#ifndef _V_COMPONENT_COLLISION_RESULT_HULL_H_
#define _V_COMPONENT_COLLISION_RESULT_HULL_H_

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
	class VComponentCollisionResultHull : public Hubris::HSmartPointerObjectBase< VComponentCollisionResultHull >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionResultHull(
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_distance,
			const Hubris::HVectorR3& in_normal
			);
		~VComponentCollisionResultHull();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionResultHull( const VComponentCollisionResultHull& in_src );
		const VComponentCollisionResultHull& operator=( const VComponentCollisionResultHull& in_rhs );

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
		const Pride::PLineR3 m_line;
		const Hubris::HREAL m_distance;
		const Hubris::HVectorR3 m_normal;
		Hubris::HVectorR3 m_position;
		Hubris::HBOOL m_positionValid;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_RESULT_HULL_H_