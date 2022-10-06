# [LeetCode-402. 移掉K位数字](https://leetcode.cn/problems/remove-k-digits/) 

给你一个以字符串表示的非负整数 `num` 和一个整数 `k` ，移除这个数中的 `k` 位数字，使得剩下的数字最小。

## 素材

1、[力扣加加](https://leetcode.cn/u/fe-lucifer/) # [一招吃遍力扣四道题，妈妈再也不用担心我被套路啦～](https://leetcode.cn/problems/remove-k-digits/solution/yi-zhao-chi-bian-li-kou-si-dao-ti-ma-ma-zai-ye-b-5/)

这个解答是非常好的。

2、[官方解题](https://leetcode.cn/problems/remove-k-digits/solution/yi-diao-kwei-shu-zi-by-leetcode-solution/)



## 例子

121219 k=3

答案: 111



12021 k=3

答案: 1



要求: 

1、保证相对顺序

2、剩余位数

### 最极端的例子

最极端的例子一：

```
12345
```

显然，直接删除掉最右边即可；



最极端的例子二：

```
54321
```

显然，直接删除掉最左边即可；

### 普通例子

```
425
```

显然，删4而非2；



## 我的解题



### 规律是什么？

从高位到地位，从左到右，单调递增的数字最小；

从高位到地位，从左到右，单调递法的数字最大；

尽可能地从最高有效位开始删起，总是选择较小的digit，删除较大的digit(贪心)，其实它就是**字典序**，按照字典序来进行理解是非常快的。

### 算法模式

贪心 + 单调栈

### 完整代码

```C++
#include <bits/stdc++.h>
// #include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <list>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <cmath>
#include <numeric>
#include <climits>
#include <random>
// example1.cpp
// new-delete-type-mismatch error
#include <memory>
#include <vector>
using namespace std;

class Solution
{
public:
  string removeKdigits(string num, int k)
  {
    std::deque<char> stk; // 这个题目要求在两端删除元素，因此需要使用deque
    int delete_cnt = 0;
    for (auto &&c : num)
    {
      while (!stk.empty() && delete_cnt < k && c < stk.back())
      {
        stk.pop_back();
        ++delete_cnt;
      }
      stk.push_back(c);
    }

    for (; delete_cnt < k; ++delete_cnt)
    {
      stk.pop_back();
    }
    while (!stk.empty() && stk.front() == '0') // 题目要求去除前导零
    {                                          // 在while循环中访问元素前，一定要判定是否为空，否则会发生asan
      stk.pop_front();
    }
    if (stk.empty()) //题目要求剩余为空就是 0
    {
      return "0";
    }

    std::string res;
    for (auto &&c : stk)
    {
      res.push_back(c);
    }
    return res;
  }
};

// Driven Program
int main()
{
	Solution s;
	cout << s.removeKdigits("1432219", 3) << endl;
	cout << s.removeKdigits("10200", 1) << endl;
	cout << s.removeKdigits("10", 2) << endl;
	cout << s.removeKdigits("10", 1) << endl;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```



输出如下:

```
1219
200
0
0
```



