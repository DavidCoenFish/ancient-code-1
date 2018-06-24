//file: Hubris/HVariables/HVariablesMath.h
#ifndef _H_VARIABLES_MATH_H_
#define _H_VARIABLES_MATH_H_

#include "Hubris/HCommon/HCommonType.h"

/* collect some variables for the base types */
namespace Hubris
{
	/**/
	struct HVariablesMath
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HVariablesMath();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >static const IN_TYPE ZeroGet();
		template< typename IN_TYPE >static const IN_TYPE HalfGet();
		template< typename IN_TYPE >static const IN_TYPE TwiceGet();
		template< typename IN_TYPE >static const IN_TYPE UnitGet();
		template< typename IN_TYPE >static const IN_TYPE MinimumGet();
		template< typename IN_TYPE >static const IN_TYPE MaximumGet();
		template< typename IN_TYPE >static const IN_TYPE PiGet();
		template< typename IN_TYPE >static const IN_TYPE PiHalfGet();
		template< typename IN_TYPE >static const IN_TYPE PiTwiceGet();
		template< typename IN_TYPE >static const IN_TYPE PiInvertGet();
		template< typename IN_TYPE >static const IN_TYPE PiHalfInvertGet();
		template< typename IN_TYPE >static const IN_TYPE PiTwiceInvertGet();
		template< typename IN_TYPE >static const IN_TYPE EpsilonGet();
		template< typename IN_TYPE >static const IN_TYPE RadToDegGet();
		template< typename IN_TYPE >static const IN_TYPE DegToRadGet();

	};

	//////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::ZeroGet();
	//template<>const HU8 HVariablesMath::ZeroGet();
	//template<>const HSINT HVariablesMath::ZeroGet();
	//template const HREAL HVariablesMath::ZeroGet< HREAL >();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::HalfGet();
	//template<>const HREAL HVariablesMath::HalfGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::TwiceGet();
	//template<>const HSINT HVariablesMath::TwiceGet();
	//template<>const HREAL HVariablesMath::TwiceGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::UnitGet();
	//template<>const HSINT HVariablesMath::UnitGet();
	//template<>const HREAL HVariablesMath::UnitGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::MinimumGet();
	//template<>const HS8 HVariablesMath::MinimumGet();
	//template<>const HU8 HVariablesMath::MinimumGet();
	//template<>const HS32 HVariablesMath::MinimumGet();
	//template<>const HU32 HVariablesMath::MinimumGet();
	//template<>const HREAL HVariablesMath::MinimumGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::MaximumGet();
	//template<>const HS8 HVariablesMath::MaximumGet();
	//template<>const HU8 HVariablesMath::MaximumGet();
	//template<>const HS32 HVariablesMath::MaximumGet();
	//template<>const HU32 HVariablesMath::MaximumGet();
	//template<>const HREAL HVariablesMath::MaximumGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiGet();
	//template<>const HREAL HVariablesMath::PiGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiHalfGet();
	//template<>const HREAL HVariablesMath::PiHalfGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiTwiceGet();
	//template<>const HREAL HVariablesMath::PiTwiceGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiInvertGet();
	//template<>const HREAL HVariablesMath::PiInvertGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiHalfInvertGet();
	//template<>const HREAL HVariablesMath::PiHalfInvertGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::PiTwiceInvertGet();
	//template<>const HREAL HVariablesMath::PiTwiceInvertGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::EpsilonGet();
	//template<>const HU8 HVariablesMath::EpsilonGet();
	//template<>const HSINT HVariablesMath::EpsilonGet();
	//template<>const HREAL HVariablesMath::EpsilonGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::RadToDegGet();
	//template<>const HREAL HVariablesMath::RadToDegGet();

	///**/
	////template< typename IN_TYPE >static const IN_TYPE HVariablesMath::DegToRadGet();
	//template<>const HREAL HVariablesMath::DegToRadGet();

	/**/
};

#endif// _H_VARIABLES_MATH_H_