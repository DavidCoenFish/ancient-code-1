//file: Vanity/VComponentCollision/VComponentCollisionInterfaceObject.h
#ifndef _V_COMPONENT_COLLISION_INTERFACE_OBJECT_H_
#define _V_COMPONENT_COLLISION_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VComponentCollision;
	class VComponentCollisionResultBase;
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Pride::PColourRealRgb >TPairDirectionColour;
		typedef Hubris::HContainerArray< TPairDirectionColour >TArrayPairDirectionColour;
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionInterfaceObject(
			VComponentCollision& in_componentCollision,
			VScene& in_scene
			);
		~VComponentCollisionInterfaceObject();

		///////////////////////////////////////////////////////
		// public methods
	public:
		//create a collision bound
		Hubris::HVOID CollisionBoundCreate(
			const TItemId in_itemId,
			const Pride::PBoundsR3& in_bound
			);

		//create a collision sphere
		Hubris::HVOID CollisionSphereCreate(
			const TItemId in_itemId
			);

		//create a collision convex hull
		Hubris::HVOID CollisionConvexHullCreate(
			const TItemId in_itemId,
			const Hubris::HFileSystemPath& in_assetPath
			);

		//create a visual simple asset
		static Hubris::HVOID CollisionConvexHullAssetCreate(
			const Hubris::HFileSystemPath& in_assetPath,
			Pride::PConvexHull& in_convexHull
			);

		Hubris::HVOID Load(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);
		Hubris::HVOID UnLoad(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const TItemId in_itemId
			);

		Hubris::HVOID CollideRay(
			VComponentCollisionResultBase& out_collisionData,
			const Pride::PLineR3& in_line,
			const Hubris::HREAL in_maximumLineLength,
			const Hubris::HREAL in_rayThickness,
			const TItemId in_itemId
			)const;

		Hubris::HVOID Render(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex,
			const TItemId in_itemId
			);

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentCollisionInterfaceObject( const VComponentCollisionInterfaceObject& in_src );
		const VComponentCollisionInterfaceObject& operator=( const VComponentCollisionInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentCollision& m_componentCollision;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_INTERFACE_OBJECT_H_