//file: Vanity/VComponentForce/VComponentForceDataSphere.h
#ifndef _V_COMPONENT_FORCE_DATA_SPHERE_H_
#define _V_COMPONENT_FORCE_DATA_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VComponentForce/VComponentForceDataBase.h"

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
		point force, sphere directional force
		with falloff...
	*/
	class VComponentForceDataSphere : public VComponentForceDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentForceDataSphere, VComponentForceDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentForceDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForceDataSphere();
		virtual ~VComponentForceDataSphere();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentForceDataSphere( const VComponentForceDataSphere& in_src );
		const VComponentForceDataSphere& operator=( const VComponentForceDataSphere& in_rhs );

		///////////////////////////////////////////////////////
		// implement VComponentForceDataBase
	public:
		virtual Hubris::HVOID SampleForce(
			Hubris::HVectorR3& in_out_forceSum,
			//Pride::PAxisAngle* const in_out_pRotation,
			const VComponentForceSampleParam& in_param,
			VScene& in_scene,
			const TItemId in_itemId
			)const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID DataSet(
			const Hubris::HSINT in_forceFlag,
			const Hubris::HSINT in_flag,
			const Hubris::HVectorR3& in_vector,
			const Hubris::HREAL in_magnitude
			);

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT FlagGetAccelleration();
		static const Hubris::HSINT FlagGetForce();
		static const Hubris::HSINT FlagGetPoint();
		static const Hubris::HSINT FlagGetDirection();
		static const Hubris::HSINT FlagGetFalloffLinear();
		static const Hubris::HSINT FlagGetFalloffSquarDistance();

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HSINT ForceFlagGet()const{ return m_forceFlag; }
		Hubris::HVOID ForceFlagSet( const Hubris::HSINT in_forceFlag ){ m_forceFlag = in_forceFlag; return; }

		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( const Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		const Hubris::HVectorR3& VectorGet()const{ return m_vector; }
		Hubris::HVectorR3& VectorGet(){ return m_vector; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_forceFlag;
		Hubris::HSINT m_flag; //am i a force or an accelleration, point force, direction, falloff linear, 
		Hubris::HVectorR3 m_vector; //magnitude is put in vector[0], can not yet have both
		//Hubris::HREAL m_magnitude;

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_DATA_SPHERE_H_