/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/22 11:56:59
 * >File Name: path_sum2.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
 *
 * For example:
 * Given the below binary tree and sum = 22,
 *               5
 *              / \
 *             4   8
 *            /   / \
 *           11  13  4
 *          /  \    / \
 *         7    2  5   1
 * return
 * [
 *    [5,4,11,2],
 *    [5,8,4,5]
 * ]
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

void FindPath(TreeNode* root, int sum, int currentsum, vector<int> &path, vector<vector<int> > &result);

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
	vector<vector<int> > result;
	if(root == NULL)
		return result;

	int currentsum = 0;
	vector<int> path;
	FindPath(root, sum, currentsum, path, result);

	return result;
}

void FindPath(TreeNode* root, int sum, int currentsum, vector<int> &path, vector<vector<int> > &result)
{
	currentsum += root -> val;
	path.push_back(root -> val);

	if(root -> left == NULL && root -> right == NULL && currentsum == sum)
	{
		result.push_back(path);
	}

	if(root -> left != NULL)
		FindPath(root -> left, sum, currentsum, path, result);

	if(root -> right != NULL)
		FindPath(root -> right, sum, currentsum, path, result);

	path.pop_back();
}

int main()
{
/*
Input:	[1], 1
Output:	[]
Expected: [[1]]
 */
	return 0;
}               
