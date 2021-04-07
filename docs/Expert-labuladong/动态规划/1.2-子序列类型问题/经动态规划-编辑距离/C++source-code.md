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
#include <string>
#include <algorithm>
#include <vector>
#include <exception>
using namespace std;

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
			throw std::logic_error("无效的索引");
		}
	}
private:
	std::size_t m_row { 0 };
	std::size_t m_col { 0 };
	std::vector<T> m_data;
};

enum Operation
{
	do_nothing = 0, insert, delete_operation, update
};
struct Node
{
	int val;
	Operation choice;
// 0 代表啥都不做
// 1 代表插入
// 2 代表删除
// 3 代表替换
};
int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

int minDistance(string &word1, size_t index1, string &word2, size_t index2, TwoDimensionArray<Node> &solution)
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
		Node &N = solution.at(index1, index2);
		N.choice = Operation::do_nothing;
		N.val = distance;
		return distance;
	}
	else
	{
		int AddDistance = minDistance(word1, index1, word2, index2 - 1, solution) + 1;	// 增
		int DeleteDistance = minDistance(word1, index1 - 1, word2, index2, solution) + 1; // 删
		int UpdateDistance = minDistance(word1, index1 - 1, word2, index2 - 1, solution) + 1; // 改
		int res = min(AddDistance, DeleteDistance, UpdateDistance);
		Node &N = solution.at(index1, index2);

		N.val = res;
		if (res == AddDistance)
		{
			N.choice = Operation::insert;
		}
		else if (res == DeleteDistance)
		{
			N.choice = Operation::delete_operation;
		}
		else if (res == UpdateDistance)
		{
			N.choice = Operation::update;
		}
		else
		{
			throw std::logic_error("进入到了不可能的分支");
		}
		return res;
	}
}

int minDistance(string word1, string word2)
{
	TwoDimensionArray<Node> Solution { word1.size(), word2.size() };
	return minDistance(word1, word1.size() - 1, word2, word2.size() - 1, Solution);

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
// g++ --std=c++11 test.cpp

```





## Memoization



## Dynamic programing