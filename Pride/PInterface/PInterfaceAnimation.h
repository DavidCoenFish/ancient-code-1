//file: Pride/PInterface/PInterfaceAnimation.h
#ifndef _P_INTERFACE_ANIMATION_H_
#define _P_INTERFACE_ANIMATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PInterfaceAnimationVisitor;
	class PInterfaceAnimationVisitorKeys;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PInterfaceAnimation
	{
		/////////////////////////////////////////////////////////////////
		// interface
	public:
		//return true it the animation has a time range, ie, expects to be used in absolute mode
		virtual const Hubris::HBOOL TimeAbsoluteTest()const=0;

		virtual Hubris::HVOID TimeAbsoluteRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const=0;

		virtual Hubris::HVOID SubmitVisitorAbsolute( const Hubris::HREAL in_timeAbsolute, PInterfaceAnimationVisitor& out_visitor )const=0;
		virtual Hubris::HVOID SubmitVisitorDelta( const Hubris::HREAL in_timeDelta, PInterfaceAnimationVisitor& out_visitor )const=0;

		//pull out all the animation data
		virtual Hubris::HVOID SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const=0;

	};
	/**/
	
};

#endif // _P_INTERFACE_ANIMATION_H_