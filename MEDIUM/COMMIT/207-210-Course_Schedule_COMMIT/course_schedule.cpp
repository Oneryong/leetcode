/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:38:43
* >File Name: course_schedule.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/*
 * There are a total of n courses(科目，课程，道路) you have to take, labeled from 0 to n - 1.
 *
 * Some courses may have prerequisites(先决条件), for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 *
 * Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
 *
 * For example:
 *
 * 2, [[1,0]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
 *
 * 2, [[1,0],[0,1]]
 * There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 *
 * Note:
 * The input prerequisites is a graph represented(代表，表现，描写) by a list of edges, not adjacency matrices(邻接矩阵). Read more about how a graph is represented.
 *
 * Hints:
 * This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological(拓扑的) ordering exists and therefore it will be impossible to take all courses.
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

bool isCycle(int numCourses, ListNode** coursetable, int* coursecomenum)
{
	if(numCourses < 1 || coursetable == NULL || coursecomenum == NULL)
		return true;

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
	}

	if(count == numCourses)
		return true;
	else
		return false;
}

bool canFinish(int numCourses, vector<pair<int, int> >& prerequisites)
{
	if(numCourses < 1 || prerequisites.empty())
		return true;

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

	bool result = isCycle(numCourses, coursetable, coursecomenum);
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
	bool result;
	result = canFinish(num, relation);
	cout << "result = " << result << endl;
	cout << "true = " << true << endl;
	return 0;
}
