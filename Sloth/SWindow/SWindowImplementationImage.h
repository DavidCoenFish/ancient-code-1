//file: Sloth/SWindow/SWindowImplementationImage.h
#ifndef _S_WINDOW_IMPLEMENTATION_IMAGE_H_
#define _S_WINDOW_IMPLEMENTATION_IMAGE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowImplementationBase.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowComponentImage;
	class SWindowImageInterface;
	class SWindowComponentPaintDx;
	struct SWindowParam;
	class SInterfaceImage;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SWindowImplementationImage : public SWindowImplementationBase
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HBITMAP;
		typedef Hubris::HVOID* HWND;
		typedef Hubris::HVOID* HDC;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImplementationImage();
		~SWindowImplementationImage();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImplementationImage( const SWindowImplementationImage& in_src );
		const SWindowImplementationImage& operator=( const SWindowImplementationImage& in_rhs );

		///////////////////////////////////////////////////////
		// implement SWindowImplementationBase
	private:
		virtual Hubris::HVOID OnClose(
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnCreate( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnPaint( 
			HWND in_hWnd 
			);
		virtual Hubris::HVOID OnSize( 
			HWND in_hWnd,
			const Hubris::HSINT in_width,
			const Hubris::HSINT in_height
			);
		virtual Hubris::HVOID OnDestroy(
			HWND in_hWnd 			
			);

		///////////////////////////////////////////////////////
		// public methods, implement SWindowImplementationImage
	public: 
		//get the image size
		const Hubris::HVectorS2 SizeGet()const;

		//set one pixel colour
		Hubris::HVOID PixelSet(
			const Hubris::HVectorS2& in_pos,
			const Pride::PColourRgba& in_colour
			);
		Hubris::HVOID ImageSet(
			const Pride::PImageRgba& in_image
			);
		//set the entire image to one colour
		Hubris::HVOID PixelWipe(
			const Pride::PColourRgba& in_colour
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		SInterfaceImage* const ImageInterfaceCreate();

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorS2 m_size;
	
		HBITMAP m_bitmapIndependant;
		HDC m_memoryDeviceContextIndependant;
		Hubris::HVOID* m_pbitmapIndependantData;
	};

	/**/
	
};

#endif // _S_WINDOW_IMPLEMENTATION_H_