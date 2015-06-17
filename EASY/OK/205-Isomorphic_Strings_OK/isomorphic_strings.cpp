/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:22:33
* >File Name: isomorphic_strings.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given two strings s and t, determine if they are isomorphic(同构的，同型的).
 *
 * Two strings are isomorphic if the characters in s can be replaced to get t.
 *
 * All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
 *
 * For example,
 * Given "egg", "add", return true.
 *
 * Given "foo", "bar", return false.
 *
 * Given "paper", "title", return true.
 *
 * Note:
 * You may assume both s and t have the same length.
 */

/*
 * 我们遍历原字符串，分别从源字符串和目标字符串取出一个字符，然后分别在两个哈希表中查找其值，若不相等，则返回false，若想等，将其值更新为i + 1。
 */

bool isIsomorphic(string s, string t)
{
	int size1 = s.size();
	int size2 = t.size();
	
	if(size1 != size2)
		return false;

	int flag1[256] = {0};
	int flag2[256] = {0};
	for(int i = 0; i < size1; ++i)
	{
		if(flag1[s[i]] != flag2[t[i]])
			return false;

		flag1[s[i]] = i + 1;
		flag2[t[i]] = i + 1;
	}

	return true;
}

int main(int argc, char** argv)
{
	string s = argv[1];
	string t = argv[2];
	cout << "s = " << s << endl;
	cout << "t = " << t << endl;
	bool result;
	result = isIsomorphic(s, t);
	cout << "result = " << result << endl;
	return 0;
}
