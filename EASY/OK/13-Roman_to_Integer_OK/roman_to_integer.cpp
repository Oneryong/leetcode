/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 17:22:20
* >File Name: roman_to_integer.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <map>

using namespace std;

/*
 * Given a roman numeral, convert it to an integer.
 *
 * Input is guaranteed to be within the range from 1 to 3999.
 */

int romanToInt(string s)
{
	int result;
	map<char, int> roman;
	roman['I'] = 1;
	roman['V'] = 5;
	roman['X'] = 10;
	roman['L'] = 50;
	roman['C'] = 100;
	roman['D'] = 500;
	roman['M'] = 1000;

	int size = s.size();
	if(size == 0)
		return 0;
	if(size == 1)
		return roman[*(s.begin())];

	int light = 0;    //the tag for light -
	//int right = 0;    //the tag for right +
	int same = 0;
	
	string :: iterator iter = s.end() - 1;
	result = roman[*iter];
	for(; iter > s.begin(); iter--)
	{
		if(roman[*iter] > roman[*(iter - 1)])
		{
			if(light == 1)
				return 0;
			if(*(iter - 1) != 'I' && *(iter - 1) != 'X' && *(iter - 1) != 'C')
				return 0;
			result = result - roman[*(iter - 1)];
			light++;
			//right = 0;
			same = 0;
		}
		else if(roman[*iter] == roman[*(iter - 1)])
		{
			if(same == 3)
				return 0;
			result = result + roman[*(iter - 1)];
			same++;
			//right++;
			light = 0;
		}
		else
		{
			//if(right == 4)
			//	return 0;
			result = result + roman[*(iter - 1)];
			//right++;
			light = 0;
			same = 0;
		}
	}

	return result;
}

int main()
{
/*
Input:	"DCXXI"
Output:	0
Expected: 621
*/
	int result;
	//string s = "XCIX";
	//string s = "";
	//string s = "X";
	//string s = "XIIII";
	//string s = "LD";
	string s = "DCXXI";
	cout << "string = " << s << endl; 
	result = romanToInt(s);
	cout << "result = " << result << endl;
	return 0;
}
