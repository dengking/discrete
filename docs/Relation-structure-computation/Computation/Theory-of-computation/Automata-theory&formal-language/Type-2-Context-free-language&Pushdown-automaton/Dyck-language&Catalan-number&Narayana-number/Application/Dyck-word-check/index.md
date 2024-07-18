

# Check Dyck-language

素材：

- geeksforgeeks [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)

- labuladong
  - labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)
  - labuladong [手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect)

Algorithm: PDA

## [LeetCode-20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/) 

### PDA

Python

```python
class Solution:
    def isValid(self, s: str) -> bool:
        stk = []
        matched_parenthesis = {
            '(': ')',
            '{': '}',
            '[': ']',
        }  # 匹配的括号
        for char in s:
            if char in {'(', '{', '['}:
                stk.append(char)
            elif char in {')', '}', ']'}:
                if not stk:
                    return False
                if matched_parenthesis[stk[-1]] == char:
                    stk.pop()
                else:
                    return False
        return not stk

```



C++

```c++
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1) {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };
        stack<char> stk;
        for (char ch: s) {
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                }
                stk.pop();
            }
            else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};

```



## Make balance

### [LeetCode-921. 使括号有效的最少添加-中等](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/)



#### PDA

能够匹配，则消除，不能够匹配则留下来，最终剩下的个数就是不匹配 ，显然它们是需要通过添加来使之平衡的。该算法是借助栈实现的

```c++
// #include <bits/stdc++.h>
#include <string>
#include <stack>
using namespace std;

class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> sk;
        for (auto &&c : s)
        {
            if (c == '(')
            {
                sk.push(c);
            }
            else
            {
                if (sk.empty())
                {
                    sk.push(c);
                }
                else if (sk.top() == '(')
                {
                    sk.pop();
                }
                else
                {
                    sk.push(c);
                }
            }
        }
        return sk.size();
    }
};

int main()
{
    Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

#### 隐式PDA

[可以先用栈模拟的思路想，然后发现并不需要这个栈](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/solutions/1/ke-yi-xian-yong-zhan-mo-ni-de-si-lu-xian-1pmj/) 

[官方解题](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/solutions/1855025/shi-gua-hao-you-xiao-de-zui-shao-tian-ji-gcxu/) 

[labuladong-手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect) 



```python
class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        need_left_cnt = 0  # 需要的左括号的次数
        need_right_cnt = 0  # 需要的右括号的次数
        for c in s:
            if c == '(':
                need_right_cnt += 1
            if c == ')':
                need_right_cnt -= 1
                if need_right_cnt == -1:
                    need_left_cnt += 1
                    need_right_cnt = 0
        return need_left_cnt + need_right_cnt

```



