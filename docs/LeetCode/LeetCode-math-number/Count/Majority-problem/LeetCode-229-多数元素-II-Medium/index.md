# [LeetCode-229. 多数元素 II-medium](https://leetcode.cn/problems/majority-element-ii/)





## [【宫水三叶の相信科学系列】详解摩尔投票为何能推广到 n / k 的情况](https://leetcode.cn/problems/majority-element-ii/solution/gong-shui-san-xie-noxiang-xin-ke-xue-xi-ws0rj/)



对于本题，我们需要统计出现次数超过 $n / 3$ 的数。

**我们可以不失一般性的将其拓展为「统计出现次数超过 n / k 的数」。**

**可以证明，出现次数超过 n / k 的数最多只有 k - 1个。否则必然违背「数总共只有 n 个」或者「当前统计的是出现次数超过 n / k 的数」的前提条件。**

当明确了符合要求的数的数量之后，我们可以使用**有限变量**来代表这 k - 1 个候选数及其出现次数。

然后使用「**摩尔投票**」的标准做法，在遍历数组时同时 `check` 这 k - 1 个数，假设当前遍历到的元素为 x：

> NOTE:
>
> 一、其实是k个数在进行比较

1、如果 x 本身是候选者的话，则对其出现次数加一；

2、如果 x 本身不是候选者，检查是否有候选者的出现次数为 0：

2.1、若有，则让 x 代替其成为候选者，并记录出现次数为 1；

2.2、若无，则让所有候选者的出现次数减一。

当处理完整个数组后，这 k - 1 个数可能会被填满，但不一定都是符合出现次数超过 n / k 要求的。

需要进行二次遍历，来确定候选者是否符合要求，将符合要求的数加到答案。

**上述做法正确性的关键是：若存在出现次数超过 n / k 的数，最后必然会成为这 k - 1 个候选者之一。**

我们可以通过「反证法」来进行证明：若出现次数超过 n / k 的数 x 最终没有成为**候选者**。



## [官方解题](https://leetcode.cn/problems/majority-element-ii/solution/qiu-zhong-shu-ii-by-leetcode-solution-y1rn/)

题目要求找出其中所有出现超过 $\lfloor\frac{n}{3}\rfloor$ 次的元素。我们可以利用**反证法**推断出满足这样条件的元素最多只有两个，我们可以利用**摩尔投票法**的核心思想，每次选择三个互不相同的元素进行**删除**（或称为「**抵消**」）。我们可以假设数组中一定只存在一个次数大于 $\lfloor\frac{n}{3}\rfloor $的元素 $x$，其中 n 为数组的长度，

一部分相同的 k 个元素 x，另一部分为 $\frac{n-k}{3}$ 组三个不同的元素，我们知道三个不同的元素会被抵消，因此最终只会剩下一个元素为 x。



## 我的解题

### 第一次提交

```c++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int candidate1 = 0, candidate2 = 0;
        int vote1 = 0, vote2 = 0;
        for (auto &&num : nums)
        {
            // 首先更换候选人
            if (vote1 == 0)
            {
                candidate1 = num;
                vote1 = 1;
            }
            else if (vote2 == 0)
            {
                candidate2 = num;
                vote2 = 1;
            }
            else
            {
                if (num == candidate1)
                {
                    ++vote1;
                }
                else if (num == candidate2)
                {
                    ++vote2;
                }
                else
                {
                    --vote1;
                    --vote2;
                }
            }
        }
        int cnt1 = 0, cnt2 = 0;
        for (auto &&num : nums)
        {
            if (candidate1 == num)
            {
                ++cnt1;
            }
            if (candidate2 == num)
            {
                ++cnt2;
            }
        }
        vector<int> res;
        if (cnt1 > nums.size() / 3)
        {
            res.push_back(candidate1);
        }
        if (cnt2 > nums.size() / 3)
        {
            res.push_back(candidate2);
        }
        return res;
    }
};

int main()
{
}

```



上述code在如下用例无法通过:

输入：`[2,2]`

输出：`[2,2]`

预期结果：`[2]`



显然上述写法是没有考虑"所有元素都相同&最终结果只有一个值"的情况。



### 官方解题



```c++

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;
class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        vector<int> ans;
        int candidate1 = 0;
        int candidate2 = 0;
        int vote1 = 0;
        int vote2 = 0;

        for (auto &num : nums)
        {
            if (vote1 > 0 && num == candidate1)
            { //如果该元素为第一个元素，则计数加1
                vote1++;
            }
            else if (vote2 > 0 && num == candidate2)
            { //如果该元素为第二个元素，则计数加1
                vote2++;
            }
            else if (vote1 == 0)
            { // 选择第一个元素
                candidate1 = num;
                vote1++;
            }
            else if (vote2 == 0)
            { // 选择第二个元素
                candidate2 = num;
                vote2++;
            }
            else
            { //如果三个元素均不相同，则相互抵消1次
                vote1--;
                vote2--;
            }
        }

        int cnt1 = 0;
        int cnt2 = 0;
        for (auto &num : nums)
        {
            if (vote1 > 0 && num == candidate1)
            { //只有得票的情况下才能够入选最终局，所以需要加上前置条件: vote1 > 0
                cnt1++;
            }
            if (vote2 > 0 && num == candidate2)
            {
                cnt2++;
            }
        }
        // 检测元素出现的次数是否满足要求
        if (vote1 > 0 && cnt1 > nums.size() / 3)
        {
            ans.push_back(candidate1);
        }
        if (vote2 > 0 && cnt2 > nums.size() / 3)
        {
            ans.push_back(candidate2);
        }

        return ans;
    }
};

int main()
{
}

```



上述算法写得非常精妙，它能够处理"所有元素都相同&最终结果只有一个值"的情况，它采取的策略是: 将票都投给candidate1，保持candidate2的票数为0，这样就将candidate2给淘汰掉(得票为0，则需要淘汰掉)。需要注意的是: 为了避免在"所有元素都相同"情况下将票分别投到candidate1和candidate2，上述写法采用的technique是: 先投票在切换candidate，这样就保证了在"所有元素都相同"情况下将票全部都投到candidate1。



