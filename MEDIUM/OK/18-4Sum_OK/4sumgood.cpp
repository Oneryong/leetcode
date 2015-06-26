/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 10:34:37
 * >File Name: 4sum.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <unordered_map>
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

vector<vector<int> > fourSum(vector<int>& nums, int target)
{
	vector<vector<int> > result;
	int len = nums.size();
	if(len < 4)
		return result;

	sort(nums.begin(), nums.end());

	unordered_map<int, vector<pair<int, int> > > table;
	table.reserve(len * len);
	int i, j, k;
	for(i = 0; i < len; ++i)
	{
		for(j = i + 1; j < len; ++j)
		{
			table[nums[i] + nums[j]].push_back(make_pair(i, j));
		}
	}

	vector<pair<int, int> > temp;
	//vector<int> tempresult;
	for(i = 0; i < len - 3; ++i)
	{
		if(i > 0 && nums[i] == nums[i - 1])
			continue;

		for(j = i + 1; j < len - 2; ++j)
		{
			if(j > i + 1 && nums[j] == nums[j - 1])
				continue;

			if(table.find(target - nums[i] - nums[j]) != table.end())
			{
				temp = table[target - nums[i] - nums[j]];
				bool flag = true;
				for(k = 0; k < temp.size(); ++k)
				{
					if(temp[k].first <= j)
						continue;
					
					if(flag || ((result.back())[2] != nums[temp[k].first]))
					{
						result.push_back(vector<int>{nums[i], nums[j], nums[temp[k].first], nums[temp[k].second]});
						//tempresult.push_back(nums[i]);
						//tempresult.push_back(nums[j]);
						//tempresult.push_back(nums[temp[k].first]);
						//tempresult.push_back(nums[temp[k].second]);
						//result.push_back(tempresult);
						//tempresult.clear();
						flag = false;
					}
				}
			}
		}
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
