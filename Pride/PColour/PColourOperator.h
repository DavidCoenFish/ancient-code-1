//file: Pride/PColour/PColourOperator.h
#ifndef _P_COLOUR_OPERATOR_H_
#define _P_COLOUR_OPERATOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	typedef PColour< Hubris::HU8, 1 >PColourMono;
	typedef PColour< Hubris::HU8, 3 >PColourRgb;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;

	typedef PColour< Hubris::HREAL, 1 >PColourRealMono;
	typedef PColour< Hubris::HREAL, 3 >PColourRealRgb;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	/////////////////////////////////////////////////////////////////
	// global operators
	/**/
	const Hubris::HBOOL operator==( const PColourMono& in_lhs, const PColourMono& in_rhs );
	const Hubris::HBOOL operator==( const PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const Hubris::HBOOL operator==( const PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const Hubris::HBOOL operator==( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const Hubris::HBOOL operator==( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const Hubris::HBOOL operator==( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const Hubris::HBOOL operator!=( const PColourMono& in_lhs, const PColourMono& in_rhs );
	const Hubris::HBOOL operator!=( const PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const Hubris::HBOOL operator!=( const PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const Hubris::HBOOL operator!=( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const Hubris::HBOOL operator!=( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const Hubris::HBOOL operator!=( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const PColourMono operator+( const PColourMono& in_lhs, const PColourMono& in_rhs );
	const PColourRgb operator+( const PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const PColourRgba operator+( const PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const PColourRealMono operator+( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const PColourRealRgb operator+( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const PColourRealRgba operator+( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const PColourMono operator+( const PColourMono& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgb operator+( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgba operator+( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRealMono operator+( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgb operator+( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgba operator+( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs );

	const PColourMono& operator+=( PColourMono& in_lhs, const PColourMono& in_rhs );
	const PColourRgb& operator+=( PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const PColourRgba& operator+=( PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const PColourRealMono& operator+=( PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const PColourRealRgb& operator+=( PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const PColourRealRgba& operator+=( PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const PColourMono operator+=( const PColourMono& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgb operator+=( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgba operator+=( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRealMono operator+=( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgb operator+=( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgba operator+=( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs );

	const PColourMono operator*( const PColourMono& in_lhs, const PColourMono& in_rhs );
	const PColourRgb operator*( const PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const PColourRgba operator*( const PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const PColourRealMono operator*( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const PColourRealRgb operator*( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const PColourRealRgba operator*( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const PColourMono& operator*=( PColourMono& in_lhs, const PColourMono& in_rhs );
	const PColourRgb& operator*=( PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const PColourRgba& operator*=( PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const PColourRealMono& operator*=( PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const PColourRealRgb& operator*=( PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const PColourRealRgba& operator*=( PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

	const PColourMono operator*( const PColourMono& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgb operator*( const PColourRgb& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgba operator*( const PColourRgba& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRealMono operator*( const PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgb operator*( const PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgba operator*( const PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs );

	const PColourMono& operator*=( PColourMono& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgb& operator*=( PColourRgb& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRgba& operator*=( PColourRgba& in_lhs, const Hubris::HU8& in_rhs );
	const PColourRealMono& operator*=( PColourRealMono& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgb& operator*=( PColourRealRgb& in_lhs, const Hubris::HREAL& in_rhs );
	const PColourRealRgba& operator*=( PColourRealRgba& in_lhs, const Hubris::HREAL& in_rhs );

	const Hubris::HBOOL operator<( const PColourMono& in_lhs, const PColourMono& in_rhs );
	const Hubris::HBOOL operator<( const PColourRgb& in_lhs, const PColourRgb& in_rhs );
	const Hubris::HBOOL operator<( const PColourRgba& in_lhs, const PColourRgba& in_rhs );
	const Hubris::HBOOL operator<( const PColourRealMono& in_lhs, const PColourRealMono& in_rhs );
	const Hubris::HBOOL operator<( const PColourRealRgb& in_lhs, const PColourRealRgb& in_rhs );
	const Hubris::HBOOL operator<( const PColourRealRgba& in_lhs, const PColourRealRgba& in_rhs );

};


#endif // _P_COLOUR_OPERATOR_H_