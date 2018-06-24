//file: Sloth/SInput/SInputKeyboard.h
#ifndef _S_INPUT_KEYBOARD_H_
#define _S_INPUT_KEYBOARD_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Sloth/SInput/SInputItemData.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInputImplementation;
	struct SInputParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class SInputKeyboard
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HWND;
		typedef Hubris::HContainerTree< Hubris::HSINT, SInputItemData >TTreeSintItemData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SInputKeyboard();
		~SInputKeyboard();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SInputKeyboard( const SInputKeyboard& in_src );
		const SInputKeyboard& operator=( const SInputKeyboard& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT ButtonStateGet(
			const Hubris::HSINT in_inputIndex
			)const;

		const Hubris::HREAL InputAmountGet(
			const Hubris::HSINT in_inputIndex
			)const;

		const Hubris::HREAL InputDeltaGet(
			const Hubris::HSINT in_inputIndex
			)const;

		//
		Hubris::HVOID UpdatePreProcessMessages();
		Hubris::HVOID ProcessMessages(
			HWND in_hWnd,
			const Hubris::HU32 in_uMessage,
			const Hubris::HU32 in_wParam,
			const Hubris::HU32 in_lParam
			);

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const Hubris::HSINT InputIndexKeyboardEscapeGet(); 
		static const Hubris::HSINT InputIndexKeyboardShiftGet();  
		static const Hubris::HSINT InputIndexKeyboardControlGet();
		static const Hubris::HSINT InputIndexKeyboardMenuGet();   
		static const Hubris::HSINT InputIndexKeyboardCapitalGet();
		static const Hubris::HSINT InputIndexKeyboardReturnGet(); 
		static const Hubris::HSINT InputIndexKeyboardSpaceGet();  
		static const Hubris::HSINT InputIndexKeyboardLeftGet();   
		static const Hubris::HSINT InputIndexKeyboardUpGet();     
		static const Hubris::HSINT InputIndexKeyboardRightGet();  
		static const Hubris::HSINT InputIndexKeyboardDownGet();   
		static const Hubris::HSINT InputIndexKeyboardNumPad0Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad1Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad2Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad3Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad4Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad5Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad6Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad7Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad8Get();
		static const Hubris::HSINT InputIndexKeyboardNumPad9Get();
		static const Hubris::HSINT InputIndexKeyboardMultiply();
		static const Hubris::HSINT InputIndexKeyboardAddGet();    
		static const Hubris::HSINT InputIndexKeyboardSeparator();
		static const Hubris::HSINT InputIndexKeyboardSubtract();
		static const Hubris::HSINT InputIndexKeyboardDecimalGet();
		static const Hubris::HSINT InputIndexKeyboardDivideGet(); 

		///////////////////////////////////////////////////////
		// private members
	private:
		TTreeSintItemData m_treeKeyState;

	};

	/**/
	
};

#endif // _S_INPUT_KEYBOARD_H_