//file: Hubris/HBufferParse/HBufferParseBinType.cpp

#include "Hubris/HubrisPreCompileHeader.h"
#include "Hubris/HBufferParse/HBufferParseBinType.h"

#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HString/HString.h"
#include "Hubris/HMatrix/HMatrix.h"

///////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;

///////////////////////////////////////////////////////////
// typedef
/**/
typedef HContainerArray< HBOOL > TArrayBool;
typedef HContainerArray< HU8 > TArrayU8;
typedef HContainerArray< HS8 > TArrayS8;
typedef HContainerArray< HU16 > TArrayU16;
typedef HContainerArray< HS16 > TArrayS16;
typedef HContainerArray< HU32 > TArrayU32;
typedef HContainerArray< HS32 > TArrayS32;
typedef HContainerArray< HR32 > TArrayR32;
typedef HContainerArray< HR64 > TArrayR64;
typedef HContainerArray< HCHAR > TArrayChar;
typedef HContainerArray< HString > TArrayString;

//typedef HContainerArray< HVectorS2 > TArrayVectorS2;
//typedef HContainerArray< HVectorS3 > TArrayVectorS3;
//typedef HContainerArray< HVectorS4 > TArrayVectorS4;
//typedef HContainerArray< HMatrixS2 > TArrayMatrixS2;
//typedef HContainerArray< HMatrixS3 > TArrayMatrixS3;
//typedef HContainerArray< HMatrixS4 > TArrayMatrixS4;
//										 
//typedef HContainerArray< HVectorR2 > TArrayVectorR2;
//typedef HContainerArray< HVectorR3 > TArrayVectorR3;
//typedef HContainerArray< HVectorR4 > TArrayVectorR4;
//typedef HContainerArray< HMatrixR2 > TArrayMatrixR2;
//typedef HContainerArray< HMatrixR3 > TArrayMatrixR3;
//typedef HContainerArray< HMatrixR4 > TArrayMatrixR4;

///////////////////////////////////////////////////////////
// public static methods
/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HBOOL >()
{
	HCOMMON_ASSERT_ALWAYS( "invalid code path" );
	return TControlValues::TCount;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HString >()
{
	HCOMMON_ASSERT_ALWAYS( "invalid code path" );
	return TControlValues::TCount;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HU8 >()
{
	return TControlValues::TValueU8;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HS8 >()
{
	return TControlValues::TValueS8;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HU16 >()
{
	return TControlValues::TValueU16;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HS16 >()
{
	return TControlValues::TValueS16;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HU32 >()
{
	return TControlValues::TValueU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HS32 >()
{
	return TControlValues::TValueS32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HR32 >()
{
	return TControlValues::TValueR32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HR64 >()
{
	return TControlValues::TValueR64;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HCHAR >()
{
	return TControlValues::TValueHCHAR;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorS2 >()
{
	return TControlValues::TValueVectorS2;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorS3 >()
{
	return TControlValues::TValueVectorS3;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorS4 >()
{
	return TControlValues::TValueVectorS4;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixS2 >()
{
	return TControlValues::TValueMatrixS2;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixS3 >()
{
	return TControlValues::TValueMatrixS3;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixS4 >()
{
	return TControlValues::TValueMatrixS4;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorR2 >()
{
	return TControlValues::TValueVectorR2;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorR3 >()
{
	return TControlValues::TValueVectorR3;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HVectorR4 >()
{
	return TControlValues::TValueVectorR4;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixR2 >()
{
	return TControlValues::TValueMatrixR2;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixR3 >()
{
	return TControlValues::TValueMatrixR3;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGet< HMatrixR4 >()
{
	return TControlValues::TValueMatrixR4;
}


/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayBool >()
{
	return TControlValues::TValueArrayHBOOLSizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayBool >()
{
	return TControlValues::TValueArrayHBOOLSizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayBool >()
{
	return TControlValues::TValueArrayHBOOLSizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayU8 >()
{
	return TControlValues::TValueArrayU8SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayU8 >()
{
	return TControlValues::TValueArrayU8SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayU8 >()
{
	return TControlValues::TValueArrayU8SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayS8 >()
{
	return TControlValues::TValueArrayS8SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayS8 >()
{
	return TControlValues::TValueArrayS8SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayS8 >()
{
	return TControlValues::TValueArrayS8SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayU16 >()
{
	return TControlValues::TValueArrayU16SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayU16 >()
{
	return TControlValues::TValueArrayU16SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayU16 >()
{
	return TControlValues::TValueArrayU16SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayS16 >()
{
	return TControlValues::TValueArrayS16SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayS16 >()
{
	return TControlValues::TValueArrayS16SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayS16 >()
{
	return TControlValues::TValueArrayS16SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayU32 >()
{
	return TControlValues::TValueArrayU32SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayU32 >()
{
	return TControlValues::TValueArrayU32SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayU32 >()
{
	return TControlValues::TValueArrayU32SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayS32 >()
{
	return TControlValues::TValueArrayS32SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayS32 >()
{
	return TControlValues::TValueArrayS32SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayS32 >()
{
	return TControlValues::TValueArrayS32SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayR32 >()
{
	return TControlValues::TValueArrayR32SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayR32 >()
{
	return TControlValues::TValueArrayR32SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayR32 >()
{
	return TControlValues::TValueArrayR32SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayR64 >()
{
	return TControlValues::TValueArrayR64SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayR64 >()
{
	return TControlValues::TValueArrayR64SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayR64 >()
{
	return TControlValues::TValueArrayR64SizeU32;
}

/**/
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayChar >()
{
	return TControlValues::TValueArrayHCHARSizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayChar >()
{
	return TControlValues::TValueArrayHCHARSizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayChar >()
{
	return TControlValues::TValueArrayHCHARSizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayString >()
{
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayString >()
{
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayString >()
{
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorS2 >()
{
	return TControlValues::TValueArrayTValueVectorS2SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorS2 >()
{
	return TControlValues::TValueArrayTValueVectorS2SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorS2 >()
{
	return TControlValues::TValueArrayTValueVectorS2SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorS3 >()
{
	return TControlValues::TValueArrayTValueVectorS3SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorS3 >()
{
	return TControlValues::TValueArrayTValueVectorS3SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorS3 >()
{
	return TControlValues::TValueArrayTValueVectorS3SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorS4 >()
{
	return TControlValues::TValueArrayTValueVectorS4SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorS4 >()
{
	return TControlValues::TValueArrayTValueVectorS4SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorS4 >()
{
	return TControlValues::TValueArrayTValueVectorS4SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixS2 >()
{
	return TControlValues::TValueArrayTValueMatrixS2SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixS2 >()
{
	return TControlValues::TValueArrayTValueMatrixS2SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixS2 >()
{
	return TControlValues::TValueArrayTValueMatrixS2SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixS3 >()
{
	return TControlValues::TValueArrayTValueMatrixS3SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixS3 >()
{
	return TControlValues::TValueArrayTValueMatrixS3SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixS3 >()
{
	return TControlValues::TValueArrayTValueMatrixS3SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixS4 >()
{
	return TControlValues::TValueArrayTValueMatrixS4SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixS4 >()
{
	return TControlValues::TValueArrayTValueMatrixS4SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixS4 >()
{
	return TControlValues::TValueArrayTValueMatrixS4SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorR2 >()
{
	return TControlValues::TValueArrayTValueVectorR2SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorR2 >()
{
	return TControlValues::TValueArrayTValueVectorR2SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorR2 >()
{
	return TControlValues::TValueArrayTValueVectorR2SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorR3 >()
{
	return TControlValues::TValueArrayTValueVectorR3SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorR3 >()
{
	return TControlValues::TValueArrayTValueVectorR3SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorR3 >()
{
	return TControlValues::TValueArrayTValueVectorR3SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayVectorR4 >()
{
	return TControlValues::TValueArrayTValueVectorR4SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayVectorR4 >()
{
	return TControlValues::TValueArrayTValueVectorR4SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayVectorR4 >()
{
	return TControlValues::TValueArrayTValueVectorR4SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixR2 >()
{
	return TControlValues::TValueArrayTValueMatrixR2SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixR2 >()
{
	return TControlValues::TValueArrayTValueMatrixR2SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixR2 >()
{
	return TControlValues::TValueArrayTValueMatrixR2SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixR3 >()
{
	return TControlValues::TValueArrayTValueMatrixR3SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixR3 >()
{
	return TControlValues::TValueArrayTValueMatrixR3SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixR3 >()
{
	return TControlValues::TValueArrayTValueMatrixR3SizeU32;
}

/**
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetSmall< TArrayMatrixR4 >()
{
	return TControlValues::TValueArrayTValueMatrixR4SizeU8;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetMedium< TArrayMatrixR4 >()
{
	return TControlValues::TValueArrayTValueMatrixR4SizeU16;
}
template<>
Hubris::HBufferParseBinType::TControlValues::TEnum Hubris::HBufferParseBinType::TypeGetLarge< TArrayMatrixR4 >()
{
	return TControlValues::TValueArrayTValueMatrixR4SizeU32;
}

/**/