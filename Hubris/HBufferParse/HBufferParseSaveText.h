//file: Hubris/HBufferParse/HBufferParseSaveText.h
#ifndef _H_BUFFER_PARSE_SAVE_TEXT_H_
#define _H_BUFFER_PARSE_SAVE_TEXT_H_

#include "Hubris/HCommon/HCommonType.h"

#include "Hubris/HBuffer/HBuffer.h"
#include "Hubris/HSmartPointer/HSmartPointerObjectBase.h"

///////////////////////////////////////////////////////////
// forward declarations
/**/
class TiXmlDocument;
class TiXmlElement;

/**/
namespace Hubris
{
	///////////////////////////////////////////////////////////
	// forward declarations
	/**/
	class HString;
	class HBuffer;
	class HBufferParseVariant;

	///////////////////////////////////////////////////////////
	// class
	/**/
	class HBufferParseSaveText : public HSmartPointerObjectBase< HBufferParseSaveText >
	{
		///////////////////////////////////////////////////////////
		// creation
	public:
		HBufferParseSaveText( const HBufferParseSaveText& in_src );
		HBufferParseSaveText();
		~HBufferParseSaveText();

		///////////////////////////////////////////////////////////
		// operators
	public:
		const HBufferParseSaveText& operator=( const HBufferParseSaveText& in_rhs );
		const HBOOL operator==( const HBufferParseSaveText& in_rhs )const;
		const HBOOL operator!=( const HBufferParseSaveText& in_rhs )const;

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

		HVOID ValueStringPut(
			const HString& in_name, //name must not have spaces
			const HString& in_typeName,
			const HString& in_stringValue
			);

		//template< typename IN_TYPE >
		//HVOID ValuePut(
		//	const HString& in_name, //name must not have spaces, can be HNULL, can not be HBPST_DEFAULT
		//	IN_TYPE& in_value
		//	);

		//////////////////////////////////////////
		// static private methods
	private:
		static const HString NameValidate( 
			const HString& in_name 
			);

		///////////////////////////////////////////////////////////
		// accessors
	public:
		const HBuffer& BufferGet()const;

		//////////////////////////////////////////
		// private methods
	private:
		TiXmlDocument* m_pDocument;
		TiXmlElement* m_pCurrentElement;

		mutable HBuffer m_buffer;

	};

	///**/
	//template< typename IN_TYPE >
	//HVOID HBufferParseSaveText::ValuePut(
	//	const HString& in_name,
	//	IN_TYPE& in_value
	//	)
	//{
	//	const HString data = HTraitStringIn( in_data );
	//	ValueStringPut(
	//		in_name, //name must not have spaces
	//		HTraitName< IN_TYPE >::NameGet(),
	//		stringValue
	//		);

	//	return;
	//}


};

#endif// _H_BUFFER_PARSE_SAVE_TEXT_H_
