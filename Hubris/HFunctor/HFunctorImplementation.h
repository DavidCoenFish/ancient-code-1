//file: Hubris/HFunctor/HFunctorImplementation.h
#ifndef _H_FUNCTOR_IMPLEMENTATION_H_
#define _H_FUNCTOR_IMPLEMENTATION_H_

/**/

#include "Hubris/HFunctor/HFunctorBase.h"
#include "Hubris/HType/HTypeList.h"

/**/
namespace Hubris
{
	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST> class HFunctorImplementation;
	
	/**/	
	template <typename IN_RETURN_TYPE>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_0() > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
	public:
		virtual IN_RETURN_TYPE operator()()const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_1(IN_CLASS_A) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_2(IN_CLASS_A, IN_CLASS_B) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_3(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_4(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_5(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_6(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F, typename IN_CLASS_G>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_7(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F, IN_CLASS_G) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
		typedef IN_CLASS_G TParamG;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF, IN_CLASS_G in_paramG) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F, typename IN_CLASS_G, typename IN_CLASS_H>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_8(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F, IN_CLASS_G, IN_CLASS_H) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
		typedef IN_CLASS_G TParamG;
		typedef IN_CLASS_H TParamH;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF, IN_CLASS_G in_paramG, IN_CLASS_H in_paramH) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F, typename IN_CLASS_G, typename IN_CLASS_H, typename IN_CLASS_I>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_9(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F, IN_CLASS_G, IN_CLASS_H, IN_CLASS_I) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
		typedef IN_CLASS_G TParamG;
		typedef IN_CLASS_H TParamH;
		typedef IN_CLASS_I TParamI;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF, IN_CLASS_G in_paramG, IN_CLASS_H in_paramH, IN_CLASS_I in_paramI) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F, typename IN_CLASS_G, typename IN_CLASS_H, typename IN_CLASS_I, typename IN_CLASS_J>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_10(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F, IN_CLASS_G, IN_CLASS_H, IN_CLASS_I, IN_CLASS_J) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
		typedef IN_CLASS_G TParamG;
		typedef IN_CLASS_H TParamH;
		typedef IN_CLASS_I TParamI;
		typedef IN_CLASS_J TParamJ;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF, IN_CLASS_G in_paramG, IN_CLASS_H in_paramH, IN_CLASS_I in_paramI, IN_CLASS_J in_paramJ) const = 0;
	};

	/**/
	template <typename IN_RETURN_TYPE, typename IN_CLASS_A, typename IN_CLASS_B, typename IN_CLASS_C, typename IN_CLASS_D, typename IN_CLASS_E, typename IN_CLASS_F, typename IN_CLASS_G, typename IN_CLASS_H, typename IN_CLASS_I, typename IN_CLASS_J, typename IN_CLASS_K>
	class HFunctorImplementation<IN_RETURN_TYPE, HTYPE_LIST_11(IN_CLASS_A, IN_CLASS_B, IN_CLASS_C, IN_CLASS_D, IN_CLASS_E, IN_CLASS_F, IN_CLASS_G, IN_CLASS_H, IN_CLASS_I, IN_CLASS_J, IN_CLASS_K) > : public HFunctorBase<IN_RETURN_TYPE>
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;		
		typedef IN_CLASS_A TParamA;
		typedef IN_CLASS_B TParamB;
		typedef IN_CLASS_C TParamC;
		typedef IN_CLASS_D TParamD;
		typedef IN_CLASS_E TParamE;
		typedef IN_CLASS_F TParamF;
		typedef IN_CLASS_G TParamG;
		typedef IN_CLASS_H TParamH;
		typedef IN_CLASS_I TParamI;
		typedef IN_CLASS_J TParamJ;
		typedef IN_CLASS_K TParamK;
	public:
		virtual IN_RETURN_TYPE operator()(IN_CLASS_A in_paramA, IN_CLASS_B in_paramB, IN_CLASS_C in_paramC, IN_CLASS_D in_paramD, IN_CLASS_E in_paramE, IN_CLASS_F in_paramF, IN_CLASS_G in_paramG, IN_CLASS_H in_paramH, IN_CLASS_I in_paramI, IN_CLASS_J in_paramJ, IN_CLASS_K in_paramK) const = 0;
	};

};

#endif // _H_FUNCTOR_IMPLEMENTATION_H_