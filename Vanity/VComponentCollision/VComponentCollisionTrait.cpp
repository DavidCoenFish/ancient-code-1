//file: Vanity/VComponentCollision/VComponentCollisionTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentCollision/VComponentCollisionTrait.h"

#include "Vanity/VComponentCollision/VComponentCollision.h"
#include "Vanity/VComponentCollision/VComponentCollisionAssetHull.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataBound.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataHull.h"
#include "Vanity/VComponentCollision/VComponentCollisionDataSphere.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Envy;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentCollisionDataBase* >TArrayBase;
typedef Hubris::HSmartPointer< VComponentCollisionDataBase >TPointerData;
typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;

/**/
HTYPE_NAME_IMPLEMENTATION( VComponentCollisionDataBound );
HTYPE_NAME_IMPLEMENTATION( VComponentCollisionDataHull );
HTYPE_NAME_IMPLEMENTATION( VComponentCollisionDataSphere );

/**/
HVOID Envy::EMementoTraitCollect< VComponentCollision >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollision& in_data )
{
	TArrayBase arrayData;
	const HSINT count = in_data.m_arrayPointerData.SizeGet();
	arrayData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		arrayData[ index ] = ( VComponentCollisionDataBase* )( in_data.m_arrayPointerData[ index ].RawGet() );
	}

	in_out_mementoCollect.OwnedPointerAdd( "itemData", arrayData );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentCollision >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollision& out_data )
{
	TArrayBase arrayData;
	in_out_mementoAssign.OwnedPointerGet( "itemData", arrayData );

	const HSINT count = arrayData.SizeGet();
	out_data.m_arrayPointerData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		out_data.m_arrayPointerData[ index ] = arrayData[ index ];
	}

	return;
}

/*
	VComponentCollisionDataBound
*/
HVOID Envy::EMementoTraitCollect< VComponentCollisionDataBound >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionDataBound& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_bound", in_data.BoundGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentCollisionDataBound >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionDataBound& out_data )
{
	Pride::PBoundsR3 bound;
	in_out_mementoAssign.MemberGet( "m_bound", bound );
	out_data.BoundSet( bound );

	return;
}

/*
	VComponentCollisionDataHull
*/
HVOID Envy::EMementoTraitCollect< VComponentCollisionDataHull >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionDataHull& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_filePath", in_data.FilePathGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentCollisionDataHull >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionDataHull& out_data )
{
	Hubris::HFileSystemPath path;
	in_out_mementoAssign.MemberGet( "m_filePath", path );
	out_data.FilePathSet( path );
	return;
}

/*
	VComponentCollisionDataSphere
*/
HVOID Envy::EMementoTraitCollect< VComponentCollisionDataSphere >( EMementoCollect&, const Vanity::VComponentCollisionDataSphere& )
{
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentCollisionDataSphere >( const EMementoAssign&, Vanity::VComponentCollisionDataSphere& )
{
	return;
}

/*
	VComponentCollisionHull
*/
Hubris::HVOID Envy::EMementoTraitCollect< VComponentCollisionHull >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionHull& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_arrayData", in_data.ArrayDataGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< VComponentCollisionHull >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionHull& out_data )
{
	in_out_mementoAssign.MemberGet( "m_arrayData", out_data.ArrayDataGet() );
	return;
}

/*
	VComponentCollisionHullData
*/
Hubris::HVOID Envy::EMementoTraitCollect< VComponentCollisionHullData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentCollisionHullData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_plane", in_data.PlaneGet() );
	in_out_mementoCollect.MemberAdd( "m_arrayIndexTouchingPlane", in_data.ArrayIndexTouchingPlaneGet() );
	return;
}

/**/
Hubris::HVOID Envy::EMementoTraitAssign< VComponentCollisionHullData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentCollisionHullData& out_data )
{
	in_out_mementoAssign.MemberGet( "m_plane", out_data.PlaneGet() );
	in_out_mementoAssign.MemberGet( "m_arrayIndexTouchingPlane", out_data.ArrayIndexTouchingPlaneGet() );
	return;
}

///////////////////////////////////////////////////////////
// global functions
/**/
Hubris::HVOID Vanity::VComponentCollisionTraitFactoryRegister()
{
	EMEMENTO_FACTORY_REGISTER( VComponentCollisionDataBound, VComponentCollisionDataBase );
	EMEMENTO_FACTORY_REGISTER( VComponentCollisionDataHull, VComponentCollisionDataBase );
	EMEMENTO_FACTORY_REGISTER( VComponentCollisionDataSphere, VComponentCollisionDataBase );
	return;
}

/**/