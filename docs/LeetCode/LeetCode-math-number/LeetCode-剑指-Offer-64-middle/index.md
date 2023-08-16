# [LeetCode-剑指 Offer 64. 求1+2+…+n-middle](https://leetcode.cn/problems/qiu-12n-lcof/)



## Recursion



```C++
class Solution {
public:
    int sumNums(int n) {
        return n == 0 ? 0 : n + sumNums(n - 1);
    }
};

```



```c++
class Solution {
public:
    int sumNums(int n) {
        n && (n += sumNums(n - 1));
        return n;
    }
};
```

