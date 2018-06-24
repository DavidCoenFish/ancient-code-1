//file: Envy/EJana/EJanaManager.h
#ifndef _E_JANA_MANAGER_H_
#define _E_JANA_MANAGER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Envy/EJana/EJana.h"

namespace Hubris
{
	class HFileSystem;
	class HFileSystemPath;
};

namespace Envy
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	class EJanaManagerImplementation;

	/////////////////////////////////////////////////////////////////
	// class

	/*
		look after loading and updating Jana documents (Jana is a Tanya document that supports inheritance from named documents )
	*/
	class EJanaManager
	{
		/////////////////////////////////////////////////////////////////
		// creation
	public:
		EJanaManager( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_basePath, const Hubris::HString& in_extentionText, const Hubris::HString& in_extentionBinary  );
		EJanaManager( const EJanaManager& in_src );
		~EJanaManager();

		/////////////////////////////////////////////////////////////////
		// operators
	public:
		const EJanaManager& operator=( const EJanaManager& in_rhs );
		Hubris::HBOOL operator==( const EJanaManager& in_rhs )const;
		Hubris::HBOOL operator!=( const EJanaManager& in_rhs )const;

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
		// private members
	private:
		EJanaManagerImplementation* m_pImplementation;

	};
};

#endif // _E_JANA_MANAGER_H_