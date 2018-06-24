//file: Vanity/VComponentCollision/VComponentCollisionHull.h
#ifndef _V_COMPONENT_COLLISION_HULL_H_
#define _V_COMPONENT_COLLISION_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentCollision/VComponentCollisionHullData.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentCollisionResultBase;

	///////////////////////////////////////////////////////
	// class
	/*
		variation on PConvexHull fo VComponentCollision,
			a list of planes, with each plane having a list of neibour planes
	*/
	class VComponentCollisionHull
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentCollisionHullData >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionHull( const VComponentCollisionHull& in_src );
		VComponentCollisionHull( Pride::PConvexHull& in_hull );
		VComponentCollisionHull();
		~VComponentCollisionHull();

		///////////////////////////////////////////////////////
		// operators
	public:
		const VComponentCollisionHull& operator=( const VComponentCollisionHull& in_rhs );
		const Hubris::HBOOL operator==( const VComponentCollisionHull& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentCollisionHull& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID CollideRay(
			VComponentCollisionResultBase& out_collisionData,
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_maximumLineLength,
			const Hubris::HMatrixR4& in_itemMatrix,
			const Hubris::HMatrixR4& in_itemMatrixInvert
			)const;

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const TArrayData& ArrayDataGet()const{ return m_arrayData; }
		TArrayData& ArrayDataGet(){ return m_arrayData; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayData m_arrayData;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_DATA_HULL_H_