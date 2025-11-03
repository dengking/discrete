# Digit-wise operation

[LeetCode-7. 整数反转-中等](https://leetcode.cn/problems/reverse-integer/) 

1、integer-overflow-underflow-prediction

2、

> **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

3、create number

[LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/) 

难点在于停止条件难写

[LeetCode-136. 只出现一次的数字-简单](https://leetcode.cn/problems/single-number/) 

[LeetCode-137. 只出现一次的数字 II-中等](https://leetcode.cn/problems/single-number-ii/) 

[LeetCode-260. 只出现一次的数字 III- middle](https://leetcode.cn/problems/single-number-iii/) 

[LeetCode-233. 数字 1 的个数-困难](https://leetcode.cn/problems/number-of-digit-one/) 

## 基础操作

### number=>digits

Extract digits from integer/split an int into its digits

```cpp
/**
 * 将数num转换为base进制
 * @param num 
 * @param base 
 * @return 
 */
std::vector<int> getDigits(int num, int base) {
    std::vector<int> digits;
    while (num) {
        digits.push_back(num % base);
        num /= base;
    }
    return digits;
}
```

stackoverflow [How do I split an int into its digits?](https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into-its-digits)

[A](https://stackoverflow.com/a/4261638)

Given the number 12345 :

```
`5` is `12345 % 10`
`4` is `12345 / 10 % 10`
`3` is `12345 / 100 % 10`
`2` is `12345 / 1000 % 10`
`1` is `12345 / 10000 % 10
```

[A](https://stackoverflow.com/a/4261624)

Reversed order digit extractor (eg. for 23 will be 3 and 2):

```cpp
while (number > 0)
{
    int digit = number%10;
    number /= 10;
    //print digit
}
```

Normal order digit extractor (eg. for 23 will be 2 and 3):

```cpp
std::stack<int> sd;

while (number > 0)
{
    int digit = number%10;
    number /= 10;
    sd.push(digit);
}

while (!sd.empty())
{
    int digit = sd.top();
    sd.pop();
    //print digit
}
```

geeksforgeeks [C Program to Print all digits of a given number](https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/)

### number=>bits

[LeetCode-50. Pow(x, n)-中等](https://leetcode.cn/problems/powx-n/) 

```cpp
#include <cstdlib>

class Solution {
public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }
        long num = labs(n);
        double pow = 1;

        while (num) { // equivalent to while(num != 0)
            if (num & 1) { // equivalent to if((num & 1) != 0)
                pow *= x;
            }

            x *= x;
            num >>= 1;
        }

        return pow;
    }
};
```

### digits=>number:  create number

[LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/) 

```cpp
// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(long x)
    {
        if (x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        long tempNum = 0;
        while (x > tempNum) // stop-condition: tempNum >= x
        {
            tempNum = tempNum * 10 + x % 10;
            x /= 10;
        }
        //    存在两种可能:
        //
        //    1、一种是回文数的长度为偶数
        //
        //    此时 `x == tempNum`，比如 `1001`
        //
        //    2、一种是长度为奇数
        //
        //    此时 `x == tempNum / 10`，比如 `10001`
        return x == tempNum || x == tempNum / 10;
    }
};

// Driver code
int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g
```
