/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:37:05
* >File Name: bitwise_AND_of_numbers_range.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise(按位) AND of all numbers in this range, inclusive(包含).
 *
 * For example, given the range [5, 7], you should return 4.
 */

//朴素的算法时间为O(n - m)
/*
int rangeBitwiseAnd(int m, int n)
{
	if(m > n || m < 0 || m > 2147483647 || n < 0 || n > 2147483647)
		return -1;

	int result = m;
	for(int i = m + 1; i <= n; ++i)
		result &= i;

	return result;
}
*/

int rangeBitwiseAnd(int m, int n)
{
	if(m > n || m < 0 || m > 2147483647 || n < 0 || n > 2147483647)
		return -1;

	int count = 0;
	while(m != n)
	{
		m = m >> 1;
		n = n >> 1;
		++count;
	}

	return (m << count);
}

int main()
{
	int m = 5;
	int n = 7;
	int result;
	result = rangeBitwiseAnd(m, n);
	cout << "result = " << result << endl;
	return 0;
}
