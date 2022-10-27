# [LeetCode-169. 多数元素-简单](https://leetcode.cn/problems/majority-element/)



hash-map

```c++
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> counter;
        for (auto &&num : nums)
        {
            ++counter[num];
        }
        for (auto &&[num, count] : counter)
        {
            if (count > (nums.size() / 2))
            {
                return num;
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

