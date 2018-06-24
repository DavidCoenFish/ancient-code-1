//file: Vanity/VComponentCollision/VComponentCollision.h
#ifndef _V_COMPONENT_COLLISION_H_
#define _V_COMPONENT_COLLISION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentCollision/VComponentCollisionDataBase.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentCollision;
};

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VComponentCollision
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollision& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollision& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentCollisionRenderParam;
	class VComponentCollisionCamera;
	class VInterfaceRenderTarget;
	class VImageHDR;
	class VComponentCollisionItemData;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollision
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentCollision >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentCollision& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentCollision >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentCollision& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< VComponentCollisionDataBase >TPointerData;
		typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollision();
		~VComponentCollision();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentCollision( const VComponentCollision& in_src );
		const VComponentCollision& operator=( const VComponentCollision& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

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
			const VScene& in_scene,
			const TItemId in_itemId
			)const;

		Hubris::HVOID Render(
			VScene& in_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex,
			const TItemId in_itemId
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayPointerData m_arrayPointerData;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_H_