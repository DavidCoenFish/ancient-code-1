//file: Vanity/VComponentCollision/VComponentCollisionDataBase.h
#ifndef _V_COMPONENT_COLLISION_DATA_BASE_H_
#define _V_COMPONENT_COLLISION_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EMemento/EMemento_Export.h >
#include "Vanity/VAsset/VAsset_Export.h"

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
	class VComponentCollisionResultBase;
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentCollisionDataBase : public Hubris::HSmartPointerObjectBase< VComponentCollisionDataBase >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( VComponentCollisionDataBase );
		EMEMENTO_FACTORY_HEADER_PURE( VComponentCollisionDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionDataBase();
		virtual ~VComponentCollisionDataBase();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;
		virtual Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface
			)=0;

		virtual Hubris::HVOID CollideRay(
			VComponentCollisionResultBase& out_collisionData,
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_maximumLineLength,
			const Hubris::HREAL in_rayThickness,
			const VScene& in_scene,
			const TItemId in_itemId
			)const=0;

		virtual Hubris::HVOID Render(
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex,
			const TItemId in_itemId
			)=0;
	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_DATA_BASE_H_