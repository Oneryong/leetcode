/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 16:54:34
* >File Name: divide_two_integers.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

/*division
 * Divide two integers without using multiplication(乘法), division(除法) and mod operator(模操作).
 *
 * If it is overflow, return MAX_INT.
 */

const int MAX_INT = 2147483647;
//const int MIN_INT = -2147483647;  //C++ 默认数据的最大值最小值对称。和ISO C90标准不一样。
const int MIN_INT = -2147483648;  //ISO C90标准的最小值。C98,C03,C11

int divide(int dividend, int divisor)
{
	if(divisor == 0)
		return MAX_INT;
	if(dividend == 0)
		return 0;

	bool flag = ((((unsigned int)dividend ^ (unsigned int)divisor) >> 31) == 1);
	int result = 0;
	int count = 0;

	if(dividend == MIN_INT)
	{
		dividend = dividend + abs(divisor);
		if(divisor == -1)
			return MAX_INT;
		++result;
	}

	if(divisor == MIN_INT)
	{
		return result;
	}

	dividend = abs(dividend);
	divisor = abs(divisor);

	if(dividend < divisor)
		result += 0;
	else if(dividend == divisor)
		result += 1;
	else
	{
		while(divisor <= (dividend >> 1))
		{
			divisor <<= 1;
			++count;
		}
		while(count >= 0)
		{
			if(dividend >= divisor)
			{
				result += (1 << count);
				dividend = dividend - divisor;
			}
			divisor >>= 1;
			--count;
		}
	}

	if(flag)
		result = -result;

	return result;
}

int main()
{
	cout << "MAX_INT = " << MAX_INT << endl;
	cout << "MIN_INT = " << MIN_INT << endl;
	int a, b;
	cout << "please intput the dividend and divisor:" << endl;
	cin >> a >> b;
	cout << "a = " << a << ", b = " << b << endl;
	int result = divide(a, b);
	cout << "result = " << result << endl;
	return 0;
}
