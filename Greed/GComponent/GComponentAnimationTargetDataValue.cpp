//file: Greed/GComponent/GComponentAnimationTargetDataValue.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GComponent/GComponentAnimationTargetDataValue.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;

////////////////////////////////////////////////////
// template definitions
/**/
template class Greed::GComponentAnimationTargetDataValue< HSINT >;
template class Greed::GComponentAnimationTargetDataValue< HREAL >;
template class Greed::GComponentAnimationTargetDataValue< HVectorR2 >;
template class Greed::GComponentAnimationTargetDataValue< HVectorR3 >;
template class Greed::GComponentAnimationTargetDataValue< HVectorR4 >;

///////////////////////////////////////////////////////
// creation
/**/
template< typename IN_TYPE >
GComponentAnimationTargetDataValue< IN_TYPE >::GComponentAnimationTargetDataValue(
	const IN_TYPE& in_value
	)
: m_value( in_value )
{
	return;
}

/**/
template< typename IN_TYPE >
GComponentAnimationTargetDataValue< IN_TYPE >::~GComponentAnimationTargetDataValue()
{
	return;
}

/**/
