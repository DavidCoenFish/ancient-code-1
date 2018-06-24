//file: Pride/PInterface/PInterfaceAnimationVisitor.h
#ifndef _P_INTERFACE_ANIMATION_VISITOR_H_
#define _P_INTERFACE_ANIMATION_VISITOR_H_

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
		provide interface for visiting an animation
	*/
	class PInterfaceAnimationVisitor
	{
		///////////////////////////////////////////////////////
		// interface
	public:
		//not test function, rather assert if there is a target in use we don't want, something is wrong, target logic on code not data side
		//virtual Hubris::HBOOL ValueAccept( const Hubris::HString& in_targetName )=0;

		virtual Hubris::HVOID ValueGet( const Hubris::HString& in_targetName, PInterfaceAnimationVariant& out_value )=0;
		virtual Hubris::HVOID ValueSet( const Hubris::HString& in_targetName, const PInterfaceAnimationVariant& in_value )=0;


		//virtual Hubris::HVOID ValueAbsoluteGet( const Hubris::HString& in_targetName, PInterfaceAnimationVariant& out_value )=0;
		//virtual Hubris::HVOID ValueAbsoluteSet( const Hubris::HString& in_targetName, const PInterfaceAnimationVariant& in_value )=0;

	};

	/**/
};

#endif // _P_INTERFACE_ANIMATION_VISITOR_H_