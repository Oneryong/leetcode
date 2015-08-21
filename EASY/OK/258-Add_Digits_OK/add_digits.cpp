/*************************************************************
* >Author: zhongwanyong
* >Email:  249348626@qq.com
* >Create Time: 2015/08/18 17:41:03
* >File Name: add_digits.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.
 * For example:
 *
 * Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.
 *
 * Follow up:
 * Could you do it without any loop/recursion(循环/递归) in O(1) runtime?
 *
 * Hint:
 *
 * A naive(天真的，幼稚的) implementation of the above process is trivial(琐碎的，不重要的). Could you come up with other methods?
 * What are all the possible results?
 * How do they occur, periodically or randomly?
 * You may find this Wikipedia article useful.
 */

//simple method
/*
int addDigits(int num)
{
	if(num < 0)
		return -1;
	if(num <= 9)
		return num;
	int temp = 0;
	int result = num;
	while(result > 9)
	{
		temp = result;
		result = 0;
		while(temp)
		{
			result += (temp % 10);
			temp /= 10;
		}
	}
	return result;
}
*/

//find the rule
/*
 * input:  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25
 * output: 0 1 2 3 4 5 6 7 8 9 1  2  3  4  5  6  7  8  9  1  2  3  4  5  6  7
 */
int addDigits(int num)
{
	if(num < 0)
		return -1;
	if(num <= 9)
		return num;
	else
		return (num - 1) % 9 + 1;
}

int main()
{
	int input = 38;
	int result = addDigits(input);
	cout << "result = " << result << endl;
	return 0;
}
