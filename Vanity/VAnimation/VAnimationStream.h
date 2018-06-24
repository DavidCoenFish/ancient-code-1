//file: Vanity/VAnimation/VAnimationStream.h
#ifndef _V_ANIMATION_STREAM_H_
#define _V_ANIMATION_STREAM_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Vanity/VAnimation/VAnimationData.h"

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VAnimationStream
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		VAnimationStream( const VAnimationStream& in_src );
		VAnimationStream();
		~VAnimationStream();

		///////////////////////////////////////////////////////
		// operator
	public:
		const VAnimationStream& operator=( const VAnimationStream& in_rhs );
		const Hubris::HBOOL operator==( const VAnimationStream& in_rhs )const;
		const Hubris::HBOOL operator!=( const VAnimationStream& in_rhs )const;

		///////////////////////////////////////////////////////
		// private methods
	public:
		Hubris::HVOID ResourceCreate();
		Hubris::HVOID ResourceRelease();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT TypeDataGet()const;
		Hubris::HVOID TypeDataSet( const Hubris::HSINT in_typeData );

		const VAnimationDataSint& AnimationDataSintGet()const;
		VAnimationDataSint& AnimationDataSintGet();

		const VAnimationDataReal& AnimationDataRealGet()const;
		VAnimationDataReal& AnimationDataRealGet();

		const VAnimationDataVectorR2& AnimationDataVectorR2Get()const;
		VAnimationDataVectorR2& AnimationDataVectorR2Get();

		const VAnimationDataVectorR3& AnimationDataVectorR3Get()const;
		VAnimationDataVectorR3& AnimationDataVectorR3Get();

		const VAnimationDataVectorR4& AnimationDataVectorR4Get()const;
		VAnimationDataVectorR4& AnimationDataVectorR4Get();

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT TypeDataGetSint();
		static const Hubris::HSINT TypeDataGetReal();
		static const Hubris::HSINT TypeDataGetVectorR2();
		static const Hubris::HSINT TypeDataGetVectorR3();
		static const Hubris::HSINT TypeDataGetVectorR4();

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_flag;
		Hubris::HVOID* m_pData;

	};

	/**/
	
};

#endif // _V_ANIMATION_STREAM_H_