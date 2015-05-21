/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 14:47:33
* >File Name: add_binary.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * Given two binary strings, return their sum (also a binary string).

 * For example,
 * a = "11"
 * b = "1"
 * Return "100". 
 */

string addBinary(string a, string b)
{
	string result;
	int size = a.size() > b.size() ? a.size() : b.size();
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	int gobit = 0;

	for(int i = 0; i < size; i++)
	{
		int ai = i < a.size() ? (a[i] - '0') : 0;
		int bi = i < b.size() ? (b[i] - '0') : 0;
		int count = (ai + bi + gobit) % 2;
		gobit = (ai + bi + gobit) / 2;
		result.insert(result.begin(), count + '0');
	}
	if(gobit == 1)
		result.insert(result.begin(), '1');

	return result;
}

int main()
{
	string a = "11";
	string b = "1";
	string result;
	result = addBinary(a, b);
	cout << "result =" << result << endl;
}
