//file: Hubris/HVariant/HVariant.h
#ifndef _H_VARIANT_H_
#define _H_VARIANT_H_


#include "Hubris/HVariant/HVariantImplementation.h"

/////////////////////////////////////////////////
// definition
/*
	created a macro passthrough wrapper class for variant as type name was going over 4000 length limit
	also creates variant as a class, so it can be predefined easier than templated variant class

	ie, attempting to avoid usage of the following
#pragma warning (disable:4503) // Disable warning: "decorated name length exceeded, name was truncated" 
	not an inssue in release application (ok, it is going to mess with the debugger) -coen

	side effect of making it a class (rather than a template) 
	is that HTraitEmpty, HTraitName, Memento trait functions need to be specialised for it
*/
#define HVARIANT_DEFINITION( IN_CLASS_NAME, IN_TYPE_LIST )						\
class IN_CLASS_NAME : public Hubris::HVariantImplementation< IN_TYPE_LIST >		\
{																				\
public:																			\
	typedef IN_TYPE_LIST TTypeList;												\
	typedef Hubris::HVariantImplementation< IN_TYPE_LIST >TVariantImplementation;\
public:																			\
	template< typename IN_TYPE >IN_CLASS_NAME( const IN_TYPE& in_src )			\
	{ ValueSet( in_src ); return; }												\
	IN_CLASS_NAME( const IN_CLASS_NAME& in_src )								\
	{ (*this) = in_src; return; }												\
	IN_CLASS_NAME( const TVariantImplementation& in_src )						\
	{ TVariantImplementation::operator=( in_src ); return; }					\
	IN_CLASS_NAME()																\
	{ return; }																	\
	~IN_CLASS_NAME()															\
	{ return; }																	\
public:																			\
	const IN_CLASS_NAME& operator=( const IN_CLASS_NAME& in_rhs )				\
	{ TVariantImplementation::operator=( in_rhs ); return( *this ); }			\
	Hubris::HBOOL operator==( const IN_CLASS_NAME& in_rhs )const				\
	{ return( TVariantImplementation::operator==( in_rhs ) ); }					\
	Hubris::HBOOL operator!=( const IN_CLASS_NAME& in_rhs )const				\
	{ return( !( operator==( in_rhs ) ) ); }									\
};

/////////////////////////////////////////////////
// example usage
/*
//yields a class called CTestbedVariant which acts as a variant
HVARIANT_DEFINITION( CTestbedVariant, HTYPE_LIST_4( HU8, HU16, HU32, HR64 ) );
*/

//and to satisfy HTraitName trait would look like
/*
template<>									
struct HTraitName< CTestbedVariant >					
{											
	static HString NameGet();	
};											
HString HTraitName< CTestbedVariant >::NameGet(){ return HTraitName< CTestbedVariant::TVariantImplementation >::NameGet(); };
*/


#endif // _H_VARIANT_H_