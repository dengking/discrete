# [LeetCode-743. 网络延迟时间-中等](https://leetcode.cn/problems/network-delay-time/) 

一、这个题目有一个特别需要注意的地方：

> 有 `n` 个网络节点，标记为 `1` 到 `n`

它的标记是从1开始的，而不是从0开始的，因此需要进行一次转换。

对于节点标记是从0-N的这种问题，adjacent list有两种选择：

1、`unordered_map<int, vector<vector<int> > > graph;`

2、`vector<vector<int>> g(n, vector<int>(n, inf)); // graph`

显然相比之下，第二种方式是更好的。



## C++

这是参考的

1、 [官方解题](https://leetcode.cn/problems/network-delay-time/solution/wang-luo-yan-chi-shi-jian-by-leetcode-so-6phc/) 

参考了它的graph表示方式；

2、[XingHe](https://leetcode.cn/u/QRhqcDD90G/) # [c++/python3/java （1）朴素dijkstra算法 （2）最小堆+visited+dijkstra算法](https://leetcode.cn/problems/network-delay-time/solution/cpython3java-1po-su-dijkstrasuan-fa-2zui-ks36/) #（二）最小堆+visited+dijkstra算法

参考了它的visited array；

```c++
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	int networkDelayTime(vector<vector<int>> &times, int n, int k)
	{
		const int inf = INT_MAX / 2;
		vector<vector<pair<int, int>>> g(n); // 在graph中，pair.fist 是节点index， pair.second是parent到它的weight
		for (auto &t : times)
		{
			int x = t[0] - 1, y = t[1] - 1; // 需要注意标号到下标的转换
			g[x].emplace_back(y, t[2]);
		}

		vector<int> dist(n, inf);
		dist[k - 1] = 0; // 需要注意标号到下标的转换
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q; // 这是min heap
		q.emplace(0, k - 1); // 在priority_queue中，pair.first 是当前节点的parent到它的weight，pair.second 是节点index
		while (!q.empty())
		{
			auto p = q.top(); // q是当前节点
			q.pop();
			int time = p.first, x = p.second;
			if (dist[x] < time)
			{
				continue;
			}
			for (auto &e : g[x]) // 对于所有的临接节点
			{
				int y = e.first, d = dist[x] + e.second;
				if (d < dist[y])
				{
					dist[y] = d;
					q.emplace(d, y);
				}
			}
		}

		int ans = *max_element(dist.begin(), dist.end());
		return ans == inf ? -1 : ans;
	}
};

int main()
{

}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g


```



写的，比较符合我的审美的一个程序:

```C++
#include <iostream>
#include <vector>
#include <queue>
#include <utility> // std::pair
#include <unordered_map>
#include <string>
#include <set>
#include <map>
#include <climits> // INT_MAX
using namespace std;

class Solution
{
public:
  int networkDelayTime(vector<vector<int> > &times, int n, int k)
  {
    vector<vector<pair<int, int> > > graph(n); // 在graph中，pair.fist 是节点index， pair.second是parent到它的weight
    for (auto &&edge : times)
    {
      int src_i = edge[0] - 1, dest_i = edge[1] - 1; // 需要注意标号到下标的转换
      int weight = edge[2];
      graph[src_i].emplace_back(dest_i, weight);
    }
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q; // 最小堆
                                                                                          // 在priority_queue中，pair.first 是parent到它的weight，pair.second 是节点index
    vector<bool> visited(n, false);                                                       // 是否已经找到了节点的最短距离
    vector<int> distances(n, INT_MAX);                                                    // 从src到各节点的距离
    int start_i = k - 1;
    q.emplace(0, start_i); // 将source放入到queue中
    distances[start_i] = 0;
    while (!q.empty())
    {
      auto src_node = q.top();
      int src_i = src_node.second;
      q.pop();
      if (visited[src_i])
      {
        continue;
      }
      visited[src_i] = true;
      for (auto &&dest_node : graph[src_i]) // 访问所有的邻接节点
      {
        int dest_i = dest_node.first;
        int weight = dest_node.second;
        int dist = distances[src_i] + weight; // 从当前节点到该节点

        if (dist < distances[dest_i])
        {
          q.push({dist, dest_i}); // 使用dis进行排序
          distances[dest_i] = dist;
        }
      }
    }
    int delayTime = *max_element(distances.begin(), distances.end());
    return delayTime == INT_MAX ? -1 : delayTime;
  }
};

int main()
{
  Solution s;
}

```



## Python

```python
import heapq
import unittest
from typing import List, Dict


class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        distances = {i + 1: float('inf') for i in range(n)}
        graph_in_ajd_list: Dict[int, Dict] = {t[0]: {} for t in times}
        for t in times:
            graph_in_ajd_list[t[0]][t[1]] = t[2]
        distances[k] = 0
        q = [(0, k)]
        while q:
            distance, node = heapq.heappop(q)
            for adj_node, adj_distance in graph_in_ajd_list.get(node, {}).items():
                new_distance = distance + adj_distance
                if new_distance < distances[adj_node]:
                    distances[adj_node] = new_distance
                    heapq.heappush(q, (new_distance, adj_node))

        max_distance = -1
        if float('inf') in distances.values():
            return max_distance
        return max(distances.values())


class TestStringMethods(unittest.TestCase):

    def test_case_1(self):
        self.solution = Solution()
        times = [[1, 2, 1], [2, 3, 2], [1, 3, 4]]
        n = 3
        k = 1

        self.assertEqual(self.solution.networkDelayTime(times, n, k), -1)


if __name__ == '__main__':
    unittest.main()

```

