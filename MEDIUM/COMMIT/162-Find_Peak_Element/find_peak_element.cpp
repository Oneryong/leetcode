/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 10:43:01
* >File Name: find_peak_element.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * A peak element is an element that is greater than its neighbors.
 *
 * Given an input array where num[i] ≠ num[i+1], find a peak element and return its index.
 *
 * The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
 *
 * You may imagine that num[-1] = num[n] = -∞.
 *
 * For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
 *
 * Note:
 * Your solution should be in logarithmic complexity.
 */


int findPeakElement(vector<int>& nums)
{
	int len = nums.size();
	if(len < 3)
		return -2147483648;

	//O(n)
	/*
	for(int i = 1; i < len - 2; ++i)
	{
		if(nums[i] > nums[i - 1])
		{
			if(nums[i] > nums[i + 1])
				return i;
		}
	}
	*/

	//O(logn)
	int start = 1;
	int end = len - 2;
	int middle;
	while(start <= end)
	{
		middle = (start + end) / 2;
		if(nums[middle - 1] < nums[middle] && nums[middle] > nums[middle + 1])
			return middle;
		else if(nums[middle - 1] > nums[middle])
			end = middle - 1;
		else
			start = middle + 1;
	}

	return -2147483648;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(1);
	int result;
	result = findPeakElement(nums);
	cout << "result = " << result << endl;
	return 0;
}
