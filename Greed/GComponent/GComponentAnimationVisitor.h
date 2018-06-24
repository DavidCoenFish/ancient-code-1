//file: Greed/GComponent/GComponentAnimationVisitor.h
#ifndef _G_COMPONENT_ANIMATION_VISITOR_H_
#define _G_COMPONENT_ANIMATION_VISITOR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Vanity/VAnimation/VAnimation_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GComponent;

	///////////////////////////////////////////////////////
	// class
	/*
		interface for game object to receive animation
	*/
	class GComponentAnimationVisitor
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentAnimationVisitor();
		~GComponentAnimationVisitor();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GComponentAnimationVisitor( const GComponentAnimationVisitor& in_src );
		const GComponentAnimationVisitor& operator=( const GComponentAnimationVisitor& in_rhs );

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID TranslationSet(
			const Hubris::HVectorR3& in_value
			);

		virtual Hubris::HVOID RotationSet(
			const Hubris::HQuaternionREAL& in_value
			);

		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HREAL in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR2& in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR3& in_animatedValue
			);
		virtual Hubris::HVOID ValueSet(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HVectorR4& in_animatedValue
			);

	};

	/**/
	
};

#endif // _G_COMPONENT_ANIMATION_VISITOR_H_