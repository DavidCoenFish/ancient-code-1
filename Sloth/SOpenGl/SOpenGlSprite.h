//file: Sloth/SOpenGl/SOpenGlSprite.h
#ifndef _S_OPEN_GL_SPRITE_H_
#define _S_OPEN_GL_SPRITE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SOpenGlSprite
	{
		///////////////////////////////////////////////////////
		// disabled
	public:
		~SOpenGlSprite();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID DrawSprite(
			const Hubris::HSINT in_spriteIndex
			);
		static const Hubris::HSINT SpriteCreate(
			const Hubris::HVectorR2& in_size,
			const Hubris::HVectorR2& in_topLeftUv,
			const Hubris::HVectorR2& in_bottomRightUv,
			const Pride::PColourRealRgba& in_colour
			);
		static Hubris::HVOID SpriteRelease(
			const Hubris::HSINT in_spriteIndex
			);

	};

	/**/
	
};

#endif // _S_OPEN_GL_SPRITE_H_