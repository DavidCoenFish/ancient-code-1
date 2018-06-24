//file: Vanity/VAnimation/VAnimationAsset.h
#ifndef _V_ANIMATION_ASSET_H_
#define _V_ANIMATION_ASSET_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAsset/VAsset.h"
#include "Vanity/VAnimation/VAnimation.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VSceneApplicationInterface;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VAnimationAsset : public VAsset
	{
		HTYPE_RUN_TIME_TYPE_INFO( VAnimationAsset, VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VAnimation >TArrayAnimation;

		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationAsset(
			VSceneApplicationInterface& in_out_sceneApplicationInterface,
			const Hubris::HFileSystemPath& in_path					
			);
		~VAnimationAsset();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VAnimationAsset( const VAnimationAsset& in_src );
		const VAnimationAsset& operator=( const VAnimationAsset& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID CreateAsset(
			const Hubris::HFileSystemPath& in_path,
			const TArrayAnimation& in_arrayAnimation
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArrayAnimation& ArrayAnimationGet()const{ return m_arrayAnimation; }
		TArrayAnimation& ArrayAnimationGet(){ return m_arrayAnimation; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayAnimation m_arrayAnimation;

	};

	/**/
	
};

#endif // _V_ANIMATION_ASSET_H_