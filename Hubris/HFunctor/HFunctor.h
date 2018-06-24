//file: Hubris/HFunctor/HFunctor.h
#ifndef _H_FUNCTOR_H_
#define _H_FUNCTOR_H_

/**/

#include "Hubris/HFunctor/HFunctorImplementation.h"
#include "Hubris/HFunctor/HFunctorMemberWrapper.h"
#include "Hubris/HFunctor/HFunctorWrapper.h"

/* from redtribe. tom - ryan */
namespace Hubris
{
	/* Functor. Handle of the function implementation */
	template <typename IN_RETURN_TYPE = HVOID, class IN_TYPE_LIST = HTYPE_LIST_0() >
	class HFunctor
	{
		typedef HFunctorImplementation<IN_RETURN_TYPE, IN_TYPE_LIST> TFunctorImplementation;
		typedef typename TFunctorImplementation::TParamA TParamA;
		typedef typename TFunctorImplementation::TParamB TParamB;
		typedef typename TFunctorImplementation::TParamC TParamC;
		typedef typename TFunctorImplementation::TParamD TParamD;
		typedef typename TFunctorImplementation::TParamE TParamE;
		typedef typename TFunctorImplementation::TParamF TParamF;
		typedef typename TFunctorImplementation::TParamG TParamG;
		typedef typename TFunctorImplementation::TParamH TParamH;
		typedef typename TFunctorImplementation::TParamI TParamI;
		typedef typename TFunctorImplementation::TParamJ TParamJ;
		typedef typename TFunctorImplementation::TParamK TParamK;
		// Repeat for N parameters

	public:
		typedef IN_RETURN_TYPE TReturnType;

	public:
		HFunctor(const HFunctor & in_src);
		HFunctor();
		~HFunctor();

		//! function constructor
		template <typename IN_FUNCTION>
		HFunctor(IN_FUNCTION in_function)
		{
			HCOMMON_NEW_PARAM(m_functorImplementation, (HFunctorWrapper<IN_FUNCTION, TFunctorImplementation>), in_function);
			return;
		}

		//! member function constructor
		template <class IN_CLASS, typename IN_MEMBER_FUNCTION> 
		HFunctor(IN_CLASS & in_class, IN_MEMBER_FUNCTION in_function)
		{
			HCOMMON_NEW_PARAM_2(m_functorImplementation, (HFunctorMemberWrapper<IN_CLASS, IN_MEMBER_FUNCTION, TFunctorImplementation>), in_class, in_function);
			return;
		}

		//! Operator const HVOID * for NULL testing
		operator const HVOID * ()const;

		const HBOOL ValidTest()const;
		HVOID Release();

		// Overloaded operator ()
		IN_RETURN_TYPE operator ()() const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ) const;
		IN_RETURN_TYPE operator ()(TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ, TParamK in_paramK) const;

		/**/
		const HFunctor& operator =(const HFunctor & in_src);
		const HBOOL operator ==(const HFunctor & in_rhs) const;
		const HBOOL operator !=(const HFunctor & in_rhs) const;

	private:
		TFunctorImplementation * m_functorImplementation;

	};

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::HFunctor(const HFunctor & in_src) :
		m_functorImplementation(NULL)
	{
		(*this) = in_src;
		return;
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::HFunctor() :
		m_functorImplementation(NULL)
	{
		return;
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::~HFunctor()
	{
		Release();
		return;
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	const HBOOL HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::ValidTest()const
	{
		return (NULL != m_functorImplementation);
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	HVOID HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::Release()
	{
		HCOMMON_DELETE(m_functorImplementation, TFunctorImplementation);
		return;
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () ()const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)();
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA)const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB)const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC)const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD)const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE)const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	IN_RETURN_TYPE HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator () (TParamA in_paramA, TParamB in_paramB, TParamC in_paramC, TParamD in_paramD, TParamE in_paramE, TParamF in_paramF, TParamG in_paramG, TParamH in_paramH, TParamI in_paramI, TParamJ in_paramJ, TParamK in_paramK) const
	{
		if (true == ValidTest())
		{
			return (*m_functorImplementation)(in_paramA, in_paramB, in_paramC, in_paramD, in_paramE, in_paramF, in_paramG, in_paramH, in_paramI, in_paramJ, in_paramK);
		}

		return IN_RETURN_TYPE();
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	const HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST> & HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator =(const HFunctor & in_src)
	{
		if ((this != &in_src) && ((*this) != in_src))
		{
			Release();
			if (NULL != in_src.m_functorImplementation)
			{
				m_functorImplementation = (TFunctorImplementation *)in_src.m_functorImplementation->Clone();
			}
		}

		return (*this);
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	const HBOOL HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator ==(const HFunctor & in_rhs) const
	{
		return (m_functorImplementation == in_rhs.m_functorImplementation);
	}

	/**/
	template <typename IN_RETURN_TYPE, class IN_TYPE_LIST>
	const HBOOL HFunctor<IN_RETURN_TYPE, IN_TYPE_LIST>::operator !=(const HFunctor & in_rhs) const
	{
		return !(operator ==(in_rhs));
	}

	/**/

};

#endif // _H_FUNCTOR_H_