//file: Pride/PGeometry/PGeometryImplementation.h
#ifndef _P_GEOMETRY_IMPLEMENTATION_H_
#define _P_GEOMETRY_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"

#include "Pride/PColour/PColour.h"//stl port workaround error C2139

namespace Hubris
{
	template< typename IN_TYPE >class HContainerArray;

	template< typename IN_FIRST, typename IN_SECOND > class HContainerPair;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;
	typedef HMatrix< HREAL, 4, 4 >HMatrixR4;

};

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class PGeometryStoreInterface;
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
	typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
	typedef PGeometryStoreData< TPairRealSint >PGeometryStoreDataRealSint; //ie, weight and matrix id
	typedef PGeometryStoreData< Pride::PColourRgba >PGeometryStoreDataColourRgba;
	typedef PGeometryStoreData< Pride::PColourRealRgba >PGeometryStoreDataColourRealRgba;

	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 >TStaticArray4PairRealSint;
	typedef PGeometryStoreData< TStaticArray4PairRealSint >PGeometryStoreDataStaticArray4PairRealSint;

	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 >TStaticArray16PairRealSint;
	typedef PGeometryStoreData< TStaticArray16PairRealSint >PGeometryStoreDataStaticArray16PairRealSint;

	typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 >TStaticArray64PairRealSint;
	typedef PGeometryStoreData< TStaticArray64PairRealSint >PGeometryStoreDataStaticArray64PairRealSint;

	///////////////////////////////////////////////////////
	// class
	/*
		owner of the base data to represent a geometry
	*/
	class PGeometryImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PGeometryStoreInterface* >TArrayStore;

		///////////////////////////////////////////////////////
		// creation
	public:
		PGeometryImplementation( const PGeometryTypeSignatureImplementation& in_typeSigniture ); 
		PGeometryImplementation( const PGeometryImplementation& in_src ); 
		PGeometryImplementation(); 
		~PGeometryImplementation(); 

		///////////////////////////////////////////////////////
		// operators
	public:
		//assert if typeSigniture doesn't match
		const PGeometryImplementation& operator=( const PGeometryImplementation& in_rhs );
		Hubris::HBOOL operator==( const PGeometryImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//clear the data in each data store
		Hubris::HVOID Clear();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const PGeometryTypeSignatureImplementation& TypeSignatureGet()const{ return m_typeSignature; }
		Hubris::HVOID TypeSignatureSet( const PGeometryTypeSignatureImplementation& in_typeSignature );

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

		///////////////////////////////////////////////////////
		// private memebers
	private:
		PGeometryTypeSignatureImplementation m_typeSignature;
		//so that vertex stride match data array size, have spit topology and data into sepereate arrays
		TArrayStore m_arrayTopology;
		TArrayStore m_arrayData;
		
	};
};

#endif // _P_GEOMETRY_IMPLEMENTATION_H_