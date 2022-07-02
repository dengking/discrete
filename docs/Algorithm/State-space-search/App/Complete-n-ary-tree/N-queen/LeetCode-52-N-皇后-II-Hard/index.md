# leetcode [52. N皇后 II](https://leetcode.cn/problems/n-queens-ii/) 困难

和 leetcode [51. N 皇后](https://leetcode.cn/problems/n-queens/) 困难 如出一辙。

## 我的解题

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
	int m_solutions { 0 }; // 所有解
	vector<string> m_solution; // 当前的一个解
public:
	int totalNQueens(int n)
	{
		m_size = n;
		m_position.reserve(m_size);
		backtrace(0);
		return m_solutions;
	}
	void backtrace(int queen_id)
	{
		if (queen_id == m_size)
		{
			// 将当前解放到m_solutions中
			++m_solutions;
		}
		else
		{
			for (int i = 0; i < m_size; ++i) // 对于每个皇后，都需要尝试这些列位置
			{
				m_position[queen_id] = i; // 将皇后放到第i列
				if (constrain(queen_id))
				{
					backtrace(queen_id + 1);
				}
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
	cout << s.totalNQueens(1) << endl;
	cout << "2" << endl;
	Solution s2;
	cout << s2.totalNQueens(2) << endl;
	cout << "3" << endl;
	Solution s3;
	cout << s3.totalNQueens(3) << endl;
	cout << "4" << endl;
	Solution s4;
	cout << s4.totalNQueens(4) << endl;

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra


```

