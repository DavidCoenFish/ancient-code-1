//file: Pride/PColour/PColourVariables.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PColour/PColourVariables.h"
#include "Pride/PColour/PColour.h"

#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// typedef
/**/

///////////////////////////////////////////////////////////
// creation
/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::WhiteGet()
{
	static TColour s_colour( 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::WhiteGet()
{
	static TColour s_colour( 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::WhiteGet()
{
	static TColour s_colour( 255 );
	return s_colour;
}
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
typename const PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::TColour& Pride::PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::WhiteGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< IN_TYPE >() );
	return s_colour;
}

/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::GreyGet()
{
	static TColour s_colour( 127, 127, 127, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::GreyGet()
{
	static TColour s_colour( 127 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::GreyGet()
{
	static TColour s_colour( 127 );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 4 >::TColour& Pride::PColourVariables< HREAL, 4 >::GreyGet()
{
	static TColour s_colour( HVariablesMath::HalfGet< HREAL >(), HVariablesMath::HalfGet< HREAL >(), HVariablesMath::HalfGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
typename const PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::TColour& Pride::PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::GreyGet()
{
	static TColour s_colour( HVariablesMath::HalfGet< IN_TYPE >() );
	return s_colour;
}

/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::BlackGet()
{
	static TColour s_colour( 0, 0, 0, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::BlackGet()
{
	static TColour s_colour( 0 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::BlackGet()
{
	static TColour s_colour( 0 );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 4 >::TColour& Pride::PColourVariables< HREAL, 4 >::BlackGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >
typename const PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::TColour& Pride::PColourVariables< IN_TYPE, IN_CHANNEL_COUNT >::BlackGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< IN_TYPE >() );
	return s_colour;
}

/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::RedGet()
{
	static TColour s_colour( 255, 0, 0, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::RedGet()
{
	static TColour s_colour( 255, 0, 0 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::RedGet()
{
	static TColour s_colour( 85 );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 4 >::TColour& Pride::PColourVariables< HREAL, 4 >::RedGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 3 >::TColour& Pride::PColourVariables< HREAL, 3 >::RedGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 1 >::TColour& Pride::PColourVariables< HREAL, 1 >::RedGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< HREAL >() / 3 );
	return s_colour;
}

/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::GreenGet()
{
	static TColour s_colour( 0, 255, 0, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::GreenGet()
{
	static TColour s_colour( 0, 255, 0 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::GreenGet()
{
	static TColour s_colour( 85 );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 4 >::TColour& Pride::PColourVariables< HREAL, 4 >::GreenGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 3 >::TColour& Pride::PColourVariables< HREAL, 3 >::GreenGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 1 >::TColour& Pride::PColourVariables< HREAL, 1 >::GreenGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< HREAL >() / 3 );
	return s_colour;
}

/**/
template<>
const PColourVariables< HU8, 4 >::TColour& Pride::PColourVariables< HU8, 4 >::BlueGet()
{
	static TColour s_colour( 0, 0, 255, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 3 >::TColour& Pride::PColourVariables< HU8, 3 >::BlueGet()
{
	static TColour s_colour( 0, 0, 255 );
	return s_colour;
}
template<>
const PColourVariables< HU8, 1 >::TColour& Pride::PColourVariables< HU8, 1 >::BlueGet()
{
	static TColour s_colour( 85 );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 4 >::TColour& Pride::PColourVariables< HREAL, 4 >::BlueGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 3 >::TColour& Pride::PColourVariables< HREAL, 3 >::BlueGet()
{
	static TColour s_colour( HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::ZeroGet< HREAL >(), HVariablesMath::UnitGet< HREAL >() );
	return s_colour;
}
template<>
typename const PColourVariables< HREAL, 1 >::TColour& Pride::PColourVariables< HREAL, 1 >::BlueGet()
{
	static TColour s_colour( HVariablesMath::UnitGet< HREAL >() / 3 );
	return s_colour;
}

/**/
////////////////////////////////////////////////////
// template definitions
/**/
template struct Pride::PColourVariables< HU8, 1 >;
template struct Pride::PColourVariables< HU8, 3 >;
template struct Pride::PColourVariables< HU8, 4 >;

template struct Pride::PColourVariables< HREAL, 1 >;
template struct Pride::PColourVariables< HREAL, 3 >;
template struct Pride::PColourVariables< HREAL, 4 >;

/**/