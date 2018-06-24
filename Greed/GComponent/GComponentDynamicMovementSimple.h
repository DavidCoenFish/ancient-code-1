//file: Greed/GComponent/GComponentDynamicMovementSimple.h
#ifndef _G_COMPONENT_DYNAMIC_MOVEMENT_SIMPLE_H_
#define _G_COMPONENT_DYNAMIC_MOVEMENT_SIMPLE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Greed
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class GComponent;

	///////////////////////////////////////////////////////
	// class
	/*
		component to help deal with simple dynamic movement of an object
		ment to otranslate movement of sphere with velocity through static collision world

	*/
	class GComponentDynamicMovementSimple
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentDynamicMovementSimple( const GComponentDynamicMovementSimple& in_src );
		GComponentDynamicMovementSimple();
		~GComponentDynamicMovementSimple();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GComponentDynamicMovementSimple& operator=( const GComponentDynamicMovementSimple& in_rhs );
		const Hubris::HBOOL operator==( const GComponentDynamicMovementSimple& in_rhs )const;
		const Hubris::HBOOL operator!=( const GComponentDynamicMovementSimple& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/
	
};

#endif // _G_COMPONENT_DYNAMIC_MOVEMENT_SIMPLE_H_