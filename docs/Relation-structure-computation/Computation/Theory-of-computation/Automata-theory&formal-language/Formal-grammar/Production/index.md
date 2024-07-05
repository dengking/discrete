

# Production

基本上所有的formal grammar都是使用的production来进行描述，所以对production进行分析是有一定必要的。

## wikipedia [Production (computer science)](https://en.wikipedia.org/wiki/Production_(computer_science))



## 产生式的递归性

当产生式体中包含产生式头部中的non-terminal的时，该产生式就是[recursive](https://en.wikipedia.org/wiki/Recursion_(computer_science))，它所描述的grammar就是[recursive grammar](https://en.wikipedia.org/wiki/Recursive_grammar)。

与产生式的递归性相关的另外一个概念是[left recursion](https://en.wikipedia.org/wiki/Left_recursion)。

### 递归公式VS产生式

数学中的递归公式（[recurrence relation](https://en.wikipedia.org/wiki/Recurrence_relation)），语言学中的产生式，两者其实有着共同之处：递归。



## 从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的角度来看[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)

在[Formal-language](../wikipedia-Formal-language.md)的《从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的角度来看[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)》章节就从[Mathematical logic](https://en.wikipedia.org/wiki/Mathematical_logic)的角度分析了[Formal grammars](https://en.wikipedia.org/wiki/Formal_grammar)，其实这是对production的分析。

从[Formation rule](https://en.wikipedia.org/wiki/Formation_rule)的角度来看待production，则它是一种推导。如果从推导的角度来看待产生式的话，则关于自顶向下parsing无法处理左递归的情况就非常任意理解了



## BNF

BNF本质上也是一种产生式

### wikipedia [Backus–Naur form](https://en.wikipedia.org/wiki/Backus%E2%80%93Naur_form)

