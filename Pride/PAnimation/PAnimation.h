//file: Pride/PAnimation/PAnimation.h
#ifndef _P_ANIMATION_H_
#define _P_ANIMATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PAnimation/PAnimationData.h"
#include "Pride/PInterface/PInterfaceAnimation.h"

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	class PAnimationDataBase;
	class PAnimationImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PAnimation : public PInterfaceAnimation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< PAnimationDataBase >PAnimationDataBasePointer;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		PAnimation( const PAnimation& in_src );
		PAnimation();
		~PAnimation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PAnimation& operator=( const PAnimation& in_rhs );
		Hubris::HBOOL operator==( const PAnimation& in_rhs )const;
		Hubris::HBOOL operator!=( const PAnimation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		/*
			see PAnimationKey for IN_KEY contract
			though under contract to have at least one key
		*/
		template< typename IN_KEY >
		Hubris::HVOID DataAdd( 
			const Hubris::HString& in_name, 
			const Hubris::HContainerArray< Hubris::HContainerPair< Hubris::HREAL, IN_KEY > >& in_arrayKeys
			)
		{
			typedef PAnimationData< IN_KEY >TAnimationData;
			TAnimationData* pAnimationData = HNULL;
			HCOMMON_NEW_PARAM_2( pAnimationData, TAnimationData, in_name, in_arrayKeys );

			//WARNING transferal of ownership, kept inside component (given to implementation)
			PAnimationDataBasePointer pointer( pAnimationData );

			DataAdd( pointer );

			return;
		}

		const Hubris::HBOOL IsEmpty()const;
		Hubris::HVOID NameArrayGet( TArrayString& out_arrayName )const;
		Hubris::HVOID TimeKeyGet( const Hubris::HString& in_name, TArrayReal& out_arrayTime )const;
		Hubris::HVOID Clear();
		Hubris::HVOID DataRemove( const Hubris::HString& in_name );
		Hubris::HVOID DataRename( const Hubris::HString& in_oldName, const Hubris::HString& in_newName );

		///////////////////////////////////////////////////////
		// implement PAnimationInterface
	public:
		//return true it the animation has a time range, ie, expects to be used in absolute mode
		virtual const Hubris::HBOOL TimeAbsoluteTest()const{ return HTRUE; }

		virtual Hubris::HVOID TimeAbsoluteRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const;
		virtual Hubris::HVOID SubmitVisitorAbsolute( const Hubris::HREAL in_timeAbsolute, PInterfaceAnimationVisitor& out_visitor )const;

		virtual Hubris::HVOID SubmitVisitorDelta( const Hubris::HREAL HCOMMON_UNUSED_VAR( in_timeDelta ), PInterfaceAnimationVisitor& HCOMMON_UNUSED_VAR( out_visitor ) )const{ HCOMMON_ASSERT_ALWAYS( "invalid code path" ); }

		virtual Hubris::HVOID SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const;

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID DataAdd( PAnimationDataBasePointer& in_pAnimationDataBase );

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const PAnimationImplementation& ImplementationGet()const;
		PAnimationImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		PAnimationImplementation* m_pImplementation;

	};

	/**/	
};

#endif // _P_ANIMATION_H_