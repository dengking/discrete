# [LeetCode-31. 下一个排列](https://leetcode.cn/problems/next-permutation/)

cppreference [std::next_permutation](https://en.cppreference.com/w/cpp/algorithm/next_permutation) 

以数字序列 `[1,2,3] `为例，其排列按照字典序依次为：

```c++
[1,2,3]
[1,3,2]
[2,1,3]
[2,3,1]
[3,1,2]
[3,2,1]
```





## [LeetCode-下一个排列算法详解：思路+推导+步骤，看不懂算我输！](https://leetcode.cn/problems/next-permutation/solution/xia-yi-ge-pai-lie-suan-fa-xiang-jie-si-lu-tui-dao-/) 

> NOTE: 
>
> 由将原来的  **升序** 逐步变为 **降序**，下面是一个简单的例子:
>
> ```C++
> 123
> 132
> 213
> 231
> 312
> 321
> ```
>
> 总的思路是: 
>
> 一. 将原来的  **升序** 逐步变为 **降序**: **升序** 的数 相较于 **降序** 的数，是比较小的
>
> 二. 逐步进行
>
> 1. 两位->三位->四位
>
> 2. 自右向左: 即自右向左，逐步(位)将原来的  **升序** 逐步变为 **降序**。
>
> 下面的算法其实就是按照上述思路进行的，算法其实，也比较简单。
>
> 

### 算法推导

如何得到这样的排列顺序？这是本文的重点。我们可以这样来分析：

一. 我们希望下一个数比当前数大，这样才满足“下一个排列”的定义。因此只需要将后面的「大数」与前面的「小数」交换，就能得到一个更大的数。比如 123456，将 5 和 6 交换就能得到一个更大的数 123465。

二. 我们还希望下一个数**增加的幅度尽可能的小**，这样才满足“下一个排列与当前排列紧邻“的要求。为了满足这个要求，我们需要：

1. 在**尽可能靠右的低位**进行交换，需要**从后向前**查找

2. 将一个 **尽可能小的「大数」** 与前面的「小数」交换。比如 `123465`，下一个排列应该把 `5` 和 `4` 交换而不是把 `6` 和 `4` 交换
3. 将「大数」换到前面后，需要将「大数」后面的所有数**重置为升序**，**升序排列就是最小的排列**。

以 `123465` 为例：首先按照上一步，交换 `5` 和 `4`，得到 `123564`；然后需要将 `5` 之后的数重置为升序，得到 `123546`。显然 `123546` 比 `123564` 更小，`123546` 就是 `123465` 的下一个排列

### 算法过程

标准的“下一个排列”算法可以描述为：

1. **从后向前**查找第一个**相邻升序**的元素对 `(i,j)`，满足 `A[i] < A[j]`。此时 `[j,end)` 必然是降序

2. 在 `[j,end)` **从后向前**查找第一个满足 `A[i] < A[k]` 的 `k`。`A[i]`、`A[k]` 分别就是上文所说的「小数」、「大数」

3. 将 `A[i]` 与 `A[k]` 交换

4. 可以断定这时 `[j,end)` 必然是降序，逆置 `[j,end)`，使其升序

5. 如果在步骤 1 找不到符合的相邻元素对，说明当前 `[begin,end)` 为一个降序顺序，则直接跳到步骤 4



## C++



```C++
// #include <bits/stdc++.h>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int> &nums) {
        int i = nums.size() - 1 - 1;             // 让i指向倒数第二个元素
        //比较第i个元素和第i+1个元素，具体例子 53421，找出 34
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }
        // 如果nums已经是最大的sequence，那么它就是递减的，那么当上述while循环退出的时候，i就是-1
        if (i >= 0) {
            int j = i + 1;
            // 此时 [i+1, -1] 是单调递减的，选择需要找到大于 nums[i]的最小的数，只需要从i+1开始寻找直到最后一个，循环退出的时候，
            while (j < nums.size() && nums[j] >
                                      nums[i]) {                                            // 需要注意:  nums[j] >= nums[i] 是错误的，带一个例子即可知晓：534421，如果带上=，则j会指向2
                ++j;
            }
            std::swap(nums[i], nums[j - 1]); // 注意：交换之后，[i+1, -1] 依然是单调递减的，因为 nums[j] < nums[i]
        } else {
            // 已经是最大的排列了，此时i的值为-1
            // 不需要做什么
        }
        std::reverse(nums.begin() + i + 1, nums.end()); // 将[i+1, -1]reverse一下，这样就是单调递增的了
    }
};

int main() {
    Solution s;
    vector<int> nums{5, 1, 1};
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

### 为什么使用`std::reverse` 而不是 `std::sort` ?

上述算法的最后一步是使用 `reverse(nums.begin() + i + 1, nums.end());` ，而不是 `std::sort` ，为什么呢？

首先需要搞清楚目的: 让 `[nums.begin() + i + 1, nums.end()]` 范围内的元素为增序；显然通过 `std::sort` 是可以实现的；但是，考虑到，此时  `[nums.begin() + i + 1, nums.end()]`  内的元素是降序的，因此，通过复杂的更低的 `std::reverse` 可以实现让 `[nums.begin() + i + 1, nums.end()]` 范围内的元素为增序的目的；

