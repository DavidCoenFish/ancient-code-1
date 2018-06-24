//file: Pride/PMaterial/PMaterialImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PMaterial/PMaterialImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PMaterialImplementation::PMaterialImplementation( const PMaterialImplementation& in_src )
{
	( *this ) = in_src;
	return;
}

/**/
PMaterialImplementation::PMaterialImplementation()
{
	return;
}

/**/
PMaterialImplementation::~PMaterialImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PMaterialImplementation& PMaterialImplementation::operator=( const PMaterialImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
	}

	return( *this );
}

/**/
Hubris::HBOOL PMaterialImplementation::operator==( const PMaterialImplementation& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
	}

	return match;
}

/**/
Hubris::HBOOL PMaterialImplementation::operator!=( const PMaterialImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/
