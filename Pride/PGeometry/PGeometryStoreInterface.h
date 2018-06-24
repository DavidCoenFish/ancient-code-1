//file: Pride/PGeometry/PGeometryStoreInterface.h
#ifndef _P_GEOMETRY_STORE_INTERFACE_H_
#define _P_GEOMETRY_STORE_INTERFACE_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Envy/EMemento/EMemento_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// abstract base class
	/**/
	class PGeometryStoreInterface
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( PGeometryStoreInterface );

		//EMEMENTO_FACTORY_HEADER_PURE( PGeometryStoreInterface );

		////////////////////////////////////////////////
		// creation
	public:
		virtual ~PGeometryStoreInterface(){ return; }

		////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID Clear()=0;
		virtual PGeometryStoreInterface* Clone()=0;
		virtual Hubris::HBOOL Cmp( const PGeometryStoreInterface* const in_pRhs )=0;

	};
	/**/
	
};

#endif // _P_GEOMETRY_STORE_INTERFACE_H_