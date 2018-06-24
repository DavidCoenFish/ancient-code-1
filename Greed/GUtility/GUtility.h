//file: Greed/GUtility/GUtility.h
#ifndef _G_UTILITY_H_
#define _G_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	class VScene;
};

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct GUtility
	{
		///////////////////////////////////////////////////////
		// public methods
	public:
		static Hubris::HVOID RegisterGameObjectFactory(
			Vanity::VScene& in_outscene
			);

		///////////////////////////////////////////////////////
		// disabled
	private:
		~GUtility();

	};

	/**/
	
};

#endif // _G_UTILITY_H_