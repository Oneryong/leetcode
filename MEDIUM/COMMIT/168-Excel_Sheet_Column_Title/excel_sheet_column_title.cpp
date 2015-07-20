/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 10:47:05
* >File Name: excel_sheet_column_title.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given a positive integer, return its corresponding column title as appear in an Excel sheet.
 *
 * For example:
 *
 * 1 -> A
 * 2 -> B
 * 3 -> C
 * ...
 * 26 -> Z
 * 27 -> AA
 * 28 -> AB 
 */

string convertToTitle(int n)
{
	string result;
	if(n <= 0)
		return NULL;

	int temp;
	while(n)
	{
		temp = n % 26;
		if(temp == 0)
			result.insert(result.begin(), 'Z');
		else
			result.insert(result.begin(), temp - 1 + 'A');

		n /= 27;
	}

	return result;
}

int main()
{
	int n = 27;
	string result;
	result = convertToTitle(n);
	cout << "result = " << result << endl;
	return 0;
}
