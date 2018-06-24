//file: Greed/GComponent/GComponentPlayerInput.h
#ifndef _G_COMPONENT_PLAYER_INPUT_H_
#define _G_COMPONENT_PLAYER_INPUT_H_

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
	class GComponentPlayerInput
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentPlayerInput( const GComponentPlayerInput& in_src );
		GComponentPlayerInput();
		~GComponentPlayerInput();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GComponentPlayerInput& operator=( const GComponentPlayerInput& in_rhs );
		const Hubris::HBOOL operator==( const GComponentPlayerInput& in_rhs )const;
		const Hubris::HBOOL operator!=( const GComponentPlayerInput& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/
	
};

#endif // _G_COMPONENT_PLAYER_INPUT_H_