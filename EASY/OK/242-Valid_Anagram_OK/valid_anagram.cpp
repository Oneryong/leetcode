/*************************************************************
* >Author: zhongwanyong
* >Email:  249348626@qq.com
* >Create Time: 2015/08/07 17:33:22
* >File Name: valid_anagram.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given two strings s and t, write a function to determine if t is an anagram(易位构词，变位词) of s.
 *
 * For example,
 * s = "anagram", t = "nagaram", return true.
 * s = "rat", t = "car", return false.
 *
 * Note:
 * You may assume the string contains only lowercase alphabets.
 */

bool isAnagram(string s, string t)
{
	if(s.size() != t.size())
		return false;

	int len = s.size();
	int hashtable[26] = {0};
	int i = 0;

	for(i = 0; i < len; ++i)
	{
		++hashtable[s[i] - 'a'];
	}

	for(i = 0; i < len; ++i)
	{
		--hashtable[t[i] - 'a'];
	}

	for(i = 0; i < 26; ++i)
	{
		if(hashtable[i] != 0)
			return false;
	}

	return true;
}

int main()
{
	string s = "anagram";
	string t = "nagaram";
	bool result;
	result = isAnagram(s, t);
	cout << "result = " << result << endl;
	return 0;
}
