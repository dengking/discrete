# LeetCode-Wiggle-Sort-Serial

摆动数组

quick select正好可以将数组按照pivot分为两部分，然后将前后两部分交错一下。

偶数位的数字比左右的大一些即可。

特殊例子处理: 中间的两个数相等，这种情况，需要将它转换为不相等的情况。



## [LeetCode-280. Wiggle Sort-Middle](https://leetcode.cn/problems/wiggle-sort/)



### sort

首先将数组$nums$进行排序，对于每个奇数位的数$nums[i]$，交换它和它后面的一个元素$nums[i+1]$。

```c++
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size() - 1; i += 2)
        {
            std::swap(nums[i], nums[i + 1]);
        }
    }
};

int main()
{
}
```



### quickSelct



## [LeetCode-324. Wiggle Sort II-Middle](https://leetcode.cn/problems/wiggle-sort-ii/)

