//file: Pride/PGeometry/PGeometryStoreTriangleStrip.h
#ifndef _P_GEOMETRY_STORE_STRIP_H_
#define _P_GEOMETRY_STORE_STRIP_H_

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
	class PGeometryStoreTriangleStrip : public PGeometryStoreInterface
	{
		HTYPE_RUN_TIME_TYPE_INFO( PGeometryStoreTriangleStrip, PGeometryStoreInterface );
		//EMEMENTO_FACTORY_HEADER( PGeometryStoreInterface );

		/////////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSintSint;
		typedef Hubris::HContainerArray< TPairSintSint >TArrayPairSintSint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryStoreTriangleStrip( const PGeometryStoreTriangleStrip& in_src );
		PGeometryStoreTriangleStrip( const Hubris::HSINT in_targetTopologyVertexIndex );
		PGeometryStoreTriangleStrip();
		virtual ~PGeometryStoreTriangleStrip();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryStoreTriangleStrip& operator=( const PGeometryStoreTriangleStrip& in_rhs );
		Hubris::HBOOL operator==( const PGeometryStoreTriangleStrip& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryStoreTriangleStrip& in_rhs )const;

		////////////////////////////////////////////////
		// implement PGeometryStoreInterface
	private:
		virtual Hubris::HVOID Clear();
		virtual PGeometryStoreInterface* Clone();
		virtual Hubris::HBOOL Cmp( const PGeometryStoreInterface* const in_pRhs );

		////////////////////////////////////////////////
		// public methods
	public:
		// array of length vertex indexs
		Hubris::HVOID StripAdd( const Hubris::HSINT* const in_pArrayVertexIndexes, const Hubris::HSINT in_vertexIndexCount );  
		Hubris::HVOID StripAdd( const TArraySint& in_arrayVertexIndex );  

		////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT StripCountGet()const;
		const Hubris::HSINT StripLengthGet( const Hubris::HSINT in_stripIndex )const;
		const Hubris::HSINT* StripDataGet( const Hubris::HSINT in_stripIndex )const;

		const Hubris::HSINT TriangleCountGet()const{ return m_triangleCount; }
		Hubris::HVOID TriangleCountSet( const Hubris::HSINT in_triangleCount ){ m_triangleCount = in_triangleCount; return; }

		const TArrayPairSintSint& ArrayStripLengthsBaseGet()const{ return m_arrayStripLengthsBase; }
		TArrayPairSintSint& ArrayStripLengthsBaseGet(){ return m_arrayStripLengthsBase; }

		const TArraySint& ArrayVertexIndexGet()const{ return m_arrayVertexIndex; }
		TArraySint& ArrayVertexIndexGet(){ return m_arrayVertexIndex; }

		const Hubris::HSINT TargetTopologyVertexIndexGet()const{ return m_targetTopologyVertexIndex; }
		Hubris::HVOID TargetTopologyVertexIndexSet( const Hubris::HSINT in_targetTopologyVertexIndex ){ m_targetTopologyVertexIndex = in_targetTopologyVertexIndex; return; }

		////////////////////////////////////////////////
		// private members
	private:
		//an array of strip lengths and base index
		TArrayPairSintSint m_arrayStripLengthsBase;
		TArraySint m_arrayVertexIndex;

		Hubris::HSINT m_triangleCount;
		//the channel of the target vertex index 
		Hubris::HSINT m_targetTopologyVertexIndex;

	};
	/**/
	
};

#endif // _P_GEOMETRY_STORE_STRIP_H_