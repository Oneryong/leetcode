/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/22 12:40:12
* >File Name: valid_palindrome.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*
 * Given a string, determine if it is a palindrome, considering only alphanumeric(字母数字的) characters and ignoring cases.
 *
 * For example,
 * "A man, a plan, a canal: Panama" is a palindrome.
 * "race a car" is not a palindrome.
 *
 * Note:
 * Have you consider that the string might be empty? This is a good question to ask during an interview.
 *
 * For the purpose of this problem, we define empty string as valid palindrome.
 */

/*
 * cctype:
 * isalnum() 是否为字母或数字
 * issupper() 是否为大写字母
 * tolower() 将大写字母转换为小写字母
 */

bool isPalindrome(string s)
{
	if(s.empty())
		return true;

	string :: iterator iter1 = s.begin();
	string :: iterator iter2 = s.end();
	while(iter1 < iter2)
	{
		while(iter1 < iter2 && !isalnum(*iter1))
			++iter1;
		while(iter1 < iter2 && !isalnum(*iter2))
			--iter2;

		if(tolower(*iter1) != tolower(*iter2))
			return false;
		
		++iter1;
		--iter2;
	}

	return true;
}

int main()
{
	//string s = "A man, a plan, a canal: Panama";
	string s = "race a car";
	cout << "string = " << s << endl;
	bool result;
	result = isPalindrome(s);
	cout << "result = " << result << endl;
	return 0;
}
