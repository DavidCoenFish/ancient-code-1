//file: Envy/EStringTable/EStringTableImplementation.h
#ifndef _E_STRING_TABLE_IMPLEMENTAION_H_
#define _E_STRING_TABLE_IMPLEMENTAION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations

	/////////////////////////////////////////////////////////////////
	// class

	/**/
	class EStringTableImplementation
	{
		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerTree< Hubris::HString, Hubris::HSINT >TTreeStringSint;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EStringTableImplementation( const EStringTableImplementation& in_src );
		EStringTableImplementation();
		~EStringTableImplementation();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EStringTableImplementation& operator=( const EStringTableImplementation& in_rhs );
		const Hubris::HBOOL operator==( const EStringTableImplementation& in_rhs )const;
		const Hubris::HBOOL operator!=( const EStringTableImplementation& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT StringAdd( const Hubris::HString& in_string );

		Hubris::HVOID StringIndexAdd( const Hubris::HString& in_string, const Hubris::HSINT in_index );

		//return HCOMMON_INVALID_INDEX is string not found
		const Hubris::HSINT StringFind( const Hubris::HString& in_string )const;

		const Hubris::HString& StringGet( const Hubris::HSINT in_index )const;
		const Hubris::HSINT StringCountGet()const;

		/////////////////////////////////////////////////////////////////
		// public accessor
	public:
		const TTreeStringSint& TreeStringIndexGet()const{ return m_treeStringIndex; }
		TTreeStringSint& TreeStringIndexGet(){ return m_treeStringIndex; }

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TArrayString m_arrayString;
		TTreeStringSint m_treeStringIndex;

	};

	/**/
};

#endif // _E_STRING_TABLE_IMPLEMENTAION_H_
