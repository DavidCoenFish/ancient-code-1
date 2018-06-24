//file: Pride/PGeometry/PGeometryStoreTriangle.h
#ifndef _P_GEOMETRY_STORE_TRIANGLE_H_
#define _P_GEOMETRY_STORE_TRIANGLE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PGeometry/PGeometryStoreInterface.h"
#include< Hubris/HContainer/HContainer_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class PGeometryStoreTriangle : public PGeometryStoreInterface
	{
		HTYPE_RUN_TIME_TYPE_INFO( PGeometryStoreTriangle, PGeometryStoreInterface );
		//EMEMENTO_FACTORY_HEADER( PGeometryStoreInterface );

		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryStoreTriangle( const PGeometryStoreTriangle& in_src );
		PGeometryStoreTriangle( const Hubris::HSINT in_targetTopologyVertexIndex );
		PGeometryStoreTriangle();
		virtual ~PGeometryStoreTriangle();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryStoreTriangle& operator=( const PGeometryStoreTriangle& in_rhs );
		Hubris::HBOOL operator==( const PGeometryStoreTriangle& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryStoreTriangle& in_rhs )const;

		////////////////////////////////////////////////
		// implement PGeometryStoreInterface
	private:
		virtual Hubris::HVOID Clear();
		virtual PGeometryStoreInterface* Clone();
		virtual Hubris::HBOOL Cmp( const PGeometryStoreInterface* const in_pRhs );

		////////////////////////////////////////////////
		// public methods
	public:
		// triangle vertex indexs
		Hubris::HVOID TriangleAdd( const Hubris::HSINT in_vertexIndexOne, const Hubris::HSINT in_vertexIndexTwo, const Hubris::HSINT in_vertexIndexThree );  

		const TArraySint& ArrayVertexIndexGet()const{ return m_arrayVertexIndex; }
		TArraySint& ArrayVertexIndexGet(){ return m_arrayVertexIndex; }

		const Hubris::HSINT TargetTopologyVertexIndexGet()const{ return m_targetTopologyVertexIndex; }
		Hubris::HVOID TargetTopologyVertexIndexSet( const Hubris::HSINT in_targetTopologyVertexIndex ){ m_targetTopologyVertexIndex = in_targetTopologyVertexIndex; return; }

		////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TriangleCountGet()const;
		Hubris::HVOID TriangleGet( const Hubris::HSINT in_triangleIndex, Hubris::HSINT& out_vertexIndexOne, Hubris::HSINT& out_vertexIndexTwo, Hubris::HSINT& out_vertexIndexThree )const;

		////////////////////////////////////////////////
		// private members
	private:
		//stride 3, indexes of vertexs, triCount = m_arrayVertexIndex.SizeGet / 3
		TArraySint m_arrayVertexIndex;

		//the topology index for the vertex data, should this be here of just in the type sig
		Hubris::HSINT m_targetTopologyVertexIndex;

	};
	/**/
	
};

#endif // _P_GEOMETRY_STORE_TRIANGLE_H_