//file: Sloth/SWindow/SWindowParamOpenGl.h
#ifndef _S_WINDOW_PARAM_OPEN_GL_H_
#define _S_WINDOW_PARAM_OPEN_GL_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include "Sloth/SWindow/SWindowParam.h"

namespace Sloth
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class SCursor;
	class SIcon;
	class SMenu;

	///////////////////////////////////////////////////////
	// struct
	/**/
	struct SWindowParamOpenGl : public SWindowParam
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		SWindowParamOpenGl(
			const Hubris::HString& in_className = "SWindowDefault",
			const Hubris::HString& in_windowTitle = "default title",
			const Hubris::HBOOL in_showWindow = HTRUE,
			const Hubris::HU32 in_classStyle = ClassStyleDefaultGet(),
			const Hubris::HU32 in_windowStyle = WindowStyleDefaultGet(),
			const Hubris::HVectorS2& in_windowOrigin = Hubris::HMatrixConstructor::HVectorS2Construct( 100, 100 ),
			const Hubris::HVectorS2& in_windowDimention = Hubris::HMatrixConstructor::HVectorS2Construct( 320, 240 ),
			//SInput* const in_pInput = HNULL,
			SCursor* const in_pCursor = HNULL,
			SIcon* const in_pIcon = HNULL,
			SMenu* const in_pMenu = HNULL
			);
		~SWindowParamOpenGl();

		///////////////////////////////////////////////////////
		// disabled
	public:
		SWindowParamOpenGl( const SWindowParamOpenGl& in_src );
		const SWindowParamOpenGl& operator=( const SWindowParamOpenGl& in_rhs );

		///////////////////////////////////////////////////////
		// public static accessors
	public:
		static const Hubris::HU32 ClassStyleDefaultGet();
		static const Hubris::HU32 WindowStyleDefaultGet();


	};

	/**/
	
};

#endif // _S_WINDOW_PARAM_H_