/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/19 20:17:33
 * >File Name: power_of_two.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given an integer, write a function to determine if it is a power of two.
 */

bool isPowerOfTwo(int n)
{
	if(n <= 0)
		return false;
	if(n == 1)
		return true;

	while(n > 1)
	{
		if(n & 0x1 == 1)
			return false;
		n >>= 1;
	}

	return true;
}

int main()
{
	return 0;
}
