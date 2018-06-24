//file: Vanity/VComponentCollision/VComponentCollisionResultBase.h
#ifndef _V_COMPONENT_COLLISION_RESULT_BASE_H_
#define _V_COMPONENT_COLLISION_RESULT_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VComponentCollision/VComponentCollisionResultBound.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultHull.h"
#include "Vanity/VComponentCollision/VComponentCollisionResultSphere.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionResultBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentCollisionResultBound >TSmartPointerBound;
		typedef Hubris::HSmartPointer< VComponentCollisionResultHull >TSmartPointerHull;
		typedef Hubris::HSmartPointer< VComponentCollisionResultSphere >TSmartPointerSphere;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionResultBase( const VComponentCollisionResultBase& in_src );
		VComponentCollisionResultBase();
		~VComponentCollisionResultBase();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentCollisionResultBase& operator=( const VComponentCollisionResultBase& in_rhs );
		const Hubris::HBOOL operator==( const VComponentCollisionResultBase& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentCollisionResultBase& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return true if there is collision data
		const Hubris::HBOOL ValidGet();

		//the distance along the collision ray or sweep that had contact
		const Hubris::HREAL DistanceSquaredGet();
		const Hubris::HREAL DistanceGet();
		const Hubris::HVectorR3& ContactPositionGet();
		//the surface or collision normal at point of contact
		const Hubris::HVectorR3& ContactNormalGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID PointerSetBound( VComponentCollisionResultBound* const in_pBound );
		Hubris::HVOID PointerSetHull( VComponentCollisionResultHull* const in_pHull );
		Hubris::HVOID PointerSetSphere( VComponentCollisionResultSphere* const in_pSphere );

		///////////////////////////////////////////////////////
		// private members
	private:
		TSmartPointerBound m_pBound;
		TSmartPointerHull m_pHull;
		TSmartPointerSphere m_pSphere;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_RESULT_BASE_H_