//file: Pride/PAnimation/PAnimationData.h
#ifndef _P_ANIMATION_DATA_H_
#define _P_ANIMATION_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PAnimation/PAnimationDataBase.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		hold the keys of the animation.
		key under contract to satisfy;-
			const Hubris::HREAL TimeGet()const;
			Hubris::HVOID Evalue( PInterfaceAnimationVisitor& out_visitor, const Hubris::HString& in_targetName );
			Hubris::HVOID Evalue( PInterfaceAnimationVisitor& out_visitor, const Hubris::HString& in_targetName, const PAnimationKey& in_nextKey, const Hubris::HREAL in_time );
			Hubris::HVOID EvalueKey( PInterfaceAnimationVisitorKeys& out_visitor, const Hubris::HString& in_targetName, const PAnimationKey& in_nextKey, const Hubris::HREAL in_time );
	*/
	template< typename IN_KEY >class PAnimationData : public PAnimationDataBase
	{
		HTYPE_RUN_TIME_TYPE_INFO( PAnimationData< IN_KEY >, PAnimationDataBase );

		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Hubris::HREAL, IN_KEY >TPairTimeKey;
		typedef Hubris::HContainerArray< TPairTimeKey >TArrayPairTimeKey;

		typedef Hubris::HContainerArray< IN_KEY >TArrayKey;
		typedef Hubris::HContainerArray< Hubris::HREAL >TArrayReal;

		///////////////////////////////////////////////////////
		// creation
	public:
		PAnimationData( const PAnimationData& in_src );
		PAnimationData( const Hubris::HString& in_name, const TArrayPairTimeKey& in_arrayKey );
		~PAnimationData();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PAnimationData& operator=( const PAnimationData& in_rhs );
		const Hubris::HBOOL operator==( const PAnimationData& in_rhs )const;
		const Hubris::HBOOL operator!=( const PAnimationData& in_rhs )const;

		///////////////////////////////////////////////////////
		// implement PAnimationDataBase
	private:
		virtual PAnimationDataBase* const Clone()const;
		virtual Hubris::HVOID DeleteThis();

		virtual const Hubris::HBOOL Cmp( const PAnimationDataBase* const in_pRhs )const;

		virtual Hubris::HVOID SubmitVisitor( const Hubris::HREAL in_time, PInterfaceAnimationVisitor& out_visitor )const;
		virtual Hubris::HVOID SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const;

		virtual const Hubris::HString& NameGet()const{ return m_name; }
		virtual Hubris::HVOID NameSet( const Hubris::HString& in_name ){ m_name = in_name; }

		virtual Hubris::HVOID TimeRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const;
		virtual Hubris::HVOID TimeGet( TArrayReal& out_arrayTime )const;

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HString m_name;
		TArrayReal m_arrayTime;
		TArrayKey m_arrayKey;

	};

	/**/
	///////////////////////////////////////////////////////
	// creation
	/**/
	template< typename IN_KEY >
	PAnimationData< IN_KEY >::PAnimationData( const PAnimationData< IN_KEY >& in_src )
	: m_name()
	, m_arrayTime()
	, m_arrayKey()
	{
		( *this ) = in_src;
		return;
	}

	/**/
	template< typename IN_KEY >
	PAnimationData< IN_KEY >::PAnimationData( const Hubris::HString& in_name, const TArrayPairTimeKey& in_arrayData )
	: m_name( in_name )
	, m_arrayTime()
	, m_arrayKey()
	{
		HCOMMON_ASSERT( 0 < in_arrayData.SizeGet(), "invalid param" );

		HCOMMON_FOR_EACH_CONST( pair, in_arrayData, TArrayPairTimeKey )
		{
			HContainerUtility::PushBack( m_arrayTime, pair.m_first );
			HContainerUtility::PushBack( m_arrayKey, pair.m_second );
		}

		return;
	}

	/**/
	template< typename IN_KEY >
	PAnimationData< IN_KEY >::~PAnimationData()
	{
		return;
	}

	///////////////////////////////////////////////////////
	// operators
	/**/
	template< typename IN_KEY >
	const PAnimationData< IN_KEY >& PAnimationData< IN_KEY >::operator=( const PAnimationData& in_rhs )
	{
		if( ( *this ) != in_rhs )
		{
			m_name = in_rhs.m_name;
			m_arrayTime = in_rhs.m_arrayTime;
			m_arrayKey = in_rhs.m_arrayKey;
		}

		return( *this );
	}

	/**/
	template< typename IN_KEY >
	const Hubris::HBOOL PAnimationData< IN_KEY >::operator==( const PAnimationData& in_rhs )const
	{
		HBOOL match = HTRUE;

		if( this != ( &in_rhs ) )
		{
			match &= ( m_name == in_rhs.m_name );
			match &= ( m_arrayTime == in_rhs.m_arrayTime );
			match &= ( m_arrayKey == in_rhs.m_arrayKey );
		}

		return match;
	}

	/**/
	template< typename IN_KEY >
	const Hubris::HBOOL PAnimationData< IN_KEY >::operator!=( const PAnimationData& in_rhs )const
	{
		return( !( operator==( in_rhs ) ) );
	}

	///////////////////////////////////////////////////////
	// implement PAnimationDataBase
	/**/
	template< typename IN_KEY >
	PAnimationDataBase* const PAnimationData< IN_KEY >::Clone()const
	{
		PAnimationData< IN_KEY >* pNew = HNULL;
		HCOMMON_NEW_PARAM( pNew, PAnimationData< IN_KEY >, ( *this ) );
		return pNew;
	}

	/**/
	template< typename IN_KEY >
	Hubris::HVOID PAnimationData< IN_KEY >::DeleteThis()
	{
		HCOMMON_DELETE_THIS( this, PAnimationData< IN_KEY > );
		return;
	}

	/**/
	template< typename IN_KEY >
	const Hubris::HBOOL PAnimationData< IN_KEY >::Cmp( const PAnimationDataBase* const in_pRhs )const
	{
		const PAnimationData< IN_KEY >* const pCastRhs = HTypeRunTimeInfoCast< PAnimationDataBase, PAnimationData< IN_KEY > >( in_pRhs );
		if( HNULL == pCastRhs )
		{
			return HFALSE;
		}

		return( ( *this ) == ( *pCastRhs ) );
	}

	/**/
	template< typename IN_KEY >
	Hubris::HVOID PAnimationData< IN_KEY >::SubmitVisitor( const Hubris::HREAL in_time, PInterfaceAnimationVisitor& out_visitor )const
	{
		HBOOL beforeStart = HFALSE;
		HBOOL afterEnd = HFALSE;
		const Hubris::HSINT keyIndex = HContainerUtility::Search( m_arrayTime, in_time, beforeStart, afterEnd );
		if( ( HTRUE == beforeStart ) ||
			( HTRUE == afterEnd ) || 
			( in_time == m_arrayTime[ keyIndex ] ) )
		{
			IN_KEY::Evalue( 
				out_visitor, 
				m_name, 
				m_arrayKey[ keyIndex ] 
			);
		}
		else
		{
			IN_KEY::Evalue( 
				out_visitor, 
				m_name, 
				m_arrayKey,
				m_arrayTime,
				keyIndex,
				in_time
			);
		}

		return;
	}

	/**/
	template< typename IN_KEY >
	Hubris::HVOID PAnimationData< IN_KEY >::SubmitVisitorKeys( PInterfaceAnimationVisitorKeys& out_visitorKeys )const
	{
		const Hubris::HSINT count = m_arrayTime.SizeGet();
		for( Hubris::HSINT index = 0; index < count; ++index )
		{
			IN_KEY::EvalueKey( 
				out_visitorKeys, 
				m_name, 
				m_arrayKey[ index ],
				m_arrayTime[ index ]
				);
		}

		return;
	}

	/**/
	template< typename IN_KEY >
	Hubris::HVOID PAnimationData< IN_KEY >::TimeRangeGet( Hubris::HREAL& out_timeLow, Hubris::HREAL& out_timeHigh )const
	{
		out_timeLow = HContainerUtility::Front( m_arrayTime );
		out_timeHigh = HContainerUtility::Back( m_arrayTime );

		return;
	}

	/**/
	template< typename IN_KEY >
	Hubris::HVOID PAnimationData< IN_KEY >::TimeGet( TArrayReal& out_arrayTime )const
	{
		out_arrayTime = m_arrayTime;
		return;
	}

	/**/

};

#endif // _P_ANIMATION_H_