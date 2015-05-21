/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/09 19:17:31
* >File Name: merge_sorted_array.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given two sorted integer arrays A and B, merge B into A as one sorted array.
 *
 * Note:
 * You may assume that A has enough space (size that is greater or equal to m + n) to hold additional elements from B. The number of elements initialized in A and B are m and n respectively.
 */



//this method is not the best, the best method don't use extral space, and the time is O(n)
void merge(int A[], int m, int B[], int n)
{
	int C[m];
	for(int num = 0; num < m; num++)
	{
		C[num] = A[num];
	}
	int i = 0, j = 0, k = 0;
	for(k = 0; k < m + n; k++)
	{
		if((i != m) && (j != n))
		{
			if(C[i] <= B[j])
			{
				A[k] = C[i];
				i++;
			}
			else
			{
				A[k] = B[j];
				j++;
			}
		}
		else if(i == m)
		{
			A[k] = B[j];
			j++;
		}
		else
		{
			A[k] = C[i];
			i++;
		}
	}
}

int main()
{
	int A[8] = {1, 3, 3, 5, 0, 0, 0, 0};
	int B[4] = {2, 2, 3, 4};
	//int len1 = sizeof(A) / sizeof(A[0]);
	//cout << "len1 = " << len1 <<endl;
	merge(A , 4, B, 4);
	cout << "A = ";
	for(int i = 0; i < 8; i++)
	{
		cout << " " << A[i];
	}
	cout << endl;
	return 0;
}
