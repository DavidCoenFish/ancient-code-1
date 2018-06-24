//file: Hubris/HFunctor/HFunctorBase.h
#ifndef _H_FUNCTOR_BASE_H_
#define _H_FUNCTOR_BASE_H_

/**/
//#include "Hubris/HType/HTypeNone.h"
class HTypeNone;

/**/
namespace Hubris
{
	/**/
	template <typename IN_RETURN_TYPE> class HFunctorBase
	{
	public:
		typedef IN_RETURN_TYPE TReturnType;
		typedef HTypeNone TParamA;
		typedef HTypeNone TParamB;
		typedef HTypeNone TParamC;
		typedef HTypeNone TParamD;
		typedef HTypeNone TParamE;
		typedef HTypeNone TParamF;
		typedef HTypeNone TParamG;
		typedef HTypeNone TParamH;
		typedef HTypeNone TParamI;
		typedef HTypeNone TParamJ;
		typedef HTypeNone TParamK;

	public:
		virtual ~HFunctorBase();
		virtual HFunctorBase * Clone()const = 0;

	};

	/**/
	template <typename IN_RETURN_TYPE> 
	HFunctorBase<IN_RETURN_TYPE>::~HFunctorBase()
	{
		return;
	}

	/**/
};

#endif // _H_FUNCTOR_H_