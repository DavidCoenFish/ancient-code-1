//file: Hubris/HMatrix/HMatrix.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrix.h"

#include "Hubris/HMatrix/HMatrixOperator.h"
#include "Hubris/HMatrix/HMatrixImplementation.h"

#include "Hubris/HCommon/HCommonAssert.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/*what would i need to do to get a general HMatrix constructo to work, matching coords set*/
//template< HSINT IN_OTHER_WIDTH, HSINT IN_OTHER_HEIGHT > HMatrix( const HMatrix< IN_TYPE, IN_OTHER_WIDTH, IN_OTHER_HEIGHT >& in_src )

////////////////////////////////////////////////////
// template definitions
/**/
template class Hubris::HMatrix< HU8, 1, 1 >;
template class Hubris::HMatrix< HU8, 1, 2 >;
template class Hubris::HMatrix< HU8, 1, 3 >;
template class Hubris::HMatrix< HU8, 1, 4 >;
template class Hubris::HMatrix< HU8, 1, 5 >;
template class Hubris::HMatrix< HU8, 2, 1 >;
template class Hubris::HMatrix< HU8, 2, 2 >;
template class Hubris::HMatrix< HU8, 2, 3 >;
template class Hubris::HMatrix< HU8, 2, 4 >;
template class Hubris::HMatrix< HU8, 2, 5 >;
template class Hubris::HMatrix< HU8, 3, 1 >;
template class Hubris::HMatrix< HU8, 3, 2 >;
template class Hubris::HMatrix< HU8, 3, 3 >;
template class Hubris::HMatrix< HU8, 3, 4 >;
template class Hubris::HMatrix< HU8, 3, 5 >;
template class Hubris::HMatrix< HU8, 4, 1 >;
template class Hubris::HMatrix< HU8, 4, 2 >;
template class Hubris::HMatrix< HU8, 4, 3 >;
template class Hubris::HMatrix< HU8, 4, 4 >;
template class Hubris::HMatrix< HU8, 4, 5 >;
template class Hubris::HMatrix< HU8, 5, 1 >;
template class Hubris::HMatrix< HU8, 5, 2 >;
template class Hubris::HMatrix< HU8, 5, 3 >;
template class Hubris::HMatrix< HU8, 5, 4 >;
template class Hubris::HMatrix< HU8, 5, 5 >;

template class Hubris::HMatrix< HSINT, 1, 1 >;
template class Hubris::HMatrix< HSINT, 1, 2 >;
template class Hubris::HMatrix< HSINT, 1, 3 >;
template class Hubris::HMatrix< HSINT, 1, 4 >;
template class Hubris::HMatrix< HSINT, 1, 5 >;
template class Hubris::HMatrix< HSINT, 2, 1 >;
template class Hubris::HMatrix< HSINT, 2, 2 >;
template class Hubris::HMatrix< HSINT, 2, 3 >;
template class Hubris::HMatrix< HSINT, 2, 4 >;
template class Hubris::HMatrix< HSINT, 2, 5 >;
template class Hubris::HMatrix< HSINT, 3, 1 >;
template class Hubris::HMatrix< HSINT, 3, 2 >;
template class Hubris::HMatrix< HSINT, 3, 3 >;
template class Hubris::HMatrix< HSINT, 3, 4 >;
template class Hubris::HMatrix< HSINT, 3, 5 >;
template class Hubris::HMatrix< HSINT, 4, 1 >;
template class Hubris::HMatrix< HSINT, 4, 2 >;
template class Hubris::HMatrix< HSINT, 4, 3 >;
template class Hubris::HMatrix< HSINT, 4, 4 >;
template class Hubris::HMatrix< HSINT, 4, 5 >;
template class Hubris::HMatrix< HSINT, 5, 1 >;
template class Hubris::HMatrix< HSINT, 5, 2 >;
template class Hubris::HMatrix< HSINT, 5, 3 >;
template class Hubris::HMatrix< HSINT, 5, 4 >;
template class Hubris::HMatrix< HSINT, 5, 5 >;

template class Hubris::HMatrix< HREAL, 1, 1 >;
template class Hubris::HMatrix< HREAL, 1, 2 >;
template class Hubris::HMatrix< HREAL, 1, 3 >;
template class Hubris::HMatrix< HREAL, 1, 4 >;
template class Hubris::HMatrix< HREAL, 1, 5 >;
template class Hubris::HMatrix< HREAL, 2, 1 >;
template class Hubris::HMatrix< HREAL, 2, 2 >;
template class Hubris::HMatrix< HREAL, 2, 3 >;
template class Hubris::HMatrix< HREAL, 2, 4 >;
template class Hubris::HMatrix< HREAL, 2, 5 >;
template class Hubris::HMatrix< HREAL, 3, 1 >;
template class Hubris::HMatrix< HREAL, 3, 2 >;
template class Hubris::HMatrix< HREAL, 3, 3 >;
template class Hubris::HMatrix< HREAL, 3, 4 >;
template class Hubris::HMatrix< HREAL, 3, 5 >;
template class Hubris::HMatrix< HREAL, 4, 1 >;
template class Hubris::HMatrix< HREAL, 4, 2 >;
template class Hubris::HMatrix< HREAL, 4, 3 >;
template class Hubris::HMatrix< HREAL, 4, 4 >;
template class Hubris::HMatrix< HREAL, 4, 5 >;
template class Hubris::HMatrix< HREAL, 5, 1 >;
template class Hubris::HMatrix< HREAL, 5, 2 >;
template class Hubris::HMatrix< HREAL, 5, 3 >;
template class Hubris::HMatrix< HREAL, 5, 4 >;
template class Hubris::HMatrix< HREAL, 5, 5 >;

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::HMatrix( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_src )
{
	( *this ) = in_src;

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::HMatrix( const IN_TYPE * const in_data )
{
	DataSet( in_data );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::HMatrix( const IN_TYPE in_default )
{
	DataSet( in_default );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::~HMatrix()
{
	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
const IN_TYPE * const Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::DataGet() const
{
	return m_data;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
HVOID Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::DataSet( const IN_TYPE * const in_data )
{
	HMatrixImplementation< IN_TYPE >::DataSet( m_data, in_data, TVar::TSize );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
HVOID Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::DataSet( const IN_TYPE in_data )
{
	HMatrixImplementation< IN_TYPE >::DataSet( m_data, in_data, TVar::TSize );

	return;
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
const Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::operator=( const HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& in_rhs )
{
	if( ( this !=&in_rhs )&& ( ( *this ) != in_rhs ) )
	{
		DataSet( in_rhs.m_data );
	}

	return( *this );
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
const Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >& Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::operator=( const IN_TYPE in_value )
{
	if( ( *this ) != in_value )
	{
		DataSet( in_value );
	}

	return( *this );
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
const IN_TYPE Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::operator[]( HSINT in_index ) const
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < TVar::TSize ), "invalid param" );
	return( m_data[ in_index ] );
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
IN_TYPE& Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::operator[]( HSINT in_index )
{
	HCOMMON_ASSERT( ( 0 <= in_index ) && ( in_index < TVar::TSize ), "invalid param" );
	return( m_data[ in_index ] );
}

/**/
template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > 
HSINT Hubris::HMatrix< IN_TYPE, IN_WIDTH, IN_HEIGHT >::IndexGet( const HSINT in_x, const HSINT in_y )
{
	HCOMMON_ASSERT( ( 0 <= in_x )&& ( in_x < IN_WIDTH ), "invalid param" );
	HCOMMON_ASSERT( ( 0 <= in_y )&& ( in_y < IN_HEIGHT ), "invalid param" );

	return( ( in_y * IN_WIDTH ) + in_x );
}

/**/