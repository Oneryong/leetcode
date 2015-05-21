/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/11 17:58:27
 * >File Name: string_to_integer.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Implement atoi to convert a string to an integer.
 *
 * Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
 *
 * Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.
 */

int myAtoi(string str)
{
	int result = 0;
	int tag = 1;
	int maxint = 2147483647;
	int temp;
	int count = 0;

	if(str.empty())
	{
		cout << "The string is empty..." << endl;
		return 0;
	}

	string :: iterator iter = str.begin();
	while(*iter == ' ')
	{
		iter++;
	}

	if(*iter == '-')
	{
		tag = -1;
		iter++;
	}
	else if(*iter == '+')
	{
		tag = 1;
		iter++;
	}

	while(*iter == '0')
	{
		iter++;
	}

	for(; iter < str.end(); iter++)
	{
		if(*iter >= '0' && *iter <= '9')
		{
			result = result * 10 + (*iter - '0');
			count++;
			if(iter <= (str.end() - 2))
			{
				if(count == 9)
				{
					if(result > (maxint / 10))
					{
						if(tag == 1)
							return maxint;
						if(tag == -1)
							return maxint * tag - 1;
					}
					else if(result == (maxint / 10) && *(iter + 1) > '7')
					{
						if(tag == 1)
							return maxint;
						if(tag == -1)
							return maxint * tag - 1;
					}
				}
			}
			if(count > 10)
			{
				if(tag == 1)
					return maxint;
				if(tag == -1)
					return maxint * tag - 1;
			}
		}
		else
		{
			cout << "the symbol must from 0 to 9..." << endl;
			//return 0;
			break;
		}
	}
	return result * tag;
}

int main()
{
	/*
Input:	"    010"
Output:	0
Expected:10

Input:	"     +004500"
Output:	
Expected:	4500

Input:	"    10522545459"
Output:	1932610867
Expected:	2147483647

Input:	"2147483648"
Output:	-2147483648
Expected: 2147483647

Input:	"   -1123u3761867"
Output:	-2147483648
Expected:	-1123

Input:	"-2147483647"
Output:	-2147483648
Expected: -2147483647
	 */
	//string s = "1234567";
	//string s = "+-2";
	//string s = "1";
	string s = "    +004500";
	//string s = "    10522545459";
	//string s = "2147483648";
	//string s = "   -1123u3761867";
	//string s = "-2147483647";
	int result;
	result = myAtoi(s);
	cout << "result = " << result << endl;
}
