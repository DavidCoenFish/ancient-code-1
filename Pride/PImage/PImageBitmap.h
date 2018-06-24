//file: Pride/PImage/PImageBitmap.h
#ifndef _P_IMAGE_BITMAP_H_
#define _P_IMAGE_BITMAP_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage;
	typedef PImage< Hubris::HU8, 4 >PImageRgba;

	///////////////////////////////////////////////////////
	// class
	/*
		convert image to windows bitmap, owns the bitmap resource
	*/
	class PImageBitmap
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef void* HANDLE;

		////////////////////////////////////////////////
		// creation
	public:
		PImageBitmap( 
			const PImageRgba& in_image,
			const Hubris::HSINT in_planes = 4, 
			const Hubris::HSINT in_bitsPerPixel = 8
			);
		~PImageBitmap();

		////////////////////////////////////////////////
		// public accessor
	public:
		HANDLE BitmapGet()const { return m_bitmap; }

		////////////////////////////////////////////////
		// disabled
	private:
		PImageBitmap( const PImageBitmap& in_src );
		const PImageBitmap& operator =( const PImageBitmap& in_rhs );

		////////////////////////////////////////////////
		// private members
	private:
		HANDLE m_bitmap;

	};
	/**/
	
};

#endif // _P_IMAGE_BITMAP_H_