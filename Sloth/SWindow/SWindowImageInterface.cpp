//file: Sloth/SWindow/SWindowImageInterface.cpp
#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SWindow/SWindowImageInterface.h"

#include "Sloth/SWindow/SWindowImplementationImage.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

////////////////////////////////////////////////////////////////
// local static methods
/**/
///////////////////////////////////////////////////////
// creation
/**/
SWindowImageInterface::SWindowImageInterface(
	SWindowImplementationImage& in_windowImplemetation
	)
: m_windowImplemetation( in_windowImplemetation )
{
	return;
}

/**/
SWindowImageInterface::~SWindowImageInterface()
{
	return;
}

///////////////////////////////////////////////////////
// interface
/**/
const Hubris::HVectorS2 SWindowImageInterface::SizeGet()const
{
	return m_windowImplemetation.SizeGet();
}

/**/
HVOID SWindowImageInterface::DeleteThis()
{
	m_windowImplemetation.InvalidateRegion();

	HCOMMON_DELETE_THIS( this, SWindowImageInterface );
	return;
}

/**/
HVOID SWindowImageInterface::PixelSet(
	const Hubris::HVectorS2& in_pos,
	const Pride::PColourRgba& in_colour
	)
{
	m_windowImplemetation.PixelSet( in_pos, in_colour );

	return;
}

/**/
HVOID SWindowImageInterface::ImageSet(
	const Pride::PImageRgba& in_image
	)
{
	m_windowImplemetation.ImageSet( in_image );

	return;
}

/**/
HVOID SWindowImageInterface::PixelWipe(
	const Pride::PColourRgba& in_colour
	)
{
	m_windowImplemetation.PixelWipe( in_colour );

	return;
}

/**/

