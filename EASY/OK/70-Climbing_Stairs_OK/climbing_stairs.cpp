/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/19 11:37:17
* >File Name: climbing_stairs.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * You are climbing a stair case. It takes n steps to reach to the top.
 *
 * Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
 */

/*
int climbStairs(int n)
{
	int result[2] = {0, 1};
	if(n < 2)
		return result[n];

	return climbStairs(n - 1) + climbStairs(n - 2);
}
*/

int climbStairs(int n)
{
	int result;
	int temp[3] = {0, 1, 2};
	if(n < 3)
		return temp[n];

	for(int i = 3; i <= n; i++)
	{
		result = temp[2] + temp[1];
		temp[1] = temp[2];
		temp[2] = result;
	}

	return result;
}

int main()
{
	int n = 2;
	int result;
	cout << "n = " << n << endl;
	result = climbStairs(n);
	cout << "result = " << result << endl;
	return 0;
}
