//file: Vanity/VComponentDynamic/VComponentDynamicDataStatic.h
#ifndef _V_COMPONENT_DYNAMIC_DATA_STATIC_H_
#define _V_COMPONENT_DYNAMIC_DATA_STATIC_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentDynamic/VComponentDynamicDataBase.h"
#include "Vanity/VComponentDynamic/VComponentDynamicComponentParam.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentDynamicDataStatic : public VComponentDynamicDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentDynamicDataStatic, VComponentDynamicDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentDynamicDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< VComponentDynamicContactData >TArrayContactData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicDataStatic(
			const VComponentDynamicComponentParam& in_param
			);
		VComponentDynamicDataStatic();
		virtual ~VComponentDynamicDataStatic();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentDynamicDataStatic( const VComponentDynamicDataStatic& in_src );
		const VComponentDynamicDataStatic& operator=( const VComponentDynamicDataStatic& in_rhs );

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

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentDynamicComponentParam m_param;

	};

};

#endif // _V_COMPONENT_DYNAMIC_DATA_STATIC_H_