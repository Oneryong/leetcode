/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:23:29
* >File Name: integertoroman.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <map>

using namespace std;

/*
 * Given an integer, convert it to a roman numeral.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

/*
 * I:1
 * V:5
 * X:10
 * L:50
 * C:100
 * D:500
 * M:1000
 */

string intToRoman(int num)
{
	string result;
	if(num < 1)
		return result;

	map<int, char> hashtable;
	hashtable[1] = 'I';
	hashtable[5] = 'V';
	hashtable[10] = 'X';
	hashtable[50] = 'L';
	hashtable[100] = 'C';
	hashtable[500] = 'D';
	hashtable[1000] = 'M';
	int array[7] = {1000, 500, 100, 50, 10, 5, 1};

	int count;    //个数
	int temp;     //余数

	for(int i = 0; i < 7; ++i)
	{
		count = num / array[i];
		temp = num % array[i];
		if(count != 0)
		{
			result.insert(result.end(), count, hashtable[array[i]]);
		}
		
		if(array[i] == 1000 || array[i] == 500)
		{
			if(temp >= array[i] - 100)
			{
				result.insert(result.end(), 'C');
				result.insert(result.end(), hashtable[array[i]]);
				temp = temp - (array[i] - 100);
			}
		}
		else if(array[i] == 100 || array[i] == 50)
		{
			if(temp >= array[i] - 10)
			{
				result.insert(result.end(), 'X');
				result.insert(result.end(), hashtable[array[i]]);
				temp = temp - (array[i] - 10);
			}
		}
		else if(array[i] == 10 || array[i] == 5)
		{
			if(temp >= array[i] - 1)
			{
				result.insert(result.end(), 'I');
				result.insert(result.end(), hashtable[array[i]]);
				temp = temp - (array[i] - 1);
			}
		}
		
		num = temp;
	}

	return result;
}

int main()
{
	int num = 95;
	string result;
	cout << "num = " << num << endl;
	result = intToRoman(num);
	cout << "result = " << result << endl;
	return 0;
}
