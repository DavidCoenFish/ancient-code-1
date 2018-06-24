//file: Sloth/SWindow/SWindowBase.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowBase.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SWindowBase::SWindowBase()
{
	return;
}

/**/
SWindowBase::~SWindowBase()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL SWindowBase::Update()
{
	const Hubris::HBOOL success = OnUpdate();
	return success;
}

/**/
Hubris::HVOID SWindowBase::DebugTextDraw(
	const Hubris::HString& in_text,
	const Hubris::HVectorS2& in_location,
	const Pride::PColourRgb& in_foregroundColour,
	const Pride::PColourRgb& in_backgroundColour
	)
{
	OnDebugTextDraw(
		in_text,
		in_location,
		in_foregroundColour,
		in_backgroundColour
		);
	return;
}

/**/
Hubris::HVOID SWindowBase::DebugTextClear()
{
	OnDebugTextClear();
	return;
}

/**/
Hubris::HVOID SWindowBase::InputSet(
	SInput* const in_pInput
	)
{
	OnInputSet(
		in_pInput
		);
	return;
}

/**/
const Hubris::HVectorS2& SWindowBase::WindowClientSizeGet()const
{
	return OnWindowClientSizeGet();
}

/**/