//file: Sloth/SInput/SInputItemData.h
#ifndef _S_INPUT_ITEM_DATA_H_
#define _S_INPUT_ITEM_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// struct
	/**/
	class SInputItemData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SInputItemData( const SInputItemData& in_src );
		SInputItemData();
		~SInputItemData();

		///////////////////////////////////////////////////////
		// disabled
	public:
		const SInputItemData& operator=( const SInputItemData& in_rhs );
		const Hubris::HBOOL operator==( const SInputItemData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SInputItemData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Update();

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT ButtonStateNoneGet();
		static const Hubris::HSINT ButtonStateUpGet();
		static const Hubris::HSINT ButtonStateDownGet();
		static const Hubris::HSINT ButtonStateChangedToUpGet();
		static const Hubris::HSINT ButtonStateChangedToDownGet();
		static const Hubris::HSINT ButtonStateModifierGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		const Hubris::HREAL ValueGet()const{ return m_value; }
		Hubris::HVOID ValueSet( Hubris::HREAL in_value ){ m_value = in_value; return; }

		const Hubris::HREAL PreviousValueGet()const{ return m_previousValue; }
	private:
		Hubris::HVOID PreviousValueSet( Hubris::HREAL in_previousValue ){ m_previousValue = in_previousValue; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_flag;
		Hubris::HREAL m_value;
		Hubris::HREAL m_previousValue;

	};

	/**/
	
};

#endif // _S_INPUT_ITEM_DATA_H_