# Lambda calculus

"lambda calculus"的中文意思是"lambda算子"。

## wikipedia [Lambda calculus](https://en.wikipedia.org/wiki/Lambda_calculus)

## cnblogs [lambda calculus入门](https://www.cnblogs.com/w0mTea/p/4244875.html)

**lambda算子**是一切**函数式语言**的基础，明白**lambda算子**对于掌握**函数式语言**有着许多好处。

### 1 基础

λ 算子是函数式编程的理论基础，是图灵机外的另一种计算模型。 它十分简洁，只有三条产生规则，却可以表达一切可计算的函数。

λ 算子的核心概念是表达式expression。λ 算子的产生规则如下：

```
<expression> ::= <name>|<function>|<application>
<function> ::= λ <name>.<expression>
<application> ::= <expression><expression>
```

需注意：

- 其中的`<name>`代表标识符。
- 表达式默认左结合（即从最左开始起作用），如果需要改变顺序可以加括号。



## zhihu [lambda calculus 最让你震撼人心的是什么？](https://www.zhihu.com/question/27522346)

作者：匿名用户
链接：https://www.zhihu.com/question/27522346/answer/386070874
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。



说说自己比一切皆函数更进一步的理解吧：函数与值的统一。

1.一切皆函数。所以lambda calculus是只有一条归约规则的最简运算模型。

2.一切皆值。所以lambda calculus对函数与值的操作是完全一致的。这种计算模型可以实现高阶函数，成为了函数式编程的基础。

相比之下，图灵机的tape和transition function两个概念还是分离的。



另外个人用计算模式的抽象过程可以类比计算机的发展。

起初我们有算盘，它可以用来记录特定数据，但我们依旧需要脑内的方程来进行运算。

后来我们有了差分机等等special purpose computer，它们本身相当于一个与具体数值无关的方程，即一阶方程。它可以操作数值，但不可以操作其他函数。

最后我们有了冯·诺依曼，在他的general purpose computer中，值与函数在底层的实现是统一的。硬件并不去分辨一段00101001是具体的值还是函数。冯·诺依曼的机器相当于一个高阶函数解释器，高阶函数（可以操作函数的函数）抽象的具体实现，其对待值与函数的方式与lambda calculus解释器是一致的。所以我们就知道了，冯诺依曼的general purpose computer结构为什么一定会被设计成这样。

## csdn [神奇的λ-calculus](https://blog.csdn.net/yuxiaohen/article/details/49643641)

> NOTE: 这篇文章非常好

### 先人遗风

λ-calculus(英文做lambda calculus)于1930s由阿隆佐·邱奇所引入，彼时在数位天才思想家的推动下数理逻辑学科已初见成行，其中关于计算机数理逻辑的尤以戈特弗里德·莱布尼兹、乔治·布尔、格奥尔格·康托尔、大卫·希尔伯特、库尔特·哥德尔、艾伦·图灵、阿隆佐·邱奇等人备受推崇，紧随其后的冯·诺依曼、约翰·麦卡锡、丹尼尔·福瑞德曼等人亦令吾辈顶礼膜拜，他们的成果殷泽后世，歌功颂德、付梓文书都显得微不足道。

### 潜龙在渊

λ-calculus之所以有着诱人的魅力，在于它的简洁和强大。它可以被称为是最小的通用程序设计语言。它简洁到只包含两条变换规则:变量替换(笔者业余时间参译的魔法书繁体版中1.1.5节有对此的详细解释，贴出链接请看官们不吝斧正: [程序應用的置換模型](https://github.com/shawhen/SICP-zh-tw/blob/master/Chapter 1/1.1.5 The Substitution Model for Procedure Application.md)、变量绑定以及一条函数定义方式。是的，没了。它的强大在于任何一个可计算函数都可以用它的形式来进行表达和求值，所以它是图灵完备的。相比今天各种流行程序语言中具有的以及时不时要新增的时髦语法和概念，基于λ-calculus发明的Lisp之流几乎让人觉得特别落后了(实际并不是这样，《黑客与画家》有对Lisp的高度褒奖，以及SICP使用Scheme，丹尼尔所著的各种Scheme书籍都是对Lisp的高度肯定)(Scheme是Lisp的一种方言)。

### 牛刀小试

λ-calculus表达式简短的语法规则使用BNF标记如下:

```
<expr> ::=  <constant>
          | <variable>
          | (<expr> <expr>)
          | (λ <variable>.<expr>)

```

其中

`<constant>`可以是诸如0、1这样的数字，或者预定义的函数: +、-、*等。

`<variable>`是x、y等这样的名字。

`(<expr> <expr>)`表示函数调用。左边的为要调用的函数，右边的为参数。

`(λ <variable>.<expr>)`被称为lambda抽象(lambda abstraction)，用以定义新的函数。