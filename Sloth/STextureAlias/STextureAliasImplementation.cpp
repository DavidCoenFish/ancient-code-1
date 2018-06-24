//file: Sloth/STextureAlias/STextureAliasImplementation.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/STextureAlias/STextureAliasImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

///////////////////////////////////////////////////////
// typedef
/**/
struct TFlag
{
	enum TEnum
	{
		TNone = 0x00,
		TNoResize = 0x01,
		TReleased = 0x02
	};
};

typedef Hubris::HSmartPointer< STextureAliasData >TDataPointer; 
typedef Hubris::HContainerArray< TDataPointer >TArrayDataPointer; 
typedef Hubris::HContainerArray< TArrayDataPointer >TArrayArrayDataPointer; 

///////////////////////////////////////////////////////
// static local variables
/**/
static const HSINT s_maxResizeFactor = 8;

///////////////////////////////////////////////////////
// static local methods
/*
	this only works on 0 <= size 
*/
static const HBOOL LocalCheckSizePowerTwo( const HSINT in_size )
{
	return( !( in_size & ( in_size - 1 ) ) );
}

/**/
static HVOID LocalBuckImage(
	TArrayArrayDataPointer& out_arrayArrayImages,
	TDataPointer& in_pointer,
	const HSINT in_size
	)
{
	const HSINT power = HCOMMON_LOWEST_BIT32( in_size );

	while( out_arrayArrayImages.SizeGet() <= power )
	{
		HContainerUtility::PushBack( out_arrayArrayImages, TArrayDataPointer() );
	}

	out_arrayArrayImages[ power ].Insert( in_pointer );

	return;
}

static const HSINT LocalCalculateResizeStep(
	const HSINT in_targetSize,
	const HSINT in_totalResizableSize,
	const HSINT in_totalNonResizableSize
	)
{
	if( ( in_totalResizableSize + in_totalNonResizableSize ) <= in_targetSize )
	{
		return 0;
	}

	for( HSINT index = 1; index < s_maxResizeFactor; ++index )
	{
		if( ( ( in_totalNonResizableSize >> ( index * 2 ) ) + in_totalNonResizableSize ) <= in_targetSize )
		{
			return index;
		}
	}

	return s_maxResizeFactor;
}

/**/
static HVOID LocalGatherData(
	TArrayArrayDataPointer& out_arrayResizeableImages,
	TArrayArrayDataPointer& out_arrayNonResizeableImages,
	HSINT& out_totalResizableSize,
	HSINT& out_totalNonResizableSize,
	TArrayDataPointer& in_arrayImages
	)
{
	out_arrayResizeableImages.Clear();
	out_arrayNonResizeableImages.Clear();
	out_totalResizableSize = 0;
	out_totalNonResizableSize = 0;

	HCOMMON_FOR_EACH( pointer, in_arrayImages, TArrayDataPointer )
	{
		const HSINT flag = pointer->FlagGet();
		if( TFlag::TReleased & flag )
		{
			continue;
		}

		HSINT size = pointer->ImageGet().SizeGet()[ 0 ];
		if( TFlag::TNoResize & flag )
		{
			out_totalNonResizableSize += ( size * size );
			LocalBuckImage(
				out_arrayNonResizeableImages,
				pointer,
				size
				);
		}
		else
		{
			out_totalResizableSize += ( size * size );
			LocalBuckImage(
				out_arrayResizeableImages,
				pointer,
				size
				);
		}
	}

	return;
}

/**/
static const Hubris::HBOOL LocalFindImage( 
	TDataPointer& out_dataPointer, 
	TArrayArrayDataPointer& in_arrayArrayImages, 
	const Hubris::HSINT in_width
	)
{
	while( 0 < in_arrayArrayImages.SizeGet() )
	{
		TArrayDataPointer& arrayPointer = HContainerUtility::Back( in_arrayArrayImages );
		if( arrayPointer.SizeGet() <= 0 )
		{
			HContainerUtility::PopBack( in_arrayArrayImages );
			continue;
		}

		TDataPointer& back = HContainerUtility::Back( arrayPointer );
		const HSINT testWidth = back->ImageGet().SizeGet()[ 0 ];
		if( in_width < testWidth )
		{
			HContainerUtility::PopBack( in_arrayArrayImages );
			continue;
		}

		if( in_width == testWidth )
		{
			out_dataPointer = back;
			HContainerUtility::PopBack( arrayPointer );
			return HTRUE;
		}

		break;
	}

	return HFALSE;
}

/**/
static const PColourRgba LocalSample(
	const Pride::PImageRgba& in_image,
	const HVectorS2& in_origin, 
	const Hubris::HSINT in_resizeStep
	)
{
	HVectorS4 data;
	const HSINT step = ( 1 << in_resizeStep );
	for( HSINT indexY = 0; indexY < step; ++indexY )
	{
		for( HSINT indexX = 0; indexX < step; ++indexX )
		{
			const PColourRgba colour = in_image.ColourGet(
				HMatrixConstructor::HVectorS2Construct( in_origin[ 0 ] + indexX, in_origin[ 1 ] + indexY )
				);

			data[ 0 ] += colour.RedGet();
			data[ 1 ] += colour.GreenGet();
			data[ 2 ] += colour.BlueGet();
			data[ 3 ] += colour.OpacityGet();
		}
	}

	PColourRgba returnColour;
	returnColour.RedSet( HU8( ( data[ 0 ] >> in_resizeStep ) & 0xFF ) );
	returnColour.GreenSet( HU8( ( data[ 1 ] >> in_resizeStep ) & 0xFF ) );
	returnColour.BlueSet( HU8( ( data[ 2 ] >> in_resizeStep ) & 0xFF ) );
	returnColour.OpacitySet( HU8( ( data[ 3 ] >> in_resizeStep ) & 0xFF ) );

	return returnColour;
}

/**/
static Hubris::HVOID LocalBlitImage(
	Pride::PImageRgba& out_image,
	TDataPointer& in_dataPointer,
	const Hubris::HSINT in_resizeStep,
	const HVectorS2& in_topLeft,
	const HVectorS2& in_bottomRight
	)
{
	const HVectorS2& drawArea = in_bottomRight - in_topLeft;

	const PImageRgba& image = in_dataPointer->ImageGet();
	const HVectorS2 size = image.SizeGet();
	const HSINT step = ( 1 << in_resizeStep );
	for( HSINT indexY = 0; indexY < drawArea[ 1 ]; ++indexY )
	{
		for( HSINT indexX = 0; indexX < drawArea[ 0 ]; ++indexX )
		{
			const PColourRgba colour = LocalSample(
				image,
				HMatrixConstructor::HVectorS2Construct( indexX * step, indexY * step ),
				in_resizeStep
				);

			out_image.ColourSet( 
				HMatrixConstructor::HVectorS2Construct( in_topLeft[ 0 ] + indexX, in_topLeft[ 1 ] + indexY ),
				colour
				);
		}
	}

	//TODO:
	HMatrixR4 matrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	const HREAL masterWidth = ( HREAL )( out_image.SizeGet().operator []( 0 ) );
	const HREAL scale = ( HREAL )( size[ 0 ] ) / masterWidth;
	const HREAL offsetX = ( HREAL )( in_topLeft[ 0 ] ) / masterWidth;
	const HREAL offsetY = ( HREAL )( in_topLeft[ 1 ] ) / masterWidth;

	matrix[ HMatrixR4::IndexGet( 0, 0 ) ] = scale;
	matrix[ HMatrixR4::IndexGet( 1, 1 ) ] = scale;
	matrix[ HMatrixR4::IndexGet( 2, 2 ) ] = scale;
	HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( 
		matrix, 
		HMatrixConstructor::HVectorR3Construct( offsetX, offsetY, 0.0F ) 
		);

	in_dataPointer->TransformSet(
		matrix
		);

	return;
}

/**/
static const Hubris::HBOOL LocalWriteImage(
	Pride::PImageRgba& out_image,
	TArrayArrayDataPointer& in_arrayResizeableImages,
	TArrayArrayDataPointer& in_arrayNonResizeableImages,
	const Hubris::HSINT in_resizeStep,
	const HVectorS2& in_topLeft, //with 0, 0 being top left
	const HVectorS2& in_bottomRight //with +x, +y being bottom right
	)
{
	const HSINT width = in_bottomRight[ 0 ] - in_topLeft[ 0 ];
	TDataPointer dataPointer;
	HSINT localResizeStep = 0;
	if( HFALSE == LocalFindImage( dataPointer, in_arrayNonResizeableImages, width ) )
	{
		if( HFALSE == LocalFindImage( dataPointer, in_arrayResizeableImages, width << in_resizeStep ) )
		{
			//nothin this size
			return HFALSE;
		}
		else
		{
			localResizeStep = in_resizeStep;
		}
	}

	//write image
	LocalBlitImage(
		out_image,
		dataPointer,
		localResizeStep,
		in_topLeft,
		in_bottomRight
		);

	return HTRUE;
}


/**/
static HVOID LocalFillTextureAlias(
	Pride::PImageRgba& out_image,
	TArrayArrayDataPointer& in_arrayResizeableImages,
	TArrayArrayDataPointer& in_arrayNonResizeableImages,
	const Hubris::HSINT in_resizeStep,
	const HVectorS2& in_topLeft, //with 0, 0 being top left
	const HVectorS2& in_bottomRight //with +x, +y being bottom right
	)
{
	if( ( in_arrayResizeableImages.SizeGet() == 0 ) &&
		( in_arrayNonResizeableImages.SizeGet() == 0 ) )
	{
		return;
	}

	if( HTRUE == LocalWriteImage(
		out_image,
		in_arrayResizeableImages,
		in_arrayNonResizeableImages,
		in_resizeStep,
		in_topLeft,
		in_bottomRight
		) )
	{
		return;
	}

	//recurse
	const HSINT width = in_bottomRight[ 0 ] - in_topLeft[ 0 ];
	if( width <= 1 )
	{
		return;
	}

	const HSINT step = width >> 1;

	LocalFillTextureAlias(
		out_image,
		in_arrayResizeableImages,
		in_arrayNonResizeableImages,
		in_resizeStep,
		HMatrixConstructor::HVectorS2Construct( in_topLeft[ 0 ], in_topLeft[ 1 ] ),
		HMatrixConstructor::HVectorS2Construct( in_bottomRight[ 0 ] - step, in_bottomRight[ 1 ] - step )
		);
	LocalFillTextureAlias(
		out_image,
		in_arrayResizeableImages,
		in_arrayNonResizeableImages,
		in_resizeStep,
		HMatrixConstructor::HVectorS2Construct( in_topLeft[ 0 ] + step, in_topLeft[ 1 ] ),
		HMatrixConstructor::HVectorS2Construct( in_bottomRight[ 0 ], in_bottomRight[ 1 ] - step )
		);
	LocalFillTextureAlias(
		out_image,
		in_arrayResizeableImages,
		in_arrayNonResizeableImages,
		in_resizeStep,
		HMatrixConstructor::HVectorS2Construct( in_topLeft[ 0 ], in_topLeft[ 1 ] + step ),
		HMatrixConstructor::HVectorS2Construct( in_bottomRight[ 0 ] - step, in_bottomRight[ 1 ] )
		);
	LocalFillTextureAlias(
		out_image,
		in_arrayResizeableImages,
		in_arrayNonResizeableImages,
		in_resizeStep,
		HMatrixConstructor::HVectorS2Construct( in_topLeft[ 0 ] + step, in_topLeft[ 1 ] + step ),
		HMatrixConstructor::HVectorS2Construct( in_bottomRight[ 0 ], in_bottomRight[ 1 ] )
		);

	return;
}

///////////////////////////////////////////////////////
// creation
/**/
STextureAliasImplementation::STextureAliasImplementation()
: m_image()
, m_arrayImages()
, m_lowestReleasedIndex( HCOMMON_INVALID_INDEX )
{
	return;
}

/**/
STextureAliasImplementation::~STextureAliasImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT STextureAliasImplementation::TextureAdd( 
	const Pride::PImageRgba& in_image,
	const Hubris::HSINT in_flag
	)
{
	HCOMMON_ASSERT( ( 0 < in_image.SizeGet()[ 0 ] ) &&
		( HTRUE == LocalCheckSizePowerTwo( in_image.SizeGet()[ 0 ] ) ), "invalid param" );

	TDataPointer pointer;
	pointer.Create();
	pointer->ImageSet( in_image );
	pointer->FlagSet( in_flag );
	if( HCOMMON_INVALID_INDEX == m_lowestReleasedIndex )
	{
		const HSINT returnIndex = HContainerUtility::PushBack( m_arrayImages, pointer );
		return returnIndex;
	}

	const HSINT returnIndex = m_lowestReleasedIndex;
	m_arrayImages[ returnIndex ] = pointer;
	m_lowestReleasedIndex += 1;
	
	//find the next lowest release index
	while( m_lowestReleasedIndex < m_arrayImages.SizeGet() )
	{
		if( TFlag::TReleased & m_arrayImages[ m_lowestReleasedIndex ]->FlagGet() )
		{
			return returnIndex;
		}
		m_lowestReleasedIndex += 1;
	}

	m_lowestReleasedIndex = HCOMMON_INVALID_INDEX;

	return returnIndex;
}

/**/
Hubris::HVOID STextureAliasImplementation::TextureRemove(
	const Hubris::HSINT in_textureIndex
	)
{
	m_arrayImages[ in_textureIndex ]->FlagSet( TFlag::TReleased | m_arrayImages[ in_textureIndex ]->FlagGet() );
	if( ( HCOMMON_INVALID_INDEX == m_lowestReleasedIndex ) ||
		( in_textureIndex < m_lowestReleasedIndex ) )
	{
		m_lowestReleasedIndex = in_textureIndex;
	}
	return;
}

/**/
Hubris::HVOID STextureAliasImplementation::GenerateTextureAlias(
	const Hubris::HVectorS2& in_size
	)
{
	HCOMMON_ASSERT( ( 0 < in_size[ 0 ] ) && ( in_size[ 0 ] == in_size[ 1 ] ), "invalid param" );
	const HSINT targetSize = in_size[ 0 ] * in_size[ 1 ];

	TArrayArrayDataPointer arrayResizeableImages;
	TArrayArrayDataPointer arrayNonResizeableImages;
	HSINT totalResizableSize = 0;
	HSINT totalNonResizableSize = 0;

	LocalGatherData(
		arrayResizeableImages,
		arrayNonResizeableImages,
		totalResizableSize,
		totalNonResizableSize,
		m_arrayImages
		);

	const HSINT resizeStep = LocalCalculateResizeStep(
		targetSize,
		totalResizableSize,
		totalNonResizableSize
		);

	m_image.SizeSet( in_size );

	LocalFillTextureAlias(
		m_image,
		arrayNonResizeableImages,
		arrayResizeableImages,
		resizeStep,
		HMatrixConstructor::HVectorS2Construct( 0, 0 ),
		in_size
		);

	return;
}

/**/
Hubris::HVOID STextureAliasImplementation::TextureMatrixGet(
	Hubris::HMatrixR4& out_matrix,
	const Hubris::HSINT in_textureIndex
	)const
{
	out_matrix = m_arrayImages[ in_textureIndex ]->TransformGet();

	//in_textureIndex;
	//out_matrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
	//HMatrixUtility::TranslateSet( out_matrix, HMatrixConstructor::HVectorR3Construct( .05F, 0.6F, 0.7F ) );

	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT STextureAliasImplementation::FlagNoResize()
{
	return( TFlag::TNoResize );
}
/**/
