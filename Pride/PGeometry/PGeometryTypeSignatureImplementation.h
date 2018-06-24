//file: Pride/PGeometry/PGeometryTypeSignatureImplementation.h
#ifndef _P_GEOMETRY_TYPE_SIGNATURE_IMPLEMENTATION_H_
#define _P_GEOMETRY_TYPE_SIGNATURE_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

#include "Pride/PGeometry/PGeometryTypeSignatureData.h"
#include "Pride/PGeometry/PGeometryTypeSignatureTopologyData.h"

namespace Pride
{
	class PGeometryTypeSignature;
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
	template Hubris::HVOID EMementoTraitCollect( EMementoCollect& in_out_mementoCollect, const Pride::PGeometryTypeSignature& in_data );
	template Hubris::HVOID EMementoTraitAssign( const EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignature& out_data );
};

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class PGeometryTypeSignatureImplementation
	{
		friend Hubris::HVOID Envy::EMementoTraitCollect< PGeometryTypeSignature >( Envy::EMementoCollect& in_out_mementoCollect, const PGeometryTypeSignature& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< PGeometryTypeSignature >( const Envy::EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignature& out_data );

		////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PGeometryTypeSignatureData >TArrayData;
		typedef Hubris::HContainerArray< PGeometryTypeSignatureTopologyData >TArrayTopologyData;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryTypeSignatureImplementation( const PGeometryTypeSignatureImplementation& in_src  );
		PGeometryTypeSignatureImplementation();
		~PGeometryTypeSignatureImplementation();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryTypeSignatureImplementation& operator=( const PGeometryTypeSignatureImplementation& in_rhs );
		Hubris::HBOOL operator==( const PGeometryTypeSignatureImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryTypeSignatureImplementation& in_rhs )const;

		//const PGeometryTypeSignatureImplementation& operator|=( const PGeometryTypeSignatureImplementation& in_rhs );
		//const PGeometryTypeSignatureImplementation& operator&=( const PGeometryTypeSignatureImplementation& in_rhs );

		////////////////////////////////////////////////
		// public methods
	public:
		/*
			type referes to a class to represent the data, which is why triangle & Strip are seperate, being different classes
			name is a usage hint

			streams have been seperated into topology and data, 
			topology vertex repersents the index of data in data streams for a vertex
			topology triangle are sets of 3 vertex index, topology has a target topology vertex 
			topology strip are sets of 3 vertex index, topology has a target topology vertex 
		*/

		// topology stream description
		const Hubris::HSINT TopologyStreamAdd( const Hubris::HSINT in_type, const TArraySint& in_target );
		const Hubris::HSINT TopologyStreamCountGet()const;
		const Hubris::HSINT TopologyStreamTypeGet( const Hubris::HSINT in_index )const;
		const TArraySint& TopologyStreamArrayIndexGet( const Hubris::HSINT in_index )const; 

		// data stream description
		const Hubris::HSINT DataStreamAdd( const Hubris::HSINT in_type, const Hubris::HString& in_name );
		const Hubris::HSINT DataStreamCountGet()const;
		const Hubris::HSINT DataStreamTypeGet( const Hubris::HSINT in_index )const;
		const Hubris::HString& DataStreamNameGet( const Hubris::HSINT in_index )const;

		////////////////////////////////////////////////
		// public static accessors
	public:
		//type accessors
		//topology streams
		static const Hubris::HSINT TypeGetTopologyVertexIndex();
		static const Hubris::HSINT TypeGetTopologyTriangle();
		static const Hubris::HSINT TypeGetTopologyTriangleStrip();

		//data streams
		static const Hubris::HSINT TypeGetDataSint(); 
		static const Hubris::HSINT TypeGetDataReal();
		static const Hubris::HSINT TypeGetDataRealSint(); //weight
		static const Hubris::HSINT TypeGetDataVectorR2();
		static const Hubris::HSINT TypeGetDataVectorR3();
		static const Hubris::HSINT TypeGetDataVectorR4();
		static const Hubris::HSINT TypeGetDataColour();
		static const Hubris::HSINT TypeGetDataColourReal();
		static const Hubris::HSINT TypeGetDataStaticArray4PairRealSint();
		static const Hubris::HSINT TypeGetDataStaticArray16PairRealSint();
		static const Hubris::HSINT TypeGetDataStaticArray64PairRealSint();

		//name accessors
		static const Hubris::HCHAR* const NameGetTopology();
		static const Hubris::HCHAR* const NameGetPosition();
		static const Hubris::HCHAR* const NameGetNormal();
		static const Hubris::HCHAR* const NameGetTangent();
		static const Hubris::HCHAR* const NameGetBinormal();
		static const Hubris::HCHAR* const NameGetColour();
		static const Hubris::HCHAR* const NameGetUv();
		static const Hubris::HCHAR* const NameGetContinuity();//smoothing~ spline
		static const Hubris::HCHAR* const NameGetSkinWeight();// 
		static const Hubris::HCHAR* const NameGetSpring();

		////////////////////////////////////////////////
		// private members
	private:
		TArrayTopologyData m_arrayTopology;
		TArrayData m_arrayData;

	};
	/**/
	
};

#endif // _P_GEOMETRY_TYPE_SIGNATURE_IMPLEMENTATION_H_