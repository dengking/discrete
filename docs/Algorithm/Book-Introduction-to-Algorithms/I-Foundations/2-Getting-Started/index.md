# 2 Getting Started

This chapter will familiarize you with the **framework** we shall use throughout the book to think about the design and analysis of algorithms. 



 The analysis introduces a notation that focuses on how that time increases with the number of items to be sorted.

> NOTE:
>
> 一、这是algorithm time analysis的核心思想



## 2.1 Insertion sort

We start with insertion sort, which is an efficient algorithm for sorting a small number of elements. Insertion sort works the way many people sort a hand of playing cards. We start with an empty left hand and the cards face down on the table. We then remove one card at a time from the table and insert it into the correct position in the left hand. To find the correct position for a card, we compare it with each of the cards already in the hand, from right to left, as illustrated in Figure 2.1. At all times, the cards held in the left hand are sorted, and these cards were originally the top cards of the pile on the table.

> NOTE:
>
> 一、这个比喻非常好，非常形象

```pseudocode

INSERTION-SORT(A) // double pointer
    for j = 2 to A.length: // 每次插入一张牌
        key = A[j] // current card to be inserted，这里记录了它的值，所以就腾空了一个位置，所以下面是可以顺序向后移动的
        // Insert A[j] into the sorted sequence A[1:j - 1].
        i = j - 1
        while i > 0 and A[i] > key: 
            A[i + 1] = A[i]
            i = i - 1
        A[i + 1] = key // 插入到了正确的位置

```

> NOTE:
>
> 一、典型的double pointer
>
> 二、内部的while loop有两种可能性导致condition不满足:
>
> 1、`i == 0`: 这种情况对应的是当前牌比 `A[1:j - 1]` 中的所有的都小，它应该插入到首位，首位的下标为1
>
> 2、`A[i] < key`:  显然此时 当前牌应该插入到牌i的后面
>
> 综上，所以插入的语句为: `A[i + 1] = key` 
>
> 其实case1也可以认为有一个sentinel它的值是无穷小，它位于 `A[0]`，显然所有的值都要插入在  `A[0]` 之后，这种解释方法就将它和case2融合在一起了。

### Loop invariants and the correctness of insertion sort

Figure 2.2 shows how this algorithm works for `A = <5, 2, 4, 6, 1, 3>`. The index `j` indicates the “**current card**” being inserted into the hand. At the beginning of each iteration of the for loop, which is indexed by `j` , 

1、the subarray consisting of elements `A[1: j - 1]` constitutes the currently sorted hand, 

2、and the remaining subarray `A[j + 1 : n]` corresponds to the pile of cards still on the table. 

> NOTE:
>
> 一、分为了两部分:
>
> 1、左手上拿的已经sorted的部分
>
> 2、放在桌子上的还未排序的部分

In fact, elements `A[1 : j - 1]` are the elements originally in positions `1` through `j - 1`, but now in sorted order. We state these properties of `A[1 : j - 1]` formally as a **loop invariant**:

> At the start of each iteration of the for loop of lines 1–8, the subarray `A[1 : j - 1]` consists of the elements originally in `A[1 : j - 1]`, but in sorted order.

> NOTE:
>
> 一、简而言之就是: 数还是原来的那几个数，但是已经排好序了

We use **loop invariants** to help us understand why an algorithm is correct. We must show three things about a **loop invariant**:

**Initialization**: It is true prior to the first iteration of the loop. 

**Maintenance**: If it is true before an iteration of the loop, it remains true before the next iteration. 

**Termination**: When the loop terminates, the invariant gives us a useful property that helps show that the algorithm is correct.

> NOTE:
>
> 一、简而言之: 从始至终都是正确的