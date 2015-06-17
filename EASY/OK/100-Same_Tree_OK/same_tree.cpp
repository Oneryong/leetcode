/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/19 11:44:43
 * >File Name: same_tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given two binary trees, write a function to check if they are equal or not.
 *
 * Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
 */

/*
 * Definition for a binary tree node.
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

bool isSameTree(TreeNode* p, TreeNode* q)
{
	bool result = false;
	if(p == NULL && q == NULL)
		return true;
	else if(p != NULL && q != NULL)
	{   
		if(p -> val == q -> val)
		{   
			result = isSameTree(p -> left, q -> left);
			if(result)
				result = isSameTree(p -> right, q -> right);
		}   
		else
			return false;
	}   
	else
		return false;

	return result;
}

int main()
{
	return 0;
}
