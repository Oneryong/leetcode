/*
 * Given an array and a value, remove all instances of that value in place and return the new length.
 *
 * The order of elements can be changed. It doesn't matter what you leave beyond the new length. 
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int removeElement(int A[], int n, int elem) 
{
	int i;
	int count = n;
	for(i = 0; i < count; i++)
	{
		if(A[i] == elem)
		{
			if(A[count - 1] != elem)
			{
				A[i] = A[count-1];
				count--;
			}
			else
			{
				count--;
				i--;
			}
		}
	}
	return count;
}

int main()
{
	int A[5] = {1, 4, 2, 4, 4};
	int i, num;
	num = removeElement(A, 5, 4);
	for(i = 0; i < num; i++)
	{
		printf("A[%d] = %d\n", i, A[i]);
	}
	return 0;
}
