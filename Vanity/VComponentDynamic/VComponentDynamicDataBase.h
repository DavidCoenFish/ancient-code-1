//file: Vanity/VComponentDynamic/VComponentDynamicDataBase.h
#ifndef _V_COMPONENT_DYNAMIC_DATA_BASE_H_
#define _V_COMPONENT_DYNAMIC_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentDynamicContactData;
	class VComponentDynamicComponentParam;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentDynamicDataBase : public Hubris::HSmartPointerObjectBase< VComponentDynamicDataBase >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( VComponentDynamicDataBase );
		EMEMENTO_FACTORY_HEADER_PURE( VComponentDynamicDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerArray< VComponentDynamicContactData >TArrayContactData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicDataBase();
		virtual ~VComponentDynamicDataBase();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentDynamicDataBase( const VComponentDynamicDataBase& in_src );
		const VComponentDynamicDataBase& operator=( const VComponentDynamicDataBase& in_rhs );

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID OnStartNewFrame()=0;

		virtual Hubris::HVOID ItemParamGet(
			VComponentDynamicComponentParam& out_param,
			Hubris::HREAL& out_invertMass //zero if item doesn't move
			)const=0;

		virtual Hubris::HVOID ItemParamSet(
			const VComponentDynamicComponentParam& in_param,
			const Hubris::HREAL in_invertMass //zero if item doesn't move
			)=0;

		virtual Hubris::HVOID ItemDataGet(
			TArrayContactData* const out_pArrayContactData = HNULL,
			Hubris::HVectorR3* const out_pVelocity = HNULL,
			Pride::PUnitVectorR3* const out_pRotationAxis = HNULL,
			Hubris::HREAL* const out_pRotationMagnitude = HNULL
			)const=0;

	};

	/**/
	
};

#endif // _V_COMPONENT_DYNAMIC_DATA_BASE_H_