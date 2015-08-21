/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:59:39
* >File Name: house_robber2.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Note: This is an extension of House Robber.
 *
 * After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

/* Dynamic Programming */
/* 
 * first: 0 ~ n-1
 * second: 1 ~ n
 * return the max
 */
int rob(vector<int>& nums)
{
	int len = nums.size();
	if(len == 0)
		return 0;
	if(len == 1)
		return nums[0];

	int max1 = 0;
	int max2 = 0;
	int i = 0;
	int dp[len];

	//first dynamic
	dp[0] = nums[0];
	dp[1] = (nums[1] > num[0]) ? nums[1] : nums[0];
	for(i = 2; i < len - 1; ++i)
	{
		dp[i] = (nums[i] + dp[i - 2] > dp[i -1]) ? nums[i] + dp[i - 2] : dp[i - 1];
	}
	max1 = dp[len - 2];

	//second dynamic
	dp[1] = nums[1];
	dp[2] = (nums[2] > nums[1]) ? nums[2] : nums[1];
	for(i = 3; i < len; ++i)
	{
		dp[i] = (nums[i] + dp[i - 2] > dp[i - 1]) ? nums[i] + dp[i - 2] : dp[i - 1];
	}
	max2 = dp[len - 1];

	return max1 > max2 ? max1 : max2;
}

int main()
{
	return 0;
}
