//file: Sloth/STextureAlias/STextureAlias.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/STextureAlias/STextureAlias.h"

#include "Sloth/STextureAlias/STextureAliasImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

///////////////////////////////////////////////////////
// creation
/**/
STextureAlias::STextureAlias()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, STextureAliasImplementation );
	return;
}

/**/
STextureAlias::~STextureAlias()
{
	HCOMMON_DELETE( m_pImplementation, STextureAliasImplementation );
	return;
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HSINT STextureAlias::TextureAdd( 
	const Pride::PImageRgba& in_image,
	const Hubris::HSINT in_flag
	)
{
	const HSINT textureIndex = ImplementationGet().TextureAdd(
		in_image,
		in_flag
		);
	return textureIndex;
}

/**/
Hubris::HVOID STextureAlias::TextureRemove(
	const Hubris::HSINT in_textureIndex
	)
{
	ImplementationGet().TextureRemove(
		in_textureIndex
		);
	return;
}

/**/
Hubris::HVOID STextureAlias::GenerateTextureAlias(
	const Hubris::HVectorS2& in_size
	)
{
	ImplementationGet().GenerateTextureAlias(
		in_size
		);
	return;
}

/**/
const Pride::PImageRgba& STextureAlias::ImageGet()const
{
	const Pride::PImageRgba& returnImage = ImplementationGet().ImageGet();
	return returnImage;
}

/**/
Hubris::HVOID STextureAlias::TextureMatrixGet(
	Hubris::HMatrixR4& out_matrix,
	const Hubris::HSINT in_textureIndex
	)const
{
	ImplementationGet().TextureMatrixGet(
		out_matrix,
		in_textureIndex
		);
	return;
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT STextureAlias::FlagNoResize()
{
	return( STextureAliasImplementation::FlagNoResize() );
}

///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HBOOL STextureAlias::TextureAliasValidGet()const
{
	const HBOOL valid = ImplementationGet().TextureAliasValidGet();
	return valid;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const STextureAliasImplementation& STextureAlias::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
STextureAliasImplementation& STextureAlias::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/