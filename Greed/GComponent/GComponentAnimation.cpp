//file: Greed/GComponent/GComponentAnimation.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GComponent/GComponentAnimation.h"

#include "Greed/GComponent/GComponentAnimationVisitor.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;

///////////////////////////////////////////////////////
// typedef

///////////////////////////////////////////////////////
// creation
/**/
GComponentAnimation::GComponentAnimation()
: m_animationBlender()
, m_arrayAnimationBoneData()
{
	return;
}

/**/
GComponentAnimation::~GComponentAnimation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID GComponentAnimation::AnimationAdd(
	const TAssetPointer& in_animationAsset
	)
{
	m_animationBlender.AnimationAssetAdd(
		in_animationAsset 
		);
	return;
}

/**/
Hubris::HVOID GComponentAnimation::TargetAdd(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HSINT in_defaultValue
	)
{
	const HSINT blenderTargetIndex = m_animationBlender.TargetNameIndexGet( in_targetName );
	if( HCOMMON_INVALID_INDEX == blenderTargetIndex )
	{
		HCOMMON_WARNING( "animation bone not found" );
		return;
	}

	GComponentAnimationTargetData* pTargetData = HNULL;
	HCOMMON_NEW_PARAM_3(
		pTargetData,
		GComponentAnimationTargetData,
		in_gameObjectVarId,
		blenderTargetIndex,
		in_defaultValue
		);

	TPointerTargetData pointerTargetData( pTargetData );

	m_arrayAnimationBoneData.Insert( pointerTargetData );

	return;
}

/**/
Hubris::HVOID GComponentAnimation::TargetAdd(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HREAL in_defaultValue
	)
{
	const HSINT blenderTargetIndex = m_animationBlender.TargetNameIndexGet( in_targetName );
	if( HCOMMON_INVALID_INDEX == blenderTargetIndex )
	{
		HCOMMON_WARNING( "animation bone not found" );
		return;
	}

	GComponentAnimationTargetData* pTargetData = HNULL;
	HCOMMON_NEW_PARAM_3(
		pTargetData,
		GComponentAnimationTargetData,
		in_gameObjectVarId,
		blenderTargetIndex,
		in_defaultValue
		);

	TPointerTargetData pointerTargetData( pTargetData );

	m_arrayAnimationBoneData.Insert( pointerTargetData );

	return;
}

/**/
Hubris::HVOID GComponentAnimation::TargetAdd(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR2& in_defaultValue
	)
{
	const HSINT blenderTargetIndex = m_animationBlender.TargetNameIndexGet( in_targetName );
	if( HCOMMON_INVALID_INDEX == blenderTargetIndex )
	{
		HCOMMON_WARNING( "animation bone not found" );
		return;
	}

	GComponentAnimationTargetData* pTargetData = HNULL;
	HCOMMON_NEW_PARAM_3(
		pTargetData,
		GComponentAnimationTargetData,
		in_gameObjectVarId,
		blenderTargetIndex,
		in_defaultValue
		);

	TPointerTargetData pointerTargetData( pTargetData );

	m_arrayAnimationBoneData.Insert( pointerTargetData );

	return;
}

/**/
Hubris::HVOID GComponentAnimation::TargetAdd(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR3& in_defaultValue
	)
{
	const HSINT blenderTargetIndex = m_animationBlender.TargetNameIndexGet( in_targetName );
	if( HCOMMON_INVALID_INDEX == blenderTargetIndex )
	{
		HCOMMON_WARNING( "animation bone not found" );
		return;
	}

	GComponentAnimationTargetData* pTargetData = HNULL;
	HCOMMON_NEW_PARAM_3(
		pTargetData,
		GComponentAnimationTargetData,
		in_gameObjectVarId,
		blenderTargetIndex,
		in_defaultValue
		);

	TPointerTargetData pointerTargetData( pTargetData );

	m_arrayAnimationBoneData.Insert( pointerTargetData );

	return;
}

/**/
Hubris::HVOID GComponentAnimation::TargetAdd(
	const Hubris::HString& in_targetName,
	const Hubris::HSINT in_gameObjectVarId,
	const Hubris::HVectorR4& in_defaultValue
	)
{
	const HSINT blenderTargetIndex = m_animationBlender.TargetNameIndexGet( in_targetName );
	if( HCOMMON_INVALID_INDEX == blenderTargetIndex )
	{
		HCOMMON_WARNING( "animation bone not found" );
		return;
	}

	GComponentAnimationTargetData* pTargetData = HNULL;
	HCOMMON_NEW_PARAM_3(
		pTargetData,
		GComponentAnimationTargetData,
		in_gameObjectVarId,
		blenderTargetIndex,
		in_defaultValue
		);

	TPointerTargetData pointerTargetData( pTargetData );

	m_arrayAnimationBoneData.Insert( pointerTargetData );

	return;
}

/**/
Hubris::HVOID GComponentAnimation::Tick(
	const Sloth::SComponentDelta& in_delta
	)
{
	m_animationBlender.TimeDeltaApply( in_delta.LastDeltaGet() );
	return;
}

/**/
Hubris::HVOID GComponentAnimation::Update(
	GComponentAnimationVisitor& out_visitor
	)const
{
	HCOMMON_FOR_EACH_CONST( pData, m_arrayAnimationBoneData, TArrayPointerTargetData )
	{
		if( HNULL == pData )
		{
			continue;
		}

		const HSINT type = pData->TypeIndexGet();
		if( type == GComponentAnimationTargetData::TypeGetSint() )
		{
			HSINT value = pData->DefaultValueSintGet();
			m_animationBlender.SampleValueGet(
				value,
				pData->BlenderTargetIndexGet()
				);
			out_visitor.ValueSet(
				pData->GameObjectVarIdGet(),
				value
				);
		}
		else if( type == GComponentAnimationTargetData::TypeGetReal() )
		{
			HREAL value = pData->DefaultValueRealGet();
			m_animationBlender.SampleValueGet(
				value,
				pData->BlenderTargetIndexGet()
				);
			out_visitor.ValueSet(
				pData->GameObjectVarIdGet(),
				value
				);
		}
		else if( type == GComponentAnimationTargetData::TypeGetVectorR2() )
		{
			HVectorR2 value = pData->DefaultValueVectorR2Get();
			m_animationBlender.SampleValueGet(
				value,
				pData->BlenderTargetIndexGet()
				);
			out_visitor.ValueSet(
				pData->GameObjectVarIdGet(),
				value
				);
		}
		else if( type == GComponentAnimationTargetData::TypeGetVectorR3() )
		{
			HVectorR3 value = pData->DefaultValueVectorR3Get();
			m_animationBlender.SampleValueGet(
				value,
				pData->BlenderTargetIndexGet()
				);
			out_visitor.ValueSet(
				pData->GameObjectVarIdGet(),
				value
				);
		}
		else if( type == GComponentAnimationTargetData::TypeGetVectorR4() )
		{
			HVectorR4 value = pData->DefaultValueVectorR4Get();
			m_animationBlender.SampleValueGet(
				value,
				pData->BlenderTargetIndexGet()
				);
			out_visitor.ValueSet(
				pData->GameObjectVarIdGet(),
				value
				);
		}

	}

	return;
}

/**/
