/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 16:56:15
* >File Name: next_permutation.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Implement next permutationi(排列，置换), which rearranges(重新排列，重新整理) numbers into the lexicographically(字典序) next greater permutation of numbers.
 *
 * If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending(上升的) order).
 *
 * The replacement must be in-place, do not allocate extra memory.
 *
 * Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 */

/*
void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}
*/

void nextPermutation(vector<int>& nums)
{
	int len = nums.size();
	if(len <= 1)
		return;

	int i, j;
	int index = -1;
	for(i = len - 1; i > 0; --i)
	{
		if(nums[i - 1] < nums[i])
		{
			index = i - 1;
			break;
		}
	}
	if(index == -1)
	{
		for(i = 0, j = len - 1; i < j; ++i, --j)
			swap(nums[i], nums[j]);
	}
	else
	{
		for(i = len - 1; i > index; --i)
		{
			if(nums[i] > nums[index])
				break;
		}

		swap(nums[index], nums[i]);
		sort(nums.begin() + index + 1, nums.end());
	}
}

int main()
{
	return 0;
}
