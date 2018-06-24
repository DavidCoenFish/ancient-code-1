//file: Pride/PGeometry/PGeometryStoreData.h
#ifndef _P_GEOMETRY_STORE_DATA_H_
#define _P_GEOMETRY_STORE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include "Pride/PGeometry/PGeometryStoreData.h"
#include "Pride/PGeometry/PGeometryStoreInterface.h"

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HType/HType_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	template< typename IN_TYPE >class PGeometryStoreData : public PGeometryStoreInterface
	{
		HTYPE_RUN_TIME_TYPE_INFO( PGeometryStoreData< IN_TYPE >, PGeometryStoreInterface );
		//EMEMENTO_FACTORY_HEADER( PGeometryStoreInterface );

		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< IN_TYPE >TArrayData;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryStoreData( const PGeometryStoreData& in_src );
		PGeometryStoreData();
		virtual ~PGeometryStoreData();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryStoreData& operator=( const PGeometryStoreData& in_rhs );
		Hubris::HBOOL operator==( const PGeometryStoreData& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryStoreData& in_rhs )const;

		////////////////////////////////////////////////
		// implement PGeometryStoreInterface
	private:
		virtual Hubris::HVOID Clear();
		virtual PGeometryStoreInterface* Clone();
		virtual Hubris::HBOOL Cmp( const PGeometryStoreInterface* const in_pRhs );

		////////////////////////////////////////////////
		// public methods
	public:
		//add data if it is unique, else return index of matching data
		Hubris::HSINT DataUniqueAdd( const IN_TYPE& in_data );
		//add data, not check on matching data
		Hubris::HSINT DataAdd( const IN_TYPE& in_data );

		////////////////////////////////////////////////
		// public accessor
	public:
		Hubris::HSINT SizeGet()const;

		const IN_TYPE& DataGet( const Hubris::HSINT in_index )const;
		IN_TYPE& DataGet( const Hubris::HSINT in_index );

		const TArrayData& ArrayDataGet()const{ return m_arrayData; }
		TArrayData& ArrayDataGet(){ return m_arrayData; }

		////////////////////////////////////////////////
		// private members
	private:
		TArrayData m_arrayData;

	};
	/**/
	
};

#endif // _P_GEOMETRY_STORE_DATA_H_