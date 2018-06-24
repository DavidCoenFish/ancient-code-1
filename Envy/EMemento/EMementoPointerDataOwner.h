//file: Envy/EMemento/EMementoPointerDataOwner.h
#ifndef _E_MEMENTO_ASSIGN_POINTER_DATA_OWNER_H_
#define _E_MEMENTO_ASSIGN_POINTER_DATA_OWNER_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMemento;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EMementoPointerDataOwner
	{
		//////////////////////////////////////////////
		//creation
	public:
		EMementoPointerDataOwner( const EMementoPointerDataOwner& in_src );
		EMementoPointerDataOwner(
			const Hubris::HSINT in_id,
			const Hubris::HString& in_factoryName,
			const Hubris::HBOOL in_isReferenced
			);
		EMementoPointerDataOwner();
		~EMementoPointerDataOwner();

		//////////////////////////////////////////////
		//operator
	public:
		const EMementoPointerDataOwner& operator=( const EMementoPointerDataOwner& in_rhs );
		const Hubris::HBOOL operator==( const EMementoPointerDataOwner& in_rhs )const;
		const Hubris::HBOOL operator!=( const EMementoPointerDataOwner& in_rhs )const;

		//////////////////////////////////////////////
		//public methods
	public:
		const Hubris::HSINT IdGet()const{ return m_id; }
		Hubris::HVOID IdSet( const Hubris::HSINT in_id ){ m_id = in_id; return; }

		const Hubris::HString& FactoryNameGet()const{ m_factoryName; }
		Hubris::HVOID FactoryNameSet( const Hubris::HString& in_factoryName ){ m_factoryName = in_factoryName; return; }

		const Hubris::HBOOL ReferencedGet()const{ m_isReferenced; }
		Hubris::HVOID ReferencedSet( const Hubris::HBOOL in_isReferenced ){ m_isReferenced = in_isReferenced; return; }

		//////////////////////////////////////////////
		//private members
	private:
		//id is HCOMMON_INVALID on HNULL
		Hubris::HSINT m_id;
		//Hubris::HString m_baseClassName; //soft type checking
		Hubris::HString m_factoryName;
		Hubris::HBOOL m_isReferenced; //if pointer is referenced, it needs to maintain it's id

	};

	/**/
};

/**/
#endif // _E_MEMENTO_ASSIGN_POINTER_DATA_OWNER_H_