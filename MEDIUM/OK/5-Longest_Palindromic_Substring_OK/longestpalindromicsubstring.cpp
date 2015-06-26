/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:19:37
* >File Name: longestpalindromicsubstring.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 */


//方法一：使用动态规划的思想
//时间O(n * n), 空间O(n * n)
//dp[i][j]表示从i到j的字符串是否是为回文串
/*
string longestPalindrome(string s)
{
	string result;
	int len = s.size();
	if(len == 0)
		return result;
	if(len == 1)
		return s;

	bool dp[len][len];
	int i, j;
	for(i = 0; i < len; ++i)
	{
		for(j = 0; j < len; ++j)
		{
			if(i >= j)
				dp[i][j] = true;
			else
				dp[i][j] = false;
		}
	}

	int maxlen = 1;
	int left, right;
	for(i = 1; i < len; ++i)  //the length of palindromic substring
	{
		for(j = 0; j + i < len; ++j)
		{
			if(s[j] != s[j + i])
				dp[j][j + i] = false;
			else
			{
				dp[j][j + i] = dp[j + 1][j + i - 1];
				if(dp[j][j + i])
				{
					if(i + 1 > maxlen)
					{
						maxlen = i + 1;
						left = j;
						right = j + i;
					}
				}
			}
		}
	}

	for(i = left; i <= right; ++i)
	{
		result.insert(result.end(), s[i]);
	}
	return result;
}
*/

//方法二：使用KMP方法，将s翻转之后得s'，求s和s'的最长公共子串。
//时间：O(n * n),空间：O(n)

//方法三：Manacher算法
//每次以一个点为对称点去查找以这个点为中心的回文长度，并记录下来。
//时间复杂度O(n), 空间复杂度O(n)
//该算法首先对字符串进行预处理，在字符串的每个字符前后都加入一个特殊符号，比如字符串 abcd 处理成 #a#b#c#d#,为了避免处理越界，在字符串首尾加上不同的两个特殊字符(c类型的字符串尾部不用加，因为自带‘\0’)，这样预处理后最终变成$#a#b#c#d#^，经过这样处理后有个好处是原来的偶数长度和奇数长度的回文在处理后的字符串中都是奇数长度

string handle(string s)
{
	int len = s.size();
	string result;
	
	result.push_back('$');
	result.push_back('#');
	for(int i = 0; i < len; ++i)
	{
		result.push_back(s[i]);
		result.push_back('#');
	}
	result.push_back('^');
	
	return result;
}

string longestPalindrome(string s)
{
	string result;
	int len = s.size();
	if(len == 0)
		return result;
	if(len == 1)
		return s;

	string temp = handle(s);
	len = temp.size();
	vector<int> p(len, 0);    //store the len of center i(1 <= i <= len - 1)
	int max = 0;
	int min = 0;
	int center = 0;
	int i;

	for(i = 1; i < len; ++i)
	{
		min = (p[2 * center - i] < (max - i)) ? p[2 * center - i] : (max - i);
		p[i] = (max > i) ? min : 1;

		while(temp[i + p[i]] == temp[i - p[i]])
			++p[i];

		if(i + p[i] > max)
		{
			max = i + p[i];
			center = i;
		}
	}

	int maxlen = 0;
	int index = 0;
	for(i = 1; i < len; ++i)
	{
		if(p[i] > maxlen)
		{
			maxlen = p[i];
			index = i;
		}
	}
	center = (index - maxlen) / 2;
	
	for(i = center; i < center + maxlen - 1; ++i)
	{
		result.insert(result.end(), s[i]);
	}

	return result;
}

int main()
{
	string s = "aabcdcba";
	string result;
	cout << "s = " << s << endl;
	result = longestPalindrome(s);
	cout << "result = " << result << endl;
	return 0;
}
