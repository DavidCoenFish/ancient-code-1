//file: Sloth/SInput/SInputImplementation.h
#ifndef _S_INPUT_IMPLEMENTATION_H_
#define _S_INPUT_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	struct SInputParam;
	class SInputKeyboard;
	class SInputMouse;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SInputImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HWND;

		///////////////////////////////////////////////////////
		// creation
	public:
		SInputImplementation( 
			const SInputParam& in_param
			);
		~SInputImplementation();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SInputImplementation( const SInputImplementation& in_src );
		const SInputImplementation& operator=( const SInputImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT ButtonStateGet(
			const Hubris::HSINT in_deviceIndex,
			const Hubris::HSINT in_inputIndex
			)const;

		const Hubris::HREAL InputAmountGet(
			const Hubris::HSINT in_deviceIndex,
			const Hubris::HSINT in_inputIndex
			)const;

		const Hubris::HREAL InputDeltaGet(
			const Hubris::HSINT in_deviceIndex,
			const Hubris::HSINT in_inputIndex
			)const;

		Hubris::HVOID UpdatePreProcessMessages();
		Hubris::HVOID ProcessMessages(
			HWND in_hWnd,
			const Hubris::HU32 in_uMessage,
			const Hubris::HU32 in_wParam,
			const Hubris::HU32 in_lParam			
			);

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT DeviceIndexKeyboardGet();
		static const Hubris::HSINT DeviceIndexMouseGet();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SInputKeyboard& KeyboardGet()const;
		SInputKeyboard& KeyboardGet();

		const SInputMouse& MouseGet()const;
		SInputMouse& MouseGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SInputKeyboard* m_pKeyboard;
		SInputMouse* m_pMouse;

	};

	/**/
	
};

#endif // _S_INPUT_IMPLEMENTATION_H_