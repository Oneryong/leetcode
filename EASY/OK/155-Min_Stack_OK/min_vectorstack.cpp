/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/12 14:27:55
* >File Name: min_vectorstack.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

//#define INIT_SIZE 100
//#define STEP 10

class MinStack
{
	public:
		MinStack()
		{
		}

		~MinStack()
		{
		}

		void push(int x)
		{
			vec.push_back(x);
			if(vectemp.empty() || *(vectemp.end() - 1) >= x)
				vectemp.push_back(x);
		}

		void pop()
		{
			if(vec.begin() == vec.end())
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			if(*(vec.end() - 1) == *(vectemp.end() - 1))
				vectemp.erase(vectemp.end() - 1);
			vec.erase(vec.end() - 1);
		}

		int top()
		{
			if(vec.begin() == vec.end())
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			return *(vec.end() -1);
		}

		int getMin()
		{
			if(vec.begin() == vec.end())
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			return *(vectemp.end() - 1);
			//sort(vec.begin(), vec.end());
			//return *(vec.begin());
			//return *(min_element(vec.begin(), vec.end()));
		}

		void show()
		{
			cout << "the elements is:" << endl;
			cout << "stack:base --> s_top." << endl;
			for(vector<int> :: iterator iter = vec.begin(); iter < vec.end(); iter++)
				cout << *iter << " ";
			cout << endl;
		}
	private:
		vector<int> vec;
		vector<int> vectemp;
};

int main()
{
	int result;
	MinStack s;
	s.push(-10000);
	s.push(-9999);
	s.push(-9998);
	s.push(-9997);
	s.push(-9996);
	s.push(-9995);
	s.push(-9994);
	s.push(-9993);
	s.push(-9992);
	s.push(-9991);
	s.push(-9990);
	s.show();
	
	result = s.getMin();
	cout << "the getMin result = " << result << endl;
	
	result = s.top();
	cout << "the top result = " << result << endl;

	s.pop();
	s.show();
	return 0;
}
