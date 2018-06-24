//file: Envy/EMemento/EMementoAssign.h
#ifndef _E_MEMENTO_ASSIGN_H_
#define _E_MEMENTO_ASSIGN_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Envy/EMemento/EMementoDataStore.h"
#include "Envy/EMemento/EMementoAssignPointer.h"

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoAssign
	{
		//////////////////////////////////////////////
		//typedef
	private:
		//alternative is to use smart pointer. damn, using smart pointers outside EMementoDataStore is violation of encapsulation
		// drop back to use pointers
		//typedef Hubris::HContainerArray< EMementoDataStore::TRecursiveDataStorePointer >TArrayPointerDataStore;
		typedef Hubris::HContainerArray< const EMementoDataStore* >TArrayPointerDataStore;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoAssign( const EMemento& in_memento );
		~EMementoAssign();

		//////////////////////////////////////////////
		//disabled
	private:
		EMementoAssign( const EMementoAssign& in_src );
		const EMementoAssign& operator=( const EMementoAssign& in_rhs );

		//////////////////////////////////////////////
		//public methods
	public:
		Hubris::HVOID PointerCreationDataRefresh(); //scan through memento to gather class name to owner
		Hubris::HVOID PointerCreatedClear();//clear record of created objects for owned poiners, so if queried, create new objects. assum ownership has been taken, ie, leak

		template< typename IN_TYPE >Hubris::HVOID MemberGet( const Hubris::HString& in_name, IN_TYPE& out_data )const;
		template< typename IN_TYPE >Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE >& out_arrayData )const;
		template< typename IN_KEY, typename IN_DATA >Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerTree< IN_KEY, IN_DATA >& out_treeData )const;
		template< typename IN_FIRST, typename IN_SECOND >Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerPair< IN_FIRST, IN_SECOND >& out_pairData )const;

		template< typename IN_TYPE >Hubris::HVOID PointerGet( const Hubris::HString& in_name, IN_TYPE*& out_pData )const;
		template< typename IN_TYPE >Hubris::HVOID PointerGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE* >& out_arrayData )const;
		template< typename IN_TYPE >Hubris::HVOID OwnedPointerGet( const Hubris::HString& in_name, IN_TYPE*& out_pData )const;
		template< typename IN_TYPE >Hubris::HVOID OwnedPointerGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE* >& out_arrayData )const;

		//////////////////////////////////////////////
		//private methods
	private:
		Hubris::HBOOL InternalMemberGet( const Hubris::HString& in_name, EMementoDataStore::TVariantExchange& out_data )const;
		const Hubris::HSINT InternalPointerIdGet()const;

		Hubris::HBOOL PushChild( const Hubris::HString& in_name )const;
		Hubris::HVOID PopChild()const;

		Hubris::HSINT ArrayChildCountGet( const Hubris::HString& in_name )const;
		Hubris::HVOID ArrayChildPush( const Hubris::HString& in_name, const Hubris::HSINT in_index )const;

		//////////////////////////////////////////////
		//inline specialisation of base types
	public:
		/**/
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HU8& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HU8 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HS8& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HS8 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HU16& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HU16 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HS16& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HS16 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HU32& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HU32 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HS32& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HS32 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HR32& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HR32 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HR64& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HR64 >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HBOOL& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HBOOL >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HCHAR& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HCHAR >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HString& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HString >();
			}
			return;
		}
		/**/
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HU8 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HU8 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HS8 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HS8 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HU16 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HU16 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HS16 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HS16 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HU32 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HU32 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HS32 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HS32 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HR32 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HR32 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HR64 >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HR64 > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HBOOL >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HBOOL > >();
			}
			return;
		}
		template<>Hubris::HVOID MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< Hubris::HCHAR >& out_data )const
		{
			EMementoDataStore::TVariantExchange data;
			if( HTRUE == InternalMemberGet( in_name, data ) )
			{
				out_data = data.ValueGet< Hubris::HContainerArray< Hubris::HCHAR > >();
			}
			return;
		}

		//////////////////////////////////////////////
		//private accessors
	private:
		EMementoAssignPointer& AssignPointerGet()const;
		//EMementoAssignPointer& AssignPointerGet();

		//////////////////////////////////////////////
		//private members
	private:
		mutable TArrayPointerDataStore m_currentObjectStack;
		mutable EMementoAssignPointer* m_pAssignPointer;

	};

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::MemberGet( const Hubris::HString& in_name, IN_TYPE& out_data )const
	{
		//unknown type, fall through to generic handler after adding child to memento
		if( HTRUE == PushChild( in_name ) )
		{
			EMementoTraitAssign( ( *this ), out_data );
			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::MemberGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE >& out_arrayData )const
	{
		const Hubris::HSINT count = ArrayChildCountGet( in_name );
		if( HCOMMON_INVALID_INDEX == count )
		{
			return;
		}

		out_arrayData.SizeSet( count );
		for( Hubris::HSINT index = 0; index < count; ++index )
		{
			ArrayChildPush( in_name, index );

			MemberGet( "item", out_arrayData[ index ] );
			//EMementoTraitAssign( ( *this ), out_arrayData[ index ] );

			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_KEY, typename IN_DATA >
	Hubris::HVOID EMementoAssign::MemberGet( const Hubris::HString& in_name, Hubris::HContainerTree< IN_KEY, IN_DATA >& out_treeData )const
	{
		const Hubris::HSINT count = ArrayChildCountGet( in_name );
		if( HCOMMON_INVALID_INDEX == count )
		{
			return;
		}

		out_treeData.Clear();
		for( Hubris::HSINT index = 0; index < count; ++index )
		{
			ArrayChildPush( in_name, index );

			IN_KEY key;
			IN_DATA data;

			MemberGet( "key", key );
			MemberGet( "data", data );

			out_treeData.Insert( key, data );

			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND >
	Hubris::HVOID EMementoAssign::MemberGet( const Hubris::HString& in_name, Hubris::HContainerPair< IN_FIRST, IN_SECOND >& out_pairData )const
	{
		if( HTRUE == PushChild( in_name ) )
		{

			MemberGet( "first", out_pairData.m_first );
			MemberGet( "second", out_pairData.m_second );

			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::PointerGet( const Hubris::HString& in_name, IN_TYPE*& out_pData )const 
	{
		if( HTRUE == PushChild( in_name ) )
		{
			if( HTRUE == PushChild( "_POINTER" ) )
			{
				const HSINT id = InternalPointerIdGet();
				out_pData = AssignPointerGet().PointerGet< IN_TYPE >( id );

				PopChild();
			}
			PopChild();
		}
		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::PointerGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE* >& out_arrayData )const 
	{
		const Hubris::HSINT count = ArrayChildCountGet( in_name );
		if( HCOMMON_INVALID_INDEX == count )
		{
			return;
		}

		out_arrayData.SizeSet( count );
		for( Hubris::HSINT index = 0; index < count; ++index )
		{
			ArrayChildPush( in_name, index );
			if( HTRUE == PushChild( "_POINTER" ) )
			{
				const HSINT id = InternalPointerIdGet();
				out_pData = AssignPointerGet().PointerGet< IN_TYPE >( id );

				PopChild();
			}
			PopChild();
		}

		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::OwnedPointerGet( const Hubris::HString& in_name, IN_TYPE*& out_pData )const 
	{
		if( HTRUE == PushChild( in_name ) )
		{
			if( HTRUE == PushChild( "_POWNED" ) )
			{
				const HSINT id = InternalPointerIdGet();
				out_pData = AssignPointerGet().PointerGet< IN_TYPE >( id );
				
				if( HNULL != out_pData )
				{
					out_pData->MementoAssign( ( *this ) );
				}

				PopChild();
			}
			PopChild();
		}
		return;
	}

	/**/
	template< typename IN_TYPE >
	Hubris::HVOID EMementoAssign::OwnedPointerGet( const Hubris::HString& in_name, Hubris::HContainerArray< IN_TYPE* >& out_arrayData )const 
	{
		const Hubris::HSINT count = ArrayChildCountGet( in_name );
		if( HCOMMON_INVALID_INDEX == count )
		{
			return;
		}

		out_arrayData.SizeSet( count );
		for( Hubris::HSINT index = 0; index < count; ++index )
		{
			ArrayChildPush( in_name, index );
			if( HTRUE == PushChild( "_POWNED" ) )
			{
				const HSINT id = InternalPointerIdGet();
				out_arrayData[ index ] = AssignPointerGet().PointerGet< IN_TYPE >( id );

				if( HNULL != out_arrayData[ index ] )
				{
					out_arrayData[ index ]->MementoAssign( ( *this ) );
				}

				PopChild();
			}
			PopChild();
		}

		return;
	}

	/**/
};

/**/
#endif // _E_MEMENTO_ASSIGN_H_