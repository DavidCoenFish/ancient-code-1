//file: Sloth/SIcon/SIconImplementation.h
#ifndef _S_ICON_IMPLEMENTATION_H_
#define _S_ICON_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SIconComponentImage;
	class SIconImageInterface;
	struct SIconParam;

	///////////////////////////////////////////////////////
	// class
	/*
		application object
			own command line
			manage windows or consoles

	*/
	class SIconImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HVOID* HICON;

		///////////////////////////////////////////////////////
		// creation
	public:
		SIconImplementation( 
			const SIconParam& in_param
			);
		~SIconImplementation();

		///////////////////////////////////////////////////////
		// public methods
	public:
		HICON IconLargeGet();
		HICON IconSmallGet();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SIconImplementation( const SIconImplementation& in_src );
		const SIconImplementation& operator=( const SIconImplementation& in_rhs );

		///////////////////////////////////////////////////////
		// private members
	private:
		HICON m_iconLarge;
		HICON m_iconSmall;

	};

	/**/
	
};

#endif // _S_ICON_IMPLEMENTATION_H_