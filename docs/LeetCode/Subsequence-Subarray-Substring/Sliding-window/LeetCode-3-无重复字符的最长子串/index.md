# [LeetCode-3. 无重复字符的最长子串](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 中等



## 我的解题

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
    int lengthOfLongestSubstring(string s)
    {
        std::unordered_map<char, int> window;
        using pair_type = decltype(window)::value_type;
        // https://stackoverflow.com/a/9371137/10173843
        auto has_repeat = [&]() -> bool
        {
            return std::any_of(window.begin(), window.end(), [](const pair_type &left)
                               { return left.second > 1; });
        };
        int ret = 0;
        int len = s.size();
        for (int left = 0, right = 0; right < len; ++right)
        {
            window[s[right]]++;
            // int window_size = right - left + 1;
            while (has_repeat())
            {
                window[s[left++]]--;
            }
            ret = max(ret, right - left + 1);
        }
        return ret;
    }
};

int main()
{
    auto s = "abcabcbb";
    Solution solu;
    solu.lengthOfLongestSubstring(s);
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

