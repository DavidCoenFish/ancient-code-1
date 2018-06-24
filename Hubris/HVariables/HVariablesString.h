//file: Hubris/HVariables/HVariablesString.h
#ifndef _H_VARIABLES_STRING_H_
#define _H_VARIABLES_STRING_H_

#include "Hubris/HCommon/HCommonType.h"

/**/
namespace Hubris
{
	/**/
	struct HVariablesString
	{
		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~HVariablesString();

		/////////////////////////////////////////////////////////////////
		// static public methods
	public:
		static const HCHAR ArrayStartGet();
		static const HCHAR ArrayEndGet();
		static const HCHAR BlockStartGet();
		static const HCHAR BlockEndGet();
		static const HCHAR EndOfStringGet();
		static const HCHAR CarrageReturnGet();
		static const HCHAR NewLineGet();
		static const HCHAR TabGet();
		static const HCHAR SpaceGet();
		static const HCHAR QuoteGet();
		static const HCHAR CommaGet();
		static const HCHAR PercentageGet();
		static const HCHAR EqualGet();
		static const HCHAR PlusGet();
		static const HCHAR MinusGet();
		static const HCHAR DecimalGet();
		static const HCHAR ExponentGet();
		static const HCHAR SemiColonGet();
		static const HCHAR ColonGet();
		static const HCHAR SlashGet();
		static const HCHAR BackSlashGet();
		static const HCHAR NumberSign();
		static const HCHAR QuestionMark();

		static const HCHAR LowA();
		static const HCHAR LowB();
		static const HCHAR LowC();
		static const HCHAR LowD();
		static const HCHAR LowE();
		static const HCHAR LowF();
		static const HCHAR LowG();
		static const HCHAR LowH();
		static const HCHAR LowI();
		static const HCHAR LowJ();
		static const HCHAR LowK();
		static const HCHAR LowL();
		static const HCHAR LowM();
		static const HCHAR LowN();
		static const HCHAR LowO();
		static const HCHAR LowP();
		static const HCHAR LowQ();
		static const HCHAR LowR();
		static const HCHAR LowS();
		static const HCHAR LowT();
		static const HCHAR LowU();
		static const HCHAR LowV();
		static const HCHAR LowW();
		static const HCHAR LowX();
		static const HCHAR LowY();
		static const HCHAR LowZ();
		
		static const HCHAR HighA();
		static const HCHAR HighB();
		static const HCHAR HighC();
		static const HCHAR HighD();
		static const HCHAR HighE();
		static const HCHAR HighF();
		static const HCHAR HighG();
		static const HCHAR HighH();
		static const HCHAR HighI();
		static const HCHAR HighJ();
		static const HCHAR HighK();
		static const HCHAR HighL();
		static const HCHAR HighM();
		static const HCHAR HighN();
		static const HCHAR HighO();
		static const HCHAR HighP();
		static const HCHAR HighQ();
		static const HCHAR HighR();
		static const HCHAR HighS();
		static const HCHAR HighT();
		static const HCHAR HighU();
		static const HCHAR HighV();
		static const HCHAR HighW();
		static const HCHAR HighX();
		static const HCHAR HighY();
		static const HCHAR HighZ();

		//return hchar for digit [0...9]
		static const HCHAR DigitGet( const HSINT in_index );
		//return hchar for hexidecimal [0...15]
		static const HCHAR HexGet( const HSINT in_index );
		//return alt case hchar for hexidecimal [0...15]
		static const HCHAR HexAltGet( const HSINT in_index );

		static const HCHAR* const TrueGet();
		static const HCHAR* const FalseGet();
	};

	/**/
};

/**/
#endif // _H_STRING_VARIABLES_H_