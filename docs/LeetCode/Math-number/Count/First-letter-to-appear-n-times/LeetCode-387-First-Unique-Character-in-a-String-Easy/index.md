# [LeetCode-387. 字符串中的第一个唯一字符-简单](https://leetcode.cn/problems/first-unique-character-in-a-string/)



## 我的解题

1、频率直方图

2、多级排序

```c++
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<int, int> frequency;
        for (auto &&ch : s)
        {
            ++frequency[ch];
        }
        for (int i = 0; i < s.size(); ++i)
        {
            if (frequency[s[i]] == 1)
            {
                return i;
            }
        }
        return -1;
    }
};

// Driver code
int main()
{
}

```

