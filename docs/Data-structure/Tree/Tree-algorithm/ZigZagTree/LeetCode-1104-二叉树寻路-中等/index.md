# LeetCode [1104. 二叉树寻路](https://leetcode.cn/problems/path-in-zigzag-labelled-binary-tree/)

![img](https://assets.leetcode.cn/aliyun-lc-upload/uploads/2019/06/28/tree.png)

## 我的解题

一、自底向上

首先找到 `label` 对应的节点处于第几层

然后逐层向上，找他的父节点

二、根据位置来计算

三、每一层的节点个数是可以计算出来的

设深度为`depth` ( 从0开始 )，对应层次的节点个数为 $2^{depth}$ 

四、每一层是正序还是逆序也是可以计算出来的

偶数层是正序，奇数层是逆序；

五、如何找到 `label` 对应的节点的parent node？

结合具体的例子来进行说明: (15 - 13) / 2 = 1，说明它的parent node位于上一层的第一个位置(位置从0来说编号)。

### 完整代码

```C++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
	int m_depth { 0 };
public:
	vector<int> pathInZigZagTree(int label)
	{
		m_depth = getDepth(label);
		vector<int> res(m_depth + 1, 0);
		res[m_depth] = label;
		while (label > 1)
		{
			label = getParentLabel(label);
			--m_depth;
			res[m_depth] = label;
		}
		return res;
	}
	int getDepth(int label)
	{
		int depth = 0;
		// (1 << (depth + 1)) 表示的是下一层的起始label
		// 只有当label大于 或 等于下一行的起始label的时候，说明它应该属于下一行
		while ((1 << (depth + 1)) <= label)
		{
			++depth;
		}
		return depth;
	}
	int getParentLabel(int label)
	{
		if (label <= 1) // root没有parent
		{
			return 1;
		}
		else
		{
			if (m_depth >> 1 == 0) // 当前行是偶数行，递增
			{
				int startLablel = 1 << (m_depth);
				int lastStartLable = startLablel - 1; // 上一行的起始label
				int order = (label - startLablel) / 2;
				return lastStartLable - order;
			}
			else // 当前行是奇数行，递减
			{
				int startLablel = (1 << (m_depth + 1)) - 1;
				int lastStartLable = 1 << (m_depth - 1);
				int order = (startLablel - label) / 2;
				return lastStartLable + order;
			}
		}

	}
};

int main()
{
	Solution s;
	s.pathInZigZagTree(14);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```

