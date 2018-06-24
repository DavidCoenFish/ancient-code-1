//file: Envy/EMementoEdit/EMementoEdit.h
#ifndef _E_MEMENTO_EDIT_H_
#define _E_MEMENTO_EDIT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// predefines
	/**/
	class EMementoEditCollect;

	///////////////////////////////////////////////////////
	// class
	/*
		hold and access the data describing how to edit a memento object containing typeds in IN_VARIANT
		similar to recursive data store
	*/
	template< typename IN_VARIANT >
	class EMementoEdit : public Hubris::HSmartPointerObjectBase< EMementoEdit< IN_VARIANT > >
	{
		friend EMementoEditCollect;
		//////////////////////////////////////////////
		//typedef
	private:
		typedef EMementoEdit< IN_VARIANT >TSelf;
		typedef Hubris::HContainerArray< IN_VARIANT >TArrayValue;
		typedef Hubris::HSmartPointer< TSelf >TPointer;
		typedef Hubris::HContainerTree< Hubris::HString, TPointer >TTreeStringPointer;
		typedef Hubris::HContainerArray< TPointer >TArrayPointer;
		typedef Hubris::HContainerTree< Hubris::HString, TArrayPointer >TTreeStringArrayPointer;

		//////////////////////////////////////////////
		//creation
	public:
		EMementoEdit( const EMementoEdit& in_src );
		EMementoEdit();
		~EMementoEdit();

		//////////////////////////////////////////////
		//operators
	public:
		const EMementoEdit& operator=( const EMementoEdit& in_rhs );
		const Hubris::HBOOL operator==( const EMementoEdit& in_rhs )const;
		const Hubris::HBOOL operator!=( const EMementoEdit& in_rhs )const;

		//////////////////////////////////////////////
		//public methods
	public:
		Hubris::HVOID DataSet(
			const Hubris::HString& in_comment,
			const Hubris::HSINT in_flag,
			const Hubris::HSINT in_flagUserData,
			const TArrayValue in_arrayDefaults,
			const Hubris::HSINT in_minRangeDefaultValueIndex = HCOMMON_INVALID_INDEX,
			const Hubris::HSINT in_maxRangeDefaultValueIndex = HCOMMON_INVALID_INDEX
			);

		//////////////////////////////////////////////
		//private members
	private:
		//edit format

		Hubris::HString m_comment;
		//has value, can have animation, has array
		Hubris::HSINT m_flag;
		//client user data
		Hubris::HSINT m_flagUserData;
		TArrayValue m_arrayDefaults;
		//an index of an item in the default array which is used for min value
		Hubris::HSINT m_minRangeDefaultValueIndex;
		//an index of an item in the default array which is used for max value
		Hubris::HSINT m_maxRangeDefaultValueIndex;

		TTreeStringPointer m_treeChildren;
		TTreeStringArrayPointer m_treeArrayChildren;

	};

	/**/
};

#endif // _E_MEMENTO_EDIT_H_