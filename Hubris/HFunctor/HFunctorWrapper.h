//file: Hubris/HFunctor/HFunctorWrapper.h
#ifndef _H_FUNCTOR_WRAPPER_H_
#define _H_FUNCTOR_WRAPPER_H_

/**/
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HFunctor/HFunctorImplementation.h"

/**/
namespace Hubris
{
	/* function functor */
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	class HFunctorWrapper : public IN_FUNCTOR_IMPLEMENTATION
	{
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TReturnType TReturnType;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamA TParamA;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamB TParamB;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamC TParamC;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamD TParamD;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamE TParamE;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamF TParamF;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamG TParamG;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamH TParamH;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamI TParamI;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamJ TParamJ;
		typedef typename IN_FUNCTOR_IMPLEMENTATION::TParamK TParamK;

	public:
		//! Constructor
		HFunctorWrapper(IN_FUNCTION in_function);

		//! Clone
		HFunctorBase<TReturnType>* Clone()const;

		// Overloaded call functions. Overrides the virtual one specified by IN_FUNCTOR_IMPLEMENTATION
		TReturnType operator ()() const;
		TReturnType operator ()(TParamA in_paramA) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ) const;
		TReturnType operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ, TParamK in_paramK) const;

	private:
		HBOOL ValidTest() const;

	private:
		IN_FUNCTION m_function;
	};

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::HFunctorWrapper(IN_FUNCTION in_function) :
		m_function(in_function)
	{
		return;
	}

	/* Clone */
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HFunctorBase<typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType> * HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::Clone()const
	{
		HFunctorWrapper * pointer = NULL;
		if (true == ValidTest())
		{
			HCOMMON_NEW_PARAM(pointer, (HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>), m_function);
		}

		return pointer;
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HBOOL HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::ValidTest()const
	{
		return (NULL != m_function);
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() ()const
	{
		if (true == ValidTest())
		{
			return m_function();
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ);
		}

		return TReturnType();
	}

	/**/
	template <typename IN_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorWrapper<IN_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ, TParamK in_paramK) const
	{
		if (true == ValidTest())
		{
			return m_function(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ, in_paramK);
		}

		return TReturnType();
	}

	/**/

};

#endif // _H_FUNCTOR_WRAPPER_H_