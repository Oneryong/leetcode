/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 16:49:41
* >File Name: generate_parentheses.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Given n pairs of parentheses(括号), write a function to generate all combinations of well-formed parentheses.
 *
 * For example, given n = 3, a solution set is:
 *
 * "((()))", "(()())", "(())()", "()(())", "()()()"
 */

void ParenthesisCore(int left, int right, string temp, vector<string>& result)
{
	if(left == 0 && right == 0)
	{
		result.push_back(temp);
		return;
	}

	if(left > 0)
		ParenthesisCore(left - 1, right, temp + "(", result);
	if(right > 0 && left < right)
		ParenthesisCore(left, right - 1, temp + ")", result);
}

vector<string> generateParenthesis(int n)
{
	vector<string> result;
	if(n <= 0)
		return result;

	ParenthesisCore(n, n, "", result);

	return result;
}

int main()
{
	int n = 3;
	vector<string> result;
	result = generateParenthesis(n);
	int i, len;
	len = result.size();
	for(i = 0; i < len; ++i)
	{
		cout << result[i] << endl;
	}
	return 0;
}
