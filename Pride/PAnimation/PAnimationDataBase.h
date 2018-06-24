//file: Pride/PAnimation/PAnimationDataBase.h
#ifndef _P_ANIMATION_DATA_BASE_H_
#define _P_ANIMATION_DATA_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >
#include< Hubris/HType/HType_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PInterfaceAnimationVisitor;
	class PInterfaceAnimationVisitorKeys;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PAnimationDataBase : public Hubris::HSmartPointerObjectBase< PAnimationDataBase >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( PAnimationDataBase );

		///////////////////////////////////////////////////////
		// interface
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual PAnimationDataBase* const Clone()const=0;
		virtual Hubris::HVOID DeleteThis()=0;

		virtual const Hubris::HBOOL Cmp( const PAnimationDataBase* const in_pRhs )const=0;

		virtual Hubris::HVOID SubmitVisitor( const Hubris::HREAL in_time, PInterfaceAnimationVisitor& out_visitor )const=0;
		virtual Hubris::HVOID SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const=0;

		virtual const Hubris::HString& NameGet()const=0;
		virtual Hubris::HVOID NameSet( const Hubris::HString& in_name )=0;
		virtual Hubris::HVOID TimeRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const=0;
		virtual Hubris::HVOID TimeGet( TArrayReal& out_arrayTime )const=0;

	};

	/**/
	
};

#endif // _P_ANIMATION_DATA_BASE_H_