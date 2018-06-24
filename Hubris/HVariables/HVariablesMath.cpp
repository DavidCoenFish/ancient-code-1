//file: Hubris/HVariables/HVariablesMath.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HVariables/HVariablesMath.h"

#include < limits >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////
// public methods
/*
	template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::ZeroGet();
*/
template <>
const HU8 Hubris::HVariablesMath::ZeroGet< HU8 >()
{
	return 0;
}
template <>
const HSINT Hubris::HVariablesMath::ZeroGet< HSINT >()
{
	return 0;
}
template <>
const HREAL Hubris::HVariablesMath::ZeroGet< HREAL >()
{
	return 0.0F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::HalfGet();
*/
template <>
const HREAL Hubris::HVariablesMath::HalfGet< HREAL >()
{
	return( 0.5F );
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::TwiceGet();
*/
template <>
const HSINT Hubris::HVariablesMath::TwiceGet< HSINT >()
{
	return 2;
}
template <>
const HREAL Hubris::HVariablesMath::TwiceGet< HREAL >()
{
	return( 2.0F );
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::UnitGet();
*/
template <>
const HSINT Hubris::HVariablesMath::UnitGet< HSINT >()
{
	return 1;
}
template <>
const HREAL Hubris::HVariablesMath::UnitGet< HREAL >()
{
	return( 1.0F );
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::MinimumGet();
*/
template <>
const HS8 Hubris::HVariablesMath::MinimumGet< HS8 >()
{
	return( -( std::numeric_limits< HS8 >::max() ) );
}
template <>
const HU8 Hubris::HVariablesMath::MinimumGet< HU8 >()
{
	return 0;
}
template <>
const HS32 Hubris::HVariablesMath::MinimumGet< HS32 >()
{
	return( -( std::numeric_limits< HS32 >::max() ) );
}
template <>
const HU32 Hubris::HVariablesMath::MinimumGet< HU32 >()
{
	return 0;
}
template <>
const HREAL Hubris::HVariablesMath::MinimumGet< HREAL >()
{
	return( -( std::numeric_limits< HREAL >::max() ) );
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::MaximumGet();
*/
template <>
const HS8 Hubris::HVariablesMath::MaximumGet< HS8 >()
{
	return std::numeric_limits< HS8 >::max();
}
template <>
const HU8 Hubris::HVariablesMath::MaximumGet< HU8 >()
{
	return std::numeric_limits< HU8 >::max();
}
template <>
const HS32 Hubris::HVariablesMath::MaximumGet< HS32 >()
{
	return std::numeric_limits< HS32 >::max();
}
template <>
const HU32 Hubris::HVariablesMath::MaximumGet< HU32 >()
{
	return std::numeric_limits< HU32 >::max();
}
template <>
const HREAL Hubris::HVariablesMath::MaximumGet< HREAL >()
{
	return std::numeric_limits< HREAL >::max();
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiGet();
*/
template <>
const HREAL Hubris::HVariablesMath::PiGet< HREAL >()
{
	return 3.1415926535897932384626433832795F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiHalfGet()
*/
template <>
const HREAL Hubris::HVariablesMath::PiHalfGet< HREAL >()
{
	return 1.5707963267948966192313216916398F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiTwiceGet()
*/
template <>
const HREAL Hubris::HVariablesMath::PiTwiceGet< HREAL >()
{
	return 6.283185307179586476925286766559F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiInvertGet()
*/
template <>
const HREAL Hubris::HVariablesMath::PiInvertGet< HREAL >()
{
	return 0.31830988618379067153776752674503F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiHalfInvertGet()
*/
template <>
const HREAL Hubris::HVariablesMath::PiHalfInvertGet< HREAL >()
{
	return 0.63661977236758134307553505349006F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::PiTwiceInvertGet()
*/
template <>
const HREAL Hubris::HVariablesMath::PiTwiceInvertGet< HREAL >()
{
	return 0.15915494309189533576888376337251F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::EpsilonGet()
*/
template <>
const HU8 Hubris::HVariablesMath::EpsilonGet< HU8 >()
{
	return 0;
}
template <>
const HSINT Hubris::HVariablesMath::EpsilonGet< HSINT >()
{
	return 0;
}
template <>
const HREAL Hubris::HVariablesMath::EpsilonGet< HREAL >()
{
	return std::numeric_limits< HREAL >::epsilon();
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::RadToDegGet()
*/
template <>
const HREAL Hubris::HVariablesMath::RadToDegGet< HREAL >()
{
	return 57.295779513082320876798154814105F;
}

/*
template< typename IN_TYPE >const IN_TYPE Hubris::HVariablesMath::DegToRadGet()
*/
template <>
const HREAL Hubris::HVariablesMath::DegToRadGet< HREAL >()
{
	return 0.017453292519943295769236907684886F;
}

/**/

