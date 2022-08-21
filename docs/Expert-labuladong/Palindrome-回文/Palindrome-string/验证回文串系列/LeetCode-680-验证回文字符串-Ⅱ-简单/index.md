# [LeetCode-680. 验证回文字符串 Ⅱ-简单](https://leetcode.cn/problems/valid-palindrome-ii/)



## 我的解题

模拟删除一个字符。

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
#include <ctype.h>

using namespace std;

class Solution
{

    int delete_cnt = 1;

public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {

            if (s[left] == s[right])
            {
                ++left, --right;
                continue;
            }
            else if (delete_cnt--)
            {
                ++left;
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};

// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



无法通过的用例: 

输入：

"cbbcc"

输出：

false

预期结果：

true



### 第二次解题

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
#include <ctype.h>

using namespace std;

class Solution
{
public:
    bool palindrome(const std::string &s, int i, int j)
    {
        for (; i < j && s[i] == s[j]; ++i, --j)
            ;
        return i >= j;
    }

    bool validPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        for (; i < j && s[i] == s[j]; ++i, --j)
            ;
        return palindrome(s, i, j - 1) || palindrome(s, i + 1, j);
    }
};

// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

