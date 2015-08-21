/*************************************************************
* >Author: zhongwanyong
* >Email:  249348626@qq.com
* >Create Time: 2015/08/19 14:38:45
* >File Name: ugly_number2.cpp
* >Description: 
*************************************************************/


/*
 * Ugly numbers are positive(正的，积极的) numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
 *
 * Write a program to find the n-th ugly number.
 *
 * Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
 *
 * Note that 1 is typically treated as an ugly number.
 *
 * Hint:
 *
 * The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
 * An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
 * The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
 * Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
 */

/*
//用来判断一个数是不是丑数
bool isUgly(int num)
{
	if(num <= 0)
		return false;

	while(num % 2 == 0)
		num /= 2;
	while(num % 3 == 0)
		num /= 3;
	while(num % 5 == 0)
		num /= 5;

	return (num == 1) ? true : false;
}
*/

//get the min number from three numbers
int getMin(int a, int b, int c)
{
	int result = (a < b) ? a : b;
	result = (result < c) ? result : c;
	return result;
}

//利用按顺序存储丑数，使用动态规划的思想。
int nthUglyNumber(int n)
{
	if(n <= 0)
		return -1;

	int ugly[n];
	ugly[0] = 1;
	int index = 1;
	int min = 0;
	
	int* p2 = ugly;
	int* p3 = ugly;
	int* p5 = ugly;
	
	while(index < n)
	{
		min = getMin((*p2) * 2, (*p3) * 3, (*p5) * 5);
		ugly[index] = min;

		while((*p2) * 2 <= ugly[index])
			++p2;
		while((*p3) * 3 <= ugly[index])
			++p3;
		while((*p5) * 5 <= ugly[index])
			++p5;

		++index;
	}

	return ugly[index - 1];
}

int main()
{
	return 0;
}
