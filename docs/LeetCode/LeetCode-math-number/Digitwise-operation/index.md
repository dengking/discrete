# Digit-wise operation



[LeetCode-7. 整数反转-中等](https://leetcode.cn/problems/reverse-integer/) 

1、integer-overflow-underflow-prediction

2、

> **Assume the environment does not allow you to store 64-bit integers (signed or unsigned).**

3、create number

[LeetCode-9. 回文数-简单](https://leetcode.cn/problems/palindrome-number/) 

[LeetCode-136. 只出现一次的数字-简单](https://leetcode.cn/problems/single-number/) 

[LeetCode-137. 只出现一次的数字 II-中等](https://leetcode.cn/problems/single-number-ii/) 

[LeetCode-260. 只出现一次的数字 III- middle](https://leetcode.cn/problems/single-number-iii/) 

[LeetCode-233. 数字 1 的个数-困难](https://leetcode.cn/problems/number-of-digit-one/) 



## Extract digits from integer/split an int into its digits

### C++

一、stackoverflow [How do I split an int into its digits?](https://stackoverflow.com/questions/4261589/how-do-i-split-an-int-into-its-digits)

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

二、geeksforgeeks [C Program to Print all digits of a given number](https://www.geeksforgeeks.org/c-program-to-print-all-digits-of-a-given-number/)



三、

```c++
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



## 数位类统计问题

[刘聪-浅谈数位类统计问题](https://www.gydoc.com/p-5722.html)  

### 乘法原理

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
>
> 

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
