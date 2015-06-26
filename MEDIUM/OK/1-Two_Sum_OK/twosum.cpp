/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:11:56
* >File Name: twosum.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices(索引) of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */

//this is the simplest solution : O(n * n)
/*
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	int size = nums.size();
	if(size < 2)
		return result;

	int i, j;
	for(i = 0; i < size; ++i)
	{
		for(j = i + 1; j < size; ++j)
		{
			if(nums[i] + nums[j] == target)
			{
				result.push_back(i + 1);
				result.push_back(j + 1);
				return result;
			}
		}
	}

	return result;
}
*/

//this method:first use hash table store the index, than sort array, than use i = 0, j = n - 1; ++i, --j;（夹逼方法）
//in this method, must do not have same number.
/*
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	int size = nums.size();
	if(size < 2)
		return result;

	int i, j;
	map<int, int> table;
	for(i = 0; i < size; ++i)
		table.insert(make_pair(nums[i], i + 1));
	
	sort(nums.begin(), nums.end());
	
	i = 0;
	j = size - 1;

	while(i < j)
	{
		if(nums[i] + nums[j] == target)
		{
			if(table[nums[i]] < table[nums[j]])
			{
				result.push_back(table[nums[i]]);
				result.push_back(table[nums[j]]);
				break;
			}
			else
			{
				result.push_back(table[nums[j]]);
				result.push_back(table[nums[i]]);
				break;
			}
		}
		else if(nums[i] + nums[j] < target)
			++i;
		else
			--j;
	}

	return result;
}
*/

//this method:use the hash table, and find the result on the hash table.
//in this method: it can have two same numbers.
vector<int> twoSum(vector<int>& nums, int target)
{
	vector<int> result;
	int size = nums.size();
	if(size < 2)
		return result;

	map<int, int> table;
	int temp;

	for(int i = 0; i < size; ++i)
	{
		temp = target - nums[i];
		if(table.find(temp) != table.end())
		{
			result.push_back(table[temp] + 1);
			result.push_back(i + 1);
		}
		else
			table.insert(make_pair(nums[i], i));
	}

	return result;
}

int main()
{
	vector<int> input(4, 1);
	vector<int> result;
	input[0] = 1;
	input[1] = 2;
	input[2] = 3;
	input[3] = 4;
	result = twoSum(input, 5);
	for(int i = 0; i < result.size(); ++i)
		cout << result[i] << endl;
	return 0;
}
