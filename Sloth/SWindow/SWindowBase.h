//file: Sloth/SWindow/SWindowBase.h
#ifndef _S_WINDOW_BASE_H_
#define _S_WINDOW_BASE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SWindowBase
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowBase();
		~SWindowBase();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowBase( const SWindowBase& in_src );
		const SWindowBase& operator=( const SWindowBase& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return false if window close has been requested
		const Hubris::HBOOL Update();

		Hubris::HVOID DebugTextDraw(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour = Pride::PColourVariablesRgb::WhiteGet(),
			const Pride::PColourRgb& in_backgroundColour = Pride::PColourVariablesRgb::BlackGet()
			);

		Hubris::HVOID DebugTextClear();

		Hubris::HVOID InputSet(
			SInput* const in_pInput
			);

		const Hubris::HVectorS2& WindowClientSizeGet()const;

		///////////////////////////////////////////////////////
		// private interface
	private:
		//return false if window close has been requested
		virtual const Hubris::HBOOL OnUpdate()=0;

		virtual Hubris::HVOID OnDebugTextDraw(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour = Pride::PColourVariablesRgb::WhiteGet(),
			const Pride::PColourRgb& in_backgroundColour = Pride::PColourVariablesRgb::BlackGet()
			)=0;

		virtual Hubris::HVOID OnDebugTextClear()=0;

		virtual Hubris::HVOID OnInputSet(
			SInput* const in_pInput
			)=0;

		virtual const Hubris::HVectorS2& OnWindowClientSizeGet()const=0;

	};

	/**/
	
};

#endif // _S_WINDOW_BASE_H_