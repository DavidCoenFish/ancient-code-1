//file: Vanity/VComponentDynamic/VComponentDynamicContactData.h
#ifndef _V_COMPONENT_DYNAMIC_CONTACT_DATA_H_
#define _V_COMPONENT_DYNAMIC_CONTACT_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VComponentDynamicContactData
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSINT TItemId;

		///////////////////////////////////////////////////////
		// creation
	public:
		VComponentDynamicContactData( const VComponentDynamicContactData& in_src );
		VComponentDynamicContactData();
		~VComponentDynamicContactData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VComponentDynamicContactData& operator=( const VComponentDynamicContactData& in_rhs );
		const Hubris::HBOOL operator==( const VComponentDynamicContactData& in_rhs )const;
		const Hubris::HBOOL operator!=( const VComponentDynamicContactData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& ContactNormalGet()const{ return m_contactNormal; }
		Hubris::HVectorR3& ContactNormalGet(){ return m_contactNormal; }

		const Hubris::HVectorR3& ContactPositionGet()const{ return m_contactPosition; }
		Hubris::HVectorR3& ContactPositionGet(){ return m_contactPosition; }

		const TItemId& TouchingObjectIdGet()const{ return m_touchingObjectId; }
		TItemId& TouchingObjectIdGet(){ return m_touchingObjectId; }

		const Hubris::HBOOL& TargetCanMoveGet()const{ return m_targetCanMove; }
		Hubris::HBOOL& TargetCanMoveGet(){ return m_targetCanMove; }

		///////////////////////////////////////////////////////
		// private member
	private:
		Hubris::HVectorR3 m_contactNormal; //worldSpace
		Hubris::HVectorR3 m_contactPosition; //worldSpace
		TItemId m_touchingObjectId;
		Hubris::HBOOL m_targetCanMove;//?
		

	};

	/**/
};

#endif // _V_COMPONENT_DYNAMIC_CONTACT_DATA_H_