//file: Vanity/VComponentForce/VComponentForce.h
#ifndef _V_COMPONENT_FORCE_H_
#define _V_COMPONENT_FORCE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentForce/VComponentForceDataBase.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VComponentForce;
};

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	///////////////////////////////////////////////////////////
	// specialise memento functions for hubris classes
	/**/

	//VComponentForce
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentForce& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentForce& out_data );

};

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VScene;
	struct VComponentForceSampleParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class VComponentForce
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< VComponentForce >( Envy::EMementoCollect& in_out_mementoCollect, const VComponentForce& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< VComponentForce >( const Envy::EMementoAssign& in_out_mementoAssign, VComponentForce& out_data );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;
		typedef Hubris::HSmartPointer< VComponentForceDataBase >TPointerData;
		typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForce();
		~VComponentForce();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VComponentForce( const VComponentForce& in_src );
		const VComponentForce& operator=( const VComponentForce& in_rhs );

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID SampleForceApplyAccelleration(
			Hubris::HVectorR3& in_out_forceSum,
			const Hubris::HVectorR3& in_accelleration,
			const VComponentForceSampleParam& in_param
			);
		static Hubris::HVOID SampleForceApplyForce(
			Hubris::HVectorR3& in_out_forceSum,
			const Hubris::HVectorR3& in_force,
			const VComponentForceSampleParam& in_param
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID OnAddItem(
			const Hubris::HSINT in_itemIndex 
			);

		Hubris::HVOID OnRemoveItem(
			const Hubris::HSINT in_itemIndex 
			);

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
		// static public accessors
	public:
		static const Hubris::HSINT FlagGetForceGravity();
		static const Hubris::HSINT FlagGetForcePhysical();
		static const Hubris::HSINT FlagGetForceMagnetic();
		static const Hubris::HSINT FlagGetForceAir();
		static const Hubris::HSINT FlagGetForceCamera();
		static const Hubris::HSINT FlagGetForceBoyancy();

		static const Hubris::HSINT FlagGetBoundAccelleration();
		static const Hubris::HSINT FlagGetBoundForce();

		static const Hubris::HSINT FlagGetSphereAccelleration();
		static const Hubris::HSINT FlagGetSphereForce();
		static const Hubris::HSINT FlagGetSpherePoint();
		static const Hubris::HSINT FlagGetSphereDirection();
		static const Hubris::HSINT FlagGetSphereFalloffLinear();
		static const Hubris::HSINT FlagGetSphereFalloffSquarDistance();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& GravitationalAccellerationGet()const{ return m_gravitationalAccelleration; }
		Hubris::HVectorR3& GravitationalAccellerationGet(){ return m_gravitationalAccelleration; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayPointerData m_arrayPointerData;
		//like the ambient light, we have a 
		Hubris::HVectorR3 m_gravitationalAccelleration;

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_H_