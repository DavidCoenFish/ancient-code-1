//file: Hubris/HCommon/HCommonDefine.h
#ifndef _H_COMMON_DEFINE_H_
#define _H_COMMON_DEFINE_H_

//define HNULL ifnot present
#ifndef HNULL
#define HNULL 0
#endif

//use native true and false? or defines ->defines of native, so can change
#ifndef HFALSE
#define HFALSE false
#endif

#ifndef HTRUE
#define HTRUE true
#endif

//invalid index
#define HCOMMON_INVALID_INDEX -1
//translate input token into a string
#define HCOMMON_TOKEN( INPUT ) #INPUT
#define HCOMMON_TOKEN_TOKEN( INPUT_ONE, INPUT_TWO ) #INPUT_ONE#INPUT_TWO
#define HCOMMON_TOKEN_TOKEN_TOKEN( INPUT_ONE, INPUT_TWO, INPUT_THREE ) (#INPUT_ONE#INPUT_TWO#INPUT_THREE)

#define HCOMMON_UNUSED_VAR( VAR )

//common way of changing index to flag, no negative index
#define HCOMMON_INDEX_TO_FLAG( INDEX )							( 1 << ( INDEX ) )

#define HCOMMON_ARRAY_SIZE( ARRAY ) ( sizeof( ARRAY ) / sizeof( ARRAY[ 0 ] ) )

/////////////////////////////////////////////////////////////////////
// system
/**/
/*
	using vs 7 at home, version 8 at work
		try not to use these system persific calls -coen
*/
#if _MFC_VER < 0x0800
	#define H_FOPEN_READ( PFILE, PATH ) PFILE = fopen( PATH, "rb" ) 
	#define H_FOPEN_WRITE( PFILE, PATH ) PFILE = fopen( PATH, "wb" ) 
	#define H_SPRINT sprintf
	#define H_STRCAT strcat
	#define H_SCAN scanf
	#define H_LOCAL_TIME( IN_TIME_STRUCTURE, IN_VALUE ) IN_TIME_STRUCTURE = ( *( localtime( &IN_VALUE) ) )
#else
	#define H_FOPEN_READ( PFILE, PATH ) fopen_s( &PFILE, PATH, "rb");
	#define H_FOPEN_WRITE( PFILE, PATH ) fopen_s( &PFILE, PATH, "wb");
	#define H_STRCAT strcat_s
	#define H_SPRINT sprintf_s
	#define H_SCAN scanf_s
	#define H_LOCAL_TIME( IN_TIME_STRUCTURE, IN_VALUE ) localtime_s( &IN_TIME_STRUCTURE, &IN_VALUE )
#endif

/////////////////////////////////////////////////////////////////////
// log
/**/
//add message to log file
#define HCOMMON_LOG( HMESSAGE ) printf( HMESSAGE )
//add message= to warning and log
#define HCOMMON_WARNING( HMESSAGE ) HCOMMON_LOG( HMESSAGE )

/////////////////////////////////////////////////////////////////////
// memory
/**/
//bottleneck all memory calls, TODO: write own memory base class
#define HCOMMON_NEW( DESTINATION, TYPE )							{ DESTINATION = new TYPE(); }												//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM( DESTINATION, TYPE, PARAM )				{ DESTINATION = new TYPE( PARAM ); }											//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_2( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_3( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_4( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_5( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_6( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_7( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX, PARAM_SEVEN )	{ DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX, PARAM_SEVEN ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_NEW_PARAM_8( DESTINATION, TYPE, PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX, PARAM_SEVEN, PARAM_EIGHT ) { DESTINATION = new TYPE( PARAM_ONE, PARAM_TWO, PARAM_THREE, PARAM_FOUR, PARAM_FIVE, PARAM_SIX, PARAM_SEVEN, PARAM_EIGHT ); }				//DESTINATION = static_cast<TYPE *>( TYPE::HNew( sizeof( TYPE ) ) );
#define HCOMMON_DELETE( INPUT, TYPE )								{ delete INPUT; INPUT = HNULL; }				//TYPE::HDelete( INPUT );
#define HCOMMON_DELETE_THIS( INPUT, TYPE )							{ delete INPUT; }				//TYPE::HDelete( INPUT );

#define HCOMMON_NEW_ARRAY( DESTINATION, TYPE, COUNT )				{ DESTINATION = new TYPE[COUNT]; }			//DESTINATION = static_cast<TYPE *>( TYPE::HNewArray( sizeof( TYPE ), COUNT ) );
#define HCOMMON_DELETE_ARRAY( DESTINATION, TYPE )					{ delete [] DESTINATION; }					//TYPE::HDeleteArray( DESTINATION )

/**/

#endif// _H_COMMON_DEFINE_H_
