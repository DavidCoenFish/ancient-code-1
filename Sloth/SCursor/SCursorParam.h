//file: Sloth/SCursor/SCursorParam.h
#ifndef _S_CURSOR_PARAM_H_
#define _S_CURSOR_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include< Hubris/HMatrix/HMatrix_Export.h >
#include< Pride/PImage/PImage_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SCursor;
	class SMenu;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SCursorParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		SCursorParam(
			const Pride::PImageRgba& in_image,
			const Hubris::HVectorS2& in_hotspot
			);
		~SCursorParam();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SCursorParam( const SCursorParam& in_src );
		const SCursorParam& operator=( const SCursorParam& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Pride::PImageRgba& ImageGet()const{ return m_image; }
		const Hubris::HVectorS2& HotspotGet()const{ return m_hotspot; }

		///////////////////////////////////////////////////////
		// private members
	private:
		const Pride::PImageRgba m_image;
		const Hubris::HVectorS2 m_hotspot;

	};

	/**/
	
};

#endif // _S_CURSOR_PARAM_H_