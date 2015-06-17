/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:08:54
* >File Name: remove_linked_list_elements.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Remove all elements from a linked list of integers that have value val.
 *
 * Example
 * Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
 * Return: 1 --> 2 --> 3 --> 4 --> 5
 */

/*
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

ListNode* removeElements(ListNode* head, int val)
{
	if(head == NULL)
		return NULL;

	ListNode* del = NULL;
	while(head != NULL && (head -> val) == val)
	{
		del = head;
		head = head -> next;
		delete del;
		del = NULL;
	}
	
	ListNode* p = head;
	while(p != NULL)
	{
		if(p -> next != NULL && ((p -> next) -> val) == val)
		{
			del = p -> next;
			p -> next = del -> next;
			delete del;
			del = NULL;
		}
		else
			p = p -> next;
	}

	return head;
}

int main()
{
	ListNode* head = new ListNode(1);
	ListNode* result = NULL;
	result = removeElements(head, 1);
	cout << "result = " << result << endl;
	return 0;
}
