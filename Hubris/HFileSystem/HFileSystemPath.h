//file: Hubris/HFileSystem/HFileSystemPath.h
#ifndef _H_FILE_SYSTEM_PATH_H_
#define _H_FILE_SYSTEM_PATH_H_

#include "Hubris/HCommon/HCommonType.h"

/*
	file path as object, wrapper to avoid component having dependance
*/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HFileSystem;
	class HFileSystemPathImplement;
	class HString;
	template< typename IN_TYPE > class HContainerArray;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HFileSystemPath
	{
		friend HFileSystem;

		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HContainerArray< HString >TArrayString;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HFileSystemPath( const HFileSystemPath& in_src );
		HFileSystemPath( const HString& in_src );
		HFileSystemPath( const HCHAR* const in_src );
		HFileSystemPath();
		~HFileSystemPath();

		///////////////////////////////////////////////////////////
		// operators
	public:
		const HFileSystemPath& operator=( const HFileSystemPath& in_rhs );
		const HBOOL operator==( const HFileSystemPath& in_rhs )const;
		const HBOOL operator!=( const HFileSystemPath& in_rhs )const;
		const HBOOL operator<( const HFileSystemPath& in_rhs )const;

		HFileSystemPath operator+( const HFileSystemPath& in_rhs ) const;
		HFileSystemPath& operator+=( const HFileSystemPath& in_rhs );

		////////////////////////////////////////
		// public methods
	public:
		//get path, file name, extention
		const HString PathFileNameExtentionGet()const;
		HVOID PathFileNameExtentionSet( const HString& in_pathFileNameExtention );

		//get path, no file name
		const HString PathOnlyGet()const;
		//return in_path with drive and folders consumed, 
		//WARNING: end leaf MUST END with a folder specifier else will be ignored as a file name
		const HString PathOnlySet( const HString& in_path );

		//get the file name with extention
		const HString FileNameExtentionOnlyGet()const;
		HVOID FileNameExtentionOnlySet( const HString& in_fileNameExtention );

		////////////////////////////////////////
		// public accessors
	public:
		const HString DriveGet()const;
		//consume the input string up till drive specifier char, return data without drive, clear drive if no drive found
		const HString DriveSet( const HString& in_data );

		HSINT FolderCountGet()const;
		const HString FolderGet( const HSINT in_index )const;
		HVOID FolderSet( const HSINT in_index, const HString& in_folder );

		//consume the input string up till folder specifier char, return data without that folder, 
		//NOP on no folder found, return string same as input string
		// WARNING, use FolderPush if you want to put another folder onto the path, FolderAdd is for appending/ consuming a path string
		const HString FolderAdd( const HString& in_data );

		const HString FolderBack()const;
		//do not decorate foler with special char, like '\\'
		HVOID FolderPush( const HString& in_folder );
		HVOID FolderPop();

		const HString FileNameGet()const;
		//consume the input string up till last extention specifier char, return data without that file name
		//assumes path and '\\' removed
		const HString FileNameSet( const HString& in_data );

		const HString ExtentionGet()const;
		//assumes leadin file name and '.' removed
		HVOID ExtentionSet( const HString& in_extention );

		///////////////////////////////////////////////////////////
		// private accessors
	private:
		const HFileSystemPathImplement& ImplementGet()const;
		HFileSystemPathImplement& ImplementGet();

		///////////////////////////////////////////////////////////
		// private members
	private:
		HFileSystemPathImplement* m_pImplement;

	};

	/**/
};

#endif// _H_FILE_SYSTEM_H_
