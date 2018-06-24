//file: Vanity/VComponentCollision/VComponentCollisionHullData.h
#ifndef _V_COMPONENT_COLLISION_HULL_DATA_H_
#define _V_COMPONENT_COLLISION_HULL_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentCollisionHullData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionHullData( const VComponentCollisionHullData& in_src );
		VComponentCollisionHullData();
		~VComponentCollisionHullData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentCollisionHullData& operator=( const VComponentCollisionHullData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentCollisionHullData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentCollisionHullData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Pride::PPlaneR3& PlaneGet()const{ return m_plane; }
		Pride::PPlaneR3& PlaneGet(){ return m_plane; }

		const TArraySint& ArrayIndexTouchingPlaneGet()const{ return m_arrayIndexTouchingPlane; }
		TArraySint& ArrayIndexTouchingPlaneGet(){ return m_arrayIndexTouchingPlane; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PPlaneR3 m_plane;
		TArraySint m_arrayIndexTouchingPlane;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_HULL_DATA_H_