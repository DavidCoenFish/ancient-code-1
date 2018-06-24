//file: Hubris/HTestbed/HTestbedContainer.cpp

#include "Hubris/HTestbed/HTestbedContainer.h"

#include "Hubris/HTestbed/HTestbed.h"

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HContainer/HContainerAlgorithm.h"
#include "Hubris/HContainer/HContainerAlgorithmSort.h"
#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HContainer/HContainerArrayBit.h"
#include "Hubris/HContainer/HContainerArrayBool.h"
#include "Hubris/HContainer/HContainerArrayTrait.h"
#include "Hubris/HContainer/HContainerLess.h"
#include "Hubris/HContainer/HContainerObjectPool.h"
#include "Hubris/HContainer/HContainerPair.h"
#include "Hubris/HContainer/HContainerPairTrait.h"
#include "Hubris/HContainer/HContainerTree.h"
#include "Hubris/HContainer/HContainerTreeTrait.h"
#include "Hubris/HContainer/HContainerUtility.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HString/HStringTrait.h"
#include "Hubris/HTrait/HTraitStringIn.h"
#include "Hubris/HTrait/HTraitSwap.h"

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

//////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HSINT >TArraySint;

//////////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedContainerAlgorithm()
{
	HBOOL success = HTRUE;

	//HContainerAlgorithm
	//static HVOID Merge( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, IN_CONTAINER& out_container );
	{
		TArraySint array0;
		array0.Insert( 1 );
		array0.Insert( 3 );
		array0.Insert( 5 );
		array0.Insert( 7 );

		TArraySint array1;
		array1.Insert( 2 );
		array1.Insert( 4 );
		array1.Insert( 5 );
		array1.Insert( 6 );

		TArraySint array2;
		array2.Insert( 1 );
		array2.Insert( 2 );
		array2.Insert( 3 );
		array2.Insert( 4 );
		array2.Insert( 5 );
		array2.Insert( 5 );
		array2.Insert( 6 );
		array2.Insert( 7 );

		TArraySint array3;
		HContainerAlgorithm::Merge( array0, array1, array3 );

		success &= ( array2 == array3 );
	}
	//static HVOID Split( const IN_CONTAINER& in_data, IN_CONTAINER& out_lhs, IN_CONTAINER& out_rhs ); 
	//static HVOID Split( IN_CONTAINER& in_out_lhs, IN_CONTAINER& out_rhs ); 
	{
		TArraySint array0;
		array0.Insert( 1 );
		array0.Insert( 2 );
		array0.Insert( 3 );
		array0.Insert( 4 );

		array0.Insert( 5 );
		array0.Insert( 5 );
		array0.Insert( 6 );
		array0.Insert( 7 );

		TArraySint array1;
		array1.Insert( 1 );
		array1.Insert( 2 );
		array1.Insert( 3 );
		array1.Insert( 4 );

		TArraySint array2;
		array2.Insert( 5 );
		array2.Insert( 5 );
		array2.Insert( 6 );
		array2.Insert( 7 );

		TArraySint array3( array0 );

		TArraySint array4;
		TArraySint array5;
		HContainerAlgorithm::Split( array0, array4, array5 );

		success &= ( array1 == array4 );
		success &= ( array2 == array5 );

		TArraySint array6;
		HContainerAlgorithm::Split( array3, array6 );

		success &= ( array3 == array1 );
		success &= ( array6 == array2 );
	}

	//static HVOID MergeSort( IN_CONTAINER& in_container ); 
	{
		TArraySint array0;
		array0.Insert( 7 );
		array0.Insert( 8 );
		array0.Insert( 9 );
		array0.Insert( 4 );
		array0.Insert( 7 );
		array0.Insert( 8 );
		array0.Insert( 9 );
		array0.Insert( 4 );
		array0.Insert( 5 );
		array0.Insert( 6 );
		array0.Insert( 7 );
		array0.Insert( 1 );
		array0.Insert( 0 );
		array0.Insert( 1 );
		array0.Insert( 2 );
		array0.Insert( 3 );
		array0.Insert( 4 );
		array0.Insert( 5 );
		array0.Insert( 6 );
		array0.Insert( 10 );
		array0.Insert( 11 );
		array0.Insert( 12 );
		array0.Insert( 10 );
		array0.Insert( 9 );
		array0.Insert( 8 );

		TArraySint array1;
		array1.Insert( 0 );
		array1.Insert( 1 );
		array1.Insert( 1 );
		array1.Insert( 2 );
		array1.Insert( 3 );
		array1.Insert( 4 );
		array1.Insert( 4 );
		array1.Insert( 4 );
		array1.Insert( 5 );
		array1.Insert( 5 );
		array1.Insert( 6 );
		array1.Insert( 6 );
		array1.Insert( 7 );
		array1.Insert( 7 );
		array1.Insert( 7 );
		array1.Insert( 8 );
		array1.Insert( 8 );
		array1.Insert( 8 );
		array1.Insert( 9 );
		array1.Insert( 9 );
		array1.Insert( 9 );
		array1.Insert( 10 );
		array1.Insert( 10 );
		array1.Insert( 11 );
		array1.Insert( 12 );

		TArraySint array2;
		array2.Insert( 7 );
		array2.Insert( 8 );
		array2.Insert( 9 );
		array2.Insert( 4 );
		array2.Insert( 7 );
		array2.Insert( 8 );
		TArraySint array3;
		array3.Insert( 4 );
		array3.Insert( 7 );
		array3.Insert( 7 );
		array3.Insert( 8 );
		array3.Insert( 8 );
		array3.Insert( 9 );

		TArraySint array4( array0 );
		HContainerAlgorithm::MergeSort( array4 );
		success &= ( array4 == array1 );

		TArraySint array5( array2 );
		HContainerAlgorithm::MergeSort( array5 );
		success &= ( array5 == array3 );
	}

	HTESTBED_VALIDATE_STATUS( "ContainerAlgorithm", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerArray()
{
	HBOOL success = HTRUE;

	typedef HContainerArray< HSINT > TArraySint;
	typedef HContainerArray< HString > TArrayString;


	//HContainerArray( const TIterator& in_insertStart, const TIterator& in_insertEnd );
	//HContainerArray( const HContainerArray& in_src );
	//HContainerArray();
	//~HContainerArray();
	
	//HContainerArray& operator =( const HContainerArray& in_rhs );
	//HBOOL operator ==( const HContainerArray& in_rhs ) const;
	//HBOOL operator !=( const HContainerArray& in_rhs ) const;
	//const IN_TYPE& operator[]( const HSINT in_index ) const;
	//IN_TYPE& operator[]( const HSINT in_index );
	{
		TArraySint array0;
		array0.Insert( 5 );
		array0.Insert( 10 );
		array0.Insert( 20 );
		array0.Insert( 3 );

		TArraySint array1( array0 );
		TArraySint array2( array0.Begin(), array0.End() );

		TArraySint array3;

		success &= ( array0 == array1 );
		success &= ( array1 == array0 );

		success &= ( array0 == array2 );
		success &= ( array2 == array0 );

		success &= ( array0 != array3 );
		success &= ( array3 != array0 );

		success &= ( array0[ 0 ] == 5 );
		success &= ( array0[ 1 ] == 10 );
		success &= ( array0[ 2 ] == 20 );
		success &= ( array0[ 3 ] == 3 );
		success &= ( array0[ 0 ] != 7 );

		success &= ( array3 < array0 );
		success &= !( array0 < array3 );
	}

	//HSINT SizeGet()const;
	//HSINT SizeSet( const HSINT in_size );
	//HSINT SizeResize( const HSINT in_size );
	//HVOID Clear();
	{
		TArrayString array0;
		array0.Insert( "hello" );
		array0.Insert( "world" );
		array0.Insert( "foo" );
		array0.Insert( "bar" );
		array0.Insert( "moo" );

		success &= ( 5 == array0.SizeGet() );
		array0.Insert( "goo" );
		success &= ( 6 == array0.SizeGet() );
		success &= ( 0 == TArrayString().SizeGet() );

		array0.SizeResize( 3 );
		success &= ( array0[ 0 ] == "hello" );
		success &= ( array0[ 1 ] == "world" );
		success &= ( array0[ 2 ] == "foo" );
		success &= ( 3 == array0.SizeGet() );

		array0.SizeSet( 2 );
		success &= ( array0[ 0 ] == HNULL );
		success &= ( array0[ 1 ] == HNULL );
		success &= ( 2 == array0.SizeGet() );

		array0.Clear();
		success &= ( 0 == array0.SizeGet() );
	}

	//const TIterator Begin() const;
	//TIterator Begin();
	//const TIterator End() const;
	//TIterator End();
	{
		TArrayString array0;
		array0.Insert( "hello" );
		array0.Insert( "world" );
		array0.Insert( "foo" );
		array0.Insert( "bar" );
		array0.Insert( "moo" );

		const TArrayString array1( array0 );

		HSINT trace = 0;
		TArrayString::TIterator iter0 = array0.Begin();
		for( const TArrayString::TIterator iter = array1.Begin(); iter != array1.End(); ++iter )
		{
			success &= ( ( *iter0 ) == ( *iter ) );
			trace += 1;
			++iter0;
		}

		success &= ( 5 == trace );
	}


	//HVOID Insert( const TIterator& in_insertStart, const TIterator& in_insertEnd, const TIterator& in_where );
	//HVOID Insert( const IN_TYPE& in_data, const TIterator& in_where );
	//HVOID Insert( const IN_TYPE& in_data );
	//HVOID Remove( const TIterator& in_start, const TIterator& in_end );
	//TIterator Remove( const TIterator& in_where );
	{
		TArrayString array0;
		array0.Insert( "hello" );
		array0.Insert( "world" );
		array0.Insert( "foo" );
		array0.Insert( "bar" );
		array0.Insert( "moo" );

		TArrayString array1( array0 );

		HSINT trace = 0;
		for( TArrayString::TIterator iter = array0.Begin(); iter != array0.End(); ++iter )
		{
			if( ( "world" == ( *iter ) ) || ( "moo" == ( *iter ) ) )
			{
				iter = array0.Remove( iter );
			}
			trace += 1;
		}

		success &= ( 3 == array0.SizeGet() );
		success &= ( 5 == trace );

		array1.Remove( array1.Begin(), array1.Begin() + 2 );
		success &= ( 3 == array1.SizeGet() );
	}

	//const HVOID* const RawGet()const{ return &m_data[ 0 ]; }
	{
		TArraySint array0;
		HSINT data[ 3 ] = { 10000, 4, -32 };
		array0.Insert( data[ 0 ] );
		array0.Insert( data[ 1 ] );
		array0.Insert( data[ 2 ] );

		success &= ( 0 == memcmp( array0.RawGet(), data, sizeof( data ) ) );

		array0[ 1 ] = -142;
		success &= ( -142 == array0[ 1 ] );
	}


	HTESTBED_VALIDATE_STATUS( "ContainerArray", success );

	return success;
}

/**
static const HBOOL LocalTestbedContainerArrayBit()
{
	HBOOL success = HTRUE;

	{
		HContainerArrayBit arrayBit0;
		arrayBit0.Insert( true );
		arrayBit0.Insert( false );
		arrayBit0.Insert( true );
		const HContainerArrayBit arrayBit1( arrayBit0 );
		const HContainerArrayBit arrayBit2 = arrayBit0;
		const HContainerArrayBit arrayBit3;

		success &= ( arrayBit0 == arrayBit0 );

		success &= ( arrayBit0 == arrayBit1 );
		success &= ( arrayBit1 == arrayBit0 );

		success &= ( arrayBit0 == arrayBit2 );
		success &= ( arrayBit2 == arrayBit0 );

		success &= ( arrayBit0 != arrayBit3 );
		success &= ( arrayBit3 != arrayBit0 );

		success &= !( arrayBit0 != arrayBit0 );

		success &= !( arrayBit0 != arrayBit2 );
		success &= !( arrayBit2 != arrayBit0 );

		success &= !( arrayBit0 == arrayBit3 );
		success &= !( arrayBit3 == arrayBit0 );
	}

	HTESTBED_VALIDATE_STATUS( "ContainerArrayBit", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerArrayBool()
{
	HBOOL success = HTRUE;

	typedef HContainerArray< HBOOL >TArrayBool;

	{
		TArrayBool arrayBool;
		arrayBool.Insert( HTRUE );
		arrayBool.Insert( HTRUE );
		arrayBool.Insert( HFALSE );
		arrayBool.Insert( HFALSE );

		arrayBool[ 1 ] = HFALSE;
		arrayBool[ 2 ] = HTRUE;

		success &= ( HTRUE == arrayBool[ 0 ] );
		success &= ( HFALSE == arrayBool[ 1 ] );
		success &= ( HTRUE == arrayBool[ 2 ] );
		success &= ( HFALSE == arrayBool[ 3 ] );
	}

	HTESTBED_VALIDATE_STATUS( "ContainerArrayBool", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerArrayTrait()
{
	HBOOL success = HTRUE;

	typedef HContainerArray< HBOOL >TArrayBool;

	success &= ( "HArray_HBOOL" == HTraitName< TArrayBool >::NameGet() );

	HTESTBED_VALIDATE_STATUS( "ContainerArrayTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerLess()
{
	HBOOL success = HTRUE;

	//template< typename IN_TYPE >struct HContainerLess
	//bool operator()(const IN_TYPE& in_lhs, const IN_TYPE& in_rhs )const
	typedef HContainerLess< HSINT >TContainerLessSint;
	TContainerLessSint lessSint;

	success &= ( HTRUE == lessSint.operator ()( 5, 10 ) );
	success &= ( HFALSE == lessSint.operator ()( 5, 5 ) );
	success &= ( HFALSE == lessSint.operator ()( 10, 5 ) );

	typedef HContainerLess< HString >TContainerLessString;
	TContainerLessString lessString;

	success &= ( HTRUE == lessString.operator ()( "aaa", "bbb" ) );
	success &= ( HFALSE == lessString.operator ()( "aaa", "aaa" ) );
	success &= ( HFALSE == lessString.operator ()( "b", "a" ) );

	HTESTBED_VALIDATE_STATUS( "ContainerLess", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerObjectPool()
{
	HBOOL success = HTRUE;

	typedef HContainerObjectPool< HString >TPoolString;

	//HContainerObjectPool();
	//~HContainerObjectPool();
	//IN_CLASS& ItemCreate();
	//HVOID ItemRelease( const IN_CLASS& in_item );
	//HSINT ItemIndexGet( const IN_CLASS& in_item )const;
	//const IN_CLASS& ItemGet( const HSINT in_index )const;
	//IN_CLASS& ItemGet( const HSINT in_index );
	//HVOID Clear( const HBOOL in_freeMemory );
	{
		TPoolString pool0;

		HString& string0 = pool0.ItemCreate();
		string0 = "quible";
		{
			HString& string1 = pool0.ItemCreate();
			string1 = "nibble";
			pool0.ItemRelease( string1 );
		}
		HString& string2 = pool0.ItemCreate();
		string2 = "dribble";

		success &= ( 0 == pool0.ItemIndexGet( string0 ) );
		success &= ( 1 == pool0.ItemIndexGet( string2 ) );

		success &= ( pool0.ItemGet( 0 ) == "quible" );
		success &= ( pool0.ItemGet( 1 ) == "dribble" );

		success &= ( 2 == pool0.SizeGet() );

		for( HSINT index = 2; index < 104; ++index )
		{
			HString& string = pool0.ItemCreate();
			string = HTraitStringIn< HSINT >( index );
		}

		for( HSINT index = 32; index < 104; ++index )
		{
			success &= ( index == pool0.ItemIndexGet( pool0.ItemGet( index ) ) );
		}

		pool0.Clear();
		success &= ( 0 == pool0.SizeGet() );

	}

	HTESTBED_VALIDATE_STATUS( "ContainerObjectPool", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerPair()
{
	HBOOL success = HTRUE;

	//HContainerPair( const IN_FIRST& in_first, const IN_SECOND& in_second );
	//HContainerPair( const HContainerPair& in_src );
	//HContainerPair();
	//~HContainerPair();
	//const HContainerPair& operator=(const HContainerPair & in_rhs);
	//HBOOL operator==(const HContainerPair & in_rhs)const;
	//HBOOL operator!=(const HContainerPair & in_rhs)const;
	//HBOOL operator<(const HContainerPair & in_rhs)const;
	//IN_FIRST m_first;
	//IN_SECOND m_second;

	typedef HContainerPair< HSINT, HString >TPairSintString;
	{
		TPairSintString pair0( 5, "fubar" );
		TPairSintString pair1( pair0 );
		TPairSintString pair2 = pair0;
		TPairSintString pair3;

		success &= ( pair0 == pair1 );
		success &= ( pair1 == pair0 );

		success &= ( pair0 == pair2 );
		success &= ( pair2 == pair0 );

		success &= ( pair0 != pair3 );
		success &= ( pair3 != pair0 );

		pair3.m_first = 6;
		pair3.m_second = "a";

		success &= ( pair0 < pair3 );
		success &= !( pair3 < pair0 );
	}

	HTESTBED_VALIDATE_STATUS( "ContainerPair", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerPairTrait()
{
	HBOOL success = HTRUE;

	typedef HContainerPair< HSINT, HString >TPairSintString;

	success &= ( "HPair_HS32_HString" == HTraitName< TPairSintString >::NameGet() );

	HTESTBED_VALIDATE_STATUS( "ContainerPairTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerTree()
{
	HBOOL success = HTRUE;

	typedef HContainerTree< HString, HSINT >TTreeStringSint;

	//HContainerTree( const HContainerTree& in_src );
	//HContainerTree();
	//~HContainerTree();
	//const HContainerTree & operator =( const HContainerTree& in_src );
	//HBOOL operator ==( const HContainerTree& in_rhs )const;
	//HBOOL operator !=( const HContainerTree& in_rhs )const;
	//HBOOL operator <( const HContainerTree& in_rhs )const;
	//const IN_DATA& operator [] ( const HS32 in_index )const;
	//IN_DATA& operator [] ( const HS32 in_index );
	{
		TTreeStringSint tree0;
		tree0.Insert( "fu", 0 );
		tree0.Insert( "bar", 1 );
		tree0.Insert( "zoo", 2 );
		tree0.Insert( "ace", 3 );
		TTreeStringSint tree1( tree0 );
		TTreeStringSint tree2 = tree0;
		TTreeStringSint tree3;

		success &= ( tree0 == tree1 );
		success &= ( tree1 == tree0 );

		success &= ( tree0 == tree2 );
		success &= ( tree2 == tree0 );

		success &= ( tree0 != tree3 );
		success &= ( tree3 != tree0 );

		success &= ( 3 == tree0[ 0 ] );
		success &= ( 1 == tree0[ 1 ] );
		success &= ( 0 == tree0[ 2 ] );
		success &= ( 2 == tree0[ 3 ] );

		tree0[ 2 ] = 45;
		success &= ( 45 == tree0[ 2 ] );

		const TTreeStringSint tree4( tree0 );
		success &= ( 45 == tree4[ 2 ] );
	}

	//HS32 SizeGet()const { return m_data.size(); }
	//HVOID Clear(); // free all memory
	//const TIterator Begin()const;		//return the iterator to the first data, could be not valid
	//TIterator Begin();					//return the iterator to the first data, could be not valid
	//const TIterator End()const;		//return the iterator after last data, not valid
	//TIterator End();					//return the iterator after last data, not valid
	{
		TTreeStringSint tree0;
		tree0.Insert( "foo", 0 );
		tree0.Insert( "zoo", 1 );
		tree0.Insert( "goo", 2 );
		tree0.Insert( "boo", 3 );
		const TTreeStringSint tree1( tree0 );

		success &= ( 4 == tree0.SizeGet() );
		tree0.Clear();
		success &= ( 0 == tree0.SizeGet() );

		const TTreeStringSint tree2( tree0 );
		success &= ( tree2.Begin() == tree2.End() );

		HSINT trace = 0;
		for( TTreeStringSint::TIterator iter = tree1.Begin(); iter != tree1.End(); ++iter )
		{
			++trace;
		}

		success &= ( trace == tree1.SizeGet() );

	}

	//const TIterator Find( const IN_KEY & in_key)const;		//return the iterator found or after last data, could be not valid
	//TIterator Find( const IN_KEY & in_key);					//return the iterator found or after last data, could be not valid
	//const TIterator FindNearest( const IN_KEY& in_key )const; 
	//TIterator FindNearest( const IN_KEY& in_key ); 
	//HVOID Insert( const TIterator& in_start, const TIterator& in_stop );
	//HVOID Insert( const IN_KEY& in_key, const IN_DATA& in_data );
	//HVOID Remove( const TIterator& in_start, const TIterator& in_stop );
	//TIterator Remove( const TIterator& in_where );
	//const IN_KEY& KeyGet( const HS32 in_index )const;
	{
		TTreeStringSint tree0;
		tree0.Insert( "foo", 0 );
		tree0.Insert( "zoo", 1 );
		tree0.Insert( "goo", 2 );
		tree0.Insert( "boo", 3 );
		const TTreeStringSint tree1( tree0 );

		const TTreeStringSint::TIterator iterFind0 = tree0.Find( "goo" );
		success &= ( 2 == ( *iterFind0 ) );

		const TTreeStringSint::TIterator iterFind1 = tree1.Find( "goo" );
		success &= ( 2 == ( *iterFind1 ) );

		const TTreeStringSint::TIterator iterFindNear0 = tree0.FindNearest( "coo" );
		success &= ( 0 == ( *iterFindNear0 ) );

		const TTreeStringSint::TIterator iterFindNear1 = tree1.FindNearest( "coo" );
		success &= ( 0 == ( *iterFindNear1 ) );

		success &= ( "boo" == tree1.KeyGet( 0 ) );

		tree0.Remove( iterFindNear0 );

		success &= ( 3== tree0.SizeGet() );
	}

	HTESTBED_VALIDATE_STATUS( "ContainerTree", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerTreeTrait()
{
	HBOOL success = HTRUE;

	typedef HContainerTree< HString, HSINT >TTreeStringSint;

	success &= ( "HTree_HString_HS32_HLess_HString" == HTraitName< TTreeStringSint >::NameGet() );


	HTESTBED_VALIDATE_STATUS( "ContainerTreeTrait", success );

	return success;
}

/**/
static const HBOOL LocalTestbedContainerUtility()
{
	HBOOL success = HTRUE;

	typedef HContainerArray< HSINT >TArraySint;
	typedef HContainerArray< HREAL >TArrayReal;

	//static HSINT PushBack( IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_data )
	//static typename const IN_CONTAINER::TType& Back( const IN_CONTAINER& in_array )
	//static typename IN_CONTAINER::TType& Back( IN_CONTAINER& in_array )
	//static HVOID PopBack( IN_CONTAINER& in_array )
	//static HSINT IndexOf( const IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_data )
	//static HSINT UniqueAdd( IN_CONTAINER& in_out_array, typename const IN_CONTAINER::TType& in_data )
	{
		TArraySint array0;

		HContainerUtility::PushBack( array0, 5 );
		HContainerUtility::PushBack( array0, 10 );
		HContainerUtility::PushBack( array0, 0 );
		HContainerUtility::PushBack( array0, 25 );

		const TArraySint array1( array0 );

		success &= ( 25 == HContainerUtility::Back( array0 ) );
		success &= ( 25 == HContainerUtility::Back( array1 ) );

		HContainerUtility::PopBack( array0 );
		HContainerUtility::PopBack( array0 );

		success &= ( 10 == HContainerUtility::Back( array0 ) );

		HContainerUtility::PushBack( array0, 3 );
		HContainerUtility::PushBack( array0, 47 );

		success &= ( 2 == HContainerUtility::IndexOf( array0, 3 ) );

		success &= ( 4 == array0.SizeGet() );
		HContainerUtility::UniqueAdd( array0, 3 );
		success &= ( 4 == array0.SizeGet() );
	}

	//static HSINT Search( const IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_key, HBOOL& out_beforeStart, HBOOL& out_afterEnd );
	{
		HBOOL beforeStart = HFALSE;
		HBOOL afterEnd = HFALSE;
		TArrayReal array0;
		array0.Insert( 0.3F );//0
		array0.Insert( 1.7F );//1
		array0.Insert( 2.0F );//2
		array0.Insert( 2.5F );//3
		array0.Insert( 4.3F );//4
		array0.Insert( 5.0F );//5

		HSINT index = HContainerUtility::Search( array0, 0.0F, beforeStart, afterEnd );
		success &= ( 0 == index );
		success &= ( HTRUE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 0.3F, beforeStart, afterEnd );
		success &= ( 0 == index );
		success &= ( HTRUE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 0.4F, beforeStart, afterEnd );
		success &= ( 0 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 1.7F, beforeStart, afterEnd );
		success &= ( 1 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 1.8F, beforeStart, afterEnd );
		success &= ( 1 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 4.9F, beforeStart, afterEnd );
		success &= ( 4 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HFALSE == afterEnd );

		index = HContainerUtility::Search( array0, 5.0F, beforeStart, afterEnd );
		success &= ( 5 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HTRUE == afterEnd );

		index = HContainerUtility::Search( array0, 5.1F, beforeStart, afterEnd );
		success &= ( 5 == index );
		success &= ( HFALSE == beforeStart );
		success &= ( HTRUE == afterEnd );
	}


	//static HSINT Search( const IN_CONTAINER& in_array, typename const IN_CONTAINER::TType& in_key, HBOOL& out_beforeStart, HBOOL& out_afterEnd );
	{
		HBOOL beforeStart = HFALSE;
		HBOOL afterEnd = HFALSE;
		TArraySint array0;
		for( HSINT index = 0; index < 100; ++index )
		{
			array0.Insert( index + index );
		}

		for( HSINT index = 0; index < 200; ++index )
		{
			HSINT found = HContainerUtility::Search( array0, index, beforeStart, afterEnd );
			success &= ( found == ( index >> 1 ) );
		}
	}

	HTESTBED_VALIDATE_STATUS( "ContainerUtility", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions
/**/
const Hubris::HBOOL TestbedContainer()
{
	HTESTBED_VALIDATE_START( "TestbedContainer" );
	HBOOL success = HTRUE;

	success &= LocalTestbedContainerAlgorithm();
	success &= LocalTestbedContainerArray();
	//success &= LocalTestbedContainerArrayBit();
	success &= LocalTestbedContainerArrayBool();
	success &= LocalTestbedContainerArrayTrait();
	success &= LocalTestbedContainerLess();
	success &= LocalTestbedContainerObjectPool();
	success &= LocalTestbedContainerPair();
	success &= LocalTestbedContainerPairTrait();
	success &= LocalTestbedContainerTree();
	success &= LocalTestbedContainerTreeTrait();
	success &= LocalTestbedContainerUtility();

	return success;
}

/**/