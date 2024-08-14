# DFS-backtracking

"Backtracking"即"回溯法"，除了本章，在下面章节中，也对它进行了论述:

一、`Expert-labuladong\3.1-回溯算法(DFS算法)系列`

> 再看看回溯算法，前文 [回溯算法详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&chksm=9bd7fb2daca0723be888b30345e2c5e64649fc31a00b05c27a0843f349e2dd9363338d0dac61&scene=21#wechat_redirect) 干脆直接说了，回溯算法就是个 N 叉树的前后序遍历问题，没有例外。

上面这段话其实总结得不错，回溯法就是树的 "深度优先遍历+先序+后序"

a、先序、pre-order、pre-action: 

1、判断是否搜索到了一个解

2、有借

b、后序、post-order、post- action:

1、有还

2、需要注意，还的时候一些比较特殊的例子:

[LeetCode-733. 图像渲染-简单](https://leetcode.cn/problems/flood-fill/) 

labuladong [Flood Fill 算法详解](https://mp.weixin.qq.com/s/Y7snQIraCC6PRhj9ZSnlzw) 



## wikipedia [Backtracking](https://en.wikipedia.org/wiki/Backtracking)

> NOTE: “backtracking”即“回溯”。

**Backtracking** is a general [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding all (or some) solutions to some [computational problems](https://en.wikipedia.org/wiki/Computational_problem), notably [constraint satisfaction problems](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem), that incrementally builds **candidates** to the solutions, and abandons a candidate ("backtracks") as soon as it determines that the candidate cannot possibly be completed to a valid solution.[[1\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-1)[[2\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-2)

> NOTE: 上面这段话的最后一句，就点明了backtrack的含义所在，非常精准。



Backtracking can be applied only for problems which admit the concept of a "partial candidate solution" and a relatively quick test of whether it can possibly be completed to a valid solution(剪枝). It is useless, for example, for locating a given value in an unordered table. When it is applicable, however, backtracking is often much faster than [brute force enumeration](https://en.wikipedia.org/wiki/Brute_force_search) of all complete candidates, since it can eliminate（消除） many candidates with a single test.

> NOTE : 上面这段话说明了可以使用backtrack解决的问题
>
> [Backtracking](https://en.wikipedia.org/wiki/Backtracking) VS  [brute force enumeration](https://en.wikipedia.org/wiki/Brute_force_search) 
>
> 剪枝

Backtracking is an important tool for solving [constraint satisfaction problems](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem),[[3\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-BiereHeule2009-3) such as [crosswords](https://en.wikipedia.org/wiki/Crosswords), [verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic), [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku), and many other puzzles. It is often the most convenient (if not the most efficient[*citation needed*]) technique for [parsing](https://en.wikipedia.org/wiki/Parsing),[[4\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-Watson2017-4) for the [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem) and other [combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problems. It is also the basis of the so-called [logic programming](https://en.wikipedia.org/wiki/Logic_programming) languages such as [Icon](https://en.wikipedia.org/wiki/Icon_programming_language), [Planner](https://en.wikipedia.org/wiki/Planner_programming_language) and [Prolog](https://en.wikipedia.org/wiki/Prolog).

Backtracking depends on user-given "[black box procedures](https://en.wikipedia.org/wiki/Procedural_parameter)" that define the problem to be solved, the nature of the partial candidates, and how they are extended into complete candidates. It is therefore a [metaheuristic](https://en.wikipedia.org/wiki/Metaheuristic) （元启发）rather than a specific algorithm – although, unlike many other meta-heuristics, it is guaranteed to find all solutions to a finite problem in a bounded amount of time.

> NOTE: 需要注意的是，backtracking是一种算法框架，或者说是一种算法技术，而不是一种专用的算法。





### Description of the method

The **backtracking algorithm** enumerates a set of ***partial candidates*** that, in principle, could be *completed* in various ways to give all the possible solutions to the given problem. The completion is done incrementally, by a sequence of ***candidate extension steps.***



Conceptually, the **partial candidates** are represented as the nodes of a [tree structure](https://en.wikipedia.org/wiki/Tree_structure), the *potential search tree.* Each partial candidate is the parent of the candidates that differ from it by a single **extension step**; the leaves of the tree are the partial candidates that cannot be extended any further.

The **backtracking algorithm** traverses this search tree [recursively](https://en.wikipedia.org/wiki/Recursion_(computer_science)), from the root down, in [depth-first order](https://en.wikipedia.org/wiki/Depth-first_search). At each node *c*, the algorithm checks whether *c* can be completed to a valid solution. If it cannot, the whole sub-tree rooted at *c* is skipped (***pruned***（剪枝）). Otherwise, the algorithm (1) checks whether *c* itself is a valid solution, and if so reports it to the user; and (2) recursively enumerates all sub-trees of *c*. The two tests and the children of each node are defined by user-given procedures.

Therefore, the *actual search tree* that is traversed by the algorithm is only a part of the potential tree. The total cost of the algorithm is the number of nodes of the actual tree times the cost of obtaining and processing each node. This fact should be considered when choosing the potential search tree and implementing the pruning test.



#### Pseudocode

In order to apply **backtracking** to a specific class of problems, one must provide the data *P* for the particular instance of the problem that is to be solved, and six [procedural parameters](https://en.wikipedia.org/wiki/Procedural_parameter), *root*, *reject*, *accept*, *first*, *next*, and *output*. These procedures should take the instance data *P* as a parameter and should do the following:

1. *root*(*P*): return the partial candidate at the root of the search tree.
2. *reject*(*P*,*c*): return *true* only if the partial candidate *c* is not worth completing.
3. *accept*(*P*,*c*): return *true* if *c* is a solution of *P*, and *false* otherwise.
4. *first*(*P*,*c*): generate the first **extension** of candidate *c*.
5. *next*(*P*,*s*): generate the next alternative **extension** of a candidate, after the extension *s*.
6. *output*(*P*,*c*): use the solution *c* of *P*, as appropriate to the application.

The **backtracking algorithm** reduces the problem to the call *bt*(*root*(*P*)), where *bt* is the following recursive procedure:

```pseudocode
procedure bt(c)
  if reject(P,c) then return
  if accept(P,c) then output(P,c)
  s ← first(P,c)
  while s ≠ NULL do
    bt(s)
    s ← next(P,s)
```

#### Usage considerations

The *reject* procedure should be a [boolean-valued function](https://en.wikipedia.org/wiki/Boolean-valued_function) that returns *true* only if it is certain that no possible extension of *c* is a valid solution for *P*. If the procedure cannot reach a definite conclusion, it should return *false*. An incorrect *true* result may cause the *bt* procedure to miss some valid solutions. The procedure may assume that *reject*(*P*,*t*) returned *false* for every ancestor *t* of *c* in the search tree.

On the other hand, the efficiency of the backtracking algorithm depends on *reject* returning *true* for candidates that are as close to the root as possible. If *reject* always returns *false*, the algorithm will still find all solutions, but it will be equivalent to a brute-force search.

The *accept* procedure should return *true* if *c* is a complete and valid solution for the problem instance *P*, and *false* otherwise. It may assume that the partial candidate *c* and all its ancestors in the tree have passed the *reject*test.

The general pseudo-code above does not assume that the valid solutions are always leaves of the potential search tree. In other words, it admits the possibility that a valid solution for *P* can be further extended to yield other valid solutions.

The *first* and *next* procedures are used by the backtracking algorithm to enumerate the children of a node *c* of the tree, that is, the candidates that differ from *c* by a single extension step. The call *first*(*P*,*c*) should yield the first child of *c*, in some order; and the call *next*(*P*,*s*) should return the next sibling of node *s*, in that order. Both functions should return a distinctive "NULL" candidate, if the requested child does not exist.

Together, the *root*, *first*, and *next* functions define the set of partial candidates and the potential search tree. They should be chosen so that every solution of *P* occurs somewhere in the tree, and no partial candidate occurs more than once. Moreover, they should admit an efficient and effective *reject* predicate.

### Examples

Examples where backtracking can be used to solve puzzles or problems include:

- [Puzzles](https://en.wikipedia.org/wiki/Puzzle) such as [eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle), [crosswords](https://en.wikipedia.org/wiki/Crosswords), [verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic), [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku)[[nb 1\]](https://en.wikipedia.org/wiki/Backtracking#cite_note-6), and [Peg Solitaire](https://en.wikipedia.org/wiki/Peg_solitaire).
- [Combinatorial optimization](https://en.wikipedia.org/wiki/Combinatorial_optimization) problems such as [parsing](https://en.wikipedia.org/wiki/Parsing) and the [knapsack problem](https://en.wikipedia.org/wiki/Knapsack_problem).
- [Logic programming](https://en.wikipedia.org/wiki/Logic_programming) languages such as [Icon](https://en.wikipedia.org/wiki/Icon_programming_language), [Planner](https://en.wikipedia.org/wiki/Planner_programming_language) and [Prolog](https://en.wikipedia.org/wiki/Prolog), which use backtracking internally to generate answers.

The following is an example where backtracking is used for the [constraint satisfaction problem](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem):

#### Constraint satisfaction

The general [constraint satisfaction problem](https://en.wikipedia.org/wiki/Constraint_satisfaction_problem) consists in finding a list of integers *x* = (*x*[1], *x*[2], …, *x*[*n*]), each in some range {1, 2, …, *m*}, that satisfies some arbitrary constraint (boolean function) *F*.

For this class of problems, the instance data *P* would be the integers *m* and *n*, and the predicate *F*. In a typical backtracking solution to this problem, one could define a partial candidate as a list of integers *c* = (*c*[1], *c*[2], …, *c*[k]), for any *k* between 0 and *n*, that are to be assigned to the first *k* variables *x*[1], *x*[2], …, *x*[*k*]. The root candidate would then be the empty list (). The *first* and *next* procedures would then be

```pseudocode
function first(P, c)
  k ← length(c)
  if k = n
    then return NULL
  else return (c[1], c[2], …, c[k], 1)

function next(P, s)
  k ← length(s)
  if s[k] = m
    then return NULL
  else return (s[1], s[2], …, s[k - 1], 1 + s[k])
```

Here *length*(*c*) is the number of elements in the list *c*.



## LeetCode习题汇总

### 解数独系列

[LeetCode-37-解数独](https://leetcode.cn/problems/sudoku-solver/)



### N-皇后系列

LeetCode-51-N-皇后-Hard

LeetCode-52-N-皇后-II-Hard

LeetCode-面试题-08.12-八皇后



### 子集划分系列

[LeetCode-698-划分为k个相等的子集](https://leetcode.cn/problems/partition-to-k-equal-sum-subsets/)

```C++
class Solution
{
	int m_k { 0 }; // 桶的个数
	vector<int> m_buckets; // 所有的桶
	int m_target { 0 }; // 每个桶的目标装载量
public:
	bool canPartitionKSubsets(vector<int> &nums, int k)
	{
		int len = nums.size();
		m_k = k;
		if (m_k > len)
		{
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);

		if (sum % m_k != 0) // 无法均匀分配
			return false;
		m_target = sum / m_k;
		m_buckets.resize(k, 0); // 桶
		sort(nums.begin(), nums.end(), greater<int>()); // 降序
		return DFS(0, nums);
	}
	bool DFS(int index, vector<int> &nums)
	{
		if (index == nums.size()) // 所有的数都放完了
		{
			for (auto &&i : m_buckets)
			{
				if (i != m_target)
				{
					return false;
				}
			}
			return true;
		}
		for (int j = 0; j < m_k; ++j)
		{
			if (nums[index] + m_buckets[j] > m_target) // 第i个数，不应当放入 m_buckets[j] 中
				continue;
			m_buckets[j] += nums[index];
			if (DFS(index + 1, nums))
			{
				return true;
			}
			m_buckets[j] -= nums[index];
		}
		return false;
	}
};
```



### 子集系列

[LeetCode-78-子集-中等](https://leetcode.cn/problems/subsets/)

[LeetCode-90-子集-II-中等](https://leetcode.cn/problems/subsets-ii/) 



### 排列系列

[46. 全排列](https://leetcode.cn/problems/permutations/) 中等



### 查找、穷举所有的可能性

这类题目，章节要求查找所有的可能性，最直接的方法就是回溯法；

1、[LeetCode-39. 组合总和](https://leetcode.cn/problems/combination-sum/) 中等

2、[LeetCode-491. 递增子序列](https://leetcode.cn/problems/increasing-subsequences/) 中等





## 如何避免回溯

如何避免回溯？下面结合了例子进行了说明：

- KMP算法: https://www.cnblogs.com/dusf/p/kmp.html



## Examples

本章给出backtracking算法的例子。

| 例子               | 解空间 | 说明                                                         |
| ------------------ | ------ | ------------------------------------------------------------ |
| 5.2装载问题        | 组合树 | 每个集装箱有两种选择：装入船1或者船2                         |
| 5.3批处理作业调度  | 组合树 | 每个作业有两种选择：使用机器1或者机器2                       |
| 5.4符号三角形问题  | 组合树 | 第一排的每个位置有两个选择：放置正号或者负号                 |
| 5.5n后问题         | 组合树 | 每一行有n个选择：n个皇后之一                                 |
| 5.6 0-1背包问题    | 组合树 | 每个背包有两个选择：装入或者不装入                           |
| 5.8图的m着色问题   | 组合树 | 每个点有m种选择：m种颜色之一                                 |
| 5.10 圆排列问题    | 排列树 | 非常典型的排列问题：第一个位置有n种选择，第二个位置有n-1种选择，......，最后一个位置只有一个选择 |
| 5.11电路板排列问题 | 排列树 | 非常典型的排列问题                                           |
| 5.9旅行售货员问题  | 排列树 | 不是非常典型的排列树问题                                     |
|                    |        |                                                              |



## geeksforgeeks [top-20-backtracking-algorithm-interview-questions](https://www.geeksforgeeks.org/top-20-backtracking-algorithm-interview-questions/)



### Pattern Searching

在字符串（也叫主串）中的定位模式（pattern）问题可以使用回溯法进行解决，但是这种解法是naive的。优化方法是KMP算法，在下面两篇文章中对两种进行了比较分析：

1、cnblogs [详解KMP算法](https://www.cnblogs.com/yjiyjige/p/3263858.html)



### [Eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle)



### [Crosswords](https://en.wikipedia.org/wiki/Crosswords)



### [Verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic)



### [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku)



### [Parsing](https://en.wikipedia.org/wiki/Parsing) 

> NOTE:
>
> 参见[*Compilers: Principles, Techniques, and Tools*](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools)的4.4 Top-Down Parsing，其中介绍了使用backtrack来实现parsing。
>
> 在GitHub中，可以检索非常多的这种项目：
>
> https://github.com/search?utf8=%E2%9C%93&q=backtrack+parse&type=

