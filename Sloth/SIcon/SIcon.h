//file: Sloth/SIcon/SIcon.h
#ifndef _S_ICON_H_
#define _S_ICON_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SIconImplementation;
	struct SIconParam;

	///////////////////////////////////////////////////////
	// class
	/*
	*/
	class SIcon
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HICON;

		///////////////////////////////////////////////////////
		// creation
	public:
		//any alpha of zero is considered to cursor mask
		SIcon( 
			const SIconParam& in_param
			);
		~SIcon();

		///////////////////////////////////////////////////////
		// public methods
	public:
		HICON IconLargeGet();
		HICON IconSmallGet();

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const SIconImplementation& ImplementationGet()const;
		SIconImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SIcon( const SIcon& in_src );
		const SIcon& operator=( const SIcon& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		SIconImplementation* m_pImplementation;

	};

	/**/
	
};

#endif // _S_ICON_H_