# [LeetCode-440. 字典序的第K小数字-中等](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/)



## 我的解题

由于之前做过 [LeetCode-386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/) ，因此我知道如何生成字典序数组，因此我第一次的解法就是仿照 [LeetCode-386. 字典序排数](https://leetcode.cn/problems/lexicographical-numbers/) 中的解法写的，但是超时了。后来看了如下几篇：

1、[杨兴元](https://leetcode.cn/u/user7056k/) # [[字节跳动最常考题之一]本题史上最完整具体的手摸手解答，时间效率超越100%用户](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/)

2、[梦溪](https://leetcode.cn/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) 

3、[官方解题](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/zi-dian-xu-de-di-kxiao-shu-zi-by-leetcod-bfy0/)

4、[jason](https://leetcode.cn/u/jason-2/) # [字典序的第K小数字](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/wu-xu-jie-zhu-shi-cha-shu-ye-neng-rong-yi-li-jie-b/)

发现把思路讲的最最清晰的是 [梦溪](https://leetcode.cn/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) ：

一、他的这种思路非常类似于quick select、二分查找，由于lexicographical-order-tree已经是有序的了，正如quick select、二分查找的使用前提一样。

二、两种选择：

1、向下走 `prefix *= 10`

2、向右走 `prefix ++`



## [梦溪](https://leetcode.cn/u/meng_xi/) # [偷了两位大佬的图和题解，记录一下本题](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/tou-liao-liang-wei-da-lao-de-tu-he-ti-ji-fs9r/) 

![image.png](https://pic.leetcode.cn/1633397054-NgEVkv-image.png)

1.初始化前缀为1，计算以1开头的节点树的所有子树结点个数:

如果**小于k，那么根节点往右走**（说明当前子树的结点树不够）；

如果**大于k，那么根节点往下走**（说明答案就在当前根节点的子树结点）

2.减去已遍历过的结点数之后，可以直接将当前结点看成新的根节点，一直重复这两步的操作，直到k = 0，找到答案。



## 第一次解题：超时

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



## 参考的代码

一、[杨兴元](https://leetcode.cn/u/user7056k/) # [[字节跳动最常考题之一]本题史上最完整具体的手摸手解答，时间效率超越100%用户](https://leetcode.cn/problems/k-th-smallest-in-lexicographical-order/solution/ben-ti-shi-shang-zui-wan-zheng-ju-ti-de-shou-mo-sh/)



```js
/**
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
var findKthNumber = function(n, k) {
  let getCount = (prefix, n) => {
    let count =  0;
    for(let cur = prefix, next = prefix + 1; cur <= n; cur *= 10, next *= 10) 
      count += Math.min(next, n+1) - cur;
    return count;
  }
  let p = 1;
  let prefix = 1;
  while(p < k) {
    let count = getCount(prefix, n);
    if(p + count > k) {
      prefix *= 10;
      p++;
    } else if(p + count <= k) {
      prefix ++;
      p += count;
    }
  }
  return prefix;
};
```

`k` 的值为 `1`，则 `p == k`，显然不会进入循环。



## 第二次解题

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
  int getCnt(long prefix, long n)
  {
    int res = 0;
    for (long i = prefix, j = prefix + 1; i <= n; i *= 10, j *= 10)
    {
      res += (min(j, n + 1) - i); // 需要注意 n + 1，结合具体例子来看：n为13，此时有：10、11、12、13 共四个元素
    }
    return res;
  }

public:
  int findKthNumber(int n, int k)
  {
    long cnt = 1;
    long prefix = 1;
    while (cnt < k)
    {
      int subtreeCnt = getCnt(prefix, n);
      if (cnt + subtreeCnt > k) // 下移
      {
        prefix *= 10;
        cnt += 1;
      }
      else // 右移
      {
        ++prefix;
        cnt += subtreeCnt;
      }
    }
    return prefix;
  }
};

int main()
{
  Solution s;
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra -g

```

