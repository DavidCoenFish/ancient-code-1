//file: Greed/GComponent/GComponentAnimationTargetData.h
#ifndef _G_COMPONENT_ANIMATION_TARGET_DATA_H_
#define _G_COMPONENT_ANIMATION_TARGET_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class GComponentAnimationTargetData : public Hubris::HSmartPointerObjectBase< GComponentAnimationTargetData >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentAnimationTargetData(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HSINT in_defaultValue
			);
		GComponentAnimationTargetData(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HREAL in_defaultValue
			);
		GComponentAnimationTargetData(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HVectorR2& in_defaultValue
			);
		GComponentAnimationTargetData(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HVectorR3& in_defaultValue
			);
		GComponentAnimationTargetData(
			const Hubris::HSINT in_gameObjectVarId,
			const Hubris::HSINT in_blenderTargetIndex,
			const Hubris::HVectorR4& in_defaultValue
			);
		~GComponentAnimationTargetData();

		///////////////////////////////////////////////////////
		// disabled
	private:
		GComponentAnimationTargetData( const GComponentAnimationTargetData& in_src );
		const GComponentAnimationTargetData& operator=( const GComponentAnimationTargetData& in_rhs );

		///////////////////////////////////////////////////////
		// static public accessor
	public:
		static const Hubris::HSINT TypeGetSint();
		static const Hubris::HSINT TypeGetReal();
		static const Hubris::HSINT TypeGetVectorR2();
		static const Hubris::HSINT TypeGetVectorR3();
		static const Hubris::HSINT TypeGetVectorR4();

		///////////////////////////////////////////////////////
		// public accessor
	public:
		const Hubris::HSINT GameObjectVarIdGet()const{ return m_gameObjectVarId; }
		const Hubris::HSINT BlenderTargetIndexGet()const{ return m_blenderTargetIndex; }
		const Hubris::HSINT TypeIndexGet()const{ return m_typeIndex; }

		const Hubris::HSINT DefaultValueSintGet()const;
		const Hubris::HREAL DefaultValueRealGet()const;
		const Hubris::HVectorR2& DefaultValueVectorR2Get()const;
		const Hubris::HVectorR3& DefaultValueVectorR3Get()const;
		const Hubris::HVectorR4& DefaultValueVectorR4Get()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		const Hubris::HSINT m_gameObjectVarId;
		const Hubris::HSINT m_blenderTargetIndex;
		const Hubris::HSINT m_typeIndex;
		Hubris::HVOID* m_pData;

	};

	/**/
	
};

#endif // _G_COMPONENT_ANIMATION_TARGET_DATA_H_