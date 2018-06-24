//file: Vanity/VComponentDynamic/VComponentDynamicTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentDynamic/VComponentDynamicTrait.h"

#include "Vanity/VComponentDynamic/VComponentDynamic.h"
#include "Vanity/VComponentDynamic/VComponentDynamicComponentParam.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataBase.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataSimple.h"
#include "Vanity/VComponentDynamic/VComponentDynamicDataStatic.h"

#include "Vanity/VScene/VScene_Export.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;
using namespace Envy;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< VComponentDynamicDataBase* >TArrayBase;
typedef Hubris::HSmartPointer< VComponentDynamicDataBase >TPointerData;
typedef Hubris::HContainerArray< TPointerData >TArrayPointerData;

/////////////////////////////////////////////////////////////////
// implement macro
/**/
HTYPE_NAME_IMPLEMENTATION( VComponentDynamicDataStatic );
HTYPE_NAME_IMPLEMENTATION( VComponentDynamicDataSimple );

/////////////////////////////////////////////////////////////////
// global functions
/* 
	VComponentDynamic
*/
HVOID Envy::EMementoTraitCollect< VComponentDynamic >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamic& in_data )
{
	TArrayBase arrayData;
	const TArrayPointerData& arrayPointerData = in_data.ArrayPointerDataGet();
	const HSINT count = arrayPointerData.SizeGet();
	arrayData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		arrayData[ index ] = ( VComponentDynamicDataBase* )( arrayPointerData[ index ].RawGet() );
	}

	in_out_mementoCollect.OwnedPointerAdd( "itemData", arrayData );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentDynamic >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamic& out_data )
{
	TArrayBase arrayData;
	in_out_mementoAssign.OwnedPointerGet( "itemData", arrayData );

	const HSINT count = arrayData.SizeGet();
	TArrayPointerData& arrayPointerData = out_data.ArrayPointerDataGet();
	arrayPointerData.SizeSet( count );
	for( HSINT index = 0; index < count; ++index )
	{
		arrayPointerData[ index ] = arrayData[ index ];
	}

	return;
}

/*
	VComponentDynamicDataStatic
*/
HVOID Envy::EMementoTraitCollect< VComponentDynamicDataStatic >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicDataStatic& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_param", in_data.ParamGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentDynamicDataStatic >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicDataStatic& out_data )
{
	in_out_mementoAssign.MemberGet( "m_param", out_data.ParamGet() );
	return;
}

/*
	VComponentDynamicDataSimple
*/
HVOID Envy::EMementoTraitCollect< VComponentDynamicDataSimple >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicDataSimple& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_param", in_data.ParamGet() );
	in_out_mementoCollect.MemberAdd( "m_invertMass", in_data.InvertMassGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentDynamicDataSimple >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicDataSimple& out_data )
{
	in_out_mementoAssign.MemberGet( "m_param", out_data.ParamGet() );
	in_out_mementoAssign.MemberGet( "m_invertMass", out_data.InvertMassGet() );
	return;
}

/*
	VComponentDynamicComponentParam
*/
HVOID Envy::EMementoTraitCollect< VComponentDynamicComponentParam >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentDynamicComponentParam& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_staticFriction", in_data.StaticFrictionGet() );
	in_out_mementoCollect.MemberAdd( "m_movingFriction", in_data.MovingFrictionGet() );
	in_out_mementoCollect.MemberAdd( "m_elasticCollisionDampen", in_data.ElasticCollisionDampenGet() );
	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentDynamicComponentParam >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentDynamicComponentParam& out_data )
{
	HREAL staticFriction = 0.0F;
	in_out_mementoAssign.MemberGet( "m_staticFriction", staticFriction );
	out_data.StaticFrictionSet( staticFriction );

	HREAL movingFriction = 0.0F;
	in_out_mementoAssign.MemberGet( "m_movingFriction", movingFriction );
	out_data.MovingFrictionSet( movingFriction );

	HREAL elasticCollisionDampen = 0.0F;
	in_out_mementoAssign.MemberGet( "m_elasticCollisionDampen", elasticCollisionDampen );
	out_data.ElasticCollisionDampenSet( elasticCollisionDampen );

	return;
}

///////////////////////////////////////////////////////////
// global functions
/**/
Hubris::HVOID Vanity::VComponentDynamicTraitFactoryRegister()
{
	EMEMENTO_FACTORY_REGISTER( VComponentDynamicDataStatic, VComponentDynamicDataBase );
	EMEMENTO_FACTORY_REGISTER( VComponentDynamicDataSimple, VComponentDynamicDataBase );

	return;
}

/**/
/**/