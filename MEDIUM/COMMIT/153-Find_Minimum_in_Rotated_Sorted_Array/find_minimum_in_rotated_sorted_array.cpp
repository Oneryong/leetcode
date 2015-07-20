/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 10:39:55
* >File Name: find_minimum_in_rotated_sorted_array.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Suppose a sorted array is rotated at some pivot unknown to you beforehand.
 *
 * (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
 *
 * Find the minimum element.
 *
 * You may assume no duplicate exists in the array.
 */

int findMin(vector<int>& nums)
{
	int len = nums.size();
	if(len == 0)
		return -1;

	if(nums[0] < nums[len - 1])
		return nums[0];
	else
	{
		int start = 0;
		int end = len - 1;
		int middle;
		while(start < end)
		{
			middle = (start + end) / 2;
			
			if(nums[middle] > nums[end])
				start = middle + 1;
			else 
				end = middle;
		}

		return nums[start];
	}
}

int main()
{
	vector<int> nums;
	nums.push_back(0);
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(5);
	nums.push_back(6);
	nums.push_back(7);
	int result;
	result = findMin(nums);
	cout << "result = " << result << endl;
	return 0;
}
