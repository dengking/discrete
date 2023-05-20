# [LeetCode-128. 最长连续序列-中等](https://leetcode.cn/problems/longest-consecutive-sequence/)



这是在阅读 robinliu gitbooks [Sweep Line (Intervals)](https://robinliu.gitbooks.io/leetcode/content/Sweep_Line.html) 时发现的。

## union-find-set





## [江不知](https://leetcode.cn/u/jalan/) # [【动态规划】Python 题解](https://leetcode.cn/problems/longest-consecutive-sequence/solution/dong-tai-gui-hua-python-ti-jie-by-jalan/)

> NOTE:
>
> 一、在 [【超小白】哈希集合/哈希表/动态规划/并查集四种方法，绝对够兄弟们喝一壶的！](https://leetcode.cn/problems/longest-consecutive-sequence/solution/xiao-bai-lang-ha-xi-ji-he-ha-xi-biao-don-j5a2/) 中也给出了这种解法

题目要求 $O(n)$ 复杂度。

一、用哈希表存储每个端点值对应连续区间的长度

二、若数已在哈希表中：跳过不做处理

三、若是新数加入：

1、取出其左右相邻数已有的连续区间长度 `left` 和 `right`

2、算当前数的区间长度为：`cur_length = left + right + 1`

3、根据 `cur_length` 更新最大长度 `max_length` 的值

4、更新区间两端点的长度值



```c++
class Solution(object):
    def longestConsecutive(self, nums):
        hash_dict = dict() // key: 区间的端点, value: 区间的长度
        
        max_length = 0
        for num in nums:
            if num not in hash_dict:
                left = hash_dict.get(num - 1, 0)
                right = hash_dict.get(num + 1, 0)
                
                cur_length = 1 + left + right
                if cur_length > max_length:
                    max_length = cur_length
                
                hash_dict[num] = cur_length
                hash_dict[num - left] = cur_length
                hash_dict[num + right] = cur_length
                
        return max_length

```

> NOTE:
>
> 一、要求是连续的，所以就不给中间留空的机会

当前的数连接了它的左边区间和右边区间，新形成的区间为:

```
[num-left, num+right]
```

新形成的区间的长度为:

 ```
cur_length = 1 + left + right
 ```



[pukgai](https://leetcode.cn/u/pukgai/) 给一个详细的思路代码说明

```python
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        res = 0
        hash_dict = dict()
        for num in nums:
            # 新进来哈希表一个数
            if num not in hash_dict:
                # 获取当前数的最左边连续长度,没有的话就更新为0
                left = hash_dict.get(num-1,0)
                # 同理获取右边的数
                right = hash_dict.get(num+1,0)
                """不用担心左边和右边没有的情况
                因为没有的话就是left或者right0
                并不改变什么
                """
                # 把当前数加入哈希表，代表当前数字出现过
                hash_dict[num] = 1
                # 更新长度
                length = left+1+right
                res = max(res,length)
                # 更新最左端点的值，如果left=n存在，那么证明当前数的前n个都存在哈希表中
                hash_dict[num-left] = length
                # 更新最右端点的值，如果right=n存在，那么证明当前数的后n个都存在哈希表中
                hash_dict[num+right] = length
                # 此时 【num-left，num-right】范围的值都连续存在哈希表中了
                # 即使left或者right=0都不影响结果
        return res
```

首先，定义一个哈希表（用于判断某个数是否存在哈希表中）

然后遍历数组

如果当前数num存在哈希表，那么跳过

如果当前数num不存在哈希表中，那么查找num-1和num+1这两个数是不是在哈希表中

比如 num是5

1234 678都在哈希表中

遍历数组的时候，遇到1234678都会掠过

此时哈希表中，1的位置和4存的值都是4（证明1或者4所在的连续长度是4）

同理 6和8存的值都是3

那么此时5进来之后，看看4和6在不在哈希表内，如果在的话，一定是端点，一定能获取到值

所以5进来之后，发现左边有4个连续的，右边有3个连续的，加上自己一个，那么组成一个大连续的

4+1+3 = 8

所以要更新当前最长连续串的端点，也就是1的位置（5-4），8的位置（5+3），更新长度为8

只需要端点存值就行，因为端点中的值在遍历的时候如果在哈希表中就会略过

如果这个时候9又进来，那么它获取到8的位置有8，10的位置有0

更新连续子串长度（8+1+0）

所以更新左端点1（9-8）的值为9，右端点9（9+0）的值为9







## double pointer 从中间向两边扩散

这个写法是参考的  robinliu gitbooks [Sweep Line (Intervals)](https://robinliu.gitbooks.io/leetcode/content/Sweep_Line.html) 。

```c++
#include <algorithm>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> sets(nums.begin(), nums.end());
        int max_len = 0;

        for (auto n : nums)
        {
            if (sets.find(n) == sets.end())
                continue;
            int i = n - 1;
            int j = n + 1;

            while (sets.find(i) != sets.end())
                sets.erase(i--);
            while (sets.find(j) != sets.end())
                sets.erase(j++);
            int cur_len = j - i - 1;
            max_len = max(cur_len, max_len);
        }

        return max_len;
    }
};

int main()
{
}
```


