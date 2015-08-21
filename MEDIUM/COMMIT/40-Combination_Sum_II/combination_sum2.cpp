/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/06/26 17:05:43
 * >File Name: combination_sum2.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
 * Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
 *
 * Each number in C may only be used once in the combination.
 *
 * Note:
 * .All numbers (including target) will be positive integers.
 * .Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
 * .The solution set must not contain duplicate combinations.
 *
 * For example, given candidate set 10,1,2,7,6,1,5 and target 8, 
 * A solution set is: 
 * [1, 7] 
 * [1, 2, 5] 
 * [2, 6] 
 * [1, 1, 6]
 */

void combinationSumCore(vector<int>& candidates, int target, int start, vector<int>& temp, vector<vector<int> >& result)
{
	if(target == 0)
	{
		result.push_back(temp);
		return;
	}

	int previous = -1;  //确保在同一级别的循环中（此for循环，而不是递归的深度），candidates[i]不重复出现。
	for(int i = start; i < candidates.size(); ++i)
	{
		if(previous == candidates[i])
			continue;

		if(target < candidates[i])
			return;    //减枝

		previous = candidates[i];

		temp.push_back(candidates[i]);
		combinationSumCore(candidates, target - candidates[i], i + 1, temp, result);//每个点不可以重复多次，所以这里不在i处停留， 从i + 1开始。
		temp.pop_back();
	}
}


vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
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
