//file: Sloth/STextureAlias/STextureAliasImplementation.h
#ifndef _S_TEXTURE_ALIAS_IMPLEMENTATION_H_
#define _S_TEXTURE_ALIAS_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/STextureAlias/STextureAliasData.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// predefs

	///////////////////////////////////////////////////////
	// class
	/*
		have an array of textures we dont resize, and thous we can (in size buckets)
		on request,  work out how much we need to shrink
		recusivly fill in quadrants of the texture
	*/
	class STextureAliasImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HSmartPointer< STextureAliasData >TDataPointer; 
		typedef Hubris::HContainerArray< TDataPointer >TArrayDataPointer; 

		///////////////////////////////////////////////////////
		// creation
	public:
		STextureAliasImplementation();
		~STextureAliasImplementation();

		///////////////////////////////////////////////////////
		// disabled
	private:
		STextureAliasImplementation( const STextureAliasImplementation& in_src );
		const STextureAliasImplementation& operator=( const STextureAliasImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HSINT TextureAdd( 
			const Pride::PImageRgba& in_image,
			const Hubris::HSINT in_flag
			);

		Hubris::HVOID TextureRemove(
			const Hubris::HSINT in_textureIndex
			);

		Hubris::HVOID GenerateTextureAlias(
			const Hubris::HVectorS2& in_size
			);

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
		const Hubris::HBOOL TextureAliasValidGet()const{ return m_textureAliasValid; }

		const Pride::PImageRgba& ImageGet()const{ return m_image; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Pride::PImageRgba m_image;
		TArrayDataPointer m_arrayImages;
		Hubris::HSINT m_lowestReleasedIndex;
		Hubris::HBOOL m_textureAliasValid;

	};

	/**/	
};

#endif // _S_TEXTURE_ALIAS_IMPLEMENTATION_H_