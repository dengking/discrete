# LeetCode [135. 分发糖果](https://leetcode.cn/problems/candy/)

从左到右单调递增子数组、从左到右单调递减子数组，比如下面的:

例子一:

```
5,7,8,3,4,2,1
```

`5,7,8` 就是 单调递增子数组，显然8最少需要3个糖果，这可以通过从左到右遍历确定

`8,3` 就是单调递减子数组

`4,2,1` 就是 单调递减子数组，显然4最少需要3个糖果，这可以通过从右到左遍历确定

例子二:

```
5,6,7,6,5,4,3,2,1
```

`5,6,7` 就是 单调递增子数组，显然7最少需要3个糖果，这可以通过从左到右遍历确定

`7,6,5,4,3,2,1` 就是 单调递减子数组，显然7最少需要7个糖果，这可以通过从右到左遍历确定

在LeetCode [406. 根据身高重建队列](https://leetcode.cn/problems/queue-reconstruction-by-height/) 的解题 [Gnakuw](https://leetcode.cn/u/nehzil/) # [【贪心思想「模拟队列插入图解」】](https://leetcode.cn/problems/queue-reconstruction-by-height/solution/by-nehzil-1z3g/) 中也提及了本题的解题思路。



## [官方解题](https://leetcode.cn/problems/candy/solution/fen-fa-tang-guo-by-leetcode-solution-f01p/) 

### 方法一：两次遍历

> NOTE: 同时满足 **左规则** 和 **右规则** 
>
> 从左往右遍历其实是保证满足 **左规则** 
>
> 从右往左遍历其实是保证满足 **右规则** 





### 方法二：常数空间遍历

## [Krahets](https://leetcode.cn/u/jyd/) # [分发糖果 （贪心思想，线性复杂度，清晰图解）](https://leetcode.cn/problems/candy/solution/candy-cong-zuo-zhi-you-cong-you-zhi-zuo-qu-zui-da-/)



## 两次遍历



```c++
#include <iostream>
#include <string>
#include <unordered_map>
#include <array>
#include <vector>
#include <string>
#include <iostream>
#include <variant>
#include <typeinfo>
#include <limits>

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int len = ratings.size();
        vector<int> left(len);
        for (int i = 0; i < len; ++i)
        {
            if (i - 1 >= 0 && ratings[i] > ratings[i - 1])
            {
                left[i] = left[i - 1] + 1;
            }
            else
            {
                left[i] = 1;
            }
        }
        int ret = 0;
        int right = 0;
        for (int i = len - 1; i >= 0; --i)
        {
            if (i + 1 < len && ratings[i] > ratings[i + 1])
            {
                ++right;
            }
            else
            {
                right = 1;
            }
            ret += max(left[i], right);
        }
        return ret;
    }
};

int main()
{
}
// g++ test.cpp --std=c++11 -pedantic -Wall -Wextra

```

