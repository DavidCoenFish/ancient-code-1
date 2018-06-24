//file: Envy/ECommandLine/ECommandLineParam.h
#ifndef _E_COMMAND_LINE_PARAM_H_
#define _E_COMMAND_LINE_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainerArray.h >
#include< Hubris/HString/HString.h >

///////////////////////////////////////////////////////
// class
/*
	min number, 
		0 param not needed
		1 must be present for param line to be valid
	followingKeyCount number
		0 param consumes no trailing strings
		1 param consumes one trailing keys
		..more than one, todo
*/
namespace Envy
{
	class ECommandLineParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HString >TArrayString;

		//////////////////////////////////////////////
		// creation
	public:
		ECommandLineParam( const ECommandLineParam& in_src );
		ECommandLineParam( 
			const TArrayString& in_arrayCommandLineKey,
			const Hubris::HString& in_targetKey,
			const Hubris::HString& in_helpText,
			const Hubris::HSINT in_minCount,
			const Hubris::HSINT in_followingKeyCount
			); 
		ECommandLineParam( 
			const Hubris::HString& in_commandLineKey,
			const Hubris::HString& in_targetKey,
			const Hubris::HString& in_helpText,
			const Hubris::HSINT in_minCount,
			const Hubris::HSINT in_followingKeyCount
			); 
		ECommandLineParam();
		~ECommandLineParam();

		///////////////////////////////////////////////////////
		// operators
	public:
		const ECommandLineParam& operator=( const ECommandLineParam& in_rhs );
		Hubris::HBOOL operator==( const ECommandLineParam& in_rhs )const;
		Hubris::HBOOL operator!=( const ECommandLineParam& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArrayString& ArrayCommandLineKeyGet()const{ return m_arrayCommandLineKey; }
		const Hubris::HString& TargetKeyGet()const{ return m_targetKey; }
		const Hubris::HString& HelpTextGet()const{ return m_helpText; }
		const Hubris::HSINT MinCountGet()const{ return m_minCount; }
		const Hubris::HSINT FollowingKeyCountGet()const{ return m_followingKeyCount; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayString m_arrayCommandLineKey;
		Hubris::HString m_targetKey; //the key we put the result into
		Hubris::HString m_helpText;
		Hubris::HSINT m_minCount;
		Hubris::HSINT m_followingKeyCount;

	};

	/**/
};

/**/
#endif // _E_COMMAND_LINE_PARAM_H_