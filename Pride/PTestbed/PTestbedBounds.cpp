//file: Pride/PTestbed/PTestbedBounds.cpp

#include "Pride/PTestbed/PTestbedBounds.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
static const HBOOL LocalTestbedBounds()
{
	HBOOL success = HTRUE;

	//PBounds( const PBounds& in_src );
	//PBounds();
	//~PBounds();
	//const PBounds& operator=( const PBounds& in_rhs );
	//Hubris::HBOOL operator==( const PBounds& in_rhs )const;
	//Hubris::HBOOL operator!=( const PBounds& in_rhs )const;
	{
		PBoundsR2 bounds0;
		bounds0.InsertPoint( HMatrixConstructor::HVectorR2Construct( 1.5F, 2.5F ), 0.5F );
		PBoundsR2 bounds1( bounds0 );
		PBoundsR2 bounds2 = bounds0;
		PBoundsR2 bounds3;

		success &= ( bounds0 == bounds1 );
		success &= ( bounds1 == bounds0 );

		success &= ( bounds0 == bounds2 );
		success &= ( bounds2 == bounds0 );

		success &= ( bounds0 != bounds3 );
		success &= ( bounds3 != bounds0 );

		success &= !( bounds0 != bounds2 );
		success &= !( bounds2 != bounds0 );

		success &= !( bounds0 == bounds3 );
		success &= !( bounds3 == bounds0 );
	}

	//HVOID InsertPoint( 
	//	const TVector& in_point, 
	//	const Hubris::HREAL in_radius = HVariablesMath< IN_TYPE >::s_zero 
	//	);
	//TVector CenterGet()const;
	//Hubris::HREAL RadiusGet()const;
	//Hubris::HREAL MaxDimGet()const;
	//Hubris::HBOOL ValidGet()const{ return m_valid; }
	{
		PBoundsR2 bounds0;
		success &= ( HFALSE == bounds0.ValidGet() );
		bounds0.InsertPoint( HMatrixConstructor::HVectorR2Construct( 1.5F, 2.5F ), 0.5F );
		PBoundsR2 bounds1( bounds0 );
		bounds1.InsertPoint( HMatrixConstructor::HVectorR2Construct( 1.5F, 4.0F ) );

		success &= ( HTRUE == bounds0.ValidGet() );
		success &= ( 0.70710677F == bounds0.RadiusGet() );
		success &= ( 1.0F == bounds0.MaxDimGet() );
		success &= ( HMatrixConstructor::HVectorR2Construct( 1.5F, 2.5F ) == bounds0.CenterGet() );

		success &= ( HTRUE == bounds1.ValidGet() );
		success &= ( 1.1180340F == bounds1.RadiusGet() );
		success &= ( 2.0F == bounds1.MaxDimGet() );
		success &= ( HMatrixConstructor::HVectorR2Construct( 1.5F, 3.0F ) == bounds1.CenterGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PBounds", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedBounds()
{
	PTESTBED_VALIDATE_START( "TestbedBounds" );
	HBOOL success = HTRUE;

	success &= LocalTestbedBounds();

	return success;
}

/**/