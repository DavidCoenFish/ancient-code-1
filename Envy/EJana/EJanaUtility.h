//file: Envy/EJana/EJanaUtility.h
#ifndef _E_JANA_UTILITY_H_
#define _E_JANA_UTILITY_H_

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

	/////////////////////////////////////////////////////////////////
	// struct
	/**/
	struct EJanaUtility
	{
		/////////////////////////////////////////////////////////////////
		// public methods
	public:
		static Hubris::HBOOL Load( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, EJana& out_document );
		static Hubris::HBOOL SaveText( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EJana& in_document );
		static Hubris::HBOOL SaveBinary( Hubris::HFileSystem& in_fileSystem, const Hubris::HFileSystemPath& in_filePath, const EJana& in_document );

		static Hubris::HVOID ParentSet( EJana& in_document, const Hubris::HString& in_parentName, const Hubris::HString& in_fileName );
		static Hubris::HBOOL ParentGet( const EJana& in_document, Hubris::HString& out_parentName, Hubris::HString& out_fileName );
		static Hubris::HVOID ParentRemove( ETanya& in_out_tanya );

		static Hubris::HVOID DerrivableNameSet( EJana& in_document, const Hubris::HString& in_derrivableName );
		static Hubris::HBOOL DerrivableNameGet( const EJana& in_document, Hubris::HString& out_derrivableName );
		static Hubris::HVOID DerrivableRemove( ETanya& in_out_tanya );

		/////////////////////////////////////////////////////////////////
		// disabled
	private:
		~EJanaUtility();

	};
};

#endif // _E_JANA_UTILITY_H_