//file: Sloth/SComponent/SComponentDeltaImplementation.h
#ifndef _S_COMPONENT_DELTA_IMPLEMENTATION_H_
#define _S_COMPONENT_DELTA_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentDeltaImplementation
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentDeltaImplementation();
		~SComponentDeltaImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SComponentDeltaImplementation( const SComponentDeltaImplementation& in_src );
		const SComponentDeltaImplementation& operator=( const SComponentDeltaImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Reset();
		Hubris::HVOID StartNewFrame();
		const Hubris::HREAL LastDeltaGet()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_lastTick;
		Hubris::HREAL m_lastDelta;

	};

	/**/
	
};

#endif // _S_COMPONENT_DELTA_IMPLEMENTATION_H_