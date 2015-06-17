/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/22 11:54:21
 * >File Name: path_sum.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *            5
 *           / \
 *          4   8
 *         /   / \
 *        11  13  4
 *       /  \      \
 *      7    2      1
 * return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.
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

bool FindPath(TreeNode* root, int sum, int currentsum);

bool hasPathSum(TreeNode* root, int sum)
{
	if(root == NULL)
		return false;

	int currentsum = 0;
	bool result;
	result = FindPath(root, sum, currentsum);

	return result;
}

bool FindPath(TreeNode* root, int sum, int currentsum)
{
	if(root ==NULL)
		return false;

	bool result = false;

	currentsum += root -> val;
	if(root -> left == NULL && root -> right == NULL && currentsum == sum)
		return true;

	if(root -> left != NULL)
		result = FindPath(root -> left, sum, currentsum);

	if(!result && root -> right != NULL)
		result = FindPath(root -> right, sum, currentsum);

	return result;
}

int main()
{
	return 0;
}
