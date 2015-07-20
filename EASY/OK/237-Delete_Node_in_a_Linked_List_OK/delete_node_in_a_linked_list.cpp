/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/19 20:46:09
 * >File Name: delete_node_in_a_linked_list.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Write a function to delete a node (except the tail) in a singly linked list, given only access to that node.
 *
 * Supposed the linked list is 1 -> 2 -> 3 -> 4 and you are given the third node with value 3, the linked list should become 1 -> 2 -> 4 after calling your function.
 */

/**
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

void deleteNode(ListNode* node)
{
	if(node == NULL)
		return;

	ListNode* del;
	del = node -> next;
	node -> val = del -> val;
	node -> next = del -> next;

	delete del;
}

int main()
{
	return 0;
}
