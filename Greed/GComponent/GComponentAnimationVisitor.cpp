//file: Greed/GComponent/GComponentAnimationVisitor.cpp

#include "Greed/GreedPreCompileHeader.h"
#include "Greed/GComponent/GComponentAnimationVisitor.h"

/////////////////////////////////////////////////////////////////
// using
/**/
using namespace Hubris;
using namespace Greed;

///////////////////////////////////////////////////////
// creation
/**/
GComponentAnimationVisitor::GComponentAnimationVisitor()
{
	return;
}

/**/
GComponentAnimationVisitor::~GComponentAnimationVisitor()
{
	return;
}

///////////////////////////////////////////////////////
// interface
/**/
Hubris::HVOID GComponentAnimationVisitor::TranslationSet(
	const Hubris::HVectorR3& HCOMMON_UNUSED_VAR( in_value )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::RotationSet(
	const Hubris::HQuaternionREAL& HCOMMON_UNUSED_VAR( in_value )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::ValueSet(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_gameObjectVarId ),
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_animatedValue )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::ValueSet(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_gameObjectVarId ),
	const Hubris::HREAL HCOMMON_UNUSED_VAR( in_animatedValue )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::ValueSet(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_gameObjectVarId ),
	const Hubris::HVectorR2& HCOMMON_UNUSED_VAR( in_animatedValue )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::ValueSet(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_gameObjectVarId ),
	const Hubris::HVectorR3& HCOMMON_UNUSED_VAR( in_animatedValue )
	)
{
	return;
}

/**/
Hubris::HVOID GComponentAnimationVisitor::ValueSet(
	const Hubris::HSINT HCOMMON_UNUSED_VAR( in_gameObjectVarId ),
	const Hubris::HVectorR4& HCOMMON_UNUSED_VAR( in_animatedValue )
	)
{
	return;
}

/**/
