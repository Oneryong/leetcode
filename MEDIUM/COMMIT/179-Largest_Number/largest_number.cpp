/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:16:28
* >File Name: largest_number.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
 * Given a list of non negative integers, arrange them such that they form the largest number.
 *
 * For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
 *
 * Note: The result may be very large, so you need to return a string instead of an integer.
 */

static string inttostring(int n)
{
	if(n < 0)
		return NULL;

	int bitflag = 1;
	int temp = n;
	string result;

	while(temp > 9)
	{
		bitflag *= 10;
		temp /= 10;
	}

	while(bitflag)
	{
		temp = n / bitflag;
		result.push_back(temp + '0');
		n %= bitflag;
		bitflag /= 10;
	}

	return result;
}

static bool comp(string a, string b)
{
	string s1 = a + b;
	string s2 = b + a;
	return (s1 > s2);
}

string largestNumber(vector<int>& nums)
{
	int len = nums.size();
	if(len == 0)
		return NULL;
	if(len == 1)
		return inttostring(nums[0]);
	
	string result;
	vector<string> temp;
	int zerocount = 0;
	int i;

	for(i = 0; i < len; ++i)
	{
		if(nums[i] == 0)
		{
			++zerocount;
		}
		temp.push_back(inttostring(nums[i]));
	}

	if(zerocount == len)
		return NULL;

	sort(temp.begin(), temp.end(), comp);

	for(i = 0; i < len; ++i)
		result += temp[i];

	return result;
}

int main()
{
	//int n = 3;
	vector<int> nums;
	nums.push_back(3);
	nums.push_back(30);
	nums.push_back(34);
	nums.push_back(5);
	nums.push_back(9);
	string result;
	//result = inttostring(n);
	result = largestNumber(nums);
	cout << "result = " << result << endl;
	return 0;
}
