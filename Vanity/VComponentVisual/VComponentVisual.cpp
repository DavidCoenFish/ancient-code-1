//file: Vanity/VComponentVisual/VComponentVisual.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentVisual/VComponentVisual.h"

#include "Vanity/VComponentVisual/VComponentVisualDataHierarchy.h"
#include "Vanity/VComponentVisual/VComponentVisualDataParticle.h"
#include "Vanity/VComponentVisual/VComponentVisualDataSimple.h"

#include "Vanity/VScene/VScene_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////
// local static methods
/**/

///////////////////////////////////////////////////////
// creation
/**/
VComponentVisual::VComponentVisual()
: m_arrayPointerData()
{
	return;
}

/**/
VComponentVisual::~VComponentVisual()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
HVOID VComponentVisual::OnAddItem(
	const Hubris::HSINT in_itemIndex
	)
{
	if( m_arrayPointerData.SizeGet() <= in_itemIndex )
	{
		m_arrayPointerData.SizeResize( in_itemIndex + 1 );
	}

	return;
}
/**/
HVOID VComponentVisual::OnRemoveItem(
	const Hubris::HSINT in_itemIndex
	)
{
	m_arrayPointerData[ in_itemIndex ] = HNULL;
	return;
}

/**/
Hubris::HVOID VComponentVisual::VisualSimpleCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	VComponentVisualDataSimple* pSimple = HNULL;
	HCOMMON_NEW(
		pSimple,
		VComponentVisualDataSimple
		);

	if( HNULL != pSimple )
	{
		pSimple->FilePathSet( in_assetPath );
	}

	m_arrayPointerData[ in_itemId ] = pSimple;

	return;
}

/**/
Hubris::HVOID VComponentVisual::VisualParticleCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	VComponentVisualDataParticle* pParticle = HNULL;
	HCOMMON_NEW(
		pParticle,
		VComponentVisualDataParticle
		);

	if( HNULL != pParticle )
	{
		pParticle->FilePathSet( in_assetPath );
	}

	m_arrayPointerData[ in_itemId ] = pParticle;

	return;
}

/**/
Hubris::HVOID VComponentVisual::VisualHierarchyCreate(
	const TItemId in_itemId,
	const Hubris::HFileSystemPath& in_assetPath
	)
{
	VComponentVisualDataHierarchy* pHierarchy = HNULL;
	HCOMMON_NEW(
		pHierarchy,
		VComponentVisualDataHierarchy
		);

	if( HNULL != pHierarchy )
	{
		pHierarchy->FilePathGet() = in_assetPath;
	}

	m_arrayPointerData[ in_itemId ] = pHierarchy;

	return;
}

/**/
Hubris::HVOID VComponentVisual::Load(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->Load( in_sceneApplicationInterface );

	return;
}

/**/
Hubris::HVOID VComponentVisual::UnLoad(
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->UnLoad( in_sceneApplicationInterface );

	return;
}

/**/
Hubris::HVOID VComponentVisual::AlphaOverrideSet(
	const Hubris::HSINT in_frameId,
	const Hubris::HREAL in_alphaOverride,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->AlphaOverrideSet( 
		in_frameId,
		in_alphaOverride
		);

	return;
}

/**/
const Hubris::HSINT VComponentVisual::RenderLayerGet(
	const TItemId in_itemId
	)const
{
	const TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return HCOMMON_INVALID_INDEX;
	}

	const HSINT renderLayer = pointer->RenderLayerGet();

	return renderLayer;
}

/**/
Hubris::HVOID VComponentVisual::Render( 
	const TItemId in_itemId,
	const Hubris::HSINT in_renderIndex,
	VScene& in_scene,
	VSceneApplicationInterface& in_sceneApplicationInterface
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->Render(
		in_itemId,
		in_renderIndex,
		in_scene,
		in_sceneApplicationInterface
		);

	return;
}

/**/
Hubris::HVOID VComponentVisual::ParticleDataLock(
	const TItemId in_itemId,
	Hubris::HSINT& out_maxCount,
	TArrayParticleData*& out_pArrayParticleData
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	VComponentVisualDataParticle* const pParticle = HTypeRunTimeInfoCast< VComponentVisualDataBase, VComponentVisualDataParticle >( pointer.RawGet() );
	if( HNULL == pParticle )
	{
		return;
	}

	pParticle->ParticleDataLock(
		out_maxCount,
		out_pArrayParticleData
		);

	return;
}

/**/
Hubris::HVOID VComponentVisual::ParticleDataUnlock(
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	VComponentVisualDataParticle* const pParticle = HTypeRunTimeInfoCast< VComponentVisualDataBase, VComponentVisualDataParticle >( pointer.RawGet() );
	if( HNULL == pParticle )
	{
		return;
	}

	pParticle->ParticleDataUnlock();

	return;
}

/**/
Hubris::HVOID VComponentVisual::HierarchyAquireAnimationData(
	const TItemId in_itemId,
	const TArrayBoneData*& out_pArrayBoneData,
	TArrayMatrix*& out_pArrayMatrix
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	VComponentVisualDataHierarchy* const pHierarchy = HTypeRunTimeInfoCast< VComponentVisualDataBase, VComponentVisualDataHierarchy >( pointer.RawGet() );
	if( HNULL == pHierarchy )
	{
		return;
	}

	pHierarchy->AquireAnimationData(
		out_pArrayBoneData,
		out_pArrayMatrix
		);

	return;
}

/**/
Hubris::HVOID VComponentVisual::HierarchyGeometryUpdate(
	const TItemId in_itemId,
	VSceneApplicationInterface& in_sceneApplicationInterface,
	const Sloth::SComponentDelta& in_delta //need delta for bounce
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	VComponentVisualDataHierarchy* const pHierarchy = HTypeRunTimeInfoCast< VComponentVisualDataBase, VComponentVisualDataHierarchy >( pointer.RawGet() );
	if( HNULL == pHierarchy )
	{
		return;
	}

	pHierarchy->GeometryUpdate(
		in_sceneApplicationInterface,
		in_delta
		);

	return;
}

/**
Hubris::HVOID VComponentVisual::AnimationUpdateSubMatrix(
	const Hubris::HSINT in_boneIndex, 
	const Hubris::HMatrixR4& in_matrix,
	const TItemId in_itemId
	)
{
	TPointerData& pointer = m_arrayPointerData[ in_itemId ];
	if( HNULL == pointer )
	{
		return;
	}

	pointer->AnimationUpdateSubMatrix(
		in_boneIndex,
		in_matrix
		);

	return;
}

/**/