//file: Sloth/SWindow/SWindowImplementationBase.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImplementationBase.h"

#include "Sloth/SWindow/SWindowParam.h"
#include "Sloth/SWindow/SWindowComponentDebugText.h"

#include "Sloth/SCursor/SCursor_Export.h"
#include "Sloth/SIcon/SIcon_Export.h"
#include "Sloth/SInput/SInput_Export.h"

#include <WINDOWS.H>

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
typedef LRESULT (CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

///////////////////////////////////////////////////////
// local static methods
/**/
static SWindowImplementationBase* const LocalWindowUserDataGet( HWND in_hWnd )
{
	return( ( SWindowImplementationBase* )LongToPtr( GetWindowLongPtr( in_hWnd, GWLP_USERDATA ) ) );
}

/**/
static Hubris::HVOID LocalWindowUserDataSet(
	HWND in_hWnd,
    LPARAM in_lParam
	)
{
	LPCREATESTRUCT lpCreateStruct = ( LPCREATESTRUCT )in_lParam;
	SWindowImplementationBase* pWindow = ( SWindowImplementationBase* )lpCreateStruct->lpCreateParams;
	SetWindowLongPtr( in_hWnd, GWLP_USERDATA, PtrToLong( pWindow ) );
	return;
}

/**/
static HMENU LocalDealWindowMenu( 
	const SWindowParam&	in_windowParam
	)
{
	HMENU menu = HNULL;
	//SMenu* pMenu = in_windowParam.MenuGet();
	//if( HNULL != pMenu )
	//{
	//	menu = pMenu->
	//}
	in_windowParam;
	return menu;
}


/**/
static const HBOOL LocalWindowClassCreatedTest(
	HINSTANCE in_hInstance,
	const SWindowParam& in_windowParam
	)
{
	WNDCLASSEX classDummy;
	if( 0 != GetClassInfoEx( 
		in_hInstance, 
		in_windowParam.ClassNameGet().RawGet(),
		&classDummy 
		) )
	{
		return HTRUE;
	}

	return HFALSE;
}

/**/
Hubris::HVOID LocalWindowClassCreate(
	HINSTANCE in_hInstance,
	const SWindowParam&	in_windowParam,
	WNDPROC in_windowProc
	)
{
	//is class already registered
	if( HTRUE == LocalWindowClassCreatedTest( 
		in_hInstance,
		in_windowParam
		) )
	{
		return;
	}

	WNDCLASSEX windowClass; 
	SecureZeroMemory( &windowClass, sizeof( windowClass ) );

	HCURSOR hCursor = HNULL;
	if( HNULL != in_windowParam.CursorGet() )
	{
		hCursor = ::HCURSOR( in_windowParam.CursorGet()->CursorGet() );
	}

	HICON hIcon = HNULL;
	HICON hIconSmall = HNULL;
	if( HNULL != in_windowParam.IconGet() )
	{
		hIcon = ::HICON( in_windowParam.IconGet()->IconLargeGet() );
		hIconSmall = ::HICON( in_windowParam.IconGet()->IconSmallGet() );
	}

	windowClass.cbSize = sizeof( windowClass );
	windowClass.style = in_windowParam.ClassStyleGet();
	windowClass.lpfnWndProc = in_windowProc;
		//LocalWindowProc;
	windowClass.cbClsExtra = 0;
	windowClass.cbWndExtra = sizeof( LONG_PTR );
	windowClass.hInstance = in_hInstance;
	windowClass.hIcon = hIcon;
	windowClass.hCursor = hCursor;
	windowClass.hbrBackground = ( HBRUSH )GetStockObject( NULL_BRUSH );
	windowClass.lpszMenuName =  NULL;
	windowClass.lpszClassName = in_windowParam.ClassNameGet().RawGet();
	windowClass.hIconSm = hIconSmall;
	
	// Register the window class. 
	RegisterClassEx( &windowClass ); 

	return;
}

/**/
static const RECT LocalWindowSizeCalculate( 
	const SWindowParam&	in_windowParam,
	const DWORD in_windowStyle
	)
{
	RECT size;
	BOOL result = 0;

	const HVectorS2 windowOrigin = in_windowParam.WindowOriginGet();
	const HVectorS2 windowDimention = in_windowParam.WindowDimentionGet();
	size.left = windowOrigin[ 0 ];
	size.top = windowOrigin[ 1 ];
	size.right = windowOrigin[ 0 ] + windowDimention[ 0 ];
	size.bottom = windowOrigin[ 1 ] + windowDimention[ 1 ];

	const BOOL menu = ( HNULL != in_windowParam.MenuGet() );
	result = AdjustWindowRectEx( &size, in_windowStyle, menu, 0 );

	return size;
}

/**/
static HWND LocalWindowCreate(
	HINSTANCE in_hInstance,
	const SWindowParam& in_windowParam,
	SWindowImplementationBase& in_window,
	WNDPROC in_windowProc
	)
{
	LocalWindowClassCreate(
		in_hInstance,
		in_windowParam,
		in_windowProc
		);

	const RECT size = LocalWindowSizeCalculate( 
		in_windowParam,
		in_windowParam.WindowStyleGet()
		);

	HMENU menu = LocalDealWindowMenu( in_windowParam );

	return CreateWindow( 
		in_windowParam.ClassNameGet().RawGet(),
		in_windowParam.WindowTitleGet().RawGet(),
		in_windowParam.WindowStyleGet(),
		size.left,
		size.top,
		size.right - size.left,
		size.bottom - size.top,
		( ::HWND ) in_windowParam.ParentGet(),
		menu,
		( ::HINSTANCE )in_hInstance,
		( LPVOID )&in_window
	);
}


///////////////////////////////////////////////////////
// creation
/**/
SWindowImplementationBase::SWindowImplementationBase()
: m_hWnd( HNULL )
, m_continue( HTRUE )
, m_focus( HTRUE )
, m_windowClientSize( HNULL )
, m_pComponentDebugText( HNULL )
, m_pInput( HNULL )
{
	HCOMMON_NEW(
		m_pComponentDebugText,
		SWindowComponentDebugText
		);
	return;
}

/**/
SWindowImplementationBase::~SWindowImplementationBase()
{
	HCOMMON_DELETE(
		m_pComponentDebugText,
		SWindowComponentDebugText
		);
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
Hubris::HVOID SWindowImplementationBase::Initialise(
	HINSTANCE in_hInstance,
	const SWindowParam& in_windowParam	
	)
{
	m_hWnd = LocalWindowCreate(
		( ::HINSTANCE )in_hInstance,
		in_windowParam,
		*this,
		( WNDPROC )WindowProc
		);

	if( HTRUE == in_windowParam.ShowWindowGet() )
	{
		ShowWindow( ::HWND( m_hWnd ), SW_SHOW );
	}

	return;
}

Hubris::HVOID SWindowImplementationBase::Release()
{
	if( HNULL != m_hWnd )
	{
		DestroyWindow( ::HWND( m_hWnd ) );
		m_hWnd = HNULL;
	}

	return;
}

/**/
const Hubris::HBOOL SWindowImplementationBase::Update()
{
	if( HNULL != m_pInput )
	{
		m_pInput->UpdatePreProcessMessages();
	}

    MSG message;
	SecureZeroMemory( &message, sizeof( message ) );

	if( HFALSE == m_focus )
	{
		Sleep( 100 );
	}
	//InvalidateRegion();
	//generate a paint message if update region not empty
	//UpdateWindow( ::HWND( m_hWnd ) );

	//GetMessage returns the WM_PAINT message when there are no other messages in the application's message queue
	BOOL result;
	//while( ( result = GetMessage( &message, ::HWND( m_hWnd ), 0, 0 ) ) != 0 )
	while( ( result = PeekMessage( &message, ::HWND( m_hWnd ), 0, 0, PM_REMOVE ) ) != 0 )
	{
        if( result == -1 )
        {
           // handle the error and possibly exit
			m_continue = HFALSE; 
        }

        TranslateMessage( &message ); 
        DispatchMessage( &message ); 

		if( WM_PAINT == message.message )
		{
			break;
		}
	};

	return m_continue;
}


/**/
HVOID SWindowImplementationBase::InvalidateRegion()
{
	InvalidateRect(
		::HWND( m_hWnd ),
		HNULL,
		FALSE
	);

	return;
}

/**/
Hubris::HVOID SWindowImplementationBase::InputSet(
	SInput* const in_pInput
	)
{
	m_pInput = in_pInput;
	return;
}

/**/
Hubris::HVOID SWindowImplementationBase::DebugTextDraw(
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour
	)
{
	ComponentDebugTextGet().TextAdd(
		in_text,
		in_location,
		in_foregroundColour,
		in_backgroundColour
		);

	return;
}

/**/
Hubris::HVOID SWindowImplementationBase::DebugTextClear()
{
	ComponentDebugTextGet().TextClear();

	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HU32 __stdcall SWindowImplementationBase::WindowProc(
	HWND in_hWnd,
	Hubris::HU32 in_uMessage,
	Hubris::HU32 in_wParam,
	Hubris::HU32 in_lParam
	)
{
    switch( in_uMessage ) 
    { 
	default: 
		{
			break;
		}
	case WM_ACTIVATE:
		{	
			Activate( in_hWnd, in_wParam );
			break;
		}
	case WM_CLOSE:
		{
			Close( in_hWnd ); 
			return 0; 
		}
	case WM_CREATE: 
		{
			LocalWindowUserDataSet( ( ::HWND )in_hWnd, in_lParam );
			Create( in_hWnd ); 
			return 0; 
		}
	case WM_PAINT: 
		{
			Paint( in_hWnd ); 
			return 0; 
		}
	case WM_ERASEBKGND:
		{
			//NOP
			return 1;
		}
	case WM_SIZE: 
		{
			Size( 
				in_hWnd,
				LOWORD( in_lParam ), 
				HIWORD( in_lParam )
				); 
			return 0; 
		}
	case WM_DESTROY: 
		{
			Destroy( in_hWnd ); 
			return 0; 
		}
    } 

	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		if( HNULL != pWindow->m_pInput )
		{
			pWindow->m_pInput->ProcessMessages(
				in_hWnd,
				in_uMessage,
				in_wParam,
				in_lParam			
				);
		}
	}

	return( DefWindowProc( ( ::HWND )in_hWnd, in_uMessage, in_wParam, in_lParam ) );
}

/**/
Hubris::HVOID SWindowImplementationBase::Activate(
	HWND in_hWnd,
	Hubris::HU32 in_wParam
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		switch( LOWORD( in_wParam ) )
		{
		default:
			{
				break;
			}
		case WA_ACTIVE:
		case WA_CLICKACTIVE:
			{
				pWindow->m_focus = HTRUE;
				break;
			}
		case WA_INACTIVE:
			{
				pWindow->m_focus = HFALSE;
				break;
			}
		}
	}
	return;
}

/**/
Hubris::HVOID SWindowImplementationBase::Close(
	HWND in_hWnd 	
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		pWindow->m_continue = HFALSE;
		pWindow->OnClose( 
			in_hWnd 
			);
	}

	return;
}
/**/
Hubris::HVOID SWindowImplementationBase::Create( 
	HWND in_hWnd 
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		pWindow->OnCreate( 
			in_hWnd 
			);
	}

	return;
}
/**/
Hubris::HVOID SWindowImplementationBase::Paint( 
	HWND in_hWnd 
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		pWindow->OnPaint( 
			in_hWnd 
			);
		pWindow->ComponentDebugTextGet().TextDraw( in_hWnd );
	}

	return;
}
/**/
Hubris::HVOID SWindowImplementationBase::Size( 
	HWND in_hWnd,
	const Hubris::HSINT in_width,
	const Hubris::HSINT in_height
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		pWindow->m_windowClientSize[ 0 ] = in_width;
		pWindow->m_windowClientSize[ 1 ] = in_height;
		pWindow->OnSize( 
			in_hWnd,
			in_width,
			in_height
			);
	}

	return;
}
/**/
Hubris::HVOID SWindowImplementationBase::Destroy(
	HWND in_hWnd 			
	)
{
	SWindowImplementationBase* pWindow = LocalWindowUserDataGet( ( ::HWND )in_hWnd );
	if( HNULL != pWindow )
	{
		pWindow->OnDestroy( 
			in_hWnd 
			);
	}

	return;
}

///////////////////////////////////////////////////////
// private members
/**/
const SWindowComponentDebugText& SWindowImplementationBase::ComponentDebugTextGet()const
{
	HCOMMON_ASSERT( HNULL != m_pComponentDebugText, "invalid memeber" );
	return( *m_pComponentDebugText );
}

/**/
SWindowComponentDebugText& SWindowImplementationBase::ComponentDebugTextGet()
{
	HCOMMON_ASSERT( HNULL != m_pComponentDebugText, "invalid memeber" );
	return( *m_pComponentDebugText );
}

/**/