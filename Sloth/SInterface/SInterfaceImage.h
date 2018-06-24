//file: Sloth/SInterface/SInterfaceImage.h
#ifndef _S_INTERFACE_PROGRESS_H_
#define _S_INTERFACE_PROGRESS_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 1 >PColourMono;
	typedef PColour< Hubris::HU8, 3 >PColourRgb;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 1 >PColourRealMono;
	typedef PColour< Hubris::HREAL, 3 >PColourRealRgb;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;
};


namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class SInterfaceAnimationVariant;

	///////////////////////////////////////////////////////
	// class
	/*
		provide interface for receiving image information
		 evolved into being a write lock
	*/
	class SInterfaceImage
	{
		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID DeleteThis()=0;

		//get the image size, nb. for windows we pad to width div by 4
		virtual const Hubris::HVectorS2 SizeGet()const=0;

		//set one pixel colour
		virtual Hubris::HVOID PixelSet(
			const Hubris::HVectorS2& in_pos,
			const Pride::PColourRgba& in_colour
			)=0;
		//observed no improvement for using PImageRgba
		virtual Hubris::HVOID ImageSet(
			const Pride::PImageRgba& in_image
			)=0;
		//set the entire image to one colour
		virtual Hubris::HVOID PixelWipe(
			const Pride::PColourRgba& in_colour
			)=0;

	};

	/**/
};

#endif // _S_INTERFACE_PROGRESS_H_