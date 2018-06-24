//file: Vanity/VComponentDynamic/VComponentDynamicDataSimple.h
#ifndef _V_COMPONENT_DYNAMIC_DATA_SIMPLE_H_
#define _V_COMPONENT_DYNAMIC_DATA_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Vanity/VComponentDynamic/VComponentDynamicDataBase.h"
#include "Vanity/VComponentDynamic/VComponentDynamicContactData.h"
#include "Vanity/VComponentDynamic/VComponentDynamicComponentParam.h"

#include< Lust/LTranslation/LTranslation_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		flags for use collision, use rotation? or seperate classes

		data simple is currently simple movement of the item without rotation, using item scene sphere for sweep shape
	*/
	class VComponentDynamicDataSimple : public VComponentDynamicDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentDynamicDataSimple, VComponentDynamicDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentDynamicDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentDynamicContactData >TArrayContactData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicDataSimple(
			const VComponentDynamicComponentParam& in_param,
			const Hubris::HREAL m_invertMass
			);
		VComponentDynamicDataSimple();
		virtual ~VComponentDynamicDataSimple();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentDynamicDataSimple( const VComponentDynamicDataSimple& in_src );
		const VComponentDynamicDataSimple& operator=( const VComponentDynamicDataSimple& in_rhs );

		///////////////////////////////////////////////////////
		// implememnt VComponentDynamicDataBase
	private:
		virtual Hubris::HVOID OnStartNewFrame();

		virtual Hubris::HVOID ItemParamGet(
			VComponentDynamicComponentParam& out_param,
			Hubris::HREAL& out_invertMass //zero if item doesn't move
			)const;

		virtual Hubris::HVOID ItemParamSet(
			const VComponentDynamicComponentParam& in_param,
			const Hubris::HREAL in_invertMass //zero if item doesn't move
			);

		virtual Hubris::HVOID ItemDataGet(
			TArrayContactData* const out_pArrayContactData = HNULL,
			Hubris::HVectorR3* const out_pVelocity = HNULL,
			Pride::PUnitVectorR3* const out_pRotationAxis = HNULL,
			Hubris::HREAL* const out_pRotationMagnitude = HNULL
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const VComponentDynamicComponentParam& ParamGet()const{ return m_param; }
		VComponentDynamicComponentParam& ParamGet(){ return m_param; }

		const Hubris::HREAL& InvertMassGet()const{ return m_invertMass; }
		Hubris::HREAL& InvertMassGet(){ return m_invertMass; }

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentDynamicComponentParam m_param;
		Hubris::HREAL m_invertMass;

		TArrayContactData m_arrayContactData;

		Lust::LTranslationComponentForceSum m_translationForceSum;
		Lust::LTranslationComponentVelocity m_translationVelocity;
		Lust::LTranslationComponent m_translation; //effectivly the target location, after resolution, should be used to set the vscene poistion of the item

		Hubris::HBOOL m_resolvedMovement; //flag if movement already resolved (in dynamic overlap pass?)

	};

};

#endif // _V_COMPONENT_DYNAMIC_DATA_SIMPLE_H_