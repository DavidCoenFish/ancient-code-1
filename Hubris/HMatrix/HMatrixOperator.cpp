//file: Hubris/HMatrix/HMatrixOperator.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HMatrix/HMatrixOperator.h"

#include "Hubris/HMatrix/HMatrix.h"
#include "Hubris/HMatrix/HMatrixImplementation.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

/**/
#define HMATRIX_OPERATOR_TYPE HU8

#include "Hubris/HMatrix/HMatrixOperatorImp.hxx"

#undef HMATRIX_OPERATOR_TYPE

/**/
#define HMATRIX_OPERATOR_TYPE HSINT

#include "Hubris/HMatrix/HMatrixOperatorImp.hxx"

#undef HMATRIX_OPERATOR_TYPE

/**/
#define HMATRIX_OPERATOR_TYPE HREAL

#include "Hubris/HMatrix/HMatrixOperatorImp.hxx"

#undef HMATRIX_OPERATOR_TYPE

/**/

