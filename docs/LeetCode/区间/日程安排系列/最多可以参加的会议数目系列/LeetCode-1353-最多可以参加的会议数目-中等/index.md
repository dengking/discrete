# [LeetCode-1353. 最多可以参加的会议数目-中等](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/)

## 我的解题

一、首先需要熟悉这道题的区间的表示方法，这是可以通过**示例 1**的配图看出的:

![img](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/02/16/e1.png)

二、对于这道题，要求解的是"参加的 **最大** 会议数目"，并且一个会议上可以中途离场的，因此一个直观的想法是: 每天参加一个会议，显然这种是能够保证参加最多会议的。





### 我的第一次解题

前提是要排序: 按照开始时间进行排序，如果开始时间相同，则按照结束时间进行排序。这样就保证开始越早、结束越早的排在前面。

其实我自己手工解的过程也是会进行排序的。

```c++
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [](const vector<int> &left, const vector<int> &right)
             {
            if(left[0] != right[0]){
                return left[0] <= right[0];
            }else{
                return left[1] <= right[1];

            } });
        int last_day = events.back()[1];
        int day = 1;
        int cnt = 0;
        for (auto &&event : events)
        {
            day = max(day, event[0]);
            if (day >= event[0] && day <= event[1])
            {
                ++cnt;
                ++day;
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<int>> events{{1, 2}, {1, 2}, {3, 3}, {1, 5}, {1, 5}};
    Solution s;
    cout << s.maxEvents(events) << endl;
}
```

#### 无法通过的用例

输入：

```
[[1,2],[1,2],[3,3],[1,5],[1,5]]
```



输出：

```
4
```



预期结果：

```
5
```



### 我的第二次解题

按结束时间进行排序，如果结束时间相同，则按照开始时间递增排序:

```c++

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        sort(events.begin(), events.end(), [](const vector<int> &left, const vector<int> &right)
             { 
                if( left[1] == right[1]){
                    return left[0] < right[0];
                } else{
                    return left[1] < right[1];
                } });

        int last_day = events.back()[1];
        int day = 1;
        int cnt = 0;
        for (auto &&event : events)
        {
            day = max(day, event[0]);
            if (day >= event[0] && day <= event[1])
            {
                ++cnt;
                ++day;
            }
        }
        return cnt;
    }
};

```



#### 无法通过的用例



输入：

```
[[1,5],[1,5],[1,5],[2,3],[2,3]]
```



输出：

`4`

预期结果：

`5`



### 总结

显然，按照前面描述的各种排序方式都无法解决问题。



## [吴自华](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/solution/sao-miao-suan-fa-tan-xin-by-lucifer1004/) #[扫描算法+贪心](https://leetcode.cn/problems/maximum-number-of-events-that-can-be-attended/solution/sao-miao-suan-fa-tan-xin-by-lucifer1004/)

> NOTE:
>
> 一、在今天可以开会的所有的event知乎，选择结束时间最早的先开会
>
> 二、每天就是一个slot，每天可以开会的event是动态变化的，这就好比是一个**竖立算盘**（有多个柱子，每个柱子上可以套的环是动态变化的），可以使用一个hybrid-ds来进行实现，这是典型的slot+machine: slot array + priority_queue



```c++
#include <queue>
#include <vector>
using namespace std;

const int MAX = 1e5 + 1;

class Solution
{
public:
    int maxEvents(vector<vector<int>> &events)
    {
        // slots
        vector<vector<int>> left(MAX);
        for (int i = 0; i < events.size(); ++i)
            left[events[i][0]].emplace_back(i);

        int ans = 0;
        priority_queue<int, vector<int>, greater<>> pq; // min heap
        for (int i = 1; i < MAX; ++i)
        {
            for (int j : left[i]) // 将开始于今天的会议加入到queue中
            {
                pq.push(events[j][1]);
            }
            while (!pq.empty() && pq.top() < i) // 将过期的剔除
            {
                pq.pop();
            }
            if (!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};

int main()
{
}
```

