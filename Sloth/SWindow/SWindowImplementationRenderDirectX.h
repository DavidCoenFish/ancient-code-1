//file: Sloth/SWindow/SWindowImplementationRenderDirectX.h
#ifndef _S_WINDOW_IMPLEMENTATION_RENDER_DIRECT_X_H_
#define _S_WINDOW_IMPLEMENTATION_RENDER_DIRECT_X_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowImplementationRender.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowComponentImage;
	class SWindowImageInterface;
	class SWindowComponentPaintDx;
	struct SWindowParamDirectX;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SWindowImplementationRenderDirectX : public SWindowImplementationRender
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HWND;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImplementationRenderDirectX();
		virtual ~SWindowImplementationRenderDirectX();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImplementationRenderDirectX( const SWindowImplementationRenderDirectX& in_src );
		const SWindowImplementationRenderDirectX& operator=( const SWindowImplementationRenderDirectX& in_rhs );

		///////////////////////////////////////////////////////
		// implement SWindowImplementationBase
	private:
		virtual Hubris::HVOID OnClose(
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnCreate( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnPaint( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnSize( 
			HWND in_hWnd,
			const Hubris::HSINT in_width,
			const Hubris::HSINT in_height
			);
		virtual Hubris::HVOID OnDestroy(
			HWND in_hWnd 			
			);

		///////////////////////////////////////////////////////
		// implement SWindowImplementationRender
	public:
		virtual SInterfaceRender* const RenderInterfaceCreate();

		///////////////////////////////////////////////////////
		// public methods
	public:


		///////////////////////////////////////////////////////
		// private members
	private:


	};

	/**/
	
};

#endif // _S_WINDOW_IMPLEMENTATION_RENDER_DIRECT_X_H_