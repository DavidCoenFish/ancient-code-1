//file: Sloth/SComponent/SComponentFPS.h
#ifndef _S_COMPONENT_FPS_H_
#define _S_COMPONENT_FPS_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SComponentFPSImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentFPS
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentFPS( 
			const Hubris::HSINT in_sampleLoopLength = 64
			);
		~SComponentFPS();

		///////////////////////////////////////////////////////
		// disabled
	private:
		SComponentFPS( const SComponentFPS& in_src );
		const SComponentFPS& operator=( const SComponentFPS& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Reset();
		//let the component know that a new frame has started
		Hubris::HVOID NotifyNewFrame( const Hubris::HREAL in_delta );
		const Hubris::HREAL FPSGet()const;

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SComponentFPSImplementation& ImplementationGet()const;
		SComponentFPSImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SComponentFPSImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_COMPONENT_FPS_H_