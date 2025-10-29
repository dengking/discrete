# Math&number

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

## Base-n representation of a number in decimal

> NOTE: 将10进制数转换为容易进制数、获得10进制数的n进制表示
> 
> 对应base-n，它的digit的范围是0~n-1
> 
> 这个算法的理解可以基于 number=>digits(不调整进制)，不断地进行剥离

Let's explain the general algorithm and provide a Python implementation for **converting a decimal (base-10) integer to any base-n representation**.

---

### Algorithm Explanation

To convert a decimal integer to its base-n representation (where n ≥ 2):

**Steps:**

1. **Initialize** an empty list to store the digits.
2. **Repeat** until the number becomes 0:
   - Divide the number by n.
   - Record the remainder(余数) (which is a digit in base-n).
   - Update the number to the integer quotient of the division.
     - 翻译: 将该数值更新为此次除法运算的整数商
     - “integer quotient” 是数学与编程领域的固定术语，译为 “整数商”，即除法运算后舍去小数部分的结果（如 7÷2 的整数商为 3），区别于 “商”（quotient，可能含小数）
3. The collected remainders, when read in reverse order, give the base-n representation.

**Note**:  
For n > 10, you'll need to use letters ('A' for 10, 'B' for 11, etc.) for digits above 9.

---

### Example Conversion (base-16):

Convert decimal 30 to base 16:

- 30 ÷ 16 = 1 remainder 14 ⇒ 'E'
- 1 ÷ 16 = 0 remainder 1 ⇒ '1'
- Collect [E, 1] ⇒ Reverse to '1E'

So 30 (decimal) is '1E' in hexadecimal (base 16).

---

### Python Implementation

Here's a general function that works for any base (2 ≤ n ≤ 36):

```python
def decimal_to_base_n(n, base):
    if n == 0:
        return '0'
    digits = []
    symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    while n > 0:
        digits.append(symbols[n % base])
        n = n // base
    return ''.join(reversed(digits))

# Example usage:
number = 30
for b in (2, 3, 8, 10, 16):
    print(f"Decimal {number} in base {b} is {decimal_to_base_n(number, b)}")
```

#### Output:

```
Decimal 30 in base 2 is 11110
Decimal 30 in base 3 is 1010
Decimal 30 in base 8 is 36
Decimal 30 in base 10 is 30
Decimal 30 in base 16 is 1E
```

### C++ implementation

```c
#include <iostream>
#include <string>
#include <algorithm>

// Converts a decimal number n to its base 'base' representation as a string
std::string decimal_to_base_n(int n, int base) {
    if (n == 0) return "0";
    std::string symbols = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string result;
    while (n > 0) {
        result += symbols[n % base];
        n /= base;
    }
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    int number = 30;
    for (int base : {2, 3, 8, 10, 16}) {
        std::cout << "Decimal " << number << " in base " << base << " is "
                  << decimal_to_base_n(number, base) << std::endl;
    }
    return 0;
}
```

---

### Summary of the algorithm

- Keep dividing by the target base.
- Write down each remainder.
- The base-n result is the remainders read in reverse.

Let me know if you need any tweaks or explanations for other cases (negative numbers, floating points, etc)!

## Use tree to represent number

在刘聪 paper [浅谈数位类统计问题](https://www.gydoc.com/p-5722.html) 中，使用了"**逐位确定**"

例子：

1、lexicographical order(字典序)

complete n-ary tree: 在每一位可以选择哪些digit。

## 数位类统计问题 # 乘法原理

[刘聪-浅谈数位类统计问题](https://www.gydoc.com/p-5722.html)  

[LeetCode-233. 数字 1 的个数-困难](https://leetcode.cn/problems/number-of-digit-one/) 

> 基于乘法原理来进行计数
> 
> 要统计百位上为1的数的个数，即要统计如下形式：
> 
> ```
> **1**
> ```
> 
> 固定一位，由它的高位、低位进行组合。

```
0
1
2
3
4
5
6
7
8
9
```

乘法原理、重复出现、这道题非常好的展示了数位具有非常好的重复性质。
