//file: Vanity/VScene/VSceneItemComponentRotation.h
#ifndef _V_SCENE_ITEM_COMPONENT_ROTATION_H_
#define _V_SCENE_ITEM_COMPONENT_ROTATION_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/**/
	class VSceneItemComponentRotation
	{
		EMEMENTO_FACTORY_HEADER( VSceneItemComponentRotation );

		///////////////////////////////////////////////////////
		// creation
	public:
		VSceneItemComponentRotation(
			const VSceneItemComponentRotation& in_src
			); 
		VSceneItemComponentRotation( 
			const Hubris::HQuaternionREAL& in_rotation = Hubris::HQuaternionREAL()
			);
		~VSceneItemComponentRotation(); 

		///////////////////////////////////////////////////////
		// operators
	public:
		const VSceneItemComponentRotation& operator=( const VSceneItemComponentRotation& in_rhs );
		const Hubris::HBOOL operator==( const VSceneItemComponentRotation& in_rhs )const;
		const Hubris::HBOOL operator!=( const VSceneItemComponentRotation& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		const Hubris::HVectorR3 RotateVector( 
			const Hubris::HVectorR3& in_vector 
			)const;

		const Hubris::HVectorR3 RotateVectorInverse( 
			const Hubris::HVectorR3& in_vector 
			)const;

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HQuaternionREAL& RotationGet()const{ return m_rotation; }
		Hubris::HVOID RotationSet( const Hubris::HQuaternionREAL& in_rotation );

		///////////////////////////////////////////////////////
		// private accessors
	public:
		const Hubris::HMatrixR3& RotationMatrixGet()const;
		const Hubris::HMatrixR3& RotationMatrixInvertedGet()const;

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HQuaternionREAL m_rotation;
		mutable Hubris::HMatrixR3 m_rotationMatrix;
		mutable Hubris::HMatrixR3 m_rotationMatrixInverted;
		mutable Hubris::HBOOL m_dirtyMatrix;
		mutable Hubris::HBOOL m_dirtyMatrixInverted;

	};

	/**/
	
};

#endif // _V_SCENE_ITEM_COMPONENT_ROTATION_H_