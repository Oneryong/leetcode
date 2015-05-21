/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/11 15:44:17
 * >File Name: multiply_strings.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

/*
 * Given two numbers represented as strings, return multiplication of the numbers as a string.
 *
 * Note: The numbers can be arbitrarily large and are non-negative.
 */

string addstring(string a, string b)
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
		int count = (ai + bi + gobit) % 10;
		gobit = (ai + bi + gobit) / 10;
		result.insert(result.begin(), count + '0');
	}   
	if(gobit != 0)
		result.insert(result.begin(), gobit + '0');

	return result;
}


string multiply(string num1, string num2) 
{
	if((num1[0] - '0') == 0)
		return num1;
	if((num2[0] - '0') == 0)
		return num2;
	
	string result;
	string resulttemp;
	int size1 = num1.size();
	int size2 = num2.size();
	
	reverse(num1.begin(), num1.end());
	reverse(num2.begin(), num2.end());

	int gobit, temp1, temp2, count;

	for(int i = 0; i < size2; i++)
	{
		gobit = 0;
		temp1 = num2[i] - '0';
		resulttemp.clear();

		for(int j = 0; j < size1; j++)
		{
			temp2 = num1[j] - '0';
			count = (temp1 * temp2 + gobit) % 10;
			gobit = (temp1 * temp2 + gobit) / 10;
			resulttemp.insert(resulttemp.begin(), count + '0');
		}
		if(gobit != 0)
			resulttemp.insert(resulttemp.begin(), gobit + '0');
		
		for(int k = 0; k < i; k++)
		{
			resulttemp.insert(resulttemp.end(), '0');
		}

		result = addstring(result, resulttemp);
	}
	return result;
}

int main()
{
	string s1, s2, result1, result2;
	s1 = "9113";
	s2 = "0";
	result2 = multiply(s1, s2);
	//result1 = addstring(s1, s2);
	cout << "result2= " << result2 << endl; 
	//cout << "result1= " << result1 << endl; 
	return 0;
}
