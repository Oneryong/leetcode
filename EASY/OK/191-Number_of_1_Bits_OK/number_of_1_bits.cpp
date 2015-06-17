/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 18:21:26
* >File Name: number_of_1_bits.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <bitset>

using namespace std;

/*
 *  Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).
 *
 * For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3
 */

int hammingWeight(unsigned int n)
{
	bitset<32> input = n;
	return input.count();
}

int main(int argc, char** argv)
{
	int result;
	int n = 11;
	result = hammingWeight(n);
	cout << "result = " << result << endl;
	return 0;
}
