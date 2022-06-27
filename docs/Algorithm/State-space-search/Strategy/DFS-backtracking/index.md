# DFS-backtracking

"Backtracking"即"回溯法"，除了本章，在下面章节中，也对它进行了论述:

一、`Expert-labuladong\3.1-回溯算法(DFS算法)系列`

> 再看看回溯算法，前文 [回溯算法详解](http://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484709&idx=1&sn=1c24a5c41a5a255000532e83f38f2ce4&chksm=9bd7fb2daca0723be888b30345e2c5e64649fc31a00b05c27a0843f349e2dd9363338d0dac61&scene=21#wechat_redirect) 干脆直接说了，回溯算法就是个 N 叉树的前后序遍历问题，没有例外。

上面这段话其实总结得不错，回溯法就是树的 "深度优先遍历+先序+后序"



## 如何避免回溯

如何避免回溯？下面结合了例子进行了说明：

- KMP算法: https://www.cnblogs.com/dusf/p/kmp.html



## TODO

https://www.geeksforgeeks.org/top-20-backtracking-algorithm-interview-questions/



### Pattern Searching

在字符串（也叫主串）中的定位模式（pattern）问题可以使用回溯法进行解决，但是这种解法是naive的。优化方法是KMP算法，在下面两篇文章中对两种进行了比较分析：

1、cnblogs [详解KMP算法](https://www.cnblogs.com/yjiyjige/p/3263858.html)



### [Eight queens puzzle](https://en.wikipedia.org/wiki/Eight_queens_puzzle)



### [Crosswords](https://en.wikipedia.org/wiki/Crosswords)



### [Verbal arithmetic](https://en.wikipedia.org/wiki/Verbal_arithmetic)



### [Sudoku](https://en.wikipedia.org/wiki/Algorithmics_of_sudoku)



### [Parsing](https://en.wikipedia.org/wiki/Parsing) 

参见[*Compilers: Principles, Techniques, and Tools*](https://en.wikipedia.org/wiki/Compilers:_Principles,_Techniques,_and_Tools)的4.4 Top-Down Parsing，其中介绍了使用backtrack来实现parsing。



在GitHub中，可以检索非常多的这种项目：

https://github.com/search?utf8=%E2%9C%93&q=backtrack+parse&type=