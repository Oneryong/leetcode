/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/10 14:24:54
* >File Name: majority_element.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

 * You may assume that the array is non-empty and the majority element always exist in the array.

 * Credits:
   Special thanks to @ts for adding this problem and creating all test cases.
 */

int majorityElement(vector<int> &num)
{
	if(num.empty())
		return -1;

	if(num.size() == 1)
		return num[0];

	int times = num.size() / 2;
	int count = 1;
	sort(num.begin(), num.end());
	vector<int> :: iterator iter = num.begin() + 1;
	for(; iter < num.end(); iter++)
	{
		if(*iter == *(iter - 1))
		{
			count++;
		}
		else
		{
			if(count > times)
				return *(iter - 1);
			else
				count = 1;
		}
	}
	if(count > times)
		return *(iter - 1);
	return -1;
}

int main()
{
	vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(2);
	//vec.push_back(1);
	//vec.push_back(1);
	//vec.push_back(1);
	vector<int> &vectemp = vec;
	int result;
	result = majorityElement(vectemp);
	cout << "result = " << result << endl;
	return 0;
}
