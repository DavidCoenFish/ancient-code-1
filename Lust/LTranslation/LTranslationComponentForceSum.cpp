//file: Lust/LTranslation/LTranslationComponentForceSum.cpp

#include "Lust/LustPreCompileHeader.h"
#include "Lust/LTranslation/LTranslationComponentForceSum.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

///////////////////////////////////////////////////////
// typedef
/**/
LTranslationComponentForceSum::LTranslationComponentForceSum( const LTranslationComponentForceSum& in_src )
: m_forceSum()
{
	( *this ) = in_src;
	return;
}

/**/
LTranslationComponentForceSum::LTranslationComponentForceSum()
: m_forceSum()
{
	return;
}

/**/
LTranslationComponentForceSum::~LTranslationComponentForceSum()
{
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const LTranslationComponentForceSum& LTranslationComponentForceSum::operator=( const LTranslationComponentForceSum& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_forceSum = in_rhs.m_forceSum;
	}

	return( *this );
}

/**/
const Hubris::HBOOL LTranslationComponentForceSum::operator==( const LTranslationComponentForceSum& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_forceSum == in_rhs.m_forceSum );
	}

	return match;
}

/**/
const Hubris::HBOOL LTranslationComponentForceSum::operator!=( const LTranslationComponentForceSum& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

/**/