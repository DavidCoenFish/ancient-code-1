//file: Hubris/HBufferParse/\HBufferParseSaveBin.h
#ifndef _H_BUFFER_PARSE_SAVE_BIN_H_
#define _H_BUFFER_PARSE_SAVE_BIN_H_

#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HCommon/HCommonType.h"
//#include "Hubris/HContainer/HContainerArray.h"
#include "Hubris/HSmartPointer/HSmartPointerObjectBase.h"

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HBufferParseVariant;
	class HString;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HBufferParseSaveBin : public HSmartPointerObjectBase< HBufferParseSaveBin >
	{
		///////////////////////////////////////////////////////////
		// typedef
	private:
		//typedef HContainerArray< HBuffer >TBufferArray;

		///////////////////////////////////////////////////////////
		// creation
	public:
		HBufferParseSaveBin( const HBufferParseSaveBin& in_src );
		HBufferParseSaveBin();
		~HBufferParseSaveBin();

		///////////////////////////////////////////////////////////
		// operators
	public:
		const HBufferParseSaveBin& operator=( const HBufferParseSaveBin& in_rhs );
		HBOOL operator==( const HBufferParseSaveBin& in_rhs )const;
		HBOOL operator!=( const HBufferParseSaveBin& in_rhs )const;

		//////////////////////////////////////////
		// public methods
	public:
		HVOID BlockStart( 
			const HString& in_name //name must not have spaces, can be HNULL
			);

		HVOID BlockEnd();

		HVOID ValuePut( 
			const HString& in_name,
			const HBufferParseVariant& in_value 
			);
	
		HVOID CommentPut( 
			const HString& in_comment 
			);

		///////////////////////////////////////////////////////////
		// accessors
	public:
		const HBuffer& BufferGet()const{ return m_buffer; }

		///////////////////////////////////////////////////////////
		// private members
	private:
		HBuffer m_buffer;

	};

};

#endif// _H_BUFFER_PARSE_SAVE_BIN_H_
