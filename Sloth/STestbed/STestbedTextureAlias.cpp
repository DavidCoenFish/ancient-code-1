//file: Sloth/STestbed/STestbedTextureAlias.cpp

#include "Sloth/STestbed/STestbedTextureAlias.h"

///////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

//////////////////////////////////////////////////
// typedef
/**/

//////////////////////////////////////////////////
// local free functions
/**/
static HVOID LocalGenerateTexture(
	PImageRgba& out_image,
	const HSINT in_size,
	const HSINT in_maskRed = 0,
	const HSINT in_maskGreen = 0,
	const HSINT in_maskBlue = 0,
	const HSINT in_maskAlpha = 0
	)
{
	out_image.SizeSet( HMatrixConstructor::HVectorS2Construct( in_size, in_size ) );
	for( HSINT indexY = 0; indexY < in_size; ++indexY )
	{
		for( HSINT indexX = 0; indexX < in_size; ++indexX )
		{
			const PColourRgba colour( 
				( HU8 )( indexY & 0xFF & ( ~in_maskRed ) ),
				( HU8 )( indexX & 0xFF & ( ~in_maskGreen ) ),
				( HU8 )( ( -indexY ) & 0xFF & ( ~in_maskBlue ) ),
				( HU8 )( ( -indexX ) & 0xFF & ( ~in_maskAlpha ) ) );

			out_image.ColourSet(
				HMatrixConstructor::HVectorS2Construct( indexX, indexY ),
				colour
				);
		}
	}

	return;
}

/**/
static const HBOOL LocalTestbedTextureAlias()
{
	HBOOL success = HTRUE;

	STextureAlias textureAlias;

	{
		PImageRgba image;
		LocalGenerateTexture( image, 128 );
		textureAlias.TextureAdd( 
			image,
			STextureAlias::FlagNoResize()
			);
	}
	{
		PImageRgba image;
		LocalGenerateTexture( image, 128, 0xFF, 0, 0, 0xFF );
		textureAlias.TextureAdd( image );
		textureAlias.TextureAdd( image );
		textureAlias.TextureAdd( image );
	}
	{
		PImageRgba image;
		LocalGenerateTexture( image, 64, 0, 0xFF, 0xFF );
		textureAlias.TextureAdd( image );
		textureAlias.TextureAdd( image );
		textureAlias.TextureAdd( image );
	}

	textureAlias.GenerateTextureAlias( HMatrixConstructor::HVectorS2Construct( 256, 256 ) );

	HBuffer buffer;
	PImageTga::BufferTgaSave( buffer, textureAlias.ImageGet() );
	HFileSystem fileSystem;
	fileSystem.FileSave( "data//test.tga", buffer );

	STESTBED_VALIDATE_STATUS( "STextureAlias", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedTextureAlias()
{
	STESTBED_VALIDATE_START( "TestbedTextureAlias" );

	HBOOL success = HTRUE;

	success &= LocalTestbedTextureAlias();

	return success;
}

/**/