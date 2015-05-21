/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/15 10:40:57
* >File Name: longest_common_prefix.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
 * Write a function to find the longest common prefix string amongst an array of strings
 */

string longestCommonPrefix(vector<string>& strs)
{
	string result;
	
	if(strs.empty())
		return result;

	cout << "result[0] = " << result[0] << endl;

	for(int i = 0; i < strs[0].size(); i++)
	{
		for(int j = 1; j < strs.size(); j++)
		{
			if(strs[0][i] != strs[j][i])
				return result;
		}
		result.insert(result.end(), strs[0][i]);
	}

	return result;
}

int main()
{
	string result;
	vector<string> vec;
	//vec.push_back("abcd");
	//vec.push_back("abcrgt");
	//vec.push_back("abchgr");
	//vec.push_back("abcrty");
	//vec.push_back("abcdth");
	//vec.push_back("abtegs");
	result = longestCommonPrefix(vec);
	cout << "result = " << result << endl;
	return 0;
}
