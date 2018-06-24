//file: Hubris/HMatrix/HMatrixConstructor.h
#ifndef _H_MATRIX_CONSTRUCTOR_H_
#define _H_MATRIX_CONSTRUCTOR_H_


#include "Hubris/HMatrix/HMatrix.h"

namespace Hubris
{
	//helper functions to construct matrix
	struct HMatrixConstructor
	{
		////////////////////////////////////////////////
		// public static functions
	public:
		static const HVectorS2 HVectorS2Construct( const HSINT in_x, const HSINT in_y );
		static const HVectorS3 HVectorS3Construct( const HSINT in_x, const HSINT in_y, const HSINT in_z );

		static const HVectorR2 HVectorR2Construct( const HREAL in_x, const HREAL in_y );
		static const HVectorR3 HVectorR3Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z );
		static const HVectorR4 HVectorR4Construct( const HREAL in_x, const HREAL in_y, const HREAL in_z, const HREAL in_w );

		static const HMatrixR4 HMatrixR4ConstructAxisAngle( const HVectorR3& in_axis, const HREAL in_angleRad );
		//construct a rotation matrix to get from base at and up to target at and up
		//presume same angle between at & up, unit vectors
		static const HMatrixR4 HMatrixR4ConstructAtUp( 
			const HVectorR3& in_targetAt, 
			const HVectorR3& in_targetUp,
			const HVectorR3& in_baseAt = HVectorR3AxisY(), 
			const HVectorR3& in_baseUp = HVectorR3AxisZ()
			);
		static const HMatrixR3 HMatrixR4ConstructAtUp3( 
			const HVectorR3& in_targetAt, 
			const HVectorR3& in_targetUp,
			const HVectorR3& in_baseAt = HVectorR3AxisY(), 
			const HVectorR3& in_baseUp = HVectorR3AxisZ()
			);

		static const HMatrixR4 HMatrixR4ConstructLookAt( 
			const HVectorR3& in_pos, 
			const HVectorR3& in_target,
			const HVectorR3& in_up 
			);

		static const HMatrixR3 HMatrixR3ConstructColoumn(
			const HVectorR3& in_coloumn0,
			const HVectorR3& in_coloumn1,
			const HVectorR3& in_coloumn2
			);

		static const HVectorR3& HVectorR3AxisX();
		static const HVectorR3& HVectorR3AxisY();
		static const HVectorR3& HVectorR3AxisZ();

		//static const HMatrixR4 HMatrixR4ConstructOrtho( 
		//	const Hubris::HREAL in_width,
		//	const Hubris::HREAL in_height,
		//	const Hubris::HREAL in_near,
		//	const Hubris::HREAL in_far
		//	);
		//static const HMatrixR4 HMatrixR4ConstructPerspective( 
		//	const Hubris::HREAL in_width,
		//	const Hubris::HREAL in_height,
		//	const Hubris::HREAL in_near,
		//	const Hubris::HREAL in_far
		//	);

		////////////////////////////////////////////////
		// disabled
	private:
		~HMatrixConstructor();

	};

};

#endif // _H_MATRIX_CONSTRUCTOR_H_