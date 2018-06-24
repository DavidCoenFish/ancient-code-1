//file: Envy/EMemento/EMementoCollect.h
#ifndef _E_MEMENTO_COLLECT_H_
#define _E_MEMENTO_COLLECT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >

#include "Envy/EMemento/EMementoDataStore.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;
	class EMementoCollectPointer;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoCollect
	{
		//////////////////////////////////////////////
		//typedef
	private:
		//alternative is to use smart pointer. damn, using smart pointers outside EMementoDataStore is violation of encapsulation
		// drop back to use pointers
		//typedef Hubris::HContainerArray< EMementoDataStore::TRecursiveDataStorePointer >TArrayPointerDataStore;
		typedef Hubris::HContainerArray< EMementoDataStore* >TArrayPointerDataStore;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoCollect( EMemento& in_memento );
		~EMementoCollect();

		//////////////////////////////////////////////
		//disabled
	private:
		EMementoCollect( const EMementoCollect& in_src );
		const EMementoCollect& operator=( const EMementoCollect& in_rhs );

		//////////////////////////////////////////////
		//public methods
	public:
		template< typename IN_TYPE >Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const IN_TYPE& in_data );
		template< typename IN_TYPE >Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE >& in_data );
		template< typename IN_KEY, typename IN_DATA >Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerTree< IN_KEY, IN_DATA >& in_data );
		template< typename IN_FIRST, typename IN_SECOND >Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerPair< IN_FIRST, IN_SECOND >& in_data );

		template< typename IN_TYPE >Hubris::HVOID PointerAdd( const Hubris::HString& in_name, const IN_TYPE* const in_pData );
		template< typename IN_TYPE >Hubris::HVOID PointerAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE* >& in_arrayData );
		template< typename IN_TYPE >Hubris::HVOID OwnedPointerAdd( const Hubris::HString& in_name, const IN_TYPE* const in_pData );
		template< typename IN_TYPE >Hubris::HVOID OwnedPointerAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE* >& in_arrayData );

		//////////////////////////////////////////////
		//private methods
	private:
		Hubris::HVOID InternalMemberAdd( const Hubris::HString& in_name, const EMementoDataStore::TVariantExchange& in_data );

		Hubris::HVOID InternalPointerAdd( const Hubris::HVOID* const in_pointer, const Hubris::HString& in_factoryName = HNULL );

		Hubris::HVOID PushChild( const Hubris::HString& in_name );
		Hubris::HVOID PopChild();

		Hubris::HVOID SeedEmptyChildArray( const Hubris::HString& in_name );
		Hubris::HVOID PushArrayChild( const Hubris::HString& in_name );

		//////////////////////////////////////////////
		//inline specialisation of base types
	public:
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HU8& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HS8& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HU16& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HS16& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HU32& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HS32& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HR32& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HR64& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HBOOL& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HCHAR& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HString& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}

		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HU8 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HS8 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HU16 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HS16 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HU32 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HS32 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HR32 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HR64 >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HBOOL >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}
		template<>Hubris::HVOID MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< Hubris::HCHAR >& in_data )
		{
			InternalMemberAdd( in_name, EMementoDataStore::TVariantExchange( in_data ) );
			return;
		}

		//////////////////////////////////////////////
		//private accessors
	private:
		const EMementoCollectPointer& CollectPointerGet()const;
		EMementoCollectPointer& CollectPointerGet();

		//////////////////////////////////////////////
		//private members
	private:
		TArrayPointerDataStore m_currentObjectStack;
		EMementoCollectPointer* m_pCollectPointer;

		/**/
	};

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::MemberAdd( const Hubris::HString& in_name, const IN_TYPE& in_data )
	{
		//unknown type, fall through to generic handler after adding child to memento
		PushChild( in_name );
		EMementoTraitCollect( ( *this ), in_data );
		PopChild();

		return;
	}

	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE >& in_arrayData )
	{
		//unknown type, fall through to generic handler after adding child to memento
		SeedEmptyChildArray( in_name );
		HCOMMON_FOR_EACH_CONST( data, in_arrayData, Hubris::HContainerArray< IN_TYPE > )
		{
			PushArrayChild( in_name );

			MemberAdd( "item", data );
			//EMementoTraitCollect( ( *this ), data );

			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_KEY, typename IN_DATA >
	Hubris::HVOID EMementoCollect::MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerTree< IN_KEY, IN_DATA >& in_treeData )
	{
		typedef Hubris::HContainerTree< IN_KEY, IN_DATA >TTree;
		SeedEmptyChildArray( in_name );
		for( const TTree::TIterator iter = in_treeData.Begin(); iter != in_treeData.End(); ++iter )
		{
			PushArrayChild( in_name );
			MemberAdd( "key", iter.KeyGet() );
			MemberAdd( "data", iter.DataGet() );
			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND >
	Hubris::HVOID EMementoCollect::MemberAdd( const Hubris::HString& in_name, const Hubris::HContainerPair< IN_FIRST, IN_SECOND >& in_data )
	{
		//SeedEmptyChildArray( in_name );
		PushChild( in_name );
		MemberAdd( "first", in_data.m_first );
		MemberAdd( "second", in_data.m_second );
		PopChild();

		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::PointerAdd( const Hubris::HString& in_name, const IN_TYPE* const in_pData )
	{
		PushChild( in_name );
		PushChild( "_POINTER" );
		InternalPointerAdd( in_pData );
		PopChild();
		PopChild();
		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::PointerAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE* >& in_arrayData )
	{
		SeedEmptyChildArray( in_name );
		HCOMMON_FOR_EACH_CONST( pPointer, in_arrayData, Hubris::HContainerArray< IN_TYPE* > )
		{
			PushArrayChild( in_name );
			PushChild( "_POINTER" );
			InternalPointerAdd( pPointer );
			PopChild();
			PopChild();
		}
		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::OwnedPointerAdd( const Hubris::HString& in_name, const IN_TYPE* const in_pData )
	{
		PushChild( in_name );
		PushChild( "_POWNED" );
		HString factoryName;
		if( HNULL != in_pData )
		{
			factoryName = in_pData->MementoFactoryNameGet();
		}
		InternalPointerAdd( in_pData, factoryName );
		if( HNULL != in_pData )
		{
			in_pData->MementoCollect( ( *this ) );
		}
		PopChild();
		PopChild();
		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoCollect::OwnedPointerAdd( const Hubris::HString& in_name, const Hubris::HContainerArray< IN_TYPE* >& in_arrayData )
	{
		SeedEmptyChildArray( in_name );
		HCOMMON_FOR_EACH_CONST( pPointer, in_arrayData, Hubris::HContainerArray< IN_TYPE* > )
		{
			PushArrayChild( in_name );
			PushChild( "_POWNED" );
			HString factoryName;
			if( HNULL != pPointer )
			{
				factoryName = pPointer->MementoFactoryNameGet();
			}
			InternalPointerAdd( pPointer, factoryName);
			if( HNULL != pPointer )
			{
				pPointer->MementoCollect( ( *this ) );
			}
			PopChild();
			PopChild();
		}
		return;
	}

	/**/
};

/**/
#endif // _E_MEMENTO_COLLECT_H_