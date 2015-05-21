/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/15 10:48:28
 * >File Name: valid_parentheses.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 *
 * The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
 */

bool isValid(string s)
{
	vector<char> vec;
	int size = s.size();
	if(size == 0 || size % 2 != 0)
		return false;

	vec.push_back(s[0]);
	for(int i = 1; i < size; i++)
	{
		if(vec.empty())
			vec.push_back(s[i]);
		else if((s[i] - 1) != *(vec.end() - 1) && (s[i] - 2) != *(vec.end() - 1))
			vec.push_back(s[i]);
		else
			vec.pop_back();
	}

	if(vec.empty())
		return true;
	else
		return false;
}

int main()
{
	bool result;
	//string s = "()[]";
	//string s = "()[";
	//string s = "()[]]]";
	string s = "()[]  []";
	result = isValid(s);
	cout << "true = " << true << endl;
	cout << "false = " << false << endl;
	cout << "result = " << result << endl;
	return 0;
}

