//file: Vanity/VComponentCollision/VComponentCollisionAssetHull.h
#ifndef _V_COMPONENT_COLLISION_ASSET_HULL_H_
#define _V_COMPONENT_COLLISION_ASSET_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VAsset/VAsset_Export.h"
#include "Vanity/VComponentCollision/VComponentCollisionHull.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VSceneApplicationInterface;
	class VComponentCollision;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentCollisionAssetHull : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentCollisionAssetHull, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionAssetHull(
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path					
			);
		~VComponentCollisionAssetHull();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentCollisionAssetHull( const VComponentCollisionAssetHull& in_src );
		const VComponentCollisionAssetHull& operator=( const VComponentCollisionAssetHull& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			Pride::PConvexHull& in_convexHull
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const VComponentCollisionHull& ConvexHullGet()const{ return m_convexHull; }
		VComponentCollisionHull& ConvexHullGet(){ return m_convexHull; }

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentCollisionHull m_convexHull;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_ASSET_HULL_H_