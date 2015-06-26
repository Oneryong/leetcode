/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/09 19:30:21
 * >File Name: contains_duplicate1.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
 */

bool containsDuplicate(vector<int>& nums)
{
	if(nums.empty())
		return false;

	sort(nums.begin(), nums.end());
	
	vector<int> :: iterator iter = nums.begin();
	for(; iter < nums.end() - 1; ++iter)
	{
		if(*iter == *(iter + 1))
			return true;
	}
	return false;
}

int main()
{
	return 0;
}
