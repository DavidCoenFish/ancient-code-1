//file: Sloth/SWindow/SWindowImage.h
#ifndef _S_WINDOW_IMAGE_H_
#define _S_WINDOW_IMAGE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowBase.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowImplementationImage;
	class SInterfaceImage;
	struct SWindowParam;

	///////////////////////////////////////////////////////
	// class
	/*
		window object
			owns window resource
			creates class desc if needed
			//given callback object to inform close request?
			returns bool on update refecting close request status
	*/
	class SWindowImage : public SWindowBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImage( 
			HINSTANCE in_hInstance,
			const SWindowParam& in_windowParam
			);
		~SWindowImage();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImage( const SWindowImage& in_src );
		const SWindowImage& operator=( const SWindowImage& in_rhs );

		///////////////////////////////////////////////////////
		// implement SWindowBase
	private:
		//return false if window close has been requested
		virtual const Hubris::HBOOL OnUpdate();

		virtual Hubris::HVOID OnDebugTextDraw(
			const Hubris::HString& in_text,
			const Hubris::HVectorS2& in_location,
			const Pride::PColourRgb& in_foregroundColour = Pride::PColourVariablesRgb::WhiteGet(),
			const Pride::PColourRgb& in_backgroundColour = Pride::PColourVariablesRgb::BlackGet()
			);

		virtual Hubris::HVOID OnDebugTextClear();
		virtual Hubris::HVOID OnInputSet(
			SInput* const in_pInput
			);
		virtual const Hubris::HVectorS2& OnWindowClientSizeGet()const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return a reference to an image interface for the window.
		SInterfaceImage* const ImageInterfaceCreate();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SWindowImplementationImage& ImplementationGet()const;
		SWindowImplementationImage& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		SWindowImplementationImage* m_pImplementation;

	};

	/**/
	
};

#endif // _S_WINDOW_IMAGE_H_