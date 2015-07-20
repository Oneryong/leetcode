/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 16:58:23
* >File Name: search_for_a_range.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a sorted array of integers, find the starting and ending position of a given target value.
 *
 * Your algorithm's runtime complexity must be in the order of O(log n).
 *
 * If the target is not found in the array, return [-1, -1].
 *
 * For example,
 * Given [5, 7, 7, 8, 8, 10] and target value 8,
 * return [3, 4]
 */

vector<int> searchRange(vector<int>& nums, int target)
{
	vector<int> result(2, -1);
	int len = nums.size();
	if(len == 0)
		return result;

	if(nums[0] > target || nums[len - 1] < target)
		return result;

	int middle;
	int leftl = 0;
	int leftr = len - 1;
	while(leftl <= leftr)
	{
		middle = (leftl + leftr) / 2;
		if(nums[middle] < target)  //注意等于号在什么位置。向左夹逼（等于的时候也向左）
			leftl = middle + 1;
		else
			leftr = middle - 1;
	}

	int rightl = 0;
	int rightr = len - 1;
	while(rightl <= rightr)
	{
		middle = (rightl + rightr) / 2;
		if(nums[middle] <= target)  //向右夹逼（等于的时候也向右）
			rightl = middle + 1;
		else
			rightr = middle - 1;
	}

	if(leftl <= rightr)
	{
		result[0] = leftl;
		result[1] = rightr;
	}

	return result;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	//nums.push_back(2);
	nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(3);
	//nums.push_back(4);
	//nums.push_back(5);
	//nums.push_back(9);
	int target = 2;
	vector<int> result;
	result = searchRange(nums, target);
	cout << "result = " << result[0] << " " << result[1] << endl;
	return 0;
}
