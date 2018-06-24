//file: Sloth/SWindow/SWindowParam.h
#ifndef _S_WINDOW_PARAM_H_
#define _S_WINDOW_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SCursor;
	class SIcon;
	class SInput;
	class SMenu;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SWindowParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		//typedef unsigned long DWORD;
		typedef Hubris::HVOID* HWND;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowParam(
			const Hubris::HString& in_className = "SWindowDefault",
			const Hubris::HString& in_windowTitle = "default title",
			const Hubris::HBOOL in_showWindow = HTRUE,
			const Hubris::HU32 in_classStyle = ClassStyleDefaultGet(),
			const Hubris::HU32 in_windowStyle = WindowStyleDefaultGet(),
			const Hubris::HVectorS2& in_windowOrigin = Hubris::HMatrixConstructor::HVectorS2Construct( 100, 100 ),
			const Hubris::HVectorS2& in_windowDimention = Hubris::HMatrixConstructor::HVectorS2Construct( 320, 240 ),
			//SInput* const in_pInput = HNULL,
			SCursor* const in_pCursor = HNULL,
			SIcon* const in_pIcon = HNULL,
			SMenu* const in_pMenu = HNULL,
			const HWND in_parentHWnd = HNULL
			);
		~SWindowParam();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowParam( const SWindowParam& in_src );
		const SWindowParam& operator=( const SWindowParam& in_rhs );

		///////////////////////////////////////////////////////
		// public static accessors
	public:
		static const Hubris::HU32 ClassStyleDefaultGet();
		static const Hubris::HU32 WindowStyleDefaultGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& ClassNameGet()const{ return m_className; }
		Hubris::HVOID ClassNameSet( const Hubris::HString& in_className ){ m_className = in_className; return; }

		const Hubris::HString& WindowTitleGet()const{ return m_windowTitle; }
		Hubris::HVOID WindowTitleSet( const Hubris::HString& in_windowTitle ){ m_windowTitle = in_windowTitle; return; }

		const Hubris::HBOOL ShowWindowGet()const{ return m_showWindow; }
		Hubris::HVOID ShowWindowSet( const Hubris::HBOOL in_showWindow ){ m_showWindow = in_showWindow; return; }

		const Hubris::HVectorS2& WindowOriginGet()const{ return m_windowOrigin; }
		Hubris::HVOID WindowOriginSet( const Hubris::HVectorS2& in_windowOrigin ){ m_windowOrigin = in_windowOrigin; return; }

		const Hubris::HVectorS2& WindowDimentionGet()const{ return m_windowDimention; }
		Hubris::HVOID WindowDimentionSet( const Hubris::HVectorS2& in_windowDimention ){ m_windowDimention = in_windowDimention; return; }

		//SInput* const InputGet()const{ return m_pInput; }
		//Hubris::HVOID InputSet( SInput* const in_pInput ){ m_pInput = in_pInput; return; }

		SCursor* const CursorGet()const{ return m_pCursor; }
		Hubris::HVOID CursorSet( SCursor* const in_pCursor ){ m_pCursor = in_pCursor; return; }

		SIcon* const IconGet()const{ return m_pIcon; }
		Hubris::HVOID IconSet( SIcon* const in_pIcon ){ m_pIcon = in_pIcon; return; }

		SMenu* const MenuGet()const{ return m_pMenu; }
		Hubris::HVOID MenuSet( SMenu* const in_pMenu ){ m_pMenu = in_pMenu; return; }

		const Hubris::HU32 ClassStyleGet()const{ return m_classStyle; }
		const Hubris::HU32 WindowStyleGet()const{ return m_windowStyle; }

		const HWND ParentGet()const{ return m_parentHWnd; }
		Hubris::HVOID ParentSet( const HWND in_parentHWnd ){ m_parentHWnd = in_parentHWnd; return; }

		//const Hubris::HBOOL DebugTextFPSGet()const{ return m_debugTextFPS; }
		//Hubris::HVOID DebugTextFPSSet( const Hubris::HBOOL in_debugTextFPS ){ m_debugTextFPS = in_debugTextFPS; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_className;
		Hubris::HString m_windowTitle;
		Hubris::HBOOL m_showWindow;
		Hubris::HU32 m_classStyle;
		Hubris::HU32 m_windowStyle;
		Hubris::HVectorS2 m_windowOrigin;
		Hubris::HVectorS2 m_windowDimention;
		//NO OWNERSHIP
		//SInput* m_pInput;
		SCursor* m_pCursor;
		SIcon* m_pIcon;
		SMenu* m_pMenu;

		HWND m_parentHWnd;

	};

	/**/
	
};

#endif // _S_WINDOW_PARAM_H_