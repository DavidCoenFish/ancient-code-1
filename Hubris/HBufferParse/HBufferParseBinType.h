//file: Hubris/HBufferParse/HBufferParseBinType.h
#ifndef _H_BUFFER_PARSE_BIN_TYPE_H_
#define _H_BUFFER_PARSE_BIN_TYPE_H_



/**/
namespace Hubris
{
	struct HBufferParseBinType
	{
		///////////////////////////////////////////////////////////
		// public types
	public:
		struct TControlValues
		{
			enum TEnum
			{
				//TBlockStartSizeU8 = 0,
				//TBlockStartSizeU16,
				//TBlockStartSizeU32,
				TBlockStart = 0,
				TBlockEnd,

				TTokenNone,
				TTokenSizeU8,
				TTokenSizeU16,
				TTokenSizeU32,

				TValueU8,
				TValueS8,
				TValueU16,
				TValueS16,
				TValueU32,
				TValueS32,
				TValueR32,
				TValueR64,
				TValueHBOOLTrue,
				TValueHBOOLFalse,
				TValueHCHAR,
				TValueHStringSizeU8,
				TValueHStringSizeU16,
				TValueHStringSizeU32,

				//TValueVectorS2,
				//TValueVectorS3,
				//TValueVectorS4,
				//TValueMatrixS2,
				//TValueMatrixS3,
				//TValueMatrixS4,

				//TValueVectorR2,
				//TValueVectorR3,
				//TValueVectorR4,
				//TValueMatrixR2,
				//TValueMatrixR3,
				//TValueMatrixR4,

				TValueArrayU8SizeU8,
				TValueArrayU8SizeU16,
				TValueArrayU8SizeU32,

				TValueArrayS8SizeU8,
				TValueArrayS8SizeU16,
				TValueArrayS8SizeU32,

				TValueArrayU16SizeU8,
				TValueArrayU16SizeU16,
				TValueArrayU16SizeU32,

				TValueArrayS16SizeU8,
				TValueArrayS16SizeU16,
				TValueArrayS16SizeU32,

				TValueArrayU32SizeU8,
				TValueArrayU32SizeU16,
				TValueArrayU32SizeU32,

				TValueArrayS32SizeU8,
				TValueArrayS32SizeU16,
				TValueArrayS32SizeU32,

				TValueArrayR32SizeU8,
				TValueArrayR32SizeU16,
				TValueArrayR32SizeU32,

				TValueArrayR64SizeU8,
				TValueArrayR64SizeU16,
				TValueArrayR64SizeU32,

				TValueArrayHBOOLSizeU8,
				TValueArrayHBOOLSizeU16,
				TValueArrayHBOOLSizeU32,

				TValueArrayHCHARSizeU8,
				TValueArrayHCHARSizeU16,
				TValueArrayHCHARSizeU32,

				TValueArrayHStringSizeU8SizeU8,			//array size the string size
				TValueArrayHStringSizeU8SizeU16,		//array size the string size
				TValueArrayHStringSizeU8SizeU32,		//array size the string size

				TValueArrayHStringSizeU16SizeU8,		//array size the string size
				TValueArrayHStringSizeU16SizeU16,		//array size the string size
				TValueArrayHStringSizeU16SizeU32,		//array size the string size

				TValueArrayHStringSizeU32SizeU8,		//array size the string size
				TValueArrayHStringSizeU32SizeU16,		//array size the string size
				TValueArrayHStringSizeU32SizeU32,		//array size the string size

				//TValueArrayTValueVectorS2SizeU8,
				//TValueArrayTValueVectorS2SizeU16,
				//TValueArrayTValueVectorS2SizeU32,

				//TValueArrayTValueVectorS3SizeU8,
				//TValueArrayTValueVectorS3SizeU16,
				//TValueArrayTValueVectorS3SizeU32,

				//TValueArrayTValueVectorS4SizeU8,
				//TValueArrayTValueVectorS4SizeU16,
				//TValueArrayTValueVectorS4SizeU32,

				//TValueArrayTValueMatrixS2SizeU8,
				//TValueArrayTValueMatrixS2SizeU16,
				//TValueArrayTValueMatrixS2SizeU32,

				//TValueArrayTValueMatrixS3SizeU8,
				//TValueArrayTValueMatrixS3SizeU16,
				//TValueArrayTValueMatrixS3SizeU32,

				//TValueArrayTValueMatrixS4SizeU8,
				//TValueArrayTValueMatrixS4SizeU16,
				//TValueArrayTValueMatrixS4SizeU32,

				//TValueArrayTValueVectorR2SizeU8,
				//TValueArrayTValueVectorR2SizeU16,
				//TValueArrayTValueVectorR2SizeU32,

				//TValueArrayTValueVectorR3SizeU8,
				//TValueArrayTValueVectorR3SizeU16,
				//TValueArrayTValueVectorR3SizeU32,

				//TValueArrayTValueVectorR4SizeU8,
				//TValueArrayTValueVectorR4SizeU16,
				//TValueArrayTValueVectorR4SizeU32,

				//TValueArrayTValueMatrixR2SizeU8,
				//TValueArrayTValueMatrixR2SizeU16,
				//TValueArrayTValueMatrixR2SizeU32,

				//TValueArrayTValueMatrixR3SizeU8,
				//TValueArrayTValueMatrixR3SizeU16,
				//TValueArrayTValueMatrixR3SizeU32,

				//TValueArrayTValueMatrixR4SizeU8,
				//TValueArrayTValueMatrixR4SizeU16,
				//TValueArrayTValueMatrixR4SizeU32,

				TCount
			};
		};

		///////////////////////////////////////////////////////////
		// static public methods
	public:
		template< typename IN_TYPE >static TControlValues::TEnum TypeGet();
		template< typename IN_TYPE >static TControlValues::TEnum TypeGetSmall();
		template< typename IN_TYPE >static TControlValues::TEnum TypeGetMedium();
		template< typename IN_TYPE >static TControlValues::TEnum TypeGetLarge();

		///////////////////////////////////////////////////////////
		// disabled
	private:
		~HBufferParseBinType();

	};
};

#endif// _H_BUFFER_PARSE_BIN_TYPE_H_
