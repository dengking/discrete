# Binary-serach-math

和数学相关的使用binary-search来解决的问题，有如下类型的问题:

1. 从搜索区间中搜索符合条件的一个数

   这类问题的一个典型特征是: 

   - 搜索区间可以根据题目意思推断出来
   - 单调函数，单调意味着是sorted的，因此可以使用binary search来进行搜索



## [LeetCode-29. Divide Two Integers-middle](https://leetcode.cn/problems/divide-two-integers/)

这道题所考察的是binary search、quick multiplication。

解题思路: 在`[0, dividend]` 中搜索最大的 `quotient`，并且 `quotient` 它满足 

```
quotient = dividend // divisor 
quotient * divisor <= dividend
```

可以将负数转换为正数来保证 $quotient * divisor$ 单调，求解满足条件的最大的数，显然这是可以使用binary search的。

**乘法**可以使用**快速乘算法**(只使用**加法**)实现。

### Python

```python
class Solution:
    INT_MIN = -2 ** 31
    INT_MAX = 2 ** 31 - 1

    def divide(self, dividend: int, divisor: int) -> int:
        if dividend == 0:
            return 0
        if divisor == 1:
            return dividend
        if divisor == -1:
            if dividend > self.INT_MIN:
                return -dividend
            else:
                return self.INT_MAX
        sign = 1
        if (dividend < 0 < divisor) or (dividend > 0 > divisor):
            sign = -1
        dividend = abs(dividend)
        divisor = abs(divisor)
        left, right = 0, dividend
        while left <= right:
            mid = left + (right - left) // 2
            product = self.quick_mul(mid, divisor)
            if product == dividend:
                right = mid
                break
            elif product < dividend:
                left = mid + 1
            else:
                right = right - 1
        return right * sign

    @staticmethod
    def quick_mul(m, n) -> int:
        product = 0
        while n:
            if n & 1:
                product += m
            m += m
            n >>= 1
        return product


if __name__ == '__main__':
    solu = Solution()
    dividend = 2147483647
    divisor = 2
    solu.divide(dividend, divisor)

```



## [LeetCode-69. x 的平方根 ](https://leetcode.cn/problems/sqrtx/) / [LeetCode-剑指 Offer II 072. 求平方根-简单](https://leetcode.cn/problems/jJ0w9p/)



### 二分查找

这是在阅读 [知乎-如何看待中国学生为了进 Google、微软等外企疯狂地刷题？北美学生想进这些名企也要刷题吗？ - Haojun的回答]( https://www.zhihu.com/question/35133069/answer/97832096) 时发现的，其中已经提出了使用二分查找。其实这道题是比较特殊的，因为理论上正确的平方根应该是double类型的，但是这道题的返回值类型是int，并且要求向下取整，因此可以使用二分查找来求解，需要注意的是: 如果要求解准确的平方根，那么二分查找算法显然是不能够使用的，因为区间内有无数个小数。

下面的这种写法是典型的运用**二分查找**来进行**逼近**，需要注意的是这道题的返回值是`right`，这是因为`while (left <= right)` 的退出条件有两个:

- `power == x`

- `left > right`

由于题目要求是向下取整，因此最终的返回值是`right`。

寻找target的predecessor，BS保证不断地向target逼近，保证一直位于target的左侧，当退出循环的时候，`left > right`，此时`left`已经越过了target，而`right`依然小于target

```c++
class Solution {
public:
    int mySqrt(int x) {
        int left = 0, right = x;
        while (left <= right) {
            double mid = left + (right - left) / 2;
            double power = mid * mid;
            if (power == x) {
                return mid;
            } else if (power < x) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};

int main() {
}
// g++ test.cpp --ne_std=c++11 -pedantic -Wall -Wextra

```



### 牛顿迭代法

并且如果要准确的求解得到，需要用到一些比较高级的数学技巧: 牛顿迭代法



## [LeetCode-367. 有效的完全平方数](https://leetcode.cn/problems/valid-perfect-square/)
