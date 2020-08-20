# 关于本章

本章讨论”computer algebra“即”计算代数“。

在学习back propagation的时候，查阅了 [如何直观地解释 backpropagation 算法？ - YE Y的回答 - 知乎](https://www.zhihu.com/question/27239198/answer/43560763) ，其中提及了“计算代数”，查询了一下，是有这种学科的：Computer algebra，下面是wikipedia [Computer algebra](https://en.wikipedia.org/wiki/Computer_algebra) 中的介绍：

> In [mathematics](https://en.wikipedia.org/wiki/Mathematics) and [computer science](https://en.wikipedia.org/wiki/Computer_science), **computer algebra**, also called **symbolic computation** or **algebraic computation**, is a scientific area that refers to the study and development of [algorithms](https://en.wikipedia.org/wiki/Algorithm) and [software](https://en.wikipedia.org/wiki/Software) for manipulating [mathematical expressions](https://en.wikipedia.org/wiki/Expression_(mathematics)) and other [mathematical objects](https://en.wikipedia.org/wiki/Mathematical_object). 



## Computational graph

在wikipedia [Computer algebra](https://en.wikipedia.org/wiki/Computer_algebra) “`Computer science aspects#Expressions`”段中，让我想起了在compiler principle中描述的对expression的表示：syntax tree、grammar tree，显然computational graph也是一种表达方式；

显然在计算代数，非常重要的一个课题就是如何来表示computation，显然computational graph是一种非常强大的工具；

symbolic computation: computational graph是就是一种典型的symbolic computation，它在6.5.5 Symbol-to-Symbol Derivatives、6.5.4 Back-Propagation Computation in Fully-Connected MLP 中有描述

关于computational graph，参见：

https://www.zhihu.com/question/27239198/answer/734273315

https://zhuanlan.zhihu.com/p/69175484

https://zhuanlan.zhihu.com/p/70075944

https://zhuanlan.zhihu.com/p/71869192

