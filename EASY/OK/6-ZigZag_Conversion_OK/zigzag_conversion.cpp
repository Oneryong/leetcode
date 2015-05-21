/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 17:50:47
* >File Name: zigzag_conversion.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
 *
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * string convert(string text, int nRows);
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 */

/*
 * Zigzag description:
 * numRows = 1
 *     . . . . .
 * numRows = 2
 *     . . . . .
 *     . . . . .
 * numRows = 3
 *     .   .   .
 *     . . . . .
 *     .   .   .
 * numRows = 4
 *     .     .     .
 *     .   . .   . .
 *     . .   . .   .
 *     .     .     .
 */



string convert(string s, int numRows)
{
	string lastresult;
	string result[numRows];
	int base;
	int choice;

	if(numRows < 1)
	{
		cout << "the numRows is wrong..." << endl;
		exit(0);
	}

	if(numRows == 1)
		base = 1;
	else
		base = 2 * numRows - 2;

	for(int i = 0; i < s.size(); i++)
	{
		choice = i % base;
		if(choice >= numRows)
		{
			choice = 2 * numRows - choice - 2;
		}

		result[choice].insert(result[choice].end(), s[i]);
	}
	lastresult = result[0];
	for(int j = 1; j < numRows; j++)
		lastresult = lastresult + result[j];
	
	return lastresult;
}

int main()
{
	string str = "PAYPALISHIRING";
	//string str = "ABC";
	cout << "str = " << str << endl;
	string result;
	result = convert(str, 3);
	cout << "result = " << result << endl;
	return 0;
}
