//file: Pride/PGeometry/PGeometryVertex.h
#ifndef _P_GEOMETRY_VERTEX_H_
#define _P_GEOMETRY_VERTEX_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
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
	class PGeometryVertexImplementation;
	class PGeometryTypeSignature;
	struct PGeometryUtility;

	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;


	///////////////////////////////////////////////////////
	// class
	/*
		a class to assist in constructing PGeometry, collect information for a vertex
		a vertex is a independant representation of the data a geometry may have to represent a vertex
		ie, it contains the value of each data stream item that a 'vertex' inside a geometry references

		consider policy: should variant be exposed? tempted not to (insualtion vrs maintanace)
	*/
	class PGeometryVertex
	{
		friend const PGeometryVertexImplementation& GeometryUtilityVertexImplementationGet( const PGeometryVertex& in_src );

		////////////////////////////////////////////////
		// typedef
	public:
		typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
	private:
		typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 4 >TStaticArray4PairRealSint;
		typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 16 >TStaticArray16PairRealSint;
		typedef Hubris::HContainerStaticArray< Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >, 64 >TStaticArray64PairRealSint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryVertex( const PGeometryTypeSignature& in_typeSigniture, const Hubris::HSINT in_topologyVertexIndex );
		PGeometryVertex( const PGeometryVertex& in_src );
		~PGeometryVertex();

		////////////////////////////////////////////////
		// operator
	public:
		const PGeometryVertex& operator=( const PGeometryVertex& in_rhs );
		Hubris::HBOOL operator==( const PGeometryVertex& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryVertex& in_rhs )const;

		////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		////////////////////////////////////////////////
		// public accessors
	public:
		const PGeometryTypeSignature TypeSignatureGet()const;
		const Hubris::HSINT TopologyVertexIndexGet()const;

		/*
			policy in_index is dataStoreIndex?
				return copy rather than by reference? (we COULD return by reference....
				vertex manipulation is ment as helper/ construction class, for performance get the raw data out of the geometry data store....
		*/
		Hubris::HSINT SintGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID SintSet( const Hubris::HSINT in_index, const Hubris::HSINT in_value );

		Hubris::HREAL RealGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID RealSet( const Hubris::HSINT in_index, const Hubris::HREAL in_value );

		TPairRealSint RealSintGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID RealSintSet( const Hubris::HSINT in_index, const TPairRealSint& in_value );

		Hubris::HVectorR2 VectorR2Get( const Hubris::HSINT in_index )const;
		Hubris::HVOID VectorR2Set( const Hubris::HSINT in_index, const Hubris::HVectorR2& in_value );

		Hubris::HVectorR3 VectorR3Get( const Hubris::HSINT in_index )const;
		Hubris::HVOID VectorR3Set( const Hubris::HSINT in_index, const Hubris::HVectorR3& in_value );

		Hubris::HVectorR4 VectorR4Get( const Hubris::HSINT in_index )const;
		Hubris::HVOID VectorR4Set( const Hubris::HSINT in_index, const Hubris::HVectorR4& in_value );

		Pride::PColourRgba ColourRgbaGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID ColourRgbaSet( const Hubris::HSINT in_index, const Pride::PColourRgba& in_value );

		Pride::PColourRealRgba ColourRgbaRealGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID ColourRgbaRealSet( const Hubris::HSINT in_index, const Pride::PColourRealRgba& in_value );

		TStaticArray4PairRealSint StaticArray4PairRealSintGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID StaticArray4PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray4PairRealSint& in_value );

		TStaticArray16PairRealSint StaticArray16PairRealSintGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID StaticArray16PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray16PairRealSint& in_value );

		TStaticArray64PairRealSint StaticArray64PairRealSintGet( const Hubris::HSINT in_index )const;
		Hubris::HVOID StaticArray64PairRealSintSet( const Hubris::HSINT in_index, const TStaticArray64PairRealSint& in_value );

	private:
		const PGeometryVertexImplementation& ImplementationGet()const;
		PGeometryVertexImplementation& ImplementationGet();

		////////////////////////////////////////////////
		// private members
	private:
		PGeometryVertexImplementation * m_pImplementation;

	};

	/**/
	
};

#endif // _P_GEOMETRY_VERTEX_H_