//file: Vanity/VTestbed/VTestbedScene.cpp

#include "Vanity/VTestbed/VTestbedScene.h"

#include< Sloth/SMaterial/SMaterial_Export.h >
#include< Sloth/SLight/SLight_Export.h >

#include< Greed/Greed_Export.h >

//////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Envy;
using namespace Pride;
using namespace Vanity;
using namespace Sloth;
using namespace Greed;

//////////////////////////////////////////////////////
// typedef
/**/
typedef Hubris::HContainerArray< HSINT >TArraySint;
typedef Hubris::HContainerPair< Sloth::SMaterialStage, Sloth::SMaterialGeometryStage >TPairMaterialGeometryStage;
typedef Hubris::HContainerArray< TPairMaterialGeometryStage >TArrayPairMaterialGeometryStage;
typedef Hubris::HContainerArray< VComponentVisualAssetParticleTypeData >TArrayParticleTypeData;
typedef Hubris::HContainerPair< Pride::PUnitVectorR3, Hubris::HREAL >TPairUnitVectorReal;
typedef Hubris::HContainerArray< TPairUnitVectorReal >TArrayPairUnitVectorReal;
typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyGeometryData >TArrayGeometryData;
typedef Hubris::HContainerArray< VComponentVisualAssetHierarchyBoneData >TArrayBoneData;
typedef Hubris::HContainerPair< Hubris::HREAL, Hubris::HSINT >TPairRealSint;
typedef Hubris::HContainerStaticArray< TPairRealSint, 4 >TStaticArray4PairRealSint;


struct TLathData
{
	HREAL m_posX;
	HREAL m_posY;
	HREAL m_posZ;
	HREAL m_normalX;
	HREAL m_normalY;
	HREAL m_normalZ;
};

static const TLathData s_lathData0[] = {
	{ 10.0F, 10.0F, 0.0F, 0.0F, 0.0F, 1.0F },
	{ 5.0F, 5.0F, 0.0F, 0.0F, 0.0F, 1.0F }
};
static const HREAL s_uvData0[] = {
	0.0F, 0.0F, 0.0F, 1.0F,
	0.25F, 0.25F, 0.25F, 0.75F
};

static const TLathData s_lathData1[] = {
	{ 5.0F, 5.0F, 0.0F, 0.0F, 1.0F, 0.0F },
	{ 5.0F, 5.0F, 1.0F, 0.0F, 1.0F, 0.0F }
};
static const HREAL s_uvData1[] = {
	0.25F, 0.25F, 0.25F, 0.75F,
	0.3F, 0.25F, 0.3F, 0.75F
};

static const TLathData s_lathData2[] = {
	{ 5.0F, 5.0F, 1.0F, 0.0F, 0.0F, 1.0F },
	{ 4.0F, 4.0F, 1.0F, 0.0F, 0.0F, 1.0F }
};
static const HREAL s_uvData2[] = {
	0.25F, 0.25F, 0.25F, 0.75F,
	0.3F, 0.3F, 0.3F, 0.7F
};

static const TLathData s_lathData3[] = {
	{ 4.0F, 4.0F, 1.0F, 0.7071F, 0.7071F, 0.0F },
	{ 4.0F, 4.0F, 9.0F, 0.7071F, 0.7071F, 0.0F },
	{ 4.0F, 4.0F,17.0F, 0.7071F, 0.7071F, 0.0F },
	{ 4.0F, 4.0F,25.0F, 0.7071F, 0.7071F, 0.0F }
};
static const HREAL s_uvData3[] = {
	0.3F, 0.0F, 0.7F, 0.0F,
	0.3F, 0.4F, 0.7F, 0.4F,
	0.3F, 0.8F, 0.7F, 0.8F,
	0.3F, 0.4F, 0.7F, 0.4F,
};


//////////////////////////////////////////////////////
// local static functions
/**/
static const TArrayGeometryData& LocalArrayGeometryDataGet()
{
	static TArrayGeometryData s_arrayBoneData;

	if( 0 == s_arrayBoneData.SizeGet() )
	{

		PGeometryTypeSignature typeSig;

		const HSINT indexPos = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() );
		const HSINT indexNormal = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetNormal() );
		const HSINT indexSkinning = typeSig.DataStreamAdd( PGeometryTypeSignature::TypeGetDataStaticArray4PairRealSint(), PGeometryTypeSignature::NameGetSkinWeight() );

		TArraySint arrayIndex;
		HContainerUtility::PushBack( arrayIndex, indexPos );
		HContainerUtility::PushBack( arrayIndex, indexNormal );
		HContainerUtility::PushBack( arrayIndex, indexSkinning );

		const HSINT indexVertex = typeSig.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayIndex );
		const HSINT indexTopology = typeSig.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), indexVertex );

		PGeometry geometry( typeSig );

		TArraySint arrayStrip;
		const HSINT count = 10;
		for( HSINT index = 0; index < count; ++index )
		{
			TStaticArray4PairRealSint skinningData;
			if( 0 != index )
			{
				skinningData.Insert( TPairRealSint( 9.0F / ( 9 - index ), 0 ) );
			}
			if( ( count - 1 ) != index )
			{
				skinningData.Insert( TPairRealSint( 9.0F / ( index ), 1 ) );
			}

			PGeometryVertex vertex0( typeSig, indexVertex );
			vertex0.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( -0.5F, 0.0F, ( HREAL )index ) );
			vertex0.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3AxisY() );
			vertex0.StaticArray4PairRealSintSet( indexSkinning, skinningData );

			PGeometryVertex vertex1( typeSig, indexVertex );
			vertex1.VectorR3Set( indexPos, HMatrixConstructor::HVectorR3Construct( 0.5F, 0.0F, ( HREAL )index ) );
			vertex1.VectorR3Set( indexNormal, HMatrixConstructor::HVectorR3AxisY() );
			vertex1.StaticArray4PairRealSintSet( indexSkinning, skinningData );

			const HSINT vertexIndex0 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex0 );
			const HSINT vertexIndex1 = PGeometryUtility::VertexAdd( typeSig, geometry, vertex1 );

			HContainerUtility::PushBack( arrayStrip, vertexIndex0 );
			HContainerUtility::PushBack( arrayStrip, vertexIndex1 );
		}

		geometry.StoreTopologyTriangleStripGet( indexTopology ).StripAdd( arrayStrip.RawGet(), arrayStrip.SizeGet() );

		SMaterialStage materialStage;
		materialStage.FlagUseLightSet( HTRUE );
		materialStage.FlagZReadSet( HTRUE );
		materialStage.FlagZWriteSet( HTRUE );
		materialStage.FlagUseTextureSet( HFALSE );

		SMaterialGeometryStage geometryStage;
		geometryStage.VertexIndexSet( indexPos );
		geometryStage.NormalIndexSet( indexNormal );
		geometryStage.TopologyIndexSet( indexTopology );

		SMaterial material;
		material.ArrayStageGeometryGet().Insert( TPairMaterialGeometryStage( materialStage, geometryStage ) );

		s_arrayBoneData.Insert( VComponentVisualAssetHierarchyGeometryData( HCOMMON_INVALID_INDEX, geometry, material ) );
	}

	return s_arrayBoneData;
}

/**/
static const TArrayBoneData& LocalArrayBoneDataGet()
{
	static TArrayBoneData s_arrayBoneData;
	if( 0 == s_arrayBoneData.SizeGet() )
	{
		const HREAL dataMatrix1[] = {
			1.0F, 0.0F, 0.0F, 0.0F,
			0.0F, 1.0F, 0.0F, 0.0F,
			0.0F, 0.0F, 1.0F, 0.0F,
			0.0F, 0.0F, 2.0F, 1.0F,
		};
		s_arrayBoneData.Insert( VComponentVisualAssetHierarchyBoneData( HCOMMON_INVALID_INDEX, HMatrixUtility::IdentityGet< HMatrixR4 >() ) );
		s_arrayBoneData.Insert( VComponentVisualAssetHierarchyBoneData( 0, HMatrixR4( dataMatrix1 ) ) );
	}
	return s_arrayBoneData;
}

/**/
static Hubris::HVOID LocalPlayerCharacterGameObjectMementoGenerate( EMementoCollect& in_out_mementoCollect )
{
	GPlayerCharacter playerCharacter;

	GPlayerCharacter::GameObjectCollect(
		in_out_mementoCollect,
		playerCharacter
		);

	return;
}

/**
static Hubris::HVOID LocalParticleGameObjectMementoGenerate( EMementoCollect& in_out_mementoCollect )
{
	GParticleEmittor particleEmittor;

	particleEmittor.MaximumParticleCountSet( 30 );
	particleEmittor.EmittorShapeGet().Insert( TPairUnitVectorReal( PUnitVectorR3( HMatrixConstructor::HVectorR3AxisZ() ), 1.0F ) );

	GParticleEmittorType particleEmittorType;
	particleEmittorType.ColourGet() = PColourVariablesRgba::WhiteGet();
	particleEmittorType.ColourGet().OpacitySet( 127 );
	particleEmittorType.SizeSet( 0.5F );
	//particleEmittorType.SizeRandSet( 5.0F );
	//particleEmittorType.VelocityGet() = HMatrixConstructor::HVectorR3Construct( 0.0F, 10.0F, 0.0F ); //HMatrixConstructor::HVectorR3AxisX();
	particleEmittorType.VelocityRandGet() = HMatrixConstructor::HVectorR3Construct( 5.0F, 5.0F, 5.0F );
	particleEmittorType.FlowRateSet( 2.0F );
	particleEmittorType.LifeSpanSet( 5.0F );
	particleEmittorType.UvTypeSet( 0 );
	particleEmittorType.AnimationSet( HTRUE );
	particleEmittorType.ForceFlagSet( VComponentForce::FlagGetForceGravity() );
	particleEmittorType.ParticleFlagSet( 
		GParticleEmittorType::ParticleFlagBillboardGet() |
		GParticleEmittorType::ParticleFlagCollisionSplatGet() 		
		//GParticleEmittorType::ParticleFlagCollisionBounceGet() 		
		);
	particleEmittorType.InvertMassSet( 1.0F );
	{
		typedef Hubris::HREAL TTime;
		typedef Hubris::HContainerPair< TTime, Hubris::HREAL >TPairTimeReal;
		typedef Hubris::HContainerArray< TPairTimeReal >TArrayPairTimeReal;
		typedef Hubris::HContainerPair< TTime, Hubris::HVectorR4 >TPairTimeVectorR4;
		typedef Hubris::HContainerArray< TPairTimeVectorR4 >TArrayPairTimeVectorR4;

		TArrayPairTimeVectorR4 arrayTimeColour;
		arrayTimeColour.Insert( TPairTimeVectorR4( 0.0F, HMatrixConstructor::HVectorR4Construct( 1.0F, 1.0F, 1.0F, 1.0F ) ) );
		arrayTimeColour.Insert( TPairTimeVectorR4( 1.0F, HMatrixConstructor::HVectorR4Construct( 0.0F, 0.0F, 0.0F, 1.0F ) ) );
		//TArrayPairTimeReal arrayTimeSize;
		//arrayTimeSize.Insert( TPairTimeReal( 0.0F, 0.5F ) );
		//arrayTimeSize.Insert( TPairTimeReal( 1.0F, 2.0F ) );

		VAnimation animation;
		animation.NameGet() = "default";
		animation.DataSet( "m_colour", VAnimation::FlagDataInterpolatorLerpGet(), arrayTimeColour );
		//animation.DataSet( "m_size", VAnimation::FlagDataInterpolatorLerpGet(), arrayTimeSize );

		particleEmittorType.AnimationGet() = animation;
	}


	particleEmittor.ArrayTypeGet().Insert( particleEmittorType );

	GParticleEmittorState particleEmittorState;
	particleEmittorState.DurationSet( -1.0F );
	particleEmittorState.ArrayTypeIndexGet().Insert( 0 );

	particleEmittor.StateMachineGet().StateAdd( "default", particleEmittorState );
	particleEmittor.ArrayPendingStateNameGet().Insert( "default" );

	GParticleEmittor::GameObjectCollect(
		in_out_mementoCollect,
		particleEmittor
		);

	return;
}

/**/
static const Hubris::HVectorR3 LocalVectorGet( const HREAL in_x, const HREAL in_y, const HREAL in_z, const HSINT in_rotation )
{
	const HSINT index = in_rotation % 4;
	switch( index )
	{
	default:
		{
			break;
		}
	case 0:
		{
			return HMatrixConstructor::HVectorR3Construct( in_x, in_y, in_z );
		}
	case 1:
		{
			return HMatrixConstructor::HVectorR3Construct( -in_y, in_x, in_z );
		}
	case 2:
		{
			return HMatrixConstructor::HVectorR3Construct( -in_x, -in_y, in_z );
		}
	case 3:
		{
			return HMatrixConstructor::HVectorR3Construct( in_y, -in_x, in_z );
		}
	}

	return HVectorR3();
}

/**/
static HVOID LocalStripAdd( 
	const TLathData * const in_pLathData,
	const HSINT in_size,
	const HREAL* const in_pUvData,
	const HSINT in_rotation,
	PGeometryStoreTriangleStrip& in_storeTriangleStrip, 
	PGeometryTypeSignature& in_typeSignature, 
	PGeometry& in_out_geometry, 
	const HSINT in_vertexStoreIndex, 
	const HSINT in_positionStreamIndex, 
	const HSINT in_noramlStreamIndex, 
	const HSINT in_uvStreamIndex 
	)
{
	TArraySint arrayIndex;	
	HSINT trace = 0;
	for( HSINT index = 0; index < in_size; ++index )
	{
		PGeometryVertex vertex( in_typeSignature, in_vertexStoreIndex );
		PGeometryUtility::DefaultVertex( in_typeSignature, vertex );
		const TLathData& data = in_pLathData[ index ];

		vertex.VectorR3Set( in_positionStreamIndex, LocalVectorGet( data.m_posX, data.m_posY, data.m_posZ, in_rotation ) );
		vertex.VectorR3Set( in_noramlStreamIndex, LocalVectorGet( data.m_normalX, data.m_normalY, data.m_normalZ, in_rotation ) );
		vertex.VectorR2Set( in_uvStreamIndex, HMatrixConstructor::HVectorR2Construct( in_pUvData[ trace ], in_pUvData[ trace + 1 ] ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( in_typeSignature, in_out_geometry, vertex ) );
		trace += 2;

		vertex.VectorR3Set( in_positionStreamIndex, LocalVectorGet( data.m_posX, data.m_posY, data.m_posZ, in_rotation + 1 ) );
		vertex.VectorR3Set( in_noramlStreamIndex, LocalVectorGet( data.m_normalX, data.m_normalY, data.m_normalZ, in_rotation + 1 ) );
		vertex.VectorR2Set( in_uvStreamIndex, HMatrixConstructor::HVectorR2Construct( in_pUvData[ trace ], in_pUvData[ trace + 1 ] ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( in_typeSignature, in_out_geometry, vertex ) );
		trace += 2;
	}

	in_storeTriangleStrip.StripAdd( arrayIndex );

	return;
}

/**/
static Hubris::HVOID LocalCreateGeometry( PGeometry& in_out_geometry )
{
	PGeometryTypeSignature typeSignature;
	TArraySint arrayDataIndex;

	const HSINT positionStreamIndex = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetPosition() );
	arrayDataIndex.Insert( positionStreamIndex );
	const HSINT noramlStreamIndex = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR3(), PGeometryTypeSignature::NameGetNormal() );
	arrayDataIndex.Insert( noramlStreamIndex );
	const HSINT uvStreamIndex = typeSignature.DataStreamAdd( PGeometryTypeSignature::TypeGetDataVectorR2(), PGeometryTypeSignature::NameGetUv() );
	arrayDataIndex.Insert( uvStreamIndex );

	const HSINT vertexStoreIndex = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyVertexIndex(), arrayDataIndex );
	const HSINT triangleStripIndex = typeSignature.TopologyStreamAdd( PGeometryTypeSignature::TypeGetTopologyTriangleStrip(), vertexStoreIndex );

	in_out_geometry.TypeSignatureSet( typeSignature );
	PGeometryStoreTriangleStrip& storeTriangleStrip = in_out_geometry.StoreTopologyTriangleStripGet( triangleStripIndex );

	for( HSINT index = 0; index < 4; ++index )
	{
		LocalStripAdd( 
			s_lathData0, 
			HCOMMON_ARRAY_SIZE( s_lathData0 ), 
			s_uvData0,
			index, 
			storeTriangleStrip, 
			typeSignature, 
			in_out_geometry,
			vertexStoreIndex,
			positionStreamIndex, 
			noramlStreamIndex,
			uvStreamIndex
			);
		LocalStripAdd( 
			s_lathData1, 
			HCOMMON_ARRAY_SIZE( s_lathData1 ), 
			s_uvData1,
			index, 
			storeTriangleStrip, 
			typeSignature, 
			in_out_geometry,
			vertexStoreIndex,
			positionStreamIndex, 
			noramlStreamIndex,
			uvStreamIndex
			);
		LocalStripAdd( 
			s_lathData2, 
			HCOMMON_ARRAY_SIZE( s_lathData2 ), 
			s_uvData2,
			index, 
			storeTriangleStrip, 
			typeSignature, 
			in_out_geometry,
			vertexStoreIndex,
			positionStreamIndex, 
			noramlStreamIndex,
			uvStreamIndex
			);
		LocalStripAdd( 
			s_lathData3, 
			HCOMMON_ARRAY_SIZE( s_lathData3 ), 
			s_uvData3,
			index, 
			storeTriangleStrip, 
			typeSignature, 
			in_out_geometry,
			vertexStoreIndex,
			positionStreamIndex, 
			noramlStreamIndex,
			uvStreamIndex
			);
	}

	//cap the coloumn
	{
		TArraySint arrayIndex;	

		PGeometryVertex vertex( typeSignature, vertexStoreIndex );
		PGeometryUtility::DefaultVertex( typeSignature, vertex );
		vertex.VectorR3Set( noramlStreamIndex, HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, 1.0F ) );

		vertex.VectorR3Set( positionStreamIndex, HMatrixConstructor::HVectorR3Construct( -4.0F, -4.0F, 25.0F ) );
		vertex.VectorR2Set( uvStreamIndex, HMatrixConstructor::HVectorR2Construct( 0.3F, 0.3F ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature, in_out_geometry, vertex ) );

		vertex.VectorR3Set( positionStreamIndex, HMatrixConstructor::HVectorR3Construct(  4.0F, -4.0F, 25.0F ) );
		vertex.VectorR2Set( uvStreamIndex, HMatrixConstructor::HVectorR2Construct( 0.7F, 0.3F ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature, in_out_geometry, vertex ) );

		vertex.VectorR3Set( positionStreamIndex, HMatrixConstructor::HVectorR3Construct( -4.0F,  4.0F, 25.0F ) );
		vertex.VectorR2Set( uvStreamIndex, HMatrixConstructor::HVectorR2Construct( 0.3F, 0.7F ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature, in_out_geometry, vertex ) );

		vertex.VectorR3Set( positionStreamIndex, HMatrixConstructor::HVectorR3Construct(  4.0F,  4.0F, 25.0F ) );
		vertex.VectorR2Set( uvStreamIndex, HMatrixConstructor::HVectorR2Construct( 0.7F, 0.7F ) );
		arrayIndex.Insert( PGeometryUtility::VertexAdd( typeSignature, in_out_geometry, vertex ) );

		storeTriangleStrip.StripAdd( arrayIndex );
	}

	return;
}
/**/
static const Hubris::HBOOL TestbedSceneObject()
{
	HBOOL success = HTRUE;

	const HSINT componentFlag = 			
			//VScene::FlagComponentAnimationGet() | 
			VScene::FlagComponentCollisionGet() |
			VScene::FlagComponentDynamicGet() |
			VScene::FlagComponentForceGet() |
			VScene::FlagComponentGameGet() |
			VScene::FlagComponentLightEmitterGet() |
			VScene::FlagComponentLightReceiverGet() |
			//VScene::FlagComponentSoundEmitterGet() |
			//VScene::FlagComponentSoundReceiverGet() |
			VScene::FlagComponentVisualGet();


	{
		VScene scene( componentFlag );

		scene.InterfaceObjectLightEmitterGet().ColourAmbientSet( PColourRealRgb( 0.5F, 0.5F, 0.5F ) );
		scene.InterfaceObjectGameGet().PhaseCountSet( 2 );
		scene.InterfaceObjectForceGet().GravitationalAccellerationGet() = HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F, -9.8F );

		const HFileSystemPath assetPath( "data\\asset\\mesh_00.txt" );

		TArrayPairMaterialGeometryStage arrayMaterialStage;

		//{
		//	PGeometry geometry;
		//	LocalCreateGeometry( geometry );
		//}
		//column (visual and collision)
		{
			SMaterialStage materialStage;
			materialStage.FlagUseLightSet( HTRUE );
			materialStage.FlagZReadSet( HTRUE );
			materialStage.FlagZWriteSet( HTRUE );
			materialStage.TexturePathSet( "DATA\\ASSET\\base_00.tga" );
			materialStage.FlagUseTextureSet( HTRUE );
			//materialStage.FlagUseTextureSet( HFALSE );

			SMaterialGeometryStage geometryStage;
			geometryStage.NormalIndexSet( 1 );
			geometryStage.VertexIndexSet( 0 );
			geometryStage.TextureCoordIndexSet( 2 );
			geometryStage.TopologyIndexSet( 1 );

			SMaterial material;
			material.ArrayStageGeometryGet().Insert( TPairMaterialGeometryStage( materialStage, geometryStage ) );

			PGeometry geometry;
			LocalCreateGeometry( geometry );
			VComponentVisualInterfaceObject::VisualAssetSimpleCreate(
				assetPath,
				geometry,
				material,
				0
				);

			for( HSINT indexX = 0; indexX < 4; ++indexX )
			{
				for( HSINT indexY = 0; indexY < 4; ++indexY )
				{
					PSphereR3 sphere;
					sphere.RadiusSet( 20.0F );
					sphere.CenterSet( HMatrixConstructor::HVectorR3Construct( 20.0F * indexX, 20.0F * indexY, 0.0F ) );
					const HSINT itemId = scene.ItemAdd( 
						VScene::FlagStaticGet() | VScene::FlagComponentLightReceiverGet() | VScene::FlagComponentVisualGet() | VScene::FlagComponentCollisionGet(),
						sphere
						);

					scene.InterfaceObjectVisualGet().VisualSimpleCreate( 
						itemId,
						assetPath
						);

					scene.InterfaceObjectCollisionGet().CollisionBoundCreate( 
						itemId,
						PBoundsR3(
							HMatrixConstructor::HVectorR3Construct( -10.0F, -10.0F, -1.0F ),
							HMatrixConstructor::HVectorR3Construct(  10.0F,  10.0F,  0.0F )
							)
						);
				}
			}
		}
		//light
		{
			PSphereR3 sphere;
			sphere.RadiusSet( 100.0F );
			sphere.CenterSet( HMatrixConstructor::HVectorR3Construct( 30.0F, 30.0F, 30.0F ) );
			const HSINT itemId = scene.ItemAdd( 
				VScene::FlagStaticGet() | VScene::FlagComponentLightEmitterGet(),
				sphere
				);

			scene.InterfaceObjectLightEmitterGet().LightSet( 
				itemId,
				SLight::ModePointGet(),
				PColourRealRgb( 1.0F, 1.0F, 1.0F ),
				1.0F,
				100.0F
				);
		}
		//collision object hull
		{
			PSphereR3 sphere;
			sphere.RadiusSet( 8.0F );
			sphere.CenterSet( HMatrixConstructor::HVectorR3Construct( 30.0F, 30.0F, 0.0F ) );
			const HSINT itemId = scene.ItemAdd( 
				VScene::FlagComponentCollisionGet(),
				sphere
				);
			PConvexHull convexHull;
			convexHull.PlaneAdd( PPlaneR3( 2.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 1.0F, 0.0F, 1.0F ) ) ) );
			convexHull.PlaneAdd( PPlaneR3( 2.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct(-1.0F, 0.0F, 1.0F ) ) ) );
			convexHull.PlaneAdd( PPlaneR3( 5.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 0.0F, 1.0F, 0.0F ) ) ) );
			convexHull.PlaneAdd( PPlaneR3( 5.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 0.0F,-1.0F, 0.0F ) ) ) );
			convexHull.PlaneAdd( PPlaneR3( 1.0F, PUnitVectorR3( HMatrixConstructor::HVectorR3Construct( 0.0F, 0.0F,-1.0F ) ) ) );

			const HFileSystemPath assetPathHull( "data\\asset\\hull_00.txt" );
			VComponentCollisionInterfaceObject::CollisionConvexHullAssetCreate(
				assetPathHull,
				convexHull
				);

			scene.InterfaceObjectCollisionGet().CollisionConvexHullCreate( 
				itemId,
				assetPathHull
				);
		}

		////game object (particles)
		//{
		//	PSphereR3 sphere;
		//	sphere.RadiusSet( 20.0F );
		//	sphere.CenterSet( HMatrixConstructor::HVectorR3Construct( 30.0F, 30.0F, 20.0F ) );
		//	const HSINT itemId = scene.ItemAdd( 
		//		VScene::FlagComponentVisualGet() | VScene::FlagComponentGameGet(),
		//		sphere
		//		);

		//	SMaterialStage materialStage;
		//	materialStage.FlagAlphaBlendSet( HTRUE );
		//	materialStage.FlagUseLightSet( HFALSE );
		//	materialStage.FlagUseTextureSet( HTRUE );
		//	materialStage.FlagZWriteSet( HFALSE );
		//	materialStage.TexturePathSet( "DATA\\ASSET\\particle_00.tga" );
		//	TArrayParticleTypeData arrayTypeData;
		//	arrayTypeData.Insert( VComponentVisualAssetParticleTypeData(
		//		HMatrixConstructor::HVectorR2Construct( 0.0F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.0F, 0.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.0F )
		//		) );
		//	arrayTypeData.Insert( VComponentVisualAssetParticleTypeData(
		//		HMatrixConstructor::HVectorR2Construct( 0.0F, 1.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 1.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.0F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F )
		//		) );
		//	arrayTypeData.Insert( VComponentVisualAssetParticleTypeData(
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 1.0F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 1.0F, 0.0F )
		//		) );
		//	arrayTypeData.Insert( VComponentVisualAssetParticleTypeData(
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 1.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 1.0F, 1.0F ),
		//		HMatrixConstructor::HVectorR2Construct( 0.5F, 0.5F ),
		//		HMatrixConstructor::HVectorR2Construct( 1.0F, 0.5F )
		//		) );

		//	const HFileSystemPath assetParticlePath( "data\\asset\\part_00.txt" );
		//	VComponentVisualInterfaceObject::VisualAssetParticleCreate(
		//		assetParticlePath,
		//		materialStage,
		//		arrayTypeData,
		//		64,
		//		1
		//		);

		//	scene.InterfaceObjectVisualGet().VisualParticleCreate( 
		//		itemId,
		//		assetParticlePath
		//		);

		//	EMemento memento;
		//	EMementoCollect mementoCollect( memento );
		//	LocalParticleGameObjectMementoGenerate( mementoCollect );
		//	const HFileSystemPath assetEmittorPath( "data\\asset\\game_00.txt" );
		//	VComponentGameInterfaceObject::GameObjectAssetCreate(
		//		assetEmittorPath,
		//		Greed::GParticleEmittor::FactoryNameGet(),
		//		memento
		//		);

		//	scene.InterfaceObjectGameGet().ItemDataSet( 
		//		itemId,
		//		assetEmittorPath
		//		);

		//}
		//player character
		{
			PSphereR3 sphere;
			sphere.RadiusSet( 2.5F );
			sphere.CenterSet( HMatrixConstructor::HVectorR3Construct( 10.0F, 10.0F, 5.0F ) );
			HQuaternionREAL quaternion;
			const HSINT itemId = scene.ItemAdd( 
				VScene::FlagComponentDynamicGet() | VScene::FlagComponentGameGet() | VScene::FlagComponentVisualGet() ,
				sphere,
				&quaternion
				);

			VComponentDynamicInterfaceObject interfaceDynamic = scene.InterfaceObjectDynamicGet();
			interfaceDynamic.CreateDynamicSimple( 
				itemId, 
				VComponentDynamicComponentParam( 1.5F, 2.0F, 0.75F ),
				2.0F 
				);

			HFileSystemPath assetHierarchyPath( "DATA\\ASSET\\CHAR_00.TXT" );
			VComponentVisualInterfaceObject::VisualAssetHierarchyCreate(
				assetHierarchyPath,
				LocalArrayGeometryDataGet(),
				LocalArrayBoneDataGet(),
				0
				);
			VComponentVisualInterfaceObject interfaceVisual = scene.InterfaceObjectVisualGet();
			interfaceVisual.VisualHierarchyCreate(
				itemId,
				assetHierarchyPath
				);

			EMemento memento;
			EMementoCollect mementoCollect( memento );
			LocalPlayerCharacterGameObjectMementoGenerate( mementoCollect );
			HFileSystemPath assetGameObjectPath( "DATA\\ASSET\\GAME_01.TXT" );
			VComponentGameInterfaceObject interfaceGame = scene.InterfaceObjectGameGet();
			interfaceGame.GameObjectAssetCreate(
				assetGameObjectPath,
				Greed::GPlayerCharacter::FactoryNameGet(),
				memento
				);
			interfaceGame.ItemDataSet(
				itemId,
				assetGameObjectPath
				);

			scene.ItemNameSet( itemId, "player0" );

			const HSINT itemIdNamed = scene.ItemNameIndexGet( "player0" );
			itemIdNamed;
			HSINT foo = 0;
			foo += 1;
		}

		scene.ItemStructureRefreash();

		VSceneUtility::StaticLightsUpdate( scene );

		EMemento memento;
		EMementoCollect mementoCollect( memento );

		mementoCollect.MemberAdd( "vscene", scene );

		HFileSystem fileSystem;
		EMementoUtility::SaveText( fileSystem, "data\\scene.txt", memento );
	}

	{
		VScene scene;
		EMemento memento;
		HFileSystem fileSystem;
		EMementoUtility::Load( fileSystem, "data\\scene.txt", memento );
		EMementoAssign mementoAssign( memento );

		mementoAssign.MemberGet( "vscene", scene );

		success &= ( componentFlag == scene.ComponentFlagGet() );
	}


	VTESTBED_VALIDATE_STATUS( "VScene Object", success );

	return success;
}

//////////////////////////////////////////////////////
// external free functions

/**/
const Hubris::HBOOL TestbedScene()
{
	VComponentCollisionTraitFactoryRegister();
	VComponentVisualTraitFactoryRegister();
	VComponentSceneTraitFactoryRegister();

	VTESTBED_VALIDATE_START( "TestbedScene" );

	HBOOL success = HTRUE;

	success &= TestbedSceneObject();

	return success;
}

/**/
