//file: Pride/PImage/PImageUtility.h
#ifndef _P_IMAGE_UTILITY_H_
#define _P_IMAGE_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PImage;
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >struct PImageUtility;
	typedef PImageUtility< Hubris::HU8, 1 >PImageUtilityMono;
	typedef PImageUtility< Hubris::HU8, 3 >PImageUtilityRgb;
	typedef PImageUtility< Hubris::HU8, 4 >PImageUtilityRgba;

	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;

	///////////////////////////////////////////////////////
	// struct
	/*
		tri-linear sample and clamp image on out of range
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >struct PImageUtility
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef PColour< IN_TYPE, IN_CHANNEL_COUNT >TColour;
		typedef PImage< IN_TYPE, IN_CHANNEL_COUNT >TImage;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//assert on &in_src == &out_resizedImage;
		static void ResizeImage( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize ); 
		static void ResizeImageQuick( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize ); 
		//assert on &in_src == &out_resizedImage;
		static void CropImage( 
			TImage& out_resizedImage, 
			const TImage& in_src, 
			const Hubris::HVectorS2& 
			in_newSize, 
			const Hubris::HVectorS2& in_origin = Hubris::HMatrixConstructor::HVectorS2Construct( 0, 0 )
		); 

		///////////////////////////////////////////////////////
		// static privatemethods
	private:
		//trilinear blend, clamp edge pixels
		static void	SampleImage( TColour& out_colour, const TImage& in_src, const Hubris::HVectorS2& in_resizedIndex, const Hubris::HVectorS2& in_resizedSize );

		//add to sum the area weighted average colour at index constrained by bounds
		static void	SampleBoundSrc( Hubris::HREAL* in_out_sum, const TImage& in_src, const Hubris::HVectorS2& in_index, const Hubris::HVectorR2& in_boundLow, const Hubris::HVectorR2& in_boundHigh );

		//get the clamped colour of an image
		static void	ClampedColourGet( TColour& out_colour, const TImage& in_src, const Hubris::HVectorS2& in_index );

		//get the clamped colour of an image
		static void	SamplePoint( TColour& out_colour, const TImage& in_src, const Hubris::HVectorR2& in_index );

		///////////////////////////////////////////////////////
		// disabled
	private:
		~PImageUtility();

	};
	/**/

};

#endif // _P_IMAGE_UTILITY_H_