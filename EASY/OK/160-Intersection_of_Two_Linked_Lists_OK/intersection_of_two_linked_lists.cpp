/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/22 12:46:22
* >File Name: intersection_of_two_linked_lists.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Write a program to find the node at which the intersection of two singly linked lists begins.
 *
 * For example, the following two linked lists:
 *
 * A:          a1 → a2
 *                      ↘
 *		          c1 → c2 → c3
 *	                ↗            
 * B:     b1 → b2 → b3
 * begin to intersect at node c1.
 * Notes:
 *
 * If the two linked lists have no intersection at all, return null.
 * The linked lists must retain their original structure after the function returns.
 * You may assume there are no cycles anywhere in the entire linked structure.
 * Your code should preferably run in O(n) time and use only O(1) memory.
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

ListNode* getIntersectionNode(ListNode *headA, ListNode *headB)
{
	if(headA == NULL || headB == NULL)
		return NULL;

	ListNode* p1 = headA;
	ListNode* p2 = headB;
	int sizeA = 0;
	int sizeB = 0;
	while(p1 != NULL)
	{
		sizeA++;
		p1 = p1 -> next;
	}
	while(p2 != NULL)
	{
		sizeB++;
		p2 = p2 -> next;
	}

	p1 = headA;
	p2 = headB;
	int step;
	if(sizeA >= sizeB)
	{
		step = sizeA - sizeB;
		while(step != 0)
		{
			p1 = p1 -> next;
			step--;
		}
	}
	else
	{
		step = sizeB - sizeA;
		while(step != 0)
		{
			p2 = p2 -> next;
			step--;
		}
	}


	while(p1 != NULL && p2 != NULL)
	{
		if(p1 == p2)
			return p1;
		p1 = p1 -> next;
		p2 = p2 -> next;
	}
	
	return NULL;
}

int main()
{
	return 0;
}
