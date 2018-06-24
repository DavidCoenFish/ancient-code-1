//file: Envy/EResourceIdManager/EResourceIdManager.h
#ifndef _E_RESOURCE_ID_MANAGER_H_
#define _E_RESOURCE_ID_MANAGER_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class EResourceIdManagerImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class EResourceIdManager
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		EResourceIdManager( const EResourceIdManager& in_src );
		EResourceIdManager( const Hubris::HSINT in_minimumResourceValue = 0 );
		~EResourceIdManager();

		///////////////////////////////////////////////////////
		// operators
	public:
		const EResourceIdManager& operator=( const EResourceIdManager& in_rhs );
		const Hubris::HBOOL operator==( const EResourceIdManager& in_rhs )const;
		const Hubris::HBOOL operator!=( const EResourceIdManager& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT ResourceIdAcquire();
		//return true if the given resource is valid
		const Hubris::HBOOL ResourceIdValid( const Hubris::HSINT in_resourceId )const;
		Hubris::HVOID ResourceIdRelease( const Hubris::HSINT in_resourceId );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		Hubris::HVOID Clear();

		//default zero
		const Hubris::HSINT MinimumResourceValueGet()const;
		Hubris::HVOID MinimumResourceValueSet( const Hubris::HSINT in_minimumResourceValue );

		//if you want to limit the number of resources, set minimum[ default 0 ], and maximum [default Max(SINT)]
		const Hubris::HSINT MaximumResourceValueGet()const;
		Hubris::HVOID MaximumResourceValueSet( const Hubris::HSINT in_maximumResourceValue );

		const Hubris::HSINT ResourceIdCountGet()const;

		/////////////////////////////////////////////////////////////////
		// private accessors
	private:
		const EResourceIdManagerImplementation& ImplementationGet()const;
		EResourceIdManagerImplementation& ImplementationGet();

		/////////////////////////////////////////////////////////////////
		// private members
	private:
		EResourceIdManagerImplementation* m_pImplementation;

	};
	
};

#endif // _E_RESOURCE_ID_MANAGER_H_
