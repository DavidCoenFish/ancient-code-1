//file: Pride/PInterface/PInterfaceAnimationVisitorKeys.h
#ifndef _P_INTERFACE_ANIMATION_VISITOR_KEYS_H_
#define _P_INTERFACE_ANIMATION_VISITOR_KEYS_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HString;
};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PInterfaceAnimationVariant;

	///////////////////////////////////////////////////////
	// class
	/*
		provide interface for visiting an animation to get the key data out
	*/
	class PInterfaceAnimationVisitorKeys
	{
		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID KeyValueSet( 
			const Hubris::HString& in_targetName, 
			const Hubris::HREAL& in_time,
			const PInterfaceAnimationVariant& in_value
			)=0;

	};

	/**/
};

#endif // _P_INTERFACE_ANIMATION_VISITOR_KEYS_H_