//file: Hubris/HBufferParse/HBufferParseVariantTrait.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseVariantTrait.h"

#include "Hubris/HBufferParse/HBufferParseVariant.h"

#include "Hubris/HContainer/HContainer_Export.h"
#include "Hubris/HMatrix/HMatrix_Export.h"
#include "Hubris/HString/HString_Export.h"
#include "Hubris/HVariant/HVariant_Export.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
const HString Hubris::HTraitName< HBufferParseVariant >::NameGet()
{ 
	return( HTraitName< HBufferParseVariant::TVariantImplementation >::NameGet() ); 
}

/**/
