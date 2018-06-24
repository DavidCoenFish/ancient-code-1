//file: Sloth/STextureStore/STextureStore.h
#ifndef _S_TEXTURE_STORE_H_
#define _S_TEXTURE_STORE_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs
	class STextureStoreImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class STextureStore
	{
		///////////////////////////////////////////////////////
		// typedef

		///////////////////////////////////////////////////////
		// creation
	public:
		STextureStore( const STextureStore& in_src );
		STextureStore();
		~STextureStore();

		///////////////////////////////////////////////////////
		// operators
	public:
		const STextureStore& operator=( const STextureStore& in_rhs );
		Hubris::HBOOL operator==( const STextureStore& in_rhs )const;
		Hubris::HBOOL operator!=( const STextureStore& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const STextureStoreImplementation& ImplementationGet()const;
		STextureStoreImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		STextureStoreImplementation* m_pImplementation;

	};

	/**/	
};

#endif // _S_TEXTURE_STORE_H_