/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 15:27:31
 * >File Name: print_primes.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <cmath>

using namespace std;

/*
 * 时间限制 1000 ms 内存限制 32768 KB 代码长度限制 100 KB 判断程序 Standard (来自 小小)
 * 题目描述
 * 令Pi表示第i个素数。现任给两个正整数M <= N <= 10000，请输出PM到PN的所有素数。
 *
 * 输入描述:
 * 输入在一行中给出M和N，其间以空格分隔。
 *
 *
 * 输出描述:
 * 输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。
 *
 * 输入例子:
 * 5 27
 *
 * 输出例子:
 * 11 13 17 19 23 29 31 37 41 43
 * 47 53 59 61 67 71 73 79 83 89
 * 97 101 103
 */

bool isPrime(int num)
{
	bool flag = true;

	int i, j;
	j = pow(num, 0.5);
	for(i = 2; i <= j; ++i)
	{
		if(num % i == 0)
		{
			flag = false;
			return flag;
		}
	}
	return flag;
}

void PrintPrime(int m, int n)
{
	if(m < 1 || n < 1 || m > n || m > 10000 || n > 10000)
		return;

	int count = 0;
	int i = 2;
	int j = 0;

	for(i = 2; count < n; i++)
	{
		if(isPrime(i))
		{
			++count;
			if(count >= m)
			{
				++j;
				if(j > 10)
				{
					j = 1;  
					cout << endl;
				}
				cout << i;
				if(j < 10 && count != n)
					cout << " ";
			}
		}
	}
}

int main()
{
	int m, n;
	cout << "please input m and n: " << endl;
	cin >> m;
	cin >> n;
	PrintPrime(m, n);
	return 0;
}
