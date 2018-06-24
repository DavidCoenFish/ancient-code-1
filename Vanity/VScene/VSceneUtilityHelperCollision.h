//file: Vanity/VScene/VSceneUtilityHelperCollision.h
#ifndef _V_SCENE_UTILITY_HELPER_COLLISION_H_
#define _V_SCENE_UTILITY_HELPER_COLLISION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declaration
	/**/
	class VComponentCollisionResultBase;
	class VScene;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneUtilityHelperCollision
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneUtilityHelperCollision(
			VScene& in_scene,
			VComponentCollisionResultBase& in_out_collisionResult,
			const Pride::PLineR3& in_line,
			const Hubris::HREAL m_maximumDistance,
			const Hubris::HREAL in_rayThickness
			);
		~VSceneUtilityHelperCollision();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VSceneUtilityHelperCollision( const VSceneUtilityHelperCollision& in_src );
		const VSceneUtilityHelperCollision& operator=( const VSceneUtilityHelperCollision& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HBOOL VisitorSorted( Hubris::HSINT in_itemId, Hubris::HREAL in_nodeDistance );

		///////////////////////////////////////////////////////
		// private members
	private:
		VScene& m_scene;
		VComponentCollisionResultBase& m_collisionResult;
		const Pride::PLineR3 m_line;
		Hubris::HREAL m_maximumDistance;
		const Hubris::HREAL m_rayThickness;

	};

};

#endif // _V_SCENE_UTILITY_HELPER_COLLISION_H_