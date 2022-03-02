# LeetCode [261. 以图判树](https://leetcode-cn.com/problems/graph-valid-tree/) 中等



## 我的解题

如果两个节点已经有公共祖先，此时再将两者连接，显然就会成环，因此这个题其实考察的是并查集union函数细节: 在进行union的时候，如果发现两个节点属于同一个root，那么此时如果继续进行union的话，显然它们就会现成环了。

显然，判断是否能够成树就两个条件:

1、无环

2、只有一个连通分量



```C++
#include <string>
#include <vector>
#include <stack>
#include <unordered_map>
#include <algorithm>
#include <random>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class UnionFindSet {
	std::vector<int> parent_;
	int component_count_{ 0 };
public:
	UnionFindSet(int n) :component_count_{ n } {
		for (int i = 0; i < n; ++i) {
			parent_.push_back(i);
		}
	}
	bool Union(int i, int j) {
		int i_root = find(i);
		int j_root = find(j);
		if (i_root == j_root) {
			return false;
		}
		else {
			parent_[i_root] = j_root; // 需要注意的是: 此处需要将 i_root 的parent而不是 i的parent设置为 j_root
			--component_count_;
			return true;
		}
	}
	int find(int i) {
		while (parent_[i] != i) {
			// 进行路径压缩
			parent_[i] = parent_[parent_[i]];
			i = parent_[i];
		}
		return i;
	}
	bool connected(int i, int j) {
		return find(i) == find(j);
	}
	int count() {
		return component_count_;
	}
};

class Solution {
public:
	bool validTree(int n, vector<vector<int>>& edges) {
		UnionFindSet uf(n);
		for (auto&& edge : edges) {
			if (!uf.Union(edge[0], edge[1])) {
				return false;
			}
		}
		return uf.count() == 1;
	}
};

int main()
{
	Solution s;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```

