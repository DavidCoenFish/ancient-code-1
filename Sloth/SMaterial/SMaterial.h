//file: Sloth/SMaterial/SMaterial.h
#ifndef _S_MATERIAL_H_
#define _S_MATERIAL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

#include "Sloth/SMaterial/SMaterialStage.h"
#include "Sloth/SMaterial/SMaterialGeometryStage.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/**/
	class SMaterial
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< SMaterialStage, SMaterialGeometryStage >TPairStageMaterialGeometry;
		typedef Hubris::HContainerArray< TPairStageMaterialGeometry >TArrayPairStageMaterialGeometry;

		///////////////////////////////////////////////////////
		// creation
	public:
		SMaterial( const SMaterial& in_src );
		SMaterial(
			const TArrayPairStageMaterialGeometry& in_arrayStageMaterialGeometry
			);
		SMaterial();
		~SMaterial();

		///////////////////////////////////////////////////////
		// operators
	public:
		const SMaterial& operator=( const SMaterial& in_rhs );
		Hubris::HBOOL operator==( const SMaterial& in_rhs )const;
		Hubris::HBOOL operator!=( const SMaterial& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT StageCountGet()const;

		const SMaterialStage& StageMaterialGet( const Hubris::HSINT in_stageIndex )const;
		SMaterialStage& StageMaterialGet( const Hubris::HSINT in_stageIndex );

		const SMaterialGeometryStage& StageGeometryGet( const Hubris::HSINT in_stageIndex )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArrayPairStageMaterialGeometry& ArrayStageGeometryGet()const{ return m_arrayStageMaterialGeometry; }
		TArrayPairStageMaterialGeometry& ArrayStageGeometryGet(){ return m_arrayStageMaterialGeometry; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayPairStageMaterialGeometry m_arrayStageMaterialGeometry;

	};

	/**/	
};

#endif // _S_MATERIAL_H_