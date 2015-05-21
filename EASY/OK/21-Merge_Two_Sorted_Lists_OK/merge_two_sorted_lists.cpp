/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/15 10:52:07
 * >File Name: merge_two_sorted_lists.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
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

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
	ListNode* head = NULL;
	if(l1 == NULL && l2 == NULL)
		return head;
	if(l1 == NULL)
	{
		head = l2;
		return head;
	}
	if(l2 == NULL)
	{
		head = l1;
		return head;
	}

	ListNode* temp = NULL;
	ListNode* p1 = l1;
	ListNode* p2 = l2;

	if(p1 -> val <= p2 -> val)
	{
		temp = p1;
		p1 = p1 -> next;
	}
	else
	{
		temp = p2;
		p2 = p2 -> next;
	}
	head = temp;

	while(p1 != NULL && p2 != NULL)
	{
		if(p1 -> val <= p2 -> val)
		{
			temp -> next = p1;
			p1 = p1 -> next;
			temp = temp -> next;
		}
		else
		{
			temp -> next = p2;
			p2 = p2 -> next;
			temp = temp -> next;
		}
	}
	if(p1 != NULL)
		temp -> next = p1;
	if(p2 != NULL)
		temp -> next = p2;

	return head;
}

void show(ListNode* head)
{
	ListNode* p; 
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

ListNode* create(int n)
{
	if(n == 0)
	{   
		cout << "n cann't be 0..." << endl;
		return NULL;
	}   

	ListNode* head = NULL;
	ListNode* p = new ListNode(1);
	head = p;
	ListNode* q = NULL;

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
	ListNode* result;
	ListNode* s1 = NULL;
	ListNode* s2 = NULL;
	s1 = create(4);
	cout << "s1:" << endl;
	show(s1);
	s2 = create(2);
	cout << "s2:" << endl;
	show(s2);
	result = mergeTwoLists(s1, s2);
	cout << "result:" << endl;
	show(result);
	return 0;
}
