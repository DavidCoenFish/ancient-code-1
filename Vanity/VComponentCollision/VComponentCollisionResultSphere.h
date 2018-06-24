//file: Vanity/VComponentCollision/VComponentCollisionResultSphere.h
#ifndef _V_COMPONENT_COLLISION_RESULT_SPHERE_H_
#define _V_COMPONENT_COLLISION_RESULT_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	class SInterfaceRender;
	class SLight;
};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionResultSphere : public Hubris::HSmartPointerObjectBase< VComponentCollisionResultSphere >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionResultSphere(
			const Hubris::HREAL in_distance,
			const Pride::PLineR3& in_line,
			const Pride::PSphereR3& in_sphere
			);
		~VComponentCollisionResultSphere();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionResultSphere( const VComponentCollisionResultSphere& in_src );
		const VComponentCollisionResultSphere& operator=( const VComponentCollisionResultSphere& in_rhs );

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
		Pride::PSphereR3 m_sphere;
		Hubris::HVectorR3 m_position;
		Hubris::HBOOL m_positionValid;
		Hubris::HVectorR3 m_normal;
		Hubris::HBOOL m_normalValid;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_RESULT_SPHERE_H_