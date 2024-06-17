## [LeetCode-3. 无重复字符的最长子串-中等](https://leetcode.cn/problems/longest-substring-without-repeating-characters/) 



### C++

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

### Python

错误写法: 

```python

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def is_window_duplicate(w: Dict[str, int]) -> bool:
            return any(cnt > 1 for cnt in w.values())

        left, right = 0, 0
        window: Dict[str, int] = defaultdict(int)
        ans = 0
        while right < len(s):
            c_right = s[right]
            right += 1
            window[c_right] += 1
            while is_window_duplicate(window):
                c_left = s[left]
                left += 1
                window[c_left] -= 1

            ans = max(ans, len(window))
        return ans

```

上述计算当前 `window` 的长度的方式是错误的，因为 `window` 的实现是dict，当一个字符的计数为0的时候，它并不会将它从dict中删除，这就导致了无法准确的计算出当前窗口中有多少个字符。



正确写法:

```python

class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        def is_window_duplicate(w: Dict[str, int]) -> bool:
            return any(cnt > 1 for cnt in w.values())

        left, right = 0, 0
        window_stat: Dict[str, int] = defaultdict(int)
        ans = 0
        while right < len(s):
            c_right = s[right]
            right += 1
            window_stat[c_right] += 1
            while is_window_duplicate(window_stat):
                c_left = s[left]
                left += 1
                window_stat[c_left] -= 1

            ans = max(ans, len(window_stat))
        return ans


if __name__ == '__main__':
    solu = Solution()
    solu.lengthOfLongestSubstring("pwwkew")

```

