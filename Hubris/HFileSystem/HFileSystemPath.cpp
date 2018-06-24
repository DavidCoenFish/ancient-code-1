//file: Hubris/HFileSystem/HFileSystemPath.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HFileSystem/HFileSystemPath.h"

#include "Hubris/HFileSystem/HFileSystemPathImplement.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// creation
/**/
HFileSystemPath::HFileSystemPath( const HFileSystemPath& in_src )
: m_pImplement( HNULL )
{
	HCOMMON_ASSERT( HNULL != in_src.m_pImplement, "invalid member" );
	HCOMMON_NEW_PARAM( m_pImplement, HFileSystemPathImplement, in_src.ImplementGet() );

	return;
}

/**/
HFileSystemPath::HFileSystemPath( const HString& in_src )
: m_pImplement( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplement, HFileSystemPathImplement, in_src );
	return;
}

/**/
HFileSystemPath::HFileSystemPath( const HCHAR* const in_src )
: m_pImplement( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplement, HFileSystemPathImplement, in_src );
	return;
}

/**/
HFileSystemPath::HFileSystemPath()
: m_pImplement( HNULL )
{
	HCOMMON_NEW( m_pImplement, HFileSystemPathImplement );
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return;
}

/**/
HFileSystemPath::~HFileSystemPath()
{
	HCOMMON_DELETE( m_pImplement, HFileSystemPathImplement );

	return;
}

///////////////////////////////////////////////////////////
// operators
/**/
const HFileSystemPath& HFileSystemPath::operator=( const HFileSystemPath& in_rhs )
{
	ImplementGet() = in_rhs.ImplementGet();

	return( *this );
}

/**/
const HBOOL HFileSystemPath::operator==( const HFileSystemPath& in_rhs )const
{
	return( ( ImplementGet() ) == ( in_rhs.ImplementGet() ) );
}

/**/
const HBOOL HFileSystemPath::operator!=( const HFileSystemPath& in_rhs )const
{
	return( ( ImplementGet() ) != ( in_rhs.ImplementGet() ) );
}

/**/
const HBOOL HFileSystemPath::operator<( const HFileSystemPath& in_rhs )const
{
	return( ( ImplementGet() ) < ( in_rhs.ImplementGet() ) );
}

/**/
HFileSystemPath HFileSystemPath::operator+( const HFileSystemPath& in_rhs )const
{
	HFileSystemPath path( *this );
	path += in_rhs;

	return path;
}

/**/
HFileSystemPath& HFileSystemPath::operator+=( const HFileSystemPath& in_rhs )
{
	ImplementGet() += in_rhs.ImplementGet();

	return( *this );
}

////////////////////////////////////////
// public methods
/**/
const HString HFileSystemPath::PathFileNameExtentionGet()const
{
	return ImplementGet().PathFileNameExtentionGet();
}

/**/
HVOID HFileSystemPath::PathFileNameExtentionSet( const HString& in_pathFileNameExtention )
{
	ImplementGet().PathFileNameExtentionSet( in_pathFileNameExtention );
	return;
}

/**/
const HString HFileSystemPath::PathOnlyGet()const
{
	return ImplementGet().PathOnlyGet();
}

/**/
const HString HFileSystemPath::PathOnlySet( const HString& in_path )
{
	return ImplementGet().PathOnlySet( in_path );
}

/**/
const HString HFileSystemPath::FileNameExtentionOnlyGet()const
{
	return ImplementGet().FileNameExtentionOnlyGet();
}

/**/
HVOID HFileSystemPath::FileNameExtentionOnlySet( const HString& in_fileNameExtention )
{
	ImplementGet().FileNameExtentionOnlySet( in_fileNameExtention );
	return;
}

////////////////////////////////////////
// public accessors
/**/
const HString HFileSystemPath::DriveGet()const
{
	return ImplementGet().DriveGet();
}

/**/
const HString HFileSystemPath::DriveSet( const HString& in_data )
{
	return ImplementGet().DriveSet( in_data );
}

/**/
HSINT HFileSystemPath::FolderCountGet()const
{
	return ImplementGet().FolderCountGet();
}

/**/
const HString HFileSystemPath::FolderGet( const HSINT in_index )const
{
	return ImplementGet().FolderGet( in_index );
}

/**/
HVOID HFileSystemPath::FolderSet( const HSINT in_index, const HString& in_folder )
{
	ImplementGet().FolderSet( in_index, in_folder );
	return;
}

/**/
const HString HFileSystemPath::FolderAdd( const HString& in_data )
{
	return ImplementGet().FolderAdd( in_data );
}

/**/
const HString HFileSystemPath::FolderBack()const
{
	return ImplementGet().FolderBack();
}

/**/
HVOID HFileSystemPath::FolderPush( const HString& in_folder )
{
	ImplementGet().FolderPush( in_folder );
	return;
}

/**/
HVOID HFileSystemPath::FolderPop()
{
	ImplementGet().FolderPop();
	return;
}

/**/
const HString HFileSystemPath::FileNameGet()const
{
	return ImplementGet().FileNameGet();
}

/**/
const HString HFileSystemPath::FileNameSet( const HString& in_data )
{
	return ImplementGet().FileNameSet( in_data );
}

/**/
const HString HFileSystemPath::ExtentionGet()const
{
	return ImplementGet().ExtentionGet();
}

/**/
HVOID HFileSystemPath::ExtentionSet( const HString& in_extention )
{
	ImplementGet().ExtentionSet( in_extention );
	return;
}

///////////////////////////////////////////////////////////
// private accessors
/**/
const HFileSystemPathImplement& HFileSystemPath::ImplementGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/
HFileSystemPathImplement& HFileSystemPath::ImplementGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplement, "invalid member" );

	return( *m_pImplement );
}

/**/
