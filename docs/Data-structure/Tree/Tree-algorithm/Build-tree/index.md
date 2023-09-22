# Build tree

本章描述的是如何构造tree。主要描述两种实现思路：

1、自底向上（reduce、规约）

2、自顶向下（expand、扩展）

## parsing algorithm

理解树构造算法的最佳案例就是parsing，在parsing中，分别有自底向上和自顶向下两种策略。

关于parsing，可以参见：

1、[wikipedia-Parsing](https://en.wikipedia.org/wiki/Parsing)

2、工程[compiler-principle](https://dengking.github.io/compiler-principle/)的[Chapter-4-Syntax-Analysis](https://dengking.github.io/compiler-principle/Chapter-4-Syntax-Analysis/)

树构造模型非常重要，在很多地方都有广泛运用。

## TODO

 结合案例来进行说明：

自顶向下的案例包括：

- 生成nav tree

自底向上的案例包括：

- shift-reduce parsing

