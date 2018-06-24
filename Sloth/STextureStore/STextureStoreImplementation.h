//file: Sloth/STextureStore/STextureStoreImplementation.h
#ifndef _S_TEXTURE_STORE_IMPLEMENTATION_H_
#define _S_TEXTURE_STORE_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs
	class STextureStoreImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class STextureStoreImplementation
	{
		///////////////////////////////////////////////////////
		// typedef

		///////////////////////////////////////////////////////
		// creation
	public:
		STextureStoreImplementation( const STextureStoreImplementation& in_src );
		STextureStoreImplementation();
		~STextureStoreImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const STextureStoreImplementation& operator=( const STextureStoreImplementation& in_rhs );
		Hubris::HBOOL operator==( const STextureStoreImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const STextureStoreImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/	
};

#endif // _S_TEXTURE_STORE_IMPLEMENTATION_H_