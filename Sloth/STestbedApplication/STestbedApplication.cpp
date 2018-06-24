//file: Sloth/STestbedApplication/STestbedApplication.cpp

#include "Sloth/STestbedApplication/STestbedApplication.h"

#include< Hubris/Hubris_Export.h >
#include< Pride/Pride_Export.h >
#include< Sloth/Sloth_Export.h >

#include <WINDOWS.H>
#include< gl/gl.h >
#include< gl/glu.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;
using namespace Sloth;

/////////////////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< SLight >TArrayLight;
typedef Hubris::HContainerArray< HREAL >TArrayReal;
typedef Hubris::HContainerArray< HSINT >TArraySint;
typedef Hubris::HContainerArray< PTriangle >TArrayTriangle;
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
typedef Hubris::HContainerStaticArray< TPairRealSint, 4 >TStaticArray4PairRealSint;
typedef Hubris::HContainerArray< Hubris::HMatrixR4 >TArrayMatrix;
typedef Hubris::HContainerArray< Hubris::HVectorR3 >TArrayVector;

/////////////////////////////////////////////////////////////////
// local class	
/**/
struct STaskObject
{
	static HVOID Run( SApplication& in_application )
	{
		PImageRgba imageCursor;
		HFileSystem fileSystem;
		PImageTga::TgaLoadGeneric( fileSystem, "data\\cursor.tga", imageCursor );
		SCursorParam cursorParam(
			imageCursor,
			HMatrixConstructor::HVectorS2Construct( 2, 2 )
			);
		SCursor* pCursor = in_application.CursorRequest( cursorParam );

		SIconParam iconParam(
			imageCursor,
			imageCursor
			);
		SIcon* pIcon = in_application.IconRequest( iconParam );
		SInput input;

		SWindowParamOpenGl windowParam;
		windowParam.CursorSet( pCursor );
		windowParam.IconSet( pIcon );

		SWindowRender* pWindow = in_application.WindowRenderRequest( windowParam );

		if( HNULL == pWindow )
		{
			return;
		}

		pWindow->InputSet( &input );

		PBoundsR3 bound0( 
			HMatrixConstructor::HVectorR3Construct( -12.0F, -1.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( -10.0F,  1.0F,  1.0F )
			);
		PBoundsR3 bound1( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -12.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F, -10.0F,  1.0F )
			);
		PBoundsR3 bound2( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F, -12.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F, -10.0F )
			);
		PBoundsR3 bound3( 
			HMatrixConstructor::HVectorR3Construct(  10.0F, -1.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  12.0F,  1.0F,  1.0F )
			);
		PBoundsR3 bound4( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, 10.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F, 12.0F,  1.0F )
			);
		PBoundsR3 bound5( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  10.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  12.0F )
			);

		PBoundsR3 bound6( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, 2.0F,  -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  4.0F,  1.0F )
			);
		PBoundsR3 bound7( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  -4.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  -2.0F )
			);
		PBoundsR3 bound8( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  2.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  4.0F )
			);
		PBoundsR3 bound9( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -1.0F,  -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  1.0F,  1.0F )
			);
		PBoundsR3 bound10( 
			HMatrixConstructor::HVectorR3Construct( -1.0F, -4.0F,  -1.0F ),
			HMatrixConstructor::HVectorR3Construct(  1.0F,  -2.0F,  1.0F )
			);

		const HMatrixR4 objectMatrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
		const HREAL cameraMatrixData[ 16 ] = {
			0.0F, -1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			-1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 0.0F, 1.0F,
		};
		const HMatrixR4 cameraMatrix( cameraMatrixData );

		//HMatrixR4 cameraMatrix = HMatrixUtility::IdentityGet< HMatrixR4 >();
		//HMatrixUtility::TranslateSet< HMatrixR4, HVectorR3 >( cameraMatrix, HMatrixConstructor::HVectorR3Construct( 0.25F, 0.0F, 0.0F ) ); 

		PCamera camera(
			cameraMatrix,
			//PCamera::TypeOrthogonalGet(),
			PCamera::TypePerspectiveGet(),
			-1.0f, 1.0f, -0.68f, 0.68f, 1.0f, 100.0F
			);

		SComponentDelta componentDelta;
		SComponentFPS componentFPS;
		SComponentFlyCamera componentFlyCamera( camera );
		SLight light0(
			SLight::ModePointGet(),
			PColourRealRgb( 1.0F, 0.0F, 0.0F ),
			HMatrixConstructor::HVectorR3Construct( 10.0F, 10.0F, 10.0F ),
			50.0F
			);
		SLight light1(
			SLight::ModeDirectGet(),
			PColourRealRgb( 0.0F, 1.0F, 0.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 0.0F ),
			50.0F
			);

		TArrayLight arrayLight;
		arrayLight.Insert(
			light0
			);
		arrayLight.Insert(
			light1
			);

		TArrayReal testTriangle;
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  1.0F );

		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );

		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  1.0F );

		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert( -1.0F );
		testTriangle.Insert(  0.0F );
		testTriangle.Insert(  1.0F );
		testTriangle.Insert(  1.0F );

		TArrayTriangle arrayTriangle;
		arrayTriangle.Insert( PTriangle(
			HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, -1.0F, 1.0F )
			) );
		arrayTriangle.Insert( PTriangle(
			HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, -1.0F, 1.0F ),
			HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, -1.0F )
			) );
		arrayTriangle.Insert( PTriangle(
			HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, -1.0F, 1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 1.0F )
			) );
		arrayTriangle.Insert( PTriangle(
			HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( -1.0F, 0.0F, -1.0F ),
			HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 1.0F )
			) );

		HVOID* geometryId = HNULL;
		SMaterialGeometryStage renderStage;
		HSINT topologyVertexIndex = 0;
		HSINT indexPos = 0;
		HSINT indexNormal = 0;
		PGeometry geometry;
		PGeometryTypeSignature typeSig;
		{
			indexPos = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() );
			const HSINT indexUv0 = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), PGeometryTypeSignature::NameGetUv() );
			const HSINT indexColour = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataColour(), PGeometryTypeSignature::NameGetColour() );
			indexNormal = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetNormal() );
			const HSINT indexSkinning = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint(), PGeometryTypeSignature::NameGetSkinWeight() );
			const HSINT indexSpring = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetSpring() );

			TArraySint arrayDynamicIndex;
			TArraySint arrayIndex;
			HContainerUtility::PushBack( arrayIndex, indexPos );
			HContainerUtility::PushBack( arrayIndex, indexUv0 );
			HContainerUtility::PushBack( arrayIndex, indexColour );
			HContainerUtility::PushBack( arrayIndex, indexNormal );
			HContainerUtility::PushBack( arrayIndex, indexSkinning );
			HContainerUtility::PushBack( arrayIndex, indexSpring );


			HContainerUtility::PushBack( arrayDynamicIndex, indexPos );
			HContainerUtility::PushBack( arrayDynamicIndex, indexNormal );

			topologyVertexIndex = typeSig.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayIndex );
			const HSINT indexTopology = typeSig.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), topologyVertexIndex );
			TStaticArray4PairRealSint skinningData0;
			skinningData0.Insert( TPairRealSint( 1.0F, 0 ) );
			TStaticArray4PairRealSint skinningData1;
			skinningData1.Insert( TPairRealSint( 0.25F, 0 ) );
			skinningData1.Insert( TPairRealSint( 0.75F, 1 ) );
			TStaticArray4PairRealSint skinningData2;
			skinningData2.Insert( TPairRealSint( 1.0F, 1 ) );

			renderStage = SMaterialGeometryStage(
				indexTopology,
				indexPos,
				indexColour, //HCOMMON_INVALID_INDEX, //indexColour, 
				indexNormal,
				indexUv0
				);

			geometry.TypeSignatureSet( typeSig );
			const HVectorR3 springConstants0 = HMatrixConstructor::HVectorR3Construct( 100.0F, 0.5F, 0.5F );
			const HVectorR3 springConstants1 = HMatrixConstructor::HVectorR3Construct( 100.0F, 5.0F, 5.0F );

			PGeometryVertex vertex0( typeSig, topologyVertexIndex );
			vertex0.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 0.0F ) );
			vertex0.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 0.0F, 0.0F ) );
			vertex0.ColourRgbaSet( indexColour, PColourRgba( 255, 0, 0, 0 ) );
			vertex0.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex0.StaticArray4PairRealSintSet( indexSkinning, skinningData0 );
			vertex0.VectorR3Set( indexSpring, springConstants0 );

			PGeometryVertex vertex1( typeSig, topologyVertexIndex );
			vertex1.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 10.0F, 0.0F, 0.0F ) );
			vertex1.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );
			vertex1.ColourRgbaSet( indexColour, PColourRgba( 0, 255, 0, 255 ) );
			vertex1.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex1.StaticArray4PairRealSintSet( indexSkinning, skinningData0 );
			vertex1.VectorR3Set( indexSpring, springConstants1 );

			PGeometryVertex vertex2( typeSig, topologyVertexIndex );
			vertex2.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 0.0F, 10.0F, 0.0F ) );
			vertex2.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ) );
			vertex2.ColourRgbaSet( indexColour, PColourRgba( 0, 0, 255, 0 ) );
			vertex2.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex2.StaticArray4PairRealSintSet( indexSkinning, skinningData1 );
			vertex2.VectorR3Set( indexSpring, springConstants0 );

			PGeometryVertex vertex3( typeSig, topologyVertexIndex );
			vertex3.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 10.0F, 10.0F, 0.0F ) );
			vertex3.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 1.0F, 1.0F ) );
			vertex3.ColourRgbaSet( indexColour, PColourRgba( 0, 0, 0, 255 ) );
			vertex3.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex3.StaticArray4PairRealSintSet( indexSkinning, skinningData1 );
			vertex3.VectorR3Set( indexSpring, springConstants1 );

			PGeometryVertex vertex4( typeSig, topologyVertexIndex );
			vertex4.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 0.0F, 20.0F, 0.0F ) );
			vertex4.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 0.0F, 0.0F ) );
			vertex4.ColourRgbaSet( indexColour, PColourRgba( 0, 0, 255, 0 ) );
			vertex4.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex4.StaticArray4PairRealSintSet( indexSkinning, skinningData2 );
			vertex4.VectorR3Set( indexSpring, springConstants0 );

			PGeometryVertex vertex5( typeSig, topologyVertexIndex );
			vertex5.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 10.0F, 20.0F, 0.0F ) );
			vertex5.VectorR2Set( indexUv0, HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F ) );
			vertex5.ColourRgbaSet( indexColour, PColourRgba( 0, 0, 0, 255 ) );
			vertex5.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			vertex5.StaticArray4PairRealSintSet( indexSkinning, skinningData2 );
			vertex5.VectorR3Set( indexSpring, springConstants1 );

			const HSINT vertexIndex0 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex0 );
			const HSINT vertexIndex1 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex1 );
			const HSINT vertexIndex2 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex2 );
			const HSINT vertexIndex3 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex3 );
			const HSINT vertexIndex4 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex4 );
			const HSINT vertexIndex5 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex5 );

			HSINT strip0[] = { vertexIndex0, vertexIndex1, vertexIndex2, vertexIndex3, vertexIndex4, vertexIndex5 };
			geometry.StoreTopologyTriangleStripGet( indexTopology ).StripAdd( strip0, 6 );
			HSINT strip1[] = { vertexIndex1, vertexIndex0, vertexIndex3, vertexIndex2 };
			geometry.StoreTopologyTriangleStripGet( indexTopology ).StripAdd( strip1, 4 );

			SInterfaceRender* pInterfaceRender = pWindow->RenderInterfaceCreate();
			geometryId = pInterfaceRender->GeometryCreate( geometry, arrayDynamicIndex );
			pInterfaceRender->DeleteThis();
		}

		{
			SInterfaceRender* pInterfaceRender = pWindow->RenderInterfaceCreate();
			pInterfaceRender->TextureSet( 0, imageCursor );
			pInterfaceRender->DeleteThis();
		}

		HSINT spriteIndex = HCOMMON_INVALID_INDEX;
		{
			SInterfaceRender* pInterfaceRender = pWindow->RenderInterfaceCreate();
			spriteIndex = pInterfaceRender->SpriteCreate(
				HMatrixConstructor::HVectorR2Construct( 1.0F, 2.0F ),
				HMatrixConstructor::HVectorR2Construct( 0.0F, 0.0F ),
				HMatrixConstructor::HVectorR2Construct( 1.0F, 1.0F ),
				PColourRealRgba( 1.0F, 1.0F, 1.0F, 1.0F )
				);
			pInterfaceRender->DeleteThis();
		}

		SMaterialStage materialStage;
		{
			materialStage.FlagUseTextureSet( HTRUE );
			materialStage.FlagAlphaBlendSet( HTRUE );
			materialStage.BlendModeSourceSet( SMaterialStage::BlendModeSourceAlphaGet() );
			materialStage.BlendModeDestinationSet( SMaterialStage::BlendModeOneMinusSourceAlphaGet() );
		}

		SMaterialStage materialStage2;
		{
			materialStage2.ColourAmbientSet( PColourRealRgb( 0.5F, 1.0F, 0.0F ) );
			//materialStage2.ColourEmissionSet( PColourRealRgb( 0.5F, 1.0F, 0.0F ) );
			//materialStage2.ColourDiffuseSet( PColourRealRgb( 0.5F, 1.0F, 0.0F ) );
			materialStage2.FlagUseLightSet( HTRUE );
			//materialStage2.ColourDiffuseSet( PColourRealRgb( 0.5F, 1.0F, 0.0F ) );
			materialStage2.AlphaSet( 0.5F );
			materialStage2.FlagZWriteSet( HFALSE );
			materialStage2.FlagAlphaBlendSet( HTRUE );
			materialStage2.BlendModeSourceSet( SMaterialStage::BlendModeSourceAlphaGet() );
			materialStage2.BlendModeDestinationSet( SMaterialStage::BlendModeOneMinusSourceAlphaGet() );

//
//			SInterfaceRender* pInterfaceRender = pWindow->RenderInterfaceCreate();
//
//			SMaterialStageShader shader;
//
////	gl_FrontColor = ( gl_Color * gl_FrontMaterial.diffuse ) + gl_FrontMaterial.emission;\n\
//
//			shader.ShaderGLSLVertexGet() = "\
//void main()\n\
//{\n\
//	gl_FrontColor = vec4( 1.0, 0.0, 0.0, 0.5 );\n\
//	gl_BackColor = ( gl_Color * gl_BackMaterial.diffuse ) + gl_BackMaterial.emission;\n\
//\n\
//	gl_Position = ftransform();\n\
//	gl_TexCoord[ 0 ] = gl_MultiTexCoord0;\n\
//	gl_NormalMatrix * gl_Normal;\n\
//}\n\
//";
//			pInterfaceRender->ShaderCreate( "shader", shader );
//
//			pInterfaceRender->DeleteThis();

		}

		TArrayMatrix arrayMatrix;
		arrayMatrix.SizeSet( 2 );
		arrayMatrix[ 0 ] = HMatrixUtility::IdentityGet< HMatrixR4 >();
		arrayMatrix[ 1 ] = HMatrixUtility::IdentityGet< HMatrixR4 >();
		TArrayReal vertexPosition;
		TArrayReal vertexNormal;
		TArrayReal vertexPositionSpring;
		TArrayVector vertexVelocity;

		HREAL boneVar = 0.0F;

		while( HTRUE == pWindow->Update() )
		{
			componentDelta.StartNewFrame();
			const HREAL delta = componentDelta.LastDeltaGet();
			componentFPS.NotifyNewFrame( delta );

			componentFlyCamera.Update( delta, input );

			pWindow->DebugTextClear();
			pWindow->DebugTextDraw(
				"FPS: " + HTraitStringIn( componentFPS.FPSGet() ),
				HMatrixConstructor::HVectorS2Construct( 0, 0 )
				);

			const HVectorR3 cameraTransform = HMatrixUtility::TranslateGet< HMatrixR4, HVectorR3 >( componentFlyCamera.CameraGet().TransformGet() );
			pWindow->DebugTextDraw(
				HTraitStringIn( cameraTransform[ 0 ] ),
				HMatrixConstructor::HVectorS2Construct( 0, 1 )
				);
			pWindow->DebugTextDraw(
				HTraitStringIn( cameraTransform[ 1 ] ),
				HMatrixConstructor::HVectorS2Construct( 0, 2 )
				);
			pWindow->DebugTextDraw(
				HTraitStringIn( cameraTransform[ 2 ] ),
				HMatrixConstructor::HVectorS2Construct( 0, 3 )
				);

			const PUnitVectorR3 unitVectorAt( HMatrixUtility::VectorProductNoTranslate( 
				componentFlyCamera.CameraGet().TransformGet(),
				-HMatrixConstructor::HVectorR3AxisZ()
				) );

			HREAL latitude = HVariablesMath::ZeroGet< HREAL >();
			HREAL longitude = HVariablesMath::ZeroGet< HREAL >();

			PUnitVectorUtility::PolarFromUnitVector(
				latitude,
				longitude,
				unitVectorAt
				);

			pWindow->DebugTextDraw(
				HTraitStringIn( latitude ),
				HMatrixConstructor::HVectorS2Construct( 0, 5 )
				);
			pWindow->DebugTextDraw(
				HTraitStringIn( longitude ),
				HMatrixConstructor::HVectorS2Construct( 0, 6 )
				);

			SInterfaceRender* pInterfaceRender = pWindow->RenderInterfaceCreate();
			pInterfaceRender->Clear(
				HTRUE,
				HTRUE,
				PColourRealRgba( 0.5F, 0.5F, 0.5F, 0.0F ),
				1.0F
				);

			pInterfaceRender->CameraSet( 
				componentFlyCamera.CameraGet()
				);

			pInterfaceRender->ModelTransformSet( objectMatrix );

			pInterfaceRender->LightSet(
				arrayLight,
				PColourRealRgb( 0.2F, 0.2F, 0.2F )
				);

			pInterfaceRender->MaterialSet( materialStage2 );
			pInterfaceRender->DrawBox( bound0 );
			pInterfaceRender->DrawBox( bound1 );
			pInterfaceRender->DrawBox( bound2 );
			pInterfaceRender->DrawBox( bound3 );
			pInterfaceRender->DrawBox( bound4 );
			pInterfaceRender->DrawBox( bound5 );

			boneVar += delta;
			while( 2.0F < boneVar )
			{
				boneVar -= 2.0F;
			}
			HMatrixUtility::TranslateSet( arrayMatrix[ 1 ], HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F,  boneVar ) );

			PGeometryUtility::PerformSkinning(
				vertexPosition,
				vertexNormal,
				typeSig, 
				geometry,
				topologyVertexIndex,
				arrayMatrix
				);

			PGeometryUtility::PerformSpring( 
				vertexPositionSpring,
				vertexVelocity,
				vertexPosition, //skin target
				typeSig, 
				geometry,
				topologyVertexIndex,
				delta
				);

			pInterfaceRender->GeometryUpdateData(
				geometryId,
				indexPos,
				vertexPositionSpring.RawGet(),
				0,
				vertexPositionSpring.SizeGet() * sizeof( HREAL )
				);

			pInterfaceRender->GeometryUpdateData(
				geometryId,
				indexNormal,
				vertexNormal.RawGet(),
				0,
				vertexPosition.SizeGet() * sizeof( HREAL )
				);

			pInterfaceRender->MaterialSet( materialStage );
			pInterfaceRender->DrawGeometry(
				geometryId,
				renderStage
				);

			pInterfaceRender->ModelTransformSet( HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );
			pInterfaceRender->DrawSprite( spriteIndex );

			pInterfaceRender->ModelTransformSet( HMatrixConstructor::HVectorR3Construct( 2.0F, 0.0F, 1.0F ) );
			pInterfaceRender->DrawSprite( spriteIndex );

			pInterfaceRender->ModelTransformSet( HMatrixConstructor::HVectorR3Construct( 0.0F, 4.0F, 1.0F ) );
			pInterfaceRender->DrawSprite( spriteIndex );

			pInterfaceRender->DeleteThis();

		}

		in_application.WindowRenderRelease( pWindow );
		in_application.CursorRelease( pCursor );
		in_application.IconRelease( pIcon );

		return;
	}
};

/**/
int __stdcall WinMain(
	HINSTANCE in_hInstance,
    HINSTANCE HCOMMON_UNUSED_VAR( in_hPrevInstance ),
    LPSTR in_lpCmdLine,
    int in_nCmdShow
)
{
	SApplication application( in_hInstance, in_lpCmdLine, in_nCmdShow );

	STaskObject::Run( application );

	return 0;
}

/**/