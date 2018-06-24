//file: Hubris/HVariant/HVariantData.h
#ifndef _H_VARIANT_DATA_H_
#define _H_VARIANT_DATA_H_

#include "Hubris/HCommon/HCommonAssert.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HVariant/HVariantDataBase.h"
#include "Hubris/HSmartPointer/HSmartPointerOperators.h"

/**/
namespace Hubris
{
	/**/
	template< typename IN_TYPE >class HVariantData : public HVariantDataBase
	{
	public:
		HVariantData( const IN_TYPE& in_data, const HS32 in_typeIndex );
		HVariantData( const HVariantData & in_src );
		HVariantData();
		virtual ~HVariantData();

		virtual HBOOL Cmp( const HVariantDataBase& in_rhs)const;

		const IN_TYPE& DataGet()const { return m_data; }
		IN_TYPE& DataGet(){ return m_data; }
		HVOID DataSet( const IN_TYPE& in_data ) { m_data = in_data; return; }

		const HVariantData& operator =( const HVariantData& in_rhs );
		const HVariantData& operator =( const IN_TYPE& in_data );

		HBOOL operator ==( const HVariantData& in_rhs )const;
		HBOOL operator !=( const HVariantData& in_rhs )const;

		virtual HS32 TypeIndexGet()const { return m_typeIndex; }

	private:
		IN_TYPE m_data;
		//not static as  HVariantData>type> may exsist in more than one variant at different indexs
		HS32 m_typeIndex;
	};

	/**/
	template< typename IN_TYPE>
	HVariantData<IN_TYPE>::HVariantData( const IN_TYPE& in_data, const HS32 in_typeIndex ) :
		m_typeIndex( in_typeIndex )
	{
		DataSet(in_data);
		return;
	}

	/**/
	template< typename IN_TYPE >
	HVariantData< IN_TYPE >::HVariantData( const HVariantData& in_src ) :
		m_typeIndex( in_src.TypeIndexGet() )
	{
		DataSet( in_data );
		return;
	}

	/**/
	template< typename IN_TYPE >
	HVariantData< IN_TYPE >::HVariantData() :
		m_typeIndex( HCOMMON_INVALID_INDEX )
	{
		return;
	}

	/**/
	template< typename IN_TYPE >
	HVariantData< IN_TYPE >::~HVariantData()
	{
		return;
	}

	/**/
	template< typename IN_TYPE >
	HBOOL HVariantData< IN_TYPE >::Cmp( const HVariantDataBase& in_rhs )const
	{
		HBOOL match = false;
		if( TypeIndexGet() == in_rhs.TypeIndexGet() )
		{
			match = ( DataGet() == ((const HVariantData< IN_TYPE >&)in_rhs).DataGet() );
		}

		return match;
	}

	/**/
	template< typename IN_TYPE >
	const HVariantData< IN_TYPE >& HVariantData< IN_TYPE >::operator =( const HVariantData& in_rhs )
	{
		if( (this != &in_rhs) && ((*this) != in_rhs) )
		{
			DataSet( in_rhs.m_data );
		}

		return( *this );
	}

	/**/
	template< typename IN_TYPE >
	const HVariantData< IN_TYPE > & HVariantData< IN_TYPE >::operator =( const IN_TYPE& in_rhs)
	{
		if( m_data != in_rhs )
		{
			DataSet( in_rhs );
		}

		return( *this );
	}

	/**/
	template< typename IN_TYPE >
	HBOOL HVariantData< IN_TYPE >::operator ==( const HVariantData& in_rhs )const
	{
		HBOOL match = true;
		match = match && ( m_data == in_rhs );
		return match;
	}

	/**/
	template< typename IN_TYPE >
	HBOOL HVariantData< IN_TYPE >::operator !=( const HVariantData& in_rhs )const
	{
		return!( operator ==( in_rhs ) );
	}

	/**/

};

#endif // _H_VARIANT_DATA_H_