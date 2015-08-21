/*************************************************************
 * >Author: zhongwanyong
 * >Email:  249348626@qq.com
 * >Create Time: 2015/08/21 11:33:28
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
 *  1 -> A
 *  2 -> B
 *  3 -> C
 *  ...
 *  26 -> Z
 *  27 -> AA
 *  28 -> AB
 */

string convertToTitle(int n)
{
	string result;
	if(n <= 0)
		return result;
	
	char table[26];
	table[0] = 'Z';
	int i = 0;
	for(i = 1; i < 26; ++i)
	{
		table[i] = (i - 1) + 'A';
	}

	int temp = 0;
	while(n)
	{
		temp = n % 26;
		result.insert(result.begin(), table[temp]);
		n /= 26;
		if(temp == 0)
			--n;
	}

	return result;
}

int main()
{
	return 0;
}
