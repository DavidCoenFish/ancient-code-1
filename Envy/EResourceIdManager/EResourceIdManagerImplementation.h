//file: Envy/EResourceIdManager/EResourceIdManagerImplementation.h
#ifndef _E_RESOURCE_ID_MANAGER_IMPLEMENTATION_H_
#define _E_RESOURCE_ID_MANAGER_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >

namespace Envy
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class EResourceIdManagerImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerArray< Hubris::HU32 >TArraySint;

		///////////////////////////////////////////////////////
		// creation
	public:
		EResourceIdManagerImplementation( const EResourceIdManagerImplementation& in_src );
		EResourceIdManagerImplementation( const Hubris::HSINT in_minimumResourceValue = 0 );
		~EResourceIdManagerImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const EResourceIdManagerImplementation& operator=( const EResourceIdManagerImplementation& in_rhs );
		const Hubris::HBOOL operator==( const EResourceIdManagerImplementation& in_rhs )const;
		const Hubris::HBOOL operator!=( const EResourceIdManagerImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID Clear();

		const Hubris::HSINT ResourceIdAcquire();
		const Hubris::HBOOL ResourceIdValid( const Hubris::HSINT in_resourceId )const;
		Hubris::HVOID ResourceIdRelease( const Hubris::HSINT in_resourceId );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT MinimumResourceValueGet()const{ return m_minimumResourceValue; }
		Hubris::HVOID MinimumResourceValueSet( const Hubris::HSINT in_minimumResourceValue ){ m_minimumResourceValue = in_minimumResourceValue; return; }

		const Hubris::HSINT MaximumResourceValueGet()const{ return m_maximumResourceValue; }
		Hubris::HVOID MaximumResourceValueSet( const Hubris::HSINT in_maximumResourceValue ){ m_maximumResourceValue = in_maximumResourceValue; return; }

		const Hubris::HSINT ResourceIdCountGet()const{ return m_count; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_minimumResourceValue;
		Hubris::HSINT m_maximumResourceValue;
		Hubris::HSINT m_minimumFreeArrayIndex;
		Hubris::HSINT m_count;
		TArraySint m_arrayResourceUseFlag;


	};
	
};

#endif // _E_RESOURCE_ID_MANAGER_IMPLEMENTATION_H_
