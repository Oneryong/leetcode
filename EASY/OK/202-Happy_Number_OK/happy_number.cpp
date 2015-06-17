/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:06:26
* >File Name: happy_number.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <set>

using namespace std;

/*
 * Write an algorithm to determine if a number is "happy".
 *
 * A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares(平方) of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
 *
 * Example: 19 is a happy number
 *
 * 1^2 + 9^2 = 82
 * 8^2 + 2^2 = 68
 * 6^2 + 8^2 = 100
 * 1^2 + 0^2 + 0^2 = 1
 */

bool isHappy(int n)
{
	int temp1 = 0;
	int temp2 = 0;
	set<int> table;
	table.insert(n);

	while(true)
	{
		while(n != 0)
		{
			temp1 = n % 10;
			temp2 += temp1 * temp1;
			n /= 10;
		}
		n = temp2;
		if(n == 1)
			return true;

		if(table.count(n))
			return false;
		else
			table.insert(n);
		temp2 = 0;
	}
}

int main()
{
	return 0;
}
