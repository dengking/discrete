# 日程安排系列

leetcode [729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i/)

leetcode [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/)

leetcode [732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/)

一、这个系列是典型的出题套路: k 次，这道题的套路让我想到了单调栈 k 次，因为 [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/)  中的写法和单调栈k次的写法非常类似，都是在循环体中添加了k次的限制。

二、leetcode [732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/)  和 leetcode [253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) 本质上一模一样



## 插旗法、同时进行的会议、公交车的人数、边界计数



### 一、[731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/) 

今天介绍的方法叫**插旗法**，其实我最早是在[253. 会议室Ⅱ](https://leetcode-cn.com/problems/meeting-rooms-ii/)中介绍过，但是由于很多同学不是会员，刚好今天又看到这种类型的题，所以想着再次介绍一下。

先来介绍一下**插旗法**：进入一个区间的时候将该点坐标对应的值+1，代表插上一面进入的🚩，离开时将该点坐标值-1，代表插上一面离开的🚩，在同一个点可以同时插进入的旗或离开的旗，因为这样并不形成区间重叠。

这种方法非常适合解最大的区间重叠数量 (或最大的并行数量) 的题目，能够将时间复杂度控制在 $O(nlog{n})$，而且代码可以说是八九不离十。

```c++
int maxConcurrent (vecotr<vecotr<int>>& time){
    map<int, int> record;
    for(auto& t : time){
        record[t[0]] += 1;
        record[t[1]] -= 1;
    }
    int ans = 0, concurrent = 0;
    for(auto& p : record){
        concurrent += p.second;
        ans = max(ans, concurrent);
    }
    return ans;
}
```

> NOTE:
>
> 一、`std::map`是ordere data structure，因此上述将`time`中的元素插入到map值，其实是一个排序的过程。
>
> 

那对于[我的日程安排表Ⅰ](https://leetcode-cn.com/problems/my-calendar-i/) 和 [我的日程安排表Ⅱ](https://leetcode-cn.com/problems/my-calendar-ii/) 的代码，无非就是并行数量的修改：

```c++
class MyCalendar {
public:
    map<int, int> rec;

    MyCalendar() {}
    
    bool book(int start, int end) {
        rec[start] += 1;
        rec[end] -= 1;
        int cur = 0;

        for(auto& p : rec){
            cur += p.second;
            if(cur > 2){   // 若修改成 cur > 1， 则对应着「我的日程安排表Ⅰ」 的代码
                rec[start]--, rec[end]++;
                return false;
            }
        }
        return true;
    }
};
```



### 二、[253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) # [muluo](https://leetcode.cn/u/muluo-2/) # [图解转化为上下车问题 O(nlogn)](https://leetcode.cn/problems/meeting-rooms-ii/solution/tu-jie-zhuan-hua-wei-shang-xia-che-wen-t-uy2q/) 

开会也可以理解成坐公交，都是占用某个资源。就拿题目给的第一组数组来分析。

```
intervals = [[0,30],[5,10],[15,20]]
```

第一个人从0上车，从30下车；
第二个人从5上车，10下车。。。

我们的问题转化为最多车上有几个人（也就是最多有多少会议室）。

显然：上车，车上人数+1；下车，车上人数-1

我们把intervals拆解一下

```c++
上车：[0, 1], [5, 1], [15, 1]

下车：[10, -1], [20, -1], [30, -1]
```



然后按照第一个数把上下车排好序

```c++
人数 1    2     1     2     1      0
     0----5----10----15----20-----30
变化 +1   +1    -1    +1    -1    -1

```



```c++
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
 
        if (intervals.size() == 0) return 0;

        vector<pair<int, int>> meetings;
        for (const vector<int>& interval : intervals) {
            meetings.push_back({interval[0], 1});
            meetings.push_back({interval[1], -1});
        }
        sort(meetings.begin(), meetings.end());

        int cnt = 0, maxValue = 0;
        for (const pair<int, int>& meeting : meetings) {
            cnt += meeting.second;
            maxValue = max(maxValue, cnt);
        }
        return maxValue;
        
    }
};

```



### 三、[我的日程安排表 III # 官方解题](https://leetcode.cn/problems/my-calendar-iii/solution/wo-de-ri-cheng-an-pai-biao-iii-by-leetcode/) # 边界计数



### 其它

[253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) # [loick](https://leetcode.cn/u/loick/) # [统计同时进行的会议](https://leetcode.cn/problems/meeting-rooms-ii/solution/tong-ji-tong-shi-jin-xing-de-hui-yi-by-loick/)



### 公共问题: 相同时间点的处理

对于同一时间点的处理，在做leetcode [253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) 时遇到过，原则是先离开后进入，其中使用的是vector。

在 [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/)  中使用`std::map`，对于同一时间点能够较好的处理。