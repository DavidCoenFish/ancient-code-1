//file: Pride/PAnimation/PAnimationImplementation.h
#ifndef _P_ANIMATION_IMPELEMENTATION_H_
#define _P_ANIMATION_IMPELEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	class PAnimationDataBase;
	class PInterfaceAnimationVisitor;
	class PInterfaceAnimationVisitorKeys;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PAnimationImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< PAnimationDataBase >PAnimationDataBasePointer;
		typedef Hubris::HContainerArray< PAnimationDataBasePointer >TArrayDataPointer;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		PAnimationImplementation( const PAnimationImplementation& in_src );
		PAnimationImplementation();
		~PAnimationImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PAnimationImplementation& operator=( const PAnimationImplementation& in_rhs );
		Hubris::HBOOL operator==( const PAnimationImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PAnimationImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL IsEmpty()const;
		Hubris::HVOID Clear();
		Hubris::HVOID DataRemove( const Hubris::HString& in_name );
		Hubris::HVOID DataRename( const Hubris::HString& in_oldName, const Hubris::HString& in_newName );

		//WARNING, transferal of ownership, presume private to component
		Hubris::HVOID DataAdd( PAnimationDataBasePointer& in_pAnimationDataBase );

		Hubris::HVOID NameArrayGet( TArrayString& out_arrayName )const;
		Hubris::HVOID TimeKeyGet( const Hubris::HString& in_name, TArrayReal& out_arrayTime )const;

		Hubris::HVOID TimeRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const;
		Hubris::HVOID SubmitVisitor( const Hubris::HREAL in_time, PInterfaceAnimationVisitor& out_visitor )const;

		Hubris::HVOID SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const;

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayDataPointer m_arrayDataPointer;
		Hubris::HREAL m_timeRangeLow;
		Hubris::HREAL m_timeRangeHigh;

	};

	/**/	
};

#endif // _P_ANIMATION_IMPELEMENTATION_H_