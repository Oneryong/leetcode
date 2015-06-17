/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/22 11:50:15
 * >File Name: balanced_binary_tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <algorithm>

using namespace std;

/*
 * Given a binary tree, determine if it is height-balanced.
 *
 * For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
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

int maxDepth(TreeNode*);

bool isBalanced(TreeNode* root)
{
	if(root == NULL)
		return true;

	bool result = true;
	int countleft = 0;
	int countright = 0;
	if(root -> left != NULL)
		countleft = maxDepth(root -> left);

	if(root -> right != NULL)
		countright = maxDepth(root -> right);

	if(abs(countleft - countright) > 1)
		return false;

	if(root -> left != NULL)
		result = isBalanced(root -> left);
	if(result && root -> right != NULL)
		result = isBalanced(root -> right);

	return result;
}

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
/*
Input:	[1,2]
Output:	false
Expected: true
 */
	return 0;
}
