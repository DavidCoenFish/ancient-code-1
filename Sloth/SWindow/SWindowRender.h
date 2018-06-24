//file: Sloth/SWindow/SWindowRender.h
#ifndef _S_WINDOW_RENDER_H_
#define _S_WINDOW_RENDER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowBase.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowImplementationRender;
	class SInterfaceRender;
	struct SWindowParamDirectX;
	struct SWindowParamOpenGl;

	///////////////////////////////////////////////////////
	// class
	/*
		window object
			owns window resource
			creates class desc if needed
			//given callback object to inform close request?
			returns bool on update refecting close request status
	*/
	class SWindowRender : public SWindowBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowRender( 
			HINSTANCE in_hInstance,
			const SWindowParamDirectX& in_windowParam
			);
		SWindowRender( 
			HINSTANCE in_hInstance,
			const SWindowParamOpenGl& in_windowParam
			);
		~SWindowRender();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowRender( const SWindowRender& in_src );
		const SWindowRender& operator=( const SWindowRender& in_rhs );

		///////////////////////////////////////////////////////
		// implement SWindowBase
	private:
		//return false if window close has been requested
		virtual const Hubris::HBOOL OnUpdate();

		virtual Hubris::HVOID OnDebugTextDraw(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour = Pride::PColourVariablesRgb::WhiteGet(),
			const Pride::PColourRgb& in_backgroundColour = Pride::PColourVariablesRgb::BlackGet()
			);

		virtual Hubris::HVOID OnDebugTextClear();
		virtual Hubris::HVOID OnInputSet(
			SInput* const in_pInput
			);
		virtual const Hubris::HVectorS2& OnWindowClientSizeGet()const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return a reference to an image interface for the window.
		SInterfaceRender* const RenderInterfaceCreate();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SWindowImplementationRender& ImplementationGet()const;
		SWindowImplementationRender& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SWindowImplementationRender* m_pImplementation;

	};

	/**/
	
};

#endif // _S_WINDOW_RENDER_H_