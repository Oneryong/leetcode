/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/10 10:17:09
* >File Name: pascal_triangle2.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given an index k, return the kth row of the Pascal's triangle.

 * For example, given k = 3,
 * Return [1,3,3,1].

 * Note:
   Could you optimize your algorithm to use only O(k) extra space?
 */

vector<int> getRow(int rowIndex)
{
	vector<int> vec;

	if(rowIndex < 0)
	{
		cout << "please input the right rowIndex..." << endl;
		return vec;
	}

	vec.push_back(1);    //create the first row
	if(rowIndex > 0)
	{

		vec.push_back(1);    //create the second row
		if(rowIndex > 1)
		{
			int i, j;
			for(i = 2; i <= rowIndex; i++)
			{
				vec.push_back(1);
				for(j = i - 1; j > 0; j--)
				{
					vec[j] = vec[j] + vec[j - 1];    //modify from the last - 1 to 1
				}
			}
		}
	}
	
	return vec;
}

int main()
{
	vector<int> result;
	result = getRow(4);
	cout << "the result is:";
	for(vector<int> :: iterator iter = result.begin(); iter < result.end(); iter++)
		cout << *iter << " ";
	cout << endl;
	return 0;
}
