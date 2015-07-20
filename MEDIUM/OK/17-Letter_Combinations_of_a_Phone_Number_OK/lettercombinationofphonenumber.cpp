/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/23 10:29:53
* >File Name: lettercombinationofphonenumber.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
 * Given a digit string, return all possible letter combinations that the number could represent.
 *
 * A mapping of digit to letters (just like on the telephone buttons) is given below.
 *   *phone.png*
 *
 * Input: Digit string "23"
 * Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 *
 * Note:
 * Although the above answer is in lexicographical(词典编纂的) order, your answer could be in any order you want.
 */
/*
vector<string> letterCombinations(string digits)
{
	vector<string> result;
	int len = digits.size();
	if(len <= 0)
		return result;

	string table[10] = {" ", "$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	int i, j, k;
	int size1, size2;
	result.push_back(table[digits[0] - '0']);
	for(i = 1; i < len; ++i)
	{
		vector<string> temp;
		size1 = table[digits[i] - '0'].size();
		size2 = result.size();
		for(j = 0; j < size1; ++j)
		{
			for(k = 0; k < size2; ++k)
			{
				temp.push_back(result[k] + table[digits[i] - '0'][j]);
			}
		}
		result = temp;
	}

	return result;
}
*/

void CombinationsCore(string* table, string& digits, int index, string& temp, vector<string>& result);

vector<string> letterCombinations(string digits)
{
	vector<string> result;
	int len = digits.size();
	if(len <= 0)
		return result;

	string table[10] = {" ", "$", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

	string temp(len, ' ');
	CombinationsCore(table, digits, 0, temp, result);

	return result;
}

void CombinationsCore(string* table, string& digits, int index, string& temp, vector<string>& result)
{
	if(index = digits.size() - 1)
	{
		result.push_back(temp);
		return;
	}

	for(int i = 0; i < table[digits[index] - '0'].size(); ++i)
	{
		temp[index] = table[digits[index] - '0'][i];
		CombinationsCore(table, digits, index + 1, temp, result);
	}
}

int main()
{
	return 0;
}
