#include <iostream>
#include <string>
#include <vector>

#include"quicksort.h"

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;

using std::vector; 

int recursiveVectorSum(vector<int> nums)
{
    if (nums.size() == 1) //base case
    {
        return nums.back();
    }
    else //recursive case
    {
        int back = nums.back();
        nums.pop_back();
        return back + recursiveVectorSum(nums);
    }
}

int main()
{
    vector<int> nums = { 11, 33, 22, 55, 44 };
    using namespace MySpace::Algos; 

    quickSort(nums, 0, 4);

    for (auto& num : nums)
    {
        cout << num << endl; 

    }
    //int sum = recursiveVectorSum(nums); 

    //cout << sum << endl; 


	return 0; 
}