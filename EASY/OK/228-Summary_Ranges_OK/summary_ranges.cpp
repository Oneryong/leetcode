/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 13:31:25
* >File Name: summary_ranges.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

/*
 * Given a sorted integer array without duplicates, return the summary(摘要，概要，总结) of its ranges.
 *
 * For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
 */

const int MAX_INT = 2147483647;
const int MIN_INT = -2147483648;

string IntToString(int a)
{
	if(a == MIN_INT)
	{
		return "-2147483648";
	}
	
	string result;
	if(a < 0)
		result += "-";

	int temp = abs(a);
	int count = 1;
	while(temp > 9)
	{
		count *= 10;
		temp /= 10;
	}

	temp = abs(a);
	while(count)
	{
		result.push_back((temp / count) + '0');
		temp %= count;
		count /= 10;
	}

	return result;
}

vector<string> summaryRanges(vector<int>& nums)
{
	vector<string> result;
	int len = nums.size();
	if(len == 0)
		return result;

	string temp = IntToString(nums[0]);

	for(int i = 1; i < len; ++i)
	{
		if(nums[i] - nums[i - 1] != 1)
		{
			if(IntToString(nums[i - 1]) != temp)
			{
				temp = temp + "->";
				temp = temp + IntToString(nums[i - 1]);
			}
			result.push_back(temp);
			temp = IntToString(nums[i]);
		}
	}

	if(IntToString(nums[len - 1]) != temp)
	{
		temp = temp + "->";
		temp = temp + IntToString(nums[len - 1]);
	}
	result.push_back(temp);

	return result;
}

int main()
{
	int a = -2147483647;
	string b;
	cout << "a = " << a << endl;
	b = IntToString(a);
	cout << "b = " << b << endl;

	vector<int> nums(2, 0);
	nums[0] = -2;
	nums[1] = -1;
//	nums[2] = 2;
//	nums[3] = 4;
//	nums[4] = 5;
//	nums[5] = 7;
	vector<string> result;
	result = summaryRanges(nums);
	int len = result.size();
	cout << "result = " << endl;
	for(int i = 0; i < len; ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}
