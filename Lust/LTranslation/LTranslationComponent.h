//file: Lust/LTranslation/LTranslationComponent.h
#ifndef _L_TRANSLATION_COMPONENT_H_
#define _L_TRANSLATION_COMPONENT_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// forward declarations
/**/
namespace Sloth
{
	class SComponentDelta;
};

namespace Lust
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class LTranslationComponentVelocity;

	///////////////////////////////////////////////////////
	// class
	/**/
	class LTranslationComponent
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		LTranslationComponent( const LTranslationComponent& in_src );
		LTranslationComponent(
			const Hubris::HVectorR3& in_translation		
			);
		LTranslationComponent();
		~LTranslationComponent();

		///////////////////////////////////////////////////////
		// operator
	public:
		const LTranslationComponent& operator=( const LTranslationComponent& in_rhs );
		const Hubris::HBOOL operator==( const LTranslationComponent& in_rhs )const;
		const Hubris::HBOOL operator!=( const LTranslationComponent& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ApplyVelocity( 
			const LTranslationComponentVelocity& in_velocity,
			const Sloth::SComponentDelta& in_delta
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& TranslationGet()const{ return m_translation; }
		Hubris::HVectorR3& TranslationGet(){ return m_translation; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR3 m_translation;

	};

	/**/
	
};

#endif // _L_TRANSLATION_COMPONENT_H_