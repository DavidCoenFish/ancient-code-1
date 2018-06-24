//file: Pride/PGeometry/PGeometryTypeSignature.h
#ifndef _P_GEOMETRY_TYPE_SIGNATURE_H_
#define _P_GEOMETRY_TYPE_SIGNATURE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HString/HString_Export.h >

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
	class PGeometry;
	class PGeometryVertex;
	class PGeometryTypeSignatureImplementation;

	///////////////////////////////////////////////////////
	// class
	/*
		property flags for what data a PGeometry may contain
	*/
	class PGeometryTypeSignature
	{
		friend PGeometry; //access to ImplementationGet()
		friend PGeometryVertex; //access to ImplementationGet()

		friend Hubris::HVOID Envy::EMementoTraitCollect< PGeometryTypeSignature >( Envy::EMementoCollect& in_out_mementoCollect, const PGeometryTypeSignature& in_data );
		friend Hubris::HVOID Envy::EMementoTraitAssign< PGeometryTypeSignature >( const Envy::EMementoAssign& in_out_mementoAssign, Pride::PGeometryTypeSignature& out_data );

		////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryTypeSignature( const PGeometryTypeSignature& in_src  );
		PGeometryTypeSignature( const PGeometryTypeSignatureImplementation& in_src );
		PGeometryTypeSignature();
		~PGeometryTypeSignature();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryTypeSignature& operator=( const PGeometryTypeSignature& in_rhs );
		Hubris::HBOOL operator==( const PGeometryTypeSignature& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryTypeSignature& in_rhs )const;

		////////////////////////////////////////////////
		// public methods
	public:
		/*
			type referes to a class to represent the data, which is why triangle & Strip are seperate, being different classes
			name is a usage hint
			channel is so you can have multiple data of matching types
			comment is a human hint
		*/

		// topology stream description
		const Hubris::HSINT TopologyStreamAdd( const Hubris::HSINT in_type, const Hubris::HSINT& in_arrayIndex );
		const Hubris::HSINT TopologyStreamAdd( const Hubris::HSINT in_type, const TArraySint& in_arrayIndex );
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
		static const Hubris::HSINT TypeGetTopologyVertexIndex();
		static const Hubris::HSINT TypeGetTopologyTriangle();
		static const Hubris::HSINT TypeGetTopologyTriangleStrip();

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
		//static const Hubris::HString NameGetTopology();
		static const Hubris::HCHAR* const NameGetPosition();
		static const Hubris::HCHAR* const NameGetNormal();
		static const Hubris::HCHAR* const NameGetTangent();
		static const Hubris::HCHAR* const NameGetBinormal();
		static const Hubris::HCHAR* const NameGetColour();
		static const Hubris::HCHAR* const NameGetUv();
		static const Hubris::HCHAR* const NameGetContinuity();//smoothing~ spline
		static const Hubris::HCHAR* const NameGetSkinWeight();// 
		static const Hubris::HCHAR* const NameGetSpring();// 3 floats, the spring constant, the dampen constant, and the maximum displacement

		////////////////////////////////////////////////
		// private accessors
	private:
		const PGeometryTypeSignatureImplementation& ImplementationGet()const;
		PGeometryTypeSignatureImplementation& ImplementationGet();

		////////////////////////////////////////////////
		// private memebers
	public:
		PGeometryTypeSignatureImplementation* m_pImplementation;

	};
	/**/
	
};

#endif // _P_GEOMETRY_TYPE_SIGNATURE_H_