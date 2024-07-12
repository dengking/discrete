# Depth-of-nested-parenthesis



## geeksforgeeks [Find maximum depth of nested parenthesis in a string](https://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string/) 



### algorithm

#### Method 1 (Uses Stack) 



#### Method 2 ( O(1) auxiliary space ) 


```c++
// A C++ program to find the maximum depth of nested 
// parenthesis in a given expression 
#include <iostream>
using namespace std;

// function takes a string and returns the 
// maximum depth nested parenthesis 
int maxDepth(string S)
{
        int current_max = 0; // current count 
        int max = 0; // overall maximum count 
        int n = S.length();

        // Traverse the input string 
        for (int i = 0; i< n; i++)
        {
                if (S[i] == '(')
                {
                        current_max++;

                        // update max if required 
                        if (current_max> max)
                                max = current_max;
                }
                else if (S[i] == ')')
                {
                        if (current_max>0)
                                current_max--;
                        else
                                return -1;
                }
        }

        // finally check for unbalanced string 
        if (current_max != 0)
                return -1;

        return max;
}

// Driver program 
int main()
{
        string s = "( x )";
        cout << maxDepth(s);
        return 0;
}

```



## [LeetCode 32. 最长有效括号-困难](https://leetcode.cn/problems/longest-valid-parentheses/)



### [苏灿](https://leetcode.cn/u/su-can-t/) # [超简单方法，只会括号匹配就行](https://leetcode.cn/problems/longest-valid-parentheses/solutions/2719468/chao-jian-dan-fang-fa-zhi-hui-gua-hao-pi-nbby/)

> NOTE:
>
> 1. 这种方法很简单

题目为找到括号匹配成功的最长连续字符，我们可以进行问题转化。这里有两个关键点。

1. 匹配成功

2. 最长连续

因此，分别模拟以上两个过程即可: 

首先是“匹配成功”，这个用栈来实现。为了给第2步做准备，我们要在匹配成功时做个记号，这里开辟一个数组，匹配成功时，在'('和")'的索引位置处记为1。然后统计数组里面连续1的个数，最长的那个就是结果



```python
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        labels = [0] * len(s)  # 标记
        stk = []
        for i in range(len(s)):
            c = s[i]
            if c == '(':
                stk.append(i)
            elif c == ')':
                if stk and s[stk[-1]] == '(':
                    labels[stk[-1]], labels[i] = 1, 1
                    stk.pop()
        cnt = 0  # 统计连续1的个数
        ans = 0
        for i in range(len(labels)):
            if labels[i]:
                cnt += 1
                ans = max(cnt, ans)
            else:
                cnt = 0
        return ans

```



### DP

定义 $dp[i]$ 表示以下标 *i* 字符结尾的**最长连续且有效括号**的长度，显然有效的**子串**一定以 ‘)’ 结尾，因此我们可以知道以 ‘(’ 结尾的子串对应的 *dp* 值必定为 0 ，我们只需要求解 ‘)’ 在 *dp* 数组中对应位置的值。

> Draft: 对于每个`)`，它要么和位于它前面的一个`(`进行配对；要么和它前面的已经配对部分的前面的一个`(`进行配对。下面用数学语言进行描述

从前往后遍历字符串求解 *dp* 值，我们每两个字符检查一次：

1. $s[i]=)$ 且 $s[i−1]=($，也就是字符串形如 “……()”，我们可以推出：
   $$
   dp[i]=dp[i−2]+2
   $$
    

2. $s[i]=)$ 且 $s[i−1]=)$，也就是字符串形如 “……))”，我们可以推出：如果 $s[i−dp[i−1]−1]=($，那么 
   $$
   dp[i]=dp[i−1]+dp[i−dp[i−1]−2]+2
   $$
   

#### C++

```c++
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int maxans = 0, n = s.length();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(') {
                    dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                }
                maxans = max(maxans, dp[i]);
            }
        }
        return maxans;
    }
};

```



## [LeetCode-1111. 有效括号的嵌套深度](https://leetcode.cn/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/)



## [LeetCode-1614. 括号的最大嵌套深度](https://leetcode.cn/problems/maximum-nesting-depth-of-the-parentheses/)

仿照 geeksforgeeks [Find maximum depth of nested parenthesis in a string](https://www.geeksforgeeks.org/find-maximum-depth-nested-parenthesis-string/) 写的

```python
class Solution:
    def maxDepth(self, s: str) -> int:
        depth, max_depth = 0, 0
        for c in s:
            if c == '(':
                depth += 1
                max_depth = max(max_depth, depth)
            elif c == ')' and depth:
                depth -= 1
        return max_depth

```

