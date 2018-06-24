//file: Pride/PGeometry/PGeometryTypeSignatureData.h
#ifndef _P_GEOMETRY_TYPE_SIGNATURE_DATA_H_
#define _P_GEOMETRY_TYPE_SIGNATURE_DATA_H_

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
	class PGeometryTypeSignatureData
	{
		////////////////////////////////////////////////
		// creation
	public:
		PGeometryTypeSignatureData( const PGeometryTypeSignatureData& in_src  );
		PGeometryTypeSignatureData( 
			const Hubris::HSINT in_type,
			const Hubris::HString& in_name
			);
		PGeometryTypeSignatureData();
		~PGeometryTypeSignatureData();

		////////////////////////////////////////////////
		// operators
	public:
		const PGeometryTypeSignatureData& operator=( const PGeometryTypeSignatureData& in_rhs );
		Hubris::HBOOL operator==( const PGeometryTypeSignatureData& in_rhs )const;
		Hubris::HBOOL operator!=( const PGeometryTypeSignatureData& in_rhs )const;

		////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TypeGet()const{ return m_type; }
		Hubris::HVOID TypeSet( const Hubris::HSINT in_type ){ m_type = in_type; return; }

		const Hubris::HString& NameGet()const{ return m_name; }
		Hubris::HVOID NameSet( const Hubris::HString in_name ){ m_name = in_name; return; }

		////////////////////////////////////////////////
		// private memebers
	private:
		Hubris::HSINT m_type;
		Hubris::HString m_name;

	};
	/**/
	
};

#endif // _P_GEOMETRY_TYPE_SIGNATURE_DATA_H_