//file: Greed/GComponent/GComponentTranslation.h
#ifndef _G_COMPONENT_TRANSLATION_H_
#define _G_COMPONENT_TRANSLATION_H_

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
	class GComponentTranslation
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		GComponentTranslation( const GComponentTranslation& in_src );
		GComponentTranslation();
		~GComponentTranslation();

		///////////////////////////////////////////////////////
		// operator
	public:
		const GComponentTranslation& operator=( const GComponentTranslation& in_rhs );
		const Hubris::HBOOL operator==( const GComponentTranslation& in_rhs )const;
		const Hubris::HBOOL operator!=( const GComponentTranslation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR3 m_translation;

	};

	/**/
	
};

#endif // _G_COMPONENT_TRANSLATION_H_