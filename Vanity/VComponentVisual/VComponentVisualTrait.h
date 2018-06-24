//file: Vanity/VComponentVisual/VComponentVisualTrait.h
#ifndef _V_COMPONENT_VISUAL_TRAIT_H_
#define _V_COMPONENT_VISUAL_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Vanity
{
	class VComponentVisual;
	class VComponentVisualAssetHierarchy;
	class VComponentVisualAssetHierarchyBoneData;
	//class VComponentVisualAssetHierarchyBoneSkinData;
	class VComponentVisualAssetHierarchyGeometryData;
	class VComponentVisualAssetParticleTypeData;
	class VComponentVisualAssetSimple;
	class VComponentVisualDataHierarchy;
	class VComponentVisualDataParticle;
	class VComponentVisualDataSimple;

};
namespace Envy
{
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );
};

///////////////////////////////////////////////////////
// trait
/**/
HTYPE_NAME_HEADER( Vanity::VComponentVisualDataParticle );
HTYPE_NAME_HEADER( Vanity::VComponentVisualDataSimple );
HTYPE_NAME_HEADER( Vanity::VComponentVisualDataHierarchy );

namespace Envy
{
	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	//VComponentVisual
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisual& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisual& out_data );

	//VComponentVisualDataHierarchy
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataHierarchy& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataHierarchy& out_data );

	//VComponentVisualDataSimple
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataSimple& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataSimple& out_data );

	//VComponentVisualDataParticle
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualDataParticle& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualDataParticle& out_data );

	//VComponentVisualAssetParticleTypeData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetParticleTypeData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetParticleTypeData& out_data );

	//VComponentVisualAssetHierarchyBoneData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyBoneData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyBoneData& out_data );

	//VComponentVisualAssetHierarchyBoneSkinData
	//template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyBoneSkinData& in_data );
	//template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyBoneSkinData& out_data );

	//VComponentVisualAssetHierarchyGeometryData
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentVisualAssetHierarchyGeometryData& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentVisualAssetHierarchyGeometryData& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////////
	// global functions
	/**/
	Hubris::HVOID VComponentVisualTraitFactoryRegister();

};


#endif // _V_COMPONENT_VISUAL_TRAIT_H_