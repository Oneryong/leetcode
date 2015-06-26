/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/09 19:30:21
 * >File Name: contains_duplicate2.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*
 * Given an array of integers and an integer k, find out whether there there are two distinct indices i and j in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
 */


bool containsNearbyDuplicate(vector<int>& nums, int k)
{
	if(nums.empty())
		return false;

	map<int, int> table;
	int len = nums.size();
	for(int i = 0; i < len; ++i)
	{
		if(table.find(nums[i]) != table.end() && (i - table[nums[i]]) <= k)
			return true;
		else
			table[nums[i]] = i;
	}

	return false;
}

int main()
{
	return 0;
}
