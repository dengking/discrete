# [LeetCode-29. Divide Two Integers-middle](https://leetcode.cn/problems/divide-two-integers/)

这道题所考察的是binary search、quick multiplication

**乘法**可以使用**快速乘算法**(只使用**加法**)实现

```
quotient = dividend // divisor 
quotient * divisor <= dividend
```

即求解最大的满足上述条件的quotient。

单调，求解满足条件的最大的数，这是binary search的典型应用。

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

