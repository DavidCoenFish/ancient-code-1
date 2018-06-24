//file: Pride/PAnimation/PAnimationKey.h
#ifndef _P_ANIMATION_KEY_H_
#define _P_ANIMATION_KEY_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PInterface/PInterfaceAnimationVisitor.h"

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;
};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PInterfaceAnimationVisitorKeys;

	///////////////////////////////////////////////////////
	// class
	/*
		sample linear animation key implementation, can be used by PAnimation
		required to satify contract with 
			PAnimationData( Evalue ) 
			HContainerArray( copy, assignment operator )
		other keys classes satisfying this contract can be used by animation system
	*/
	template< typename IN_TYPE >class PAnimationKey
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PAnimationKey >TArrayKey;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		PAnimationKey( const PAnimationKey& in_src );
		PAnimationKey( const IN_TYPE& in_data = IN_TYPE() );
		~PAnimationKey();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PAnimationKey& operator=( const PAnimationKey& in_rhs );
		const Hubris::HBOOL operator==( const PAnimationKey& in_rhs )const;
		const Hubris::HBOOL operator!=( const PAnimationKey& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods, interface obliged by PAnimationData
	public:
		static Hubris::HVOID Evalue( 
			PInterfaceAnimationVisitor& out_visitor, 
			const Hubris::HString& in_targetName, 
			const PAnimationKey& in_key 
			);

		/*
			under contract for range of in_arrayIndex to be inclusive[ 0 ... ( in_arrayKey.SizeGet() - 2 ) ]
			with in_arrayKey.SizeGet() == in_arrayTime.SizeGet()
		*/
		static Hubris::HVOID Evalue( 
			PInterfaceAnimationVisitor& out_visitor, 
			const Hubris::HString& in_targetName, 
			const TArrayKey& in_arrayKey,
			const TArrayReal& in_arrayTime,
			const Hubris::HSINT in_arrayIndex,
			const Hubris::HREAL in_timeSample 
			);

		static Hubris::HVOID EvalueKey( 
			PInterfaceAnimationVisitorKeys& out_visitorKeys, 
			const Hubris::HString& in_targetName,
			const PAnimationKey& in_key,
			const Hubris::HREAL in_time
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		IN_TYPE m_data;

	};

	/**/
};

#endif // _P_ANIMATION_KEY_H_