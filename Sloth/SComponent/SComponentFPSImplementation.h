//file: Sloth/SComponent/SComponentFPSImplementation.h
#ifndef _S_COMPONENT_FPS_IMPLEMENTATION_H_
#define _S_COMPONENT_FPS_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentFPSImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentFPSImplementation( 
			const Hubris::HSINT in_sampleLoopLength
			);
		~SComponentFPSImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SComponentFPSImplementation( const SComponentFPSImplementation& in_src );
		const SComponentFPSImplementation& operator=( const SComponentFPSImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Reset();
		//let the component know that a new frame has started
		Hubris::HVOID NotifyNewFrame( const Hubris::HREAL in_delta );
		const Hubris::HREAL FPSGet()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayReal m_arrayDelta;
		Hubris::HREAL m_averageDelta;
		const Hubris::HSINT m_arrayLoopLength;
		Hubris::HSINT m_loopInsertTrace;

	};

	/**/
	
};

#endif // _S_COMPONENT_FPS_IMPLEMENTATION_H_