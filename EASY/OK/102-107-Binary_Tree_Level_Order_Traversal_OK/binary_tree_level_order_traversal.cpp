/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/05/19 11:53:53
* >File Name: binary_tree_level_order_traversal.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
 *
 * For example:
 * Given binary tree {3,9,20,#,#,15,7},
 *        3
 *       / \
 *      9  20
 *      /   \
 *     15    7
 * return its level order traversal as:
 * [
 *   [3],
 *   [9,20],
 *   [15,7]
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

vector<vector<int> > levelOrder(TreeNode* root)
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

	return result;
}

int main()
{
	return 0;
}
