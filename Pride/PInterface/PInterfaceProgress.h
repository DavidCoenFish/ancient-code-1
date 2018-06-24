//file: Pride/PInterface/PInterfaceProgress.h
#ifndef _P_INTERFACE_PROGRESS_H_
#define _P_INTERFACE_PROGRESS_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Hubris
{
	class HString;

};

namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	class PInterfaceAnimationVariant;

	///////////////////////////////////////////////////////
	// class
	/*
		provide interface for receiving progress information
	*/
	class PInterfaceProgress
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		virtual ~PInterfaceProgress();

		///////////////////////////////////////////////////////
		// interface
	public:
		virtual Hubris::HVOID ProgressSet( 
			const Hubris::HString& in_message,
			const Hubris::HREAL in_percentageProgress
			)=0;
		// in_percentageProgress is [ 0 ... 1.0 ]
		virtual Hubris::HVOID ProgressAmountSet( const Hubris::HREAL in_percentageProgress )=0;
		virtual Hubris::HVOID ProgressTextSet( const Hubris::HString& in_message )=0;
		virtual const Hubris::HBOOL CancelGet()const=0;

	};

	/**/
};

#endif // _P_INTERFACE_PROGRESS_H_