//file: Pride/PGeometry/PGeometryStoreVertexIndex.h
#ifndef _P_GEOMETRY_STORE_VERTEX_INDEX_H_
#define _P_GEOMETRY_STORE_VERTEX_INDEX_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Envy/EMemento/EMemento_Export.h >

#include "Pride/PGeometry/PGeometryStoreInterface.h"

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		the type signature has the array of dataStore indexs the vertex refers to
		the PGeometryStoreVertexIndex is stride indexs into the dataStoreData for each vertex
	*/
	class PGeometryStoreVertexIndex : public PGeometryStoreInterface
	{
		HTYPE_RUN_TIME_TYPE_INFO( PGeometryStoreVertexIndex, PGeometryStoreInterface );
		//EMEMENTO_FACTORY_HEADER( PGeometryStoreInterface );

		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryStoreVertexIndex( const PGeometryStoreVertexIndex& in_src );
		PGeometryStoreVertexIndex( const Hubris::HSINT in_stride );
		PGeometryStoreVertexIndex();
		virtual ~PGeometryStoreVertexIndex();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryStoreVertexIndex& operator=( const PGeometryStoreVertexIndex& in_rhs );
		Hubris::HBOOL operator==( const PGeometryStoreVertexIndex& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryStoreVertexIndex& in_rhs )const;

		////////////////////////////////////////////////
		// implement PGeometryStoreInterface
	private:
		virtual Hubris::HVOID Clear();
		virtual PGeometryStoreInterface* Clone();
		virtual Hubris::HBOOL Cmp( const PGeometryStoreInterface* const in_pRhs );

		////////////////////////////////////////////////
		// public methods
	public:
		// arrayDataIndexes[ m_stride ]
		Hubris::HSINT DataArrayIndexUniqueAdd( const Hubris::HSINT* const in_pArrayDataIndexes );
		Hubris::HSINT DataArrayIndexAdd( const Hubris::HSINT* const in_pArrayDataIndexes );

		////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT StrideGet()const{ return m_stride; }
		Hubris::HVOID StrideSet( const Hubris::HSINT in_stride ){ m_stride = in_stride; return; }
		
		//array size / stride, eqivalent of the vertex count
		const Hubris::HSINT DataArrayCountGet()const;
		// array[ index * stride ]
		const Hubris::HSINT* const DataArrayIndexGet( const Hubris::HSINT in_index )const;

		const TArraySint& ArrayDataIndexGet()const{ return m_arrayDataIndex; }
		TArraySint& ArrayDataIndexGet(){ return m_arrayDataIndex; }
		//Hubris::HVOID ArrayDataIndexSet( const TArraySint& in_arrayDataIndex ){ m_arrayDataIndex = in_arrayDataIndex; return; }

		////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_stride;
		TArraySint m_arrayDataIndex;

	};
	/**/
	
};

#endif // _P_GEOMETRY_STORE_VERTEX_INDEX_H_