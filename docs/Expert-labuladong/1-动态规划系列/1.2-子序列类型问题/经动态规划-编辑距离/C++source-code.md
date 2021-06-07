# C++ source code

## Brute force

### 不记录具体操作

```C++
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int minDistance(string &word1, size_t index1, string &word2, size_t index2)
{
	if (index1 == -1)
	{
		return index2 + 1;
	}
	if (index2 == -1)
	{
		return index1 + 1;
	}
	int distance = 0;
	if (word1[index1] == word2[index2])
	{
		return minDistance(word1, index1 - 1, word2, index2 - 1);
	}
	else
	{
		return min(minDistance(word1, index1, word2, index2 - 1) + 1, // 增
		minDistance(word1, index1 - 1, word2, index2) + 1, // 删
		minDistance(word1, index1 - 1, word2, index2 - 1) + 1 // 改
						);
	}
}

int minDistance(string word1, string word2)
{
	return minDistance(word1, word1.size() - 1, word2, word2.size() - 1);
}

int main()
{
	string word1 = "horse", word2 = "ros";
	cout << minDistance(word1, word2) << endl;
	word1 = "intention", word2 = "execution";
	cout << minDistance(word1, word2) << endl;
	word1 = "rad", word2 = "apple";
	cout << minDistance(word1, word2) << endl;
}
// g++ test.cpp -g

```

输出如下:

```C++
3
5
5
```

### 记录具体操作

```C++
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

/**
 * @brief 动态二维数组，便于记录解
 *
 * @tparam T
 */
template<typename T>
class TwoDimensionArray
{
public:
	TwoDimensionArray(std::size_t row, std::size_t col) :
					m_row { row }, m_col { col }
	{
		m_data.resize(m_row * m_col);
	}
	T& at(std::size_t row_index, std::size_t col_index)
	{
		if (row_index < m_row && col_index < m_col)
		{
			return m_data[row_index * m_col + col_index];
		}
		else
		{
			std::stringstream s;
			s << "无效的索引:[" << row_index << "," << col_index << "]";
			throw std::logic_error(s.str());
		}
	}
private:

	std::size_t m_row { 0 }; // 行数
	std::size_t m_col { 0 }; // 列数
	std::vector<T> m_data;
};
// 0 代表啥都不做
// 1 代表插入
// 2 代表删除
// 3 代表替换
// nil 是初始值
enum Operation
{
	do_nothing = 0, insert, delete_operation, update, nil
};
static const char *OperationStrArray[] = { "do_nothing", "insert", "delete", "update" };
/**
 * @brief 记录解
 *
 */
struct Record
{
	int val { 0 }; // edit distance
	Operation choice { Operation::nil }; // 执行的操作
	Record(int v, Operation c) :
					val { v }, choice { c }
	{
	}
	Record() = default;

};
bool operator >(const Record &left, const Record &right)
{
	return left.val > right.val;
}
bool operator==(const Record &left, const Record &right)
{
	return left.val == right.val;
}
bool operator<(const Record &left, const Record &right)
{
	return left.val < right.val;
}
Record min(Record a, Record b, Record c)
{
	return min(a, min(b, c));
}
/**
 * @brief 从solution中，跟踪出解
 *
 * @param Solution
 * @param index1
 * @param index2
 */
void TraceSolution(TwoDimensionArray<Record> &Solution, size_t index1, size_t index2)
{
	if (index1 == 0 && index2 == 0)
	{
		Record &r = Solution.at(index1, index2);
		std::cout << "在位置[" << index1 << "]处执行的操作为:" << OperationStrArray[r.choice] << std::endl;
		return;
	}
	else
	{
		Record &r = Solution.at(index1, index2);
		if (r.choice == Operation::delete_operation)
		{
			TraceSolution(Solution, index1 - 1, index2);
		}
		else if (r.choice == Operation::do_nothing)
		{
			TraceSolution(Solution, index1 - 1, index2 - 1);
		}
		else if (r.choice == Operation::insert)
		{
			TraceSolution(Solution, index1, index2 - 1);
		}
		else if (r.choice == Operation::update)
		{
			TraceSolution(Solution, index1 - 1, index2 - 1);
		}
		else
		{
			throw std::logic_error("进入到了不可能的分支");
		}
		std::cout << "在位置[" << index1 << "]处执行的操作为:" << OperationStrArray[r.choice] << std::endl;
	}

}

int minDistance(string &word1, size_t index1, string &word2, size_t index2, TwoDimensionArray<Record> &solution)
{
	if (index1 == -1)
	{
		return index2 + 1;
	}
	if (index2 == -1)
	{
		return index1 + 1;
	}
	if (word1[index1] == word2[index2])
	{
		int distance = minDistance(word1, index1 - 1, word2, index2 - 1, solution);
		Record &r = solution.at(index1, index2);
		r.choice = Operation::do_nothing;
		r.val = distance;
		return distance;
	}
	else
	{
		int AddDistance = minDistance(word1, index1, word2, index2 - 1, solution) + 1;	// 增
		Record AddNode { AddDistance, Operation::insert };
		int DeleteDistance = minDistance(word1, index1 - 1, word2, index2, solution) + 1; // 删
		Record DeleteNode { DeleteDistance, Operation::delete_operation };
		int UpdateDistance = minDistance(word1, index1 - 1, word2, index2 - 1, solution) + 1; // 改
		Record UpdateNode { UpdateDistance, Operation::update };
		Record MinimalNode = min(AddNode, DeleteNode, UpdateNode);
		solution.at(index1, index2) = MinimalNode;

		return MinimalNode.val;
	}
}

int minDistance(string word1, string word2)
{
	TwoDimensionArray<Record> Solution { word1.size(), word2.size() };
	int Res = minDistance(word1, word1.size() - 1, word2, word2.size() - 1, Solution);
	TraceSolution(Solution, word1.size() - 1, word2.size() - 1);
	std::cout << "[" << word1 << "]和[" << word2 << "]的最小编辑距离为:" << Res << std::endl;
	return Res;

}

int main()
{
	string word1 = "horse", word2 = "ros";
	minDistance(word1, word2);
	word1 = "intention", word2 = "execution";
	minDistance(word1, word2);
	word1 = "rad", word2 = "apple";
	minDistance(word1, word2);
}
// g++ --std=c++11 test.cpp

```

输出如下:

```C++
在位置[0]处执行的操作为:update
在位置[1]处执行的操作为:do_nothing
在位置[2]处执行的操作为:delete
在位置[3]处执行的操作为:do_nothing
在位置[4]处执行的操作为:delete
[horse]和[ros]的最小编辑距离为:3
在位置[0]处执行的操作为:update
在位置[1]处执行的操作为:update
在位置[2]处执行的操作为:delete
在位置[3]处执行的操作为:do_nothing
在位置[4]处执行的操作为:update
在位置[4]处执行的操作为:insert
在位置[5]处执行的操作为:do_nothing
在位置[6]处执行的操作为:do_nothing
在位置[7]处执行的操作为:do_nothing
在位置[8]处执行的操作为:do_nothing
[intention]和[execution]的最小编辑距离为:5
terminate called after throwing an instance of 'std::logic_error'
  what():  无效的索引:[0,18446744073709551615]
Aborted (core dumped)

```





## Memoization



## Dynamic programing

### 记录具体操作的

```C++
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

/**
 * @brief 动态二维数组，便于记录解
 *
 * @tparam T
 */
template<typename T>
class TwoDimensionArray
{
public:
	TwoDimensionArray(std::size_t row, std::size_t col) :
					m_row { row }, m_col { col }
	{
		m_data.resize(m_row * m_col);
	}
	T& at(std::size_t row_index, std::size_t col_index)
	{
		if (row_index < m_row && col_index < m_col)
		{
			return m_data[row_index * m_col + col_index];
		}
		else
		{
			std::stringstream s;
			s << "无效的索引:[" << row_index << "," << col_index << "]";
			throw std::logic_error(s.str());
		}
	}
private:

	std::size_t m_row { 0 }; // 行数
	std::size_t m_col { 0 }; // 列数
	std::vector<T> m_data;
};
// 0 代表啥都不做
// 1 代表插入
// 2 代表删除
// 3 代表替换
// nil 是初始值
enum Operation
{
	do_nothing = 0, insert, delete_operation, update, nil
};
static const char *OperationStrArray[] = { "do_nothing", "insert", "delete", "update" };
/**
 * @brief 记录解
 *
 */
struct Record
{
	int val { 0 }; // edit distance
	Operation choice { Operation::nil }; // 执行的操作
	Record(int v, Operation c) :
					val { v }, choice { c }
	{
	}
	Record() = default;

};
bool operator >(const Record &left, const Record &right)
{
	return left.val > right.val;
}
bool operator==(const Record &left, const Record &right)
{
	return left.val == right.val;
}
bool operator<(const Record &left, const Record &right)
{
	return left.val < right.val;
}
Record min(Record a, Record b, Record c)
{
	return min(a, min(b, c));
}
/**
 * @brief 从solution中，跟踪出解
 *
 * @param Solution
 * @param index1
 * @param index2
 */
void TraceSolution(TwoDimensionArray<Record> &Solution, size_t index1, size_t index2)
{
	if (index1 == 0 && index2 == 0)
	{
		Record &r = Solution.at(index1, index2);
		std::cout << "在位置[" << index1 << "]处执行的操作为:" << OperationStrArray[r.choice] << std::endl;
		return;
	}
	else
	{
		Record &r = Solution.at(index1, index2);
		if (r.choice == Operation::delete_operation)
		{
			TraceSolution(Solution, index1 - 1, index2);
		}
		else if (r.choice == Operation::do_nothing)
		{
			TraceSolution(Solution, index1 - 1, index2 - 1);
		}
		else if (r.choice == Operation::insert)
		{
			TraceSolution(Solution, index1, index2 - 1);
		}
		else if (r.choice == Operation::update)
		{
			TraceSolution(Solution, index1 - 1, index2 - 1);
		}
		else
		{
			throw std::logic_error("进入到了不可能的分支");
		}
		std::cout << "在位置[" << index1 << "]处执行的操作为:" << OperationStrArray[r.choice] << std::endl;
	}

}

int minDistance(string &word1, size_t index1, string &word2, size_t index2, TwoDimensionArray<Record> &solution)
{
	if (index1 == -1)
	{
		return index2 + 1;
	}
	if (index2 == -1)
	{
		return index1 + 1;
	}
	if (word1[index1] == word2[index2])
	{
		int distance = minDistance(word1, index1 - 1, word2, index2 - 1, solution);
		Record &r = solution.at(index1, index2);
		r.choice = Operation::do_nothing;
		r.val = distance;
		return distance;
	}
	else
	{
		int AddDistance = minDistance(word1, index1, word2, index2 - 1, solution) + 1;	// 增
		Record AddNode { AddDistance, Operation::insert };
		int DeleteDistance = minDistance(word1, index1 - 1, word2, index2, solution) + 1; // 删
		Record DeleteNode { DeleteDistance, Operation::delete_operation };
		int UpdateDistance = minDistance(word1, index1 - 1, word2, index2 - 1, solution) + 1; // 改
		Record UpdateNode { UpdateDistance, Operation::update };
		Record MinimalNode = min(AddNode, DeleteNode, UpdateNode);
		solution.at(index1, index2) = MinimalNode;

		return MinimalNode.val;
	}
}

int minDistance(string word1, string word2)
{
	std::size_t len1 = word1.size(), len2 = word2.size();
	TwoDimensionArray<Record> DPTable { len1 + 1, len2 + 1 };
	DPTable.at(0, 0) = { 0, Operation::do_nothing };

	/**
	 * S1非空，S2为空，显然，直接删除S1即可
	 */
	for (int i = 1; i <= len1; ++i)
	{
		DPTable.at(i, 0) = { i, Operation::delete_operation };
	}
	/**
	 * S1空，S2非空，显然，直接插入S2即可
	 */
	for (int j = 1; j <= len2; ++j)
	{
		DPTable.at(0, j) = { j, Operation::insert };
	}
	for (int i = 1; i <= len1; ++i)
		for (int j = 1; j <= len2; ++j)
		{
			if (word1[i - 1] == word2[j - 1])
			{
				DPTable.at(i, j) = { DPTable.at(i - 1, j - 1).val, Operation::do_nothing };
			}
			else
			{
				DPTable.at(i, j) = min( { DPTable.at(i - 1, j - 1).val + 1, Operation::update }, { DPTable.at(i - 1, j).val + 1, Operation::delete_operation }, { DPTable.at(i, j - 1).val + 1, Operation::insert });
			}
		}
	TraceSolution(DPTable, len1, len2);
	int Res = DPTable.at(len1, len2).val;
	std::cout << "[" << word1 << "]和[" << word2 << "]的最小编辑距离为:" << Res << std::endl;
	return Res;

}

int main()
{
	string word1 = "horse", word2 = "ros";
	minDistance(word1, word2);
	word1 = "intention", word2 = "execution";
	minDistance(word1, word2);
	word1 = "rad", word2 = "apple";
	minDistance(word1, word2);
}
// g++ --std=c++11 test.cpp


```

输出如下:

```C++
在位置[0]处执行的操作为:do_nothing
在位置[1]处执行的操作为:update
在位置[2]处执行的操作为:do_nothing
在位置[3]处执行的操作为:delete
在位置[4]处执行的操作为:do_nothing
在位置[5]处执行的操作为:delete
[horse]和[ros]的最小编辑距离为:3
在位置[0]处执行的操作为:do_nothing
在位置[1]处执行的操作为:update
在位置[2]处执行的操作为:update
在位置[3]处执行的操作为:update
在位置[4]处执行的操作为:update
在位置[5]处执行的操作为:update
在位置[6]处执行的操作为:do_nothing
在位置[7]处执行的操作为:do_nothing
在位置[8]处执行的操作为:do_nothing
在位置[9]处执行的操作为:do_nothing
[intention]和[execution]的最小编辑距离为:5
在位置[0]处执行的操作为:do_nothing
在位置[0]处执行的操作为:insert
在位置[0]处执行的操作为:insert
在位置[1]处执行的操作为:update
在位置[2]处执行的操作为:update
在位置[3]处执行的操作为:update
[rad]和[apple]的最小编辑距离为:5

```

### 不记录具体操作的、[标准答案](https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-by-leetcode-solution/)

```C++
#include <string>
#include <iostream>
using namespace std;

class Solution
{
public:
	int minDistance(string word1, string word2)
	{
		int n = word1.length();
		int m = word2.length();

		// 有一个字符串为空串
		if (n * m == 0)
			return n + m;

		// DP 数组
		int D[n + 1][m + 1];

		// 边界状态初始化
		for (int i = 0; i < n + 1; i++)
		{
			D[i][0] = i;
		}
		for (int j = 0; j < m + 1; j++)
		{
			D[0][j] = j;
		}

		// 计算所有 DP 值
		for (int i = 1; i < n + 1; i++)
		{
			for (int j = 1; j < m + 1; j++)
			{
				int left = D[i - 1][j] + 1;
				int down = D[i][j - 1] + 1;
				int left_down = D[i - 1][j - 1];
				if (word1[i - 1] != word2[j - 1])
					left_down += 1;
				D[i][j] = min(left, min(down, left_down));

			}
		}
		return D[n][m];
	}
};

int main()
{
	Solution s;
	string word1 = "horse", word2 = "ros";
	std::cout << s.minDistance(word1, word2) << std::endl;
	word1 = "intention", word2 = "execution";
	std::cout << s.minDistance(word1, word2) << std::endl;
	word1 = "rad", word2 = "apple";
	std::cout << s.minDistance(word1, word2) << std::endl;
}

```

