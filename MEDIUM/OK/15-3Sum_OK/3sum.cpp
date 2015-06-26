/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 10:24:52
 * >File Name: 3sum.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

/*
 * Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique(唯一的) triplets(三元组) in the array which gives the sum of zero.
 *
 * Note:
 * Elements in a triplet (a,b,c) must be in non-descending(非下降的) order. (ie, a ≤ b ≤ c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},
 *
 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
 */

void twoSum(vector<int>& nums, int start, int target, vector<vector<int> >& result)
{
	int size = nums.size();
	if(size - start < 2)
		return;

	vector<int> temp1;
	int temp;
	int i = start;
	int j = size - 1;

	while(i < j)
	{
		temp = nums[i] + nums[j];

		if(temp < target)
			++i;
		else if(temp > target)
			--j;
		else
		{
			temp1.push_back(nums[start - 1]);
			temp1.push_back(nums[i]);
			temp1.push_back(nums[j]);
			result.push_back(temp1);
			temp1.clear();

			temp = i + 1;
			while(temp < j && nums[temp] == nums[i])
				++temp;
			i = temp;

			temp = j - 1;
			while(temp > i && nums[temp] == nums[j])
				--temp;
			j = temp;
		}
	}
}


vector<vector<int> > threeSum(vector<int>& nums)
{
	vector<vector<int> > result;
	int len = nums.size();
	if(len < 3)
		return result;

	int target = 0;
	sort(nums.begin(), nums.end());
	int i;
	for(i = 0; i < len - 2; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		target = 0 - nums[i];
		twoSum(nums, i + 1, target, result);
	}

	return result;
}

int main()
{
	int i, j;
	int a, b;
	vector<int> s;
	s.push_back(-1);
	s.push_back(0);
	s.push_back(1);
	s.push_back(2);
	s.push_back(-1);
	s.push_back(-4);
	a = s.size();
	for(i = 0; i < a; ++i)
	{
		cout << s[i] << " ";
	}
	cout << endl;
	vector<vector<int> > result;
	result = threeSum(s);
	a = result.size();
	for(i = 0; i < a; ++i)
	{
		b = result[i].size();
		for(j = 0; j < b; ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	return 0;
}
