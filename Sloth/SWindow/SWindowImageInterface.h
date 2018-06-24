//file: Sloth/SWindow/SWindowImageInterface.h
#ifndef _S_WINDOW_IMAGE_INTERFACE_H_
#define _S_WINDOW_IMAGE_INTERFACE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SInterface/SInterfaceImage.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SWindowImplementationImage;

	///////////////////////////////////////////////////////
	// class
	/**/
	class SWindowImageInterface : public SInterfaceImage
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HINSTANCE;
		typedef Hubris::HVOID* HWND;

		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowImageInterface(
			SWindowImplementationImage& in_windowImplemetation
			);
		~SWindowImageInterface();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID DeleteThis();

		//get the image size
		virtual const Hubris::HVectorS2 SizeGet()const;

		//set one pixel colour
		virtual Hubris::HVOID PixelSet(
			const Hubris::HVectorS2& in_pos,
			const Pride::PColourRgba& in_colour
			);
		virtual Hubris::HVOID ImageSet(
			const Pride::PImageRgba& in_image
			);
		//set the entire image to one colour
		virtual Hubris::HVOID PixelWipe(
			const Pride::PColourRgba& in_colour
			);

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowImageInterface( const SWindowImageInterface& in_src );
		const SWindowImageInterface& operator=( const SWindowImageInterface& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private members
	private:
		//references, we don't own, just provide interface for
		SWindowImplementationImage& m_windowImplemetation;

	};

	/**/
	
};

#endif // _S_WINDOW_IMAGE_INTERFACE_H_