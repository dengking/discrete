# leetcode [77. 组合](https://leetcode.cn/problems/combinations/)

## 理解题意

这道题的"组合"其实和我们平时所说的"排列组合"中的组合有些差异的，题目中的: 

```C++
输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
```

按道理来说从4个数中，选择2个，可能性为 $C_4^2 = 12$ ，但是上述答案只有6种。其实原题没有说明的是: 它的"组合"是有一些限制的: 

```C++
1、2、3、4
```

需要按照顺序来进行组合，不允许 `[4,1]`的这种情况。因此，在进行实现的时候，是需要添加上顺序要求的:

生成的子集中的元素的顺序需要和原集合中的元素的顺序一致。

## 解法

解法一: 转换为"子集"问题

这道题可以转换为"子集"问题，`n`个数中的每个数都可能被选出，不过，它有限制条件: 子集的长度为`k`。

## [官方解题](https://leetcode.cn/problems/combinations/solution/zu-he-by-leetcode-solution/)



### 方法一：递归实现组合型枚举

> NOTE: 
>
> 一、下面的实现是能够维持生成的子集中的元素
>
> 1、`cur`是从0开始，因此先加入到`temp`中的是小元素，后进入的是大元素，维持了和原集合中元素相同的顺序。
>
> 二、相比之下，labuladong [回溯算法团灭排列/组合/子集问题](https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA) 中给出的code是更加直观易懂的
>
> 

```C++
#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 作者：LeetCode-Solution
 链接：https://leetcode.cn/problems/combinations/solution/zu-he-by-leetcode-solution/
 来源：力扣（LeetCode）
 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 *
 */
class Solution
{
public:
	vector<int> temp;
	vector<vector<int>> ans;

	void dfs(int cur, int n, int k)
	{
		// 剪枝：temp 长度加上区间 [cur, n] 的长度小于 k，不可能构造出长度为 k 的 temp
		if (temp.size() + (n - cur + 1) < k)
		{
			return;
		}
		// 记录合法的答案
		if (temp.size() == k)
		{
			ans.push_back(temp);
			return;
		}
		// 考虑选择当前位置
		temp.push_back(cur);
		dfs(cur + 1, n, k);
		temp.pop_back();
		// 考虑不选择当前位置
		dfs(cur + 1, n, k);
	}

	vector<vector<int>> combine(int n, int k)
	{
		dfs(1, n, k);
		return ans;
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	Solution s;
	vector<vector<int>> combs = s.combine(4, 2);
	cout << combs.size() << endl;
	cout << combs << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

```c++
6
[[1,2,],[1,3,],[1,4,],[2,3,],[2,4,],[3,4,],]
```



### 方法二：非递归（字典序法）实现组合型枚举

> NOTE: 
>
> 1、暂时没有完整的学习，比较复杂

假设我们把原序列中被选中的位置记为 11，不被选中的位置记为 00，对于每个方案都可以构造出一个二进制数。

我们让原序列从大到小排列（即 $\{ n, n - 1, \cdots 1, 0 \}$ ）。我们先看一看 $n=4$, $k=2$ 的例子: 

| 原序列中被选中的数 | 对应的二进制数 | 方案 |
| ------------------ | -------------- | ---- |
| `43[2][1]`         | 0011           | 2, 1 |
| `4[3]2[1]`         | 0101           | 3, 1 |
| `4[3][2]1`         | 0110           | 3,2  |
| `[4]32[1]`         | 1001           | 4,1  |
| `[4]3[2]1`         | 1010           | 4,2  |
| `[4][3]21`         | 1100           | 4,3  |







## 我的解题



### 一个错误的解题

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	vector<vector<int>> ans; // 最终答案
	vector<int> t; // 存放临时的答案

public:
	vector<vector<int>> combine(int n, int k)
	{
		dfs(n, 0, k);
		return ans;
	}
	/**
	 * @brief
	 *
	 * @param cur 递归深度
	 * @param solution_len 解的长度
	 */
	void dfs(int n, int cur, int solution_len)
	{
		if (cur == solution_len)
		{
			ans.push_back(t);
			return;
		}
		for (int i = 1; i <= n; ++i)
		{
			t.push_back(i);
			dfs(n, cur + 1, solution_len);
			t.pop_back();
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}
int main()
{
	Solution s;
	vector<vector<int>> combs = s.combine(4, 2);
	cout << combs.size() << endl;
	cout << combs << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

输出如下:

```C++
16
[[1,1,],[1,2,],[1,3,],[1,4,],[2,1,],[2,2,],[2,3,],[2,4,],[3,1,],[3,2,],[3,3,],[3,4,],[4,1,],[4,2,],[4,3,],[4,4,],]
```

### labuladong [回溯算法团灭排列/组合/子集问题](https://mp.weixin.qq.com/s/qT6WgR6Qwn7ayZkI3AineA)

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	vector<vector<int>> res;
public:
	vector<vector<int>> combine(int n, int k)
	{
		vector<int> track;
		dfs(n, k, 1, track);
		return res;
	}
	void dfs(int n, int k, int start, vector<int> &track)
	{
		if (track.size() == k)
		{
			res.push_back(track);
			return;
		}
		for (int i = start; i <= n; ++i)
		{
			track.push_back(i);
			dfs(n, k, i + 1, track); // 需要注意的是: 必须是 `i + 1`，即后一个数必须要从它开始，这是非常容易出错的地方，如果传入`start + 1`，就会出现错误
			track.pop_back();
		}
	}
};

template<typename ...Args>
ostream& operator <<(ostream &stream, const vector<Args...> &v)
{
	stream << "[";
	for (auto &&i : v)
	{
		stream << i << ",";
	}
	stream << "]";
	return stream;
}

int main()
{
	Solution s;
	vector<vector<int>> combs = s.combine(4, 2);
	cout << combs.size() << endl;
	cout << combs << endl;
}
// g++ test.cpp -pedantic -Wall -Wextra --std=c++11

```

