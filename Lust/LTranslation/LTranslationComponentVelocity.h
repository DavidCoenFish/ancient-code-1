//file: Lust/LTranslation/LTranslationComponentVelocity.h
#ifndef _L_TRANSLATION_COMPONENT_VELOCITY_H_
#define _L_TRANSLATION_COMPONENT_VELOCITY_H_

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
	class LTranslationComponentForceSum;

	///////////////////////////////////////////////////////
	// class
	/**/
	class LTranslationComponentVelocity
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		LTranslationComponentVelocity( const LTranslationComponentVelocity& in_src );
		LTranslationComponentVelocity();
		~LTranslationComponentVelocity();

		///////////////////////////////////////////////////////
		// operator
	public:
		const LTranslationComponentVelocity& operator=( const LTranslationComponentVelocity& in_rhs );
		const Hubris::HBOOL operator==( const LTranslationComponentVelocity& in_rhs )const;
		const Hubris::HBOOL operator!=( const LTranslationComponentVelocity& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		Hubris::HVOID ApplyForceSum( 
			const LTranslationComponentForceSum& in_forceSum,
			const Sloth::SComponentDelta& in_delta,
			const Hubris::HREAL in_massInvert
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HVectorR3& VelocityGet()const{ return m_velocity; }
		Hubris::HVectorR3& VelocityGet(){ return m_velocity; }
	
		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HVectorR3 m_velocity;

	};

	/**/
	
};

#endif // _L_TRANSLATION_COMPONENT_VELOCITY_H_