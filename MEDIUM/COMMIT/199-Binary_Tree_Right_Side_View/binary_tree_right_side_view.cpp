/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/01 11:30:17
 * >File Name: binary_tree_right_side_view.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
 *
 * For example:
 * Given the following binary tree,
 *     1            <---
 *   /   \
 *  2     3         <---
 *  \     \
 *   5     4        <---
 * You should return [1, 3, 4].
 */

/**
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

vector<int> rightSideView(TreeNode* root)
{
	vector<int> result;
	if(root == NULL)
		return result;

	TreeNode* temp = root;
	result.push_back(root -> val);
	while(temp -> right != NULL || temp -> left != NULL)
	{
		if(temp -> right != NULL)
		{
			temp = temp -> right;
		}
		else
		{
			temp = temp -> left;
		}

		result.push_back(temp -> val);
	}

	return result;
}

int main()
{
	return 0;
}
