# Sentinel 



## wikipedia [Sentinel value](https://en.wikipedia.org/wiki/Sentinel_value)



## Linked list Sentinel node

1、在阅读 open-std [P1144R2 Object relocation in terms of move plus destroy](http://open-std.org/JTC1/SC22/WG21/docs/papers/2019/p1144r2.html#non-trivial-sample-list) 时，其中提及了 "Sentinel node"

2、根据整理的内容来看，Sentinel node可以用于实现double linked list

### wikipedia [Sentinel node](https://en.wikipedia.org/wiki/Sentinel_node)





## Example



### Append to tail and flush



> 由于最后一个元素没有flush标志，因此最后一个元素的flush，需要在循环外进行处理，最最典型的例子就是merge interval、计算器。
>
> 或者增加一个pseudo-flag，比如在[文慕阳](https://leetcode-cn.com/u/wen-mu-yang/) # [C++ 利用哨兵👨‍✈️，维护一个单调栈📈(图解，直观掌握)h](http://ttps//leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/m/) 中列举的哨兵（Sentinel）。
>
> 在parsing algorithm中，会手工加入一个结束标志，它能够触发自动机来进行reduction。



### [LeetCode-729. 我的日程安排表 I ](https://leetcode.cn/problems/my-calendar-i/) # [极简二分查找思路，C++](https://leetcode.cn/problems/my-calendar-i/solution/by-liuyvjin-dsho/)

用一个有序容器保存每个日程的 $start_i$  和 $end_i$ ，当要插入新的日程 $[s, \ e)$ 时，首先二分查找在该日程之后发生第一个日程安排，也即查找第一个日程 $i$ 满足：
$$
e <= start_i
$$
这可以直接调用 `lower_bound` 方法实现。接着检查上一个日程 $i-1$ 是否与该日程重叠，若有：

$$
end_{i-1} <= s
$$
则没有重叠。满足上述两个条件就可以直接插入新日程安排，反之不能插入。
具体实现时，有序容器可以有多种选择，比如:

1、map 本身保证有序

2、vector 配合 `lower_bound` 保证每次插入新日程到正确的位置，也能保持有序
另外，首先在容器里面插入一个 $[-1, -1)$ 的日程，可以避免访问前一个日程时越界，减少许多判断。

> NOTE:
>
> 一、它保证 `lower_bound` 总是有返回值，这其实和dummy head node的作用非常类似。

```c++
class MyCalendar
{
public:
  map<int, int> cale; // cale[start] = end;
  MyCalendar()
  {
    cale[-1] = -1; // 避免 --it 越界
  }

  bool book(int start, int end)
  {
    // 找到 end 之后的第一个日程, 即满足 start[idx] >= end 的第一个迭代器
    auto it = cale.lower_bound(end);
    // 检查前一个日程与当前日程是否重叠,  当end[idx - 1] <= start 时不重叠
    if ((--it)->second <= start)
    {
      cale[start] = end;
      return true;
    }
    return false;
  }
};
```



### dp base case

TODO

### 多分配一个避免越界

TODO

故意多分配一个来避免越界



### Stop condition: sentinel value

TODO

