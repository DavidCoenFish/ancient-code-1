//file: Hubris/HContainer/HContainerPair.h
#ifndef _H_CONTAINER_PAIR_H_
#define _H_CONTAINER_PAIR_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"

namespace Hubris
{
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair
	{
		///////////////////////////////////////////////////////////////
		// creation
	public:
		HContainerPair( const IN_FIRST& in_first, const IN_SECOND& in_second );
		HContainerPair( const HContainerPair& in_src );
		HContainerPair();
		~HContainerPair();

		///////////////////////////////////////////////////////////////
		// operators
	public:
		const HContainerPair& operator=(const HContainerPair & in_rhs);
		HBOOL operator==(const HContainerPair & in_rhs)const;
		HBOOL operator!=(const HContainerPair & in_rhs)const;
		HBOOL operator<(const HContainerPair & in_rhs)const;

		///////////////////////////////////////////////////////////////
		// public members
	public:
		IN_FIRST m_first;
		IN_SECOND m_second;

	};

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HContainerPair< IN_FIRST, IN_SECOND >::HContainerPair( const IN_FIRST& in_first, const IN_SECOND& in_second )
	: m_first( in_first )
	, m_second( in_second ) 
	{ 
		return; 
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HContainerPair< IN_FIRST, IN_SECOND >::HContainerPair( const HContainerPair & in_src )
	: m_first()
	, m_second() 
	{ 
		( *this ) = in_src;
		return; 
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HContainerPair< IN_FIRST, IN_SECOND >::HContainerPair()
	: m_first()
	, m_second() 
	{ 
		
		return; 
	}
	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HContainerPair< IN_FIRST, IN_SECOND >::~HContainerPair() 
	{ 		
		return; 
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	const HContainerPair< IN_FIRST, IN_SECOND >& HContainerPair< IN_FIRST, IN_SECOND >::operator=( const HContainerPair< IN_FIRST, IN_SECOND >& in_rhs )
	{		
		if( *this != in_rhs )
		{
			m_first = in_rhs.m_first;
			m_second = in_rhs.m_second;
		}

		return( *this );
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HBOOL HContainerPair< IN_FIRST, IN_SECOND >::operator==( const HContainerPair< IN_FIRST, IN_SECOND >& in_rhs )const
	{	
		HBOOL match = true;

		if( this != &in_rhs )
		{
			match = match && ( m_first == in_rhs.m_first );
			match = match && ( m_second == in_rhs.m_second );
		}

		return match;
	}

	/**/
	template< typename IN_FIRST, typename IN_SECOND > 
	HBOOL HContainerPair< IN_FIRST, IN_SECOND >::operator!=( const HContainerPair< IN_FIRST, IN_SECOND >& in_rhs )const
	{	
		return!( operator==( in_rhs ) );
	}

	/**/
	template <typename IN_FIRST, typename IN_SECOND> 
	HBOOL HContainerPair<IN_FIRST, IN_SECOND>::operator<(const HContainerPair<IN_FIRST, IN_SECOND> & in_rhs)const
	{	
		if( m_first < in_rhs.m_first )
		{
			return HTRUE;
		}
		else if( m_first != in_rhs.m_first )
		{
			return HFALSE;
		}

		if( m_second < in_rhs.m_second )
		{
			return HTRUE;
		}
		
		return HFALSE;
	}

	/**/
};

#endif// _H_CONTAINER_PAIR_H_
