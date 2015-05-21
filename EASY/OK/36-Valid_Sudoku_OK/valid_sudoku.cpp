/*************************************************************
 * >Author: zhongwanyong
 * >Email:  zwy249348626@163.com
 * >Create Time: 2015/05/15 10:59:09
 * >File Name: valid_sudoku.cpp
 * >Description: 
 *************************************************************/

#include <iostream>
#include <vector>

using namespace std;

/*
 * Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
 *
 * The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
 *
 * +---+---+---+---+---+---+---+---+---+
 * | 7 | 3 |   $   | 7 |   $   |   |   |
 * +---+---+---+---+---+---+---+---+---+
 * | 6 |   |   $ 1 | 9 | 5 $   |   |   |
 * +---+---+---+---+---+---+---+---+---+
 * |   | 9 | 8 $   |   |   $   | 6 |   |
 * +~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+
 * | 8 |   |   $   | 6 |   $   |   | 3 |
 * +---+---+---+---+---+---+---+---+---+
 * | 4 |   |   $ 8 |   | 3 $   |   | 1 |
 * +---+---+---+---+---+---+---+---+---+
 * | 7 |   |   $   | 2 |   $   |   | 6 |
 * +~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+~~~+
 * |   | 6 |   $   |   |   $ 2 | 8 |   |
 * +---+---+---+---+---+---+---+---+---+
 * |   |   |   $ 4 | 1 | 9 $   |   | 5 |
 * +---+---+---+---+---+---+---+---+---+
 * |   |   |   $   | 8 |   $   | 7 | 9 |
 * +---+---+---+---+---+---+---+---+---+

 * A partially filled sudoku which is valid.
 *
 * Note:
 * A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.
 */

bool isValidSudoku(vector<vector<char> >& board)
{
	int i, j, k, l, temp;
	if(board.size() != 9)
		return false;
	for(i = 0; i < 9; i++)
	{
		if(board[i].size() != 9)
			return false;
	}

	int tag[12];
	for(i = 0; i < 12; i++)
		tag[i] = 0;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			temp = board[i][j] - '.';
			tag[temp] += 1;	
		}
		for(j = 3; j < 12; j++)
		{
			if(tag[j] > 1)
				return false;
			tag[j] = 0;
		}
	}
	
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			temp = board[j][i] - '.';
			tag[temp] += 1;	
		}
		for(j = 3; j < 12; j++)
		{
			if(tag[j] > 1)
				return false;
			tag[j] = 0;
		}
	}

	for(i = 0; i < 9; i = i + 3)
	{
		for(j = 0; j < 9; j = j + 3)
		{
			for(k = i; k < i + 3; k++)
			{
				for(l = j; l < j + 3; l++)
				{
					temp = board[k][l] - '.';
					tag[temp] += 1;
				}
			}
			for(l = 3; l < 12; l++)
			{
				if(tag[l] > 1)
					return false;
				tag[l] = 0;
			}

		}
	}

	return true;
}

void show(vector<vector<char> >& board)
{
	int i, j;
	for(i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			cout << " " << board[i][j] << " ";
		}
		cout << endl;
	}
}

int main()
{
	bool reuslt;
	vector<vector<char> > board;

	result = isValidSudoku(board);
	cout << "result = " << result << endl;
	return 0;
}
