//file: Sloth/SWindow/SWindowImplementationBase.h
#ifndef _S_WINDOW_IMPLEMENTATION_BASE_H_
#define _S_WINDOW_IMPLEMENTATION_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;
	class SWindowComponentImage;
	class SWindowImageInterface;
	class SWindowComponentPaintDx;
	struct SWindowParam;
	class SInterfaceImage;
	class SWindowComponentDebugText;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SWindowImplementationBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HWND;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImplementationBase();
		~SWindowImplementationBase();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImplementationBase( const SWindowImplementationBase& in_src );
		const SWindowImplementationBase& operator=( const SWindowImplementationBase& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Initialise(
			HINSTANCE in_hInstance,
			const SWindowParam& in_windowParam			
			);
		Hubris::HVOID Release();

		//return false if window close has been requested
		const Hubris::HBOOL Update();
		Hubris::HVOID InvalidateRegion();

		Hubris::HVOID InputSet(
			SInput* const in_pInput
			);

		Hubris::HVOID DebugTextDraw(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour,
			const Pride::PColourRgb& in_backgroundColour
			);

		Hubris::HVOID DebugTextClear();

		///////////////////////////////////////////////////////
		// private methods
	private:
		Hubris::HVOID WindowClassCreate(
			HINSTANCE in_hInstance,
			const SWindowParam&	in_windowParam
			);

		static Hubris::HU32 __stdcall WindowProc(
			HWND in_hWnd,
			Hubris::HU32 in_uMessage,
			Hubris::HU32 in_wParam,
			Hubris::HU32 in_lParam
			);

		static Hubris::HVOID Activate(
			HWND in_hWnd,
			Hubris::HU32 in_wParam
			);

		static Hubris::HVOID Close(
			HWND in_hWnd 
			);
		static Hubris::HVOID Create( 
			HWND in_hWnd 
			);
		static Hubris::HVOID Paint( 
			HWND in_hWnd 
			);
		static Hubris::HVOID Size( 
			HWND in_hWnd,
			const Hubris::HSINT in_width,
			const Hubris::HSINT in_height
			);
		static Hubris::HVOID Destroy(
			HWND in_hWnd 			
			);

		///////////////////////////////////////////////////////
		// protected
	protected:
		HWND HWndGet(){ return m_hWnd; }

		///////////////////////////////////////////////////////
		// private interface
	private:
		virtual Hubris::HVOID OnClose(
			HWND in_hWnd 
			)=0;
		virtual Hubris::HVOID OnCreate( 
			HWND in_hWnd 
			)=0;
		virtual Hubris::HVOID OnPaint( 
			HWND in_hWnd 
			)=0;
		virtual Hubris::HVOID OnSize( 
			HWND in_hWnd,
			const Hubris::HSINT in_width,
			const Hubris::HSINT in_height
			)=0;
		virtual Hubris::HVOID OnDestroy(
			HWND in_hWnd 			
			)=0;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorS2& WindowClientSizeGet()const{ return m_windowClientSize; }

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SWindowComponentDebugText& ComponentDebugTextGet()const;
		SWindowComponentDebugText& ComponentDebugTextGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		//false if window close has been requested
		Hubris::HBOOL m_continue;
		Hubris::HBOOL m_focus;
		HWND m_hWnd;

		Hubris::HVectorS2 m_windowClientSize;

		SWindowComponentDebugText* m_pComponentDebugText;

		//NO OWNERSHIP
		SInput* m_pInput;

	};

	/**/
	
};

#endif // _S_WINDOW_IMPLEMENTATION_BASE_H_