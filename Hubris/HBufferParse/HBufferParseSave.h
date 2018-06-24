//file: Hubris/HBufferParse/HBufferParseSave.h
#ifndef _H_BUFFER_PARSE_SAVE_H_
#define _H_BUFFER_PARSE_SAVE_H_

#include "Hubris/HCommon/HCommonType.h"

#include "Hubris/HBufferParse/HBufferParseSaveBin.h"
#include "Hubris/HBufferParse/HBufferParseSaveText.h"
#include "Hubris/HSmartPointer/HSmartPointer.h"

/**/
namespace Hubris
{
	//////////////////////////////////////////
	// forward declarations
	class HBuffer;
	class HBufferParseVariant;
	struct HBufferParseManager;

	//////////////////////////////////////////
	// class
	/*
		this is a wrapper for 'buffer parse save interface'
		making a copy doesn't make a duplicate destination buffer, but still puts data into the original buffer, this could be a mistake
		todo: duplicate resource on assignment, add accessor to internal buffer reference, 
		ie, change to owning buffer
	*/
	class HBufferParseSave
	{
		friend HBufferParseManager;

		///////////////////////////////////////////////////////////
		// typedef
	private:
		typedef HSmartPointer< HBufferParseSaveBin >TSaveBinPointer;
		typedef HSmartPointer< HBufferParseSaveText >TSaveTextPointer;

		///////////////////////////////////////////////////////////
		// creation
	private:
		HBufferParseSave( const HBOOL in_createBin, const HBOOL in_createText );
	public:
		HBufferParseSave( const HBufferParseSave& in_src );
		~HBufferParseSave();

		///////////////////////////////////////////////////////////
		// operator
	public:
		const HBufferParseSave& operator=( const HBufferParseSave& in_rhs );
		HBOOL operator==( const HBufferParseSave& in_rhs )const;
		HBOOL operator!=( const HBufferParseSave& in_rhs )const;

		///////////////////////////////////////////////////////////
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
		const HBuffer& BufferGet()const;

		///////////////////////////////////////////////////////////
		// private Members
	private:
		TSaveBinPointer m_pSaveBin;
		TSaveTextPointer m_pSaveText;

	};

	/**/
};

#endif// _H_BUFFER_PARSE_SAVE_H_
