//file: Lust/LTranslation/LTranslationComponentForceSum.h
#ifndef _L_TRANSLATION_COMPONENT_FORCE_SUM_H_
#define _L_TRANSLATION_COMPONENT_FORCE_SUM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Lust
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class LTranslation;

	///////////////////////////////////////////////////////
	// class
	/**/
	class LTranslationComponentForceSum
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		LTranslationComponentForceSum( const LTranslationComponentForceSum& in_src );
		LTranslationComponentForceSum();
		~LTranslationComponentForceSum();

		///////////////////////////////////////////////////////
		// operator
	public:
		const LTranslationComponentForceSum& operator=( const LTranslationComponentForceSum& in_rhs );
		const Hubris::HBOOL operator==( const LTranslationComponentForceSum& in_rhs )const;
		const Hubris::HBOOL operator!=( const LTranslationComponentForceSum& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& ForceSumGet()const{ return m_forceSum; }
		Hubris::HVectorR3& ForceSumGet(){ return m_forceSum; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR3 m_forceSum;

	};

	/**/
	
};

#endif // _L_TRANSLATION_COMPONENT_FORCE_SUM_H_