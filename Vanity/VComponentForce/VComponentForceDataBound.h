//file: Vanity/VComponentForce/VComponentForceDataBound.h
#ifndef _V_COMPONENT_FORCE_DATA_BOUND_H_
#define _V_COMPONENT_FORCE_DATA_BOUND_H_

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
	*/
	class VComponentForceDataBound : public VComponentForceDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( VComponentForceDataBound, VComponentForceDataBase );
		EMEMENTO_FACTORY_HEADER( VComponentForceDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForceDataBound();
		virtual ~VComponentForceDataBound();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentForceDataBound( const VComponentForceDataBound& in_src );
		const VComponentForceDataBound& operator=( const VComponentForceDataBound& in_rhs );

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
			const Pride::PBoundsR3& in_bounds,
			const Hubris::HVectorR3& in_vector
			);

		///////////////////////////////////////////////////////
		// private methods
	public:

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT FlagGetAccelleration();
		static const Hubris::HSINT FlagGetForce();

		///////////////////////////////////////////////////////
		// public acessors
	public:
		const Hubris::HSINT ForceFlagGet()const{ return m_forceFlag; }
		Hubris::HVOID ForceFlagSet( const Hubris::HSINT in_forceFlag ){ m_forceFlag = in_forceFlag; return; }

		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( const Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		const Pride::PBoundsR3& BoundsGet()const{ return m_bounds; }
		Pride::PBoundsR3& BoundsGet(){ return m_bounds; }

		const Hubris::HVectorR3& VectorGet()const{ return m_vector; }
		Hubris::HVectorR3& VectorGet(){ return m_vector; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_forceFlag;
		Hubris::HSINT m_flag; //am i a force or an accelleration
		Pride::PBoundsR3 m_bounds;
		Hubris::HVectorR3 m_vector; //force or accelleration

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_DATA_BOUND_H_