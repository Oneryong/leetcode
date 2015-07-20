/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 10:37:25
* >File Name: maximum_product_subarray.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Find the contiguous subarray within an array (containing at least one number) which has the largest product(产品，结果，乘积).
 *
 * For example, given the array [2,3,-2,4],
 * the contiguous subarray [2,3] has the largest product = 6.
 */

int maxProduct(vector<int>& nums)
{
	int len = nums.size();
	if(len == 0)
		return 0;

	vector<int> temp;
	int tempproduct = 1;
	int maxproduct = nums[0];
	int i, j;

	temp.push_back(nums[0]);
	for(i = 1; i < len; ++i)
	{
		if(nums[i] == nums[i - 1] + 1)
			temp.push_back(nums[i]);
		else
		{
			for(j = 0; j < temp.size(); ++j)
			{
				tempproduct *= temp[j];
			}

			if(tempproduct > maxproduct)
			{
				maxproduct = tempproduct;
			}

			temp.clear();
			temp.push_back(nums[i]);
			tempproduct = 1;
		}
	}

	for(j = 0; j < temp.size(); ++j)
	{
		tempproduct *= temp[j];
	}

	if(tempproduct > maxproduct)
	{
		maxproduct = tempproduct;
	}

	return maxproduct;
}

int main()
{
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(3);
	nums.push_back(-2);
	nums.push_back(4);
	int result;
	result = maxProduct(nums);
	cout << "result = " << result << endl;
	return 0;
}
