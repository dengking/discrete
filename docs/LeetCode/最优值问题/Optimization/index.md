# Optimization

## 打擂台

## Optimization algorithm and search algorithm

使用各种各样的[Optimization algorithm](https://en.wikipedia.org/wiki/Optimization_algorithm)来实现[Optimization](https://en.wikipedia.org/wiki/Mathematical_optimization)问题，其实其过程也可以看做是[Search algorithm](https://en.wikipedia.org/wiki/Search_algorithm)：search for best solution，即寻找最优解，这些算法往往采用的策略是：不断地向最优解逼近，关于这个观点，在`Relation-structure-computation\Computation\index.md#Iterative method`章节中也进行了描述。

比如[Gradient descent](https://en.wikipedia.org/wiki/Gradient_descent)就是一个典型的例子：该算法的过程可以看做是不断地向目标逼近的过程，下面是说明此观点的素材：

[如何直观地解释 backpropagation 算法？ - Anonymous的回答 - 知乎]( https://www.zhihu.com/question/27239198/answer/89853077)中有这样的说明：

> 梯度下降法需要给定一个初始点，并求出该点的梯度向量，然后以负梯度方向为搜索方向，以一定的步长进行搜索，从而确定下一个迭代点，再计算该新的梯度方向，如此重复直到cost收敛。



