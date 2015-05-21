/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/15 10:44:20
 * >File Name: remove_nth_node_from_endof_number.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a linked list, remove the nth node from the end of list and return its head.
 *
 * For example,
 *
 * Given linked list: 1->2->3->4->5, and n = 2.
 *
 * After removing the second node from the end, the linked list becomes 1->2->3->5.
 * Note:
 * Given n will always be valid.
 * Try to do this in one pass.
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
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if(head == NULL)
	{
		cout << "List is empty..." << endl;
		return NULL;
	}
	
	ListNode *p1, *p2;
	p1 = head -> next;
	p2 = NULL;
	int count = 1;

	for(int i = 1; i < n; i++)
	{
		if(p1 != NULL)
			p1 = p1 -> next;
		else
		{
			cout << "n is to big..." << endl;
			return NULL;
		}
	}
	p2 = head;
	if(p1 == NULL)
	{
		head = head -> next;
		delete p2;
		return head;
	}

	p1 = p1 -> next;
	while(p1 != NULL)
	{
		p1 = p1 -> next;
		p2 = p2 -> next;
	}

	ListNode *temp = p2 -> next;
	p2 -> next = p2 -> next -> next;
	delete temp;

	return head;
}

void show(ListNode *head)
{
	ListNode *p;
	p = head;
	if(head == NULL)
		return;

	cout << "result = ";
	while(p != NULL)
	{
		cout << p -> val << " ";
		p = p -> next;
	}
	cout << endl;
}

ListNode *create(int n)
{
	if(n == 0)
	{
		cout << "n cann't be 0..." << endl;
	}

	ListNode *head = NULL;
	ListNode *p = new ListNode(1);
	head = p;
	ListNode *q = NULL;

	for(int j = 1; j < n; j++)
	{
		q = new ListNode(j + 1);
		p -> next = q;
		p = p -> next;
	}

	return head;
}

int main()
{
	ListNode *head = NULL;
	//head = create(1);
	//head = create(2);
	head = create(5);
	//head = create(1);
	show(head);
	head = removeNthFromEnd(head, 5);
	show(head);
	return 0;
}
