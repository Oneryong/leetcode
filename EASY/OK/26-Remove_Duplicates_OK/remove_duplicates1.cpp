/*
 * Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

 * Do not allocate extra space for another array, you must do this in place with constant memory.

 * For example,
 Given input array A = [1,1,2],

 * Your function should return length = 2, and A is now [1,2].
 */
#include <stdio.h>

int removeDuplicates(int A[], int n)
{
	int count = 0;
	if(n <= 1)
	{
		count = n;
		return count;
	}
	int i;
	for(i = 1; i < n; i++)
	{
		if(A[i - 1] != A[i])
		{
			count++;
			A[count] = A[i];
		}
	}
	return count + 1;
}

int main()
{
	int A[0] = {};
	int len;
	len = removeDuplicates(A, 0);
	printf("len = %d\n", len);
	printf("result = ");
	int j;
	for(j = 0; j < len; j++)
	{
		printf(" %d", A[j]);
	}
	printf("\n");
	return 0;
}
