/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/12 10:42:57
* >File Name: min_seqstack.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * getMin() -- Retrieve the minimum element in the stack.
 */

#define INIT_SIZE 10
#define STEP 10

class MinStack
{
	public:
		MinStack():s_top(-1), length(INIT_SIZE)
		{
			//base = (int *)malloc(sizeof(int) * INIT_SIZE);
			base = new int[INIT_SIZE];
			if(!base)
			{
				cout << "Stack init fault..." << endl;
				exit(0);
			}
		}

		~MinStack()
		{
			//s_top = 0;
			delete []base;
			base = 0;
			//free(base);
		}

		void do_overflow()
		{
			int *newbase = new int[length + STEP];
			if(!newbase)
			{
				cout << "apply new memory fault..." << endl;
				exit(0);
			}
			for(int i = 0; i <= length; i++)
				newbase[i] = base[i];
			
			length = length + STEP;
			delete []base;
			base = newbase;
		}

		void push(int x)
		{
			if(s_top >= length - 1)
				//base = (int *)realloc(base, sizeof(int) * (length + STEP));
				do_overflow();

			s_top++;
			base[s_top] = x;
		}

		void pop()
		{
			if(s_top == -1)
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			s_top--;
		}

		int top()
		{
			if(s_top == -1)
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			return base[s_top];
		}

		int getMin()
		{
			if(s_top == -1)
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			sort(&base[0], &base[s_top]);
			return base[0];
		}

		void show()
		{
			cout << "the elements is:" << endl;
			cout << "stack:base --> s_top" << endl;
			for(int i = 0; i <= s_top; i++)
				cout << base[i] << " ";
			cout << endl;
		}
	private:
		int *base;
		int s_top;
		int length;
};

int main()
{
	int result;
	MinStack s;
	s.push(3);
	s.push(2);
	s.push(1);
	s.push(4);
	s.show();
	
	result = s.getMin();
	cout << "the getMin result = " << result << endl;
	
	result = s.top();
	cout << "the top result = " << result << endl;

	s.pop();
	s.show();
	return 0;
}
