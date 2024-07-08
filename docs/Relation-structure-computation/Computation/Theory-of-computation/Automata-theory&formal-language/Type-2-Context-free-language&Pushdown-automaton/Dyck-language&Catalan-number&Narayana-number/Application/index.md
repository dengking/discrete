# LeetCode-Dyck-language

- geeksforgeeks [Binary tree to string with brackets](https://www.geeksforgeeks.org/binary-tree-string-brackets/) 

- labuladong

​		labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)

​		labuladong [手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect)

​		labuladong [回溯算法最佳实践：合法括号生成](https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g)



check:

[LeetCode-20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/) 

generator: 

[LeetCode-22. Generate Parentheses-Medium](https://leetcode.cn/problems/generate-parentheses/) / [LeetCode-LCR 085. 括号生成](https://leetcode.cn/problems/IDBivT/) / [LeetCode-面试题 08.09. 括号](https://leetcode.cn/problems/bracket-lcci/) 

[LeetCode-96. Unique Binary Search Trees-Medium](https://leetcode.cn/problems/unique-binary-search-trees/)

[LeetCode-241. Different Ways to Add Parentheses-Medium](https://leetcode.cn/problems/different-ways-to-add-parentheses/) 

solution: [C++ | using Dyck words (Catalan number)](https://leetcode.com/problems/different-ways-to-add-parentheses/solutions/1684052/c-using-dyck-words-catalan-number/)

[LeetCode-894. All Possible Full Binary Trees-Medium](https://leetcode.com/problems/all-possible-full-binary-trees/) 

make the invalid parentheses valid: 

[LeetCode-32. 最长有效括号-Hard](https://leetcode.cn/problems/longest-valid-parentheses/) 

[LeetCode-301. Remove Invalid Parentheses](https://leetcode.cn/problems/remove-invalid-parentheses/)

[LeetCode-921. Minimum Add to Make Parentheses Valid-Medium](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/) 

[LeetCode-1541. Minimum Insertions to Balance a Parentheses String-Medium](https://leetcode.cn/problems/minimum-insertions-to-balance-a-parentheses-string/) 

[LeetCode-1963. Minimum Number of Swaps to Make the String Balanced-Medium](https://leetcode.cn/problems/minimum-number-of-swaps-to-make-the-string-balanced/) 

[LeetCode-2116. Check if a Parentheses String Can Be Valid-Medium](https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/) 

[LeetCode-921. Minimum Add to Make Parentheses Valid-Medium](https://leetcode.cn/problems/minimum-add-to-make-parentheses-valid/) 和 [LeetCode-2116. Check if a Parentheses String Can Be Valid-Medium](https://leetcode.cn/problems/check-if-a-parentheses-string-can-be-valid/) 表述相同。



## Check Dyck-language

素材：

- geeksforgeeks [Check for balanced parentheses in an expression](https://www.geeksforgeeks.org/check-for-balanced-parentheses-in-an-expression/)

- labuladong
  - labuladong [3 分钟看懂如何判断括号的合法性](https://mp.weixin.qq.com/s/o2MjTSIC4FkPscF5MnLXMQ)
  - labuladong [手把手解决三道括号相关的算法题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247487246&idx=1&sn=4a514020ce9dc8777e2d1d503188b62b&scene=21#wechat_redirect)

Algorithm: PDA

### [LeetCode-20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/) 

#### PDA

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


