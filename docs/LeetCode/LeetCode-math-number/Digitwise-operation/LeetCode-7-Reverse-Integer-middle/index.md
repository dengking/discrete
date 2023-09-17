# [LeetCode-7. 整数反转-中等](https://leetcode.cn/problems/reverse-integer/) 



## 我的解题

由于题目明确要求 "**Assume the environment does not allow you to store 64-bit integers (signed or unsigned)**"，所以这道题只能够采用prediction的方式来预测乘法、加法操作是否会发生overflow、underflow。 

[画手大鹏L6](https://leetcode.cn/u/guanpengchn/) # [画解算法：7. 整数反转](https://leetcode.cn/problems/reverse-integer/solution/hua-jie-suan-fa-7-zheng-shu-fan-zhuan-by-guanpengc/)

> 溢出条件有两个，一个是大于整数最大值`MAX_VALUE`，另一个是小于整数最小值 `MIN_VALUE`，设当前计算结果为 `ans`，下一位为 `digit`。
>
> 一、从 `ans * 10 + digit > MAX_VALUE` 这个溢出条件来看
>
> - 当出现 `ans > MAX_VALUE / 10` 且 还有`digit`需要添加 时，则一定溢出
> - 当出现 `ans == MAX_VALUE / 10` 且 `digit > 7` 时，则一定溢出，`7` 是 `2^31 - 1` 的个位数
>
> 二、从 `ans * 10 + digit < MIN_VALUE` 这个溢出条件来看
>
> - 当出现 `ans < MIN_VALUE / 10` 且 还有`digit`需要添加 时，则一定溢出
> - 当出现 `ans == MIN_VALUE / 10` 且 `digit < -8` 时，则一定溢出，`8` 是`-2^31` 的个位数

```c++

#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int ans = 0;
        while (x) // 负数的truth value是1，所以它是支持负数的，需要注意这里的条件不能是 while (x > 0)
        {
            int digit = x % 10;
            // 当出现 `ans > MAX_VALUE / 10` 且 还有`digit`需要添加 时，则一定溢出
            // 当出现 `ans == MAX_VALUE / 10` 且 `digit > 7` 时，则一定溢出，`7` 是 `2^31 - 1` 的个位数
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7))
            {
                return 0;
            }
            // 当出现 `ans < MIN_VALUE / 10` 且 还有`digit`需要添加 时，则一定溢出
            // 当出现 `ans == MIN_VALUE / 10` 且 `digit < -8` 时，则一定溢出，`8` 是`-2^31` 的个位数
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8))
            {
                return 0;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }
};

int main()
{
    Solution s;

    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
}
```

