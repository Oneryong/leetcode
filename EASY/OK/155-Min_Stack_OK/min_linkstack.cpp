/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/12 10:42:33
* >File Name: min_linkstack.cpp
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

class Node
{
	private:
		int elem;
		Node *prev;
	public:
		Node()
		{
			prev = 0;
		}
		
		Node(Node &node)
		{
			elem = node.elem;
			prev = node.prev;
		}

		Node(int a, Node *b)
		{
			elem = a;
			prev = b;
		}

		~Node()
		{
		}

		int getelem()
		{
			return elem;
		}

		Node *getprev()
		{
			return prev;
		}

};

class MinStack
{
	private:
		Node *base;
		Node *s_top;
	public:
		MinStack()
		{
			base = new Node;
			if(!base)
			{
				cout << "Stack init fault..." << endl;
				exit(0);
			}
			s_top = base;
		}

		~MinStack()
		{
			Node *temp;
			while(s_top != 0)
			{
				temp = s_top;
				s_top = (*s_top).getprev();
				delete temp;
			}
		}

		void push(int x)
		{
			s_top = new Node(x, s_top);
		}

		void pop()
		{
			if(s_top == base)
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			Node *temp = s_top;
			s_top = (*s_top).getprev();
			delete temp;
		}

		int top()
		{
			if(s_top == base)
			{
				cout << "the stack is empty..." << endl;
				exit(0);
			}
			return (*s_top).getelem();
		}

		int getMin()
		{
		}

		void show()
		{
			cout << "the elements is:" << endl;
			cout << "stack:s_top --> base" << endl;
			for(Node *i = s_top; i != base; i = (*i).getprev())
				cout << (*i).getelem() << " ";
			cout << endl;
		}
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
	
	//result = s.getMin();
	//cout << "the getMin result = " << result << endl;
	
	result = s.top();
	cout << "the top result = " << result << endl;

	s.pop();
	s.show();
	return 0;
}
