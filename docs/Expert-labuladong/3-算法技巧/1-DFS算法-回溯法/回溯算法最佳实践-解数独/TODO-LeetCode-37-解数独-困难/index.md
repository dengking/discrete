# LeetCode [37. 解数独](https://leetcode.cn/problems/sudoku-solver/) 困难



## 我的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	constexpr static int ROW_INDEX = 8; // 行下标
	constexpr static int COL_INDEX = 8; // 列下标
public:
	void solveSudoku(vector<vector<char>> &board)
	{
		backtrace(board, 0, 0);
	}
	void backtrace(vector<vector<char>> &board, int row, int col)
	{
		if (row >= ROW_INDEX && col >= COL_INDEX)
		{
			return;
		}
		else if (board[row][col] == '.')
		{
			for (char val = '1'; val <= '9'; ++val)
			{
				if (possible(board, row, col, val))
				{
					board[row][col] = val;
					auto coordinate = getNextCoordinate(row, col);
					backtrace(board, coordinate.first, coordinate.second);
					board[row][col] = '.';
				}
			}
		}
		else
		{
			auto coordinate = getNextCoordinate(row, col);
			backtrace(board, coordinate.first, coordinate.second);
		}
	}
	std::pair<int, int> getNextCoordinate(int row, int col)
	{
		if (col < COL_INDEX)
		{
			return
			{	row, col+1};
		}
		else
		{
			return
			{	row+1,0};
		}
	}
	/**
	 * @brief
	 *
	 * @param row
	 * @param col
	 * @param val
	 * @return
	 */
	bool possible(vector<vector<char>> &board, int row, int col, char val)
	{
		unordered_map<int, int> count;
		// 校验行
		auto &row_data = board[row];

		for (int i = 0; i <= COL_INDEX; ++i)
		{
			if (row_data[i] != '.' && row_data[i] == val)
			{
				return false;
			}
		}
		// 校验列
		for (int i = 0; i <= ROW_INDEX; ++i)
		{
			if (board[i][col] != '.' && board[i][col] == val)
			{
				return false;
			}
		}
		// 统计3x3 宫
		int row_order = row / 3;

		int col_order = col / 3;
		for (int i = row_order * 3; i < (row_order + 1) * 3; ++i)
			for (int j = col_order * 3; j < (col_order + 1) * 3; ++i)
			{
				if (board[i][j] != '.' && board[i][j] == val)
				{
					return false;
				}
			}
		return true;
	}

};

int main()
{

}

```

