//file: Vanity/VAnimation/VAnimationStream.cpp

#include "Vanity/VanityPreCompileHeader.h"
#include "Vanity/VAnimation/VAnimationStream.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Vanity;

/////////////////////////////////////////////////////////////////
// typedef
/**/
struct TTypeData
{
	enum TEnum
	{
		TSint = 1, //is NOT default
		TReal,
		TVectorR2,
		TVectorR3,
		TVectorR4,

		TCount
	};
};

///////////////////////////////////////////////////////
// creation
/**/
VAnimationStream::VAnimationStream( const VAnimationStream& in_src )
: m_flag( 0 )
, m_pData( HNULL )
{
	( *this ) = in_src;
	return;
}

/**/
VAnimationStream::VAnimationStream()
: m_flag( 0 )
, m_pData( HNULL )
{
	return;
}

/**/
VAnimationStream::~VAnimationStream()
{
	ResourceRelease();
	return;
}

///////////////////////////////////////////////////////
// operator
/**/
const VAnimationStream& VAnimationStream::operator=( const VAnimationStream& in_rhs )
{
	if( ( *this ) != in_rhs )
	{
		TypeDataSet( in_rhs.TypeDataGet() );

		switch( in_rhs.TypeDataGet() )
		{
		default:
			{
				break;
			}
		case TTypeData::TSint:
			{
				AnimationDataSintGet() = in_rhs.AnimationDataSintGet();
				break;
			}
		case TTypeData::TReal:
			{
				AnimationDataRealGet() = in_rhs.AnimationDataRealGet();
				break;
			}
		case TTypeData::TVectorR2:
			{
				AnimationDataVectorR2Get() = in_rhs.AnimationDataVectorR2Get();
				break;
			}
		case TTypeData::TVectorR3:
			{
				AnimationDataVectorR3Get() = in_rhs.AnimationDataVectorR3Get();
				break;
			}
		case TTypeData::TVectorR4:
			{
				AnimationDataVectorR4Get() = in_rhs.AnimationDataVectorR4Get();
				break;
			}
		}
	}
	return( *this );
}

/**/
const Hubris::HBOOL VAnimationStream::operator==( const VAnimationStream& in_rhs )const
{
	HBOOL match = HTRUE;
	if( this != ( &in_rhs ) )
	{
		match &= ( m_flag == in_rhs.m_flag );
		if( HTRUE == match )
		{
			switch( in_rhs.TypeDataGet() )
			{
			default:
				{
					break;
				}
			case TTypeData::TSint:
				{
					match &= ( AnimationDataSintGet() == in_rhs.AnimationDataSintGet() );
					break;
				}
			case TTypeData::TReal:
				{
					match &= ( AnimationDataRealGet() == in_rhs.AnimationDataRealGet() );
					break;
				}
			case TTypeData::TVectorR2:
				{
					match &= ( AnimationDataVectorR2Get() == in_rhs.AnimationDataVectorR2Get() );
					break;
				}
			case TTypeData::TVectorR3:
				{
					match &= ( AnimationDataVectorR3Get() == in_rhs.AnimationDataVectorR3Get() );
					break;
				}
			case TTypeData::TVectorR4:
				{
					match &= ( AnimationDataVectorR4Get() == in_rhs.AnimationDataVectorR4Get() );
					break;
				}
			}
		}
	}

	return match;
}

/**/
const Hubris::HBOOL VAnimationStream::operator!=( const VAnimationStream& in_rhs )const
{
	return( !( operator==( in_rhs ) ) );
}

///////////////////////////////////////////////////////
// private methods
/**/
Hubris::HVOID VAnimationStream::ResourceCreate()
{
	switch( TypeDataGet() )
	{
	default:
		{
			break;
		}
	case TTypeData::TSint:
		{
			HCOMMON_NEW( m_pData, VAnimationDataSint );
			break;
		}
	case TTypeData::TReal:
		{
			HCOMMON_NEW( m_pData, VAnimationDataReal );
			break;
		}
	case TTypeData::TVectorR2:
		{
			HCOMMON_NEW( m_pData, VAnimationDataVectorR2 );
			break;
		}
	case TTypeData::TVectorR3:
		{
			HCOMMON_NEW( m_pData, VAnimationDataVectorR3 );
			break;
		}
	case TTypeData::TVectorR4:
		{
			HCOMMON_NEW( m_pData, VAnimationDataVectorR4 );
			break;
		}
	}

	return;
}

/**/
Hubris::HVOID VAnimationStream::ResourceRelease()
{
	if( HNULL == m_pData )
	{
		return;
	}

	switch( TypeDataGet() )
	{
	default:
		{
			break;
		}
	case TTypeData::TSint:
		{
			HCOMMON_DELETE( m_pData, VAnimationDataSint );
			break;
		}
	case TTypeData::TReal:
		{
			HCOMMON_DELETE( m_pData, VAnimationDataReal );
			break;
		}
	case TTypeData::TVectorR2:
		{
			HCOMMON_DELETE( m_pData, VAnimationDataVectorR2 );
			break;
		}
	case TTypeData::TVectorR3:
		{
			HCOMMON_DELETE( m_pData, VAnimationDataVectorR3 );
			break;
		}
	case TTypeData::TVectorR4:
		{
			HCOMMON_DELETE( m_pData, VAnimationDataVectorR4 );
			break;
		}
	}

	return;
}
///////////////////////////////////////////////////////
// public accessors
/**/
const Hubris::HSINT VAnimationStream::TypeDataGet()const
{
	return m_flag;
}

/**/
Hubris::HVOID VAnimationStream::TypeDataSet( const Hubris::HSINT in_typeData )
{
	ResourceRelease();
	m_flag = in_typeData;
	ResourceCreate();
	return;
}

/**/
const VAnimationDataSint& VAnimationStream::AnimationDataSintGet()const
{
	HCOMMON_ASSERT( TTypeData::TSint == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataSint* )m_pData );
}

/**/
VAnimationDataSint& VAnimationStream::AnimationDataSintGet()
{
	HCOMMON_ASSERT( TTypeData::TSint == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataSint* )m_pData );
}

/**/
const VAnimationDataReal& VAnimationStream::AnimationDataRealGet()const
{
	HCOMMON_ASSERT( TTypeData::TReal == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataReal* )m_pData );
}

/**/
VAnimationDataReal& VAnimationStream::AnimationDataRealGet()
{
	HCOMMON_ASSERT( TTypeData::TReal == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataReal* )m_pData );
}

/**/
const VAnimationDataVectorR2& VAnimationStream::AnimationDataVectorR2Get()const
{
	HCOMMON_ASSERT( TTypeData::TVectorR2 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR2* )m_pData );
}

/**/
VAnimationDataVectorR2& VAnimationStream::AnimationDataVectorR2Get()
{
	HCOMMON_ASSERT( TTypeData::TVectorR2 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR2* )m_pData );
}

/**/
const VAnimationDataVectorR3& VAnimationStream::AnimationDataVectorR3Get()const
{
	HCOMMON_ASSERT( TTypeData::TVectorR3 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR3* )m_pData );
}

/**/
VAnimationDataVectorR3& VAnimationStream::AnimationDataVectorR3Get()
{
	HCOMMON_ASSERT( TTypeData::TVectorR3 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR3* )m_pData );
}

/**/
const VAnimationDataVectorR4& VAnimationStream::AnimationDataVectorR4Get()const
{
	HCOMMON_ASSERT( TTypeData::TVectorR4 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR4* )m_pData );
}

/**/
VAnimationDataVectorR4& VAnimationStream::AnimationDataVectorR4Get()
{
	HCOMMON_ASSERT( TTypeData::TVectorR4 == TypeDataGet(), "invalid state" );
	return( *( VAnimationDataVectorR4* )m_pData );
}

///////////////////////////////////////////////////////
// static public accessors
/**/
const Hubris::HSINT VAnimationStream::TypeDataGetSint()
{
	return TTypeData::TSint;
}

/**/
const Hubris::HSINT VAnimationStream::TypeDataGetReal()
{
	return TTypeData::TReal;
}

/**/
const Hubris::HSINT VAnimationStream::TypeDataGetVectorR2()
{
	return TTypeData::TVectorR2;
}

/**/
const Hubris::HSINT VAnimationStream::TypeDataGetVectorR3()
{
	return TTypeData::TVectorR3;
}

/**/
const Hubris::HSINT VAnimationStream::TypeDataGetVectorR4()
{
	return TTypeData::TVectorR4;
}

/**/
