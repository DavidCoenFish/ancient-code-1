//file: Hubris/HBuffer/HBufferOperators.cpp
#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBuffer/HBufferOperators.h"

#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonMemory.h"


///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// global free methods
/**/
const HBuffer Hubris::operator +( const HBuffer& in_lhs, const HBuffer& in_rhs )
{
	HBuffer result( in_lhs );
	result += in_rhs;
	return result;
}

/**/
const HBuffer& Hubris::operator +=( HBuffer& in_lhs, const HBuffer& in_rhs )
{
	const HSINT sizeLhs = in_lhs.SizeGet();
	const HSINT sizeRhs = in_rhs.SizeGet();

	in_lhs.SizeResize( sizeLhs + sizeRhs );

	in_lhs.DataSet( in_rhs.RawGet(), sizeRhs, sizeLhs );

	return in_lhs;
}

/**/
const HBOOL Hubris::operator <( const HBuffer & in_lhs, const HBuffer & in_rhs )
{
	const HSINT sizeLhs = in_lhs.SizeGet();
	const HSINT sizeRhs = in_rhs.SizeGet();
	if( sizeLhs != sizeRhs )
	{
		return( sizeLhs < sizeRhs );
	}
	if( 0 != sizeRhs )
	{
		//do we actually need a memory cmp, or can just use address?
		//return( in_lhs.RawGet() < in_rhs.RawGet() );
		return( HCommonMemory::MemoryCompair( in_lhs.RawGet(), in_rhs.RawGet(), sizeLhs ) < 0 );
	}

	return HFALSE;
}

/**/
