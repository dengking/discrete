# Topological sorting



## Guide: DFS VS BFS

两种算法:DFS和BFS，相比之下，BFS是更加容易理解的，因为它是符合我们直接进行topological sorting的顺序的。

使用 "入度" 和 "长度"概念来对DFS和BFS进行理解:

|                 | DFS                                                          | BFS                                                          |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
|                 | 一个node，如果它的 "入度"  为0，则表示它没有依赖其他节点，它是**低阶课程**，应该优先学习 | 一个node，如果它的 "出度"  为0，则表示没有其它节点依赖它，它是**高阶课程**，应该最后学习 |
|                 | BFS优先寻找**低阶课程**，将它放到**队首**；                  | DFS优先寻找**高阶课程**，将它放到**栈底**；                  |
|                 | BFS中只需要**入度**即可: 它根据**入度**来寻找**低阶课程**；某个节点的入度如果非0，则表示它存在依赖； | DFS中只需要**出度**即可: 它根据**出度**来寻找**高阶课程**；  |
| data structure  | BFS使用queue；                                               | DFS使用stack；                                               |
| circle deadloop | BFS不需要处理circle deadloop                                 | DFS需要处理circle deadloop: 如果存在circle，那么在DFS circle的时候，肯定会回到原点，因此可以据此来判定是否有circle，一旦有circle，则直接break即可。 |
|                 | BFS其实是**正向排序**，它借助queue；                         | DFS其实是**逆向排序**，再借助stack进行逆向，从而可以得到正确的顺序 |
|                 |                                                              |                                                              |



### dependency graph

首先需要根据 `prerequisites` 数组构建出dependency graph，这样能够找到它的相邻节点，原味给出的解法中都是使用的**adjacent list**，题目描述如下:

> 在选修某些课程之前需要一些先修课程。 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，表示如果要学习课程 ai 则 必须 先学习课程  bi 。

则说明在dependency graph中，存在从bi->ai的边，也就说明ai位于bi的adjacency list中

## LeetCode [207. 课程表](https://leetcode.cn/problems/course-schedule/) # [力扣官方题解](https://leetcode.cn/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/)

> NOTE: 
>
> 这个题只需要判断是否存在circle，即circle detection

1、如果图 `G` 中存在环（即图 `G` 不是「有向无环图」），那么图 `G` 不存在**拓扑排序**。

这是因为假设图中存在环 $x_1, x_2, \cdots, x_n, x_1$ ，那么 $x_1$ 在排列中必须出现在 $x_n$的前面，但 $x_n$ 同时也必须出现在 $x_1$  的前面，因此不存在一个满足要求的排列，也就不存在拓扑排序；

> NOTE: 
>
> 一、上述使用的是反证法: 自相矛盾
>
> 二、在实现topological sorting的时候，一个非常重要的问题是circle，一旦有circle则无法进行topological sorting

2、如果图 $G$ 是有向无环图，那么它的拓扑排序可能不止一种。举一个最极端的例子，如果图 $G$ 值包含 $n$ 个节点却没有任何边，那么任意一种编号的排列都可以作为拓扑排序。

### 方法一：深度优先搜索

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
> ![](./graph-with-circle.jpg)
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



### 方法二: 广度优先搜索

> NOTE: 
>
> 二、广度优先搜索的含义是: 在算法中，对于所有入度为0的节点，找到它的所有的邻接节点，对每个邻接节点进行处理: 降低它们的入度
>
> 三、一些note: 
>
> 1、找到没有被依赖的
>
> 2、使用dependency relation构建的structure，如果能够进行**topological sorting**，则会形成**hierarchy structure**。
>
> 3、沿着relation的分析不断地向下寻找，直到找到一个没有任何依赖的
>
> 4、这让我想起了topological sorting中，找到没有任何依赖的那个节点，然后反向不断地删减；其实，它和析构一个linked list是非常类似的，它们本质上都是对依赖关系的删除

方法一的深度优先搜索是一种「逆向思维」：最先被放入栈中的节点是在拓扑排序中最后面的节点。我们也可以使用正向思维，顺序地生成拓扑排序，这种方法也更加直观。

> NOTE: 
>
> 这种方式是更加容易理解的

上面的想法类似于**广度优先搜索**，因此我们可以将**广度优先搜索**的流程与**拓扑排序**的求解联系起来。

#### **算法**

我们使用一个队列来进行**广度优先搜索**。初始时，所有入度为 0 的节点都被放入队列中，它们就是可以作为拓扑排序最前面的节点，并且它们之间的相对顺序是无关紧要的。

```C++
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Solution {
private:
	vector<vector<int>> edges; // adjacency list
	vector<int> indeg; // 节点的入度

public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		edges.resize(numCourses);
		indeg.resize(numCourses);
		for (const auto& info : prerequisites) {
			edges[info[1]].push_back(info[0]);
			++indeg[info[0]];
		}

		queue<int> q;
		// 将入度为0的节点放入到queue中
		// 这个for循环非常有必要，因为graph可能是非联通图，加上这个for能够保证graph中的每个节点被access到
		for (int i = 0; i < numCourses; ++i) {
			if (indeg[i] == 0) {
				q.push(i);
			}
		}

		int visited = 0;// 答案、已经sort的节点个数
		while (!q.empty()) {
			++visited;
			int u = q.front();
			q.pop();
			for (int v : edges[u]) {
				--indeg[v];
				if (indeg[v] == 0) {
					q.push(v);
				}
			}
		}

		return visited == numCourses;
	}
};

int main()
{
	Solution s;
	int numCourses = 2;
	vector<vector<int>> prerequisites{ {1,0} };
	cout << s.canFinish(numCourses, prerequisites) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -Werror

```





## wikipedia [Topological sorting](https://en.wikipedia.org/wiki/Topological_sorting)

In [computer science](https://en.wikipedia.org/wiki/Computer_science), a **topological sort** or **topological ordering** of a [directed graph](https://en.wikipedia.org/wiki/Directed_graph) is a [linear ordering](https://en.wikipedia.org/wiki/Total_order) of its [vertices](https://en.wikipedia.org/wiki/Vertex_(graph_theory)) such that for every directed edge *uv* from vertex *u* to vertex *v*, *u* comes before *v* in the ordering. 

> NOTE: 
> 1、linear ordering是一个logical structure

For instance, the vertices of the graph may represent tasks to be performed, and the edges may represent constraints that one task must be performed before another; in this application, a topological ordering is just a valid sequence for the tasks. 

> NOTE: 
> 1、上述是典型的dependency graph

A topological ordering is possible if and only if the graph has no [directed cycles](https://en.wikipedia.org/wiki/Directed_cycle), that is, if it is a [directed acyclic graph](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (DAG). Any DAG has at least one topological ordering, and [algorithms](https://en.wikipedia.org/wiki/Algorithm) are known for constructing a topological ordering of any DAG in [linear time](https://en.wikipedia.org/wiki/Linear_time). Topological sorting has many applications especially in ranking problems such as [feedback arc set](https://en.wikipedia.org/wiki/Feedback_arc_set).

## 素材

labuladong [拓扑排序，YYDS！](https://mp.weixin.qq.com/s/7nP92FhCTpTKIAplj_xWpA)

jianshu [拓扑排序(一)——有向图成环检测](https://www.jianshu.com/p/d6042b659f70)

csdn [[ZZ]如何判断有向图是否成环](https://blog.csdn.net/leonsc/article/details/5973209)

csdn [数据结构 图 有向无环图](https://blog.csdn.net/nomad2/article/details/1559664)

csdn [拓扑排序判断有向图是否成环](https://blog.csdn.net/qq_40642465/article/details/80670269)



## Implementation

github [Algo-Tree](https://github.com/Algo-Phantoms/Algo-Tree)/[Code](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code)/[C++](https://github.com/Algo-Phantoms/Algo-Tree/tree/main/Code/C%2B%2B)/[Topological_sort.cpp](https://github.com/Algo-Phantoms/Algo-Tree/blob/main/Code/C%2B%2B/Topological_sort.cpp)



## LeetCode 课程表
https://leetcode.cn/problems/course-schedule/solution/ke-cheng-biao-by-leetcode-solution/

https://leetcode.cn/problems/course-schedule-ii/solution/ke-cheng-biao-ii-by-leetcode-solution/


https://leetcode.cn/problems/course-schedule-iv/

