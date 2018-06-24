//file: Hubris/HFileSystem/HFileSystemPathImplement.h
#ifndef _H_FILE_SYSTEM_PATH_IMPLEMENT_H_
#define _H_FILE_SYSTEM_PATH_IMPLEMENT_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HString/HString.h"

/*
	file path as object
*/
namespace Hubris
{
	////////////////////////////////////////
	// class
	/*
	policy.
		returning data by value rather than reference, 
		  bad for speed but doen't burden class to maintain ownership of returned data by reference

		consider a path being made up of drive, [n] folders, a file name and a file extention
		any of which (except individual folder) can be empty
	*/
	class HFileSystemPathImplement
	{
		////////////////////////////////////////
		// typedef
	private:
		typedef HContainerArray< HString >TArrayString;
		typedef HContainerArray< HCHAR >TArrayHCHAR;

		////////////////////////////////////////
		// creation
	public:
		HFileSystemPathImplement( const HFileSystemPathImplement& in_src );
		//if you want to only set path not file name, be sure to include trailing folder specifier, 
		//	ie, you can leave out file name and extention
		HFileSystemPathImplement( const HString& in_pathFileNameExtention );
		HFileSystemPathImplement();
		~HFileSystemPathImplement();

		////////////////////////////////////////
		// operators
	public:
		const HFileSystemPathImplement& operator=( const HFileSystemPathImplement& in_rhs );
		HBOOL operator==( const HFileSystemPathImplement& in_rhs )const;
		HBOOL operator!=( const HFileSystemPathImplement& in_rhs )const;
		HBOOL operator<( const HFileSystemPathImplement& in_rhs )const;

		//add all folders and replace filename and extention
		const HFileSystemPathImplement operator+( const HFileSystemPathImplement& in_rhs )const;
		const HFileSystemPathImplement& operator+=( const HFileSystemPathImplement& in_rhs );

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
		const HString FolderAdd( const HString& in_data );

		const HString FolderBack()const;
		HVOID FolderPush( const HString& in_folder );
		HVOID FolderPop();

		const HString FileNameGet()const;
		//consume the input string up till last extention specifier char, return data without that file name
		const HString FileNameSet( const HString& in_data );

		const HString ExtentionGet()const;
		HVOID ExtentionSet( const HString& in_extention );

		////////////////////////////////////////
		// private Members
	private:
		HString m_drive;
		TArrayString m_arrayFolders;
		HString m_fileName;
		HString m_fileExtention;

	};

	/**/
};

#endif// _H_FILE_SYSTEM_PATH_IMPLEMENT_H_
