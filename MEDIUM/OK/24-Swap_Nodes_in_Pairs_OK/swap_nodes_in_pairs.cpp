/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 16:51:45
* >File Name: swap_nodes_in_pairs.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a linked list, swap every two adjacent nodes and return its head.
 *
 * For example,
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 *
 * Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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

ListNode* swapPairs(ListNode* head)
{
	if(head == NULL || head -> next == NULL)
		return head;

	ListNode* p = head;
	ListNode* q = head -> next;
	int temp;

	while(p != NULL && q != NULL)
	{
		temp = p -> val;
		p -> val = q -> val;
		q -> val = temp;
		if(q -> next != NULL)
			p = q -> next;
		else
			p = NULL;

		if(p != NULL && p -> next != NULL)
			q = p -> next;
		else
			q = NULL;
	}

	return head;
}

int main()
{
	return 0;
}
