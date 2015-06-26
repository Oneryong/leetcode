/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:18:24
* >File Name: count_primes.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

/*
 * Description:
 *
 * Count the number of prime numbers(素数，质数) less than a non-negative number, n
 */

int countPrimes(int n)
{
	if(n < 2)
		return 0;

	bool table[n];
	memset(table, true, n);
	table[0] = false;
	table[1] = false;

	int count = n - 2;
	int times = pow(n, 0.5);
	
	int i, j;
	for(i = 2; i <= times; ++i)
	{
		for(j = 2; (j * i) < n; ++j)
		{
			if(table[j * i] == true)
			{
				table[j * i] = false;
				--count;
			}
		}
	}

	return count;
}

int main()
{
	int n = 2000000;
	int result;
	result = countPrimes(n);
	cout << "result = " << result << endl;
	return 0;
}
