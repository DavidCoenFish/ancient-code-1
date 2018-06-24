//file: Vanity/VComponentGame/VComponentGameVariant.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGameVariant.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;
using namespace Envy;

//HTYPE_EMPTY_IMPLEMENTATION_CONSTRUCTOR( ETanyaVariant );
//const IN_CLASS& Hubris::HTraitEmpty< IN_CLASS >::EmptyGet() { static const IN_CLASS s_default; return s_default; } 	\
//IN_CLASS* Hubris::HTraitEmpty< IN_CLASS* >::EmptyGet() { return HNULL; } 

//variant
//collect values into a memento object
Hubris::HVOID Envy::EMementoTraitCollect< VComponentGameVariant >( EMementoCollect& in_out_mementoCollect, const VComponentGameVariant& in_data )
{
	EMementoTraitCollect( in_out_mementoCollect, ( const VComponentGameVariant::TVariantImplementation& )( in_data ) );
	return;
}
Hubris::HVOID Envy::EMementoTraitAssign< VComponentGameVariant >( const EMementoAssign& in_out_mementoAssign, VComponentGameVariant& out_data )
{
	EMementoTraitAssign( in_out_mementoAssign, ( VComponentGameVariant::TVariantImplementation& )( out_data ) );
	return;
}

/**/