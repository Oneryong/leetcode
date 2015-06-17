/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:04:03
* >File Name: house_robber.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
 *
 * Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
 */

/*
 * Dynamic Programming
 */

int rob(vector<int>& nums)
{
	if(nums.empty())
		return 0;

	int size = nums.size();
	vector<int> dp(size, 0);
	dp[0] = nums[0];

	if(size > 1)
	{
		dp[1] = (nums[0] >= nums[1]) ? nums[0] : nums[1];
		for(int i = 2; i < size; ++i)
		{
			dp[i] = ((nums[i] + dp[i - 2]) > dp[i - 1]) ? (nums[i] + dp[i - 2]) : dp[i - 1];
		}
	}

	return dp[size - 1];
}

int main()
{
/*
Input: [4,1,2,7,5,3,1]
Output: 12
Expected: 14
 */
	return 0;
}
