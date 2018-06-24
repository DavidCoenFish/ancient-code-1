//file: Pride/PAnimation/PAnimationImplementation.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PAnimation/PAnimationImplementation.h"

#include "Pride/PAnimation/PAnimationDataBase.h"

#include< Hubris/HMath/HMath_Export.h >
#include< Hubris/HVariables/HVariables_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// creation
/**/
PAnimationImplementation::PAnimationImplementation( const PAnimationImplementation& in_src )
: m_arrayDataPointer()
, m_timeRangeLow( HVariablesMath::MaximumGet< HREAL >() )
, m_timeRangeHigh( HVariablesMath::MinimumGet< HREAL >() )
{
	( *this ) = in_src;
	return;
}

/**/
PAnimationImplementation::PAnimationImplementation()
: m_arrayDataPointer()
, m_timeRangeLow( HVariablesMath::MaximumGet< HREAL >() )
, m_timeRangeHigh( HVariablesMath::MinimumGet< HREAL >() )
{
	return;
}

/**/
PAnimationImplementation::~PAnimationImplementation()
{
	return;
}

///////////////////////////////////////////////////////
// operators
/**/
const PAnimationImplementation& PAnimationImplementation::operator=( const PAnimationImplementation& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		m_arrayDataPointer.Clear();
		HCOMMON_FOR_EACH_CONST( pData, in_rhs.m_arrayDataPointer, TArrayDataPointer )
		{
			m_arrayDataPointer.Insert( PAnimationDataBasePointer( pData->Clone() ) );
		}
		m_timeRangeLow = in_rhs.m_timeRangeLow;
		m_timeRangeHigh = in_rhs.m_timeRangeHigh;

	}

	return( *this );
}

/**/
Hubris::HBOOL PAnimationImplementation::operator==( const PAnimationImplementation& in_rhs )const
{
	HBOOL match = HTRUE;

	if( this != ( &in_rhs ) )
	{
		match &= ( m_arrayDataPointer.SizeGet() == in_rhs.m_arrayDataPointer.SizeGet() );
		match &= ( m_timeRangeLow == in_rhs.m_timeRangeLow );
		match &= ( m_timeRangeHigh == in_rhs.m_timeRangeHigh );

		if( HTRUE == match )
		{
			for( HSINT index = 0; index < m_arrayDataPointer.SizeGet(); ++index )
			{
				match &= m_arrayDataPointer[ index ]->Cmp( in_rhs.m_arrayDataPointer[ index ].RawGet() );
				if( HFALSE == match )
				{
					break;
				}
			}
		}
	}

	return match;
}

/**/
Hubris::HBOOL PAnimationImplementation::operator!=( const PAnimationImplementation& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// public methods
/**/
const Hubris::HBOOL PAnimationImplementation::IsEmpty()const
{
	return( 0 == m_arrayDataPointer.SizeGet() );
}

/**/
HVOID PAnimationImplementation::Clear()
{
	( *this ) = PAnimationImplementation();
	return;
}

/**/
HVOID PAnimationImplementation::DataRemove( const Hubris::HString& in_name )
{
	for( TArrayDataPointer::TIterator iterator = m_arrayDataPointer.Begin(); iterator != m_arrayDataPointer.End(); ++iterator )
	{
		if( in_name == ( *iterator )->NameGet() )
		{
			iterator = m_arrayDataPointer.Remove( iterator );
		}
	}

	return;
}

/**/
HVOID PAnimationImplementation::DataRename( const Hubris::HString& in_oldName, const Hubris::HString& in_newName )
{
	HCOMMON_FOR_EACH( data, m_arrayDataPointer, TArrayDataPointer )
	{
		if( data->NameGet() == in_oldName )
		{
			data->NameSet( in_newName );
		}
	}

	return;
}

/**/
HVOID PAnimationImplementation::DataAdd( PAnimationDataBasePointer& in_pAnimationDataBase )
{
	HCOMMON_ASSERT( HNULL != in_pAnimationDataBase, "invalid param" );
	m_arrayDataPointer.Insert( in_pAnimationDataBase );

	HREAL timeLow;
	HREAL timeHigh;
	in_pAnimationDataBase->TimeRangeGet( timeLow, timeHigh );

	m_timeRangeLow = HMathUtility::Minimum( m_timeRangeLow, timeLow );
	m_timeRangeHigh = HMathUtility::Maximum( m_timeRangeHigh, timeHigh );

	return;
}

/**/
HVOID PAnimationImplementation::NameArrayGet( TArrayString& out_arrayName )const
{
	out_arrayName.Clear();

	HCOMMON_FOR_EACH_CONST( pData, m_arrayDataPointer, TArrayDataPointer )
	{
		HCOMMON_ASSERT( HNULL != pData, "invalid member" );
		out_arrayName.Insert( pData->NameGet() );
	}

	return;
}

/**/
HVOID PAnimationImplementation::TimeKeyGet( const Hubris::HString& in_name, TArrayReal& out_arrayTime )const
{
	out_arrayTime.Clear();

	HCOMMON_FOR_EACH_CONST( pData, m_arrayDataPointer, TArrayDataPointer )
	{
		HCOMMON_ASSERT( HNULL != pData, "invalid member" );
		if( in_name != pData->NameGet() )
		{
			continue;
		}

		pData->TimeGet( out_arrayTime );
		break;
	}

	return;
}

/**/
HVOID PAnimationImplementation::TimeRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const
{
	out_timeLow = m_timeRangeLow;
	out_timeHigh = m_timeRangeHigh;
	return;
}

/**/
HVOID PAnimationImplementation::SubmitVisitor( const Hubris::HREAL in_time, PInterfaceAnimationVisitor& out_visitor )const
{
	HCOMMON_FOR_EACH_CONST( pData, m_arrayDataPointer, TArrayDataPointer )
	{
		HCOMMON_ASSERT( HNULL != pData, "invalid member" );
		pData->SubmitVisitor( in_time, out_visitor );
	}

	return;
}

/**/
Hubris::HVOID PAnimationImplementation::SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const
{
	HCOMMON_FOR_EACH_CONST( pData, m_arrayDataPointer, TArrayDataPointer )
	{
		HCOMMON_ASSERT( HNULL != pData, "invalid member" );
		pData->SubmitVisitorKeys( out_visitorKeys );
	}

	return;
}

/**/

