//file: Envy/EMemento/EMementoFactory.h
#ifndef _E_MEMENTO_FACTORY_H_
#define _E_MEMENTO_FACTORY_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;
	class EMementoCollect;
	class EMementoAssign;

};

#define EMEMENTO_FACTORY_HEADER( IN_BASE_CLASS )						\
	public:																\
		virtual const Hubris::HString MementoFactoryNameGet()const;		\
		virtual Hubris::HVOID MementoCollect( Envy::EMementoCollect& in_out_collect )const;\
		virtual Hubris::HVOID MementoAssign( const Envy::EMementoAssign& in_assign );\
		static IN_BASE_CLASS* const MementoFactoryCreate();

#define EMEMENTO_FACTORY_HEADER_PURE( IN_BASE_CLASS )					\
	public:																\
		virtual const Hubris::HString MementoFactoryNameGet()const=0;	\
		virtual Hubris::HVOID MementoCollect( Envy::EMementoCollect& in_out_collect )const=0;\
		virtual Hubris::HVOID MementoAssign( const Envy::EMementoAssign& in_assign )=0;\

#define EMEMENTO_FACTORY_SOURCE( IN_CLASS, IN_BASE_CLASS )				\
	const Hubris::HString IN_CLASS::MementoFactoryNameGet()const		\
	{																	\
		return Hubris::HTraitName< IN_CLASS >::NameGet();				\
	}																	\
	Hubris::HVOID IN_CLASS::MementoCollect( Envy::EMementoCollect& in_out_collect )const \
	{																	\
		in_out_collect.MemberAdd( "_DATA", *this );						\
		return;															\
	}																	\
	Hubris::HVOID IN_CLASS::MementoAssign( const Envy::EMementoAssign& in_assign )\
	{																	\
		in_assign.MemberGet( "_DATA", *this );							\
		return;															\
	}																	\
	IN_BASE_CLASS* const IN_CLASS::MementoFactoryCreate()				\
	{																	\
		IN_CLASS* pClass = HNULL;										\
		HCOMMON_NEW(													\
			pClass,														\
			IN_CLASS													\
			);															\
		return pClass;													\
	}

//then to register class, somewhere in the code place
#define EMEMENTO_FACTORY_REGISTER( IN_CLASS, IN_BASE_CLASS )			\
	EMementoFactory< IN_BASE_CLASS >::RegisterCreation(					\
		Hubris::HTraitName< IN_CLASS >::NameGet(),						\
		&IN_CLASS::MementoFactoryCreate									\
		);

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// struct
	/**/
	template< typename IN_TYPE >struct EMementoFactory
	{
		//////////////////////////////////////////////
		// typedef
	private:
		typedef IN_TYPE* const (*FClassCreate)();
		typedef Hubris::HContainerTree< Hubris::HString, FClassCreate >TTreeStringClassCreate;

		//////////////////////////////////////////////
		// disabled
	private:
		~EMementoFactory();

		//////////////////////////////////////////////
		// static public methods
	public:
		static Hubris::HVOID RegisterCreation( 
			const Hubris::HString& in_name,
			const FClassCreate in_fClassCreate
			);

		static IN_TYPE* const CreateObject(
			const Hubris::HString& in_name			
			);

		//////////////////////////////////////////////
		// static public methods
	private:
		static TTreeStringClassCreate s_treeNameClassCreate;

	};

	//////////////////////////////////////////////
	// static public methods
	/**/
	template< typename IN_TYPE > 
	Hubris::HVOID EMementoFactory< IN_TYPE >::RegisterCreation( 
		const Hubris::HString& in_name,
		const FClassCreate in_fClassCreate
		)
	{
		s_treeNameClassCreate.Insert( in_name, in_fClassCreate );
		return;
	}

	/**/
	template< typename IN_TYPE > 
	IN_TYPE* const EMementoFactory< IN_TYPE >::CreateObject(
		const Hubris::HString& in_name
		)
	{
		TTreeStringClassCreate::TIterator iterator = s_treeNameClassCreate.Find( in_name );
		if( iterator != s_treeNameClassCreate.End() )
		{
			return( ( *iterator )() );
		}

		return HNULL;
	}

	//////////////////////////////////////////////
	// static public methods
	/**/
	template< typename IN_TYPE > 
	typename EMementoFactory< IN_TYPE >::TTreeStringClassCreate EMementoFactory< IN_TYPE >::s_treeNameClassCreate;

};

/**/
#endif // _E_MEMENTO_FACTORY_H_