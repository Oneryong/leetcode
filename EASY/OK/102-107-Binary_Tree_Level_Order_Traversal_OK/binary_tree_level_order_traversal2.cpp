/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/22 11:43:43
 * >File Name: binary_tree_level_order_traversal2.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

/*
 * Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *      3
 *     / \
 *    9  20
 *    /   \
 *    15   7
 * return its bottom-up level order traversal as:
 * [
 *   [15,7],
 *   [9,20],
 *   [3]
 * ]
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

vector<vector<int> > levelOrderBottom(TreeNode* root)
{
	vector<vector<int> > result;
	vector<int> tempresult;
	queue<TreeNode*> temp1;
	queue<TreeNode*> temp2;
	TreeNode* tempnode;

	if(root == NULL)
		return result;

	temp1.push(root);

	while(!temp1.empty() || !temp2.empty())
	{
		if(!temp1.empty() && temp2.empty())
		{
			while(!temp1.empty())
			{
				tempnode = temp1.front();
				temp1.pop();
				tempresult.push_back(tempnode -> val);
				if(tempnode -> left != NULL)
					temp2.push(tempnode -> left);
				if(tempnode -> right != NULL)
					temp2.push(tempnode -> right);
			}
			result.push_back(tempresult);
			tempresult.clear();
		}
		if(temp1.empty() && !temp2.empty())
		{
			while(!temp2.empty())
			{
				tempnode = temp2.front();
				temp2.pop();
				tempresult.push_back(tempnode -> val);
				if(tempnode -> left != NULL)
					temp1.push(tempnode -> left);
				if(tempnode -> right != NULL)
					temp1.push(tempnode -> right);
			}
			result.push_back(tempresult);
			tempresult.clear();
		}
	}

	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	return 0;
}
