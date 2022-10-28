# [LeetCode-169. 多数元素-简单](https://leetcode.cn/problems/majority-element/)



## hash-map

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



## Boyer–Moore majority vote algorithm



```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = 0, vote = 0;
        for (auto &&num : nums)
        {
            if (vote == 0) // 更换候选人
            {
                element = num;
                vote = 1;
            }
            else if (num == element)
            {
                ++vote;
            }
            else
            {
                --vote;
            }
        }
        return element;
    }
};

// Driver code
int main()
{
}

```



上述算法等价于:



```c++
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int element = 0, vote = 0;
        for (auto &&num : nums)
        {
            if (vote > 0 && num == element)
            {
                ++vote;
            }
            else if (vote == 0) // 更换候选人
            {
                element = num;
                vote = 1;
            }
            else
            {
                --vote;
            }
        }
        return element;
    }
};

// Driver code
int main()
{
}

```



## 排序



```c++
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};

// Driver code
int main()
{
}

```

