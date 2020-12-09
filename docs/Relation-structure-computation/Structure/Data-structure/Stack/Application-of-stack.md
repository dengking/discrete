# Application of stack
栈有着非常多的应用，我觉得有必要总结一下这些纷繁复杂的应用主要使用了栈的哪些特性。

## 栈特性：先进后出（先进后出）
栈的后进先出（先进后出）特性其实存在着一种天然的**逆序**（与此相反的是queue的先进先出则是天然的**顺序**）
- 逆序

## 栈特性：有进有出

括号匹配（正括号进栈，反括号出栈），函数执行（调用函数进栈，函数返回出栈）

## 栈特性：线性

栈是一种**线性**的数据结构，一些**线性序列**可以基于栈来做一些**相邻元素**的基于**某种关系**的**聚合**。
- 相邻
- 基于某种关系的聚合

## [All nearest smaller values](https://en.wikipedia.org/wiki/All_nearest_smaller_values)
使用栈来表示**最近**
## 括号匹配问题

其实括号匹配问题也可以使用这种思路来进行分析：包含有括号对的字符串是**线性**的，在进行括号匹配的时候，我们仅仅关注的是括号字符而忽视所有的其他字符，所以从这个角度来看的话，字符串仅仅包含了括号对，所以其中的元素都是相邻的；**正括号**与**反括号**之间存在的关系是**匹配关系**，只有当相邻两个括号字符之间存在着**匹配关系**的时候，我们才将它们**聚合**（对应这将出栈）；其实这种框架是能够解决非常多的类似这样的问题的





## 显示栈和隐式栈

隐式栈是指使用call stack，比如：

- python的`pgen`使用隐式栈来实现括号的匹配



## 总结

### stack in [automata theory](https://en.wikipedia.org/wiki/Automata_theory)

- [Deterministic pushdown automaton](https://en.wikipedia.org/wiki/Deterministic_pushdown_automaton)
- [Pushdown automaton](https://en.wikipedia.org/wiki/Pushdown_automaton)

### [Stack-oriented programming](https://en.wikipedia.org/wiki/Stack-oriented_programming)



### [Stack machine](https://en.wikipedia.org/wiki/Stack_machine)