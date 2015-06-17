/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 18:19:28
* >File Name: reverse_bits.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <bitset>

using namespace std;

/*
 * Reverse bits of a given 32 bits unsigned integer.
 *
 * For example, given input 43261596 (represented in binary as 00000010100101000001111010011100), return 964176192 (represented in binary as 00111001011110000010100101000000).
 *
 * Follow up:
 * If this function is called many times, how would you optimize it?
 *
 * Related problem: Reverse Integer
 */

unsigned int reverseBits(unsigned int n)
{
	bitset<32> input = n;
	bitset<1> temp;
	int i, j;
	for(i = 0, j = 31; i < j; i++, j--)
	{
		temp[0] = input[i];
		input[i] = input[j];
		input[j] = temp[0];
	}

	return (int)(input.to_ulong());
}

int main()
{
	unsigned int result;
	unsigned int n = 43261596;
	cout << "n = " << n << endl;
	result = reverseBits(n);
	cout << "result = " << result << endl;
	return 0;
}
