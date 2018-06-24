//file: Pride/PCamera/PCamera.h
#ifndef _P_CAMERA_H_
#define _P_CAMERA_H_

#include< Hubris/HCommon/HCommon_Export.h >
#include< Hubris/HMatrix/HMatrix_Export.h >

namespace Pride
{
	/////////////////////////////////////////////////////////////////
	// forward declarations
	/**/

	///////////////////////////////////////////////////////
	// class
	/*
		is it overburdining the camera to have it generate a hull? 
		using camera as something to cache hull result...
		using camera as something to cache sphere result...

	*/
	class PCamera
	{
		///////////////////////////////////////////////////////
		// creation
	public:
		PCamera( const PCamera& in_src );
		PCamera( 
			const Hubris::HMatrixR4& in_transform,
			const Hubris::HSINT in_type,
			const Hubris::HREAL in_left,
			const Hubris::HREAL in_right,
			const Hubris::HREAL in_top,
			const Hubris::HREAL in_bottom,
			const Hubris::HREAL in_near,
			const Hubris::HREAL in_far
			);
		PCamera();
		~PCamera();

		///////////////////////////////////////////////////////
		// operators
	public:
		const PCamera& operator=( const PCamera& in_rhs );
		const Hubris::HBOOL operator==( const PCamera& in_rhs )const;
		const Hubris::HBOOL operator!=( const PCamera& in_rhs )const;

		///////////////////////////////////////////////////////
		// static public accessors
	public:
		static const Hubris::HSINT TypePerspectiveGet();
		static const Hubris::HSINT TypeOrthogonalGet();

		///////////////////////////////////////////////////////
		// public accessors
	public:
		const Hubris::HMatrixR4& TransformGet()const{ return m_transform; }
		Hubris::HVOID TransformSet( const Hubris::HMatrixR4& in_transform ){ m_transform = in_transform; return; }

		const Hubris::HSINT TypeGet()const{ return m_type; }
		Hubris::HVOID TypeSet( const Hubris::HSINT in_type ){ m_type = in_type; return; }

		const Hubris::HREAL LeftGet()const{ return m_left; }
		Hubris::HVOID LeftSet( const Hubris::HREAL in_left ){ m_left = in_left; return; }

		const Hubris::HREAL RightGet()const{ return m_right; }
		Hubris::HVOID RightSet( const Hubris::HREAL in_right ){ m_right = in_right; return; }
	
		const Hubris::HREAL TopGet()const{ return m_top; }
		Hubris::HVOID TopSet( const Hubris::HREAL in_top ){ m_top = in_top; return; }

		const Hubris::HREAL BottomGet()const{ return m_bottom; }
		Hubris::HVOID BottomSet( const Hubris::HREAL in_bottom ){ m_bottom = in_bottom; return; }
	
		const Hubris::HREAL NearGet()const{ return m_near; }
		Hubris::HVOID NearSet( const Hubris::HREAL in_near ){ m_near = in_near; return; }
	
		const Hubris::HREAL FarGet()const{ return m_far; }
		Hubris::HVOID FarSet( const Hubris::HREAL in_far ){ m_far = in_far; return; }

		///////////////////////////////////////////////////////
		// private members
	private:
		Hubris::HMatrixR4 m_transform;
		Hubris::HSINT m_type;
		Hubris::HREAL m_left;
		Hubris::HREAL m_right;
		Hubris::HREAL m_top;
		Hubris::HREAL m_bottom;
		Hubris::HREAL m_near;
		Hubris::HREAL m_far;

	};

	/**/
};

#endif // _P_CAMERA_H_