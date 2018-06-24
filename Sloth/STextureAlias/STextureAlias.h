//file: Sloth/STextureAlias/STextureAlias.h
#ifndef _S_TEXTURE_ALIAS_H_
#define _S_TEXTURE_ALIAS_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs
	class STextureAliasImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class STextureAlias
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		STextureAlias();
		~STextureAlias();

		///////////////////////////////////////////////////////
		// disabled
	private:
		STextureAlias( const STextureAlias& in_src );
		const STextureAlias& operator=( const STextureAlias& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT TextureAdd( 
			const Pride::PImageRgba& in_image,
			const Hubris::HSINT in_flag = 0
			);

		Hubris::HVOID TextureRemove(
			const Hubris::HSINT in_textureIndex
			);

		Hubris::HVOID GenerateTextureAlias(
			const Hubris::HVectorS2& in_size
			);

		const Pride::PImageRgba& ImageGet()const;

		Hubris::HVOID TextureMatrixGet(
			Hubris::HMatrixR4& out_matrix,
			const Hubris::HSINT in_textureIndex
			)const;

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT FlagNoResize(); 

		///////////////////////////////////////////////////////
		// public accessors
	public:
		//return false if texture added after generate or texture alias not generated
		const Hubris::HBOOL TextureAliasValidGet()const;

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const STextureAliasImplementation& ImplementationGet()const;
		STextureAliasImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		STextureAliasImplementation* m_pImplementation;

	};

	/**/	
};

#endif // _S_TEXTURE_ALIAS_H_