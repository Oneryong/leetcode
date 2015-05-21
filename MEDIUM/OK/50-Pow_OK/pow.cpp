/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/21 11:14:18
* >File Name: pow.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Implement pow(x, n).
 */
bool equal(double a, double b);
double Power1(double x, int n);
double Power2(double x, int n);

double myPow(double x, int n)
{
	double result;
	int tag = 0;

	//(* / 0) is error
	if(equal(x, 0.0) && n < 0)
		return 0;
	
	//if n < 0, return (1 / result).
	if(n < 0)
	{
		n = -n;
		tag = 1;
	}

	result = Power2(x, n);

	if(tag == 1)
		return 1 / result;
	else
		return result;
}

double Power1(double x, int n)
{
	double result = 1.0;
	while(n)
	{
		result = result * x;
		n--;
	}
	return result;
}

double Power2(double x, int n)
{
	double result;

	if(n == 0)
		return 1;
	if(n == 1)
		return x;

	result = myPow(x, n >> 1);
	result = result * result;
	if((n & 0x1) == 1)
		result = result * x;

	return result;
}

bool equal(double a, double b)
{
	if((a - b > -0.0000001) && (a - b < 0.0000001))
		return true;
	else
		return false;
}

int main()
{
/*
Input:	8.88023, 3
Output:	8.88023
Expected: 700.28148

Time Limit Exceeded
Last executed input: 0.00001, 2147483647 
 */
	int n = 3;
	double x = 8.88023;
	cout << "x = " << x << endl;
	cout << "n = " << n << endl;
	double result;
	result = myPow(x, n);
	cout << "result = " << result << endl;
	return 0;
}
