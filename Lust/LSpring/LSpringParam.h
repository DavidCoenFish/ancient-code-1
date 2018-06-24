//file: Lust/LSpring/LSpringParam.h
#ifndef _L_SPRING_PARAM_H_
#define _L_SPRING_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

///////////////////////////////////////////////////////
// class
/*
	springConstant force to return spring to origin
	springDamppenConstant amount to lerp back to origin the displacement, 0 for no dampen
	sprinMaximumDistance maximum displacement from origin for spring
*/
namespace Lust
{
	class LSpringParam
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		LSpringParam( const LSpringParam& in_src );
		LSpringParam(
			const Hubris::HREAL in_springConstant,
			const Hubris::HREAL in_springDamppenConstant,
			const Hubris::HREAL in_sprinMaximumDistance
			);
		LSpringParam();
		~LSpringParam();

		///////////////////////////////////////////////////////
		// operators
	public:
		const LSpringParam& operator=( const LSpringParam& in_rhs );
		const Hubris::HBOOL operator==( const LSpringParam& in_rhs )const;
		const Hubris::HBOOL operator!=( const LSpringParam& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HREAL SpringConstantGet()const{ return m_springConstant; }
		Hubris::HVOID SpringConstantSet( const Hubris::HREAL in_springConstant ){ m_springConstant = in_springConstant; return; }

		const Hubris::HREAL SpringDamppenConstantGet()const{ return m_springDamppenConstant; }
		Hubris::HVOID SpringDamppenConstantSet( const Hubris::HREAL in_springDamppenConstant ){ m_springDamppenConstant = in_springDamppenConstant; return; }

		const Hubris::HREAL SpringMaximumDistanceGet()const{ return m_springMaximumDistance; }
		Hubris::HVOID SpringMaximumDistanceSet( const Hubris::HREAL in_springMaximumDistance ){ m_springMaximumDistance = in_springMaximumDistance; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HREAL m_springConstant;
		Hubris::HREAL m_springDamppenConstant;
		Hubris::HREAL m_springMaximumDistance;

	};

	/**/
	
};

#endif // _L_SPRING_PARAM_H_