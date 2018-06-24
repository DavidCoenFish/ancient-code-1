//file: Pride/PAnimation/PAnimationUtility.cpp

#include "Pride/PridePreCompileHeader.h"
#include "Pride/PAnimation/PAnimationUtility.h"

#include "Pride/PAnimation/PAnimation.h"

#include< Hubris/HContainer/HContainer_Export.h >

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Pride;

///////////////////////////////////////////////////////
// public static methods
/**/	
HVOID PAnimationUtility::CollectKeyframe( TArrayReal& out_timeArray, const PAnimation& in_animation )
{
	out_timeArray.Clear();
	TArrayString nameList;

	//collect all the keys (assuming sorted)
	TArrayReal totalKeys;
	in_animation.NameArrayGet( nameList );
	HCOMMON_FOR_EACH_CONST( name, nameList, TArrayString )
	{
		TArrayReal keys;
		in_animation.TimeKeyGet( name, keys );

		TArrayReal oldKeys( totalKeys );
		HContainerAlgorithm::Merge< TArrayReal >( oldKeys, keys, totalKeys );
	}

	//add unique keys (assuming sorted)
	HCOMMON_FOR_EACH_CONST( key, totalKeys, TArrayReal )
	{
		if( ( 0 == out_timeArray.SizeGet() ) ||
			( key != Hubris::HContainerUtility::Back( out_timeArray ) ) )
		{
			Hubris::HContainerUtility::PushBack( out_timeArray, key );
		}
	}

	return;
}

/**/
HVOID PAnimationUtility::RemapData( PAnimation& in_out_animation, const TArrayPairStringString& in_arrayOldNewNames )
{
	TArrayString arrayAnimationName;
	in_out_animation.NameArrayGet( arrayAnimationName );

	HCOMMON_FOR_EACH_CONST( animationName, arrayAnimationName, TArrayString )
	{
		HBOOL found = HFALSE;
		HCOMMON_FOR_EACH_CONST( pairOldNew, in_arrayOldNewNames, TArrayPairStringString )
		{
			if( animationName == pairOldNew.m_first )
			{
				found = HTRUE;
				in_out_animation.DataRename( animationName, pairOldNew.m_second );
			}
		}

		if( HFALSE == found )
		{
			in_out_animation.DataRemove( animationName );
		}
	}

	return;
}

/**/
