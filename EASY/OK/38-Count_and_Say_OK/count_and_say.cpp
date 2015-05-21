/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/11 17:29:28
* >File Name: count_and_say.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>

using namespace std;

/*
 * The count-and-say sequence is the sequence of integers beginning as follows:
 * 1, 11, 21, 1211, 111221, ...
 *
 * 1 is read off as "one 1" or 11.
 * 11 is read off as "two 1s" or 21.
 * 21 is read off as "one 2, then one 1" or 1211.
 * Given an integer n, generate the nth sequence.
 *
 * Note: The sequence of integers will be represented as a string.
 */

string countresult(string s)
{
	string result;
	int count = 0;
	char temp1 = *(s.begin());
	char temp2;
	string :: iterator iter = s.begin();
	for(; iter < s.end(); iter++)
	{
		temp2 = *iter;
		if(temp1 == temp2)
		{
			count++;
		}
		else
		{
			result.insert(result.end(), count + '0');
			result.insert(result.end(), temp1);
			temp1 = temp2;
			count = 1;
		}
	}
	result.insert(result.end(), count + '0');
	result.insert(result.end(), temp1);

	return result;
}

string countAndSay(int n)
{
	string result = "1";

	if(n <= 0)
		return "0";

	if(n == 1)
		return result;

	for(int i = 1; i < n; i++)
	{
		result = countresult(result);
	}

	return result;

}

int main()
{
	int n = 5;
	string result;
	cout << "n = " << n << endl;
	result = countAndSay(n);
	cout << "result = " << result << endl;
	return 0;
}
