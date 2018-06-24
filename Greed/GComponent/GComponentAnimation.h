//file: Greed/GComponent/GComponentAnimation.h
#ifndef _G_COMPONENT_ANIMATION_H_
#define _G_COMPONENT_ANIMATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Vanity/VAnimation/VAnimation_Export.h >

#include "Greed/GComponent/GComponentAnimationTargetData.h"

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GComponentAnimationVisitor;
	class GComponentTranslation;
	class GComponentRotation;

	///////////////////////////////////////////////////////
	// class
	/*
		query; does animated component own everything related to the animation.
		such as default value and target enum

		so it can own everything (all state info) a visitor is passed in to receive the update bone values
		rather than oblige the client to remeber what values are updated
	*/
	class GComponentAnimation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< GComponentAnimationTargetData >TPointerTargetData;
		typedef Hubris::HContainerArray< TPointerTargetData >TArrayPointerTargetData;
		typedef Hubris::HSmartPointer< Vanity::VAnimationAsset >TAssetPointer;

		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentAnimation();
		~GComponentAnimation();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GComponentAnimation( const GComponentAnimation& in_src );
		const GComponentAnimation& operator=( const GComponentAnimation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID AnimationAdd(
			const TAssetPointer& in_animationAsset
			);

		Hubris::HVOID TargetAdd(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_defaultValue
			);
		Hubris::HVOID TargetAdd(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HREAL in_defaultValue
			);
		Hubris::HVOID TargetAdd(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR2& in_defaultValue
			);
		Hubris::HVOID TargetAdd(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR3& in_defaultValue
			);
		Hubris::HVOID TargetAdd(
			const Hubris::HString& in_targetName,
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR4& in_defaultValue
			);

		Hubris::HVOID Tick(
			const Sloth::SComponentDelta& in_delta
			);

		Hubris::HVOID Update(
			GComponentAnimationVisitor& out_visitor
			)const;

		///////////////////////////////////////////////////////
		// private members
	private:
		Vanity::VAnimationBlenderAsset m_animationBlender;
		//array[ default value, type, blender index, game object index ]
		TArrayPointerTargetData m_arrayAnimationBoneData;

		//TODO: 
		GComponentTranslation* m_pComponentTranslation;
		GComponentRotation* m_pComponentRotation;

	};

	/**/
	
};

#endif // _G_COMPONENT_ANIMATION_H_