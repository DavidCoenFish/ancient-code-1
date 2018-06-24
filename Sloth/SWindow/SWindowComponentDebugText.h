//file: Sloth/SWindow/SWindowComponentDebugText.h
#ifndef _S_WINDOW_COMPONENT_DEBUG_TEXT_H_
#define _S_WINDOW_COMPONENT_DEBUG_TEXT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowComponentDebugTextData.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SWindowComponentDebugText
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HWND;
		typedef Hubris::HContainerArray< SWindowComponentDebugTextData >TArrayData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowComponentDebugText();
		~SWindowComponentDebugText();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowComponentDebugText( const SWindowComponentDebugText& in_src );
		const SWindowComponentDebugText& operator=( const SWindowComponentDebugText& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID TextAdd(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour,
			const Pride::PColourRgb& in_backgroundColour
			);

		Hubris::HVOID TextClear();

		Hubris::HVOID TextDraw(
			HWND in_hwnd
			);

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayData m_arrayData;

	};

	/**/
	
};

#endif // _S_WINDOW_COMPONENT_DEBUG_TEXT_H_