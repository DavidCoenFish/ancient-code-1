//file: Envy/ETanya/ETanyaVariant.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/ETanya/ETanyaVariant.h"

#include "Envy/EMemento/EMemento_Export.h"

using namespace Envy;

//HTYPE_EMPTY_IMPLEMENTATION_CONSTRUCTOR( ETanyaVariant );
//const IN_CLASS& Hubris::HTraitEmpty< IN_CLASS >::EmptyGet() { static const IN_CLASS s_default; return s_default; } 	\
//IN_CLASS* Hubris::HTraitEmpty< IN_CLASS* >::EmptyGet() { return HNULL; } 

//variant
//collect values into a memento object
Hubris::HVOID Envy::EMementoTraitCollect< ETanyaVariant >( EMementoCollect& in_out_mementoCollect, const ETanyaVariant& in_data )
{
	EMementoTraitCollect( in_out_mementoCollect, ( const ETanyaVariant::TVariantImplementation& )( in_data ) );
	return;
}
Hubris::HVOID Envy::EMementoTraitAssign< ETanyaVariant >( const EMementoAssign& in_out_mementoAssign, ETanyaVariant& out_data )
{
	EMementoTraitAssign( in_out_mementoAssign, ( ETanyaVariant::TVariantImplementation& )( out_data ) );
	return;
}

/**/