# LeetCode [424. 替换后的最长重复字符](https://leetcode.cn/problems/longest-repeating-character-replacement/)



## 我的解题

这是参考[migoo](https://leetcode.cn/u/migoo/) # [通过此题了解一下什么是滑动窗口 Java 题解](https://leetcode.cn/problems/longest-repeating-character-replacement/solution/tong-guo-ci-ti-liao-jie-yi-xia-shi-yao-shi-hua-don/) 写的。

```C++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
#include <typeinfo>
#include <limits>

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    int characterReplacement(string s, int k)
    {
        std::unordered_map<char, int> cnt;
        using pair_type = decltype(cnt)::value_type;
        // https://stackoverflow.com/a/9371137/10173843
        auto max_of_cnt_func = [&]() -> int
        {
            return std::max_element(cnt.begin(), cnt.end(), [](const pair_type &left, const pair_type &right)
                                    { return left.second < right.second; })
                ->second;
        };
        int ret = 0;
        int len = s.size();
        for (int left = 0, right = 0; right < len; ++right)
        {
            cnt[s[right]]++;
            // int window_size = right - left + 1;
            while (right - left + 1 - max_of_cnt_func() > k)
            {
                cnt[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

