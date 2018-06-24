\
//file: Pride/PImage/PImageUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PImage/PImageUtility.h"

#include "Pride/PImage/PImage.h"

#include "Pride/PColour/PColour_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

////////////////////////////////////////////////////
// template definitions
/**/
template struct Pride::PImageUtility< HU8, 1 >;
template struct Pride::PImageUtility< HU8, 3 >;
template struct Pride::PImageUtility< HU8, 4 >;

template struct Pride::PImageUtility< HREAL, 4 >;

///////////////////////////////////////////////////////
// static public methods
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::ResizeImage( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize )
{
	HCOMMON_ASSERT( &out_resizedImage != &in_src, "invalid param, src and dest should not be the same" );

	out_resizedImage.SizeSet( in_newSize );
	for( HSINT indexResizedWidth = 0; indexResizedWidth < in_newSize[ 0 ]; ++indexResizedWidth )
	{
		for( HSINT indexResizedHeight = 0; indexResizedHeight < in_newSize[ 1 ]; ++indexResizedHeight )
		{
			const HVectorS2 resizedIndex = HMatrixConstructor::HVectorS2Construct( indexResizedWidth, indexResizedHeight );
			TColour sampledColour;

			SampleImage( sampledColour, in_src, resizedIndex, in_newSize );

			out_resizedImage.ColourSet( resizedIndex, sampledColour );
		}
	}

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::ResizeImageQuick( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize )
{
	HCOMMON_ASSERT( &out_resizedImage != &in_src, "invalid param, src and dest should not be the same" );

	out_resizedImage.SizeSet( in_newSize );

	const HVectorS2 oldSize = in_src.SizeGet();
	HVectorR2 adjustPos = HMatrixConstructor::HVectorR2Construct( ( HREAL )( oldSize[ 0 ] ) / ( HREAL )( in_newSize[ 0 ] ), ( HREAL )( oldSize[ 1 ] ) / ( HREAL )( in_newSize[ 1 ] ) );

	for( HSINT indexResizedWidth = 0; indexResizedWidth < in_newSize[ 0 ]; ++indexResizedWidth )
	{
		for( HSINT indexResizedHeight = 0; indexResizedHeight < in_newSize[ 1 ]; ++indexResizedHeight )
		{
			const HVectorS2 srcIndex = HMatrixConstructor::HVectorS2Construct( ( HSINT )(indexResizedWidth * adjustPos[ 0 ] ), ( HSINT )(indexResizedHeight * adjustPos[ 1 ] ) );
			TColour sampledColour;

			ClampedColourGet( sampledColour, in_src, srcIndex );

			const HVectorS2 resizedIndex = HMatrixConstructor::HVectorS2Construct( indexResizedWidth, indexResizedHeight );
			out_resizedImage.ColourSet( resizedIndex, sampledColour );
		}
	}

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::CropImage( TImage& out_resizedImage, const TImage& in_src, const Hubris::HVectorS2& in_newSize, const Hubris::HVectorS2& in_origin )
{
	HCOMMON_ASSERT( &out_resizedImage != &in_src, "invalid param, src and dest should not be the same" );

	out_resizedImage.SizeSet( in_newSize );
	for( HSINT indexResizedWidth = 0; indexResizedWidth < in_newSize[ 0 ]; ++indexResizedWidth )
	{
		for( HSINT indexResizedHeight = 0; indexResizedHeight < in_newSize[ 1 ]; ++indexResizedHeight )
		{
			const HVectorS2 resizedIndex = HMatrixConstructor::HVectorS2Construct( indexResizedWidth, indexResizedHeight );
			TColour sampledColour;

			ClampedColourGet( sampledColour, in_src, resizedIndex + in_origin );

			out_resizedImage.ColourSet( resizedIndex, sampledColour );
		}
	}

	return;
}

///////////////////////////////////////////////////////
// static privatemethods
/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::SampleImage( TColour& out_colour, const TImage& in_src, const Hubris::HVectorS2& in_resizedIndex, const Hubris::HVectorS2& in_resizedSize )
{
	HREAL sum[ IN_CHANNEL_COUNT ];
	for( HSINT index = 0; index < IN_CHANNEL_COUNT; ++index )
	{ 
		sum[ index ] = 0; 
	}

	//get the index bounds
	HVectorR2 boundLow;
	HVectorR2 boundHigh;
	const HVectorS2 size = in_src.SizeGet();

	boundLow[ 0 ] = ( ( ( HREAL ) in_resizedIndex[ 0 ] ) / ( ( HREAL ) in_resizedSize[ 0 ] ) ) * ( ( HREAL ) size[ 0 ] );
	boundLow[ 1 ] = ( ( ( HREAL ) in_resizedIndex[ 1 ] ) / ( ( HREAL ) in_resizedSize[ 1 ] ) ) * ( ( HREAL ) size[ 1 ] );

	boundHigh[ 0 ] = ( ( ( HREAL ) in_resizedIndex[ 0 ] + 1.0F ) / ( ( HREAL ) in_resizedSize[ 0 ] ) ) * ( ( HREAL ) size[ 0 ] );
	boundHigh[ 1 ] = ( ( ( HREAL ) in_resizedIndex[ 1 ] + 1.0F ) / ( ( HREAL ) in_resizedSize[ 1 ] ) ) * ( ( HREAL ) size[ 1 ] );

	HSINT indexWidthLow = ( HSINT ) boundLow[ 0 ];
	if( boundLow[ 0 ] < 0 )
	{
		indexWidthLow -= 1;
	}
	HSINT indexWidthHigh = ( HSINT ) boundHigh[ 0 ];
	if( 0 < boundHigh[ 0 ] )
	{
		indexWidthHigh += 1;
	}

	HSINT indexHeightLow = ( HSINT ) boundLow[ 1 ];
	if( boundLow[ 1 ] < 0 )
	{
		indexHeightLow -= 1;
	}

	HSINT indexHeightHigh = ( HSINT ) boundHigh[ 1 ];
	if( 0 < boundHigh[ 1 ] )
	{
		indexHeightHigh += 1;
	}

	const HVectorR2 sampleOffset = boundHigh - boundLow;
	const HREAL area = sampleOffset[ 0 ] * sampleOffset[ 1 ];
	if( HMathUtility::EpsilonZero( area ) )
	{
		//bail on small area
		return;
	}

	for( HSINT indexHeight = indexHeightLow; indexHeight < indexHeightHigh; ++indexHeight )
	{
		for( HSINT indexWidth = indexWidthLow; indexWidth < indexWidthHigh; ++indexWidth )
		{
			SampleBoundSrc( sum, in_src, HMatrixConstructor::HVectorS2Construct( indexWidth, indexHeight ), boundLow, boundHigh );
		}
	}

	{
		TColour::TVector normalisedSum;
		for( HSINT index = 0; index < IN_CHANNEL_COUNT; ++index )
		{ 
			normalisedSum[ index ] = ( IN_TYPE )( sum[ index ] / area );
		}

		out_colour.DataSet( normalisedSum );
	}

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::SampleBoundSrc( HREAL* in_out_sum, const TImage& in_src, const Hubris::HVectorS2& in_index, const HVectorR2& in_boundLow, const HVectorR2& in_boundHigh )
{
	HCOMMON_ASSERT( NULL != in_out_sum, "invalid param" );

	//sample 4 points, average colour, add to sum
	HVectorR2 points[4];
	TColour sample[4];

	const HREAL minX = HMathUtility::Maximum( ( HREAL ) in_index[ 0 ], in_boundLow[ 0 ] );
	const HREAL minY = HMathUtility::Maximum( ( HREAL ) in_index[ 1 ], in_boundLow[ 1 ] );
	const HREAL maxX = HMathUtility::Minimum( ( HREAL ) ( in_index[ 0 ] + 1 ), in_boundHigh[ 0 ] );
	const HREAL maxY = HMathUtility::Minimum( ( HREAL ) ( in_index[ 1 ] + 1 ), in_boundHigh[ 1 ] );

	SamplePoint( sample[ 0 ], in_src, HMatrixConstructor::HVectorR2Construct( minX, minY ) );
	SamplePoint( sample[ 1 ], in_src, HMatrixConstructor::HVectorR2Construct( maxX, minY ) );
	SamplePoint( sample[ 2 ], in_src, HMatrixConstructor::HVectorR2Construct( minX, maxY ) );
	SamplePoint( sample[ 3 ], in_src, HMatrixConstructor::HVectorR2Construct( maxX, maxY ) );

	const HREAL area = ( maxX - minX ) * ( maxY - minY );
	const HREAL mul = area / 4.0F;
	for( HSINT index = 0; index < IN_CHANNEL_COUNT; ++index )
	{
		HREAL value = 0.0F;
		value += ( HREAL ) sample[ 0 ].DataGet().operator[]( index );
		value += ( HREAL ) sample[ 1 ].DataGet().operator[]( index );
		value += ( HREAL ) sample[ 2 ].DataGet().operator[]( index );
		value += ( HREAL ) sample[ 3 ].DataGet().operator[]( index );

		in_out_sum[ index ] += ( value * mul );
	}

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::ClampedColourGet( TColour& out_colour, const TImage& in_src, const Hubris::HVectorS2& in_index )
{
	
	HVectorS2 safeIndex( in_index );
	const HVectorS2& size = in_src.SizeGet();

	//bail on zero size on any axis
	if( ( 0 == size[ 0 ] ) || ( 0 == size[ 1 ] ) )
	{
		return;
	}

	if( safeIndex[ 0 ] < 0 )
	{
		safeIndex[ 0 ] = 0;
	}
	else if( size[ 0 ] <= safeIndex[ 0 ] )
	{
		safeIndex[ 0 ] = size[ 0 ] - 1;
	}

	if( safeIndex[ 1 ] < 0 )
	{
		safeIndex[ 1 ] = 0;
	}
	else if( size[ 1 ] <= safeIndex[ 1 ] )
	{
		safeIndex[ 1 ] = size[ 1 ] - 1;
	}

	out_colour = in_src.ColourGet( safeIndex );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_CHANNEL_COUNT >
void Pride::PImageUtility< IN_TYPE, IN_CHANNEL_COUNT >::SamplePoint( TColour& out_colour, const TImage& in_src, const Hubris::HVectorR2& in_index )
{
	
	TColour sample[ 4 ];
	HVectorS2 index;
	HSINT widthOffset = 1;
	HSINT heightOffset = 1;

	index[ 0 ] = ( HSINT ) in_index[ 0 ];
	if( in_index[ 0 ] < 0 )
	{
		widthOffset = -1;
	}
	index[ 1 ] = ( HSINT ) in_index[ 1 ];
	if( in_index[ 1 ] < 0 )
	{
		heightOffset = -1;
	}

	ClampedColourGet( sample[ 0 ], in_src, index );
	ClampedColourGet( sample[ 1 ], in_src, index + HMatrixConstructor::HVectorS2Construct( widthOffset, 0 ) );
	ClampedColourGet( sample[ 2 ], in_src, index + HMatrixConstructor::HVectorS2Construct( 0, heightOffset ) );
	ClampedColourGet( sample[ 3 ], in_src, index + HMatrixConstructor::HVectorS2Construct( widthOffset, heightOffset ) );

	//	0 -- 1 if both positive, mirrored around axis
	//	|    |
	//	|    |
	//	2 -- 3

	HVectorR2 ratio( in_index );
	ratio[ 0 ] -= ( HREAL ) index[ 0 ];
	ratio[ 1 ] -= ( HREAL ) index[ 1 ];

	TColour subSample[ 2 ];
	subSample[ 0 ].DataSet( HMathUtility::Lerp( sample[ 0 ].DataGet(), sample[ 1 ].DataGet(), ratio[ 0 ] ) );
	subSample[ 1 ].DataSet( HMathUtility::Lerp( sample[ 2 ].DataGet(), sample[ 3 ].DataGet(), ratio[ 0 ] ) );

	out_colour.DataSet( HMathUtility::Lerp( subSample[ 0 ].DataGet(), subSample[ 1 ].DataGet(), ratio[ 1 ] ) );

	return;
}
