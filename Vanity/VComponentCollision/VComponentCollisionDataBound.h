//file: Vanity/VComponentCollision/VComponentCollisionDataBound.h
#ifndef _V_COMPONENT_COLLISION_DATA_SIMPLE_H_
#define _V_COMPONENT_COLLISION_DATA_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentCollision/VComponentCollisionDataBase.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionDataBound : public VComponentCollisionDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentCollisionDataBound, VComponentCollisionDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentCollisionDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionDataBound();
		virtual ~VComponentCollisionDataBound();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionDataBound( const VComponentCollisionDataBound& in_src );
		const VComponentCollisionDataBound& operator=( const VComponentCollisionDataBound& in_rhs );

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
		const Pride::PBoundsR3& BoundGet()const{ return m_bound; }
		Hubris::HVOID BoundSet( const Pride::PBoundsR3& in_bound ){ m_bound = in_bound; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PBoundsR3 m_bound;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_DATA_SIMPLE_H_