//file: Sloth/SComponent/SComponentDelta.h
#ifndef _S_COMPONENT_DELTA_H_
#define _S_COMPONENT_DELTA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SComponentDeltaImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentDelta
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentDelta();
		~SComponentDelta();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentDelta( const SComponentDelta& in_src );
		const SComponentDelta& operator=( const SComponentDelta& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//reset is like start new frome, but with a zero delta to last frame
		Hubris::HVOID Reset();
		Hubris::HVOID StartNewFrame();
		//get the time delta (0
		const Hubris::HREAL LastDeltaGet()const;

		//
		//const Hubris::HREAL DeltaReducedPowerGet0_95()const?
		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SComponentDeltaImplementation& ImplementationGet()const;
		SComponentDeltaImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentDeltaImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_DELTA_H_