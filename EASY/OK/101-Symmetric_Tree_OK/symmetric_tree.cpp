/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/19 11:47:53
* >File Name: symmetric_tree.cpp
* >Description: 
*************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
 *
 * For example, this binary tree is symmetric:
 *
 *      1
 *     / \
 *    2   2
 *   / \ / \
 *  3  4 4  3
 * But the following is not:
 *       1
 *      / \
 *     2   2
 *      \   \
 *       3    3
 * Note:
 * Bonus points if you could solve it both recursively and iteratively.
 *
 * confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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

TreeNode* CopyTree(const TreeNode*);
void MirrorTree(TreeNode*);
bool CompareTree(TreeNode*, TreeNode*);

bool isSymmetric(TreeNode* root)
{
	bool result = true;
	if(root == NULL)
		return result;

	TreeNode* p = CopyTree(root);

	MirrorTree(root);

	result = CompareTree(p, root);

	delete p;

	return result;
}

TreeNode* CopyTree(const TreeNode* root)
{
	TreeNode* p;
	if(root == NULL)
		return NULL;

	p = new TreeNode(root -> val);
	if(root -> left != NULL)
		p -> left = CopyTree(root -> left);
	if(root -> right != NULL)
		p -> right = CopyTree(root -> right);

	return p;
}

void MirrorTree(TreeNode* root)
{
	TreeNode* p = root;
	if(p == NULL)
		return;

	if(p -> left == NULL && p -> right == NULL)
		return;

	TreeNode* temp = p -> left;
	p -> left = p -> right;
	p -> right = temp;

	if(p -> left != NULL)
		MirrorTree(p -> left);
	if(p -> right != NULL)
		MirrorTree(p -> right);
}

bool CompareTree(TreeNode* p, TreeNode* q)
{
	bool result = false;
	if(p == NULL && q == NULL)
		return true;
	else if(p != NULL && q != NULL)
	{
		if(p -> val == q -> val)
		{
			result = CompareTree(p -> left, q -> left);
			if(result)
				result = CompareTree(p -> right, q -> right);
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
