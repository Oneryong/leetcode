/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/15 10:55:07
* >File Name: implement_str.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Implement strStr().

 * Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
 */

int strStr(string haystack, string needle)
{
	int index = 0;
	int size1 = needle.size();
	int size2 = haystack.size();
	
	if(size1 > size2)
		return -1;
	
	if(size1 == 0 || size2 == 0)
		return 0;

	int i, j;
	for(i = 0; i <= size2 - size1; i++)
	{
		if(haystack[i] == needle[0])
		{
			index = i;
			for(j = 1; j < size1; j++)
			{
				if(needle[j] != haystack[i + j])
					break;
			}
			if(j == size1)
				return index;
		}
	}

	return -1;
}

int main()
{
/*
Input:	"", ""
Output:	-1
Expected: 0
 */
	int index;
	string s1 = "abcd";
	string s2 = "";
	cout << "s1 = " << s1 << endl;
	cout << "s2 = " << s2 << endl;
	index = strStr(s1, s2);
	cout << "index = " << index << endl;
	return 0;
}
