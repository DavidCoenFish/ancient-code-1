//file: Vanity/VComponentForce/VComponentForceDataBase.h
#ifndef _V_COMPONENT_FORCE_DATA_BASE_H_
#define _V_COMPONENT_FORCE_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;
	class VScene;
	struct VComponentForceSampleParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentForceDataBase : public Hubris::HSmartPointerObjectBase< VComponentForceDataBase >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( VComponentForceDataBase );
		EMEMENTO_FACTORY_HEADER_PURE( VComponentForceDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForceDataBase();
		virtual ~VComponentForceDataBase();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID SampleForce(
			Hubris::HVectorR3& in_out_forceSum,
			//Pride::PAxisAngle* const in_out_pRotation,
			const VComponentForceSampleParam& in_param,
			VScene& in_scene,
			const TItemId in_itemId
			)const=0;

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_DATA_BASE_H_