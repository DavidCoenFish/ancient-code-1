//file: Sloth/SInput/SInputMouse.h
#ifndef _S_INPUT_MOUSE_H_
#define _S_INPUT_MOUSE_H_

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
	class SInputMouse
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HWND;
		typedef Hubris::HContainerArray< SInputItemData >TArrayItemData;

		///////////////////////////////////////////////////////
		// creation
	public:
		SInputMouse();
		~SInputMouse();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SInputMouse( const SInputMouse& in_src );
		const SInputMouse& operator=( const SInputMouse& in_rhs );

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
		static const Hubris::HSINT InputIndexMouseLeftGet();
		static const Hubris::HSINT InputIndexMouseMiddleGet();
		static const Hubris::HSINT InputIndexMouseRightGet();
		static const Hubris::HSINT InputIndexMouseHorizontalGet();
		static const Hubris::HSINT InputIndexMouseVerticalGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayItemData m_arrayItemData;

	};

	/**/
	
};

#endif // _S_INPUT_MOUSE_H_