# [LeetCode-796. 旋转字符串-简单](https://leetcode.cn/problems/rotate-string/)



## 我的解题





### 第一次错误解题



```c++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int len1 = s.size(), len2 = goal.size();
        if (len1 != len2)
            return false;
        int first = 0, second = 0;
        while (second < len2)
        {
            if (goal[second] == s[first])
                break;
            ++second;
        }
        for (; first < len2; ++first)
        {
            if (s[first] != goal[second])
            {
                return false;
            }
            else
            {
                second = (second + 1) % len2;
            }
        }
        return true;
    }
};

// Driver program to test above functions
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    Solution solu;
    solu.rotateString(s, goal);
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

无法通过的用例:

```
"bbbacddceeb"
"ceebbbbacdd"
```

原因在于 `second` 的初始值错误，上述算法无法处理上述case。



### 第二次解题: KMP

思路: 

一、移动的几次等于两个串的最长公共前缀后缀的长度。

二、将两个字符串拼接起来，求解最长公共前缀后缀，然后匹配剩余部分。

```C++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <queue>
#include <algorithm>
#include <iterator>
#include <cstdlib>

using namespace std;

class Solution
{
public:
    bool rotateString(string s, string goal)
    {
        int len1 = s.size(), len2 = goal.size();
        if (len1 != len2)
            return false;
        if (s == goal)
            return true;
        vector<int> failure_array(2 * len2, 0);
        auto sgoal = s + goal;
        int i = 0, j = 1;
        while (j < sgoal.size())
        {
            if (sgoal[i] == sgoal[j])
            {
                ++i;
            }
            else if (i > 0)
            {
                i = failure_array[i - 1];
                continue;
            }
            failure_array[j++] = i;
        }
        auto rotateCnt = failure_array.back();

        for (int first = rotateCnt, second = 0; first < len1; ++first, ++second)
        {
            if (s[first] != goal[second])
                return false;
        }
        return true;
    }
};

// Driver program to test above functions
int main()
{
    string s = "abcde";
    string goal = "cdeab";
    Solution solu;
    cout << solu.rotateString(s, goal) << endl;
    s = "bbbacddceeb";
    goal = "ceebbbbacdd";
    cout << solu.rotateString(s, goal) << endl;
    s = "aa";
    goal = "aa";
    cout << solu.rotateString(s, goal) << endl;
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## 模拟

### [力扣官方题解](https://leetcode.cn/u/leetcode-solution/)

首先，如果 $s$ 和 $\textit{goal}$ 的长度不一样，那么无论怎么旋转，$s$ 都不能得到 $\textit{goal}$，返回 $\text{false}$。在长度一样（都为 $n$）的前提下，假设 $s$ 旋转 $i$ 位，则与 $\textit{goal}$ 中的某一位字符 $\textit{goal}[j]$ 对应的原 $s$ 中的字符应该为 $s[(i+j) \bmod n]$。在固定 $i$ 的情况下，遍历所有 $j$，若对应字符都相同，则返回 $\text{true}$。否则，继续遍历其他候选的 $i$。若所有的 $i$ 都不能使 $s$ 变成 $\textit{goal}$，则返回 $\text{false}$。

```python
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        m, n = len(s), len(goal)
        if m != n:
            return False
        for i in range(n):
            for j in range(n):
                if s[(i + j) % n] != goal[j]:
                    break
            else:
                return True
        return False

```

### [LeetCode-【宫水三叶】简单模拟题](https://leetcode.cn/problems/rotate-string/solution/by-ac_oier-bnkx/)

由于每次旋转操作都是将最左侧字符移动到最右侧，因此如果 goal 可由 s 经过多步旋转而来，那么 goal 必然会出现在 s + s 中，即满足 `(s + s).contains(goal)`，同时为了 s 本身过长导致的结果成立，我们需要先确保两字符串长度相等。

```Java
class Solution {
    public boolean rotateString(String s, String goal) {
        return s.length() == goal.length() && (s + s).contains(goal);
    }
}

```

