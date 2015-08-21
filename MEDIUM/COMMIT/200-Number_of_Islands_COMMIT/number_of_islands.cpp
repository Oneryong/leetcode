/*************************************************************
* >Author: zhongwanyong
* >Email:  zwy249348626@163.com
* >Create Time: 2015/07/01 11:33:36
* >File Name: number_of_islands.cpp
* >Description: 
*************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally(水平的) or vertically(垂直的). You may assume all four edges of the grid are all surrounded by water.
 *
 * Example 1:
 * 11110
 * 11010
 * 11000
 * 00000
 * Answer: 1
 *
 * Example 2:
 * 11000
 * 11000
 * 00100
 * 00011
 * Answer: 3
 */

void dfs(vector<vector<char> >& grid, int i, int j, int rowlen, int columnlen)
{
	if(i < 0 || i > rowlen - 1 || j < 0 || j > columnlen)
		return;

	if(grid[i][j] == '1')
	{
		grid[i][j] = '2';
		dfs(grid, i - 1, j, rowlen, columnlen);
		dfs(grid, i, j - 1, rowlen, columnlen);
		dfs(grid, i + 1, j, rowlen, columnlen);
		dfs(grid, i, j + 1, rowlen, columnlen);
	}
}

int numIslands(vector<vector<char> >& grid)
{
	int count = 0;
	
	int rowlen = grid.size();
	if(rowlen == 0)
		return 0;
	
	int columnlen = grid[0].size();
	if(columnlen == 0)
		return 0;

	int i, j;
	for(i = 0; i < rowlen; ++i)
	{
		for(j = 0; j < columnlen; ++j)
		{
			if(grid[i][j] != '1')
				continue;

			++count;
			dfs(grid, i, j, rowlen, columnlen);
		}
	}

	return count;
}

int main()
{
	return 0;
}
