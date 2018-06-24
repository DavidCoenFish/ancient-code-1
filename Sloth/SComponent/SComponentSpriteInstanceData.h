//file: Sloth/SComponent/SComponentSpriteInstanceData.h
#ifndef _S_COMPONENT_SPRITE_INSTANCE_DATA_H_
#define _S_COMPONENT_SPRITE_INSTANCE_DATA_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class SComponentSpriteInstanceData
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SComponentSpriteInstanceData( const SComponentSpriteInstanceData& in_src );
		SComponentSpriteInstanceData(
			const Hubris::HSINT in_spriteIndex,
			//const Hubris::HSINT in_sortHint,
			const Hubris::HREAL in_alphaOverride,
			const Hubris::HMatrixR4& in_matrix,
			const Hubris::HBOOL in_visible
			);
		SComponentSpriteInstanceData();
		~SComponentSpriteInstanceData();

		///////////////////////////////////////////////////////
		// operator
	public:
		const SComponentSpriteInstanceData& operator=( const SComponentSpriteInstanceData& in_rhs );
		const Hubris::HBOOL operator==( const SComponentSpriteInstanceData& in_rhs )const;
		const Hubris::HBOOL operator!=( const SComponentSpriteInstanceData& in_rhs )const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HSINT SpriteIndexGet()const{ return m_spriteIndex; }
		Hubris::HVOID SpriteIndexSet( const Hubris::HSINT in_spriteIndex ){ m_spriteIndex = in_spriteIndex; return; }

		//const Hubris::HSINT SortHintGet()const{ return m_sortHint; }
		//Hubris::HVOID SortHintSet( const Hubris::HSINT in_sortHint ){ m_sortHint = in_sortHint; return; }

		const Hubris::HREAL AlphaOverrideGet()const{ return m_alphaOverride; }
		Hubris::HVOID AlphaOverrideSet( const Hubris::HREAL in_alphaOverride ){ m_alphaOverride = in_alphaOverride; return; }

		const Hubris::HMatrixR4& MatrixGet()const{ return m_matrix; }
		Hubris::HMatrixR4& MatrixGet(){ return m_matrix; }

		const Hubris::HBOOL VisibleGet()const{ return m_visible; }
		Hubris::HVOID VisibleSet( const Hubris::HBOOL in_visible ){ m_visible = in_visible; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HSINT m_spriteIndex;
		//Hubris::HSINT m_sortHint;
		Hubris::HREAL m_alphaOverride;
		Hubris::HMatrixR4 m_matrix;
		Hubris::HBOOL m_visible;

	};

	/**/
	
};

#endif // _S_COMPONENT_SPRITE_INSTANCE_DATA_H_