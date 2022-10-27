# [LeetCode-2351. 第一个出现两次的字母-简单](https://leetcode.cn/problems/first-letter-to-appear-twice/)



```c++
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    char repeatedCharacter(string s)
    {
        unordered_map<char, int> frequency;
        for (auto &&c : s)
        {
            ++frequency[c];
            if (frequency[c] == 2)
            {
                return c;
            }
        }
        return 0;
    }
};

// Driver code
int main()
{
}

```

