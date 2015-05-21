/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/15 11:16:07
 * >File Name: length_of_last_word.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.
 *
 * If the last word does not exist, return 0.
 *
 * Note: A word is defined as a character sequence consists of non-space characters only.
 *
 * For example, 
 * Given s = "Hello World",
 * return 5.
 */

int lengthOfLastWord(string s)
{
	int count = 0;
	if(s.empty())
		return 0;

	string :: iterator iter1 = s.end() - 1;
	string :: iterator iter2 = s.begin();
	
	while(*iter1 == ' ' && iter1 >= iter2)
	{
		iter1--;
	}
	
	for(; iter1 >= iter2; iter1--)
	{
		if(*iter1 != ' ')
			count++;
		else
			return count;
	}

	return count;
}

int main()
{
	int result;
	//string s = "Hello world";
	//string s = "";
	//string s = "   ";
	//string s = "Hello world   ";
	string s = "   Hello ";
	cout << "string = " << s << endl;
	result = lengthOfLastWord(s);
	cout << "result = " << result << endl;
	return 0;
}
