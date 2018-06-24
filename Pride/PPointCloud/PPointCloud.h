//file: Pride/PPointCloud/PPointCloud.h
#ifndef _P_POINT_CLOUD_H_
#define _P_POINT_CLOUD_H_

#include< Hubris/HCommon/HCommon_Export.h >

#include< Hubris/HContainer/HContainer_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >


namespace Pride
{
	///////////////////////////////////////////////////////
	// predefs
	/**/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPointCloud;
	typedef PPointCloud< Hubris::HREAL, 2 >PPointCloudR2; //instanciated in cpp
	typedef PPointCloud< Hubris::HREAL, 3 >PPointCloudR3; //instanciated in cpp
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PBounds;

	///////////////////////////////////////////////////////
	// class
	/*
		track bounds in [n] space
	*/
	template< typename IN_TYPE, Hubris::HSINT IN_COUNT >class PPointCloud
	{
		///////////////////////////////////////////////////////
		// typedef
	private:
		typedef Hubris::HMatrix< IN_TYPE, IN_COUNT, 1 >TVector;
		typedef Hubris::HContainerArray< TVector >TArrayVector;
		typedef Hubris::HContainerArray< Hubris::HSINT >TArraySint;
		typedef PBounds< IN_TYPE, IN_COUNT >TBounds;

		///////////////////////////////////////////////////////
		// creation
	public:
		PPointCloud( const PPointCloud& in_src );
		PPointCloud();
		~PPointCloud();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PPointCloud& operator=( const PPointCloud& in_rhs );
		const Hubris::HBOOL operator==( const PPointCloud& in_rhs )const;
		const Hubris::HBOOL operator!=( const PPointCloud& in_rhs )const;

		///////////////////////////////////////////////////////
		// static public methods
	public:
		static const TVector ThreasholdCreate(
			const TBounds& in_bounds,
			const Hubris::HREAL in_pointMergeThreasholdPercentage
			);

		static const TVector ThreasholdCreate(
			const TArrayVector& in_arrayPoint,
			const Hubris::HREAL in_pointMergeThreasholdPercentage
			);

		///////////////////////////////////////////////////////
		// public methods
	public:
		//merge a point, weild with point within threashold, return point index
		const Hubris::HSINT PointMerge( 
			const TVector& in_point,
			const TVector& in_threashold = TVector()
			);

		Hubris::HVOID ArrayPointMerge( 
			const TArrayVector& in_arrayPoint,
			const TVector& in_threashold = TVector()
			);

		Hubris::HVOID ArrayPointAdd( 
			const TArrayVector& in_arrayPoint
			);

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const TArrayVector& ArrayPointsGet()const{ return m_arrayPoints; }
		Hubris::HVOID ArrayPointsSet( const TArrayVector& in_arrayVertex );

		///////////////////////////////////////////////////////
		// private members
	private:
		TArrayVector m_arrayPoints;
		TArraySint m_arrayMergeCount;

	};

	/**/
	
};

#endif // _P_POINT_CLOUD_H_