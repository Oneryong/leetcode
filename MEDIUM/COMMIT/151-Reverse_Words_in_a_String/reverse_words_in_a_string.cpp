/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 10:34:16
* >File Name: reverse_words_in_a_string.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * Given an input string, reverse the string word by word.
 *
 *For example,
 * Given s = "the sky is blue",
 * return "blue is sky the".
 *
 * Update (2015-02-12):
 * For C programmers: Try to solve it in-place in O(1) space.
 */


//使用夹逼方法
void reverseWords(string &s)
{
	int len = s.size();
	if(len == 0)
		return;

	s = s + "$";
	int firstcount = 0;
	int secondcount = 0;
	int firstend = 0;
	int secondstart = len - 1;
	
	//find the end of the first element.
	while(s[firstend] != ' ')
	{
		++firstcount;
		++firstend;
	}
	//cout << firstcount << endl;
	//cout << firstend << endl;

	//find the start of the second element.
	while(s[secondstart] != ' ')
	{
		++secondcount;
		--secondstart;
	}
	//cout << secondcount << endl;
	//cout << secondstart << endl;

	while(firstend <= secondstart)
	{
		s.insert(secondstart + secondcount + 1, s, firstend - firstcount, firstcount);
		s.insert(firstend - firstcount, s, secondstart + 1, secondcount);
		s.erase(secondstart + secondcount + 1, secondcount);
		s.erase(firstend + secondcount - firstcount, firstcount);
		secondstart = secondstart + secondcount - firstcount;
		firstend = firstend + secondcount - firstcount;

		if(firstend == secondstart)
			break;

		firstcount = 0;
		secondcount = 0;
		++firstend;
		--secondstart;

		while(s[firstend] != ' ')
		{
			++firstcount;
			++firstend;
		}
		//cout << firstcount << endl;
		//cout << firstend << endl;

		while(s[secondstart] != ' ')
		{
			++secondcount;
			--secondstart;
		}
		//cout << secondcount << endl;
		//cout << secondstart << endl;
		
		//cout << secondstart << endl;
		//cout << firstend << endl;
	}
	s.erase(s.size() - 1, 1);
}

int main()
{
	string s = "the a b blue";
	cout << "s = " << s << endl;
	reverseWords(s);
	cout << "result = " << s << endl;
	return 0;
}
