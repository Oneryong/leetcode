/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:17:33
* >File Name: longestsubstring.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
 */

int lengthOfLongestSubstring(string s)
{
	if(s.empty())
		return 0;

	int count = 0;
	int hashtable[256] = {0};
	int len = s.size(); 
	int i = 0;
	int j = 0;
	

	while(i < len)
	{
		if(hashtable[s[i]] != 0)
		{
			if((i - j) > count)
				count = i - j;
			for(; j < hashtable[s[i]]; ++j)
			{
				hashtable[s[j]] = 0;
			}
		}
		else
		{
			hashtable[s[i]] = i + 1;
			++i;
		}
	}
	if((i - j) > count)
		count = i - j;

	return count;
}

int main()
{
/*
input = "aab"
output = 2
 */
	string s = "abcabcbb";
	//string s = "aab";
	int result;
	result = lengthOfLongestSubstring(s);
	cout << "result = " << result << endl;
	return 0;
}
