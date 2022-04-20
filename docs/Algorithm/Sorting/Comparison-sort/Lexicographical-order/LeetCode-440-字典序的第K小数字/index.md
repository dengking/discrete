# [440. 字典序的第K小数字](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/)



## 我的解题

由于之前做过 LeetCode [386. 字典序排数](https://leetcode-cn.com/problems/lexicographical-numbers/) ，因此我知道如何生成字典序数组，因此我第一次的解法就是仿照 LeetCode [386. 字典序排数](https://leetcode-cn.com/problems/lexicographical-numbers/) 中的解法写的，但是超时了。后来看了如下几篇：

1、[杨兴元](https://leetcode-cn.com/u/user7056k/) # [本题史上最完整具体的手摸手解答，时间效率超越100%用户](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/)

2、[梦溪](https://leetcode-cn.com/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) 

3、[官方解题](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/zi-dian-xu-de-di-kxiao-shu-zi-by-leetcod-bfy0/)

4、[jason](https://leetcode-cn.com/u/jason-2/) # [字典序的第K小数字](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/wu-xu-jie-zhu-shi-cha-shu-ye-neng-rong-yi-li-jie-b/)

发现把思路讲的最最清晰的是 [梦溪](https://leetcode-cn.com/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) ：他的这种思路非常类似于quick select、二分查找，由于lexicographical-order-tree已经是有序的了，正如quick select、二分查找的使用前提一样。

## [梦溪](https://leetcode-cn.com/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode-cn.com/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) 

![image.png](https://pic.leetcode-cn.com/1633397054-NgEVkv-image.png)

1.初始化前缀为1，计算以1开头的节点树的所有子树结点个数:

如果**小于k，那么根节点往右走**（说明当前子树的结点树不够）；

如果**大于k，那么根节点往下走**（说明答案就在当前根节点的子树结点）

2.减去已遍历过的结点数之后，可以直接将当前结点看成新的根节点，一直重复这两步的操作，直到k = 0，找到答案。



### 第一次解题

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
  int findKthNumber(int n, int k)
  {
    int cnt = 0;
    int res = 0;
    std::function<void(int)> dfs = [&](int num)
    {
      if (num > n) // 剪枝
      {
        return;
      }
      ++cnt;
      if (cnt == k)
      {
        res = num;
        return;
      }
      for (int i = 0; i <= 9; ++i)
      {
        dfs(num * 10 + i);
      }
    };
    for (int num = 1; num <= 9; ++num)
    {
      dfs(num);
    }
    return res;
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

上述算法在如下超时

```
6516650
3611122
```



