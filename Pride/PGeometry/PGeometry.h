//file: Pride/PGeometry/PGeometry.h
#ifndef _P_GEOMETRY_H_
#define _P_GEOMETRY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HString;

	template< typename IN_TYPE >class HContainerArray;
	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;

};


namespace Pride
{
	class PGeometry;
};

namespace Envy
{
	///////////////////////////////////////////////////////////
	// forward declarations
	class EMementoCollect;
	class EMementoAssign;

	//collect values into a memento object
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const IN_TYPE& in_data );
	template< typename IN_TYPE >Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, IN_TYPE& out_data );

	//PGeometryTypeSignature
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometry& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometry& out_data );
};

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PGeometryImplementation;
	class PGeometryTypeSignature;
	class PGeometryStoreTriangleStrip;
	class PGeometryStoreTriangle;
	class PGeometryStoreVertexIndex;

	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	template< typename IN_TYPE >class PGeometryStoreData;

	typedef PGeometryStoreData< Hubris::HSINT >PGeometryStoreDataSint;
	typedef PGeometryStoreData< Hubris::HREAL >PGeometryStoreDataReal;
	typedef PGeometryStoreData< Hubris::HVectorR2 >PGeometryStoreDataVectorR2;
	typedef PGeometryStoreData< Hubris::HVectorR3 >PGeometryStoreDataVectorR3;
	typedef PGeometryStoreData< Hubris::HVectorR4 >PGeometryStoreDataVectorR4;
	//DON'T define TPairRealSint in scope Pride, as it is a common type that may be defined in other namespaces
	//typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
	typedef PGeometryStoreData< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT > >PGeometryStoreDataRealSint; //ie, weight and matrix id
	typedef PGeometryStoreData< Pride::PColourRgba >PGeometryStoreDataColourRgba;
	typedef PGeometryStoreData< Pride::PColourRealRgba >PGeometryStoreDataColourRealRgba;
	typedef PGeometryStoreData< Pride::PColourRealRgba >PGeometryStoreDataColourRealRgba;

	//typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 >TStaticArray4PairRealSint;
	typedef PGeometryStoreData< Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 > >PGeometryStoreDataStaticArray4PairRealSint;

	//typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 >TStaticArray16PairRealSint;
	typedef PGeometryStoreData< Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 > >PGeometryStoreDataStaticArray16PairRealSint;

	//typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 >TStaticArray64PairRealSint;
	typedef PGeometryStoreData< Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 > >PGeometryStoreDataStaticArray64PairRealSint;

	///////////////////////////////////////////////////////
	// class
	/*
		owner of the base data to represent a geometry

		allow multiple streams of data, though seperated conceptually into topology streams, and data streams
		a vertex is internally to geometry a set of indexes to the data streams. (externally a vertex has the data for each stream)
		can have multiple vertex index stores
		topologies currently are strip, triangle (which in turn point to the topology vertex)

		simple usage
			make a type signature, 
				topology stream vertex indexs and strip or triangles
				data stream position, normal, uv whatever
			construct the geometry with the type signature

		query:
			skinning, have bone string table? vertex can have [n] bone index and weights (array, or a hard coded max bones)
			....try a hard coded max, data store of several hard coded max sizes 4, 8, 16, 32
			q. is it ok to have string table of bone names inside the geometry? tempted to say no
			a. no, don't know the 'material' that will be applied to the geometry, don't know that much about what the bones geometry may apply to....


	*/
	class PGeometry
	{
		//memento
		friend Hubris::HVOID Envy::EMementoTraitCollect< PGeometry >( Envy::EMementoCollect& in_out_mementoCollect, const PGeometry& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< PGeometry >( const Envy::EMementoAssign& in_out_mementoAssign, PGeometry& out_data );

		///////////////////////////////////////////////////////
		// creation
	public:
		PGeometry( const PGeometryTypeSignature& in_typeSigniture ); 
		PGeometry( const PGeometry& in_src ); 
		PGeometry(); 
		~PGeometry(); 

		///////////////////////////////////////////////////////
		// operators
	public:
		//allow assignment by different type sig
		const PGeometry& operator=( const PGeometry& in_rhs );
		Hubris::HBOOL operator==( const PGeometry& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometry& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//clear the data in each data store
		Hubris::HVOID Clear();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//const PGeometryTypeSignature TypeSignatureGet()const;
		//avoid return by value, modify param
		const PGeometryTypeSignature TypeSignatureGet()const;
		//WARNING, setting the type sig will ERASE all data in geometry
		Hubris::HVOID TypeSignatureSet( const PGeometryTypeSignature& in_typeSignature );

		const PGeometryStoreVertexIndex& StoreTopologyVertexIndexGet( const Hubris::HSINT in_index )const;
		PGeometryStoreVertexIndex& StoreTopologyVertexIndexGet( const Hubris::HSINT in_index );

		const PGeometryStoreTriangleStrip& StoreTopologyTriangleStripGet( const Hubris::HSINT in_index )const;
		PGeometryStoreTriangleStrip& StoreTopologyTriangleStripGet( const Hubris::HSINT in_index );

		const PGeometryStoreTriangle& StoreTopologyTriangleGet( const Hubris::HSINT in_index )const;
		PGeometryStoreTriangle& StoreTopologyTriangleGet( const Hubris::HSINT in_index );


		const PGeometryStoreDataSint& StoreDataSintGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataSint& StoreDataSintGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataReal& StoreDataRealGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataReal& StoreDataRealGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataVectorR2& StoreDataVectorR2Get( const Hubris::HSINT in_index )const;
		PGeometryStoreDataVectorR2& StoreDataVectorR2Get( const Hubris::HSINT in_index );

		const PGeometryStoreDataVectorR3& StoreDataVectorR3Get( const Hubris::HSINT in_index )const;
		PGeometryStoreDataVectorR3& StoreDataVectorR3Get( const Hubris::HSINT in_index );

		const PGeometryStoreDataVectorR4& StoreDataVectorR4Get( const Hubris::HSINT in_index )const;
		PGeometryStoreDataVectorR4& StoreDataVectorR4Get( const Hubris::HSINT in_index );

		const PGeometryStoreDataRealSint& StoreDataRealSintGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataRealSint& StoreDataRealSintGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataColourRgba& StoreDataColourRgbaGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataColourRgba& StoreDataColourRgbaGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataColourRealRgba& StoreDataColourRealRgbaGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataColourRealRgba& StoreDataColourRealRgbaGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataStaticArray4PairRealSint& StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataStaticArray4PairRealSint& StoreDataStaticArray4PairRealSintGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataStaticArray16PairRealSint& StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataStaticArray16PairRealSint& StoreDataStaticArray16PairRealSintGet( const Hubris::HSINT in_index );

		const PGeometryStoreDataStaticArray64PairRealSint& StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index )const;
		PGeometryStoreDataStaticArray64PairRealSint& StoreDataStaticArray64PairRealSintGet( const Hubris::HSINT in_index );

		//skinning
		////add bone name if not found
		//const Hubris::HSINT BoneIndexAdd( const Hubris::HString& in_boneName );
		////return HCOMMON_INVALID_INDEX if bone not found
		//const Hubris::HSINT BoneIndexGet( const Hubris::HString& in_boneName )const;
		//const Hubris::HString BoneNameGet( const Hubris::HSINT in_boneIndex )const;

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const PGeometryImplementation& ImplementationGet()const;
		PGeometryImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private memebers
	private:
		PGeometryImplementation* m_pImplementation;

	};
};

#endif // _P_GEOMETRY_H_