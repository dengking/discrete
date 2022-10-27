# [LeetCode-11. 盛最多水的容器](https://leetcode.cn/problems/container-with-most-water/) 



## 我的解题



### $O(N^2)$



```c++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        for (int left = 0; left < height.size(); ++left)
        {
            for (int right = left + 1; right < height.size(); ++right)
            {
                res = max(res, (right - left) * min(height[left], height[right]));
            }
        }
        return res;
    }
};

int main()
{
}

```



### $O(N)$



```C++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;

        int left = 0, right = height.size() - 1;
        while (left < right)
        {
            res = max(res, (right - left) * min(height[left], height[right]));
            if (height[left] < height[right])
            {
                ++left;
            }
            else
            {
                --right;
            }
        }
        return res;
    }
};

int main()
{
}

```



## [Krahets](https://leetcode.cn/u/jyd/) # [11. 盛最多水的容器（双指针，清晰图解）](https://leetcode.cn/problems/container-with-most-water/solution/container-with-most-water-shuang-zhi-zhen-fa-yi-do/)

由于可容纳水的高度由两板中的 **短板** 决定，因此可得如下 **面积公式** ：
$$
S(i, j) = min(h[i], h[j]) × (j - i)
$$


在每个状态下，无论长板或短板向中间收窄一格，都会导致水槽 **底边宽度** -1−1 变短：

1、若向内 **移动短板** ，水槽的短板 $min(h[i], h[j])$ 可能变大，因此下个水槽的面积 **可能增大** 。

2、若向内 **移动长板** ，水槽的短板 $min(h[i], h[j])$ 不变或变小，因此下个水槽的面积 **一定变小** 。

> NOTE:
>
> 一、由于可容纳水的高度由两板中的 **短板** 决定，因此就可以得到上述结论
>
> 二、上述是approximation

