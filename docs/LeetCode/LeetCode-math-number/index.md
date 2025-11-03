# Math&number



## Use tree to represent number

在刘聪 paper [浅谈数位类统计问题](https://www.gydoc.com/p-5722.html) 中，使用了"**逐位确定**"

例子：

1、lexicographical order(字典序)

complete n-ary tree: 在每一位可以选择哪些digit。

## 数位类统计问题 # 乘法原理

[刘聪-浅谈数位类统计问题](https://www.gydoc.com/p-5722.html)  

[LeetCode-233. 数字 1 的个数-困难](https://leetcode.cn/problems/number-of-digit-one/) 

> 基于乘法原理来进行计数
> 
> 要统计百位上为1的数的个数，即要统计如下形式：
> 
> ```
> **1**
> ```
> 
> 固定一位，由它的高位、低位进行组合。

```
0
1
2
3
4
5
6
7
8
9
```

乘法原理、重复出现、这道题非常好的展示了数位具有非常好的重复性质。
