/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/09 17:12:16
 * >File Name: excel_sheet_tree_iterator.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Related to question Excel Sheet Column Title
 *
 * Given a column title as appear in an Excel sheet, return its corresponding column number.
 *
 * For example:
 *
 * A -> 1
 * B -> 2
 * C -> 3
 * ...
 * Z -> 26
 * AA -> 27
 * AB -> 28 
 */

int titleToNumber(string s)
{
	if(s.empty())
		return 0;

	int result = 0;
	string :: iterator iter = s.begin();

	for(; iter < s.end(); iter++)
	{
		if(*iter < 'A' || *iter > 'Z')
			return 0;
		else
		{
			result = (result * 26) + (*iter - 'A' + 1);	
		}
	}

	return result;
}

int main()
{
	int result;
	string s = "AAA";
	cout << "s = " << s << endl;
	result = titleToNumber(s);
	cout << "result = " << result << endl;
	return 0;
}
