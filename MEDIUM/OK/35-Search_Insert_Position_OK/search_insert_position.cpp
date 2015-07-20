/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 17:00:23
* >File Name: search_insert_position.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
 *
 * You may assume no duplicates in the array.
 *
 * Here are few examples.
 * [1,3,5,6], 5 → 2
 * [1,3,5,6], 2 → 1
 * [1,3,5,6], 7 → 4
 * [1,3,5,6], 0 → 0
 */

int searchInsert(vector<int>& nums, int target)
{
	int len = nums.size();
	if(len == 0)
		return 0;

	if(nums[0] >= target)
		return 0;
	if(nums[len - 1] < target)
		return len;

	int left = 0;
	int right = len - 1;
	int middle;
	while(left <= right)
	{
		middle = (left + right) / 2;
		if(nums[middle] < target)
			left = middle + 1;
		else if(nums[middle] > target)
			right = middle - 1;
		else
			return middle;
	}

	return left;
}

int main()
{
	return 0;
}
