/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/09 19:25:54
* >File Name: reverse_linked_list.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Reverse a singly linked list
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

ListNode* reverseList(ListNode* head)
{
	if(head == NULL)
		return NULL;

	ListNode* tail = head;
	ListNode* p = head -> next;

	while(p != NULL)
	{
		tail -> next = p -> next;
		p -> next = head;
		head = p;
		p = tail -> next;
	}

	return head;
}

int main()
{
	return 0;
}
