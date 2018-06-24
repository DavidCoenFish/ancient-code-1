//file: Hubris/HVariant/HVariantDataBase.h
#ifndef _H_VARIANT_DATA_BASE_H_
#define _H_VARIANT_DATA_BASE_H_

#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HSmartPointer/HSmartPointerObjectBase.h"

/**/
namespace Hubris
{
	//base class for the data variant
	class HVariantDataBase : public HSmartPointerObjectBase< HVariantDataBase >
	{
	public:
		//////////////////////////////////////////////////////
		// disabled
		HVariantDataBase();
		virtual ~HVariantDataBase();

		virtual HBOOL Cmp( const HVariantDataBase& in_rhs ) const;
		virtual HS32 TypeIndexGet() const;

	private:
		//////////////////////////////////////////////////////
		// disabled
		HVariantDataBase( const HVariantDataBase& in_src );
		const HVariantDataBase operator =( const HVariantDataBase & in_rhs );

	};

	/**/
};

#endif // _H_VARIANT_DATA_BASE_H_