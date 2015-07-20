/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/01 10:49:50
 * >File Name: binary_search_tree_iterator.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
 *
 * Calling next() will return the next smallest number in the BST.
 *
 * Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
 */

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class TreeNode
{
public:
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) : val(x), left(NULL), right(NULL)
	{
	}
};

class BSTIterator
{
public:
	TreeNode* head;

	BSTIterator(TreeNode *root)
	{
		head = root;
	}

	/** @return whether we have a next smallest number */
	bool hasNext()
	{
		if(head != NULL)
			return true;
		else
			return false;
	}

	/** @return the next smallest number */
	int next()
	{
		TreeNode* temp = head;
		while(temp -> left != NULL)
		{
			temp = temp -> left;
		}

		return temp -> val;
	}
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

int main()
{
	return 0;
}
