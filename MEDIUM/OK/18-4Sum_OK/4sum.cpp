/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 10:34:37
 * >File Name: 4sum.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * Note:
 * Elements in a quadruplet (a,b,c,d) must be in non-descending order. (ie, a ≤ b ≤ c ≤ d)
 * The solution set must not contain duplicate quadruplets.
 * For example, given array S = {1 0 -1 0 -2 2}, and target = 0.
 *
 * A solution set is:
 * (-1,  0, 0, 1)
 * (-2, -1, 1, 2)
 * (-2,  0, 0, 2)
 */

void twoSum(vector<int>& nums, int& start1, int& start2, int target, vector<vector<int> >& result)
{
	int size = nums.size();
	if(size - start2 < 2)
		return;

	vector<int> temp1;
	int temp;
	int i = start2;
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
			temp1.push_back(nums[start1 - 1]);
			temp1.push_back(nums[start2 - 1]);
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

void threeSum(vector<int>& nums, int& start1, int& start2, int target, vector<vector<int> >& result)
{
	int len = nums.size();
	if(len - start1 < 3)
		return;

	int tar;
	for(int i = start1; i < len - 2; ++i)
	{
		if(i > start1 && nums[i] == nums[i - 1])
			continue;
		tar = target - nums[i];
		start2 = i + 1;
		twoSum(nums, start1, start2, tar, result);
	}
}

vector<vector<int> > fourSum(vector<int>& nums, int target)
{
	vector<vector<int> > result;
	int len = nums.size();
	if(len < 4)
		return result;

	sort(nums.begin(), nums.end());

	int tar;
	int start1 = 0;
	int start2 = 0;
	for(int i = 0; i < len - 3; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;
		tar = target - nums[i];
		start1 = i + 1;
		threeSum(nums, start1, start2, tar, result);
	}

	return result;
}

int main()
{
	int i, j;
	int a, b;
	vector<int> s;
	s.push_back(1);
	s.push_back(0);
	s.push_back(-1);
	s.push_back(0);
	s.push_back(-2);
	s.push_back(2);
	a = s.size();
	
	for(i = 0; i < a; ++i)
	{
		cout << s[i] << " ";
	}
	
	int target = 0;
	cout << "target = " << target << endl;
	
	vector<vector<int> > result;
	result = fourSum(s, target);
	
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
