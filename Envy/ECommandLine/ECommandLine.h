//file: Envy/ECommandLine/ECommandLine.h
#ifndef _E_COMMAND_LINE_H_
#define _E_COMMAND_LINE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >

///////////////////////////////////////////////////////
// forward declair
/**/
namespace Envy
{
	class ECommandLineParam;
};

///////////////////////////////////////////////////////
// class
/**/
namespace Envy
{
	/*
	  help deal with reading of command line param
	*/
	class ECommandLine
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
		typedef Hubris::HContainerArray< ECommandLineParam >TArrayParam;
		typedef Hubris::HContainerTree< Hubris::HString, TArrayString >TTreeStingArrayString;

		///////////////////////////////////////////////////////
		// creation
	public:
		ECommandLine( 
			const Hubris::HBOOL in_keyCaseInsensitive,
			const TArrayParam& in_arrayParam,
			const TArrayString& in_arrayCommandLine
			);
		~ECommandLine();

		///////////////////////////////////////////////////////
		// disabled
	private:
		ECommandLine( const ECommandLine& in_src );
		const ECommandLine& operator=( const ECommandLine& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HBOOL KeyTest( const Hubris::HString& in_key )const;
		const TArrayString& KeyGet( const Hubris::HString& in_key )const;

		const Hubris::HBOOL ValidGet()const{ return m_valid; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HBOOL m_valid; //all keys with a minimum of 
		TTreeStingArrayString m_treeData;

	};


	/**/
};

#endif // _E_COMMAND_LINE_H_