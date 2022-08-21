# [LeetCode-125. 验证回文串-简单](https://leetcode.cn/problems/valid-palindrome/)



## 我的解题



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
    bool isQualified(const string &s, int index)
    {
        return isalpha(s[index]) || isdigit(s[index]);
    }
    bool isEqual(const string &s, int left, int right)
    {
        return std::tolower(s[left]) == std::tolower(s[right]);
    }

public:
    bool isPalindrome(string s)
    {
        int left = 0, right = s.size() - 1;
        while (left < right)
        {
            if (!isQualified(s, left))
            {
                ++left;
                continue;
            }
            if (!isQualified(s, right))
            {
                --right;
                continue;
            }
            if (isEqual(s, left, right))
            {
                ++left, --right;
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

