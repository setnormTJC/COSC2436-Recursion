#include<vector> 

using std::vector;

namespace MySpace
{
	namespace Algos
	{
		static int swapCount = 0;
		static int comparisonCount = 0;

		template<typename T>
		void mySwap(vector<T>& list, int first, int second)
		{
			T temp;

			temp = list[first];
			list[first] = list[second];
			list[second] = temp;

			swapCount++;
		}


		template<typename T>
		int partition(vector<T>& list, int first, int last)
		{
			T pivot;
			//using T here may alleviate confusing indices with elements!

			int index, smallIndex;

			mySwap(list, first, (first + last) / 2);

			pivot = list[first];
			smallIndex = first;

			for (index = first + 1; index <= last; index++)
			{
				comparisonCount++;

				if (list[index] < pivot)
				{
					smallIndex++;
					mySwap(list, index, smallIndex);

				}
			}

			mySwap(list, first, smallIndex);

			return smallIndex;
		}

		template<typename T>
		void quickSort(vector<T>& list, int first, int last)
		{
			int pivotLocation;

			if (first < last)
			{
				pivotLocation = partition(list, first, last);
				//DIVIDE/partition and conquer!
				quickSort(list, first, pivotLocation - 1); //lower sublist
				//sorts lesser/left ~half of array (if setting pivot to middle)  
				quickSort(list, pivotLocation + 1, last); //upper sublist ("right" half if ascending sort)
			}
		}

	} //end algos namespace 

} //end MySpace

