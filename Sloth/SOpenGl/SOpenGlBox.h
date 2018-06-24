//file: Sloth/SOpenGl/SOpenGlBox.h
#ifndef _S_OPEN_GL_BOX_H_
#define _S_OPEN_GL_BOX_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SOpenGlBox
	{
		///////////////////////////////////////////////////////
		// disabled
	public:
		~SOpenGlBox();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID DrawBox(
			const Pride::PBoundsR3& in_bounds
			);

	};

	/**/
	
};

#endif // _S_OPEN_GL_BOX_H_