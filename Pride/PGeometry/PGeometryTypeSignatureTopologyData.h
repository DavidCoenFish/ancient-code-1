//file: Pride/PGeometry/PGeometryTypeSignatureTopologyData.h
#ifndef _P_GEOMETRY_TYPE_SIGNATURE_TOPOLOGY_DATA_H_
#define _P_GEOMETRY_TYPE_SIGNATURE_TOPOLOGY_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HString/HString_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class PGeometryTypeSignatureTopologyData
	{
		////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryTypeSignatureTopologyData( const PGeometryTypeSignatureTopologyData& in_src  );
		PGeometryTypeSignatureTopologyData( 
			const Hubris::HSINT in_type,
			const TArraySint& in_arrayIndex
			);
		PGeometryTypeSignatureTopologyData();
		~PGeometryTypeSignatureTopologyData();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryTypeSignatureTopologyData& operator=( const PGeometryTypeSignatureTopologyData& in_rhs );
		Hubris::HBOOL operator==( const PGeometryTypeSignatureTopologyData& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryTypeSignatureTopologyData& in_rhs )const;

		////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TypeGet()const{ return m_type; }
		Hubris::HVOID TypeSet( const Hubris::HSINT in_type ){ m_type = in_type; return; }

		const TArraySint& ArrayIndexGet()const{ return m_arrayIndex; }
		Hubris::HVOID ArrayIndexSet( const TArraySint& in_arrayIndex ){ m_arrayIndex = in_arrayIndex; return; }

		////////////////////////////////////////////////
		// private memebers
	private:
		Hubris::HSINT m_type;
		TArraySint m_arrayIndex;

	};
	/**/
	
};

#endif // _P_GEOMETRY_TYPE_SIGNATURE_TOPOLOGY_DATA_H_