//file: Vanity/VComponentForce/VComponentForceInterfaceObject.h
#ifndef _V_COMPONENT_FORCE_INTERFACE_OBJECT_H_
#define _V_COMPONENT_FORCE_INTERFACE_OBJECT_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	class VComponentForce;
	struct VComponentForceSampleParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentForceInterfaceObject
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Pride::PColourRealRgb >TPairDirectionColour;
		typedef Hubris::HContainerArray< TPairDirectionColour >TArrayPairDirectionColour;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForceInterfaceObject(
			VComponentForce& in_componentLight,
			VScene& in_scene
			);
		~VComponentForceInterfaceObject();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentForceInterfaceObject( const VComponentForceInterfaceObject& in_src );
		const VComponentForceInterfaceObject& operator=( const VComponentForceInterfaceObject& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ForceBoundCreate(
			const TItemId in_itemId,
			const Hubris::HSINT in_forceFlag,
			const Hubris::HSINT in_boundFlag,
			const Pride::PBoundsR3& in_bounds,
			const Hubris::HVectorR3& in_vector
			);

		Hubris::HVOID ForceSphereCreate(
			const TItemId in_itemId,
			const Hubris::HSINT in_forceFlag,
			const Hubris::HSINT in_sphereFlag,
			const Hubris::HVectorR3& in_vector,
			const Hubris::HREAL in_magnitude
			);

		Hubris::HVOID SampleForce(
			Hubris::HVectorR3& in_out_forceSum,
			//Pride::PAxisAngle* const in_out_pRotation,
			const VComponentForceSampleParam& in_param,
			VScene& in_scene,
			const TItemId in_itemId
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& GravitationalAccellerationGet()const;
		Hubris::HVectorR3& GravitationalAccellerationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		VComponentForce& m_componentForce;
		VScene& m_scene;

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_INTERFACE_OBJECT_H_