//file: Greed/GComponent/GComponentRotation.h
#ifndef _G_COMPONENT_ROTATION_H_
#define _G_COMPONENT_ROTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GComponent;

	///////////////////////////////////////////////////////
	// class
	/**/
	class GComponentRotation
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentRotation( const GComponentRotation& in_src );
		GComponentRotation();
		~GComponentRotation();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GComponentRotation& operator=( const GComponentRotation& in_rhs );
		const Hubris::HBOOL operator==( const GComponentRotation& in_rhs )const;
		const Hubris::HBOOL operator!=( const GComponentRotation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/
	
};

#endif // _G_COMPONENT_ROTATION_H_