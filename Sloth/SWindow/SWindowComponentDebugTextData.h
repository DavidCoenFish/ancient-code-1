//file: Sloth/SWindow/SWindowComponentDebugTextData.h
#ifndef _S_WINDOW_COMPONENT_DEBUG_TEXT_DATA_H_
#define _S_WINDOW_COMPONENT_DEBUG_TEXT_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SWindowComponentDebugTextData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowComponentDebugTextData( const SWindowComponentDebugTextData& in_src );
		SWindowComponentDebugTextData(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour,
			const Pride::PColourRgb& in_backgroundColour			
			);
		SWindowComponentDebugTextData();
		~SWindowComponentDebugTextData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SWindowComponentDebugTextData& operator=( const SWindowComponentDebugTextData& in_rhs );
		const Hubris::HBOOL operator==( const SWindowComponentDebugTextData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SWindowComponentDebugTextData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HString& TextGet()const{ return m_text; }
		const Hubris::HVectorS2& LocationGet()const{ return m_location; }
		const Pride::PColourRgb& ForegroundColourGet()const{ return m_foregroundColour; }
		const Pride::PColourRgb& BackgroundColourGet()const{ return m_backgroundColour; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_text;
		Hubris::HVectorS2 m_location;
		Pride::PColourRgb m_foregroundColour;
		Pride::PColourRgb m_backgroundColour;

	};

	/**/
	
};

#endif // _S_WINDOW_COMPONENT_DEBUG_TEXT_DATA_H_