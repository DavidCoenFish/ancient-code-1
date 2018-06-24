//file: Sloth/SOpenGl/SOpenGlSprite.cpp

#include "Sloth/SlothPreCompileHeader.h"
#include "Sloth/SOpenGl/SOpenGlSprite.h"

#include< windows.h >
#include< gl/gl.h >
#include< gl/glu.h >
#include< OpenGl/glext.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// local static variables
/**/

///////////////////////////////////////////////////////
// static public methods
/**/
Hubris::HVOID SOpenGlSprite::DrawSprite(
	const Hubris::HSINT in_spriteIndex
	)
{
	glCallList( in_spriteIndex );

	return;
}

/**/
const Hubris::HSINT SOpenGlSprite::SpriteCreate(
	const Hubris::HVectorR2& in_size,
	const Hubris::HVectorR2& in_topLeftUv,
	const Hubris::HVectorR2& in_bottomRightUv,
	const Pride::PColourRealRgba& in_colour
	)
{
	const HSINT displayListIndex = glGenLists( 1 );
	if( 0 == displayListIndex )
	{
		return HCOMMON_INVALID_INDEX;
	}

	glNewList( displayListIndex, GL_COMPILE );

	glBegin( GL_TRIANGLE_STRIP );

	glColor4f( in_colour.RedGet(), in_colour.GreenGet(), in_colour.BlueGet(), in_colour.OpacityGet() );

	//      +y
	//       ^
	//       |
	// topLeft
	//   1 ----- 0
	//   | \     |
	//   |   \   |  +x->
	//   |     \ |
	//   3 ----- 2 
	//            bottomRight
	//

	//0
	glTexCoord2f( in_bottomRightUv[ 0 ], in_topLeftUv[ 1 ] );
	glVertex3f( ( in_size[ 0 ] ), ( in_size[ 1 ] ), 0.0F );

	//1
	glTexCoord2f( in_topLeftUv[ 0 ], in_topLeftUv[ 1 ] );
	glVertex3f( -( in_size[ 0 ] ), ( in_size[ 1 ] ), 0.0F );

	//2
	glTexCoord2f( in_bottomRightUv[ 0 ], in_bottomRightUv[ 1 ] );
	glVertex3f( ( in_size[ 0 ] ), -( in_size[ 1 ] ), 0.0F );

	//3
	glTexCoord2f( in_topLeftUv[ 0 ], in_bottomRightUv[ 1 ] );
	glVertex3f( -( in_size[ 0 ] ), -( in_size[ 1 ] ), 0.0F );

	glEnd();

	glEndList();

	return displayListIndex;
}

/**/
Hubris::HVOID SOpenGlSprite::SpriteRelease(
	const Hubris::HSINT in_spriteIndex
	)
{
	glDeleteLists( in_spriteIndex, 1 );
	return;
}

/**/