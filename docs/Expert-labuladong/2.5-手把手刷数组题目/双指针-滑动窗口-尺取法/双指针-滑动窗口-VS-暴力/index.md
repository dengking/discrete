# 滑动窗口 VS 暴力搜索



## stackoverflow [Is two pointer problem same as sliding window](https://stackoverflow.com/questions/64078162/is-two-pointer-problem-same-as-sliding-window)



### [A](https://stackoverflow.com/a/64078338)

**Sliding window algorithms** can be implemented with a single pointer and a variable for **window size**. Typically we use all of the elements within the window for the problem (for eg - sum of all elements in the window).

Two pointer technique is quite similar but we usually compare the value at the two pointers instead of all the elements between the pointers.

Two pointers can also have variations like fast-slow pointer.

Hope it answers your question.

## 滑动窗口 VS 暴力搜索

滑动窗口相较于暴力搜索，优势何在？如何减少搜索空间？

1、滑动窗口，能够较快地判断窗口中，是否包含子串

2、暴力搜索，子串使用`str[i:j]`来表示，它使用嵌套for来给出所有的`i`、`j`组合

3、滑动窗口，基于上一次的位置开始进行expand、shrink，它不必每次重头再来。

> NOTE: 
>
> 以空间换时间

## TODO

fatalerrors [LC algorithm skills summary: double pointer and sliding window skills](https://www.fatalerrors.org/a/lc-algorithm-skills-summary-double-pointer-and-sliding-window-skills.html)

> NOTE: 
>
> 1、LC algorithm的含义是什么？