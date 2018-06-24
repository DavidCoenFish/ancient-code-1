//file: Envy/EMemento/EMementoTrait.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EMemento/EMementoTrait.h"

#include "Envy/EMemento/EMementoAssign.h"
#include "Envy/EMemento/EMementoCollect.h"

#include< Hubris/HFileSystem/HFileSystem_Export.h >
#include< Hubris/HQuaternion/HQuaternion_Export.h >

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

///////////////////////////////////////////////////////////
// local static variables
/**/
static const HCHAR* const s_fileSystemPathName = "path";

///////////////////////////////////////////////////////////
// specialise memento
/**/
HVOID Envy::EMementoTraitCollect< HFileSystemPath >( EMementoCollect& in_out_mementoCollect, const Hubris::HFileSystemPath& in_data )
{
	in_out_mementoCollect.MemberAdd( s_fileSystemPathName, in_data.PathFileNameExtentionGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< HFileSystemPath >( const EMementoAssign& in_out_mementoAssign, Hubris::HFileSystemPath& out_data )
{
	HString path;
	in_out_mementoAssign.MemberGet( s_fileSystemPathName, path );
	out_data.PathFileNameExtentionSet( path );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitCollect< HTypeNone >( EMementoCollect&, const Hubris::HTypeNone& )
{
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< HTypeNone >( const EMementoAssign&, Hubris::HTypeNone& )
{
	return;
}

/**/
HVOID Envy::EMementoTraitCollect< HQuaternionREAL >( EMementoCollect& in_out_mementoCollect, const Hubris::HQuaternionREAL& in_data )
{
	in_out_mementoCollect.MemberAdd( "w", in_data.WGet() );
	in_out_mementoCollect.MemberAdd( "x", in_data.XGet() );
	in_out_mementoCollect.MemberAdd( "y", in_data.YGet() );
	in_out_mementoCollect.MemberAdd( "z", in_data.ZGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< HQuaternionREAL >( const EMementoAssign& in_out_mementoAssign, Hubris::HQuaternionREAL& out_data )
{
	HREAL w = 0.0F;
	in_out_mementoAssign.MemberGet( "w", w );
	out_data.WSet( w );

	HREAL x = 0.0F;
	in_out_mementoAssign.MemberGet( "x", x );
	out_data.XSet( x );

	HREAL y = 0.0F;
	in_out_mementoAssign.MemberGet( "y", y );
	out_data.YSet( y );

	HREAL z = 0.0F;
	in_out_mementoAssign.MemberGet( "z", z );
	out_data.ZSet( z );

	return;
}

/**/

