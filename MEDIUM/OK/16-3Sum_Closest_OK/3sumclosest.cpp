/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 10:27:27
 * >File Name: 3sumclosest.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

/*
 * Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
 *
 * For example, given array S = {-1 2 1 -4}, and target = 1.
 *
 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
 */

void twoSum(vector<int>& nums, int start, int& target, int& closest, int& result)
{
	int size = nums.size();
	if(size - start < 2)
		return;

	int temp;
	int i = start;
	int j = size - 1;

	while(i < j)
	{   
		temp = nums[start - 1] + nums[i] + nums[j] - target;

		if(abs(temp) < abs(closest))
		{   
			closest = temp;
			result = nums[start - 1] + nums[i] + nums[j];
		}
		if(temp < 0)
			++i;
		else
			--j;
	}
}


int threeSumClosest(vector<int>& nums, int target)
{
	int len = nums.size();
	if(len < 3)
		return -target;

	sort(nums.begin(), nums.end());
	int tar;
	int closest = nums[0] + nums[1] + nums[2] - target;
	int result = nums[0] + nums[1] + nums[2];

	for(int i = 0; i < len - 2; ++i)
	{
		twoSum(nums, i + 1, target, closest, result);
	}

	return result;
}

int main()
{
	int result;
	int i, len;
	vector<int> vec;
	vec.push_back(-1);
	vec.push_back(2);
	vec.push_back(1);
	vec.push_back(-4);
	len = vec.size();
	cout << "vec = ";
	for(i = 0; i < len; ++i)
	{
		cout << vec[i] << " ";
	}
	int target = 1;
	cout << "terget = " << target << endl;
	result = threeSumClosest(vec, target);
	cout << "result = " << result << endl;
	return 0;
}
