//file: Pride/PAnimation/PAnimation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PAnimation/PAnimation.h"

#include "Pride/PAnimation/PAnimationImplementation.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

/**/
///////////////////////////////////////////////////////
// creation
/**/
PAnimation::PAnimation( const PAnimation& in_src )
: m_pImplementation( HNULL )
{
	HCOMMON_NEW_PARAM( m_pImplementation, PAnimationImplementation, in_src.ImplementationGet() );
	return;
}

/**/
PAnimation::PAnimation()
: m_pImplementation( HNULL )
{
	HCOMMON_NEW( m_pImplementation, PAnimationImplementation );
	return;
}

/**/
PAnimation::~PAnimation()
{
	HCOMMON_DELETE( m_pImplementation, PAnimationImplementation );
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PAnimation& PAnimation::operator=( const PAnimation& in_rhs )
{
	ImplementationGet() = in_rhs.ImplementationGet();
	return( *this );
}

/**/
Hubris::HBOOL PAnimation::operator==( const PAnimation& in_rhs )const
{
	return( ImplementationGet() == in_rhs.ImplementationGet() );
}

/**/
Hubris::HBOOL PAnimation::operator!=( const PAnimation& in_rhs )const
{
	return( ImplementationGet() != in_rhs.ImplementationGet() );
}

///////////////////////////////////////////////////////
// public methods
const Hubris::HBOOL PAnimation::IsEmpty()const
{
	return ImplementationGet().IsEmpty();
}

/**/
HVOID PAnimation::NameArrayGet( TArrayString& out_arrayName )const
{
	ImplementationGet().NameArrayGet( out_arrayName );
	return;
}

/**/
HVOID PAnimation::TimeKeyGet( const Hubris::HString& in_name, TArrayReal& out_arrayTime )const
{
	ImplementationGet().TimeKeyGet( in_name, out_arrayTime );
	return;
}

/**/
HVOID PAnimation::Clear()
{
	ImplementationGet().Clear();
	return;
}

/**/
HVOID PAnimation::DataRemove( const Hubris::HString& in_name )
{
	ImplementationGet().DataRemove( in_name );
	return;
}

/**/
HVOID PAnimation::DataRename( const Hubris::HString& in_oldName, const Hubris::HString& in_newName )
{
	ImplementationGet().DataRename( in_oldName, in_newName );
	return;
}

///////////////////////////////////////////////////////
// implement PAnimationInterface
/**/
HVOID PAnimation::TimeAbsoluteRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const
{
	ImplementationGet().TimeRangeGet( out_timeLow, out_timeHigh );
	return;
}

/**/
HVOID PAnimation::SubmitVisitorAbsolute( const Hubris::HREAL in_timeAbsolute, PInterfaceAnimationVisitor& out_visitor )const
{
	ImplementationGet().SubmitVisitor( in_timeAbsolute, out_visitor );
	return;
}

/**/
HVOID PAnimation::SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const
{
	ImplementationGet().SubmitVisitorKeys( out_visitorKeys );
	return;
}

///////////////////////////////////////////////////////
// private methods
/**/
HVOID PAnimation::DataAdd( PAnimationDataBasePointer& in_pAnimationDataBase )
{
	ImplementationGet().DataAdd( in_pAnimationDataBase );
	return;
}

///////////////////////////////////////////////////////
// private accessors
/**/
const PAnimationImplementation& PAnimation::ImplementationGet()const
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}

/**/
PAnimationImplementation& PAnimation::ImplementationGet()
{
	HCOMMON_ASSERT( HNULL != m_pImplementation, "invalid member" );
	return( *m_pImplementation );
}
/**/


