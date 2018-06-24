//file: Vanity/VScene/VSceneUtilityHelperRenderCollision.h
#ifndef _V_SCENE_UTILITY_HELPER_RENDER_COLLISION_H_
#define _V_SCENE_UTILITY_HELPER_RENDER_COLLISION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declaration
	/**/
	class VScene;
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneUtilityHelperRenderCollision
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneUtilityHelperRenderCollision( 
			VScene& in_out_scene,
			VSceneApplicationInterface& in_sceneApplicationInterface,
			const Hubris::HSINT in_renderIndex
			);
		~VSceneUtilityHelperRenderCollision();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VSceneUtilityHelperRenderCollision( const VSceneUtilityHelperRenderCollision& in_src );
		const VSceneUtilityHelperRenderCollision& operator=( const VSceneUtilityHelperRenderCollision& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HBOOL VisitorSorted( Hubris::HSINT in_itemId );

		///////////////////////////////////////////////////////
		// private members
	private:
		VScene& m_scene;
		VSceneApplicationInterface& m_sceneApplicationInterface;
		const Hubris::HSINT m_renderIndex;

	};

};

#endif // _V_SCENE_UTILITY_HELPER_RENDER_COLLISION_H_