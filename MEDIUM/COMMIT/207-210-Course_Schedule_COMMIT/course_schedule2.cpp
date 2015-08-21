/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/07/01 11:49:35
 * >File Name: course_schedule2.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * There are a total of n courses you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, return the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of them. If it is impossible to finish all courses, return an empty array.
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So the correct course order is [0,1]
 *
 * 4, [[1,0],[2,0],[3,1],[3,2]]
 * There are a total of 4 courses to take. To take course 3 you should have finished both courses 1 and 2. Both courses 1 and 2 should be taken after you finished course 0. So one correct course order is [0,1,2,3]. Another correct ordering is[0,2,1,3].
 *
 * Note:
 * The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
 *
 * Hints:
 * This problem is equivalent to finding the topological order in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
 * Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
 * Topological sort could also be done via BFS.
 */

class ListNode
{
public:
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL)
	{
	}
};

void isCycle(int numCourses, ListNode** coursetable, int* coursecomenum, vector<int>& result)
{
	if(numCourses < 1 || coursetable == NULL || coursecomenum == NULL)
		return;

	queue<int> zerocome;
	int count = 0;
	int temp = 0;
	for(int i = 1; i <= numCourses; ++i)    //i from 1, because coursecomenum[0] = 0(no use)
	{   
		if(coursecomenum[i] == 0)
			zerocome.push(i);
	}
	//Topology Sort
	ListNode* p = NULL;
	while(!zerocome.empty())
	{
		temp = zerocome.front();
		zerocome.pop();
		p = coursetable[temp] -> next;
		while(p != NULL)
		{
			--coursecomenum[p -> val];
			if(coursecomenum[p -> val] == 0)
			{
				zerocome.push(p -> val);
			}
			p = p -> next;
		}
		++count;
		result.push_back(temp);
	}

	if(count != numCourses)
		result.clear();
}

vector<int> findOrder(int numCourses, vector<pair<int, int> >& prerequisites)
{
	vector<int> result;
	if(numCourses < 1 || prerequisites.empty())
		return result;

	ListNode* coursetable[numCourses + 1];  //Adjacency List
	int coursecomenum[numCourses + 1];

	//init coursetable[], coursecomenum[]
	for(int i = 0; i <= numCourses; ++i)
	{
		coursetable[i] = new ListNode(i);
		coursecomenum[i] = 0;
	}

	vector<pair<int, int> > :: iterator start = prerequisites.begin();
	vector<pair<int, int> > :: iterator stop = prerequisites.end();
	ListNode* p = NULL;

	//create Adjacency List
	for(; start < stop; ++start)
	{
		p = coursetable[(*start).second];
		while(p -> next != NULL)
			p = p -> next;
		p -> next = new ListNode((*start).first);
		++coursecomenum[(*start).first];
	}

	isCycle(numCourses, coursetable, coursecomenum, result);
	return result;
}

int main()
{
	int num = 5;
	vector<pair<int, int> >relation;
	relation.push_back(make_pair(2, 1));
	relation.push_back(make_pair(3, 1));
	relation.push_back(make_pair(5, 2));
	relation.push_back(make_pair(5, 3));
	relation.push_back(make_pair(2, 4));
	vector<int> result;
	result = findOrder(num, relation);
	cout << "result = ";
	for(vector<int> :: iterator iter = result.begin(); iter < result.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	return 0;
}
