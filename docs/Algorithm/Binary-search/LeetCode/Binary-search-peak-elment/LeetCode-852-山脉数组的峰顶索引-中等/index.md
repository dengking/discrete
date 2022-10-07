# [LeetCode-852. 山脉数组的峰顶索引-中等](https://leetcode.cn/problems/peak-index-in-a-mountain-array/)



## [官方解题 # 二分查找](https://leetcode.cn/problems/peak-index-in-a-mountain-array/solution/shan-mai-shu-zu-de-feng-ding-suo-yin-by-dtqvv/)

**思路与算法**

记满足题目要求的下标 $i$ 为 $i_\textit{ans}$。我们可以发现：

1、当 $i < i_\textit{ans}$  时，$\textit{arr}_i < \textit{arr}_{i+1}$ 恒成立；

2、当 $i \geq i_\textit{ans}$时，$\textit{arr}_i > \textit{arr}_{i+1}$ 恒成立；

这与方法一的遍历过程也是一致的，因此 $i_\textit{ans}$  即为「最小的满足 $\textit{arr}_i > \textit{arr}_{i+1}$ 的下标 $i$」，我们可以用二分查找的方法来找出 $i_\textit{ans}$。



### 版本一

官方解题给出的代码有些细节处难以理解，下面是根据 [Luna](https://leetcode.cn/u/luna_/) # [852.二分查找](https://leetcode.cn/problems/peak-index-in-a-mountain-array/solution/852-by-luna_-zy5n/) 中给出的代码写的。

```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    /**
     * @brief 要找到最小的满足arr[i] > arr[i + 1]的坐标
     *
     * @param arr
     * @return int
     */
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] < arr[mid + 1]) // 左侧
            {
                left = mid + 1;
            }
            else // arr[mid] >= arr[mid + 1] // 右侧
            {
                right = mid; // 为什么不是 right=mid-1？
            }
        }
        return left;
    }
};

int main()
{

    Solution s;
    vector<int> nums{4, 5, 6, 7, 1, 2};
    cout << s.peakIndexInMountainArray(nums) << endl;
}
```



### 版本二

下面是根据 [小鸡炖蘑菇](https://leetcode.cn/u/zz1998/) # [代码简洁 一种还不错的解法](https://leetcode.cn/problems/peak-index-in-a-mountain-array/solution/dai-ma-jian-ji-yi-chong-huan-bu-cuo-de-j-oi07/) 写的c++版本

```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    /**
     * @brief 要找到最小的满足arr[i] > arr[i + 1]的坐标
     *
     * @param arr
     * @return int
     */
    int peakIndexInMountainArray(vector<int> &arr)
    {
        int n = arr.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            {
                return mid;
            }
            else if (arr[mid] > arr[mid - 1] && arr[mid] < arr[mid + 1]) // 左侧
            {
                left = mid + 1;
            }
            else if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1]) // 右侧
            {
                right = mid - 1;
            }
        }
        return left;
    }
};

int main()
{

    Solution s;
    vector<int> nums{4, 5, 6, 7, 1, 2};
    cout << s.peakIndexInMountainArray(nums) << endl;
}
```

