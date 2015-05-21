/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 17:26:22
* >File Name: compare_version_numbers.cpp
* >Description: 
*************************************************************/


#include <iostream>
#include <string>

using namespace std;

/*
 * Compare two version numbers version1 and version2.
 * If version1 > version2 return 1, if version1 < version2 return -1, otherwise return 0.
 *
 * You may assume that the version strings are non-empty and contain only digits and the . character.
 * The . character does not represent a decimal point and is used to separate number sequences.
 * For instance, 2.5 is not "two and a half" or "half way to version three", it is the fifth second-level revision of the second first-level revision.
 *
 * Here is an example of version numbers ordering:
 *
 * 0.1 < 1.1 < 1.2 < 13.37
 */

int compareVersion(string version1, string version2)
{
	int v1 = 0;
	int v2 = 0;
	string :: iterator iter1 = version1.begin();
	string :: iterator iter11 = version1.end();
	string :: iterator iter2 = version2.begin();
	string :: iterator iter22 = version2.end();

	while(1)
	{
		while(*iter1 != '.' && iter1 < iter11)
		{
			v1 = v1 * 10 + (*iter1 - '0');
			iter1++;
		}

		while(*iter2 != '.' && iter2 < iter22)
		{
			v2 = v2 * 10 + (*iter2 - '0');
			iter2++;
		}

		cout << "v1 = " << v1 << endl;
		cout << "v2 = " << v2 << endl;
		if(v1 > v2)
			return 1;
		else if(v1 < v2)
			return -1;
		else
		{
			if(iter1 == iter11 && iter2 == iter22)
				return 0;
			else if(iter1 == iter11 && iter2 != iter22)
			{
				while(iter2 + 1 < iter22)
				{
					if(*(iter2 + 1) != '0' && *(iter2 + 1) != '.')
						return -1;
					iter2++;
				}
					return 0;
			}
			else if(iter1 != iter11 && iter2 == iter22)
			{
				while(iter1 + 1 < iter11)
				{
					if(*(iter1 + 1) != '0' && *(iter1 + 1) != '.')
						return 1;
					iter1++;
				}
				return 0;
			}
			else
			{
				iter1++;
				iter2++;
				v1 = 0;
				v2 = 0;
			}
		}
	}
}

int main()
{
/*
Input:	"1.0", "1"
Output:	1
Expected: 0
 */
	string s1 = "1.0";
	string s2 = "1";
	int result;
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	result = compareVersion(s1, s2);
	cout << "result = " << result << endl;
}
