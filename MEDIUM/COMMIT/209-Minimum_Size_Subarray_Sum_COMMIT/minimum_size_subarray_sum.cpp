/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:47:17
* >File Name: minimum_size_subarray_sum.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ≥ s. If there isn't one, return 0 instead.
 *
 * For example, given the array [2,3,1,2,4,3] and s = 7,
 * the subarray [4,3] has the minimal length under the problem constraint.
 *
 * More practice:
 * If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
 */

int minSubArrayLen(int s, vector<int>& nums)
{
	int len = nums.size();
	if(len <= 0)
		return 0;

	int start = 0;
	int end = 0;
	int sum = 0;
	int min = 0;
	int temp = 0;

	//find the first result
	while(sum < s && end < len)
	{
		sum += nums[end];
		++end;
	}
	if(sum < s)
		return 0;
	min = end - start;

	//find the min result
	while(start < end && end < len)
	{
		if(end < len)
		{
			sum += nums[end];
			++end;
		}

		if(sum - nums[start] < s)
		{
			if(end == len - 1)
				break;
			else
				continue;
		}

		while(start < end && sum - nums[start] >= s)
		{
			sum -= nums[start];
			++start;
		}
		temp = end - start;
		min = min < temp ? min : temp;
	}
	return min;
}

int main()
{
	vector<int> input;
	int a = 0;
	cout << "please input the vector: ";
	while(cin >> a)
		input.push_back(a);
	cout << endl;
	//input.push_back(2);
	//input.push_back(3);
	//input.push_back(1);
	//input.push_back(2);
	//input.push_back(4);
	//input.push_back(3);
	int s = 7;
	int result = minSubArrayLen(s, input);
	cout << "resutl = " << result << endl;
	return 0;
}
