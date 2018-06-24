//file: Sloth/SInput/SInputParam.h
#ifndef _S_INPUT_PARAM_H_
#define _S_INPUT_PARAM_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SInput;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SInputParam
	{
		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		SInputParam();
		~SInputParam();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SInputParam( const SInputParam& in_src );
		const SInputParam& operator=( const SInputParam& in_rhs );

		///////////////////////////////////////////////////////
		// public accessors
	public:

		///////////////////////////////////////////////////////
		// private members
	private:


	};

	/**/
	
};

#endif // _S_INPUT_PARAM_H_