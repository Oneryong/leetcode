/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 18:16:05
* >File Name: factorial_trailing_zeroes.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given an integer n, return the number of trailing zeroes in n!.
 *
 * Note: Your solution should be in logarithmic time complexity.
 */

int trailingZeroes(int n)
{
	int result = 0;
	while(n)
	{
		result += (n / 5);
		n /= 5;
	}
	return result;
}

int main(int argc, char** argv)
{
	int n = 5;
	int result;
	result = trailingZeroes(n);
	cout << "result = " << result << endl;
	return 0;
}
