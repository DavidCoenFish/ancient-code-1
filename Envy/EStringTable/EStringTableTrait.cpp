//file: Envy/EStringTable/EStringTableTrait.cpp

#include "Envy/EnvyPreCompileHeader.h"
#include "Envy/EStringTable/EStringTableTrait.h"

#include "Envy/EStringTable/EStringTable.h"
#include "Envy/EStringTable/EStringTableImplementation.h"
#include "Envy/EMemento/EMemento_Export.h"
#include "Hubris/HContainer/HContainer_Export.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerTree< Hubris::HString, Hubris::HSINT >TTreeStringSint;

//typedef Hubris::HContainerArray< Hubris::HString >TArrayString;
//typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HString >TPairSintString;
//typedef Hubris::HContainerArray< TPairSintString >TArrayPairSintString;

///////////////////////////////////////////////////////////
// specialise memento
/**/
HVOID Envy::EMementoTraitCollect< EStringTable >( EMementoCollect& in_out_mementoCollect, const Envy::EStringTable& in_data )
{
	//TArrayString arrayString;
	//const HSINT count = in_data.StringCountGet();

	//arrayString.SizeSet( count );
	//for( HSINT index = 0; index < count; ++index )
	//{
	//	arrayString[ index ] = in_data.StringGet( index );
	//}

	//in_out_mementoCollect.MemberAdd( "m_stringTable", arrayString );
	in_out_mementoCollect.MemberAdd( "m_stringTable", in_data.ImplementationGet().TreeStringIndexGet() );

	return;
}

/**/
HVOID Envy::EMementoTraitAssign< EStringTable >( const EMementoAssign& in_out_mementoAssign, Envy::EStringTable& out_data )
{
	//out_data = EStringTable();

	//TArrayString arrayString;
	//in_out_mementoAssign.MemberGet( "m_stringTable", arrayString );

	//HCOMMON_FOR_EACH_CONST( string, arrayString, TArrayString )
	//{
	//	out_data.StringAdd( string );
	//}
	TTreeStringSint treeString;
	in_out_mementoAssign.MemberGet( "m_stringTable", treeString ); //in_data.ImplementationGet().TreeStringIndexGet() );

	for( TTreeStringSint::TIterator iterator = treeString.Begin(); iterator != treeString.End(); ++iterator )
	{
		out_data.StringIndexAdd( iterator.KeyGet(), ( *iterator ) );
	}

	return;
}

/**/