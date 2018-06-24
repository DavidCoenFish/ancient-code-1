//file: Sloth/SMaterial/SMaterialStageShaderData.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SMaterial/SMaterialStageShaderData.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Sloth;

//collect values into a memento object
Hubris::HVOID Envy::EMementoTraitCollect< SMaterialStageShaderDataVariant >( EMementoCollect& in_out_mementoCollect, const SMaterialStageShaderDataVariant& in_data )
{
	EMementoTraitCollect( in_out_mementoCollect, ( const SMaterialStageShaderDataVariant::TVariantImplementation& )( in_data ) );
	return;
}
Hubris::HVOID Envy::EMementoTraitAssign< SMaterialStageShaderDataVariant >( const EMementoAssign& in_out_mementoAssign, SMaterialStageShaderDataVariant& out_data )
{
	EMementoTraitAssign( in_out_mementoAssign, ( SMaterialStageShaderDataVariant::TVariantImplementation& )( out_data ) );
	return;
}

/**/