//file: Hubris/HVariant/HVariantImplementation.h
#ifndef _H_VARIANT_IMPLEMENTATION_H_
#define _H_VARIANT_IMPLEMENTATION_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HVariant/HVariantData.h"
#include "Hubris/HVariant/HVariantDataBase.h"
#include "Hubris/HSmartPointer/HSmartPointer.h"
#include "Hubris/HSmartPointer/HSmartPointerOperators.h"
#include "Hubris/HType/HTypeListUtility.h"

/**/
namespace Hubris
{
	/////////////////////////////////////////////////////////
	// class
	/**/
	template< class IN_TYPE_LIST >class HVariantImplementation
	{
		/////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HSmartPointer< HVariantDataBase >TVariantPointer;
	public:
		typedef IN_TYPE_LIST TTypeList;

		/////////////////////////////////////////////////////////
		// creation
	public:
		/* workaround for vs2003 Member-Template Definitions separate from its declaration failing */
		template< typename IN_TYPE >HVariantImplementation( const IN_TYPE& in_src )
		{		
			ValueSet( in_src );
			return;
		}

		HVariantImplementation( const HVariantImplementation& in_src );
		HVariantImplementation();
		~HVariantImplementation();

		/////////////////////////////////////////////////////////
		// public methods

		/* workaround for vs2003 Member-Template Definitions separate from its declaration failing */
		template< typename IN_TYPE >HVOID ValueSet( const IN_TYPE& in_src )
		{
			HCOMMON_ASSERT_STATIC( ( HCOMMON_INVALID_INDEX != HTypeListUtilIndexOf< IN_TYPE_LIST, IN_TYPE >::index ), type_not_on_type_list );
			const HSINT index = HTypeListUtilIndexOf< IN_TYPE_LIST, IN_TYPE >::index;

			if( HNULL != m_data )
			{
				if( ( index == m_data->TypeIndexGet() ) && ( 1 == m_data->RefereceCountGet().ReferenceCountGet() ) )
				{
					//we only change the smart pointer's value if we are the only one using it
					*( ( HVariantData< IN_TYPE >*)( m_data.operator ->() ) ) = in_src;
					return;
				}
				else
				{
					m_data = HNULL;
				}
			}

			HVariantDataBase* data = HNULL;
			HCOMMON_NEW_PARAM_2( data, HVariantData< IN_TYPE >, in_src, index );

			m_data = data;

			return;	
		}

		/* allow a code path for type none, but assert if actually called */
		template<>HVOID ValueSet( const HTypeNone& )
		{
			HCOMMON_ASSERT_ALWAYS( "invalid code path" );
			m_data = HNULL;
			return;
		}

		/* workaround for vs2003 Member-Template Definitions separate from its declaration failing */
		template< typename IN_TYPE >const IN_TYPE& ValueGet()const
		{
			HCOMMON_ASSERT( HNULL != m_data, "invalid data access" );
			HCOMMON_ASSERT( HTRUE == TypeTest< IN_TYPE >(), "invalid data access" );

			return( ( const HVariantData< IN_TYPE >* )( m_data.operator ->() ) )->DataGet();
		}

		/* workaround for vs2003 Member-Template Definitions separate from its declaration failing */
		template< typename IN_TYPE >IN_TYPE& ValueGet()
		{
			HCOMMON_ASSERT( HNULL != m_data, "invalid data access" );
			HCOMMON_ASSERT( HTRUE == TypeTest< IN_TYPE >(), "invalid data access" );

			const HSINT index = HTypeListUtilIndexOf< IN_TYPE_LIST, IN_TYPE >::index;
			if( 1 == m_data->RefereceCountGet().ReferenceCountGet() )
			{
				return( (HVariantData< IN_TYPE >*)( m_data.operator ->() ) )->DataGet();
			}

			//clone on non const access
			HVariantDataBase* data = HNULL;
			HCOMMON_NEW_PARAM_2( data, HVariantData< IN_TYPE >, ( (HVariantData< IN_TYPE >*)( m_data.operator ->() ) )->DataGet(), index );

			m_data = data;

			return( (HVariantData< IN_TYPE >*)( m_data.operator ->() ) )->DataGet();
		}

		//test if the variant is of the given type
		/* workaround for vs2003 Member-Template Definitions separate from its declaration failing */
		template< typename IN_TYPE > const HBOOL TypeTest()const
		{
			if( HNULL == m_data )
			{
				return HFALSE;
			}
			return( HTypeListUtilIndexOf< IN_TYPE_LIST, IN_TYPE >::index == m_data->TypeIndexGet() );
		}

		//return the typelist index of the type
		const HSINT TypeIndexGet()const;

		/////////////////////////////////////////////////////////
		// operator

		const HVariantImplementation& operator=( const HVariantImplementation & in_rhs );
		const HBOOL operator==( const HVariantImplementation& in_rhs )const;
		const HBOOL operator!=( const HVariantImplementation& in_rhs )const;

		const HBOOL TypesMatch( const HVariantImplementation& in_rhs )const;

		//INTERNAL COMPILER ERROR now this is inherited, damn
		//template< typename IN_TYPE >operator IN_TYPE()const
		//{
		//	HCOMMON_ASSERT( HNULL != m_data, "invalid data access" );
		//	const HBOOL indexCorrect = HTypeListUtilIndexOf< IN_TYPE_LIST, IN_TYPE >::index == m_data->TypeIndexGet();
		//	HCOMMON_ASSERT( HTRUE == indexCorrect, "invalid data access" );

		//	return( ( HVariantData< IN_TYPE >* )( m_data.operator ->() ) )->DataGet();
		//}

		/////////////////////////////////////////////////////////
		// private members
	private:
		TVariantPointer m_data;

	};

	/**/
	template< class IN_TYPE_LIST >
	HVariantImplementation< IN_TYPE_LIST >::HVariantImplementation( const HVariantImplementation& in_src )
	{
		( *this ) = in_src;
		return;
	}

	/**/
	template< class IN_TYPE_LIST >
	HVariantImplementation< IN_TYPE_LIST >::HVariantImplementation()
	{
		return;
	}

	/**/
	template< class IN_TYPE_LIST >
	HVariantImplementation< IN_TYPE_LIST >::~HVariantImplementation()	
	{
		m_data = HNULL;
		return;
	}

	/**/
	template< class IN_TYPE_LIST >
	const HVariantImplementation< IN_TYPE_LIST >& HVariantImplementation< IN_TYPE_LIST >::operator =( const HVariantImplementation< IN_TYPE_LIST >& in_rhs )
	{
		if( (this != &in_rhs) && ( (*this) != in_rhs ) )
		{
			m_data = in_rhs.m_data;
		}

		return( *this );
	}


	/**/
	template< class IN_TYPE_LIST >
	const HBOOL HVariantImplementation< IN_TYPE_LIST >::operator ==( const HVariantImplementation< IN_TYPE_LIST > & in_rhs ) const
	{
		HBOOL match = HFALSE;

		if( &m_data == &in_rhs.m_data )
		{
			match = HTRUE;
		}
		else if( (m_data != HNULL) && (in_rhs.m_data != HNULL) )
		{
			match = m_data->Cmp( *in_rhs.m_data );
		}
		else if( (m_data == HNULL) && (in_rhs.m_data == HNULL) )
		{
			match = HTRUE;
		}

		return match;
	}

	/**/
	template< class IN_TYPE_LIST >
	const HBOOL HVariantImplementation< IN_TYPE_LIST >::operator !=( const HVariantImplementation< IN_TYPE_LIST > & in_rhs )const
	{
		return!( operator ==( in_rhs ) );
	}

	/**/
	template< class IN_TYPE_LIST >
	const HBOOL HVariantImplementation< IN_TYPE_LIST >::TypesMatch( const HVariantImplementation& in_rhs )const
	{
		if( ( m_data == HNULL ) && ( in_rhs.m_data == HNULL ) )
		{
			return HTRUE;
		}
		else if( ( m_data == HNULL ) || ( in_rhs.m_data == HNULL ) )
		{
			return HFALSE;
		}
		else if( m_data->TypeIndexGet() == in_rhs.m_data->TypeIndexGet() )
		{
			return HTRUE;
		}

		return HFALSE;
	}

	/**/
	template< class IN_TYPE_LIST >
	const HSINT HVariantImplementation< IN_TYPE_LIST >::TypeIndexGet()const
	{
		if( HNULL != m_data )
		{
			return m_data->TypeIndexGet();
		}

		return HCOMMON_INVALID_INDEX;
	}

	/**/

};

#endif // _H_VARIANT_IMPLEMENTATION_H_