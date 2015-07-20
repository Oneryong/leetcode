/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/19 20:30:53
 * >File Name: palindrome_linked_list.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a singly linked list, determine if it is a palindrome.
 *
 * Follow up:
 * Could you do it in O(n) time and O(1) space?
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

bool isPalindrome(ListNode* head)
{
	if(head == NULL || head -> next == NULL)
		return true;

	int count = 0;
	ListNode* p = head;
	while(p != NULL)
	{
		++count;
		p = p -> next;
	}
	
	//reverse the last half of list.
	p = head;
	ListNode* temp1 = NULL;
	ListNode* temp2 = NULL;
	ListNode* temp3 = NULL;
	
	if((count & 0x1) == 0)
	{
		count /= 2;
		--count;
	}
	else
	{
		count /= 2;
	}

	while(count)
	{
		p = p -> next;
		--count;
	}
	temp1 = p;
	temp2 = p -> next -> next;
	p -> next -> next = NULL;
	while(temp2 != NULL)
	{
		temp3 = temp2;
		temp2 = temp2 -> next;
		temp3 -> next = temp1 -> next;
		temp1 -> next = temp3;
	}
	//reverse end.

	temp1 = temp1 -> next;
	p = head;
	while(temp1 != NULL)
	{
		if(temp1 -> val != p -> val)
			return false;
		else
		{
			temp1 = temp1 -> next;
			p = p -> next;
		}
	}

	return true;
}

int main()
{
	ListNode* head = new ListNode(1);
	head -> next = new ListNode(2);
	bool result;
	result = isPalindrome(head);
	cout << "result = " << result << endl;
	return 0;
}
