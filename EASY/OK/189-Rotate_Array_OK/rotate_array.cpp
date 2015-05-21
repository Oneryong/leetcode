/********************************************************
* 
* Author: zhongwanyong
* Email:  zwy249348626@163.com
* Create Time: 2015/04/29 15:23:20
* File Name: rotate_array.cpp
* Description: 
*
********************************************************/

#include <iostream>

using namespace std;

/*
 * Rotate an array of n elements to the right by k steps.

 * For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

 *Note:
    Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

 *[show hint]
    Related problem: Reverse Words in a String II
 */
void rotate(int nums[], int n, int k)
{
	int temp[k];
	int i;

	if(k > n)
		//exit(0);
		k = k % n;

	for(i = 0; i < k; i++)
	{
		temp[i] = nums[n - k + i];
	}

	for(i = n - 1; i >= k; i--)
	{
		nums[i] = nums[i - k];
	}

	for(i = 0; i < k; i++)
	{
		nums[i] = temp[i];
	}
}

int main()
{
	int array[7] = {1, 2, 3, 4, 5, 6, 7};
	int j;
	for(j = 0; j < 7; j++)
		cout << array[j] << " ";
	cout << endl;
	rotate(array, 7, 8);
	for(j = 0; j < 7; j++)
		cout << array[j] << " ";
	cout << endl;
	return 0;
}
