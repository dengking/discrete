## LeetCode-课程表系列

| LeetCode                                                     | 算法 |
| ------------------------------------------------------------ | ---- |
| [LeetCode-207. 课程表](https://leetcode.cn/problems/course-schedule/) |      |
| [LeetCode-210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii/) |      |
| [LeetCode-630. 课程表 III](https://leetcode.cn/problems/course-schedule-iii/) |      |
| [LeetCode-1462. 课程表 IV](https://leetcode.cn/problems/course-schedule-iv/) |      |

Dependency graph模型:

首先需要根据 `prerequisites` 数组构建出dependency graph，这样能够找到它的相邻节点，原味给出的解法中都是使用的**adjacent list**，题目描述如下:

> 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

则说明在dependency graph中，存在从bi->ai的边，也就说明ai位于bi的adjacency list中，在dependency graph中，in-degree就表示依赖。



## [LeetCode-207. 课程表](https://leetcode.cn/problems/course-schedule/) 



### [力扣官方题解](https://leetcode.cn/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/)

> NOTE: 这个题只需要判断是否存在circle，即circle detection

1、如果图 `G` 中存在环（即图 `G` 不是「有向无环图」），那么图 `G` 不存在**拓扑排序**。

这是因为假设图中存在环 $x_1, x_2, \cdots, x_n, x_1$ ，那么 $x_1$ 在排列中必须出现在 $x_n$的前面，但 $x_n$ 同时也必须出现在 $x_1$  的前面，因此不存在一个满足要求的排列，也就不存在拓扑排序；

> NOTE: 上述使用的是反证法: 自相矛盾，在实现topological sorting的时候，一个非常重要的问题是circle，一旦有circle则无法进行topological sorting

2、如果图 $G$ 是有向无环图，那么它的拓扑排序可能不止一种。举一个最极端的例子，如果图 $G$ 值包含 $n$ 个节点却没有任何边，那么任意一种编号的排列都可以作为拓扑排序。

#### 方法一：深度优先搜索

#### **算法**

对于图中的任意一个节点，它在搜索的过程中有**三种状态**，即：

1、「未搜索」：我们还没有搜索到这个节点；

2、**「搜索中」**：我们搜索过这个节点，但还没有回溯到该节点，即该节点还没有入栈，还有相邻的节点没有搜索完成）；

3、「已完成」：我们搜索过并且回溯过这个节点，即该节点已经入栈，并且所有该节点的相邻节点都出现在栈的更底部的位置，满足拓扑排序的要求。

> NOTE: 
>
> 一、难点在于三种状态的处理
>
> 所谓的"搜索"，其实就是是否access、traverse、visited了这个节点:
>
> "**「搜索中」**" 表示 已经访问了这个节点，查看下面的code可知，它使用 `visited` array来记录节点的状态

通过上述的三种状态，我们就可以给出使用**深度优先搜索**得到**拓扑排序**的算法流程，在每一轮的搜索开始时，我们任取一个**「未搜索」**的节点开始进行深度优先搜索。

一、我们将当前搜索的节点 u 标记为**「搜索中」**，遍历该节点的每一个相邻节点 vv：

1、如果 v 为「未搜索」，那么我们开始搜索 v，待搜索完成回溯到 u；

2、如果 v 为「搜索中」，那么我们就找到了图中的一个环，因此是不存在拓扑排序的；

> NOTE: 
>
> 一、这是难以理解的地方，为什么呢？首先画个带环的图看看: 
>
> ![](/Users/dengkai/Documents/GitHub/discrete/docs/Data-structure/Graph/Algorithm/Topological-sorting/graph-with-cycle.jpg)
>
> 其中 简单理解是: 如果graph中存在circle，那么再DFS circle的时候，一定会回到原点，这种情况就是2中描述的情形。这是DFS graph中常用的通过`visited` array来判断是否存在环的方法。
>
> 这是典型的DFS判断graph中是否存在circle的情况，一般称之为为circle detection，因此这一步是这个算法的关键所在。

3、如果 v 为「已完成」，那么说明 v 已经在栈中了，而 u 还不在栈中，因此 u 无论何时入栈都不会影响到 (u, v)(u,v) 之前的拓扑关系，以及不用进行任何操作。

当 u 的所有相邻节点都为「已完成」时，我们将 u 放入栈中，并将其标记为「已完成」。

```C++
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<int>> edges; // adjacency list
	vector<int> visited;
	bool valid = true;

public:
	void dfs(int u) {
		visited[u] = 1;
		for (int v : edges[u]) {
			if (visited[v] == 0) {
				dfs(v);
				if (!valid) {
					return;
				}
			}
			else if (visited[v] == 1) {
				valid = false;
				return;
			}
		}
		visited[u] = 2;
	}

	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		visited.resize(numCourses);
		// 构建dependency graph
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
		}
		// 外面的这个for循环是非常有必要的，因为可能是非联通图，如果不加for的话，可能导致部分图未处理
		for (int i = 0; i < numCourses && valid; ++i) {
			if (!visited[i]) {
				dfs(i);
			}
		}
		return valid;
	}
};


int main()
{
	Solution s;
	int numCourses = 2;
	vector<vector<int>> prerequisites{ {1,0} };
	cout << s.canFinish(numCourses, prerequisites) << endl;
}

```



### BFS

```python
from collections import defaultdict, deque
from typing import *


class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = defaultdict(list)
        for prep in prerequisites:
            graph[prep[1]].append(prep[0])
        for i in range(numCourses):
            if i not in graph:
                graph[i] = []
        in_degree = {node: 0 for node in graph}
        for node in graph:
            for adj_node in graph[node]:
                in_degree[adj_node] += 1
        q = deque([node for node in graph if in_degree[node] == 0])
        cnt = 0
        while q:
            node = q.popleft()
            cnt += 1
            for adj_node in graph[node]:
                in_degree[adj_node] -= 1
                if in_degree[adj_node] == 0:
                    q.append(adj_node)
        return cnt == numCourses

```



## [LeetCode-210. 课程表 II](https://leetcode.cn/problems/course-schedule-ii/)



### BFS

````python
from collections import defaultdict, deque
from typing import *


class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        topo_order = []
        graph = defaultdict(list)
        in_degree = [0] * numCourses
        for prep in prerequisites:
            graph[prep[1]].append(prep[0])
            in_degree[prep[0]] += 1
        q = deque([node for node in range(numCourses) if in_degree[node] == 0])
        while q:
            node = q.popleft()
            topo_order.append(node)
            for adj_node in graph.get(node, []):
                in_degree[adj_node] -= 1
                if in_degree[adj_node] == 0:
                    q.append(adj_node)
        if len(topo_order) == numCourses:
            return topo_order
        else:
            return []

````



## [LeetCode-630. 课程表 III](https://leetcode.cn/problems/course-schedule-iii/)



## [LeetCode-1462. 课程表 IV](https://leetcode.cn/problems/course-schedule-iv/)

