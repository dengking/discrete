# Generate-Dyck-language

生成Dyck language，等价于加括号，很多问题都可以转换为生成Dyck language:

wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) # [Generalizations](https://en.wikipedia.org/wiki/Matrix_chain_multiplication#Generalizations)

> The matrix chain multiplication problem generalizes to solving a more abstract problem: given a linear sequence of objects, an **associative binary operation** on those objects, and a way to compute the **cost** of performing that operation on any two given objects (as well as all partial results), compute the minimum cost way to group the objects to apply the operation over the sequence.

draft: 其实就是expression tree

draft: 括号和binary operator对应



## Algo: DFS backtrack



## Algo: DP

[LeetCode-【最简单易懂的】动态规划](https://leetcode.cn/problems/generate-parentheses/solutions/9251/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/) 

> 考虑 `i=n` 时相比 `n-1` 组括号增加的那一组括号的位置

draft: given a linear sequence of objects, enumerate the position to split/separate the sequence into two subsequences, 在断开位置的左侧subsequence括上一对括号, 右侧subsequence括上一对括号，从而将它们连接起来

wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) example:

```
(A)(BCD)
(AB)(CD)
(ABC)(D)
```

draft: binary operator、二分: 将sequence一分为二(left、right)

draft: 乘法原理

## Generate Parentheses



### gpt-4o generate n pairs of matched parentheses using dynamic programming

Certainly! Generating all valid combinations of \( n \) pairs of matched parentheses using dynamic programming involves constructing the combinations incrementally. Let's break down the algorithm step by step.

#### Problem Statement

Given \( n \), generate all combinations of \( n \) pairs of matched parentheses.

#### Dynamic Programming Approach

The idea is to use a dynamic programming table to store the valid combinations of parentheses for each length up to \( 2n \). The table will be filled incrementally, ensuring that each combination is valid.

#### Detailed Explanation

1. **Initialization**:
   - We initialize a list `dp` where `dp[i]` will store all valid combinations of \( i \) pairs of parentheses.
   - `dp[0]` is initialized to `[""]` because there is one valid combination of 0 pairs of parentheses, which is the empty string.

2. **Filling the DP Table**:
   - We iterate over the number of pairs of parentheses from 1 to \( n \).
   - For each number of pairs \( i \), we generate combinations by splitting the problem into smaller subproblems.
   - We use two nested loops to iterate over possible positions to split the combination:
     - The outer loop iterates over the number of pairs \( j \) that can be placed inside the first pair of parentheses.
     - The inner loop iterates over the remaining pairs \( i - 1 - j \) that can be placed outside the first pair of parentheses.
   - For each valid combination of \( j \) pairs inside and \( i - 1 - j \) pairs outside, we construct a new valid combination by combining these parts.

3. **Combining Parts**:
   - For each combination of \( j \) pairs inside and \( i - 1 - j \) pairs outside, we construct a new valid combination by placing the inside part within a pair of parentheses and concatenating it with the outside part.
   - This ensures that the resulting combination is valid.

#### Python Implementation

Here is the Python function with detailed comments to generate all valid combinations of \( n \) pairs of matched parentheses:

```python
from typing import *


def generate_parentheses(n: int):
    # Initialize the DP table
    dp: List[List[str]] = [[] for _ in range(n + 1)]
    dp[0] = [""]  # Base case: one valid combination of 0 pairs of parentheses

    # Fill the DP table
    for i in range(1, n + 1):
        for j in range(i):  # split position
            for left in dp[j]:
                for right in dp[i - 1 - j]:
                    dp[i].append("(" + left + ")" + right)

    return dp[n]


if __name__ == '__main__':
    # Example usage
    n = 3
    parentheses_combinations = generate_parentheses(n)
    for combination in parentheses_combinations:
        print(combination)

```

> NOTE:
>
> 一. [LeetCode-【最简单易懂的】动态规划](https://leetcode.cn/problems/generate-parentheses/solutions/9251/zui-jian-dan-yi-dong-de-dong-tai-gui-hua-bu-lun-da/) 
>
> > 考虑 `i=n` 时相比 `n-1` 组括号增加的那一组括号的位置
>
> 
>
> > 既然知道了 i<n 的情况，那我们就可以对所有情况进行遍历：
> >
> > "(" + 【i=p时所有括号的排列组合】 + ")" + 【i=q时所有括号的排列组合】
> >
> > 其中 p + q = n-1，且 p q 均为非负整数。
> >
> > 事实上，当上述 p 从 0 取到 n-1，q 从 n-1 取到 0 后，所有情况就遍历完了。
>
> 二. 乘法原理
>
> 内部嵌套的left-right循环实现的是乘法

#### Explanation of the Code:

1. **Initialization**:
   - `dp = [[] for _ in range(n + 1)]`: Creates a list of empty lists for each number of pairs from 0 to \( n \).
   - `dp[0] = [""]`: Sets the base case where there is one valid combination of 0 pairs of parentheses, which is the empty string.

2. **Filling the DP Table**:
   - `for i in range(1, n + 1)`: Iterates over the number of pairs of parentheses from 1 to \( n \).
   - `for j in range(i)`: Iterates over the possible positions to split the combination.
   - `for left in dp[j]`: Iterates over the valid combinations of \( j \) pairs of parentheses.
   - `for right in dp[i - 1 - j]`: Iterates over the valid combinations of \( i - 1 - j \) pairs of parentheses.
   - `dp[i].append("(" + left + ")" + right)`: Constructs a new valid combination by placing the `left` part inside a pair of parentheses and concatenating it with the `right` part.

#### Example Output:

For \( n = 3 \):

```
((()))
(()())
(())()
()(())
()()()
```

#### Explanation of the Output:

- `((()))`: All pairs of parentheses are nested.
- `(()())`: One pair of parentheses is nested inside another pair.
- `(())()`: Two pairs of parentheses are nested, followed by an independent pair.
- `()(())`: One pair of parentheses is followed by a nested pair.
- `()()()`: All pairs of parentheses are independent.

## LeetCode

Type: 单纯的计算数量

[LeetCode-22. Generate Parentheses-middle](https://leetcode.cn/problems/generate-parentheses/) 

由于括号都相同，因此只和subsequence的长度有关，因此它的dp array是一维的

[LeetCode-96. Unique Binary Search Trees-middle](https://leetcode.cn/problems/unique-binary-search-trees/) 

它仅仅计数，数量之和subsequence的长度有关，因此它的dp array是一维的

Type: 枚举所有解

[LeetCode-95. Unique Binary Search Trees II-middle](https://leetcode.cn/problems/unique-binary-search-trees-ii/) 

[LeetCode-894. All Possible Full Binary Trees-Medium](https://leetcode.cn/problems/all-possible-full-binary-trees/): 所有的node的value都是0，因此只和长度有关，因此它的dp array是一维的 

Type: 计算最优解 

Matrix chain multiplication

draft: 上述一维dp和二位dp的区别，让我想到了高中时候学习排列组合的时候，遇到的颜色相同、颜色不同的小球的问题

## [LeetCode-22. Generate Parentheses-middle](https://leetcode.cn/problems/generate-parentheses/)



### DFS+backtrack+path+prunc

Python

参考的 gpt-4o Dyck path # Generating Dyck Paths 写的

```python
from typing import *


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        ans = []
        self.dfs('', n, 0, 0, ans)
        return ans

    def dfs(self, path: str, n, open_cnt: int, close_cnt: int, ans: List[str]):
        if open_cnt == close_cnt == n:
            ans.append(path)
            return
        if open_cnt < n:
            self.dfs(path + '(', n, open_cnt + 1, close_cnt, ans)
        if close_cnt < open_cnt:
            self.dfs(path + ')', n, open_cnt, close_cnt + 1, ans)

```

C++

labuladong [回溯算法最佳实践：合法括号生成](https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g) 

```c++
#include <algorithm>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
    vector<string> result;
public:
    vector<string> generateParenthesis(int n) {
        string path;
        path.reserve(n * 2);
        dfs(0, n, path, 0, 0);
        return result;
    }

private:
    void dfs(int i, int n, string &path, int leftCnt, int rightCnt) {
        /**
         * 剪枝
         */
        if (leftCnt < rightCnt) {
            return;
        }
        /**
         * 剪枝
         */
        if (leftCnt > n) {
            return;
        }
        if (i == 2 * n) {
            if (leftCnt == rightCnt) {
                result.push_back(path);
            }
            return;
        }
        /**
         * 选择: 插入(
         */
        path.push_back('(');
        dfs(i + 1, n, path, leftCnt + 1, rightCnt);
        path.pop_back();
        /**
         * 选择: 插入)
         */
        path.push_back(')');
        dfs(i + 1, n, path, leftCnt, rightCnt + 1);
        path.pop_back();
    }
};

// Driver code
int main() {

    Solution s;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### DP

```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
    # Initialize the DP table
    dp: List[List[str]] = [[] for _ in range(n + 1)]
    dp[0] = [""]  # Base case: one valid combination of 0 pairs of parentheses

    # Fill the DP table
    for i in range(1, n + 1):
        for j in range(i):  # split position
            for left in dp[j]:
                for right in dp[i - 1 - j]:
                    dp[i].append("(" + left + ")" + right)

    return dp[n]
```



## LeetCode Unique Binary Search Trees Serial

Q: 给定一个sorted sequence，如何构建binary search tree？

A: 递归构造: 

i => root node

i< => left tree

i> => right tree



### [LeetCode-96. Unique Binary Search Trees-middle](https://leetcode.cn/problems/unique-binary-search-trees/) 

#### DP



[LeetCode-画手大鹏](https://leetcode.cn/u/guanpengchn/) # [画解算法：96. 不同的二叉搜索树](https://leetcode.cn/problems/unique-binary-search-trees/solutions/6693/hua-jie-suan-fa-96-bu-tong-de-er-cha-sou-suo-shu-b/) 

假设 `n` 个节点存在二叉排序树的个数是 `G (n)`，令 `f(i)` 为以 `i` 为根的二叉搜索树的个数，则
$$
G(n) = f(1) + f(2) + f(3) + f(4) + \dots + f(n)  
$$
当 `i` 为**根节点**时，其**左子树**节点个数为 `i-1` 个，**右子树**节点为 `n-i`，则
$$
f(i) = G(i-1) \times G(n-i)
$$
综合两个公式可以得到 [卡特兰数](https://leetcode.cn/link/?target=https%3A%2F%2Fbaike.baidu.com%2Fitem%2F卡特兰数) 公式
$$
G(n) = G(0) \times G(n-1) + G(1) \times G(n-2) + \dots + G(n-1) \times G(0)
$$


```python
class Solution:
    def numTrees(self, n: int) -> int:
        dp = [0] * (n + 1) # G (n)
        dp[0] = 1
        dp[1] = 1
        for i in range(2, n + 1):
            for j in range(1, i + 1):  # 枚举root node
                dp[i] += dp[j - 1] * dp[i - j]
        return dp[n]

```



### [LeetCode-95. Unique Binary Search Trees II-middle](https://leetcode.cn/problems/unique-binary-search-trees-ii/) 



#### DP



```python
from typing import *


class TreeNode:
    """Definition for a binary tree node."""

    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def generateTrees(self, n: int) -> List[Optional[TreeNode]]:
        # dp[i, j] 表示用 i .. j 构建的二叉搜索树的所有根节点列表
        # 枚举树根节点k in range(i, j + 1)
        # dp[i, k - 1] 为所有左子树可能的根节点列表
        # dp[k + 1, j] 为所有右子树可能的根节点列表
        dp: List[List[List[Optional[TreeNode]]]] = [[[None] for _ in range(n + 2)] for _ in range(n + 2)]
        for seq_len in range(1, n + 1):  # length of sequence
            # i + seq_len <= n + 1 ==> i <= n + 1 - seq_en
            for i in range(1, n + 2 - seq_len):
                j = i + seq_len - 1
                dp[i][j] = []  # 初始化值
                for root in range(i, j + 1):
                    for left in dp[i][root - 1]:
                        for right in dp[root + 1][j]:
                            dp[i][j].append(TreeNode(root, left, right))

        return dp[1][n]


if __name__ == '__main__':
    solu = Solution()
    solu.generateTrees(4)

```



## [LeetCode-894. All Possible Full Binary Trees-Medium](https://leetcode.cn/problems/all-possible-full-binary-trees/) 

[力扣官方题解](https://leetcode.cn/u/leetcode-solution/) # [所有可能的真二叉树](https://leetcode.cn/problems/all-possible-full-binary-trees/solutions/2713780/suo-you-ke-neng-de-zhen-er-cha-shu-by-le-1uku/)

### 方法一：分治

**真二叉树**中的每个结点的子结点数是 0 或 2，此时可以推出**真二叉树**中的结点数 *n* 为奇数，可以使用数学归纳法证明：

- 当**真二叉树**中只有 1 个结点时，此时 1 为**奇数**，树中唯一的结点是**根结点**
- 当**真二叉树**中有 *n* 个结点时，根据**真二叉树**的定义，此时可将其中一个叶结点增加两个子结点之后仍为**真二叉树**，新的**真二叉树**中有 *n*+2 个结点，由于 *n* 是奇数，此时 *n*+2 也是奇数

由于**真二叉树**中的结点数一定是奇数，因此当给定的节点数 *n* 是偶数时，此时无法构成真二叉树，返回空值即可。当**真二叉树**节点数目 *n* 大于 1 时，此时**真二叉树**的左子树与右子树也一定为**真二叉树**，则此时左子树的节点数目与右子树的节点数目也一定为**奇数**。

当 *n* 是奇数时，*n* 个结点的**真二叉树**满足左子树和右子树的结点数都是奇数，此时左子树和右子树的结点数之和是 *n*−1，假设左子树的数目为 *i*，则左子树的节点数目则为 *n*−1−*i*，则可以推出**左子树**与**右子树**的节点数目序列为：

[(1,*n*−2),(3,*n*−4),(5,*n*−6),⋯,(*n*−2,1)]

假设我们分别构节点数目为 *i* 和节点数目为 *n*−1−*i* 的**真二叉树**，即可构造出 *n* 个结点的**真二叉树**。我们可以利用分治来构造**真二叉树**，分治的终止条件是 *n*=1。



```python
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        full_binary_trees = []
        if n % 2 == 0:
            return full_binary_trees
        if n == 1:
            full_binary_trees.append(TreeNode(0))
            return full_binary_trees
        for i in range(1, n, 2):
            left_subtrees = self.allPossibleFBT(i)
            right_subtrees = self.allPossibleFBT(n - 1 - i)
            for left_subtree in left_subtrees:
                for right_subtree in right_subtrees:
                    root = TreeNode(0, left_subtree, right_subtree)
                    full_binary_trees.append(root)
        return full_binary_trees

```

### 方法二：动态规划

```python
class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        if n % 2 == 0:
            return []
    
        dp = [[] for _ in range(n + 1)]
        dp[1] = [TreeNode(0)]
        for i in range(3, n + 1, 2):
            for j in range(1, i, 2):
                for leftSubtree in dp[j]:
                    for rightSubtree in dp[i - 1 - j]:
                        root = TreeNode(0, leftSubtree, rightSubtree)
                        dp[i].append(root)
        return dp[n]

```



## Matrix Chain Multiplication/矩阵连乘的最优计算次序问题

素材

- geeksforgeeks [Matrix Chain Multiplication | DP-8](https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/) 
- wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) 

### 问题描述

**矩阵连乘的最优次序问题**解决的是多个矩阵连乘次数的问题，可以将这些矩阵看做是一个**矩阵链**；对它进行递归就可以将原长的矩阵链切割为两个**子链**，然后将两个**子链**相乘；不同的切割方案导致**子链**的长度问题，不同长度的子链它们的乘法次数也是不同的；可以根据它得到更长的**矩阵链**的乘法次数；

### step1分析最优解的结构

将**矩阵链**记为$A_iA_{i+1} \dots A_j$，简记为$A[i:j]$。

考察计算$A[1:n]$的最优计算次序问题：设这个计算次序在$A_k$和$A_{k+1}$之间将**矩阵链**断开，$1 \le k \lt n$，则其相应的完全加括号方式为$ (A_1 \dots A_{k}) (A_{k+1} \ldots A_n)$。依照此次序，先计算$A[1:k]$和$A[k+1, n]$，然后将计算结果相乘得到$A[1:n]$。

这个问题的一个关键特征是：计算$A[1:n]$最优次序所包含的计算矩阵子链$A[1:k]$和$A[k+1, n]$的次序也是最优的。因此，矩阵连乘计算次序问题的最优解蕴含着其子问题的最优解，这种性质称为**最优子结构性质**。



### step2建立递归关系

设计**动态规划算法**的第2步是递归地定义**最优值**。设$A[i:j], 1 \le i\le j \le n$，所需的最少乘法次数是$m[i][j]$，则原问题的**最优值**为$m[1][n]$。
$$
m[i][j] = 
\begin{cases}
0, & i=j \\
\min\limits_{i \le k \lt j} \{ m[i][k] + m[k+i][j] + p_{i-1}p_k p_j \} & i \lt j 
\end{cases}
$$

$m[i][j]$给出了最优解，同时还确定了$A[i:j]$的最优次序中的断开位置$k$，若将对应于$m[i][j]$的断开位置$k$记为$s[i][j]$，在计算出最优值$m[i][j]$后，可递归地由$s[i][j]$构造出相应的最优解。

> NOTE: $i=j$是递归关系中的base case，是递归的终止条件；

在矩阵连乘问题中，如何来定义和保存子问题的解呢？使用二维表来保存的是不同长度的矩阵链的乘法次数，二维表的第一维是矩阵链的起始位置，第二维是矩阵链的终止位置；



### step3计算最优值

输入参数$p_0, p_1, \dots , p_n$存储于数组$p$中，算法除了输出最优值数组`m`外，还输出记录最优断开位置的数组`s`。

```c++
void MatrixChain(int *p, int n, int **m, int **s)
{
    for (int i = 0; i < n; ++i)
        m[i][i] = 0;
    for (int chain_length = 2; chain_length <= n; ++chain_length) // 矩阵链的长度
    {
        for (int i = 0; i < n - chain_length; ++i)
        {
            int j = i + chain_length - 1; // 子链的终止位置
            // 下面使用打擂台的方式选出最优解
            m[i][j] = m[i + 1][j] + p[i - 1] * p[i] * p[j];
            s[i][j] = i;
            for (int k = i + 1; k < j; ++k)
            {
                int t = m[i][k] + m[k + 1][j] + p[k - 1] * p[k] * p[j];
                if (t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}
```

时间复杂度：$O(n^3)$

空间复杂度：$O(n^2)$

### step4构造最优解

$s[i][j]$表示的是计算$A[i:j]$的最佳断开位置；所以矩阵链$A[1:n]$的最佳断开位置为$s[1][n]$，从它可以得到两个子链$A[1:s[1][n]]$、$A[s[1][n] + 1:n]$，而这两个子链的断开位置又可以通过查表得到，显然这是一个递归的过程，使用如下函数可以实现将解输出：

```c++
void TraceBack(int i, int j, int **s){
	if( i == j)return;
	TraceBack(i, s[i][j], s);
	TraceBack(s[i][j] + 1, j, s);
	cout<<"Multiply A"<<i<<","<<s[i][j];
	cout<<"and A"<<(s[i][j]+1)<<","<<j<<endl;
}
```

> NOTE: 
>
> 1、二叉树的深度优先搜索



### gpt-4o

Matrix Chain Multiplication is a classic optimization problem that can be solved using dynamic programming. The goal is to determine the most efficient way to multiply a given sequence of matrices. The problem is not to perform the multiplications but to decide the order in which to perform the multiplications.

#### Problem Statement

Given a sequence of matrices \( $A_1, A_2, \ldots, A_n$ \), where the dimensions of matrix \( $A_i$ \) are \( $p_{i-1} \times p_i$ \), the task is to find the minimum number of scalar multiplications needed to compute the product \( $A_1A_2 \ldots A_n$ \).

#### Dynamic Programming Approach

We use a table `m` where `m[i][j]` represents the minimum number of scalar multiplications needed to compute the matrix \( $A_i$ \) to \( $A_j$ \). The table is filled in a bottom-up manner.

#### Python Implementation

Here is a Python function to solve the Matrix Chain Multiplication problem using dynamic programming:

```python
from typing import *


def matrix_chain_order(p: List[int]):
    n = len(p) - 1  # Number of matrices
    dp: List[List[int]] = [[0 for _ in range(n)] for _ in range(n)]
    solution: List[List[int]] = [[0 for _ in range(n)] for _ in range(n)]

    # m[i][i] = 0 for all i
    for i in range(n):
        dp[i][i] = 0

    # l is the chain length
    for l in range(2, n + 1):
        for i in range(n - l + 1):
            j = i + l - 1
            dp[i][j] = float('inf')
            for k in range(i, j):
                q = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1]
                if q < dp[i][j]:
                    dp[i][j] = q
                    solution[i][j] = k

    return dp, solution


def print_optimal_parens(s, i, j):
    if i == j:
        print(f"A{i + 1}", end="")
    else:
        print("(", end="")
        print_optimal_parens(s, i, s[i][j])
        print_optimal_parens(s, s[i][j] + 1, j)
        print(")", end="")


if __name__ == '__main__':
    # Example usage
    p = [30, 35, 15, 5, 10, 20, 25]  # Dimensions of matrices
    m, s = matrix_chain_order(p)

    print("Minimum number of multiplications is:", m[0][len(p) - 2])
    print("Optimal parenthesization is:", end=" ")
    print_optimal_parens(s, 0, len(p) - 2)
    print()

```

#### Explanation:

1. **Initialization**:
   - `n = len(p) - 1`: Number of matrices.
   - `m = [[0 for _ in range(n)] for _ in range(n)]`: Table to store the minimum number of multiplications.
   - `s = [[0 for _ in range(n)] for _ in range(n)]`: Table to store the split points.

2. **Base Case**:
   - `m[i][i] = 0`: No cost to multiply one matrix.

3. **Filling the Table**:
   - `for l in range(2, n + 1)`: Iterate over the chain length.
   - `for i in range(n - l + 1)`: Iterate over the starting index of the chain.
   - `j = i + l - 1`: Ending index of the chain.
   - `m[i][j] = float('inf')`: Initialize the cost to infinity.
   - `for k in range(i, j)`: Iterate over the possible split points.
   - `q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1]`: Calculate the cost of multiplying the matrices.
   - `if q < m[i][j]`: Update the minimum cost and the split point.

4. **Printing the Optimal Parenthesization**:
   - `print_optimal_parens(s, i, j)`: Recursively print the optimal parenthesization.

#### Example Output:

For the input dimensions `p = [30, 35, 15, 5, 10, 20, 25]`:

```
Minimum number of multiplications is: 15125
Optimal parenthesization is: ((A1(A2A3))((A4A5)A6))
```

This output



## [LeetCode-241. 为运算表达式设计优先级-中等](https://leetcode.cn/problems/different-ways-to-add-parentheses/) 

abstract syntax tree binary expression tree

### 分治

```python
class Solution:
    def diffWaysToCompute(self, input: str) -> List[int]:
        # 如果只有数字，直接返回
        if input.isdigit():
            return [int(input)]

        res = []
        for i, char in enumerate(input):
            if char in ['+', '-', '*']:
                # 1.分解：遇到运算符，计算左右两侧的结果集
                # 2.解决：diffWaysToCompute 递归函数求出子问题的解
                left = self.diffWaysToCompute(input[:i])
                right = self.diffWaysToCompute(input[i+1:])
                # 3.合并：根据运算符合并子问题的解
                for l in left:
                    for r in right:
                        if char == '+':
                            res.append(l + r)
                        elif char == '-':
                            res.append(l - r)
                        else:
                            res.append(l * r)

        return res

```

### DP

[京城打工人](https://leetcode.cn/u/capital-worker/) # [为运算表达式设计优先级【递归+动态规划】](https://leetcode.cn/problems/different-ways-to-add-parentheses/solutions/1636760/wei-yun-suan-biao-da-shi-she-by-jiang-hu-0pf0/)
