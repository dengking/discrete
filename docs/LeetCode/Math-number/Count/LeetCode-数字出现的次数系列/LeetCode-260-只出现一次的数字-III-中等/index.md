# [LeetCode-260. 只出现一次的数字 III-中等](https://leetcode.cn/problems/single-number-iii/) 



## [官方解题](https://leetcode.cn/problems/single-number-iii/solution/zhi-chu-xian-yi-ci-de-shu-zi-iii-by-leet-4i8e/)

> NOTE:
>
> 一、divide&conquer
>
> 依据 `xorsum` 的 lsb，  `x1` 和 `x2` 肯定会被分到不同组；
>
> 依据 `xorsum` 的 lsb，相同的数肯定会被分到相同组；
>
> 



```c++

#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        int xorsum = 0;
        for (int num : nums)
        {
            xorsum ^= num;
        }
        // 防止溢出，理解下面解法的前提是理解integer的representation: two's-complement
        // INT_MIN=0x8000，int类型是无法表示(-INT_MIN)，下面采用的是prediction来避免overflow
        //
        int lsb = (xorsum == INT_MIN ? xorsum : xorsum & (-xorsum));
        int type1 = 0, type2 = 0;
        for (int num : nums)
        {
            if (num & lsb)
            {
                type1 ^= num;
            }
            else
            {
                type2 ^= num;
            }
        }
        return {type1, type2};
    }
};

int main()
{
}

```

