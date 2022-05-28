# 大数乘法



## 算法

素材:

1、labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect)

2、 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 

labuladong [教计算机做算术：字符串乘法](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484466&idx=1&sn=0281340cc1f41230e4512e905b9d27dd&scene=21#wechat_redirect) 中描述的思路其实就是 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 中的"方法二：做乘法"，并且在 [**LeetCode** 字符串相乘 # 官方解题](https://leetcode.cn/problems/multiply-strings/solution/zi-fu-chuan-xiang-cheng-by-leetcode-solution/) 中提出了如下更加容易理解的思路:

"""

方法二还可以用另外一种方法改写。我们把两个数相乘看成是两个多项式相乘，因为任何一个数都可以表示成为
$$
\sum_{i = 0}^{n - 1} a_i \times 10^i
$$



的形式，也就相当于对多项式

> NOTE:
>
> 上面的这种形式是小端模式

也就相当于对多项式

$$
A(x) = \sum_{i = 0} ^ {n - 1} a_i x^i
$$



在 $x = 10$ 处求值。

当两个数 $N_a$ 、$N_b$  相乘的时候，我们也可以认为这两个数是两个多项式

$$
\left\{ \begin{aligned} & A(x) = \sum_{i = 0} ^ {n - 1} a_i x^i \\ & B(x) = \sum_{i = 0} ^ {m - 1} b_i x^i \end{aligned} \right.
$$


相乘的结果 $C(x) = A(x) \times B(x)$ 在 $x = 10$ 处求值。我们可以这样表示 $C(x)$：

$$
C(x) = \sum_{i = 0}^{n + m - 2} c_i x^i
$$

这里

$$
c_i = \sum_{k = 0} ^ {i} a_k b_{i - k}
$$

于是我们就可以顺序求解 $c_i$ ，每次 $O(i)$ 地选取下标和为 $i$ 的一组 $(a_k, b_{i - k})$。求到 $c_i$序列之后，再处理**进位**即可得到答案。

> NOTE:
>
> "下标和为 $i$ 的一组"所表示的其实是类似于如下的意思:
> $$
> 100 * 100
> $$
> 它们的结果应该放到万位上，它非常好的模拟了错位相乘。

对比这两种做法：

......

它们的本质是一样的，并且时间复杂度都是 $O(\max \{ n, m\} ^2)$。我们再仔细的观察 $c_i$的形式：
$$
c_i = \sum_{k = 0}^{i} a_k b_{i - k}
$$


它揭示了多项式乘法的另一面：$c_i$ 序列其实是 $a_i$ 序列和 $b_i$ 序列的卷积，即：
$$
\vec{c} = \vec{a} * \vec{b}
$$

至此，



"""

1、上面是使用的数学语言来描述大数相乘的过程



### 我的一点总结

结合一个具体的例子来进行理解:

```
    123
    456
```

从最终目标入手，首先需要明确两数相乘的结果的长度为 `m + n` 。

其次，我们平时做乘法的时候，需要错位，其实那是考虑了它所处的位(个位、十位、百位)

两个数相乘其实是可以拆解位多个数相乘然后进行相加。

运算顺序: 从低位到高位，需要从低位向高位进行计算。

累加模式

进位

## 试题

**LeetCode** [43. 字符串相乘](https://leetcode.cn/problems/multiply-strings/)

它的官方解题时比较复杂的。



## 蚂蚁集团面试题: 100!

```c++
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

#include <vector>
#include <iostream>

/**
 * @brief 将一个数转换为vector
 *
 * @param num
 * @return std::vector<int>
 */
std::vector<int> toVector(int num)
{
  std::vector<int> res;

  while (num != 0)
  {
    res.push_back(num % 10);
    num /= 10;
  }

  return res;
}

std::vector<int> add(std::vector<int> &left, std::vector<int> &right)
{
  // 双指针
  int first = 0;
  int second = 0;
  int adder = 0; // 进位
  std::vector<int> res;

  while (first < left.size() && second < right.size())
  {
    int sum = left[first] + right[second] + adder;
    res.push_back(sum % 10);
    adder = sum / 10;
    ++first;
    ++second;
  }
  while (first < left.size())
  {
    int sum = left[first] + adder;

    res.push_back(sum % 10);
    adder = sum / 10;
    ++first;
  }
  while (second < right.size())
  {
    int sum = right[second] + adder;
    res.push_back(sum % 10);
    adder = sum / 10;
    ++second;
  }
  // 0099 + 001 = 00001
  if (adder)
  {
    res.push_back(adder);
  }
  return res;
}
/**
 * @brief 各位分别与right相处，比如: 789 * 10 = 700 * 10 + 80 * 10 + 9 * 10
 *
 * @param left
 * @param right
 * @return std::vector<int>
 */
std::vector<int> multiply(std::vector<int> &left, int right)
{
  std::vector<int> sum;
  int multi = 1;
  for (auto &&bit : left)
  {
    sum.push_back(bit * multi * right);
    multi *= 10;
  }
  std::vector<int> res;
  for (auto &&num : sum)
  {
    auto numVec = toVector(num);
    res = add(res, numVec);
  }
  return res;
}

int main()
{
  std::vector<int> first = toVector(100);

  for (int i = 99; i >= 98; --i)
  {
    first = multiply(first, i);
  }
  std::copy(first.begin(), first.end(), std::ostream_iterator<int>(std::cout, " "));
}

// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```



## 素材



CSDN [大整数乘法-面试题](https://blog.csdn.net/weixin_42804808/article/details/109724408)

CSDN [华为经典面试题---大数乘法的c++实现](https://blog.csdn.net/LucasDove/article/details/50728508)

