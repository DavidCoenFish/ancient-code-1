//file: Pride/PLight/PLightOperator.h
#ifndef _P_LIGHT_OPERATOR_H_
#define _P_LIGHT_OPERATOR_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PLight;
	typedef PLight< Hubris::HU8, 1 >PLightMono;
	typedef PLight< Hubris::HU8, 3 >PLightRgb;
	typedef PLight< Hubris::HU8, 4 >PLightRgba;
	typedef PLight< Hubris::HREAL, 1 >PLightRealMono;
	typedef PLight< Hubris::HREAL, 3 >PLightRealRgb;
	typedef PLight< Hubris::HREAL, 4 >PLightRealRgba;


	/////////////////////////////////////////////////////////////////
	// global operators
	/**/
	const Hubris::HBOOL operator<( const PLightMono& in_lhs, const PLightMono& in_rhs );
	const Hubris::HBOOL operator<( const PLightRgb& in_lhs, const PLightRgb& in_rhs );
	const Hubris::HBOOL operator<( const PLightRgba& in_lhs, const PLightRgba& in_rhs );
	const Hubris::HBOOL operator<( const PLightRealMono& in_lhs, const PLightRealMono& in_rhs );
	const Hubris::HBOOL operator<( const PLightRealRgb& in_lhs, const PLightRealRgb& in_rhs );
	const Hubris::HBOOL operator<( const PLightRealRgba& in_lhs, const PLightRealRgba& in_rhs );

	/**/
	
};

#endif // _P_LIGHT_OPERATOR_H_