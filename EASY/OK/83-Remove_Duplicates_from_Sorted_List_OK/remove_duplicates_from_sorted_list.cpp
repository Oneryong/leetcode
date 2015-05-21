/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/19 11:41:23
* >File Name: remove_duplicates_from_sorted_list.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a sorted linked list, delete all duplicates such that each element appear only once.
 *
 * For example,
 * Given 1->1->2, return 1->2.
 * Given 1->1->2->3->3, return 1->2->3.
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

ListNode* deleteDuplicates(ListNode* head)
{
	ListNode* temp = head;
	ListNode* p = NULL;
	if(head == NULL || head -> next == NULL)
		return temp;

	while(temp -> next != NULL)
	{
		if(temp -> val == temp -> next -> val)
		{
			p = temp -> next;
			temp -> next = p -> next;
			delete p;
		}
		else
		{
			temp = temp -> next;
		}
	}

	return head;
}

int main()
{

	return 0;
}
