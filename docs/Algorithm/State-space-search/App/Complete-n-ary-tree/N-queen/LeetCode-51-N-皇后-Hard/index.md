# leetcode [51. N 皇后](https://leetcode.cn/problems/n-queens/) 困难



## 我的解题

我是按照《计算机算法设计与分析-5-回溯法》中给出的demo写的。

```C++
#include <bits/stdc++.h>
using namespace std;

template<typename ...Args>
ostream& operator<<(ostream &stream, vector<Args...> v)
{
	for (auto &&i : v)
		stream << i << endl;
	return stream;
}

class Solution
{
	int m_size; // 棋盘大小
	vector<int> m_position; // 皇后放置的位置，m_solution[i] 表示将第i个皇后放到第 m_solution[i] 列
	vector<vector<string>> m_solutions; // 所有解
	vector<string> m_solution; // 当前的一个解
public:
	vector<vector<string>> solveNQueens(int n)
	{
		m_size = n;
		m_position.reserve(m_size);
		// 初始化 m_solution
		for (int i = 0; i < m_size; ++i)
		{
			m_solution.push_back( { });
			for (int j = 0; j < m_size; ++j)
			{
				m_solution.back().push_back('.');
			}
		}
		backtrace(0);
		return m_solutions;
	}
	void backtrace(int queen_id)
	{
		if (queen_id == m_size)
		{
			// 将当前解放到m_solutions中
			m_solutions.push_back(m_solution);
		}
		else
		{
			for (int i = 0; i < m_size; ++i) // 对于每个皇后，都需要尝试这些列位置
			{
				m_position[queen_id] = i; // 将皇后放到第i列
				m_solution[queen_id][i] = 'Q';
				if (constrain(queen_id))
				{
					backtrace(queen_id + 1);
				}
				m_solution[queen_id][i] = '.'; // 回溯
			}
		}

	}
	bool constrain(int queen_id)
	{
		for (int i = 0; i < queen_id; ++i)
		{
			if (m_position[i] == m_position[queen_id]) // 处于同一列，显然违反规则
				return false;
			if (abs(queen_id - i) == abs(m_position[queen_id] - m_position[i])) // 处于同一对角线，斜率为1，显然是违反规则的
				return false;
		}
		return true;
	}
};

int main()
{
	cout << "1" << endl;
	Solution s;
	cout << s.solveNQueens(1) << endl;
	cout << "2" << endl;
	Solution s2;
	cout << s2.solveNQueens(2) << endl;
	cout << "3" << endl;
	Solution s3;
	cout << s3.solveNQueens(3) << endl;
	cout << "4" << endl;
	Solution s4;
	cout << s4.solveNQueens(4) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

