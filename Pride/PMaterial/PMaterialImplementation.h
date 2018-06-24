//file: Pride/PMaterial/PMaterialImplementation.h
#ifndef _P_MATERIAL_IMPLEMENTATION_H_
#define _P_MATERIAL_IMPLEMENTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// class
	/**/
	class PMaterialImplementation
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		PMaterialImplementation( const PMaterialImplementation& in_src );
		PMaterialImplementation();
		~PMaterialImplementation();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PMaterialImplementation& operator=( const PMaterialImplementation& in_rhs );
		Hubris::HBOOL operator==( const PMaterialImplementation& in_rhs )const;
		Hubris::HBOOL operator!=( const PMaterialImplementation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private members
	private:

	};

	/**/
	
};

#endif // _P_MATERIAL_IMPLEMENTATION_H_