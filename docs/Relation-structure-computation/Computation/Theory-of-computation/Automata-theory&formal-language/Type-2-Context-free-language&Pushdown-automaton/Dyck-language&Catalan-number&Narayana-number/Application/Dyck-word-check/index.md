

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

