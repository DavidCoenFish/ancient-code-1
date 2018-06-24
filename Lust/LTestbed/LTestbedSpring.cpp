//file: Lust/LTestbed/LTestbedSpring.cpp

#include "Lust/LTestbed/LTestbedSpring.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Lust;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedSpring()
{
	HBOOL success = HTRUE;

	{
		const LSpringReal spring0(
			LSpringParam( 1.0F, 0.1F, 2.0F ),
			5.0F,
			4.0F
			);
		const LSpringReal spring1( spring0 );
		const LSpringReal spring2 = spring0;
		const LSpringReal spring3;

		success &= ( spring0 == spring1 );
		success &= ( spring1 == spring0 );

		success &= ( spring0 == spring2 );
		success &= ( spring2 == spring0 );

		success &= ( spring0 != spring3 );
		success &= ( spring3 != spring0 );

		success &= !( spring0 != spring2 );
		success &= !( spring2 != spring0 );

		success &= !( spring0 == spring3 );
		success &= !( spring3 == spring0 );
	}

	{
		const LSpringR3 spring0(
			LSpringParam( 1.0F, 0.1F, 10.0F ),
			HMatrixConstructor::HVectorR3Construct( 3.0F, 4.0F, 5.0F ),
			HMatrixConstructor::HVectorR3Construct( 6.0F, 7.0F, 8.0F )
			);

		const LSpringR3 spring1( spring0 );
		const LSpringR3 spring2 = spring0;
		const LSpringR3 spring3;

		success &= ( spring0 == spring1 );
		success &= ( spring1 == spring0 );

		success &= ( spring0 == spring2 );
		success &= ( spring2 == spring0 );

		success &= ( spring0 != spring3 );
		success &= ( spring3 != spring0 );

		success &= !( spring0 != spring2 );
		success &= !( spring2 != spring0 );

		success &= !( spring0 == spring3 );
		success &= !( spring3 == spring0 );
	}


	{
		LSpringR3 spring0(
			LSpringParam( 2.0F, 0.5F, 6.0F ),
			HMatrixConstructor::HVectorR3Construct( 3.0F, 4.0F, 5.0F ),
			HMatrixConstructor::HVectorR3Construct( 6.0F, 7.0F, 8.0F )
			);

		for( HSINT index = 0; index < 50; ++index )
		{
			spring0.Update( 0.05F );

			//printf( 
			//	"%f %f %f  %f %f %f\n", 
			//	spring0.DisplacementGet()[ 0 ], 
			//	spring0.DisplacementGet()[ 1 ], 
			//	spring0.DisplacementGet()[ 2 ], 
			//	spring0.VelocityGet()[ 0 ], 
			//	spring0.VelocityGet()[ 1 ], 
			//	spring0.VelocityGet()[ 2 ] 
			//	);
		}
	}

	LTESTBED_VALIDATE_STATUS( "LSpring", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedSpring()
{
	LTESTBED_VALIDATE_START( "TestbedSpring" );
	HBOOL success = HTRUE;

	success &= LocalTestbedSpring();

	return success;
}

/**/