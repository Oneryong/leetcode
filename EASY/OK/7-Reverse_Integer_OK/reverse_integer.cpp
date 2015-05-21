/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/11 17:54:17
 * >File Name: reverse_integer.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Reverse digits of an integer.
 *
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 * //Have you thought about this?
 * //Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
 * //
 * //If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
 * //
 * //Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
 * //
 * //For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
 */

/*
 * 2^31 - 1 = 2147483647
 * 2^32 - 1 = 4294967295
 */
int reverse(int x)
{
	int max = 2147483647;
	if(x == 0)
		return 0;

	int tag;
	if(x < 0)
	{
		x = -x;
		tag = -1;
	}
	else
		tag = 1;
	
	int result = 0;
	if(x > 1000000000)
	{
		int base = 1000000000;
		while(x > 0)
		{
			result = result * 10 + (x % 10);
			if(result > max / base)
				return 0;
			else
				base = base / 10;
			x = x / 10;
		}
	}
	else
	{
		while(x > 0)
		{
			result = result * 10 + (x % 10);
			x = x / 10;
		}

	}

	result = result * tag;
	return result;
}

int main()
{
	/*
Input:	-2147483412
Output:	0
Expected: -2143847412

Input:	1534236469
Output:	
Expected: 0

Input:	1563847412
Output:	-2147483645
Expected: 0
	 */
	int result;
	//int x = -2147483412;
	int x = 1534236469;
	//int x = 1563847412;
	cout << "x = " << x << endl;
	result = reverse(x);
	cout << "result = " << result << endl;
	return 0;
}
