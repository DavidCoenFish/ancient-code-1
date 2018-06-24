//file: Sloth/SMaterial/SMaterialStageShaderData.h
#ifndef _S_MATERIAL_STAGE_SHADER_DATA_H_
#define _S_MATERIAL_STAGE_SHADER_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Envy/EDataStore/EDataStore.h >
#include< Hubris/HVariant/HVariant.h >
#include< Hubris/HType/HTypeList.h >

namespace Sloth
{
	class SMaterialStageShaderDataVariant;
};

namespace Envy
{
	class EMementoCollect;
	class EMementoAssign;

	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Sloth::SMaterialStageShaderDataVariant& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Sloth::SMaterialStageShaderDataVariant& out_data );

};

namespace Sloth
{
	///////////////////////////////////////////////////
	// typedefs
	/**/
	typedef HTYPE_LIST_3( 
		Hubris::HBOOL,
		Hubris::HS32,
		Hubris::HR32
	)SMaterialStageShaderDataVariantTypeList;

	/**/
	HVARIANT_DEFINITION( SMaterialStageShaderDataVariant, SMaterialStageShaderDataVariantTypeList );

	///////////////////////////////////////////////////////
	// class
	/**/
	typedef Envy::ERecursiveDataStore< SMaterialStageShaderDataVariant >SMaterialStageShaderData;

	/**/
};

#endif // _S_MATERIAL_STAGE_SHADER_DATA_H_