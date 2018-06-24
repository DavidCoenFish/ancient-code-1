//file: Pride/PMaterial/PMaterial.h
#ifndef _P_MATERIAL_H_
#define _P_MATERIAL_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	class PMaterialImplementation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class PMaterial
	{
		///////////////////////////////////////////////////////
		// typedef

		///////////////////////////////////////////////////////
		// creation
	public:
		PMaterial( const PMaterial& in_src );
		PMaterial();
		~PMaterial();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PMaterial& operator=( const PMaterial& in_rhs );
		Hubris::HBOOL operator==( const PMaterial& in_rhs )const;
		Hubris::HBOOL operator!=( const PMaterial& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:

		///////////////////////////////////////////////////////
		// private accessors
	private:
		const PMaterialImplementation& ImplementationGet()const;
		PMaterialImplementation& ImplementationGet();

		///////////////////////////////////////////////////////
		// private members
	private:
		PMaterialImplementation* m_pImplementation;

	};

	/**/	
};

#endif // _P_MATERIAL_H_