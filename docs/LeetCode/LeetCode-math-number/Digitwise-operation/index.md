# Digitwise operation



[LeetCode-136. 只出现一次的数字](https://leetcode.cn/problems/single-number/) 简单

[LeetCode-137. 只出现一次的数字 II](https://leetcode.cn/problems/single-number-ii/) 中等

[LeetCode-260. 只出现一次的数字 III- middle](https://leetcode.cn/problems/single-number-iii/) 



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
