# [LeetCode-7. 整数反转-中等](https://leetcode.cn/problems/reverse-integer/)



## 我的解题

[画手大鹏L6](https://leetcode.cn/u/guanpengchn/) # [画解算法：7. 整数反转](https://leetcode.cn/problems/reverse-integer/solution/hua-jie-suan-fa-7-zheng-shu-fan-zhuan-by-guanpengc/)



```c++

#include <iostream>
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int res = 0;
        while (x)
        {
            int bit = x % 10;
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && bit > 7))
            {
                return 0;
            }
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && bit < -8))
            {
                return 0;
            }
            res = res * 10 + bit;
            x /= 10;
        }
        return res;
    }
};

int main()
{
    Solution s;

    cout << s.reverse(123) << endl;
    cout << s.reverse(-123) << endl;
}
```

