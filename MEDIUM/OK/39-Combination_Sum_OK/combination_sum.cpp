/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/06/26 17:02:55
* >File Name: combination_sum.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Given a set of candidate(候选人，候选者) numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * The same repeated number may be chosen from C unlimited number of times.
 *
 * Note:
 * .All numbers (including target) will be positive(正的) integers.
 * .Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * .The solution set must not contain duplicate combinations.
 * 
 * For example, given candidate set 2,3,6,7 and target 7, 
 * A solution set is: 
 * [7] 
 * [2, 2, 3] 
 */

void combinationSumCore(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int> >& result)
{
	if(target == 0)
	{
		result.push_back(temp);
		return;
	}

	for(int i = start; i < candidates.size(); ++i)
	{
		if(target < candidates[i])
			return;    //减枝

		temp.push_back(candidates[i]);
		combinationSumCore(candidates, target - candidates[i], i, temp, result);    //每个点可以重复多次，所以这里在i处停留。
		temp.pop_back();
	}
}

vector<vector<int> > combinationSum(vector<int>& candidates, int target)
{
	vector<vector<int> > result;
	vector<int> temp;
	if(candidates.size() == 0)
		return result;

	sort(candidates.begin(), candidates.end());

	combinationSumCore(candidates, target, 0, temp, result);

	return result;
}

int main()
{
	return 0;
}
