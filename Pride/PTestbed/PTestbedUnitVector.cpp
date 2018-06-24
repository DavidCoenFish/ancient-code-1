//file: Pride/PTestbed/PTestbedUnitVector.cpp

#include "Pride/PTestbed/PTestbedUnitVector.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedUnitVector()
{
	HBOOL success = HTRUE;

	//PUnitVectorR3( const PUnitVectorR3& in_src );
	//explicit PUnitVectorR3(
	//	const Hubris::HVectorR3& in_vector
	//	);
	//PUnitVectorR3();
	//~PUnitVectorR3();
	//const PUnitVectorR3& operator=( const PUnitVectorR3& in_rhs );
	//Hubris::HBOOL operator==( const PUnitVectorR3& in_rhs )const;
	//Hubris::HBOOL operator!=( const PUnitVectorR3& in_rhs )const;
	{
		PUnitVectorR3 unitVector0;
		unitVector0.VectorSet( HMatrixConstructor::HVectorR3AxisY() );
		const PUnitVectorR3 unitVector1( unitVector0 ); 
		const PUnitVectorR3 unitVector2( HMatrixConstructor::HVectorR3AxisY() ); 
		const PUnitVectorR3 unitVector3 = unitVector0;
		const PUnitVectorR3 unitVector4;

		success &= ( unitVector0 == unitVector1 );
		success &= ( unitVector1 == unitVector0 );

		success &= ( unitVector0 == unitVector2 );
		success &= ( unitVector2 == unitVector0 );

		success &= ( unitVector0 == unitVector3 );
		success &= ( unitVector3 == unitVector0 );

		success &= ( unitVector0 != unitVector4 );
		success &= ( unitVector4 != unitVector0 );

		success &= !( unitVector0 != unitVector3 );
		success &= !( unitVector3 != unitVector0 );

		success &= !( unitVector0 == unitVector4 );
		success &= !( unitVector4 == unitVector0 );
	}

	//const Hubris::HREAL operator[]( Hubris::HSINT in_index )const;
	//operator const Hubris::HVectorR3&()const{ return m_unitVector; }
	{
		const HVectorR3 vector0 = HMatrixConstructor::HVectorR3AxisY();
		const PUnitVectorR3 unitVector0( vector0 ); 

		success &= ( vector0[ 0 ] == unitVector0[ 0 ] );
		success &= ( vector0[ 1 ] == unitVector0[ 1 ] );
		success &= ( vector0[ 2 ] == unitVector0[ 2 ] );
		success &= ( 1.0F == unitVector0[ 1 ] );

		success &= ( vector0 == unitVector0.VectorGet() );
	}

	//HVOID VectorSet( const Hubris::HVectorR3& in_unitVector );
	//const Hubris::HBOOL ValidGet()const{ return m_valid; }
	{
		PUnitVectorR3 unitVector0;

		unitVector0.VectorSet( HMatrixConstructor::HVectorR3Construct( 0.0F, 10.0F, 0.0F ) );
		//unitVector0.VectorSet( HVectorR3() );

		success &= ( HMatrixConstructor::HVectorR3AxisY() == unitVector0.VectorGet() );
	}

	PTESTBED_VALIDATE_STATUS( "PUnitVectorR3", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedUnitVector()
{
	PTESTBED_VALIDATE_START( "TestbedUnitVector" );
	HBOOL success = HTRUE;

	success &= LocalTestbedUnitVector();

	return success;
}

/**/