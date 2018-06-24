//file: Pride/PTestbed/PTestbedMesh.cpp

#include "Pride/PTestbed/PTestbedMesh.h"

//////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// typedefs
/**/
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;
typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;

//////////////////////////////////////////////////
// local free functions
/**/
static const HBOOL LocalTestbedMesh()
{
	HBOOL success = HTRUE;

	TArrayVector arrayVector0;
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F,  1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F,  1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F, -1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F,  1.0F, -1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F, -1.0F ) );
	arrayVector0.Insert( HMatrixConstructor::HVectorR3Construct(  1.0F, -1.0F, -1.0F ) );

	TArraySint arrayTriangleIndex0;
	arrayTriangleIndex0.Insert( 0 );
	arrayTriangleIndex0.Insert( 1 );
	arrayTriangleIndex0.Insert( 2 );

	arrayTriangleIndex0.Insert( 0 );
	arrayTriangleIndex0.Insert( 2 );
	arrayTriangleIndex0.Insert( 3 );

	arrayTriangleIndex0.Insert( 0 );
	arrayTriangleIndex0.Insert( 3 );
	arrayTriangleIndex0.Insert( 7 );

	arrayTriangleIndex0.Insert( 0 );
	arrayTriangleIndex0.Insert( 7 );
	arrayTriangleIndex0.Insert( 4 );

	//PMesh( const PMesh& in_src );
	//PMesh( 
	//	const TArrayVector& in_arrayVertex,  
	//	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	//	);
	//~PMesh();
	//const PMesh& operator=( const PMesh& in_rhs );
	//const Hubris::HBOOL operator==( const PMesh& in_rhs )const;
	//const Hubris::HBOOL operator!=( const PMesh& in_rhs )const;
	{
		const PMesh mesh0( arrayVector0, arrayTriangleIndex0 );
		const PMesh mesh1( mesh0 );
		const PMesh mesh2 = mesh0;
		const PMesh mesh3;

		success &= ( mesh0 == mesh1 );
		success &= ( mesh1 == mesh0 );

		success &= ( mesh0 == mesh2 );
		success &= ( mesh2 == mesh0 );

		success &= ( mesh0 != mesh3 );
		success &= ( mesh3 != mesh0 );

		success &= !( mesh0 != mesh2 );
		success &= !( mesh2 != mesh0 );

		success &= !( mesh0 == mesh3 );
		success &= !( mesh3 == mesh0 );
	}


	//HVOID DataSet( 
	//	const TArrayVector& in_arrayVertex,  
	//	const TArraySint& in_arrayTriangleVertexIndex //assert SizeGet() %3 == 0
	//	);

	//const TArrayVector& ArrayVertexGet()const;
	//const Hubris::HSINT TriangleCountGet()const;
	//HVOID TriangleIndexGet(
	//	const Hubris::HSINT in_triangleIndex,
	//	Hubris::HSINT& out_vertexIndexOne,
	//	Hubris::HSINT& out_vertexIndexTwo,
	//	Hubris::HSINT& out_vertexIndexThree
	//	)const;
	//HVOID TriangleVertexGet(
	//	const Hubris::HSINT in_triangleIndex,
	//	Hubris::HVectorR3& out_vertexOne,
	//	Hubris::HVectorR3& out_vertexTwo,
	//	Hubris::HVectorR3& out_vertexThree
	//	)const;
	//const Hubris::HSINT TriangleEdgeTouchesGet(
	//	const Hubris::HSINT in_triangleIndex,
	//	const Hubris::HSINT in_edgeIndex
	//	);
	//HVOID TriangleNormaleGet(
	//	const Hubris::HSINT in_triangleIndex,
	//	Hubris::HVectorR3& out_normal
	//	);

	PTESTBED_VALIDATE_STATUS( "PMesh", success );

	return success;
}

///////////////////////////////////////////////////
// external methods
/**/
const Hubris::HBOOL TestbedMesh()
{
	PTESTBED_VALIDATE_START( "TestbedMesh" );
	HBOOL success = HTRUE;

	success &= LocalTestbedMesh();

	return success;
}

/**/