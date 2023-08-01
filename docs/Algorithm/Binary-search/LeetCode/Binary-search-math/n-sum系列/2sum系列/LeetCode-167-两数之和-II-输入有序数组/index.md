# [LeetCode-167. Two Sum II - Input array is sorted](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/)



## 穷举

```c++
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {

        for (int left = 0; left < numbers.size(); ++left)
        {
            for (int right = left + 1; right < numbers.size(); ++right)
            {
                if (numbers[left] + numbers[right] == target)
                {
                    return {left + 1, right + 1};
                }
            }
        }
        return {};
    }
};

ostream &operator<<(ostream &stream, vector<int> v)
{
    for (auto &&i : v)
        stream << i;
    return stream;
}

// Driver code
int main()
{

    Solution s;
    vector<int> nums{2, 7, 11, 15};
    cout << s.twoSum(nums, 9) << endl;
    nums = {2, 3, 4};
    cout << s.twoSum(nums, 6) << endl;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

解空间是: 上三角方阵(upper triangular square matrix)，如图所示（下图来自于  [nettee](https://leetcode.cn/u/nettee/) [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/)  ）:

![检查单元格 0, 7](https://pic.leetcode-cn.com/11af3da798c61eb69691db9ac28c74383b4c5f9586c39689e0529b423c669221.jpg)

上述算法其实是逐行进行搜索的。



## 双指针

```C++
#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0, right = numbers.size() - 1;
        int sum = 0;
        while (left < right)
        {
            sum = numbers[left] + numbers[right];
            if (sum < target)
            {
                ++left;
            }
            else if (sum > target)
            {
                --right;
            }
            else
            {
                return {left + 1, right + 1};
            }
        }
        return {};
    }
};

ostream &operator<<(ostream &stream, vector<int> v)
{
    for (auto &&i : v)
        stream << i;
    return stream;
}

// Driver code
int main()
{

    Solution s;
    vector<int> nums{2, 7, 11, 15};
    cout << s.twoSum(nums, 9) << endl;
    nums = {2, 3, 4};
    cout << s.twoSum(nums, 6) << endl;
    return 0;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

一、上述代码看似简单，但是问自己如下问题:

1、

```c++
            if (sum < target)
            {
                ++left;
            }
```

修改为 `--right` 是否可行？

```c++
            if (sum > target)
            {
                --right;
            }
```

修改为 `++left` 是否可行？

在 [nettee](https://leetcode.cn/u/nettee/) [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/)  对上述问题给出了很好的解答。

每一行、每一列的最大值、最小值都是可以计算出的，通过它和target的比较，可以能够快速地一次性抛弃一行、一列。



二、总的来说，从两个方向来概括这个algorithm:

1、binary-search-approximation=逼近

2、v3s=virtual-search-state-solution-space=square-缩减-剪枝

tag-double-pointer-left-right-from-sides-to-middle-binary-search-approximation=逼近-two-sum-两数之和

从左右两侧进行逼近，能够穷举

三、素材：

1、[nettee](https://leetcode.cn/u/nettee/) [一张图告诉你 O(n) 的双指针解法的本质原理（C++/Java）](https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/87919/yi-zhang-tu-gao-su-ni-on-de-shuang-zhi-zhen-jie-fa/) 

从**搜索空间**的角度解释了上述解法的复杂度的由来。

这个题的解空间是一个正方形点一半，它的(缩减、剪枝)是一次剪一行、一列，显然是比较高效的。这让我联想到了binary-search，显然它的(缩减、剪枝)是一次剪一半。



