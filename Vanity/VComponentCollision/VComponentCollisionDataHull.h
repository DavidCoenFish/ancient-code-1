//file: Vanity/VComponentCollision/VComponentCollisionDataHull.h
#ifndef _V_COMPONENT_COLLISION_DATA_HULL_H_
#define _V_COMPONENT_COLLISION_DATA_HULL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentCollision/VComponentCollisionDataBase.h"
#include "Vanity/VComponentCollision/VComponentCollisionAssetHull.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentCollisionDataHull : public VComponentCollisionDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentCollisionDataHull, VComponentCollisionDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentCollisionDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HSmartPointer< VComponentCollisionAssetHull >TPointerAsset;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentCollisionDataHull();
		virtual ~VComponentCollisionDataHull();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentCollisionDataHull( const VComponentCollisionDataHull& in_src );
		const VComponentCollisionDataHull& operator=( const VComponentCollisionDataHull& in_rhs );

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
		const Hubris::HFileSystemPath& FilePathGet()const{ return m_filePath; }
		Hubris::HVOID FilePathSet( const Hubris::HFileSystemPath& in_filePath ){ m_filePath = in_filePath; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HFileSystemPath m_filePath;
		TPointerAsset m_pAsset;

		//debug render data
		TArrayReal m_arrayTriangle;

	};

	/**/
	
};

#endif // _V_COMPONENT_COLLISION_DATA_HULL_H_