//file: Pride/PGeometry/PGeometryVertexImplementation.h
#ifndef _P_GEOMETRY_VERTEX_IMPLEMENTATION_H_
#define _P_GEOMETRY_VERTEX_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Pride/PGeometry/PGeometryVertexVariant.h"
#include "Pride/PGeometry/PGeometryTypeSignatureImplementation.h"

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		a class to assist in constructing PGeometry, collect information for a vertex
	*/
	class PGeometryVertexImplementation
	{
		////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< PGeometryVertexVariant >TArrayData;

		////////////////////////////////////////////////
		// creation
	public:
		PGeometryVertexImplementation( const PGeometryVertexImplementation& in_src );
		PGeometryVertexImplementation( 
			const PGeometryTypeSignatureImplementation& in_typeSignature, 
			const Hubris::HSINT in_topologyVertexIndex 
			);
		~PGeometryVertexImplementation();

		////////////////////////////////////////////////
		// operator
	public:
		const PGeometryVertexImplementation& operator=( const PGeometryVertexImplementation& in_rhs );
		Hubris::HBOOL operator==( const PGeometryVertexImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryVertexImplementation& in_rhs )const;

		////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		////////////////////////////////////////////////
		// public accessors
	public:
		const PGeometryTypeSignatureImplementation& TypeSignatureGet()const{ return m_typeSignature; }
		const Hubris::HSINT TopologyVertexIndexGet()const{ return m_topologyVertexIndex; }

		Hubris::HVOID VariantSet( const Hubris::HSINT in_index, const PGeometryVertexVariant& in_variant );
		const PGeometryVertexVariant& VariantGet( const Hubris::HSINT in_index )const;

		////////////////////////////////////////////////
		// private members
	private:
		PGeometryTypeSignatureImplementation m_typeSignature;
		Hubris::HSINT m_topologyVertexIndex;
		TArrayData m_data;

	};
	/**/
	
};

#endif // _P_GEOMETRY_VERTEX_IMPLEMENTATION_H_