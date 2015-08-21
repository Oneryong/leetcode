/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 13:10:37
* >File Name: kth_largest_element_in_an_array.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct(明显的，独特的，清楚的，有区别的) element.
 *
 * For example,
 * Given [3,2,1,5,6,4] and k = 2, return 5.
 *
 * Note: 
 * You may assume k is always valid, 1 ≤ k ≤ array's length.
 */

/* 
 * 快速排序
 * 注意数据是否都是相互独立的，需不需要考虑是否独立。
 */

/*
int partition(vector<int>& nums, int start, int end)
{
	if(start == end)
		return start;
	int core = nums[start];
	int i, j, temp;
	for(i = start - 1, j = start; j <= end; ++j)
	{
		if(nums[j] <= core)
		{
			temp = nums[j];
			nums[j] = nums[i + 1];
			nums[i + 1] = temp;
			++i;
		}
	}
	return i;
}

int findK(vector<int>& nums, int k, int start, int end)
{
	if(nums.empty())
		return 0;
	if(start >= end)
		return nums[start];
	int m = partition(nums, start, end);
	if(m == k)
		return nums[m];
	else if(m < k)
		return partition(nums, m + 1, end);
	else
		return partition(nums, start, m - 1);
}

int findKthLargest(vector<int>& nums, int k)
{
	int len = nums.size();
	if(len == 0 || k <= 0 || k > len)
		return 0;

	return findK(nums, len - k, 0, len - 1);
}
*/

int findKthLargest(vector<int>& nums, int k)
{
	int len = nums.size();
	if(len == 0 || k <= 0 || k > len)
		return 0;

	int start = 0;
	int end = len - 1;
	//注意这里是非完整的快排，每次只会处理其中的一半。
	while(start < end)
	{
		int left = start;
		int right = end;
		int key = nums[left];    //快排的轴心
		//快排的思想
		while(left < right)
		{
			while(left < right && nums[right] <= key)    //这里 <= 是为了逆序排序，因为要获得第K大的元素。
				--right;
			nums[left] = nums[right];
			while(left < right && nums[left] > key)
				++left;
			nums[right] = nums[left];
		}
		nums[left] = key;
		if(left == k - 1)
			return nums[k - 1];
		else if(left > k - 1)
			end = left - 1;
		else
			start = left + 1;
	}
	return nums[k - 1];
}

int main()
{
	return 0;
}
