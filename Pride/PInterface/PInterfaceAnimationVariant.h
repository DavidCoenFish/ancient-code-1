//file: Pride/PInterface/PInterfaceAnimationVariant.h
#ifndef _P_INTERFACE_ANIMATION_VARIANT_H_
#define _P_INTERFACE_ANIMATION_VARIANT_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HType/HType_Export.h >
#include< Hubris/HVariant/HVariant_Export.h >

namespace Hubris
{
	template< typename IN_TYPE >class HQuaternion;
	typedef HQuaternion< HREAL >HQuaternionREAL;

	template< typename IN_TYPE, HSINT IN_WIDTH, HSINT IN_HEIGHT > class HMatrix;
	typedef HMatrix< HREAL, 2, 1 >HVectorR2;
	typedef HMatrix< HREAL, 3, 1 >HVectorR3;
	typedef HMatrix< HREAL, 4, 1 >HVectorR4;

	template< typename IN_TYPE >class HContainerArray;

	class HString;

};

namespace Pride
{
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;
	typedef Hubris::HContainerArray< Hubris::HREAL >TInterfaceAnimationVariantArrayReal;

	/**/
	typedef HTYPE_LIST_10( 
		Hubris::HSINT,
		Hubris::HREAL, 
		Hubris::HString, 
		Hubris::HVectorR2,
		Hubris::HVectorR3,
		Hubris::HVectorR4,
		Hubris::HQuaternionREAL,
		PColourRgba,
		PColourRealRgba,
		//( Hubris::HContainerArray< Hubris::HREAL > )
		TInterfaceAnimationVariantArrayReal
		)PInterfaceAnimationVariantTypeList;
	
	/**/
	HVARIANT_DEFINITION( PInterfaceAnimationVariant, PInterfaceAnimationVariantTypeList );

	/**/
	
};

#endif // _P_INTERFACE_ANIMATION_VARIANT_H_