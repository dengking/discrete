# 生成排列数的算法

参考文章:

1、CSDN [全排列—含重复元素](https://blog.csdn.net/drawlessonsfrom/article/details/108936498)

2、LeetCode [46. 全排列](https://leetcode-cn.com/problems/permutations/) 中等

3、LeetCode [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/) 中等



## 基于回溯法的算法



### 抽取法

将完全二叉树通过剪枝的方式，修建为一颗排列树；

在每个位置处，都可以选择n个元素；如果元素已经被选择，则跳过；

这是比较原始但是简单的方式；



在下面文章中，描述了这种算法:

1、LeetCode [47. 全排列 II](https://leetcode-cn.com/problems/permutations-ii/) 中等

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
	vector<int> vis; // 元素是否被放入到排列中，1-是、0-否

public:
	void backtrack(vector<int> &nums, vector<vector<int>> &ans, int idx, vector<int> &perm)
	{
		if (idx == nums.size())
		{
			ans.emplace_back(perm);
			return;
		}
		for (int i = 0; i < (int) nums.size(); ++i)
		{
			/**
			 * 1、vis[i] 为 1 ，表示第 i 个元素已经放入到了排列中
			 * 2、nums[i] == nums[i - 1] && !vis[i - 1] 对应的是 01 模式，这种模式是需要剪枝的
			 */
			if (vis[i] || (i > 0 && nums[i] == nums[i - 1] && !vis[i - 1]))
			{
				continue;
			}
			perm.emplace_back(nums[i]);
			vis[i] = 1;
			backtrack(nums, ans, idx + 1, perm);
			vis[i] = 0;
			perm.pop_back();
		}
	}

	vector<vector<int>> permuteUnique(vector<int> &nums)
	{
		vector<vector<int>> ans;
		vector<int> perm;
		vis.resize(nums.size());
		sort(nums.begin(), nums.end());
		backtrack(nums, ans, 0, perm);
		return ans;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("-91283472332") << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



2、CSDN [全排列—含重复元素](https://blog.csdn.net/drawlessonsfrom/article/details/108936498) 

```C++
#include <bits/stdc++.h>
using namespace std;
int number = 0;
int vis[15] = { 0 }; //表示未被访问过
void f(string a, int n, char b[], int p)
{
	if (p == n)
	{
		cout << b << endl;
		number++;
		return;
	}
	//在对字符串进行有序排列中，也可以开始就对他进行有序排列，因为在每次进行追加中其vis[i]均会被置为0，回到其初始状态
	for (int i = 0; i < n; i++)
	{
		if (i > 0 && a[i] == a[i - 1] && !vis[i - 1]) //进行去重，在去重需要是原来的字符串有序，同时保证a[i-1]未被访问过
		{
			continue;
		}
		if (!vis[i])
		{
			b[p] = a[i];
			vis[i] = 1;
			f(a, n, b, p + 1);
			vis[i] = 0;
		}
	}
}
int main()
{
	string str = "baba";
	sort(str.begin(), str.end()); //对字符串进行有序排列
	char b[15] = "";
	f(str, str.length(), b, 0);
	cout << number << endl;
	return 0;
}

```



### 交换法

这种算法就相对比较精妙一些，它不需要记录每个字符是否放入到了排列中，它是直接生成排列树的。

在下面文章中，描述了这种算法:

1、LeetCode [46. 全排列](https://leetcode-cn.com/problems/permutations/)

```C++
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
	void backtrack(vector<vector<int>> &res, vector<int> &output, int first, int len)
	{
		// 所有数都填完了
		if (first == len)
		{
			res.emplace_back(output);
			return;
		}
		for (int i = first; i < len; ++i)
		{
			// 动态维护数组
			swap(output[i], output[first]);
			// 继续递归填下一个数
			backtrack(res, output, first + 1, len);
			// 撤销操作
			swap(output[i], output[first]);
		}
	}
	vector<vector<int>> permute(vector<int> &nums)
	{
		vector<vector<int> > res;
		backtrack(res, nums, 0, (int) nums.size());
		return res;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("-91283472332") << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



### 抽取法 VS 交换法

#### 相同点

1、两种方法都是基于回溯法的

#### 不同点

1、

**抽取法**是将完全二叉树通过剪枝的方式，修建为一颗排列树；

```C++
for (int i = 0; i < (int) nums.size(); ++i)
```

它需要记录每个元素是否在排列中；



**交换法**是直接生成排列树，它没有剪枝的过程；

```C++
for (int i = first; i < len; ++i)
```



## Steinhaus-Johnson-Trotter-algorithm

参见 `Steinhaus-Johnson-Trotter-algorithm` 章节。

## TODO

baike [字典序](https://baike.baidu.com/item/%E5%AD%97%E5%85%B8%E5%BA%8F/7786229?fr=aladdin#5)

baike [全排列](https://baike.baidu.com/item/%E5%85%A8%E6%8E%92%E5%88%97)

baike [中介数](https://baike.baidu.com/item/%E4%B8%AD%E4%BB%8B%E6%95%B0/12796689?fr=aladdin)

csdn [全排列及相关扩展算法（三）——利用中介数求排列在字典序排位算法](https://blog.csdn.net/sm9sun/article/details/77258384)

