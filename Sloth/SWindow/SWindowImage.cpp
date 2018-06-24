//file: Sloth/SWindow/SWindowImage.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImage.h"

#include "Sloth/SWindow/SWindowImplementationImage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowImage::SWindowImage( 
	HINSTANCE in_hInstance,
	const SWindowParam& in_windowParam
	)
{
	HCOMMON_NEW(
		m_pImplementation, 
		SWindowImplementationImage
		);

	ImplementationGet().Initialise(
		in_hInstance,
		in_windowParam
		);

	return;
}

/**/
SWindowImage::~SWindowImage()
{
	ImplementationGet().Release();

	HCOMMON_DELETE( 
		m_pImplementation, 
		SWindowImplementationImage 
		);
	return;
}


///////////////////////////////////////////////////////
// implement SWindowBase
/**/
const Hubris::HBOOL SWindowImage::OnUpdate()
{
	return( ImplementationGet().Update() );
}

Hubris::HVOID SWindowImage::OnInputSet(
	SInput* const in_pInput
	)
{
	ImplementationGet().InputSet(
		in_pInput
		);
	return;
}

/**/
Hubris::HVOID SWindowImage::OnDebugTextDraw(
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
Hubris::HVOID SWindowImage::OnDebugTextClear()
{
	ImplementationGet().DebugTextClear();
	return;
}

/**/
const Hubris::HVectorS2& SWindowImage::OnWindowClientSizeGet()const
{
	return ImplementationGet().WindowClientSizeGet();
}

///////////////////////////////////////////////////////
// public methods
/**/
SInterfaceImage* const SWindowImage::ImageInterfaceCreate()
{
	return ImplementationGet().ImageInterfaceCreate();
}

///////////////////////////////////////////////////////
// private accessors
/**/
const SWindowImplementationImage& SWindowImage::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
SWindowImplementationImage& SWindowImage::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
