/*************************************************************
 * >Author: zhongwanyong
 * >Email:  249348626@qq.com
 * >Create Time: 2015/08/21 11:38:20
 * >File Name: implement_stack_using_queues.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <queue>

using namespace std;

/*
 * Implement the following operations of a stack using queues.
 *
 * push(x) -- Push element x onto stack.
 * pop() -- Removes the element on top of the stack.
 * top() -- Get the top element.
 * empty() -- Return whether the stack is empty.
 *
 * Notes:
 * You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
 * Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
 * You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
 */

class Stack
{
public:
	// Push element x onto stack.
	void push(int x)
	{
		if(q[0].empty() && q[1].empty())
		{
			q[0].push(x);
		}
		else if(!q[0].empty() && q[1].empty())
		{
			q[0].push(x);
		}
		else if(q[0].empty() && !q[1].empty())
		{
			q[1].push(x);
		}
		else
			return;
	}

	// Removes the element on top of the stack.
	void pop()
	{
		int index = 0;    //store the index of queue who is not empty.
		int swap = 0;    //use for swap the element.
		if(q[0].empty() && q[1].empty())
			return;
		else if(!q[0].empty() && !q[1].empty())
			return;
		else if(!q[0].empty() && q[1].empty())
		{
			index = 0;
		}
		else
		{
			index = 1;
		}

		while(q[index].size() != 1)
		{
			swap = q[index].front();
			q[1 - index].push(swap);
			q[index].pop();
		}
		q[index].pop();
	}

	// Get the top element.
	int top()
	{
		int index = 0;    //store the index of queue who is not empty.
		if(q[0].empty() && q[1].empty())
			return -1;
		else if(!q[0].empty() && !q[1].empty())
			return -1;
		else if(!q[0].empty() && q[1].empty())
		{
			index = 0;
		}
		else
		{
			index = 1;
		}
	
		return q[index].back();
	}

	// Return whether the stack is empty.
	bool empty()
	{
		if(q[0].empty() && q[1].empty())
			return true;
		else
			return false;
	}
private:
	queue<int> q[2];
};

int main()
{
	return 0;
}
