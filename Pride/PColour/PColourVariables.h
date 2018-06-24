//file: Pride/PColour/PColourVariables.h
#ifndef _P_COLOUR_VARIABLES_H_
#define _P_COLOUR_VARIABLES_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >struct PColourVariables;

	typedef PColourVariables< Hubris::HU8, 1 >PColourVariablesMono;
	typedef PColourVariables< Hubris::HU8, 3 >PColourVariablesRgb;
	typedef PColourVariables< Hubris::HU8, 4 >PColourVariablesRgba;

	typedef PColourVariables< Hubris::HREAL, 1 >PColourVariablesRealMono;
	typedef PColourVariables< Hubris::HREAL, 3 >PColourVariablesRealRgb;
	typedef PColourVariables< Hubris::HREAL, 4 >PColourVariablesRealRgba;

	///////////////////////////////////////////////////////
	// struct
	/*
		for mono, reg/ green/ blue is treated as 1/3 of the colout intensity of white
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >struct PColourVariables
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef PColour< IN_TYPE, IN_CHANNEL_COUNT >TColour;

		///////////////////////////////////////////////////////
		// public static accessors
	public:
		static const TColour& WhiteGet();
		static const TColour& GreyGet();
		static const TColour& BlackGet();

		static const TColour& RedGet();
		static const TColour& GreenGet();
		static const TColour& BlueGet();

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PColourVariables();

	};

	/**/
};

#endif // _P_COLOUR_VARIABLES_H_