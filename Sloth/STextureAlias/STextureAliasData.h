//file: Sloth/STextureAlias/STextureAliasData.h
#ifndef _S_TEXTURE_ALIAS_DATA_H_
#define _S_TEXTURE_ALIAS_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HSmartPointer/HSmartPointer_Export.h >

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
	class STextureAliasData : public Hubris::HSmartPointerObjectBase< STextureAliasData >
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		//typedef Hubris::HContainerArray< 

		///////////////////////////////////////////////////////
		// creation
	public:
		STextureAliasData();
		~STextureAliasData();

		///////////////////////////////////////////////////////
		// disabled
	private:
		STextureAliasData( const STextureAliasData& in_src );
		const STextureAliasData& operator=( const STextureAliasData& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT FlagGet()const{ return m_flag; }
		Hubris::HVOID FlagSet( const Hubris::HSINT in_flag ){ m_flag = in_flag; return; }

		const Pride::PImageRgba& ImageGet()const{ return m_image; }
		Hubris::HVOID ImageSet( const Pride::PImageRgba& in_image ){ m_image = in_image; return; }

		const Hubris::HMatrixR4& TransformGet()const{ return m_transform; }
		Hubris::HVOID TransformSet( const Hubris::HMatrixR4& in_transform ){ m_transform = in_transform; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_flag;
		Pride::PImageRgba m_image;
		Hubris::HMatrixR4 m_transform;

	};

	/**/	
};

#endif // _S_TEXTURE_ALIAS_DATA_H_