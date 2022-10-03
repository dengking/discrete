# 我的日程安排系列



[LeetCode-729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i/)

[LeetCode-731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/)

[LeetCode-732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/) 



## k-constrain

这个系列是典型的出题套路: k 次，这道题的套路让我想到了单调栈 k 次，因为 [731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/)  中的写法和单调栈k次的写法非常类似，都是在循环体中添加了k次的限制。



## 统一解法: sweep-line-algorithm

这个系列的是可以使用 sweep-line-algorithm 进行统一解决的。



### [LeetCode-731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/) # [Laugh](https://leetcode.cn/u/laughhhh/) # [[ 一法解N题] ✔](https://leetcode.cn/problems/my-calendar-ii/solution/yi-fa-jie-nti-by-laughhhh-pll7/) 

今天介绍的方法叫**插旗法**，其实我最早是在 [LeetCode-253. 会议室Ⅱ](https://leetcode.cn/problems/meeting-rooms-ii/) 中介绍过，但是由于很多同学不是会员，刚好今天又看到这种类型的题，所以想着再次介绍一下。

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

那对于[我的日程安排表Ⅰ](https://leetcode.cn/problems/my-calendar-i/) 和 [我的日程安排表Ⅱ](https://leetcode.cn/problems/my-calendar-ii/) 的代码，无非就是并行数量的修改：

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



### [LeetCode-729. 我的日程安排表 I](https://leetcode.cn/problems/my-calendar-i/)



```c++

class MyCalendar
{
    std::map<int, int> calendar_;

public:
    MyCalendar()
    {
    }

    bool book(int start, int end)
    {
        calendar_[start] += 1;
        calendar_[end] -= 1;
        int concurrent = 0;
        for (auto &&[_, cnt] : calendar_)
        {
            concurrent += cnt;
            if (concurrent > 1)
            {
                // roll back
                calendar_[start] -= 1;
                calendar_[end] += 1;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
```



### [LeetCode-731. 我的日程安排表 II](https://leetcode.cn/problems/my-calendar-ii/)



```c++

class MyCalendarTwo
{
  std::map<int, int> cale; // 时间戳: 人数
public:
  MyCalendarTwo()
  {
  }

  bool book(int start, int end)
  {
    cale[start]++;
    cale[end]--;
    int cnt = 0;
    for (auto &&p : cale)
    {
      cnt += p.second;
      if (cnt > 2)
      {
        // rollback  
        cale[start]--;
        cale[end]++;
        return false;
      }
    }
    return true;
  }
};
```



### [LeetCode-732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/) 

[LeetCode-732. 我的日程安排表 III](https://leetcode.cn/problems/my-calendar-iii/)  和 [LeetCode-253. 会议室 II](https://leetcode.cn/problems/meeting-rooms-ii/) 本质上一模一样。



```c++

class MyCalendarThree
{
  std::map<int, int> cale; // 时间戳:人数
public:
  MyCalendarThree()
  {
  }
  /**
   * @brief 返回我的交集个数
   *
   * @param start
   * @param end
   * @return int
   */
  int book(int start, int end)
  {
    cale[start]++;
    cale[end]--;
    int cnt = 0, max_cnt = 0;
    for (auto &&p : cale)
    {
      cnt += p.second;
      max_cnt = max(max_cnt, cnt);
    }
    return max_cnt;
  }
};

```

