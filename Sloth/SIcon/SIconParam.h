//file: Sloth/SIcon/SIconParam.h
#ifndef _S_ICON_PARAM_H_
#define _S_ICON_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SIcon;
	class SMenu;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SIconParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		SIconParam(
			const Pride::PImageRgba& in_imageLarge,
			const Pride::PImageRgba& in_imageSmall
			);
		~SIconParam();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SIconParam( const SIconParam& in_src );
		const SIconParam& operator=( const SIconParam& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PImageRgba& ImageLargeGet()const{ return m_imageLarge; }
		const Pride::PImageRgba& ImageSmallGet()const{ return m_imageSmall; }

		///////////////////////////////////////////////////////
		// private members
	private:
		const Pride::PImageRgba m_imageLarge;
		const Pride::PImageRgba m_imageSmall;

	};

	/**/
	
};

#endif // _S_ICON_PARAM_H_