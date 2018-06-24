//file: Vanity/VComponentGame/VComponentGameTrait.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VComponentGame/VComponentGameTrait.h"
#include "Vanity/VComponentGame/VComponentGameItemData.h"

#include "Vanity/VComponentGame/VComponentGame.h"

#include< Envy/EMemento/EMemento_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerPair< HSINT, VComponentGameItemData >TPairSintItemData;
typedef Hubris::HContainerArray< TPairSintItemData >TArrayPairSintItemData;

///////////////////////////////////////////////////////////
// VComponentLightEmitter
/**/
HVOID Envy::EMementoTraitCollect< VComponentGame >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentGame& in_data )
{
	TArrayPairSintItemData arrayGameObject;
	const HSINT gameObjectCount = in_data.ArrayItemDataGet().SizeGet();
	const VComponentGameItemData defaultItemData;
	for( HSINT index = 0; index < gameObjectCount; ++index )
	{
		if( in_data.ArrayItemDataGet()[ index ] == defaultItemData )
		{
			continue;
		}

		arrayGameObject.Insert( TPairSintItemData( index, in_data.ArrayItemDataGet()[ index ] ) );
	}

	in_out_mementoCollect.MemberAdd( "gameObjectCount", gameObjectCount );
	in_out_mementoCollect.MemberAdd( "itemData", arrayGameObject );
	in_out_mementoCollect.MemberAdd( "m_phaseCount", in_data.PhaseCountGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentGame >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentGame& out_data )
{
	TArrayPairSintItemData arrayGameObject;
	HSINT gameObjectCount = 0;

	in_out_mementoAssign.MemberGet( "gameObjectCount", gameObjectCount );
	in_out_mementoAssign.MemberGet( "itemData", arrayGameObject );

	HSINT phaseCount = 0;
	in_out_mementoAssign.MemberGet( "m_phaseCount", phaseCount );
	out_data.PhaseCountSet( phaseCount );

	out_data.ArrayItemDataGet().SizeSet( gameObjectCount );
	HCOMMON_FOR_EACH_CONST( pair, arrayGameObject, TArrayPairSintItemData )
	{
		out_data.ArrayItemDataGet()[ pair.m_first ] = pair.m_second;
	}

	return;
}

/*
	VComponentGameItemData
*/
HVOID Envy::EMementoTraitCollect< VComponentGameItemData >( EMementoCollect& in_out_mementoCollect, const Vanity::VComponentGameItemData& in_data )
{
	in_out_mementoCollect.MemberAdd( "m_dataPath", in_data.DataPathGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< VComponentGameItemData >( const EMementoAssign& in_out_mementoAssign, Vanity::VComponentGameItemData& out_data )
{
	in_out_mementoAssign.MemberGet( "m_dataPath", out_data.DataPathGet() );

	return;
}

/**/