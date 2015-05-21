/*
 * Follow up for "Remove Duplicates":

 * What if duplicates are allowed at most twice?

 * For example,

 * Given sorted array A = [1,1,1,2,2,3],

 * Your function should return length = 5, and A is now [1,1,2,2,3].
 */

#include <stdio.h>

int removeDuplicates(int A[], int n)
{
	int count = 0;
	if(n <= 2)
	{
		count = n;
		return count;
	}
	int i;
	int tag = 1;
	for(i = 1; i < n; i++)
	{
		if(A[i - 1] == A[i])
		{
			tag++;
		}
		else
		{
			if(tag == 1)
			{
				count += 1;
				A[count] = A[i];
				tag = 1;
			}
			else
			{
				count += 2;
				A[count - 1] = A[i - 1];
				A[count] = A[i];
				tag = 1;
			}
		}
	}
	if(tag != 1)
	{
		count += 1;
		A[count] = A[i - 1];
		tag = 1;
	}
	return count + 1;
}

int main()
{
	int A[4] = {2, 1, 1, 1};
	int len;
	len = removeDuplicates(A, 4);
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
