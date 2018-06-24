//file: Vanity/VComponentDynamic/VComponentDynamicComponentParam.h
#ifndef _V_COMPONENT_DYNAMIC_COMPONENT_PARAM_H_
#define _V_COMPONENT_DYNAMIC_COMPONENT_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentDynamicComponentParam
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicComponentParam( const VComponentDynamicComponentParam& in_src );
		VComponentDynamicComponentParam(
			const Hubris::HREAL in_staticFriction,
			const Hubris::HREAL in_movingFriction,
			const Hubris::HREAL in_elasticCollisionDampen
			);
		VComponentDynamicComponentParam();
		~VComponentDynamicComponentParam();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentDynamicComponentParam& operator=( const VComponentDynamicComponentParam& in_rhs );
		const Hubris::HBOOL operator==( const VComponentDynamicComponentParam& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentDynamicComponentParam& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HREAL StaticFrictionGet()const{ return m_staticFriction; }
		Hubris::HVOID StaticFrictionSet( const Hubris::HREAL in_staticFriction ){ m_staticFriction = in_staticFriction; return; }

		const Hubris::HREAL MovingFrictionGet()const{ return m_movingFriction; }
		Hubris::HVOID MovingFrictionSet( const Hubris::HREAL in_movingFriction ){ m_movingFriction = in_movingFriction; return; }

		const Hubris::HREAL ElasticCollisionDampenGet()const{ return m_elasticCollisionDampen; }
		Hubris::HVOID ElasticCollisionDampenSet( const Hubris::HREAL in_elasticCollisionDampen ){ m_elasticCollisionDampen = in_elasticCollisionDampen; return; }

		///////////////////////////////////////////////////////
		// private member
	private:
		Hubris::HREAL m_staticFriction;
		Hubris::HREAL m_movingFriction;
		Hubris::HREAL m_elasticCollisionDampen;

	};

	/**/
};

#endif // _V_COMPONENT_DYNAMIC_COMPONENT_PARAM_H_