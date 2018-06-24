//file: Pride/PImage/PImage.h
#ifndef _P_IMAGE_H_
#define _P_IMAGE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage;
	typedef PImage< Hubris::HU8, 1 >PImageMono;
	typedef PImage< Hubris::HU8, 3 >PImageRgb;
	typedef PImage< Hubris::HU8, 4 >PImageRgba;

	typedef PImage< Hubris::HREAL, 1 >PImageRealMono;
	typedef PImage< Hubris::HREAL, 3 >PImageRealRgb;
	typedef PImage< Hubris::HREAL, 4 >PImageRealRgba;

	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;

	///////////////////////////////////////////////////////
	// class
	/*
		base bones image object, template channel count and type
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage
	{
		///////////////////////////////////////////////////////////
		// typedef
	public:
		typedef PColour< IN_TYPE, IN_CHANNEL_COUNT >TColour;
	private:
		typedef Hubris::HContainerArray< IN_TYPE >TArrayData;
		typedef Hubris::HMatrix< IN_TYPE, IN_CHANNEL_COUNT, 1 >TVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PImage( const PImage& in_src );
		PImage( const Hubris::HVectorS2& in_size = Hubris::HVectorS2() );
		~PImage();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PImage& operator=( const PImage& in_rhs );
		Hubris::HBOOL operator==( const PImage& in_rhs )const;
		Hubris::HBOOL operator!=( const PImage& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return true if given index is valid
		Hubris::HBOOL IndexValid( const Hubris::HVectorS2& in_index )const;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const Hubris::HVectorS2 IndexCreate( const Hubris::HSINT in_width, const Hubris::HSINT in_height );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//assert if out of range (return by const value not reference intentional, don't oblige implementation )
		const TColour ColourGet( const Hubris::HVectorS2& in_index )const;
		void ColourSet( const Hubris::HVectorS2& in_index, const TColour& in_colour );

		//makes no attempt at preserving image data
		void SizeSet( const Hubris::HVectorS2& in_size );
		//(return by const value not reference intentional)
		const Hubris::HVectorS2 SizeGet()const{ return m_size; }

		const void* const RawGet()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorS2 m_size;
		TArrayData m_data;

	};
	/**/
};

#endif // _P_IMAGE_H_