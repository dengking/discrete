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

draft: given a linear sequence of objects, enumerate the position to split/separate the sequence into two subsequences, 在断开位置的左侧subsequence括上一对括号, 右侧subsequence括上一对括号

wikipedia [Matrix chain multiplication](https://en.wikipedia.org/wiki/Matrix_chain_multiplication) example:

```
(A)(BCD)
(AB)(CD)
(ABC)(D)
```

draft: binary operator、二分: 将sequence一分为二(left、right)

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

