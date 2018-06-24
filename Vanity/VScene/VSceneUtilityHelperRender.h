//file: Vanity/VScene/VSceneUtilityHelperRender.h
#ifndef _V_SCENE_UTILITY_HELPER_RENDER_H_
#define _V_SCENE_UTILITY_HELPER_RENDER_H_

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
	class VSceneUtilityHelperRender
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerArray< TArraySint >TArrayArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneUtilityHelperRender( 
			VScene& in_out_scene,
			const Hubris::HSINT in_renderIndex,
			VSceneApplicationInterface& in_sceneApplicationInterface
			);
		~VSceneUtilityHelperRender();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VSceneUtilityHelperRender( const VSceneUtilityHelperRender& in_src );
		const VSceneUtilityHelperRender& operator=( const VSceneUtilityHelperRender& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HBOOL VisitorSorted( Hubris::HSINT in_itemId );
		Hubris::HVOID PostVisitor();

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID RenderItemId( const Hubris::HSINT in_itemId );

		///////////////////////////////////////////////////////
		// private members
	private:
		VScene& m_scene;
		const Hubris::HSINT m_renderIndex;
		VSceneApplicationInterface& m_sceneApplicationInterface;
		TArrayArraySint m_pendingArrayId;

	};

};

#endif // _V_SCENE_UTILITY_HELPER_RENDER_H_