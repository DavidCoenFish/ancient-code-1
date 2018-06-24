//file: Vanity/VAsset/VAsset.h
#ifndef _V_ASSET_H_
#define _V_ASSET_H_

#include< Hubris/HCommon/HCommon_Export.h >

namespace Vanity
{
	///////////////////////////////////////////////////////
	// forward declarations
	/**/
	class VAssetManager;

	///////////////////////////////////////////////////////
	// class
	/**/
	class VAsset : public Hubris::HSmartPointerObjectBase< VAsset >
	{
		HTYPE_RUN_TIME_TYPE_INFO_BASE( VAsset );

		///////////////////////////////////////////////////////
		// typedef
	private:

		///////////////////////////////////////////////////////
		// creation
	public:
		VAsset();
		virtual ~VAsset();

		///////////////////////////////////////////////////////
		// disabled
	public:
		VAsset( const VAsset& in_src );
		const VAsset& operator=( const VAsset& in_rhs );

	//	///////////////////////////////////////////////////////
	//	// interface
	//public:
	//	virtual Hubris::HVOID PackData(
	//		VAssetManager& in_out_assetManager,
	//		const Hubris::HFileSystemPath& in_path
	//		)=0; //unload

	//	virtual Hubris::HVOID UnPackData( 
	//		VAssetManager& in_out_assetManager,
	//		const Hubris::HFileSystemPath& in_path
	//		)=0; //load file


	};

	/**/
	
};

#endif // _V_ASSET_H_