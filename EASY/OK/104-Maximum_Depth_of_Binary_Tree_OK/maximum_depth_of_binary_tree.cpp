/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/19 11:59:00
 * >File Name: maximum_depth_of_binary_tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a binary tree, find its maximum depth.
 *
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
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

int maxDepth(TreeNode* root)
{
	if(root == NULL)
		return 0;

	int countdepth = 1;
	int countleft = 0;
	int countright = 0;
	if(root -> left != NULL)
		countleft = maxDepth(root -> left);

	if(root -> right != NULL)
		countright = maxDepth(root -> right);

	int temp = countleft > countright ? countleft : countright;

	countdepth += temp;

	return countdepth;
}

int main()
{
	return 0;
}
