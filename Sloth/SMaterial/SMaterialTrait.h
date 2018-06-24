//file: Sloth/SMaterial/SMaterialTrait.h
#ifndef _S_MATERIAL_TRAIT_H_
#define _S_MATERIAL_TRAIT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	class SMaterial;
	class SMaterialStage;
	class SMaterialGeometryStage;
};

/**/
namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	///////////////////////////////////////////////////////////
	// memento
	/**/
	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	//SMaterial
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterial& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterial& out_data );

	//SMaterialStage
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialStage& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialStage& out_data );

	//SMaterialGeometryStage
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialGeometryStage& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialGeometryStage& out_data );

};

#endif // _S_MATERIAL_TRAIT_H_