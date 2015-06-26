/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/23 10:14:05
 * >File Name: addtwonumbers.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
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

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
	if(l1 == NULL && l2 == NULL)
		return NULL;
	if(l1 == NULL)
		return l2;
	if(l2 == NULL)
		return l1;

	int temp = 0;
	int flag = 0;
	ListNode* result = l1;
	while(l1 -> next != NULL && l2 -> next != NULL)
	{
		temp = (l1 -> val) + (l2 -> val) + flag;
		l1 -> val = temp % 10;
		flag = temp / 10;
		l1 = l1 -> next;
		l2 = l2 -> next;
	}
	
	if(l2 -> next != NULL)
		l1 -> next = l2 -> next;

	temp = (l1 -> val) + (l2 -> val) + flag;
	l1 -> val = temp % 10;
	flag = temp / 10;

	while(flag != 0 && l1 -> next != NULL)
	{
		temp = ((l1 -> next) -> val) + flag;
		(l1 -> next) -> val = temp % 10;
		flag = temp / 10;
		l1 = l1 -> next;
	}
	if(l1 -> next == NULL && flag != 0)
		l1 -> next = new ListNode(flag);

	return result;
}

int main()
{
	ListNode* p1 = new ListNode(9);
	p1 -> next = new ListNode(8);
	ListNode* p2 = new ListNode(1);
	cout << "l1 =";
	ListNode* l1 = p1;
	ListNode* l2 = p2;
	while(l1 != NULL)
	{
		cout << " " << l1 -> val;
		l1 = l1 -> next;
	}
	cout << endl;
	cout << "l2 =";
	while(l2 != NULL)
	{
		cout << " " << l2 -> val;
		l2 = l2 -> next;
	}
	cout << endl;
	ListNode* result = addTwoNumbers(p1, p2);
	cout << "result =";
	while(result != NULL)
	{
		cout << " " << result -> val;
		result = result -> next;
	}
	cout << endl;
	return 0;
}
