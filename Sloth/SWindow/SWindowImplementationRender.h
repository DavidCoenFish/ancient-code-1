//file: Sloth/SWindow/SWindowImplementationRender.h
#ifndef _S_WINDOW_IMPLEMENTATION_RENDER_H_
#define _S_WINDOW_IMPLEMENTATION_RENDER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowImplementationBase.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInterfaceRender;
	class SWindowComponentImage;
	class SInterfaceRender;
	struct SWindowParam;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SWindowImplementationRender : public SWindowImplementationBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImplementationRender();
		virtual ~SWindowImplementationRender();

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImplementationRender( const SWindowImplementationRender& in_src );
		const SWindowImplementationRender& operator=( const SWindowImplementationRender& in_rhs );

		///////////////////////////////////////////////////////
		// public interface
	public:
		virtual SInterfaceRender* const RenderInterfaceCreate()=0;

	};

	/**/
	
};

#endif // _S_WINDOW_IMPLEMENTATION_RENDER_H_