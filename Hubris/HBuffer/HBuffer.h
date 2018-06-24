//file: Hubris/HBuffer/HBuffer.h
#ifndef _H_BUFFER_H_
#define _H_BUFFER_H_

#include "Hubris/HCommon/HCommonType.h"

/*
	generic resizeable data buffer, support copy, assignment, 
*/
namespace Hubris
{
	class HBuffer
	{
		///////////////////////////////////////////////////////////
		// creation
	public:
		HBuffer( const HBuffer& in_src );
		HBuffer( const HVOID* const in_src, const HSINT in_size );
		HBuffer();
		~HBuffer();

		//////////////////////////////////////////
		// operators
	public:
		//see HBufferOperators.h for other operators
		const HBuffer& operator =( const HBuffer& in_rhs );
		const HBOOL operator ==( const HBuffer& in_rhs )const;
		const HBOOL operator !=( const HBuffer& in_rhs )const;

		//////////////////////////////////////////
		// accessor
	public:
		//get data, can be null if size is zero
		const HVOID* const RawGet() const { return m_data; }
		//this is not a safe function, supplied for likes of printf on obligation that size was set before calling this to be filled in
		HVOID* RawGet() { return m_data; }

		HVOID DataSet( const HVOID* const in_src, const HSINT in_size, const HSINT in_offset = 0 );
		HVOID DataGet( HVOID* const in_dest, const HSINT in_size, const HSINT in_offset = 0 ) const;

		HSINT SizeGet() const { return m_size; }
		HVOID SizeSet( const HSINT in_size );
		//change size and attempt to preserve contents
		HVOID SizeResize( const HSINT in_size );
		HVOID Clear();

		//////////////////////////////////////////
		// private mebers
	private:
		HVOID* m_data;
		HSINT m_size;

	};
};

#endif// _H_BUFFER_H_
