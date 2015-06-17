/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/17 16:56:05
 * >File Name: invert_binary_tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Invert a binary tree.
 *
 *         4
 *       /   \
 *      2     7
 *     / \   / \
 *    1   3 6   9
 * to
 *          4
 *        /   \
 *       7     2
 *      / \   / \
 *     9   6 3   1
 */

/*
 * Definition for a binary tree node.
 * struct TreeNode
 * {
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

TreeNode* invertTree(TreeNode* root)
{
	if(root == NULL)
		return NULL;

	invertTree(root -> left);
	invertTree(root -> right);
	TreeNode* temp = root -> right;
	root -> right = root -> left;
	root -> left = temp;

	return root;

}

int main()
{
	return 0;
}
