//file: Pride/PColour/PColour.h
#ifndef _P_COLOUR_H_
#define _P_COLOUR_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour;
	//see cpp for instanciation
	typedef PColour< Hubris::HU8, 1 >PColourMono;
	typedef PColour< Hubris::HU8, 3 >PColourRgb;
	typedef PColour< Hubris::HU8, 4 >PColourRgba;
	typedef PColour< Hubris::HREAL, 1 >PColourRealMono;
	typedef PColour< Hubris::HREAL, 3 >PColourRealRgb;
	typedef PColour< Hubris::HREAL, 4 >PColourRealRgba;

	///////////////////////////////////////////////////////
	// class
	/*
		colour data is expected to be in range of zero to one for HREAL, but may exceed range on either side
		opacity of FULL is solid, opacity of ZERO is fully transparent
		added channel count to template, a bit weird having multiple constructores for template variations
		depend on run time assert to detect misuse (ie, out of range access)
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_CHANNEL_COUNT >class PColour
	{
		///////////////////////////////////////////////////////////
		// typedef
	public:
		typedef Hubris::HMatrix< IN_TYPE, IN_CHANNEL_COUNT, 1 >TVector;

		///////////////////////////////////////////////////////
		// creation
	public:
		PColour( const PColour& in_src );
		//for vector manipulation of data, see accessors DataGet & DataSet
		//disallow assignment from vector, no way of knowing which is red/ green/ blue? oblige to be from DataGet
		PColour( const TVector& in_data ); 
		PColour( 
			const IN_TYPE in_red,
			const IN_TYPE in_green,
			const IN_TYPE in_blue,
			const IN_TYPE in_opacity
			);
		PColour( 
			const IN_TYPE in_red,
			const IN_TYPE in_green,
			const IN_TYPE in_blue
			);
		//set all chanels to the same value, default constructor
		/*
			could not set them to s_unit as for colourU8 end up have 1,1,1,1 as default colour 
			(so is default black transparent?)
		*/
		PColour( const IN_TYPE in_mono = 0.0F /* Hubris::HVariablesMath::ZeroGet< IN_TYPE >() */ );
		~PColour();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PColour& operator=( const PColour& in_rhs );
		//const Hubris::HBOOL operator==( const PColour& in_rhs )const;
		//const Hubris::HBOOL operator!=( const PColour& in_rhs )const;

		///////////////////////////////////////////////////////
		// public methods
	public:
		//return the value in the first channel, set the value to the same in all channels
		IN_TYPE MonoGet()const;
		void MonoSet( const IN_TYPE in_mono );

		//colour data is expected to be in range of zero to one, but may exceed range on either side
		IN_TYPE RedGet()const;
		void RedSet( const IN_TYPE in_red );

		IN_TYPE GreenGet()const;
		void GreenSet( const IN_TYPE in_green );

		IN_TYPE BlueGet()const;
		void BlueSet( const IN_TYPE in_blue );

		//opacity of 1.0 is solid, opacity of zero is fully transparent
		IN_TYPE OpacityGet()const;
		void OpacitySet( const IN_TYPE in_opacity );

		const TVector& DataGet()const{ return m_data; }
		void DataSet( const TVector& in_data ){ m_data = in_data; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		TVector m_data;

	};

	/**/
};

#endif // _P_COLOUR_H_
