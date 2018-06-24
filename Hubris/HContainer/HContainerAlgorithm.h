//file: Hubris/HContainer/HContainerAlgorithm.h
#ifndef _H_CONTAINER_ALGORITHM_H_
#define _H_CONTAINER_ALGORITHM_H_

#include "Hubris/HCommon/HCommonDefine.h"
#include "Hubris/HCommon/HCommonForEach.h"
#include "Hubris/HCommon/HCommonType.h"
#include "Hubris/HContainer/HContainerAlgorithmSort.h"
//#include "Hubris/HTrait/HTraitSwap.h"

/**/
namespace Hubris
{
	template< typename IN_TYPE >
	HVOID HTraitSwap( IN_TYPE& in_out_lhs, IN_TYPE& in_out_rhs );

	class HContainerAlgorithm
	{
		///////////////////////////////////////////////////////////
		// public static methods
	public:
		template< typename IN_CONTAINER > 
		static HVOID Merge( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, IN_CONTAINER& out_container ); 

		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID Merge( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, IN_CONTAINER& out_container ); 

		//split given data into two containers
		template< typename IN_CONTAINER > 
		static HVOID Split( const IN_CONTAINER& in_data, IN_CONTAINER& out_lhs, IN_CONTAINER& out_rhs ); 
		//split given data into a second containers
		template< typename IN_CONTAINER > 
		static HVOID Split( IN_CONTAINER& in_out_lhs, IN_CONTAINER& out_rhs ); 

		template< typename IN_CONTAINER > 
		static HVOID MergeSort( IN_CONTAINER& in_container ); 

		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID MergeSort( IN_CONTAINER& in_container ); 

		///////////////////////////////////////////////////////////
		// private static methods
	private:
		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID BubbleSort( IN_CONTAINER& in_container ); 

		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID BubbleSortRange( typename IN_CONTAINER::TIterator& in_start, typename IN_CONTAINER::TIterator& in_end ); 

		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID MergeSortRange( typename IN_CONTAINER::TIterator& in_start, typename IN_CONTAINER::TIterator& in_end ); 

		template< typename IN_CONTAINER, typename IN_SORT > 
		static HVOID MergeToRange( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, typename IN_CONTAINER::TIterator& in_destStart, typename IN_CONTAINER::TIterator& in_destEnd ); 

		///////////////////////////////////////////////////////////
		// private static members
	private:
		static const HSINT s_mergeSortThreashold = 20;
	};

	/**/
	template< typename IN_CONTAINER > 
	HVOID HContainerAlgorithm::Merge( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, IN_CONTAINER& out_container )
	{
		Merge< IN_CONTAINER, HContainerAlgorithmSort< IN_CONTAINER::TType > >( in_lhs, in_rhs, out_container );
		return;
	}

	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::Merge( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, IN_CONTAINER& out_container )
	{
		out_container.SizeSet( in_lhs.SizeGet() + in_rhs.SizeGet() );
		IN_CONTAINER::TIterator start = out_container.Begin();
		IN_CONTAINER::TIterator end = out_container.End();
		MergeToRange< IN_CONTAINER, IN_SORT >( in_lhs, in_rhs, start, end );
		return;
	}

	/**/
	template< typename IN_CONTAINER > 
	HVOID HContainerAlgorithm::Split( const IN_CONTAINER& in_data, IN_CONTAINER& out_lhs, IN_CONTAINER& out_rhs )
	{
		out_lhs.Clear();
		out_rhs.Clear();

		const HSINT count = in_data.SizeGet();
		if( 0 < count )
		{
			const HSINT half = ( count + 1 ) >> 1;

			out_lhs.Insert( in_data.Begin(), in_data.Begin() + half );
			out_rhs.Insert( in_data.Begin() + half, in_data.End() );
		}

		return;
	}

	template< typename IN_CONTAINER > 
	HVOID HContainerAlgorithm::Split( IN_CONTAINER& in_out_lhs, IN_CONTAINER& out_rhs )
	{
		out_rhs.Clear();

		const HSINT count = in_out_lhs.SizeGet();
		if( 0 < count )
		{
			const HSINT half = (count + 1) >> 1;

			out_rhs.Insert( in_out_lhs.Begin() + half, in_out_lhs.End() );
			in_out_lhs.Remove( in_out_lhs.Begin() + half, in_out_lhs.End() );
		}

		return;
	}

	/**/
	template< typename IN_CONTAINER > 
	HVOID HContainerAlgorithm::MergeSort( IN_CONTAINER& in_container )
	{
		MergeSort< IN_CONTAINER, HContainerAlgorithmSort< IN_CONTAINER::TType > >( in_container );
		return;
	}


	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::MergeSort( IN_CONTAINER& in_container )
	{
		IN_CONTAINER::TIterator start = in_container.Begin();
		IN_CONTAINER::TIterator end = in_container.End();
		MergeSortRange< IN_CONTAINER, IN_SORT >( start, end );
		return;
	}

	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::BubbleSort( IN_CONTAINER& in_container )
	{
		IN_CONTAINER::TIterator start = in_container.Begin();
		IN_CONTAINER::TIterator end = in_container.End();
		BubbleSortRange< IN_CONTAINER, IN_SORT >( start, end );

		return;
	}

	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::BubbleSortRange( typename IN_CONTAINER::TIterator & in_start, typename IN_CONTAINER::TIterator & in_end )
	{
		if( ( in_end - in_start ) <= 1 )
		{
			return;
		}

		for( IN_CONTAINER::TIterator iter = in_end - 1; iter != in_start; --iter )
		{
			IN_CONTAINER::TIterator bubble = iter - 1;
			IN_CONTAINER::TIterator bubbleNext = iter;

			while( true == IN_SORT::Compair( ( *bubbleNext ), ( *bubble ) ) )
			{
				HTraitSwap< IN_CONTAINER::TType >( ( *bubble ), ( *bubbleNext ) );

				bubble = bubbleNext;
				bubbleNext += 1;

				if( bubbleNext == in_end )
				{
					break;
				}
			}
		}

		return;
	};

	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::MergeSortRange( typename IN_CONTAINER::TIterator& in_start, typename IN_CONTAINER::TIterator& in_end )
	{
		const HSINT length = ( in_end - in_start );
		if( length <= 1 )
		{
			return;
		}
		else if( length < s_mergeSortThreashold )
		{
			BubbleSortRange< IN_CONTAINER, IN_SORT >( in_start, in_end );
		}
		else 
		{
			const HSINT firstHalf = length >> 1;

			IN_CONTAINER firstHalfArray;
			{
				IN_CONTAINER::TIterator firstHalfArrayStart = in_start;
				IN_CONTAINER::TIterator firstHalfArrayEnd = in_start + firstHalf;

				firstHalfArray.Insert( firstHalfArrayStart, firstHalfArrayEnd );
				MergeSort< IN_CONTAINER, IN_SORT >( firstHalfArray );
			}

			IN_CONTAINER secondHalfArray;
			{
				IN_CONTAINER::TIterator secondHalfArrayStart = in_start + firstHalf;
				IN_CONTAINER::TIterator secondHalfArrayEnd = in_end;

				secondHalfArray.Insert( secondHalfArrayStart, secondHalfArrayEnd );
				MergeSort< IN_CONTAINER, IN_SORT >( secondHalfArray );
			}

			MergeToRange< IN_CONTAINER, IN_SORT >( firstHalfArray, secondHalfArray, in_start, in_end );
		}

		return;
	}

	/**/
	template< typename IN_CONTAINER, typename IN_SORT > 
	HVOID HContainerAlgorithm::MergeToRange( const IN_CONTAINER& in_lhs, const IN_CONTAINER& in_rhs, typename IN_CONTAINER::TIterator& in_destStart, typename IN_CONTAINER::TIterator & in_destEnd )
	{
		IN_CONTAINER::TIterator traceFirstHalf = in_lhs.Begin();
		IN_CONTAINER::TIterator endFirstHalf = in_lhs.End();

		IN_CONTAINER::TIterator traceSecondHalf = in_rhs.Begin();
		IN_CONTAINER::TIterator endSecondHalf = in_rhs.End();

		HCOMMON_FOR_EACH_RANGE( data, IN_CONTAINER, in_destStart, in_destEnd )
		{
			HBOOL addFirst = false;

			if( traceFirstHalf == endFirstHalf )
			{
				addFirst = false;
			}
			else if( traceSecondHalf == endSecondHalf )
			{
				addFirst = true;
			}
			else
			{
				//addFirst = ((*traceFirstHalf) < (*traceSecondHalf));
				addFirst = IN_SORT::Compair( ( *traceFirstHalf ), ( *traceSecondHalf ) );
			}

			if( true == addFirst )
			{
				data = ( *traceFirstHalf );
				++traceFirstHalf;
			}
			else
			{
				data = ( *traceSecondHalf );
				++traceSecondHalf;
			}
		}

		return;
	}

	/**/
};

#endif // _H_CONTAINER_ALGORITHM_H_