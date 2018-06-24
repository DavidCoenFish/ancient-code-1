//file: Hubris/HSmartPointer/HSmartPointerObjectBase.h
#ifndef _H_SMART_POINTER_OBJECT_BASE_H_
#define _H_SMART_POINTER_OBJECT_BASE_H_

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HSmartPointer/HSmartPointerReferenceCount.h"

namespace Hubris
{
	template< typename IN_TYPE >class HSmartPointer;

	template< typename IN_TYPE >class HSmartPointerObjectBase
	{
		friend HSmartPointer< IN_TYPE >;

		///////////////////////////////////////////////////
		// creation
	public:
		HSmartPointerObjectBase( const HSmartPointerObjectBase& in_src )
		: m_referenceCount()
		{
			( *this ) = in_src;
			return;
		}
		HSmartPointerObjectBase()
		: m_referenceCount()
		{
			return;
		}

		///////////////////////////////////////////////////
		// operators
	public:
		const HSmartPointerObjectBase& operator =( const HSmartPointerObjectBase& )
		{
			//NOP, assignment doesn't modify smart pointer reference count, only HSmartPointer modifies count
			return( *this );
		}
		const Hubris::HBOOL operator ==( const HSmartPointerObjectBase& HCOMMON_UNUSED_VAR( in_rhs ) )const
		{
			return HTRUE;
		}
		const Hubris::HBOOL operator !=( const HSmartPointerObjectBase& HCOMMON_UNUSED_VAR( in_rhs ) )const
		{
			return HFALSE;
		}

		///////////////////////////////////////////////////
		// public accessors
	public:
		const HSmartPointerReferenceCount& RefereceCountGet()const{ return m_referenceCount; }
		HSmartPointerReferenceCount& RefereceCountGet(){ return m_referenceCount; }

		///////////////////////////////////////////////////
		// private memebers
	private:
		HSmartPointerReferenceCount m_referenceCount;

	};
	/**/
};

#endif // _H_SMART_POINTER_OBJECT_BASE_H_