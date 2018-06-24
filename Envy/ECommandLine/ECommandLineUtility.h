//file: Envy/ECommandLine/ECommandLineUtility.h
#ifndef _E_COMMAND_LINE_PARAM_UTILITY_H_
#define _E_COMMAND_LINE_PARAM_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainerArray.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Hubris
{
	class HString;
};

namespace Envy
{
	class ECommandLineParam;
};

///////////////////////////////////////////////////////
// struct
/**/
namespace Envy
{
	struct ECommandLineUtility
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< ECommandLineParam >TArrayParam;
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		///////////////////////////////////////////////////////
		// disabled
	private:
		~ECommandLineUtility();

		///////////////////////////////////////////////////////
		// static public methods
	public:
		//" [{-s,-source} foo.txt] /D out.txt /P PC"
		//"    {/S, /Source} [optional] source file name with relative or absolute path\n"
		static const Hubris::HString HelpTextGet(
			const Hubris::HString& in_startHelpText,
			const TArrayParam& in_arrayParam
			);

		static const TArrayString CommandLineToStringArray(
			const Hubris::HSINT in_argc,
			Hubris::HCHAR ** const in_argv
			);

	};

	/**/
};

/**/
#endif // _E_COMMAND_LINE_PARAM_UTILITY_H_