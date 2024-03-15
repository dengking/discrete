# [LeetCode-1392. 最长快乐前缀-困难](https://leetcode.cn/problems/longest-happy-prefix/) 



## 我的解题



### Rabin–Karp algorithm

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
    string longestPrefix(string s)
    {
        int n = s.size();
        int prefix = 0, suffix = 0;
        int base = 31, mod = 1000000007, mul = 1;
        int happy = 0;
        for (int i = 1; i < n; ++i) // i 表示的是长度
        {
            prefix = ((long long)prefix * base + (s[i - 1] - 97)) % mod;
            suffix = (suffix + (long long)(s[n - i] - 97) * mul) % mod;
            if (prefix == suffix)
            {
                happy = i;
            }
            // else // 对于用例 "ababab" ，它是无法通过的
            // {
            //     break;
            // }
            mul = (long long)mul * base % mod;
        }
        return s.substr(0, happy);
    }
};

// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



### KMP

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
    string longestPrefix(string s)
    {
        vector<int> failure_array(s.size(), 0);
        int i = 0, j = 1;
        while (j < s.size())
        {
            if (s[i] == s[j])
            {
                i += 1;
            }
            else if (i > 0)
            {
                i = failure_array[i - 1];
                continue;
            }
            failure_array[j++] = i;
        }
        return s.substr(0, failure_array.back());
    }
};

// Driver program to test above functions
int main()
{
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

