//file: Envy/EJana/EJanaManagerImplementation.h
#ifndef _E_JANA_MANAGER_IMPLEMENTATION_H_
#define _E_JANA_MANAGER_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EJana/EJana.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HFileSystem/HFileSystem_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations

	/////////////////////////////////////////////////////////////////
	// class

	/*
		look after loading and updating Jana documents (Jana is a Tanya document that supports inheritance from named documents )
	*/
	class EJanaManagerImplementation
	{
		/////////////////////////////////////////////////////////////////
		// typedefs
	private:
		typedef Hubris::HContainerPair< Hubris::HFileSystemPath, EJana >TPathJanaPair;
		typedef Hubris::HContainerTree< Hubris::HString, TPathJanaPair >TNamePathJanaMap;

		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EJanaManagerImplementation( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  );
		EJanaManagerImplementation( const EJanaManagerImplementation& in_src );
		~EJanaManagerImplementation();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EJanaManagerImplementation& operator=( const EJanaManagerImplementation& in_rhs );
		Hubris::HBOOL operator==( const EJanaManagerImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const EJanaManagerImplementation& in_rhs )const;

		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		//flatten a Jana document to a tanya document, uses the documents found from initialised base path to define parents, return false on error
		Hubris::HBOOL JanaToTanya( const EJana& in_jana, ETanya& out_tanya );

		//load a jana document, return false on error
		Hubris::HBOOL JanaGet( const Hubris::HString& in_fileName, EJana& out_jana );

		//get the count of files found from base path
		Hubris::HSINT FileCountGet()const;
		//get the name of a found file
		const Hubris::HString& FileNameGet( const Hubris::HSINT in_index )const;

		/////////////////////////////////////////////////////////////////
		// private methods
	private:
		//use object scope rather than Initialise and Release methods, 
		//void Initialise( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  );
		//void Release();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		TNamePathJanaMap m_namePathJanaMap;

	};
};

#endif // _E_JANA_MANAGER_IMPLEMENTATION_H_