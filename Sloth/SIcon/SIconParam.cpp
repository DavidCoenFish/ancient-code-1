//file: Sloth/SIcon/SIconParam.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SIcon/SIconParam.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
SIconParam::SIconParam(
	const Pride::PImageRgba& in_imageLarge,
	const Pride::PImageRgba& in_imageSmall
	)
	: m_imageLarge( in_imageLarge )
	, m_imageSmall( in_imageSmall )

{
	return;
}

/**/
SIconParam::~SIconParam()
{
	return;
}

/**/
