//file: Vanity/VComponentCollision/VComponentCollisionDataSphere.h
#ifndef _V_COMPONENT_COLLISION_DATA_SPHERE_H_
#define _V_COMPONENT_COLLISION_DATA_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentCollision/VComponentCollisionDataBase.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionDataSphere : public VComponentCollisionDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentCollisionDataSphere, VComponentCollisionDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentCollisionDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionDataSphere();
		virtual ~VComponentCollisionDataSphere();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionDataSphere( const VComponentCollisionDataSphere& in_src );
		const VComponentCollisionDataSphere& operator=( const VComponentCollisionDataSphere& in_rhs );

		///////////////////////////////////////////////////////
		// implement VComponentCollisionDataBase
	private:
		virtual Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);
		virtual Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface
			);
		virtual Hubris::HVOID CollideRay(
			VComponentCollisionResultBase& out_collisionData,
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_maximumLineLength,
			const Hubris::HREAL in_rayThickness,
			const VScene& in_scene,
			const TItemId in_itemId
			)const;
		virtual Hubris::HVOID Render(
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex,
			const TItemId in_itemId
			);

		///////////////////////////////////////////////////////
		// public acessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_DATA_SPHERE_H_