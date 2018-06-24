//file: Vanity/VComponentForce/VComponentForceSampleParam.h
#ifndef _V_COMPONENT_FORCE_SAMPLE_PARAM_H_
#define _V_COMPONENT_FORCE_SAMPLE_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// struct
	/*
		hold param for force sample function
	*/
	struct VComponentForceSampleParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentForceSampleParam(
			const Hubris::HSINT in_forceFlag,
			const Hubris::HVectorR3& in_location,
			const Hubris::HREAL in_massInvert = 1.0F
			);
		~VComponentForceSampleParam();

		///////////////////////////////////////////////////////
		// disabled
	private:
		VComponentForceSampleParam( const VComponentForceSampleParam& in_src );
		const VComponentForceSampleParam& operator=( const VComponentForceSampleParam& in_rhs );

	public:
		const Hubris::HSINT m_forceFlag;
		const Hubris::HVectorR3& m_location;
		const Hubris::HREAL m_massInvert;

	};

	/**/
	
};

#endif // _V_COMPONENT_FORCE_SAMPLE_PARAM_H_