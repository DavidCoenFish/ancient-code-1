//file: Sloth/SOpenGl/SOpenGlSphere.h
#ifndef _S_OPEN_GL_SPHERE_H_
#define _S_OPEN_GL_SPHERE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SOpenGlSphere
	{
		///////////////////////////////////////////////////////
		// disabled
	public:
		~SOpenGlSphere();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID DrawSphere(
			const Hubris::HREAL in_radius,
			const Hubris::HSINT in_sphereDisplayList
			);

	};

	/**/
	
};

#endif // _S_OPEN_GL_SPHERE_H_