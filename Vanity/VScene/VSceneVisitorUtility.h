//file: Vanity/VScene/VSceneVisitorUtility.h
#ifndef _V_SCENE_VISITOR_UTILITY_H_
#define _V_SCENE_VISITOR_UTILITY_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	////////////////////////////////////////////////////////////
	// struct VSceneVisitorUtility
	/**/
	struct VSceneVisitorUtility
	{
		////////////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HContainerPair< Hubris::HSINT, Hubris::HSINT >TPairSinSint;
		typedef Hubris::HContainerPair< Hubris::HSINT, TPairSinSint >TPairSinPairSintSint;
		typedef Hubris::HContainerArray< TPairSinPairSintSint >TArrayPairSinSint;
		typedef Hubris::HContainerTree< Hubris::HREAL, TArrayPairSinSint >TTreeRealArrayPairSintSint;

		////////////////////////////////////////////////////////////
		// disabled
	private:
		~VSceneVisitorUtility();

		////////////////////////////////////////////////////////////
		// static public methods
	public:
		static const Hubris::HREAL CalculateSort( 
			const Pride::PSphereR3& in_sphere,
			const Hubris::HVectorR3& in_vector
			);

		static Hubris::HVOID InsertSortNode(
			TTreeRealArrayPairSintSint& in_out_tree,
			const Hubris::HREAL in_sortValue,
			const Hubris::HSINT in_nodeIndex,
			const Hubris::HSINT in_flag
			);

		static Hubris::HVOID InsertSortSphere(
			TTreeRealArrayPairSintSint& in_out_tree,
			const Hubris::HREAL in_sortValue,
			const Hubris::HSINT in_sphereIndex,
			const Hubris::HSINT in_flag
			);

		//return true is either indexNode or indexSphere are valid
		static const Hubris::HBOOL SortPop(
			TTreeRealArrayPairSintSint& in_out_tree,
			Hubris::HSINT& out_indexNode,
			Hubris::HSINT& out_indexSphere,
			Hubris::HSINT& out_flag
			);

		//all bits of subject flag must be present in component flag
		static const Hubris::HBOOL ComponentFlagTest(
			const Hubris::HSINT in_componentFlag,
			const Hubris::HSINT in_subjectFlag
			);

	};
	
};

#endif // _V_SCENE_VISITOR_UTILITY_H_