//file: Vanity/VScene/VSceneApplicationInterface.h
#ifndef _V_SCENE_APPLICATION_INTERFACE_H_
#define _V_SCENE_APPLICATION_INTERFACE_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Hubris
{
	class HFileSystem;
};
namespace Sloth
{
	class SComponentDelta;
	class SInterfaceRender;
	class SInput;
	class STextureAlias;
};
namespace Vanity
{
	class VAssetManager;
};

///////////////////////////////////////////////////////
// class
/*
	interface for VScene to gain access to various parts of an application
	renderer, camera, input, delta, asset manager

	//TODO:
	virtuals are expencive, but useful for defining interface
		may want to move some of there functions to be methods not virtuals for speed
*/
namespace Vanity
{
	class VSceneApplicationInterface
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneApplicationInterface();
		~VSceneApplicationInterface();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VSceneApplicationInterface( const VSceneApplicationInterface& in_src );
		const VSceneApplicationInterface& operator=( const VSceneApplicationInterface& in_rhs );

		///////////////////////////////////////////////////////
		// interface
	public:
		//get the asset mamanger
		virtual const VAssetManager& AssetManagerGet()const=0;
		virtual VAssetManager& AssetManagerGet()=0;

		/*
			this is a mess, want to register render interface with scene, 
			but we only have render interface while attached to renderer... ie created for each frame update
		*/
		virtual const Hubris::HSINT RenderInterfaceCountGet()const=0;
		virtual Sloth::SInterfaceRender* const RenderInterfaceGet( const Hubris::HSINT in_renderIndex )=0; //can return HNULL

		// access the camera data
		//virtual const Hubris::HVectorR3& CameraVectorAtGet()const=0;
		//virtual const Hubris::HVectorR3& CameraVectorUpGet()const=0;
		//virtual const Hubris::HVectorR3& CameraVectorRightGet()const=0;
		//virtual const Pride::PConvexHull& CameraFustrumHullGet()const=0;
		//virtual const Pride::PSphereR3& CameraFustrumSphereGet()const=0;

		virtual const Sloth::SInput& InputGet( const Hubris::HSINT in_controllerIndex )const=0;

		virtual const Sloth::SComponentDelta& DeltaGet()const=0;

		//virtual const Hubris::HSINT FrameIdGet()const=0;

		virtual const Sloth::STextureAlias& TextureAliasGet()const=0;
		virtual Sloth::STextureAlias& TextureAliasGet()=0;

		virtual const Hubris::HFileSystem& FileSystemGet()const=0;
		virtual Hubris::HFileSystem& FileSystemGet()=0;

	};

	/**/
	
};

#endif // _V_SCENE_APPLICATION_INTERFACE_H_