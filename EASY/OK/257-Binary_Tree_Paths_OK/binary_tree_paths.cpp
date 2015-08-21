/*************************************************************
* >Author: zhongwanyong
* >Email:  249348626@qq.com
* >Create Time: 2015/08/18 17:32:40
* >File Name: binary_tree_paths.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <string>
#include <vector>
//#include <utility>    //pair类型的头文件

using namespace std;

/*
 * Given a binary tree, return all root-to-leaf paths.
 *
 * For example, given the following binary tree:
 *
 *      1
 *    /   \
 *   2     3
 *    \
 *     5
 *
 * All root-to-leaf paths are:
 *
 * ["1->2->5", "1->3"]
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


//采用回溯法
/*
vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	if(root == NULL)
		return result;

	vector<pair<TreeNode*, int> > vec;    //use vector as stack
	vec.push_back(make_pair(root, 0));
	pair<TreeNode*, int> temp;
	string str;
	while(!vec.empty())
	{
		temp = *(vec.end() - 1);
		str.push_back((temp.first) -> val + '0');
		str.append("->");
		if((temp.first) -> left == NULL && (temp.first) -> right == NULL)
		{
			str.erase(str.end() - 2, str.end() - 1);
			result.push_back(str);
			str.erase(str.end() - 1);
			vec.pop_back();
		}
		else if((temp.first) -> left != NULL && (temp.first) -> right != NULL)
		{
			if((temp.second) == 0)
			{
				vec.push_back(make_pair((temp.first) -> left, 0));
				(temp.second) = 1;
			}
			else if((temp.second) == 1)
			{
				vec.push_back(make_pair((temp.first) -> right, 0));
				(temp.second) = 2;
			}
			else
				vec.pop_back();
		}
		else if((temp.first) -> left != NULL && (temp.first) -> right == NULL)
		{
			if((temp.second) == 0)
			{
				vec.push_back(make_pair((temp.first) -> left, 0));
				(temp.second) = 1;
			}
			else
				vec.pop_back();
		}
		else
		{
			if((temp.second) == 0)
			{
				vec.push_back(make_pair((temp.first) -> left, 0));
				(temp.second) = 2;
			}
			else
				vec.pop_back();
		}
	}
	return result;
}
*/

//int to string
string itoa(int num)
{
	string result;
	if(num == 0)
	{
		result = "0";
		return result;
	}

	bool falg = false;    //记录是否有负号
	if(num < 0)
	{
		falg = true;
		num = -num;
	}

	while(num)
	{
		result.insert(result.begin(), (num % 10) + '0');
		num /= 10;
	}

	if(falg)
	{
		result.insert(result.begin(), '-');
	}

	return result;
}

//采用先根遍历，遇到叶子结点就存储并结束。
void getPaths(TreeNode* root, string str, vector<string>& vec)
{
	if(root == NULL)
		return;

	int value = root -> val;
	str += itoa(value);
	
	if(root -> left == NULL && root -> right == NULL)
	{
		vec.push_back(str);
		return;
	}

	if(root -> left != NULL)
		getPaths(root -> left, str + "->", vec);
	if(root -> right != NULL)
		getPaths(root -> right, str + "->", vec);
	
}

vector<string> binaryTreePaths(TreeNode* root)
{
	vector<string> result;
	if(root == NULL)
		return result;

	getPaths(root, "", result);
	return result;
}

int main()
{
	int a = -123;
	string str = itoa(a);
	cout << "str = " << str << endl;
	return 0;
}
