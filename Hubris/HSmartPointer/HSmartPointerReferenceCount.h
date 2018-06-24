//file: Hubris/HSmartPointer/HSmartPointerReferenceCount.h
#ifndef _H_SMART_POINTER_REFERENCE_COUNT_H_
#define _H_SMART_POINTER_REFERENCE_COUNT_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	/**/
	class HSmartPointerReferenceCount
	{
		//////////////////////////////////////////////////////
		// creation
	public:
		HSmartPointerReferenceCount();
		~HSmartPointerReferenceCount();

		//////////////////////////////////////////////////////
		// public methods
	public:
		HVOID Increment()const;
		HVOID Decrement()const;

		//return true if the reference count is zero
		HBOOL ZeroReferenceTest()const;

		//////////////////////////////////////////////////////
		// public accessors
	public:
		HS32 ReferenceCountGet()const { return m_referenceCount; }

		//////////////////////////////////////////////////////
		// disabled
	private:
		HSmartPointerReferenceCount( const HSmartPointerReferenceCount & in_src );
		const HSmartPointerReferenceCount& operator =( const HSmartPointerReferenceCount& in_src );

		//////////////////////////////////////////////////////
		// private members
	private:
		mutable HS32 m_referenceCount;

	};
};

#endif // _H_SMART_POINTER_REFERENCE_COUNT_H_