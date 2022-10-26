# [LeetCode-137. 只出现一次的数字 II-中等](https://leetcode.cn/problems/single-number-ii/) 



## [官方解题](https://leetcode.cn/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetc-23t6/)



### 方法二：依次确定每一个二进制位

> NOTE:
>
> 一、在 [KrahetsL6](https://leetcode.cn/u/jyd/) # [137. 只出现一次的数字 II（有限状态自动机 + 位运算，清晰图解）](https://leetcode.cn/problems/single-number-ii/solution/single-number-ii-mo-ni-san-jin-zhi-fa-by-jin407891/) 中，对这种思路进行了更好的阐述:
>
> > 如下图所示，考虑数字的二进制形式，对于出现三次的数字，各 二进制位 出现的次数都是 33 的倍数。
> > 因此，统计所有数字的各二进制位中 11 的出现次数，并对 33 求余，结果则为只出现一次的数字。
> >
> > ![](https://pic.leetcode-cn.com/28f2379be5beccb877c8f1586d8673a256594e0fc45422b03773b8d4c8418825-Picture1.png)
> >
>
> 

```c++

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int ans = 0;
        for (int i = 0; i < 32; ++i) // 位数
        {
            int total = 0;
            for (int num : nums)
            {
                total += ((num >> i) & 1);
            }
            if (total % 3) // create number
            {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main()
{
}

```

