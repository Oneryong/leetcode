/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/22 11:52:23
 * >File Name: minimum_depth_of_binary_tree.cpp
 * >Description: 
 *************************************************************/

#include <iostream>

using namespace std;

/*
 * Given a binary tree, find its minimum depth.
 *
 * The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 *
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

int minDepth(TreeNode* root)
{
	if(root == NULL)
		return 0;

	int countdepth = 1;
	int countleft = 0;
	int countright = 0;
	if(root -> left != NULL)
		countleft = minDepth(root -> left);

	if(root -> right != NULL)
		countright = minDepth(root -> right);

	int temp;
	if(countleft != 0 && countright != 0)
		temp = countleft < countright ? countleft : countright;
	else if(countleft != 0)
		temp = countleft;
	else if(countright != 0)
		temp = countright;
	else
		temp = 0;

	countdepth += temp;

	return countdepth;
}

int main()
{
/*
Input:	[1,2]
Output:	1
Expected: 2
 */
	return 0;
}           
