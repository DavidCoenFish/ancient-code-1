//file: Hubris/HString/HString.h
#ifndef _H_STRING_H_
#define _H_STRING_H_

#include "Hubris/HCommon/HCommonType.h"
#include <string>

/**/
namespace Hubris
{
	//////////////////////////////////////////
	// class
	//see HStringUtility for methods that operator on strings
	//see HStringOperators for operators
	//see HTraitStringIn for base types to string
	//see HTraitStringOut for string to base types
	class HString
	{
		///////////////////////////////////////////////////////////
		// typedef
	//public: HCHAR under obligation to match type in HString
		//typedef HCHAR TCharacter; 
	private:
		typedef std::string TImplementationString;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HString( const HString& in_src );
		HString( const HCHAR* const in_src );
		HString( const HCHAR in_src );
		HString( const HSINT in_src ); // for HNULL construct only, assert on non null
		HString();
		~HString();

		//////////////////////////////////////////
		// operators, for other operators, see HStringOperators
	public:
		const HString& operator =( const HString& in_rhs );
		const HString& operator =( const HCHAR* const in_rhs );
		const HString& operator =( const HCHAR in_rhs );
		const HString& operator =( const HSINT in_rhs ); // for HNULL assign only, assert on non null

		const HCHAR operator[]( const HSINT in_index ) const;
		HCHAR& operator[]( const HSINT in_index );

		//////////////////////////////////////////
		// accessor
	public:
		//get data, "" if empty ie, ('\0')
		const HCHAR* const RawGet() const;

		//doesn't include trailing zero (nb of char)
		HSINT SizeGet() const;
		// returns new size, internally adds one for trailing EOS
		HSINT SizeSet( const HSINT in_size );
		// returns new size, internally adds one for trailing EOS, preserve string contents
		HSINT SizeResize( const HSINT in_size );

		HBOOL IsEmpty()const{ return( 0 == SizeGet() ); }

		//////////////////////////////////////////
		// public methods
	public:
		//convienence function, SizeSet(0) could be used
		HVOID Clear();
		// assert on attempt to write data out of range
		HVOID DataSet( const HCHAR* const in_data, const HSINT in_size, const HSINT in_offset );

		//////////////////////////////////////////
		// private members
	private:
		//TImplementationString m_data;
		std::string m_data;

	};
};

#endif // _H_STRING_H_