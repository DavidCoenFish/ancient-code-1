//file: Pride/PImage/PImageTga.h
#ifndef _P_IMAGE_TGA_H_
#define _P_IMAGE_TGA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HFileSystem;
	class HFileSystemPath;
}

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage;
	typedef PImage< Hubris::HU8, 1 >PImageMono;
	typedef PImage< Hubris::HU8, 3 >PImageRgb;
	typedef PImage< Hubris::HU8, 4 >PImageRgba;

	///////////////////////////////////////////////////////
	// struct
	/*
		load and save tga file with PImage data
	*/
	struct PImageTga
	{
		///////////////////////////////////////////////////////
		// static public methods
	public:
		//return true if file found, output tga format preference
		static const Hubris::HBOOL TgaFormatGet( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, Hubris::HBOOL& out_isMono, Hubris::HBOOL& out_isRgb, Hubris::HBOOL& out_isRgba );

		//policy, out image is zero size if file not found or wrong format
		static const Hubris::HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageMono& out_imageMono );
		static const Hubris::HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgb& out_imageRgb );
		static const Hubris::HBOOL TgaLoad( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba );

		//load any format TGA and return it as Rgba
		static const Hubris::HBOOL TgaLoadGeneric( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, PImageRgba& out_imageRgba );

		static const Hubris::HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageMono& in_imageMono );
		static const Hubris::HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgb& in_imageRgb );
		static const Hubris::HBOOL TgaSave( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_path, const PImageRgba& in_imageRgba );

		static const Hubris::HBOOL BufferTgaFormatGet( const Hubris::HBuffer& in_buffer, Hubris::HBOOL& out_isMono, Hubris::HBOOL& out_isRgb, Hubris::HBOOL& out_isRgba );

		static const Hubris::HBOOL BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageMono& out_imageMono );
		static const Hubris::HBOOL BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageRgb& out_imageRgb );
		static const Hubris::HBOOL BufferTgaLoad( const Hubris::HBuffer& in_buffer, PImageRgba& out_imageRgba );

		static const Hubris::HBOOL BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageMono& in_imageMono );
		static const Hubris::HBOOL BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageRgb& in_imageRgb );
		static const Hubris::HBOOL BufferTgaSave( Hubris::HBuffer& out_buffer, const PImageRgba& in_imageRgba );

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HCHAR* const TgaExtentionGet();

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PImageTga();

	};
	/**/
	
};

#endif // _P_IMAGE_UTILITY_H_