# Boyer–Moore majority vote algorithm

一、需要明确切换candidate和更新当前candidate的vote的含义: 

当当前candidate的vote为0的时候需要切换candidate；

当当前candidate的vote大于0的时候，才能够更新candidate的vote；



## wikipedia [Boyer–Moore majority vote algorithm](https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm)

The **Boyer–Moore majority vote algorithm** is an [algorithm](https://en.wikipedia.org/wiki/Algorithm) for finding the [majority](https://en.wikipedia.org/wiki/Majority) of a sequence of elements using [linear time](https://en.wikipedia.org/wiki/Linear_time) and constant space. It is named after [Robert S. Boyer](https://en.wikipedia.org/wiki/Robert_S._Boyer) and [J Strother Moore](https://en.wikipedia.org/wiki/J_Strother_Moore), who published it in 1981,[[1\]](https://en.wikipedia.org/wiki/Boyer–Moore_majority_vote_algorithm#cite_note-bm-1) and is a prototypical example of a [streaming algorithm](https://en.wikipedia.org/wiki/Streaming_algorithm).

### Description

The algorithm maintains in its [local variables](https://en.wikipedia.org/wiki/Local_variable) a sequence element and a counter, with the counter initially zero. It then processes the elements of the sequence, one at a time. When processing an element *x*, if the counter is zero, the algorithm stores *x* as its remembered sequence element and sets the counter to one. Otherwise, it compares *x* to the stored element and either increments the counter (if they are equal) or decrements the counter (otherwise). At the end of this process, if the sequence has a majority, it will be the element stored by the algorithm. This can be expressed in [pseudocode](https://en.wikipedia.org/wiki/Pseudocode) as the following steps:

```pseudocode
Initialize an element m and a counter i with i = 0
For each element x of the input sequence:
    If i = 0, then assign m = x and i = 1
    else if m = x, then assign i = i + 1
    else assign i = i − 1

Return m
```

> NOTE:
>
> 一、在 [LeetCode-169. 多数元素](https://leetcode.cn/problems/majority-element/) # [Java-3种方法(计数法/排序法/摩尔投票法)](https://leetcode.cn/problems/majority-element/solution/3chong-fang-fa-by-gfu-2/) 中，对上述算法有着更加好的描述：
>
> > 候选人(`cand_num`)初始化为`nums[0]`，票数`count`初始化为`1`。
> >
> > 当遇到与`cand_num`相同的数，则票数`count = count + 1`，否则票数`count = count - 1`。
> >
> > 当票数`count`为`0`时，更换候选人，并将票数`count`重置为`1`。
> >
> > 遍历完数组后，`cand_num`即为最终答案。
> >
> > 为何这行得通呢？
> >
> > 投票法是遇到相同的则`票数 + 1`，遇到不同的则`票数 - 1`。
> >
> > 且“多数元素”的个数`> ⌊ n/2 ⌋`，其余元素的个数总和`<= ⌊ n/2 ⌋`。
> >
> > 因此“多数元素”的个数 `-` 其余元素的个数总和 的结果 肯定 `>= 1`。
> >
> > 这就相当于每个“多数元素”和其他元素 两两相互抵消，抵消到最后肯定还剩余**至少`1`个**“多数元素”。
> >
> > 无论数组是`1 2 1 2 1`，亦或是`1 2 2 1 1`，总能得到正确的候选人。
>
> 



## zhihu [如何理解摩尔投票算法？](https://www.zhihu.com/question/49973163)



[如何理解摩尔投票算法？ - 喝七喜的回答 - 知乎]( https://www.zhihu.com/question/49973163/answer/235921864)

首先请考虑最基本的摩尔投票问题，找出一组数字序列中出现次数大于总数1/2的数字（并且假设这个数字一定存在）。显然这个数字只可能有一个。**摩尔投票算法是基于这个事实：每次从序列里选择两个不相同的数字删除掉（或称为“抵消”），最后剩下一个数字或几个相同的数字，就是出现次数大于总数一半的那个**。请首先认同这个事实，这里不证明了~



