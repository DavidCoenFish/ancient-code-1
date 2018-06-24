//file: Sloth/SWindow/SWindowRender.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowRender.h"

#include "Sloth/SWindow/SWindowImplementationRenderDirectX.h"
#include "Sloth/SWindow/SWindowImplementationRenderOpenGl.h"
#include "Sloth/SWindow/SWindowParamDirectX.h"
#include "Sloth/SWindow/SWindowParamOpenGl.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowRender::SWindowRender( 
	HINSTANCE in_hInstance,
	const SWindowParamDirectX& in_windowParam
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW(
		m_pImplementation,
		SWindowImplementationRenderDirectX
		);

	ImplementationGet().Initialise(
		in_hInstance,
		in_windowParam
		);

	return;
}

/**/
SWindowRender::SWindowRender( 
	HINSTANCE in_hInstance,
	const SWindowParamOpenGl& in_windowParam
	)
: m_pImplementation( HNULL )
{
	HCOMMON_NEW(
		m_pImplementation,
		SWindowImplementationRenderOpenGl
		);

	ImplementationGet().Initialise(
		in_hInstance,
		in_windowParam
		);

	return;
}

/**/
SWindowRender::~SWindowRender()
{
	ImplementationGet().Release();

	HCOMMON_DELETE(
		m_pImplementation,
		SWindowImplementationRender
		);

	return;
}

///////////////////////////////////////////////////////
// implement SWindowBase
/**/
const Hubris::HBOOL SWindowRender::OnUpdate()
{
	return( ImplementationGet().Update() );
}

/**/
Hubris::HVOID SWindowRender::OnDebugTextDraw(
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour
	)
{
	ImplementationGet().DebugTextDraw(
		in_text,
		in_location,
		in_foregroundColour,
		in_backgroundColour
		);
	return;
}

/**/
Hubris::HVOID SWindowRender::OnDebugTextClear()
{
	ImplementationGet().DebugTextClear();
	return;
}

/**/
Hubris::HVOID SWindowRender::OnInputSet(
	SInput* const in_pInput
	)
{
	ImplementationGet().InputSet(
		in_pInput
		);
	return;
}

/**/
const Hubris::HVectorS2& SWindowRender::OnWindowClientSizeGet()const
{
	return ImplementationGet().WindowClientSizeGet();
}

///////////////////////////////////////////////////////
// public methods
/**/
SInterfaceRender* const SWindowRender::RenderInterfaceCreate()
{
	return( ImplementationGet().RenderInterfaceCreate() );	
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SWindowImplementationRender& SWindowRender::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
SWindowImplementationRender& SWindowRender::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
