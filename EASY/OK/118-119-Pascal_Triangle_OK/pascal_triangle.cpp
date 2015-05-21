/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/09 19:36:51
* >File Name: pascal_triangle.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given numRows, generate the first numRows of Pascal's triangle.

 * For example, given numRows = 5,
 * Return
 [
      [1],
     [1,1],
    [1,2,1],
   [1,3,3,1],
  [1,4,6,4,1]
]
*/

vector<vector<int> > generate(int numRows)
{
	vector<vector<int> > vec;
	vector<int> vectemp;

	if(numRows < 1)
	{
		cout << "please input the right rows..." << endl;
		return vec;
	}

	//add the first row
	vectemp.push_back(1);
	vec.push_back(vectemp);
	vectemp.clear();

	//add the other rows
	if(numRows > 1)
	{
		//add the second row
		vectemp.push_back(1);
		vectemp.push_back(1);
		vec.push_back(vectemp);
		vectemp.clear();

		if(numRows > 2)
		{
			vector<vector<int> > :: iterator iter = vec.begin() + 1;
			int i, j;
			int temp;
			for(i = 3; i <= numRows; i++)
			{
				vectemp.push_back(1);
				for(j = 1; j < i - 1; j++ )
				{
					temp = (*iter)[j - 1] + (*iter)[j];
					cout << "temp = " << temp << endl;
					vectemp.push_back(temp);
				}
				vectemp.push_back(1);
				vec.push_back(vectemp);
				vectemp.clear();
				iter = vec.begin() + (i - 1);  //update the iter
			}
		}
	}
	return vec;
}

int main()
{
	vector<vector<int> >result;
	result = generate(5);
	for(vector<vector<int> > :: iterator iter1 = result.begin(); iter1 < result.end(); iter1++)
	{
		for(vector<int> :: iterator iter2 = (*iter1).begin(); iter2 < (*iter1).end(); iter2++)
			cout << *iter2 <<" ";
		cout << endl;
	}
	return 0;
}
