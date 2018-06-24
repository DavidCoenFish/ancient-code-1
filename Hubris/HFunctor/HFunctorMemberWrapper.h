//file: Hubris/HFunctor/HFunctorMemberWrapper.h
#ifndef _H_FUNCTOR_MEMBER_WRAPPER_H_
#define _H_FUNCTOR_MEMBER_WRAPPER_H_

/**/
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HFunctor/HFunctorImplementation.h"

/**/
namespace Hubris
{
	/* Member function functor */
	template< class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION >
	class HFunctorMemberWrapper : public IN_FUNCTOR_IMPLEMENTATION
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
		HFunctorMemberWrapper(IN_CLASS & in_object, IN_MEMBER_FUNCTION in_function);

		//! Clone
		HFunctorBase<TReturnType> * Clone()const;

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
		IN_MEMBER_FUNCTION m_function;
		IN_CLASS * m_object;
	};

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::HFunctorMemberWrapper(IN_CLASS & in_object, IN_MEMBER_FUNCTION in_function) :
		m_function(in_function),
		m_object(&in_object)
	{
		return;
	}

	/* Clone */
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HFunctorBase<typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType> * HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::Clone() const
	{
		HFunctorMemberWrapper * pointer = NULL;
		if (true == ValidTest())
		{
			HCOMMON_NEW_PARAM_2(pointer, (HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>), *m_object, m_function)
		}

		return pointer;
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	HBOOL HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::ValidTest()const
	{
		return ((NULL != m_function) && (NULL != m_object));
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() ()const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))();
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ);
		}

		return TReturnType();
	}

	/**/
	template <class IN_CLASS, typename IN_MEMBER_FUNCTION, class IN_FUNCTOR_IMPLEMENTATION>
	typename HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::TReturnType HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, IN_FUNCTOR_IMPLEMENTATION>::operator() (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ, TParamK in_paramK) const
	{
		if (true == ValidTest())
		{
			return ((m_object)->*(m_function))(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ, in_paramK);
		}

		return TReturnType();
	}

	/**/

};

#endif // _H_FUNCTOR_H_